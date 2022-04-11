
#ifndef _vrefer_c
#define _vrefer_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vrefer.sng  */
/* Target         : vrefer.c  */
/* Identification : 0.0-1065019001-2581.2580 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_configuration_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[8+1];
	int	page_number;
	char	buffer_FILENAME[65];
	char	buffer_ABALHOST[65];
	char	buffer_IDENTITY[66];
	char	buffer_REPLAY[66];
	char	buffer_RECORD[66];
	char	buffer_ATR[67];
	char	buffer_ATR_DEFINE[67];
	char	buffer_ATR_INCLUDE[67];
	char	buffer_ATR_OPTIONS[67];
	char	buffer_ALD[67];
	char	buffer_ALD_OPTIONS[67];
	char	buffer_OTR[67];
	char	buffer_OTR_DEFINE[67];
	char	buffer_OTR_INCLUDE[67];
	char	buffer_OTR_OPTIONS[67];
	char	buffer_OLD[67];
	char	buffer_OLD_OPTIONS[67];
	char	buffer_EXA[67];
	char	buffer_EXADB[67];
	char	buffer_IMAGEPATH[69];
	char	buffer_ICONPATH[69];
	char	buffer_PALETTE[69];
	char	buffer_SKIN[69];
	int	value_TRIGGER_STYLE;
	char	buffer_TRIGGER_COLOUR[12];
	char	buffer_FONTPATH[69];
	char	buffer_FONT1[67];
	char	buffer_FONT2[67];
	char	buffer_FONT3[67];
	char	buffer_FONT4[67];
	char	buffer_FONT5[67];
	char	buffer_FONT6[67];
	char	buffer_FONT7[67];
	char	buffer_FONT8[67];
	char	buffer_FONT9[67];
	char	buffer_FONT10[67];
	char	buffer_HTML_TITLE[67];
	char	buffer_HTML_LOGO[67];
	char	buffer_HTML_COPYRIGHT[67];
	char	buffer_SCREEN_CSS[67];
	char	buffer_PRINT_CSS[67];
	char	buffer_NAVIGATOR[67];
	char	buffer_DOCPATH[67];
	char	buffer_PRINTER[69];
	int	value_PAPERTYPE;
	int	value_LAYOUT;
	int	value_PAGEFEED;
	int	value_RESOLUTION;
	char	buffer_AED[67];
	int	value_AED_FONT;
	int	value_AED_STATE;
	int	value_AED_SYNTAX;
	int	value_AED_NORMAL;
	int	value_AED_QUOTE;
	int	value_AED_KEYWORD;
	int	value_AED_COMMENT;
	int	value_AED_PUNCTUATE;
	char	buffer_AMAKE[67];
	char	buffer_AMAKE_OPTIONS[67];
	char	buffer_AMAKE_DEFINE[67];
	char	buffer_AMAKE_LIST[67];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[62];
	} * _Context;

private	int	accept_configuration_create(
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{

	if (!(_Context = allocate( sizeof( struct accept_configuration_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=78;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FILENAME, 64, pFILENAME);
		visual_transferin(_Context->buffer_ABALHOST, 64, pABALHOST);
		visual_transferin(_Context->buffer_IDENTITY, 65, pIDENTITY);
		visual_transferin(_Context->buffer_REPLAY, 65, pREPLAY);
		visual_transferin(_Context->buffer_RECORD, 65, pRECORD);
		visual_transferin(_Context->buffer_ATR, 66, pATR);
		visual_transferin(_Context->buffer_ATR_DEFINE, 66, pATR_DEFINE);
		visual_transferin(_Context->buffer_ATR_INCLUDE, 66, pATR_INCLUDE);
		visual_transferin(_Context->buffer_ATR_OPTIONS, 66, pATR_OPTIONS);
		visual_transferin(_Context->buffer_ALD, 66, pALD);
		visual_transferin(_Context->buffer_ALD_OPTIONS, 66, pALD_OPTIONS);
		visual_transferin(_Context->buffer_OTR, 66, pOTR);
		visual_transferin(_Context->buffer_OTR_DEFINE, 66, pOTR_DEFINE);
		visual_transferin(_Context->buffer_OTR_INCLUDE, 66, pOTR_INCLUDE);
		visual_transferin(_Context->buffer_OTR_OPTIONS, 66, pOTR_OPTIONS);
		visual_transferin(_Context->buffer_OLD, 66, pOLD);
		visual_transferin(_Context->buffer_OLD_OPTIONS, 66, pOLD_OPTIONS);
		visual_transferin(_Context->buffer_EXA, 66, pEXA);
		visual_transferin(_Context->buffer_EXADB, 66, pEXADB);
		visual_transferin(_Context->buffer_IMAGEPATH, 68, pIMAGEPATH);
		visual_transferin(_Context->buffer_ICONPATH, 68, pICONPATH);
		visual_transferin(_Context->buffer_PALETTE, 68, pPALETTE);
		visual_transferin(_Context->buffer_SKIN, 68, pSKIN);
		visual_transferin((void *) 0, 0, pTRIGGER_STYLE);
		if (!( pTRIGGER_STYLE )) _Context->value_TRIGGER_STYLE=0;
		else	_Context->value_TRIGGER_STYLE = *((int *)pTRIGGER_STYLE);
		visual_transferin(_Context->buffer_TRIGGER_COLOUR, 11, pTRIGGER_COLOUR);
		visual_transferin(_Context->buffer_FONTPATH, 68, pFONTPATH);
		visual_transferin(_Context->buffer_FONT1, 66, pFONT1);
		visual_transferin(_Context->buffer_FONT2, 66, pFONT2);
		visual_transferin(_Context->buffer_FONT3, 66, pFONT3);
		visual_transferin(_Context->buffer_FONT4, 66, pFONT4);
		visual_transferin(_Context->buffer_FONT5, 66, pFONT5);
		visual_transferin(_Context->buffer_FONT6, 66, pFONT6);
		visual_transferin(_Context->buffer_FONT7, 66, pFONT7);
		visual_transferin(_Context->buffer_FONT8, 66, pFONT8);
		visual_transferin(_Context->buffer_FONT9, 66, pFONT9);
		visual_transferin(_Context->buffer_FONT10, 66, pFONT10);
		visual_transferin(_Context->buffer_HTML_TITLE, 66, pHTML_TITLE);
		visual_transferin(_Context->buffer_HTML_LOGO, 66, pHTML_LOGO);
		visual_transferin(_Context->buffer_HTML_COPYRIGHT, 66, pHTML_COPYRIGHT);
		visual_transferin(_Context->buffer_SCREEN_CSS, 66, pSCREEN_CSS);
		visual_transferin(_Context->buffer_PRINT_CSS, 66, pPRINT_CSS);
		visual_transferin(_Context->buffer_NAVIGATOR, 66, pNAVIGATOR);
		visual_transferin(_Context->buffer_DOCPATH, 66, pDOCPATH);
		visual_transferin(_Context->buffer_PRINTER, 68, pPRINTER);
		visual_transferin((void *) 0, 0, pPAPERTYPE);
		if (!( pPAPERTYPE )) _Context->value_PAPERTYPE=0;
		else	_Context->value_PAPERTYPE = *((int *)pPAPERTYPE);
		visual_transferin((void *) 0, 0, pLAYOUT);
		if (!( pLAYOUT )) _Context->value_LAYOUT=0;
		else	_Context->value_LAYOUT = *((int *)pLAYOUT);
		visual_transferin((void *) 0, 0, pPAGEFEED);
		if (!( pPAGEFEED )) _Context->value_PAGEFEED=0;
		else	_Context->value_PAGEFEED = *((int *)pPAGEFEED);
		visual_transferin((void *) 0, 0, pRESOLUTION);
		if (!( pRESOLUTION )) _Context->value_RESOLUTION=0;
		else	_Context->value_RESOLUTION = *((int *)pRESOLUTION);
		visual_transferin(_Context->buffer_AED, 66, pAED);
		visual_transferin((void *) 0, 0, pAED_FONT);
		if (!( pAED_FONT )) _Context->value_AED_FONT=0;
		else	_Context->value_AED_FONT = *((int *)pAED_FONT);
		visual_transferin((void *) 0, 0, pAED_STATE);
		if (!( pAED_STATE )) _Context->value_AED_STATE=0;
		else	_Context->value_AED_STATE = *((int *)pAED_STATE);
		visual_transferin((void *) 0, 0, pAED_SYNTAX);
		if (!( pAED_SYNTAX )) _Context->value_AED_SYNTAX=0;
		else	_Context->value_AED_SYNTAX = *((int *)pAED_SYNTAX);
		visual_transferin((void *) 0, 0, pAED_NORMAL);
		if (!( pAED_NORMAL )) _Context->value_AED_NORMAL=0;
		else	_Context->value_AED_NORMAL = *((int *)pAED_NORMAL);
		visual_transferin((void *) 0, 0, pAED_QUOTE);
		if (!( pAED_QUOTE )) _Context->value_AED_QUOTE=0;
		else	_Context->value_AED_QUOTE = *((int *)pAED_QUOTE);
		visual_transferin((void *) 0, 0, pAED_KEYWORD);
		if (!( pAED_KEYWORD )) _Context->value_AED_KEYWORD=0;
		else	_Context->value_AED_KEYWORD = *((int *)pAED_KEYWORD);
		visual_transferin((void *) 0, 0, pAED_COMMENT);
		if (!( pAED_COMMENT )) _Context->value_AED_COMMENT=0;
		else	_Context->value_AED_COMMENT = *((int *)pAED_COMMENT);
		visual_transferin((void *) 0, 0, pAED_PUNCTUATE);
		if (!( pAED_PUNCTUATE )) _Context->value_AED_PUNCTUATE=0;
		else	_Context->value_AED_PUNCTUATE = *((int *)pAED_PUNCTUATE);
		visual_transferin(_Context->buffer_AMAKE, 66, pAMAKE);
		visual_transferin(_Context->buffer_AMAKE_OPTIONS, 66, pAMAKE_OPTIONS);
		visual_transferin(_Context->buffer_AMAKE_DEFINE, 66, pAMAKE_DEFINE);
		visual_transferin(_Context->buffer_AMAKE_LIST, 66, pAMAKE_LIST);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	_Context->focus_pages[2]=8;
	_Context->focus_pages[3]=23;
	_Context->focus_pages[4]=30;
	_Context->focus_pages[5]=42;
	_Context->focus_pages[6]=50;
	_Context->focus_pages[7]=56;
	_Context->focus_pages[8]=74;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(0,0,790,600);
	return(0);
}

private	int	accept_configuration_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_configuration_remove(
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FILENAME, 64, pFILENAME);
		visual_transferout(_Context->buffer_ABALHOST, 64, pABALHOST);
		visual_transferout(_Context->buffer_IDENTITY, 65, pIDENTITY);
		visual_transferout(_Context->buffer_REPLAY, 65, pREPLAY);
		visual_transferout(_Context->buffer_RECORD, 65, pRECORD);
		visual_transferout(_Context->buffer_ATR, 66, pATR);
		visual_transferout(_Context->buffer_ATR_DEFINE, 66, pATR_DEFINE);
		visual_transferout(_Context->buffer_ATR_INCLUDE, 66, pATR_INCLUDE);
		visual_transferout(_Context->buffer_ATR_OPTIONS, 66, pATR_OPTIONS);
		visual_transferout(_Context->buffer_ALD, 66, pALD);
		visual_transferout(_Context->buffer_ALD_OPTIONS, 66, pALD_OPTIONS);
		visual_transferout(_Context->buffer_OTR, 66, pOTR);
		visual_transferout(_Context->buffer_OTR_DEFINE, 66, pOTR_DEFINE);
		visual_transferout(_Context->buffer_OTR_INCLUDE, 66, pOTR_INCLUDE);
		visual_transferout(_Context->buffer_OTR_OPTIONS, 66, pOTR_OPTIONS);
		visual_transferout(_Context->buffer_OLD, 66, pOLD);
		visual_transferout(_Context->buffer_OLD_OPTIONS, 66, pOLD_OPTIONS);
		visual_transferout(_Context->buffer_EXA, 66, pEXA);
		visual_transferout(_Context->buffer_EXADB, 66, pEXADB);
		visual_transferout(_Context->buffer_IMAGEPATH, 68, pIMAGEPATH);
		visual_transferout(_Context->buffer_ICONPATH, 68, pICONPATH);
		visual_transferout(_Context->buffer_PALETTE, 68, pPALETTE);
		visual_transferout(_Context->buffer_SKIN, 68, pSKIN);
		visual_transferout((void *) 0, 0, pTRIGGER_STYLE);
		if ( pTRIGGER_STYLE != (char *) 0)
			*((int*)pTRIGGER_STYLE) = _Context->value_TRIGGER_STYLE;
		visual_transferout(_Context->buffer_TRIGGER_COLOUR, 11, pTRIGGER_COLOUR);
		visual_transferout(_Context->buffer_FONTPATH, 68, pFONTPATH);
		visual_transferout(_Context->buffer_FONT1, 66, pFONT1);
		visual_transferout(_Context->buffer_FONT2, 66, pFONT2);
		visual_transferout(_Context->buffer_FONT3, 66, pFONT3);
		visual_transferout(_Context->buffer_FONT4, 66, pFONT4);
		visual_transferout(_Context->buffer_FONT5, 66, pFONT5);
		visual_transferout(_Context->buffer_FONT6, 66, pFONT6);
		visual_transferout(_Context->buffer_FONT7, 66, pFONT7);
		visual_transferout(_Context->buffer_FONT8, 66, pFONT8);
		visual_transferout(_Context->buffer_FONT9, 66, pFONT9);
		visual_transferout(_Context->buffer_FONT10, 66, pFONT10);
		visual_transferout(_Context->buffer_HTML_TITLE, 66, pHTML_TITLE);
		visual_transferout(_Context->buffer_HTML_LOGO, 66, pHTML_LOGO);
		visual_transferout(_Context->buffer_HTML_COPYRIGHT, 66, pHTML_COPYRIGHT);
		visual_transferout(_Context->buffer_SCREEN_CSS, 66, pSCREEN_CSS);
		visual_transferout(_Context->buffer_PRINT_CSS, 66, pPRINT_CSS);
		visual_transferout(_Context->buffer_NAVIGATOR, 66, pNAVIGATOR);
		visual_transferout(_Context->buffer_DOCPATH, 66, pDOCPATH);
		visual_transferout(_Context->buffer_PRINTER, 68, pPRINTER);
		visual_transferout((void *) 0, 0, pPAPERTYPE);
		if ( pPAPERTYPE != (char *) 0)
			*((int*)pPAPERTYPE) = _Context->value_PAPERTYPE;
		visual_transferout((void *) 0, 0, pLAYOUT);
		if ( pLAYOUT != (char *) 0)
			*((int*)pLAYOUT) = _Context->value_LAYOUT;
		visual_transferout((void *) 0, 0, pPAGEFEED);
		if ( pPAGEFEED != (char *) 0)
			*((int*)pPAGEFEED) = _Context->value_PAGEFEED;
		visual_transferout((void *) 0, 0, pRESOLUTION);
		if ( pRESOLUTION != (char *) 0)
			*((int*)pRESOLUTION) = _Context->value_RESOLUTION;
		visual_transferout(_Context->buffer_AED, 66, pAED);
		visual_transferout((void *) 0, 0, pAED_FONT);
		if ( pAED_FONT != (char *) 0)
			*((int*)pAED_FONT) = _Context->value_AED_FONT;
		visual_transferout((void *) 0, 0, pAED_STATE);
		if ( pAED_STATE != (char *) 0)
			*((int*)pAED_STATE) = _Context->value_AED_STATE;
		visual_transferout((void *) 0, 0, pAED_SYNTAX);
		if ( pAED_SYNTAX != (char *) 0)
			*((int*)pAED_SYNTAX) = _Context->value_AED_SYNTAX;
		visual_transferout((void *) 0, 0, pAED_NORMAL);
		if ( pAED_NORMAL != (char *) 0)
			*((int*)pAED_NORMAL) = _Context->value_AED_NORMAL;
		visual_transferout((void *) 0, 0, pAED_QUOTE);
		if ( pAED_QUOTE != (char *) 0)
			*((int*)pAED_QUOTE) = _Context->value_AED_QUOTE;
		visual_transferout((void *) 0, 0, pAED_KEYWORD);
		if ( pAED_KEYWORD != (char *) 0)
			*((int*)pAED_KEYWORD) = _Context->value_AED_KEYWORD;
		visual_transferout((void *) 0, 0, pAED_COMMENT);
		if ( pAED_COMMENT != (char *) 0)
			*((int*)pAED_COMMENT) = _Context->value_AED_COMMENT;
		visual_transferout((void *) 0, 0, pAED_PUNCTUATE);
		if ( pAED_PUNCTUATE != (char *) 0)
			*((int*)pAED_PUNCTUATE) = _Context->value_AED_PUNCTUATE;
		visual_transferout(_Context->buffer_AMAKE, 66, pAMAKE);
		visual_transferout(_Context->buffer_AMAKE_OPTIONS, 66, pAMAKE_OPTIONS);
		visual_transferout(_Context->buffer_AMAKE_DEFINE, 66, pAMAKE_DEFINE);
		visual_transferout(_Context->buffer_AMAKE_LIST, 66, pAMAKE_LIST);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_configuration_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(0,0,790,600,2,"Sing : Version 1.0a",19,0x3);
	visual_image(3,21,782,574,"skin.gif",4);
	if (_Context->page_number == 1 ) {
	visual_tabpage(20,40,750,500,2,"&General",8,0,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&General",8,0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(40,90,710,16,1,27,0,"General Configuration",21,2);
	visual_frame(40,106,710,414,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(210,150,518+2,16+2,5);
	visual_text(210+1,150+1,518,16,1,27,28,_Context->buffer_FILENAME,64,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(210,180,518+2,16+2,5);
	visual_text(210+1,180+1,518,16,1,27,28,_Context->buffer_ABALHOST,64,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,150,140,16,3,27,0,"FILENAME",8,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,180,140,16,3,27,0,"ABALHOST",8,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,220,144,16,3,27,0,"IDENTITY",8,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,250,144,16,3,27,0,"REPLAY",6,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,280,144,16,3,27,0,"RECORD",6,2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(210,220,520+2,16+2,5);
	visual_text(210+1,220+1,520,16,1,27,28,_Context->buffer_IDENTITY,65,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(210,250,520+2,16+2,5);
	visual_text(210+1,250+1,520,16,1,27,28,_Context->buffer_REPLAY,65,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(210,280,520+2,16+2,5);
	visual_text(210+1,280+1,520,16,1,27,28,_Context->buffer_RECORD,65,0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(20,40,750,500,2,"A&bal",5,84,2);
	} else {
		visual_tabpage(20,40,750,500,2,"A&bal",5,84,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(40,80,710,16,1,27,0,"ABAL",4,2);
	visual_frame(40,96,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,110,140,16,3,27,0,"ATR",3,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,130,140,16,3,27,0,"ATR.DEFINE",10,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,150,140,16,3,27,0,"ATR.INCLUDE",11,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,170,138,20,3,27,0,"ATR.OPTIONS",11,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,220,140,16,3,27,0,"ALD.OPTIONS",11,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,200,140,16,3,27,0,"ALD",3,2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,110,528+2,16+2,5);
	visual_text(200+1,110+1,528,16,1,27,28,_Context->buffer_ATR,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,130,528+2,16+2,5);
	visual_text(200+1,130+1,528,16,1,27,28,_Context->buffer_ATR_DEFINE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,150,528+2,16+2,5);
	visual_text(200+1,150+1,528,16,1,27,28,_Context->buffer_ATR_INCLUDE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,170,528+2,16+2,5);
	visual_text(200+1,170+1,528,16,1,27,28,_Context->buffer_ATR_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,200,528+2,16+2,5);
	visual_text(200+1,200+1,528,16,1,27,28,_Context->buffer_ALD,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,220,528+2,16+2,5);
	visual_text(200+1,220+1,528,16,1,27,28,_Context->buffer_ALD_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(40,260,710,16,1,27,0,"ABAL++",6,2);
	visual_frame(40,276,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(40,440,710,16,1,27,0,"ABAL and ABAL++",15,2);
	visual_frame(40,456,710,64,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,290,140,16,3,27,0,"OTR",3,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,310,140,16,3,27,0,"OTR.DEFINE",10,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,330,140,16,3,27,0,"OTR.INCLUDE",11,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,350,140,16,3,27,0,"OTR.OPTIONS",11,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,400,140,16,3,27,0,"OLD.OPTIONS",11,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,380,140,16,3,27,0,"OLD",3,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,470,140,16,3,27,0,"EXA",3,2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(50,490,140,16,3,27,0,"EXADB",5,2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,290,528+2,16+2,5);
	visual_text(200+1,290+1,528,16,1,27,28,_Context->buffer_OTR,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,310,528+2,16+2,5);
	visual_text(200+1,310+1,528,16,1,27,28,_Context->buffer_OTR_DEFINE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,330,528+2,16+2,5);
	visual_text(200+1,330+1,528,16,1,27,28,_Context->buffer_OTR_INCLUDE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,350,528+2,16+2,5);
	visual_text(200+1,350+1,528,16,1,27,28,_Context->buffer_OTR_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,380,528+2,16+2,5);
	visual_text(200+1,380+1,528,16,1,27,28,_Context->buffer_OLD,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,400,528+2,16+2,5);
	visual_text(200+1,400+1,528,16,1,27,28,_Context->buffer_OLD_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,470,528+2,16+2,5);
	visual_text(200+1,470+1,528,16,1,27,28,_Context->buffer_EXA,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(200,490,528+2,16+2,5);
	visual_text(200+1,490+1,528,16,1,27,28,_Context->buffer_EXADB,66,0);
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(20,40,750,500,2,"&Images",7,150,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&Images",7,150,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,110,154,16,3,27,0,"IMAGEPATH",9,2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(200,110,544+2,16+2,5);
	visual_text(200+1,110+1,544,16,1,27,28,_Context->buffer_IMAGEPATH,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,140,154,16,3,27,0,"ICONPATH",8,2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,170,154,16,3,27,0,"PALETTE",7,2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,200,154,16,3,27,0,"SKIN",4,2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,230,154,16,3,27,0,"TRIGGER.STYLE",13,2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(450,230,184,20,3,27,0,"TRIGGER.COLOUR",14,2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(200,140,544+2,16+2,5);
	visual_text(200+1,140+1,544,16,1,27,28,_Context->buffer_ICONPATH,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(200,170,544+2,16+2,5);
	visual_text(200+1,170+1,544,16,1,27,28,_Context->buffer_PALETTE,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(200,200,544+2,16+2,5);
	visual_text(200+1,200+1,544,16,1,27,28,_Context->buffer_SKIN,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(200,230,184,80,1,27,28,parse_selection("colour|bold|underline",&_Context->value_TRIGGER_STYLE),512);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(650,230,88+2,16+2,5);
	visual_text(650+1,230+1,88,16,1,27,28,_Context->buffer_TRIGGER_COLOUR,11,0);
		}
	if (_Context->page_number == 4 ) {
	visual_tabpage(20,40,750,500,2,"&Fonts",6,230,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&Fonts",6,230,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(40,150,700,16,1,27,0,"Font Filenames",14,2);
	visual_frame(40,166,700,314,4);
		}
	if (_Context->page_number == 4 ) {
	visual_text(40,110,154,16,3,27,0,"FONTPATH",8,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,180,136,16,3,27,0,"FONT1",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,210,136,16,3,27,0,"FONT2",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,240,136,16,3,27,0,"FONT3",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,270,136,16,3,27,0,"FONT4",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,300,136,16,3,27,0,"FONT5",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,330,136,16,3,27,0,"FONT6",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,360,136,16,3,27,0,"FONT7",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,390,136,16,3,27,0,"FONT8",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,420,136,16,3,27,0,"FONT9",5,2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(50,450,140,20,3,27,0,"FONT10",6,2);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,110,544+2,16+2,5);
	visual_text(200+1,110+1,544,16,1,27,28,_Context->buffer_FONTPATH,68,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,180,528+2,16+2,5);
	visual_text(200+1,180+1,528,16,1,27,28,_Context->buffer_FONT1,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,210,528+2,16+2,5);
	visual_text(200+1,210+1,528,16,1,27,28,_Context->buffer_FONT2,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,240,528+2,16+2,5);
	visual_text(200+1,240+1,528,16,1,27,28,_Context->buffer_FONT3,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,270,528+2,16+2,5);
	visual_text(200+1,270+1,528,16,1,27,28,_Context->buffer_FONT4,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,300,528+2,16+2,5);
	visual_text(200+1,300+1,528,16,1,27,28,_Context->buffer_FONT5,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,330,528+2,16+2,5);
	visual_text(200+1,330+1,528,16,1,27,28,_Context->buffer_FONT6,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,360,528+2,16+2,5);
	visual_text(200+1,360+1,528,16,1,27,28,_Context->buffer_FONT7,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,390,528+2,16+2,5);
	visual_text(200+1,390+1,528,16,1,27,28,_Context->buffer_FONT8,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,420,528+2,16+2,5);
	visual_text(200+1,420+1,528,16,1,27,28,_Context->buffer_FONT9,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(200,450,528+2,16+2,5);
	visual_text(200+1,450+1,528,16,1,27,28,_Context->buffer_FONT10,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_tabpage(20,40,750,500,2,"&Documents",10,302,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&Documents",10,302,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(40,80,710,16,1,27,0,"Html Document Parameters",24,2);
	visual_frame(40,96,710,424,4);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,110,140,20,3,27,0,"HTML.TITLE",10,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,140,140,16,3,27,0,"HTML.LOGO",9,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,170,140,16,3,27,0,"COPYRIGHT",9,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,200,140,16,3,27,0,"SCREEN.CSS",10,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,230,140,16,3,27,0,"PRINT.CSS",9,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,260,140,16,3,27,0,"NAVIGATOR",9,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(50,290,140,16,3,27,0,"DOCPATH",7,2);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,110,528+2,16+2,5);
	visual_text(200+1,110+1,528,16,1,27,28,_Context->buffer_HTML_TITLE,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,140,528+2,16+2,5);
	visual_text(200+1,140+1,528,16,1,27,28,_Context->buffer_HTML_LOGO,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,170,528+2,16+2,5);
	visual_text(200+1,170+1,528,16,1,27,28,_Context->buffer_HTML_COPYRIGHT,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,200,528+2,16+2,5);
	visual_text(200+1,200+1,528,16,1,27,28,_Context->buffer_SCREEN_CSS,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,230,528+2,16+2,5);
	visual_text(200+1,230+1,528,16,1,27,28,_Context->buffer_PRINT_CSS,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,260,528+2,16+2,5);
	visual_text(200+1,260+1,528,16,1,27,28,_Context->buffer_NAVIGATOR,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(200,290,528+2,16+2,5);
	visual_text(200+1,290+1,528,16,1,27,28,_Context->buffer_DOCPATH,66,0);
		}
	if (_Context->page_number == 6 ) {
	visual_tabpage(20,40,750,500,2,"&Printing",9,407,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&Printing",9,407,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(40,110,154,16,3,27,0,"PRINTER",7,2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(40,150,154,16,3,27,0,"RESOLUTION",10,2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(440,150,154,16,3,27,0,"PAPERTYPE",9,2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(40,190,154,16,3,27,0,"LAYOUT",6,2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(440,190,154,16,3,27,0,"PAGEFEED",8,2);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(200,110,544+2,16+2,5);
	visual_text(200+1,110+1,544,16,1,27,28,_Context->buffer_PRINTER,68,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(590,150,152,48,1,27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(200,190,144,48,1,0,0,parse_selection("Portrait|Landscape",&_Context->value_LAYOUT),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(590,190,152,48,1,27,0,parse_selection("None|Before|After",&_Context->value_PAGEFEED),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(200,150,144,64,1,27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),768);
		}
	if (_Context->page_number == 7 ) {
	visual_tabpage(20,40,750,500,2,"&Editor",7,491,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&Editor",7,491,0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(50,120,140,16,3,27,0,"AED",3,2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(50,170,140,16,3,27,0,"AED.FONT",8,2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(50,230,690,16,1,27,0,"Editor Syntaxical Colours",25,2);
	visual_frame(50,246,690,74,4);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(200,120,528+2,16+2,5);
	visual_text(200+1,120+1,528,16,1,27,28,_Context->buffer_AED,66,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(200,170,150,70,1,0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),0);
		}
	if (_Context->page_number == 7 ) {
	visual_check(90,350,207,20,3,27,0,"AED.STATE",9,_Context->value_AED_STATE|0);
		}
	if (_Context->page_number == 7 ) {
	visual_check(340,350,207,20,3,27,0,"AED.SYNTAX",10,_Context->value_AED_SYNTAX|0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(60,260,126,16,2,27,0,"AED.NORMAL",10,259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(200,260,112,16,2,27,0,"AED.STRING",10,259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(340,260,110,20,2,27,0,"AED.KEYWORD",11,259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(470,260,110,20,2,27,0,"AED.COMMENT",11,259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(600,260,126,16,2,27,0,"AED.PUNCTUATE",13,259);
		}
	if (_Context->page_number == 7 ) {
	visual_select(60,280,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(200,280,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(340,280,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(470,280,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(600,280,120,96,1,28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	visual_button(20,550,98,32,2,27,28,"&Accept",7,0);
	visual_button(120,550,98,32,2,27,28,"&SaveFile",9,0);
	visual_button(220,550,98,32,2,28,28,"Sa&veLdap",9,0);
	visual_button(470,550,98,32,2,28,28,"L&oadLdap",9,0);
	visual_button(322,550,70,32,2,27,28,"Edi&tFile",9,0);
	visual_button(396,550,70,32,2,27,28,"&Delete",7,0);
	visual_button(570,550,98,32,2,27,28,"&LoadFile",9,0);
	visual_button(670,550,98,32,2,27,28,"&Cancel",7,0);
	if (_Context->page_number == 8 ) {
	visual_tabpage(20,40,750,500,2,"&Project",8,565,2);
	} else {
		visual_tabpage(20,40,750,500,2,"&Project",8,565,0);
		}
	if (_Context->page_number == 8 ) {
	visual_text(50,120,140,16,3,27,0,"AMAKE",5,2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(50,150,161,16,3,27,0,"AMAKE.OPTIONS",13,2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(50,180,161,20,3,27,0,"AMAKE.DEFINE",12,2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(50,210,161,20,3,27,0,"AMAKE.LIST",10,2);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(220,120,528+2,16+2,5);
	visual_text(220+1,120+1,528,16,1,27,28,_Context->buffer_AMAKE,66,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(220,150,528+2,16+2,5);
	visual_text(220+1,150+1,528,16,1,27,28,_Context->buffer_AMAKE_OPTIONS,66,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(220,180,528+2,16+2,5);
	visual_text(220+1,180+1,528,16,1,27,28,_Context->buffer_AMAKE_DEFINE,66,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(220,210,528+2,16+2,5);
	visual_text(220+1,210+1,528,16,1,27,28,_Context->buffer_AMAKE_LIST,66,0);
		}
	visual_thaw(0,0,790,600);

	return(0);
}
private int on_ACCEPT_event() {
	return(13);
	return(-1);
}
private int on_SAVEFILE_event() {
	return('Cs');
	return(-1);
}
private int on_SAVELDAP_event() {
	return('SL');
	return(-1);
}
private int on_LoadLdap_event() {
	return('LL');
	return(-1);
}
private int on_EDITFILE_event() {
	return('Ce');
	return(-1);
}
private int on_DELETE_event() {
	return('ZL');
	return(-1);
}
private int on_LOADFILE_event() {
	return('Cl');
	return(-1);
}
private int on_CANCEL_event() {
	return(27);
	return(-1);
}


private	int	accept_configuration_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 769 )  
	&&  (my >= 4 )  
	&&  (mx <= 785 )  
	&&  (my <= 20 )) {
		return(1);	/* Auto5703 */

		}
	if ((mx >= 753 )  
	&&  (my >= 4 )  
	&&  (mx <= 769 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrefer.htm");
			};
		return(-1);	/* Auto5703 */

		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 20 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 103 ) 
		&&  (my <= 64 )) {
			return(2); /* General */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 210 ) 
		&&  ( my >= 150 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 166 )) {
			return(3); /* FILENAME */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 210 ) 
		&&  ( my >= 180 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 196 )) {
			return(4); /* ABALHOST */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 210 ) 
		&&  ( my >= 220 ) 
		&&  ( mx <= 730 ) 
		&&  ( my <= 236 )) {
			return(5); /* IDENTITY */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 210 ) 
		&&  ( my >= 250 ) 
		&&  ( mx <= 730 ) 
		&&  ( my <= 266 )) {
			return(6); /* REPLAY */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 210 ) 
		&&  ( my >= 280 ) 
		&&  ( mx <= 730 ) 
		&&  ( my <= 296 )) {
			return(7); /* RECORD */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 104 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 169 ) 
		&&  (my <= 64 )) {
			return(8); /* Abal */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 126 )) {
			return(9); /* ATR */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 146 )) {
			return(10); /* ATR_DEFINE */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 150 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 166 )) {
			return(11); /* ATR_INCLUDE */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 170 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 186 )) {
			return(12); /* ATR_OPTIONS */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 200 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 216 )) {
			return(13); /* ALD */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 220 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 236 )) {
			return(14); /* ALD_OPTIONS */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 306 )) {
			return(15); /* OTR */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 310 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 326 )) {
			return(16); /* OTR_DEFINE */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 346 )) {
			return(17); /* OTR_INCLUDE */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 350 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 366 )) {
			return(18); /* OTR_OPTIONS */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 380 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 396 )) {
			return(19); /* OLD */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 400 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 416 )) {
			return(20); /* OLD_OPTIONS */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 470 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 486 )) {
			return(21); /* EXA */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 490 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 506 )) {
			return(22); /* EXADB */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 170 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 249 ) 
		&&  (my <= 64 )) {
			return(23); /* Images */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 126 )) {
			return(24); /* IMAGEPATH */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 140 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 156 )) {
			return(25); /* ICONPATH */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 170 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 186 )) {
			return(26); /* PALETTE */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 200 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 216 )) {
			return(27); /* SKIN */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 200 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 384 ) 
		&&  (my <= 246 )) {
			return(28); /* TRIGGER_STYLE */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 650 ) 
		&&  ( my >= 230 ) 
		&&  ( mx <= 738 ) 
		&&  ( my <= 246 )) {
			return(29); /* TRIGGER_COLOUR */
		}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 250 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 321 ) 
		&&  (my <= 64 )) {
			return(30); /* Fonts */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 126 )) {
			return(31); /* FONTPATH */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 180 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 196 )) {
			return(32); /* FONT1 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 210 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 226 )) {
			return(33); /* FONT2 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 240 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 256 )) {
			return(34); /* FONT3 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 270 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 286 )) {
			return(35); /* FONT4 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 300 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 316 )) {
			return(36); /* FONT5 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 346 )) {
			return(37); /* FONT6 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 360 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 376 )) {
			return(38); /* FONT7 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 390 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 406 )) {
			return(39); /* FONT8 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 420 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 436 )) {
			return(40); /* FONT9 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 450 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 466 )) {
			return(41); /* FONT10 */
		}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if ((mx >= 322 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 426 ) 
		&&  (my <= 64 )) {
			return(42); /* Documents */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 126 )) {
			return(43); /* HTML_TITLE */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 140 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 156 )) {
			return(44); /* HTML_LOGO */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 170 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 186 )) {
			return(45); /* HTML_COPYRIGHT */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 200 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 216 )) {
			return(46); /* SCREEN_CSS */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 230 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 246 )) {
			return(47); /* PRINT_CSS */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 260 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 276 )) {
			return(48); /* NAVIGATOR */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 306 )) {
			return(49); /* DOCPATH */
		}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if ((mx >= 427 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 510 ) 
		&&  (my <= 64 )) {
			return(50); /* Printing */
		}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 126 )) {
			return(51); /* PRINTER */
		}
		}
	if (_Context->page_number == 6 ) {
		if ((mx >= 590 ) 
		&&  (my >= 150 ) 
		&&  (mx <= 742 ) 
		&&  (my <= 166 )) {
			return(52); /* PAPERTYPE */
		}
		}
	if (_Context->page_number == 6 ) {
		if ((mx >= 200 ) 
		&&  (my >= 190 ) 
		&&  (mx <= 344 ) 
		&&  (my <= 206 )) {
			return(53); /* LAYOUT */
		}
		}
	if (_Context->page_number == 6 ) {
		if ((mx >= 590 ) 
		&&  (my >= 190 ) 
		&&  (mx <= 742 ) 
		&&  (my <= 206 )) {
			return(54); /* PAGEFEED */
		}
		}
	if (_Context->page_number == 6 ) {
		if ((mx >= 200 ) 
		&&  (my >= 150 ) 
		&&  (mx <= 344 ) 
		&&  (my <= 166 )) {
			return(55); /* RESOLUTION */
		}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if ((mx >= 511 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 584 ) 
		&&  (my <= 64 )) {
			return(56); /* Editor */
		}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= 200 ) 
		&&  ( my >= 120 ) 
		&&  ( mx <= 728 ) 
		&&  ( my <= 136 )) {
			return(57); /* AED */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 200 ) 
		&&  (my >= 170 ) 
		&&  (mx <= 350 ) 
		&&  (my <= 186 )) {
			return(58); /* AED_FONT */
		}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= 90 ) 
		&&  ( my >= 350 ) 
		&&  ( mx <= 297 ) 
		&&  ( my <= 370 )) {
			return(59); /* AED_STATE */
		}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= 340 ) 
		&&  ( my >= 350 ) 
		&&  ( mx <= 547 ) 
		&&  ( my <= 370 )) {
			return(60); /* AED_SYNTAX */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 60 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 180 ) 
		&&  (my <= 296 )) {
			return(61); /* AED_NORMAL */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 200 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 320 ) 
		&&  (my <= 296 )) {
			return(62); /* AED_QUOTE */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 340 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 452 ) 
		&&  (my <= 296 )) {
			return(63); /* AED_KEYWORD */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 470 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 582 ) 
		&&  (my <= 296 )) {
			return(64); /* AED_COMMENT */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 600 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 720 ) 
		&&  (my <= 296 )) {
			return(65); /* AED_PUNCTUATE */
		}
		}
	if (( mx >= 20 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 118 ) 
	&&  ( my <= 582 )) {
		return(66); /* ACCEPT */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 218 ) 
	&&  ( my <= 582 )) {
		return(67); /* SAVEFILE */
		}
	if (( mx >= 220 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 318 ) 
	&&  ( my <= 582 )) {
		return(68); /* SAVELDAP */
		}
	if (( mx >= 470 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 568 ) 
	&&  ( my <= 582 )) {
		return(69); /* LoadLdap */
		}
	if (( mx >= 322 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 392 ) 
	&&  ( my <= 582 )) {
		return(70); /* EDITFILE */
		}
	if (( mx >= 396 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 466 ) 
	&&  ( my <= 582 )) {
		return(71); /* DELETE */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 668 ) 
	&&  ( my <= 582 )) {
		return(72); /* LOADFILE */
		}
	if (( mx >= 670 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 768 ) 
	&&  ( my <= 582 )) {
		return(73); /* CANCEL */
		}
	if (_Context->page_number == 8 ) {
	} else {
		if ((mx >= 585 ) 
		&&  (my >= 40 ) 
		&&  (mx <= 667 ) 
		&&  (my <= 64 )) {
			return(74); /* Project */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 220 ) 
		&&  ( my >= 120 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 136 )) {
			return(75); /* AMAKE */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 220 ) 
		&&  ( my >= 150 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 166 )) {
			return(76); /* AMAKE_OPTIONS */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 220 ) 
		&&  ( my >= 180 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 196 )) {
			return(77); /* AMAKE_DEFINE */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 220 ) 
		&&  ( my >= 210 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 226 )) {
			return(78); /* AMAKE_LIST */
		}
		}

	return(-1);
}


private	int	accept_configuration_losefocus()
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
		case 5 : 
			break;
		case 6 : 
			break;
		case 7 : 
			break;
		case 8 : 
			break;

		}
	return(0);

}


private	int	accept_configuration_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* General */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* FILENAME */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(210+1,150+1,518,16,1,_Context->buffer_FILENAME,64);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* ABALHOST */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(210+1,180+1,518,16,1,_Context->buffer_ABALHOST,64);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* IDENTITY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(210+1,220+1,520,16,1,_Context->buffer_IDENTITY,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* REPLAY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(210+1,250+1,520,16,1,_Context->buffer_REPLAY,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* RECORD */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(210+1,280+1,520,16,1,_Context->buffer_RECORD,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Abal */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* ATR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,110+1,528,16,1,_Context->buffer_ATR,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* ATR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,130+1,528,16,1,_Context->buffer_ATR_DEFINE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* ATR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,150+1,528,16,1,_Context->buffer_ATR_INCLUDE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ATR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,170+1,528,16,1,_Context->buffer_ATR_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* ALD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,200+1,528,16,1,_Context->buffer_ALD,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* ALD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,220+1,528,16,1,_Context->buffer_ALD_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* OTR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,290+1,528,16,1,_Context->buffer_OTR,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* OTR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,310+1,528,16,1,_Context->buffer_OTR_DEFINE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* OTR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,330+1,528,16,1,_Context->buffer_OTR_INCLUDE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* OTR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,350+1,528,16,1,_Context->buffer_OTR_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* OLD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,380+1,528,16,1,_Context->buffer_OLD,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* OLD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,400+1,528,16,1,_Context->buffer_OLD_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* EXA */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,470+1,528,16,1,_Context->buffer_EXA,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* EXADB */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(200+1,490+1,528,16,1,_Context->buffer_EXADB,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* Images */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x18 :
				/* IMAGEPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(200+1,110+1,544,16,1,_Context->buffer_IMAGEPATH,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ICONPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(200+1,140+1,544,16,1,_Context->buffer_ICONPATH,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* PALETTE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(200+1,170+1,544,16,1,_Context->buffer_PALETTE,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* SKIN */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(200+1,200+1,544,16,1,_Context->buffer_SKIN,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* TRIGGER_STYLE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(200,230,184,80,1,27,28,parse_selection("colour|bold|underline",&_Context->value_TRIGGER_STYLE),514);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* TRIGGER_COLOUR */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(650+1,230+1,88,16,1,_Context->buffer_TRIGGER_COLOUR,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Fonts */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1f :
				/* FONTPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,110+1,544,16,1,_Context->buffer_FONTPATH,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* FONT1 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,180+1,528,16,1,_Context->buffer_FONT1,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* FONT2 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,210+1,528,16,1,_Context->buffer_FONT2,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* FONT3 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,240+1,528,16,1,_Context->buffer_FONT3,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* FONT4 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,270+1,528,16,1,_Context->buffer_FONT4,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* FONT5 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,300+1,528,16,1,_Context->buffer_FONT5,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* FONT6 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,330+1,528,16,1,_Context->buffer_FONT6,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* FONT7 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,360+1,528,16,1,_Context->buffer_FONT7,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* FONT8 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,390+1,528,16,1,_Context->buffer_FONT8,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* FONT9 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,420+1,528,16,1,_Context->buffer_FONT9,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* FONT10 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(200+1,450+1,528,16,1,_Context->buffer_FONT10,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* Documents */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2b :
				/* HTML_TITLE */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,110+1,528,16,1,_Context->buffer_HTML_TITLE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* HTML_LOGO */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,140+1,528,16,1,_Context->buffer_HTML_LOGO,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* HTML_COPYRIGHT */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,170+1,528,16,1,_Context->buffer_HTML_COPYRIGHT,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* SCREEN_CSS */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,200+1,528,16,1,_Context->buffer_SCREEN_CSS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* PRINT_CSS */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,230+1,528,16,1,_Context->buffer_PRINT_CSS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* NAVIGATOR */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,260+1,528,16,1,_Context->buffer_NAVIGATOR,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* DOCPATH */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(200+1,290+1,528,16,1,_Context->buffer_DOCPATH,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* Printing */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x33 :
				/* PRINTER */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(200+1,110+1,544,16,1,_Context->buffer_PRINTER,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* PAPERTYPE */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(590,150,152,48,1,27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* LAYOUT */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(200,190,144,48,1,0,0,parse_selection("Portrait|Landscape",&_Context->value_LAYOUT),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* PAGEFEED */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(590,190,152,48,1,27,0,parse_selection("None|Before|After",&_Context->value_PAGEFEED),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x37 :
				/* RESOLUTION */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(200,150,144,64,1,27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x38 :
				/* Editor */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x39 :
				/* AED */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(200+1,120+1,528,16,1,_Context->buffer_AED,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* AED_FONT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(200,170,150,70,1,0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* AED_STATE */
				if (_Context->page_number == 7 ) {
				visual_check(90,350,207,20,3,27,0,"AED.STATE",9,(_Context->value_AED_STATE |2));
					_Context->keycode = visual_getch();
				visual_check(90,350,207,20,3,27,0,"AED.STATE",9,(_Context->value_AED_STATE |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* AED_SYNTAX */
				if (_Context->page_number == 7 ) {
				visual_check(340,350,207,20,3,27,0,"AED.SYNTAX",10,(_Context->value_AED_SYNTAX |2));
					_Context->keycode = visual_getch();
				visual_check(340,350,207,20,3,27,0,"AED.SYNTAX",10,(_Context->value_AED_SYNTAX |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* AED_NORMAL */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(60,280,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3e :
				/* AED_QUOTE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(200,280,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3f :
				/* AED_KEYWORD */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(340,280,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* AED_COMMENT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(470,280,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x41 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(600,280,120,96,1,28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x42 :
				/* ACCEPT */
				visual_button(20,550,98,32,2,27,28,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(20,550,98,32,2,27,28,"&Accept",7,0);
				break;
			case	0x43 :
				/* SAVEFILE */
				visual_button(120,550,98,32,2,27,28,"&SaveFile",9,2);
				_Context->keycode = visual_getch();
				visual_button(120,550,98,32,2,27,28,"&SaveFile",9,0);
				break;
			case	0x44 :
				/* SAVELDAP */
				visual_button(220,550,98,32,2,28,28,"Sa&veLdap",9,2);
				_Context->keycode = visual_getch();
				visual_button(220,550,98,32,2,28,28,"Sa&veLdap",9,0);
				break;
			case	0x45 :
				/* LoadLdap */
				visual_button(470,550,98,32,2,28,28,"L&oadLdap",9,2);
				_Context->keycode = visual_getch();
				visual_button(470,550,98,32,2,28,28,"L&oadLdap",9,0);
				break;
			case	0x46 :
				/* EDITFILE */
				visual_button(322,550,70,32,2,27,28,"Edi&tFile",9,2);
				_Context->keycode = visual_getch();
				visual_button(322,550,70,32,2,27,28,"Edi&tFile",9,0);
				break;
			case	0x47 :
				/* DELETE */
				visual_button(396,550,70,32,2,27,28,"&Delete",7,2);
				_Context->keycode = visual_getch();
				visual_button(396,550,70,32,2,27,28,"&Delete",7,0);
				break;
			case	0x48 :
				/* LOADFILE */
				visual_button(570,550,98,32,2,27,28,"&LoadFile",9,2);
				_Context->keycode = visual_getch();
				visual_button(570,550,98,32,2,27,28,"&LoadFile",9,0);
				break;
			case	0x49 :
				/* CANCEL */
				visual_button(670,550,98,32,2,27,28,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(670,550,98,32,2,27,28,"&Cancel",7,0);
				break;
			case	0x4a :
				/* Project */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x4b :
				/* AMAKE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(220+1,120+1,528,16,1,_Context->buffer_AMAKE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4c :
				/* AMAKE_OPTIONS */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(220+1,150+1,528,16,1,_Context->buffer_AMAKE_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4d :
				/* AMAKE_DEFINE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(220+1,180+1,528,16,1,_Context->buffer_AMAKE_DEFINE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4e :
				/* AMAKE_LIST */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(220+1,210+1,528,16,1,_Context->buffer_AMAKE_LIST,66);
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
			accept_configuration_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_configuration_show();
			continue;
		case	0x2 :
			accept_configuration_losefocus();
			_Context->page_number=8;
			_Context->focus_item=78;
			accept_configuration_show();
			continue;
		case	0x3 :
			accept_configuration_losefocus();
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_configuration_show();
			continue;
		case	0x12 :
			accept_configuration_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_configuration_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_configuration_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto5703 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* General */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 1;
							accept_configuration_show();
							}
						continue;
					case	0x3 :
						/* FILENAME */
						continue;
					case	0x4 :
						/* ABALHOST */
						continue;
					case	0x5 :
						/* IDENTITY */
						continue;
					case	0x6 :
						/* REPLAY */
						continue;
					case	0x7 :
						/* RECORD */
						continue;
					case	0x8 :
						/* Abal */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 2;
							accept_configuration_show();
							}
						continue;
					case	0x9 :
						/* ATR */
						continue;
					case	0xa :
						/* ATR_DEFINE */
						continue;
					case	0xb :
						/* ATR_INCLUDE */
						continue;
					case	0xc :
						/* ATR_OPTIONS */
						continue;
					case	0xd :
						/* ALD */
						continue;
					case	0xe :
						/* ALD_OPTIONS */
						continue;
					case	0xf :
						/* OTR */
						continue;
					case	0x10 :
						/* OTR_DEFINE */
						continue;
					case	0x11 :
						/* OTR_INCLUDE */
						continue;
					case	0x12 :
						/* OTR_OPTIONS */
						continue;
					case	0x13 :
						/* OLD */
						continue;
					case	0x14 :
						/* OLD_OPTIONS */
						continue;
					case	0x15 :
						/* EXA */
						continue;
					case	0x16 :
						/* EXADB */
						continue;
					case	0x17 :
						/* Images */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 3;
							accept_configuration_show();
							}
						continue;
					case	0x18 :
						/* IMAGEPATH */
						continue;
					case	0x19 :
						/* ICONPATH */
						continue;
					case	0x1a :
						/* PALETTE */
						continue;
					case	0x1b :
						/* SKIN */
						continue;
					case	0x1c :
						/* TRIGGER_STYLE */
						continue;
					case	0x1d :
						/* TRIGGER_COLOUR */
						continue;
					case	0x1e :
						/* Fonts */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 4;
							accept_configuration_show();
							}
						continue;
					case	0x1f :
						/* FONTPATH */
						continue;
					case	0x20 :
						/* FONT1 */
						continue;
					case	0x21 :
						/* FONT2 */
						continue;
					case	0x22 :
						/* FONT3 */
						continue;
					case	0x23 :
						/* FONT4 */
						continue;
					case	0x24 :
						/* FONT5 */
						continue;
					case	0x25 :
						/* FONT6 */
						continue;
					case	0x26 :
						/* FONT7 */
						continue;
					case	0x27 :
						/* FONT8 */
						continue;
					case	0x28 :
						/* FONT9 */
						continue;
					case	0x29 :
						/* FONT10 */
						continue;
					case	0x2a :
						/* Documents */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 5;
							accept_configuration_show();
							}
						continue;
					case	0x2b :
						/* HTML_TITLE */
						continue;
					case	0x2c :
						/* HTML_LOGO */
						continue;
					case	0x2d :
						/* HTML_COPYRIGHT */
						continue;
					case	0x2e :
						/* SCREEN_CSS */
						continue;
					case	0x2f :
						/* PRINT_CSS */
						continue;
					case	0x30 :
						/* NAVIGATOR */
						continue;
					case	0x31 :
						/* DOCPATH */
						continue;
					case	0x32 :
						/* Printing */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 6;
							accept_configuration_show();
							}
						continue;
					case	0x33 :
						/* PRINTER */
						continue;
					case	0x34 :
						/* PAPERTYPE */
						continue;
					case	0x35 :
						/* LAYOUT */
						continue;
					case	0x36 :
						/* PAGEFEED */
						continue;
					case	0x37 :
						/* RESOLUTION */
						continue;
					case	0x38 :
						/* Editor */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 7;
							accept_configuration_show();
							}
						continue;
					case	0x39 :
						/* AED */
						continue;
					case	0x3a :
						/* AED_FONT */
						continue;
					case	0x3b :
						/* AED_STATE */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AED_STATE += 1;
							_Context->value_AED_STATE &= 1;
							}
						continue;
					case	0x3c :
						/* AED_SYNTAX */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AED_SYNTAX += 1;
							_Context->value_AED_SYNTAX &= 1;
							}
						continue;
					case	0x3d :
						/* AED_NORMAL */
						continue;
					case	0x3e :
						/* AED_QUOTE */
						continue;
					case	0x3f :
						/* AED_KEYWORD */
						continue;
					case	0x40 :
						/* AED_COMMENT */
						continue;
					case	0x41 :
						/* AED_PUNCTUATE */
						continue;
					case	0x42 :
						/* ACCEPT */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(20,550,98,32,2,27,28,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(20,550,98,32,2,27,28,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ACCEPT_event()) != -1) break;

							}
						continue;
					case	0x43 :
						/* SAVEFILE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,550,98,32,2,27,28,"&SaveFile",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,550,98,32,2,27,28,"&SaveFile",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SAVEFILE_event()) != -1) break;

							}
						continue;
					case	0x44 :
						/* SAVELDAP */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(220,550,98,32,2,28,28,"Sa&veLdap",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(220,550,98,32,2,28,28,"Sa&veLdap",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SAVELDAP_event()) != -1) break;

							}
						continue;
					case	0x45 :
						/* LoadLdap */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(470,550,98,32,2,28,28,"L&oadLdap",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(470,550,98,32,2,28,28,"L&oadLdap",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_LoadLdap_event()) != -1) break;

							}
						continue;
					case	0x46 :
						/* EDITFILE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(322,550,70,32,2,27,28,"Edi&tFile",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(322,550,70,32,2,27,28,"Edi&tFile",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_EDITFILE_event()) != -1) break;

							}
						continue;
					case	0x47 :
						/* DELETE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(396,550,70,32,2,27,28,"&Delete",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(396,550,70,32,2,27,28,"&Delete",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DELETE_event()) != -1) break;

							}
						continue;
					case	0x48 :
						/* LOADFILE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(570,550,98,32,2,27,28,"&LoadFile",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(570,550,98,32,2,27,28,"&LoadFile",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_LOADFILE_event()) != -1) break;

							}
						continue;
					case	0x49 :
						/* CANCEL */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(670,550,98,32,2,27,28,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(670,550,98,32,2,27,28,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_CANCEL_event()) != -1) break;

							}
						continue;
					case	0x4a :
						/* Project */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus();
							_Context->page_number = 8;
							accept_configuration_show();
							}
						continue;
					case	0x4b :
						/* AMAKE */
						continue;
					case	0x4c :
						/* AMAKE_OPTIONS */
						continue;
					case	0x4d :
						/* AMAKE_DEFINE */
						continue;
					case	0x4e :
						/* AMAKE_LIST */
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
				_Context->focus_item=78;
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

public	int	accept_configuration(
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{
	int	status=0;
	status = accept_configuration_create(
	 pFILENAME,
	 pABALHOST,
	 pIDENTITY,
	 pREPLAY,
	 pRECORD,
	 pATR,
	 pATR_DEFINE,
	 pATR_INCLUDE,
	 pATR_OPTIONS,
	 pALD,
	 pALD_OPTIONS,
	 pOTR,
	 pOTR_DEFINE,
	 pOTR_INCLUDE,
	 pOTR_OPTIONS,
	 pOLD,
	 pOLD_OPTIONS,
	 pEXA,
	 pEXADB,
	 pIMAGEPATH,
	 pICONPATH,
	 pPALETTE,
	 pSKIN,
	 pTRIGGER_STYLE,
	 pTRIGGER_COLOUR,
	 pFONTPATH,
	 pFONT1,
	 pFONT2,
	 pFONT3,
	 pFONT4,
	 pFONT5,
	 pFONT6,
	 pFONT7,
	 pFONT8,
	 pFONT9,
	 pFONT10,
	 pHTML_TITLE,
	 pHTML_LOGO,
	 pHTML_COPYRIGHT,
	 pSCREEN_CSS,
	 pPRINT_CSS,
	 pNAVIGATOR,
	 pDOCPATH,
	 pPRINTER,
	 pPAPERTYPE,
	 pLAYOUT,
	 pPAGEFEED,
	 pRESOLUTION,
	 pAED,
	 pAED_FONT,
	 pAED_STATE,
	 pAED_SYNTAX,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pAMAKE,
	 pAMAKE_OPTIONS,
	 pAMAKE_DEFINE,
	 pAMAKE_LIST);
	if ( status != 0) return(status);
	status = accept_configuration_show();
		enter_modal();
	status = accept_configuration_focus();
		leave_modal();
	status = accept_configuration_hide();
	status = accept_configuration_remove(
	 pFILENAME,
	 pABALHOST,
	 pIDENTITY,
	 pREPLAY,
	 pRECORD,
	 pATR,
	 pATR_DEFINE,
	 pATR_INCLUDE,
	 pATR_OPTIONS,
	 pALD,
	 pALD_OPTIONS,
	 pOTR,
	 pOTR_DEFINE,
	 pOTR_INCLUDE,
	 pOTR_OPTIONS,
	 pOLD,
	 pOLD_OPTIONS,
	 pEXA,
	 pEXADB,
	 pIMAGEPATH,
	 pICONPATH,
	 pPALETTE,
	 pSKIN,
	 pTRIGGER_STYLE,
	 pTRIGGER_COLOUR,
	 pFONTPATH,
	 pFONT1,
	 pFONT2,
	 pFONT3,
	 pFONT4,
	 pFONT5,
	 pFONT6,
	 pFONT7,
	 pFONT8,
	 pFONT9,
	 pFONT10,
	 pHTML_TITLE,
	 pHTML_LOGO,
	 pHTML_COPYRIGHT,
	 pSCREEN_CSS,
	 pPRINT_CSS,
	 pNAVIGATOR,
	 pDOCPATH,
	 pPRINTER,
	 pPAPERTYPE,
	 pLAYOUT,
	 pPAGEFEED,
	 pRESOLUTION,
	 pAED,
	 pAED_FONT,
	 pAED_STATE,
	 pAED_SYNTAX,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pAMAKE,
	 pAMAKE_OPTIONS,
	 pAMAKE_DEFINE,
	 pAMAKE_LIST);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrefer_c */
