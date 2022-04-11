// ****************************************************************************
// * zsoSys.h
// * System module
// ****************************************************************************
#ifndef _ZSOSYS_H
#define _ZSOSYS_H

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------

// zSysPupo
WORD BdaSys_zPush(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha);
WORD BdaSys_zPop();

// zSysSys
WORD BdaSys_zInit(PTRC version);
WORD BdaSys_zEnd();
WORD BdaSys_zHide(WORD flag);
WORD BdaSys_zShow(WORD flag,WORD x1,WORD y1,WORD x2,WORD y2);
WORD BdaSys_zWait();

// zSysUtil
WORD BdaSys_zRleCompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn);
WORD BdaSys_zRleDecompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn);
WORD BdaSys_EmptyFunction();
WORD BdaSys_zFind(PTRC chaine,PTRC achercher,WORD debut,WORD fin);
WORD BdaSys_zTab2Seq(WORD min,WORD max,PTRC car,PTRC sty,PTRC s,WORD x_min,WORD y, PTRC pseq,PTRC osty,WORD mode);
WORD BdaSys_zIndex(PTRC chaine,CHAR car,WORD debut,WORD fin);
WORD BdaSys_zOem2Ansi(PTRC chaine,WORD lg);
WORD BdaSys_zAnsi2Oem(PTRC chaine,WORD lg);

// special zxp
WORD BdaSys_AnalAsfun(PTRC String,WORD iDeb, WORD iFin, WORD* pLg, WORD* pLgTot, WORD* pZa, WORD* pZc, WORD* pZf);
WORD BdaSys_CptCharInString(PTRC ch, WORD lg, PTRC car);
WORD BdaSys_TransformBadCar(WORD lg,PTRC str);
WORD BdaSys_Zadrs(PTRC adresse);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
  }
#endif

#endif