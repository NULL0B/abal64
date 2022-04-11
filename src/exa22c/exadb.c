/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXADB - C   				*/
/*		Date 	:	27/12/1991				*/
/*		Version :	1.2d / 1.3a / 1.4b / 1.5a		*/
/*									*/
/*----------------------------------------------------------------------*/
#define DEBUGGER
#ifndef	 ABAL21
#ifndef  ABAL14
#include "ex.c"			/* Executeur Startup Module		*/
#else
#include "exmain.c"		/* Revised Executeur Startup Module	*/
#endif
#else
#include "exmain.c"		/* Revised Executeur Startup Module	*/
#endif
#include "exd.c"		/* Executeur Global Data Segment	*/
#include "exi.c"		/* Executeur initialisation functions	*/

