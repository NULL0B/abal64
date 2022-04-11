#ifndef __LKDEBUG_H__
#define __LKDEBUG_H__

/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990
 *      Module  : ATR
 *      Fichier : LKDEBUG.H
 *      Version : 2.1a
 *      Date    : 23/03/93
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Debug interne du traducteur]
 *
 * 
 */

 /*
 * Mises a jour :
 * ------------
 */
#ifdef _ATRDEBUG
#define EXT_ATRDEBUG
#else
#define EXT_ATRDEBUG extern
#endif /* _ATRDEBUG */

/* Masque de debug : fonction dbgoption */

#define AMEM		0x0001	/* Debug memoire */

#ifdef LINT_ARGS
EXT_ATRDEBUG void dbginit(char *);
EXT_ATRDEBUG void dbgfin(void);
EXT_ATRDEBUG void dbgoption(WORD);
EXT_ATRDEBUG char *dbgalloc(char *, long);
EXT_ATRDEBUG void dbgfree(char *);
EXT_ATRDEBUG void dbgstat(void);
#else
EXT_ATRDEBUG void dbginit();
EXT_ATRDEBUG void dbgfin();
EXT_ATRDEBUG void dbgoption();
EXT_ATRDEBUG char *dbgalloc();
EXT_ATRDEBUG void dbgfree();
EXT_ATRDEBUG void dbgstat();
#endif /* LINT_ARGS */


/* -------------------- Fichier : atrdebug.hs -----------------------*/

#endif