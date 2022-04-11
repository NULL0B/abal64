// ****************************************************************************
// * zsoGui.h
// * GUI module
// ****************************************************************************
#ifndef _ZSOGUI_H
#define _ZSOGUI_H

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------

// zGuiCurs
WORD BdaGui_zStatusMouse(PTRC string);
WORD BdaGui_zInitMouse(PTRC string);
WORD BdaGui_zShowMouse();
WORD BdaGui_zHideMouse();

// zGuiInMe
WORD BdaGui_zPrintVar(WORD focus,WORD x,WORD y,PTRC var);
WORD BdaGui_zPrintItem(WORD x,WORD y,WORD lg,PTRC phrase,PTRC car,WORD coul1,WORD coul2,WORD fils);

// zGuiWin
WORD BdaGui_zWinScroll(WORD x,WORD y,WORD larg,WORD haut,SWORD dx,SWORD dy);

// special zxp
WORD BdaGui_zzzshadow(WORD x,WORD y, WORD n);
WORD BdaGui_zzshadow(WORD x1,WORD y1,WORD x2,WORD y2);
WORD BdaGui_MoveWindow(WORD newx,WORD newy);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
  }
#endif

#endif