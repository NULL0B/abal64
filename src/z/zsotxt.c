// ****************************************************************************
// * zsoTxt.c
// * TEXT module
// ****************************************************************************

#define  CI_MODULE_ID   0x0008

#include "wdef.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zsoext.h"
#include "zsotxt.h"

// ****************************************************************************
// * BdaTxt_zPrint: (THO name) zprint - ABAL API -
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaTxt_zPrint(WORD lg,PTRC str,SWORD dx,SWORD dy)
{
MI_TRACE_DCL_TFN("Print");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaTxt_zPrintXYWithSeq: (THO name) zprintxy - ABAL API -
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaTxt_zPrintXYWithSeq(WORD x,WORD y,WORD lg,PTRC phrase)
{
MI_TRACE_DCL_TFN("PrintXY_Seq");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

