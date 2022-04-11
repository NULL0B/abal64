/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXTVARB.H  				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXTVARB_H	/* If not already included			*/
#define	_EXTVARB_H	/* Avoid multiple inclusions			*/

#include "ex.h"			/* Global Executeur definitions		*/
#include "exmvirt.h"		/* Fictive machine definition		*/
#include "exfile.h"		/* File Acces rights			*/
#include "experm.h"		/* ASSIGN permissions mask definitions	*/
#include "exvtype.h"		/* ABAL DATA TYPE Definitions		*/
#include "exmacro.h"		/* ABAL Check Macros	  		*/
#include "exerrno.h"		/* Error Code and possible values	*/
#include "extmp.h"		/* Temporary allocation mechanism	*/
#include "excico.h"		/* CICO interface definition		*/
#include "exask.h"		/* ASK Control Variables		*/
#include "exwork.h"		/* WORK SET Description			*/

#ifdef	ABAL14
EXTERN	EXALONG SystemError;
#endif

#ifdef	ABAL21
EXTERN	EXAWORD meg_tfu;
#endif	

EXTERN	EXAWORD	simcbd;		/* File Read Write Code			*/
EXTERN	BPTR	fieldex;
EXTERN	EXAWORD	fieldlen;
EXTERN	BPTR	workptrw;
EXTERN	BPTR	descptrw;
EXTERN	EXAWORD	worktypw,workeepw;
EXTERN	EXALONG	fieldpos;
EXTERN	EXAWORD	fieldlog;


EXTERN	EXALONG 	rnd_var;
EXTERN	struct fichdt PTR AssignTable;
EXTERN	BPTR	bigbase;
EXTERN	EXAWORD	bigvlen;
EXTERN	EXALONG	bigvofs;
EXTERN	BPTR	keepvptr;
EXTERN	EXAWORD	keepvlen;
EXTERN	EXALONG	keepvofs;

EXTERN	EXAWORD	extwrite;

#ifdef LINEAR_MEM
EXTERN	BPTR	ExtendedMemory;
#endif

#endif	/* _EXTVARB_H */
	/* ---------- */

