/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXASK.H   				*/
/*		Date 	:	20/04/1993				*/
/*		Version :	1.4d / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXASK_H
#define	_EXASK_H

#ifndef	ABAL_RTL
/*	Global Variables used to control the ABAL ASK operations	*/
/*	--------------------------------------------------------	*/
/*	Buffer and control variables 	*/
/*	----------------------------	*/
EXTERN	EXAWORD	NationalLanguage;
EXTERN	EXABYTE	askbuf[];		/* Keyboard entry and workzone	*/
EXTERN	EXAWORD	askmust;		/* Nombre de caracteres Saisie 	*/
EXTERN	EXAWORD	maxask;			/* Global buffer limit		*/
EXTERN	EXAWORD	abufdex;		/* Current buffer pointer	*/

/*	HOTKEY management variables	*/
/*	---------------------------	*/
EXTERN	EXAWORD	LastJumpKey;		/* Key Last Causing Debranch	*/
EXTERN 	EXAWORD	askjmp[256];		/* Matrix of jump adresses   	*/
EXTERN 	EXAWORD	asktst[256];		/* Keys that cause jumps     	*/
EXTERN 	EXAWORD	jmpdex;			/* Number to test	     	*/

/*	FORMAT management variables	*/
/*	---------------------------	*/
EXTERN	EXAWORD 	askfmt;			/* Current Format byte 		*/
EXTERN	BPTR	fmtptr;			/* Pointer to current format string */
EXTERN	EXAWORD	fmtflg;
EXTERN	EXAWORD	oblig;
EXTERN	EXAWORD	fmtchk;
EXTERN	EXAWORD	fmtdex;
EXTERN	EXAWORD	fmtmax;
EXTERN	EXAWORD	fmtlen;
EXTERN	EXAWORD	fmtgod[];
EXTERN	EXAWORD	fmthld[];		/* Tracking of format work	*/
EXTERN	EXAWORD	fmtcpt[];		/* Maximum format count		*/

/*	Dynamic format control variables	*/
/*	--------------------------------	*/
EXTERN	EXAWORD	dynamat[DYNASIZE];	/* Dynamic format values	*/
EXTERN	EXAWORD	dynadex;		/* Current element index	*/
EXTERN	EXAWORD	dynamax;		/* Next free element index	*/


/*	GENERAL FLAGS and MASKS		*/
/*	-----------------------		*/

EXTERN	BINAIRE	askl;
EXTERN	BINAIRE	askc;			/* Line and column of Ask Start */

EXTERN 	EXAWORD	insflg;			/* Insert / overwrite semaph 	*/
EXTERN 	EXAWORD	askmask;		/* Ask mask for Input control 	*/

EXTERN	EXAWORD	askcolour;		/* ASK Colour value FORE | BACK	*/
EXTERN	EXAWORD	askatrib;		/* ASK Atribute value		*/
EXTERN	EXAWORD 	AtbContext;		/* Current screen atributs	*/
EXTERN  EXAWORD 	LastFore;		/* Current fore ground colour	*/ 
EXTERN  EXAWORD 	LastBack;		/* Current back ground colour	*/
EXTERN	EXAWORD	askerr;			/* ASK ERROR Target Adresse  	*/

#ifdef	ABAL21

EXTERN	EXAWORD	MouseAdresse;		/* Mouse Target Adresse		*/
EXTERN	EXAWORD	TimerAdresse;		/* Timer Target Adresse		*/

	/* ------  */ 
#endif	/* ABAL21  */
	/* ------  */ 

	/* -------- */ 
#endif	/* ABAL_RTL */
	/* -------- */

#endif	/* _EXASK_H */
	/* -------- */


