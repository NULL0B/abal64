// ****************************************************************************
// * zText.h
// * Trace functionnality
// ****************************************************************************
#ifndef _ZTEXT_H
#define _ZTEXT_H

#ifdef __cplusplus
	extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------

// zTexPrin
WORD BDA_WINAPI BdaTxt_zPrint(WORD lg,PTRC str,SWORD dx,SWORD dy);
WORD BDA_WINAPI BdaTxt_zPrintXYWithSeq(WORD x,WORD y,WORD lg,PTRC phrase);
WORD BDA_WINAPI BdaTxt_zPrintL(WORD lg,PTRC phrase,WORD mode);
WORD BDA_WINAPI BdaTxt_zPrintXYWithoutSeq(WORD x,WORD y,WORD lg,PTRC phrase);

// zTexSta
WORD BDA_WINAPI BdaTxt_zStatusXY(WORD x,WORD y);
WORD BDA_WINAPI BdaTxt_zStatusDraw();
WORD BDA_WINAPI BdaTxt_zStatus(PTRC text,WORD lg);

// zTexFont
WORD BDA_WINAPI BdaTxt_zFont(SWORD no_fonte);
WORD BDA_WINAPI BdaTxt_zDefaultFont(WORD item,WORD font);
WORD BDA_WINAPI BdaTxt_zFontChoose(PTRC fonte_desc);
WORD BDA_WINAPI BdaTxt_zFontCreate(short fontID,PTRC pFontDesc);
WORD BDA_WINAPI BdaTxt_zFontDelete(short fontID);

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
WORD TexCopyRemoveEsc(PTRC Dst, PTRC Src, WORD lg );
WORD TexPrint(WORD hFont, PTRC str, WORD nbchar, WORD Mode);
WORD TexPrintXY(WORD hFont, WORD x,WORD y,PTRC text, WORD lg, WORD Mode);
WORD TexPrintGrXY(WORD hFont, WORD grx,WORD gry,PTRC text, WORD lg, WORD Mode);
VOID TexPrintXY_FillBG( WORD hFont, WORD x, WORD y, PTRC text, WORD lg, WORD Mode);
VOID TexPrintButtonCaption(  WORD hFont, WORD x, WORD y, PTRC mptr, WORD lg, PTRC kptr, WORD ColHotKey, WORD IsEvenHeigth, WORD IsPushed );
VOID  TexPrintMenuItem(  WORD hFont, WORD x, WORD y, PTRC mptr, WORD lg, PTRC kptr, WORD ColHotKey, WORD HasChild);

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
