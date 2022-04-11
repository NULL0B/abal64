/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	MEMORY.H				*/
/*		Version :	1.1a					*/
/*		Date	:	20/08/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef MEMORYH
#define MEMORYH

#include <stdio.h>		/* Standard IO handling routines	*/
#include <stdlib.h>		/* Error return definitions		*/
#include <unistd.h>		/* Error return definitions		*/
#include <string.h>		/* Error return definitions		*/
#include <memory.h>		/* Error return definitions		*/
#include <errno.h>		/* Error return definitions		*/
#include "aplus.h"		/* Include standard definitions		*/

#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
#define	REDEFINE_MEMORY
#else
#ifdef	REDEFINE_MEMORY
#undef	REDEFINE_MEMORY
#endif
#endif
#else
#ifdef	REDEFINE_MEMORY
#undef	REDEFINE_MEMORY
#endif
#endif

#ifdef	REDEFINE_MEMORY
#include "exrdef.h"
#endif

#endif	/* MEMORYH */
	/* ------- */
