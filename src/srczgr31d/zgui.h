// ****************************************************************************
// * zGui.h
// * GUI module
// ****************************************************************************
#ifndef _ZGUI_H
#define _ZGUI_H


#ifdef __cplusplus
	extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
// zGuiBut
WORD BDA_WINAPI BdaGui_zButton(WORD focus,WORD t,WORD x,WORD y,WORD c,PTRC text,WORD lg,PTRC cle);
WORD BDA_WINAPI BdaGui_zSmallButton(WORD focus,WORD x,WORD y,WORD c,PTRC text,WORD lg,PTRC cle);
WORD BDA_WINAPI BdaGui_zTabview(WORD focus,WORD verti,WORD x,WORD y,WORD c,PTRC text,WORD lg,PTRC cle);

// zGuiCtrl
WORD BDA_WINAPI BdaGui_zF1Button(WORD focus,WORD x,WORD y);
WORD BDA_WINAPI BdaGui_zVaButton(WORD focus,WORD x,WORD y);
WORD BDA_WINAPI BdaGui_zCheck(WORD focus,WORD actif,WORD x,WORD y,WORD coul,WORD fond);
WORD BDA_WINAPI BdaGui_zRadio(WORD focus,WORD actif,WORD x,WORD y,WORD coul,WORD fond);

// zGuiCurs
WORD BDA_WINAPI BdaGui_zStatusMouse(PTRC string);
WORD BDA_WINAPI BdaGui_zMouseCursor(WORD type);
WORD BDA_WINAPI BdaGui_zAskCursor(WORD oui);
WORD BDA_WINAPI BdaGui_zInitMouse(PTRC string);
WORD BDA_WINAPI BdaGui_zShowMouse();
WORD BDA_WINAPI BdaGui_zHideMouse();

// zGuiInMe
WORD BDA_WINAPI BdaGui_zPrintVar(WORD focus,WORD x,WORD y,PTRC var);
WORD BDA_WINAPI BdaGui_zPrintItem(WORD x,WORD y,WORD lg,PTRC phrase,PTRC car,WORD coul1,WORD coul2,WORD fils);

// zGuiList
WORD BDA_WINAPI BdaGui_zListHoriScrollBar(WORD x,WORD y,WORD flag,WORD larg,WORD pos,WORD size,WORD appuye);
WORD BDA_WINAPI BdaGui_zListVertScrollBar(WORD x,WORD y,WORD flag,WORD haut,WORD pos,WORD size,WORD state);
WORD BDA_WINAPI BdaGui_zLisFicScrollBar(WORD x,WORD y,WORD larg,WORD haut,WORD appuye);
WORD BDA_WINAPI BdaGui_zListTitle(WORD x,WORD y,WORD lg,PTRC titre);

// zGuiMsgb
WORD BDA_WINAPI BdaGui_zMesErr(PTRC message,WORD lg);
WORD BDA_WINAPI BdaGui_zMesYesNo(PTRC message,WORD lg,WORD actif);
WORD BDA_WINAPI BdaGui_zMesYesNoCancel(PTRC message,WORD lg);
WORD BDA_WINAPI BdaGui_zMesVal(PTRC message,WORD lg);

// zGuiWin
WORD BDA_WINAPI BdaGui_zWindow(SWORD style,WORD x,WORD y,WORD larg,WORD haut,WORD coul,WORD fond,PTRC title,SWORD lg,WORD bouts);
WORD BDA_WINAPI BdaGui_zWinTitle(WORD x,WORD y,WORD larg,PTRC title,WORD lg,WORD appel,WORD actif);
WORD BDA_WINAPI BdaGui_zFrame( SWORD style,WORD xx1,WORD yy1,WORD xx2,WORD yy2, WORD coul,WORD fond,WORD lg_titre,PTRC titre);
WORD BDA_WINAPI BdaGui_zWinClear(PTRC car,WORD x,WORD y,WORD la,WORD ha);
WORD BDA_WINAPI BdaGui_zWinMove(SWORD x,SWORD y,SWORD ll,SWORD hh,SWORD nx,SWORD ny);
WORD BDA_WINAPI BdaGui_zWinMoveable(WORD x,WORD y,WORD ll,WORD hh);
WORD BDA_WINAPI BdaGui_zWinScroll(WORD x,WORD y,WORD larg,WORD haut,SWORD dx,SWORD dy);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------
WORD zFrame_Internal( SWORD style,WORD xx1,WORD yy1,WORD xx2,WORD yy2, WORD coul,WORD fond,WORD lg_titre,PTRC titre);
void zButton_Internal(WORD focus,WORD t,WORD x,WORD y,WORD c,PTRC text,WORD lg,PTRC cle);

// zGuiWin
VOID GuiWindowInternal(WORD State,WORD x,WORD y,WORD larg,WORD haut,WORD coul,WORD fond,PTRC title,SWORD lg,WORD bouts);
VOID GuiWinTitleInternal(WORD State, WORD x,WORD y,WORD larg,PTRC title,WORD lg,WORD appel,WORD actif);
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

#define IDYES     1
#define IDNO      2
#define IDOK      3
#define IDCANCEL  4
#define IDABANDON 5

#define MB_YES      1
#define MB_NO       2
#define MB_YESNO    3
#define MB_OK       4
#define MB_CANCEL   8
#define MB_ABANDON  16

#define MB_OKNO      MB_OK  | MB_NO
#define MB_YESNOCANCEL     MB_YES | MB_NO | MB_CANCEL
#define MB_YESNOABANDON    MB_YES | MB_NO | MB_ABANDON
#define MB_OKABANDON     MB_OK | MB_ABANDON
#define MB_OKCANCEL    MB_OK | MB_CANCEL 

#define MB_ICONQUESTION    32
#define MB_ICONASTERISK    64
#define MB_ICONEXCLAMATION  128
#define MB_DEFBUTTON    256
#define MB_DEFBUTTON2   512

#define MB_WIDTH   7  /* Button Colour value    */


#endif

