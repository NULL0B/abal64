/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXTIMER.H 				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXTIMER_H
#define	_EXTIMER_H


#include "exptr.h"

/*	---------------------------------	*/
/*	ON TIMER etc Management variables	*/
/*	---------------------------------	*/

EXTERN EXAWORD   	timersem;	/* Semaphore d'etat de le horloge 	*/
EXTERN EXAWORD   	timeradr;	/* Adresse de debranchement		*/
EXTERN EXAWORD   	timercpt;	/* Delai programmee de le horloge	*/
EXTERN EXAWORD    	timerret;	/* Adresse de retour de debranchement	*/
EXTERN EXABYTE 		descarto[7];	/* Arto Descriptor			*/
EXTERN EXABYTE		timerproc[ABALPTRSIZE];	/* Resolved Procedure Pointer4TimerCall	*/

#endif	/* _EXTIMER_H */
	/* ---------- */
