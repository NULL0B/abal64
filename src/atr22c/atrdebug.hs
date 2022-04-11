/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : ATRDEBUG.HS
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Debug interne du traducteur]
 *
 */

 /*
 * Mises a jour :
 * ------------
 */

#ifdef _ATRDEBUG

static BINAIRE atr_debug;	/* Flag de mise en marche de debug */
static FILE *atr_file_dbg;	/* Fichier de trace de mise au point */

#define dbgprintf(d) if ( atr_debug & d ) fprintf

/*		Structure de debug de la memoire 	*/
/*		--------------------------------	*/
#define DbgMem struct _DbgM
DbgMem {
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

