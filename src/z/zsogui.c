// ****************************************************************************
// * zsoGui.c
// * GUI module
// ****************************************************************************

#define  CI_MODULE_ID   0x0004

#include "wdef.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zsoext.h"
#include "zsogui.h"

// ****************************************************************************
// * BdaGui_zStatusMouse: (THO name) zstatusmouse - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zStatusMouse(PTRC string)
{
MI_TRACE_DCL_TFN("StatusMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zInitMouse: (THO name) zinitmouse - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zInitMouse(PTRC string)
{
MI_TRACE_DCL_TFN("InitMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zShowMouse: (THO name) zshowmouse - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zShowMouse(void)
{
MI_TRACE_DCL_TFN("ShowMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zHideMouse: (THO name) zinitmouse - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zHideMouse(void)
{
MI_TRACE_DCL_TFN("HideMouse");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zPrintVar: (THO name) zbprintvar - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zPrintVar(WORD state,WORD x,WORD y,PTRC var)
{
MI_TRACE_DCL_TFN("zPrintVar");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zPrintItem: (THO name) zprintitem - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zPrintItem(WORD x,WORD y,WORD lg,PTRC phrase,PTRC car,WORD coul1,WORD coul2,WORD child)
{
MI_TRACE_DCL_TFN("PrintItem");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zWinScroll: (THO name) zwin_scroll - ABAL API -
// *   Scroll une zone graphique pour optimiser les scrolling de liste
// *   Cette optimisation n'est pas implémentée sous UNIX
// *   jamais appelé dans la couche ABAL (voir zlifup,zlifdown z_lisfi.s)
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zWinScroll(WORD x,WORD y,WORD larg,WORD haut,SWORD dx,SWORD dy)
{
MI_TRACE_DCL_TFN("WinScroll");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zzzshadow: (THO name) zzzshadow - ABAL API - 
// *   ?????????
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zzzshadow(WORD x,WORD y, WORD n)
{
MI_TRACE_DCL_TFN("zzzshadow");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_zzshadow: (THO name) zzshadow - ABAL API - 
// *   ?????????
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_zzshadow(WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("zzshadow");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaGui_MoveWindow
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaGui_MoveWindow(WORD newx,WORD newy)
{
MI_TRACE_DCL_TFN("MoveWindow");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}
