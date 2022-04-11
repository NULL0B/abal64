// ****************************************************************************
// * zac.h
// * Text file access functionnalities
// ****************************************************************************
#ifndef _ZAC_H
#define _ZAC_H

// ************************************
// * ABAL API
// ************************************

#ifdef __cplusplus
  extern "C" {
#endif
// ----------------------------------------------------------------------------
// - BDA functions
// ----------------------------------------------------------------------------
WORD BDA_WINAPI BdaZac_init(SWORD b_length);
WORD BDA_WINAPI BdaZac_open(SWORD no,PTRC nom,SWORD mode);
WORD BDA_WINAPI BdaZac_nextline(SWORD no,PTRC ligne,SWORD FAR PTR lg_l);
WORD BDA_WINAPI BdaZac_prevline(SWORD no,PTRC ligne,SWORD FAR PTR lg_l);
WORD BDA_WINAPI BdaZac_firstline(SWORD no,PTRC ligne,SWORD FAR PTR lg_l);
WORD BDA_WINAPI BdaZac_lastline(SWORD no,PTRC ligne,SWORD FAR PTR lg_l);
WORD BDA_WINAPI BdaZac_read(SWORD no,PTRC ligne,SWORD lg);
WORD BDA_WINAPI BdaZac_close(SWORD no);
WORD BDA_WINAPI BdaZac_create(SWORD no,PTRC nom);
WORD BDA_WINAPI BdaZac_write(SWORD no,PTRC chaine,SWORD lg);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
  }
#endif

#endif
