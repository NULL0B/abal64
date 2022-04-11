// ****************************************************************************
// * zSys.h
// * System module
// ****************************************************************************
#ifndef _ZSYS_H
#define _ZSYS_H

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
// zSysPupo
WORD BDA_WINAPI BdaSys_zPush(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha);
WORD BDA_WINAPI BdaSys_zPop();
WORD BDA_WINAPI BdaSys_zWinImpl(WORD x1,WORD y1,WORD x2,WORD y2);
WORD BDA_WINAPI BdaSys_zWinSetStack(WORD flag,WORD no,WORD x1,WORD y1,WORD x2,WORD y2);

// zSysSys
WORD BDA_WINAPI BdaSys_zInit(PTRC version);
WORD BDA_WINAPI BdaSys_zEnd();
WORD BDA_WINAPI BdaSys_zHide(WORD flag);
WORD BDA_WINAPI BdaSys_zShow(WORD flag,WORD x1,WORD y1,WORD x2,WORD y2);
WORD BDA_WINAPI BdaSys_zWait();
WORD BDA_WINAPI BdaSys_zAppliAlone(PTRC nomappli);
WORD BDA_WINAPI BdaSys_zWinVersion();
WORD BDA_WINAPI BdaSys_zWinNbBits();
WORD BDA_WINAPI BdaSys_zGetMaxy(WORD FAR PTR x,WORD FAR PTR y);
WORD BDA_WINAPI BdaSys_zWinHelp(PTRC ch1,SWORD type,PTRC ch2);
WORD BDA_WINAPI BdaSys_zSystemMenu(); 
WORD BDA_WINAPI BdaSys_zRGBColor(WORD set,WORD cprol,WORD r,WORD g,WORD b); 
WORD BDA_WINAPI BdaSys_zDefaultColor(WORD item,WORD r,WORD g,WORD b); 
WORD BDA_WINAPI BdaSys_ManageLoadgo(WORD IsBeforeLoadgo);

// zSysUtil
WORD BDA_WINAPI BdaSys_zRleCompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn);
WORD BDA_WINAPI BdaSys_zRleDecompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn);
WORD BDA_WINAPI BdaSys_zFind(PTRC chaine,PTRC achercher,WORD debut,WORD fin);
WORD BDA_WINAPI BdaSys_zIndex(PTRC chaine,CHAR car,WORD debut,WORD fin);
WORD BDA_WINAPI BdaSys_zOem2Ansi(PTRC chaine,WORD lg);
WORD BDA_WINAPI BdaSys_zAnsi2Oem(PTRC chaine,WORD lg);
WORD BDA_WINAPI BdaSys_zTab2Seq(WORD min,WORD max,PTRC car,PTRC sty,PTRC s,WORD x_min,WORD y, PTRC pseq,PTRC osty,WORD mode);
WORD BDA_WINAPI BdaSys_EmptyFunction();
WORD BDA_WINAPI BdaSys_zChDir(PTRC dir_nom);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

// zSysPuPo
WORD zSysPush_Internal(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha);
WORD zSysPop_Internal(VOID);

// zSysSys
VOID  SysInitShow(VOID);
VOID  SysIncreaseShow(PTI_RECTANGLE p);
VOID  SysShow(VOID);
VOID  SysHide(VOID);
VOID  SysWait( SWORD dixsec );

extern SWORD hide_show_counter;
#ifdef __cplusplus
  }
#endif

#endif
