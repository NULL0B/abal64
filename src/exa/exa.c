/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXA - C  				*/
/*		Date 	:	07/05/1996				*/
/*		Version :	2.1d              			*/
/*									*/
/*----------------------------------------------------------------------*/

#define EXECUTEUR		/* Generation of  EXA			*/

#ifndef ABAL14
#ifndef ABAL21
#include "ex.c"			/* Executeur Startup Module		*/
#else
#include "exmain.c"		/* Revised Executeur Startup Module	*/
#endif
#else
#include "exmain.c"		/* Revised Executeur Startup Module	*/
#endif
#include "exd.c"		/* Executeur Global Data Segment	*/
#include "exi.c"		/* Executeur initialisation functions	*/

void	check_debug_assign(int handle) { return; } 




