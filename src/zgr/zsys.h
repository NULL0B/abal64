// ****************************************************************************
// * zSys.h
// * System module
// ****************************************************************************
#ifndef _ZSYS_H
#define _ZSYS_H

#include "bda.h"

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
// zSysPupo
EXAWORD BDA_API BdaSys_zPush(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha);
EXAWORD BDA_API BdaSys_zPop();
EXAWORD BDA_API BdaSys_zWinImpl(WORD x1,WORD y1,WORD x2,WORD y2);
EXAWORD BDA_API BdaSys_zWinSetStack(WORD flag,WORD no,WORD x1,WORD y1,WORD x2,WORD y2);

// zSysSys
EXAWORD BDA_API BdaSys_zInit(char FAR * version);
EXAWORD BDA_API BdaSys_zEnd();
EXAWORD BDA_API BdaSys_zHide(WORD flag);
EXAWORD BDA_API BdaSys_zShow(WORD flag,WORD x1,WORD y1,WORD x2,WORD y2);
EXAWORD BDA_API BdaSys_zWait();
EXAWORD BDA_API BdaSys_zAppliAlone(char FAR * nomappli);
EXAWORD BDA_API BdaSys_zWinVersion();
EXAWORD BDA_API BdaSys_zWinNbBits();
EXAWORD BDA_API BdaSys_zGetMaxy(WORD FAR PTR x,WORD FAR PTR y);
EXAWORD BDA_API BdaSys_zWinHelp(char FAR * ch1,SWORD type,char FAR * ch2);
EXAWORD BDA_API BdaSys_zSystemMenu(); 
EXAWORD BDA_API BdaSys_zRGBColor(WORD set,WORD cprol,WORD r,WORD g,WORD b); 
EXAWORD BDA_API BdaSys_zDefaultColor(WORD item,WORD r,WORD g,WORD b); 
EXAWORD BDA_API BdaSys_ManageLoadgo(WORD IsBeforeLoadgo);

// zSysUtil
EXAWORD BDA_API BdaSys_zRleCompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn);
EXAWORD BDA_API BdaSys_zRleDecompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn);
EXAWORD BDA_API BdaSys_zFind(char FAR * chaine,char FAR * achercher,WORD debut,WORD fin);
EXAWORD BDA_API BdaSys_zIndex(char FAR * chaine,CHAR car,WORD debut,WORD fin);
EXAWORD BDA_API BdaSys_zOem2Ansi(char FAR * chaine,WORD lg);
EXAWORD BDA_API BdaSys_zAnsi2Oem(char FAR * chaine,WORD lg);
EXAWORD BDA_API BdaSys_zTab2Seq(WORD min,WORD max,char FAR * car,char FAR * sty,char FAR * s,WORD x_min,WORD y, char FAR * pseq,char FAR * osty,WORD mode);
EXAWORD BDA_API BdaSys_EmptyFunction();
EXAWORD BDA_API BdaSys_zChDir(char FAR * dir_nom);

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
VOID  SysFlush(VOID);

extern SWORD hide_show_counter;
#ifdef __cplusplus
  }
#endif

#endif
