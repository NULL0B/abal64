/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMATH - H				*/
/*		Version :	2.1a					*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMATH_H
#define	_EXMATH_H

#include "ex.h"			/* Standard executeur definitions	*/
#include "exctype.h"		/* Character types			*/
#include "exmvirt.h"		/* Virtual machine definition		*/
#include "excico.h"		/* CICO interface definition		*/
#include "exask.h"		/* ASK Control Variables		*/
#include "extmp.h"		/* Temporary work control		*/
#include "exwork.h"		/* WORK SET Description			*/

EXTERN	EXABYTE	mathwork[6][BCDDIG];
EXTERN	EXAWORD	rsig;
#ifndef	ABAL_RTL
EXTERN	EXABYTE	sepdec;
#endif

EXTERN	BPTR	TcodeConstants;
EXTERN	BPTR	GlobalConstants;
EXTERN	BPTR	GlobalDataSegment;
EXTERN	BPTR	GlobalDataTable;


#include "exvtype.h"

	/* --------- */
#endif	/* _EXMATH_H */
	/* --------- */
