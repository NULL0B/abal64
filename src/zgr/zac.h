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
EXAWORD BDA_API BdaZac_init(SWORD b_length);
EXAWORD BDA_API BdaZac_open(SWORD no,char FAR * nom,SWORD mode);
EXAWORD BDA_API BdaZac_nextline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l);
EXAWORD BDA_API BdaZac_prevline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l);
EXAWORD BDA_API BdaZac_firstline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l);
EXAWORD BDA_API BdaZac_lastline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l);
EXAWORD BDA_API BdaZac_read(SWORD no,char FAR * ligne,SWORD lg);
EXAWORD BDA_API BdaZac_close(SWORD no);
EXAWORD BDA_API BdaZac_create(SWORD no,char FAR * nom);
EXAWORD BDA_API BdaZac_write(SWORD no,char FAR * chaine,SWORD lg);

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

#ifdef __cplusplus
  }
#endif

#endif
