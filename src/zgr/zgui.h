// ****************************************************************************
// * zGui.h
// * GUI module
// ****************************************************************************
#ifndef _ZGUI_H
#define _ZGUI_H

#include "bda.h"

#ifdef __cplusplus
	extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
// zGuiBut
EXAWORD BDA_API BdaGui_zButton(WORD focus,WORD t,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle);
EXAWORD BDA_API BdaGui_zSmallButton(WORD focus,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle);
EXAWORD BDA_API BdaGui_zTabview(WORD focus,WORD verti,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle);

// zGuiCtrl
EXAWORD BDA_API BdaGui_zF1Button(WORD focus,WORD x,WORD y);
EXAWORD BDA_API BdaGui_zVaButton(WORD focus,WORD x,WORD y);
EXAWORD BDA_API BdaGui_zCheck(WORD focus,WORD actif,WORD x,WORD y,WORD coul,WORD fond);
EXAWORD BDA_API BdaGui_zRadio(WORD focus,WORD actif,WORD x,WORD y,WORD coul,WORD fond);

// zGuiCurs
EXAWORD BDA_API BdaGui_zStatusMouse(char FAR * string);
EXAWORD BDA_API BdaGui_zMouseCursor(WORD type);
EXAWORD BDA_API BdaGui_zAskCursor(WORD oui);
EXAWORD BDA_API BdaGui_zInitMouse(char FAR * string);
EXAWORD BDA_API BdaGui_zShowMouse();
EXAWORD BDA_API BdaGui_zHideMouse();

// zGuiInMe
EXAWORD BDA_API BdaGui_zPrintVar(WORD focus,WORD x,WORD y,char FAR * var);
EXAWORD BDA_API BdaGui_zPrintItem(WORD x,WORD y,WORD lg,char FAR * phrase,char FAR * car,WORD coul1,WORD coul2,WORD fils);

// zGuiList
EXAWORD BDA_API BdaGui_zListHoriScrollBar(WORD x,WORD y,WORD flag,WORD larg,WORD pos,WORD size,WORD appuye);
EXAWORD BDA_API BdaGui_zListVertScrollBar(WORD x,WORD y,WORD flag,WORD haut,WORD pos,WORD size,WORD state);
EXAWORD BDA_API BdaGui_zLisFicScrollBar(WORD x,WORD y,WORD larg,WORD haut,WORD appuye);
EXAWORD BDA_API BdaGui_zListTitle(WORD x,WORD y,WORD lg,char FAR * titre);

// zGuiMsgb
EXAWORD BDA_API BdaGui_zMesErr(char FAR * message,WORD lg);
EXAWORD BDA_API BdaGui_zMesYesNo(char FAR * message,WORD lg,WORD actif);
EXAWORD BDA_API BdaGui_zMesYesNoCancel(char FAR * message,WORD lg);
EXAWORD BDA_API BdaGui_zMesVal(char FAR * message,WORD lg);

// zGuiWin
EXAWORD BDA_API BdaGui_zWindow(SWORD style,WORD x,WORD y,WORD larg,WORD haut,WORD coul,WORD fond,char FAR * title,SWORD lg,WORD bouts);
EXAWORD BDA_API BdaGui_zWinTitle(WORD x,WORD y,WORD larg,char FAR * title,WORD lg,WORD appel,WORD actif);
EXAWORD BDA_API BdaGui_zFrame( SWORD style,WORD xx1,WORD yy1,WORD xx2,WORD yy2, WORD coul,WORD fond,WORD lg_titre,char FAR * titre);
EXAWORD BDA_API BdaGui_zWinClear(char FAR * car,WORD x,WORD y,WORD la,WORD ha);
EXAWORD BDA_API BdaGui_zWinMove(SWORD x,SWORD y,SWORD ll,SWORD hh,SWORD nx,SWORD ny);
EXAWORD BDA_API BdaGui_zWinMoveable(WORD x,WORD y,WORD ll,WORD hh);
EXAWORD BDA_API BdaGui_zWinScroll(WORD x,WORD y,WORD larg,WORD haut,SWORD dx,SWORD dy);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------
WORD zFrame_Internal( SWORD style,WORD xx1,WORD yy1,WORD xx2,WORD yy2, WORD coul,WORD fond,WORD lg_titre,char FAR * titre);
void zButton_Internal(WORD focus,WORD t,WORD x,WORD y,WORD c,char FAR * text,WORD lg,char FAR * cle);

// zGuiWin
VOID GuiWindowInternal(WORD State,WORD x,WORD y,WORD larg,WORD haut,WORD coul,WORD fond,char FAR * title,SWORD lg,WORD bouts);
VOID GuiWinTitleInternal(WORD State, WORD x,WORD y,WORD larg,char FAR * title,WORD lg,WORD appel,WORD actif);
void GuiDestroyScrollHolder();

// zGuiInMe
VOID GuiHorizontalMenuFrame(int atcol,int atlin,int nbcol,int nblin); 
VOID GuiVerticalMenuFrame(int atcol,int atlin,int nbcol,int nblin);
VOID GuiInputFrame(int x,int y,int cx,int cy);

// zGuiList
VOID GuiListFrame(int atcol,int atlin,int nbcol,int nblin);

// zGuiBut
VOID GuiGetButtonRectangle( PTI_RECTANGLE pRect, WORD x, WORD y, WORD cx, WORD Type );
VOID GuiGetGrButtonRectangle( PTI_RECTANGLE pRect, WORD x, WORD y, WORD cx, WORD Type );
VOID GuiTabviewFrame(int atcol,int atlin,int nbcol,int nblin);
VOID GuiButtonFrame( WORD x, WORD y, WORD cx, WORD cy);

// zGuiCurs
VOID GuiSetActiveCursor(WORD Yes);

// zGuiMsgb
int GuiInitialiseMBoxSystem(int x1,int y1,int x2,int y2);
int GuiInitialiseScrollSystem();
void GuiDestroyMBoxSystem();

#ifdef __cplusplus
	}
#endif

// ----------------------------------------------------------------------------
// - MOUSE DEFINES
// ----------------------------------------------------------------------------

#define	_MIMO_LEFT 	1
#define	_MIMO_RIGHT	2

#define _MIMO_KEYBOARD		0x0002

#define _MIMO_DOWN		0x0010
#define _MIMO_UP		0x0020

#define _MIMO_CLICK		0x0040
#define _MIMO_DOUBLE		0x0080

#define _MIMO_MOVE		0x0100
#define _MIMO_WHILE_DOWN	0x0200

#define _MIMO_SEND_LEFT 	0x1000
#define _MIMO_SEND_RIGHT	0x2000
#define _MIMO_IS_DOWN		0x4000


//--------------------------------------------------------------------
//		STANDART BITMAP DEFINES
//--------------------------------------------------------------------

#define	_ARROW_HOME		    12
#define	_ARROW_PAGE_UP		18
#define	_ARROW_LINE_UP		 5
#define	_ARROW_LINE_DOWN	11
#define	_ARROW_PAGE_DOWN	 3
#define	_ARROW_END		     2
#define	_ARROW_LEFT		     8
#define	_ARROW_RIGHT		   6

//--------------------------------------------------------------------
//		MESSAGE BOX DEFINES
//--------------------------------------------------------------------

#define ZIDYES     1
#define ZIDNO      2
#define ZIDOK      3
#define ZIDCANCEL  4
#define ZIDABANDON 5

#define ZMB_YES      1
#define ZMB_NO       2
#define ZMB_YESNO    3
#define ZMB_OK       4
#define ZMB_CANCEL   8
#define ZMB_ABANDON  16

#define ZMB_OKNO				ZMB_OK  | ZMB_NO
#define ZMB_YESNOCANCEL		ZMB_YES | ZMB_NO | ZMB_CANCEL
#define ZMB_YESNOABANDON	ZMB_YES | ZMB_NO | ZMB_ABANDON
#define ZMB_OKABANDON		ZMB_OK  | ZMB_ABANDON
#define ZMB_OKCANCEL			ZMB_OK  | ZMB_CANCEL 

#define ZMB_ICONQUESTION		32
#define ZMB_ICONASTERISK		64
#define ZMB_ICONEXCLAMATION	128
#define ZMB_DEFBUTTON			256
#define ZMB_DEFBUTTON2			512

#define MB_WIDTH   7  /* Button Colour value    */


#endif

