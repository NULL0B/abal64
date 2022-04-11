// ****************************************************************************
// * zsoTxt.h
// * TEXT module
// ****************************************************************************
#ifndef _ZSOTXT_H
#define _ZSOTXT_H

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
// zTexPrin
WORD BdaTxt_zPrint(WORD lg,PTRC str,SWORD dx,SWORD dy);
WORD BdaTxt_zPrintXYWithSeq(WORD x,WORD y,WORD lg,PTRC phrase);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
  }
#endif

#endif