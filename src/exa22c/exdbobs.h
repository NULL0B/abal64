/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBOBS.H 				*/
/*		Date 	:	11/08/1993				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBOBS_H
#define	_EXDBOBS_H

/*	Gestion des variables en observation		*/
/*	------------------------------------		*/

#define	OBSPTR	struct exadb_observe SPTR

struct	exadb_observe {
	OBSPTR	next;
	OBSPTR	previous;
	EXAWORD	descriptor;
	EXAWORD	index;
	EXAWORD	andex;
	EXAWORD	type;
	EXAWORD	owner;
	};

#ifdef	_EXDBOBS_C
	OBSPTR	ObsBase;
	EXAWORD	ObservationCount;
#else
EXTERN	OBSPTR	ObsBase;
EXTERN	EXAWORD	ObservationCount;
#endif


#endif	/* _EXDBOBS_H */
	/* ---------- */
