/*
 *	Projet  : ABAL
 *	Module  : EXA
 *	Fichier : exdbglob.h
 *	Date    : 17/03/2004
 *	Debuggueur ABAL
 */

#ifndef _EXDBGLOB_H
#define _EXDBGLOB_H

#ifdef _EXDBGLOB_C
#undef  EXTERN
#define EXTERN 
#else
#undef  EXTERN
#define EXTERN extern
#endif

EXTERN unsigned long		IsVariableShow;	/* #BG: To modify motor treatment about pointer members not already allocated */
EXTERN unsigned long		FirstStepFlag;		/* #BG: Indicates first Step Over/Into */

/*	Step over trap managment */
/*	------------------------ */
EXTERN unsigned char*	StepOverTrap;		/* #BG: Current trap for Step Over mode (TRAPTR) */
EXTERN unsigned long		StepOverMode;		/* #BG: Indicates if Step Over mode is active */
EXTERN unsigned long		StepIntoMode;		/* FCH: Indicates if Step Into mode is active */

EXTERN unsigned long		IsReloadBreakList;	/* #BG: Indicates if breakpoints list must be reloaded */

EXTERN char*				LinePtr;					/* New line pointer for Resume	  */

/* Caller Identification */
/* --------------------- */
EXTERN unsigned long		CallerId;			/* FCH: Indicates who calls the wexadb.dll initialised by SetInfo */
#endif
