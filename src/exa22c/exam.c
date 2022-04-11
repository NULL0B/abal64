/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXAM - C   				*/
/*		Version :	1.4a					*/
/*		Date 	:	26/10/1990				*/
/*									*/
/*----------------------------------------------------------------------*/
#define EXECUTEUR
#define EXAMINE
#ifdef	ABAL14
#include "exmain.c"
#else
#include "ex.c"			/* Executeur Startup Module		*/
#endif
#include "exi.c"		/* Executeur initialisation functions	*/
#include "exd.c"		/* Executeur Global Data Segment	*/
