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
SWORD sf_anfc(char FAR *,char FAR *);   
SWORD sf_open(SWORD FAR PTR,char FAR *);   
SWORD sf_cfile(SWORD FAR PTR,char FAR *); 
SWORD sf_dfile(char FAR *);    
SWORD sf_read(SWORD,SWORD,char FAR *,SWORD);
SWORD sf_write(SWORD,SWORD,char FAR *,SWORD);
SWORD sf_close(SWORD);

#ifdef __cplusplus
  }
#endif

#endif
