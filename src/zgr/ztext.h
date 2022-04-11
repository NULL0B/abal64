// ****************************************************************************
// * zText.h
// * Trace functionnality
// ****************************************************************************
#ifndef _ZTEXT_H
#define _ZTEXT_H

#include "bda.h"

#ifdef __cplusplus
	extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------

// zTexPrin
EXAWORD BDA_API BdaTxt_zPrint(WORD lg,char FAR * str,SWORD dx,SWORD dy);
EXAWORD BDA_API BdaTxt_zPrintXYWithSeq(WORD x,WORD y,WORD lg,char FAR * phrase);
EXAWORD BDA_API BdaTxt_zPrintL(WORD lg,char FAR * phrase,WORD mode);
EXAWORD BDA_API BdaTxt_zPrintXYWithoutSeq(WORD x,WORD y,WORD lg,char FAR * phrase);

// zTexSta
EXAWORD BDA_API BdaTxt_zStatusXY(WORD x,WORD y);
EXAWORD BDA_API BdaTxt_zStatusDraw();
EXAWORD BDA_API BdaTxt_zStatus(char FAR * text,WORD lg);

// zTexFont
EXAWORD BDA_API BdaTxt_zFont(SWORD no_fonte);
EXAWORD BDA_API BdaTxt_zDefaultFont(WORD item,WORD font);
EXAWORD BDA_API BdaTxt_zFontChoose(char FAR * fonte_desc);
EXAWORD BDA_API BdaTxt_zFontCreate(short fontID,char FAR * pFontDesc);
EXAWORD BDA_API BdaTxt_zFontDelete(short fontID);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

// zTexFont
WORD TexSetFont( WORD hFont );
WORD TexGetFont( VOID );
WORD TexSetFontRef( WORD hFont );

WORD TexInitFont(VOID);
VOID TexEndFont(VOID);

WORD  TexFontIDToHandle( SWORD fontID );
SWORD TexFontHandleToID( WORD hFont );

// zTexPrin
WORD TexCopyRemoveEsc(char FAR * Dst, char FAR * Src, WORD lg );
WORD TexPrint(WORD hFont, char FAR * str, WORD nbchar, WORD Mode);
WORD TexPrintXY(WORD hFont, WORD x,WORD y,char FAR * text, WORD lg, WORD Mode);
WORD TexPrintGrXY(WORD hFont, WORD grx,WORD gry,char FAR * text, WORD lg, WORD Mode);
VOID TexPrintXY_FillBG( WORD hFont, WORD x, WORD y, char FAR * text, WORD lg, WORD Mode);
VOID TexPrintButtonCaption(  WORD hFont, WORD x, WORD y, char FAR * mptr, WORD lg, char FAR * kptr, WORD ColHotKey, WORD IsEvenHeigth, WORD IsPushed );
VOID  TexPrintMenuItem(  WORD hFont, WORD x, WORD y, char FAR * mptr, WORD lg, char FAR * kptr, WORD ColHotKey, WORD HasChild);

// zTexSta
VOID TexStatusFrame(int atcol,int atlin,int nbcol,int nblin); 

// zTexFgBg
WORD TexSetFGBG( WORD ColFG, WORD ColBG);
WORD TexSetFG( WORD ColFG);
WORD TexSetBG( WORD ColBG);
WORD TexGetFG(VOID);
WORD TexGetBG(VOID);
VOID TexFillBackground( WORD hFont, WORD x, WORD y, WORD ColorBG, WORD lg);

#ifdef __cplusplus
	}
#endif

#endif
