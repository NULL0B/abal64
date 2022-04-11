/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990
 *      Module  : ATR
 *      Fichier : ATRDEBUG.HS
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

// YT : The next line has been removed because it redefines WORD (unsigned int / unsigned short)
// #define WORD unsigned int
#include <fcntl.h>
#include <stdio.h>

static WORD atr_debug;	/* Flag de mise en marche de debug */
static FILE * atr_file_dbg;	/* Fichier de trace de mise au point */

#define dbgprintf(d) if ( atr_debug & d ) fprintf

/*		Structure de debug de la memoire 	*/
/*		--------------------------------	*/
#define DbgMem struct _DbgM
/*jph DbgMem {*/
struct _DbgM {
	char nom[10];		/* Type de memoire */
	char *pt;		/* Pointeur reel */
	long no;		/* no d'ordre d'allocation */
	long nb;		/* nombre d'octets alloues */
	DbgMem *suiv;		/* suivant */
};

static DbgMem *lstmem;
static long dbgnballoc;
static long dbgmem;
static long dbgmemno;

#endif /* _ATRDEBUG */
/* -------------------- Fichier : atrdebug.hs -----------------------*/




