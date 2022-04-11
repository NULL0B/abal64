// ****************************************************************************
// * zAsmUtil.h
// * ASM module
// ****************************************************************************
#ifndef _ZASMUTIL_H
#define _ZASMUTIL_H


#ifdef __cplusplus
  extern "C" {
#endif

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

/* Gestion fichiers */
SWORD sf_anfc(PTRC,PTRC);   
SWORD sf_open(SWORD FAR PTR,PTRC);   
SWORD sf_cfile(SWORD FAR PTR,PTRC); 
SWORD sf_dfile(PTRC);    
SWORD sf_read(SWORD,SWORD,PTRC,SWORD);
SWORD sf_write(SWORD,SWORD,PTRC,SWORD);
SWORD sf_close(SWORD);

#ifdef __cplusplus
  }
#endif

#endif
