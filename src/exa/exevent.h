/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2005 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXEVENT.H 				*/
/*		Version :	3.1b       				*/
/*		Date 	:	14/04/2005				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXEVENT_H
#define	_EXEVENT_H

#include "exptr.h"

EXTERN	EXAWORD		EventChannel;

#ifdef	ABAL21
EXTERN	EXAWORD		HardEvent;
EXTERN	EXAWORD		EventSignal;
EXTERN	unsigned long	EventTime;
#endif

EXTERN EXABYTE		eventproc[ABALPTRSIZE];	/* Resolved Procedure Pointer4EventCall	*/

#endif	/* _EXEVENT_H */
	/* ---------- */

