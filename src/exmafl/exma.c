/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1996
 *	Module  : EXA
 *	Fichier : EXMA.C
 *	Version : 1.1c
 *	Date    : 01/04/96
 *	Systeme : Windows 3 / NT / MS-DOS / Unix
 *
 *	Executeur ABAL
 *
 *	[Interface methodes d'acces - Code]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	cf. EXMA.HIS
 *	24/04/95 : passage en 1.1b = unification entre tous les OS
 *	18/05/95 : passage a l'indice FLFILE no 3 et CRITERIA no 3
 *	18/10/95 : consolidation Unix / Dos / Windows
 *	22/10/95 : corrections perte de fins de commentaires !!!
 *	01/04/96 : support des noms de fichiers longs
 *
 */

/*T-------------------------------------------------------------------------
 *
 * EXMA : implemente les appels aux methodes suivantes :
 *		- acces direct
 *		- acces sequentiel pur
 *		- acces sequentiel indexe
 *		- multicriteres
 *		- base de donnees
 * sur la base d'une API de type FLFILE et CRITERIA.
 *
 * Selon l'environnement, le lien avec les methodes d'acces peut etre
 * dynamique (DOS / Windows), ou bien statique (Unix).
 *
 * ------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------
 *
 * Options de compilation conditionnelle :
 *
 *	WIN16			Windows 16 bits (3.x / WoW)
 *	WIN32			Windows 32 bits (NT natif)
 *	DOS			MS-DOS + Phar Lap 286 v2.1
 *	ISUNIX			Unix
 *
 * ------------------------------------------------------------------------- */

/* Inclusions importees */

#include "exma.h"


/* Inclusions des sources systeme-dependant : a garder
 * avant les autres inclusions a cause des redefinitions de
 * fonctions en macros
 */

#ifdef WIN1632
#include "exmawin.c"			/* Windows 3 / NT */
#endif
#ifdef DOS
#include "exmados.c"			/* MS-DOS + PharLap */
#endif
#ifdef ISUNIX
#include "exmaunix.c"			/* Unix */
#endif


/* Inclusions des sources non systeme-dependant */

#include "exmafl.c"			/* acces direct et sequentiel pur */
#include "exmasi.c"			/* acces sequentiel indexe */
#include "exmamc.c"			/* acces multicriteres */
#include "exmabd.c"			/* acces base de donnees */

