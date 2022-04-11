/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXDBMOTO.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 
/*----------------------------------------------------------------------*/
/* Performs Tcode Execution for EXADB (Version 1.4a)			*/
/*----------------------------------------------------------------------*/
#define	DEBUGGER		/* Declare EXADB identity		*/

				/* ------------------------------------ */
#include "exmotor.h"		/* Include general debug header file	*/
#include "exproto1.h"		/* ------------------------------------ */

EXAWORD	ExQui;			/* Execution Caller identity		*/
				/* STARTUP or IOCYCLE			*/
				/* ------------------------------------ */
EXTERN	EXAWORD	StopStatus;
EXTERN  EXAWORD db_step_ctrl;
EXTERN	EXAWORD	DebugAssign;
EXTERN	EXAWORD	AssignBreak;

#ifdef	VERSION666
#include "extc32.h"
#endif

#ifdef WIN32
EXTERN int __stdcall PubGetNoWait(void);
EXTERN EXAWORD mouse_arto;
#define	let_windows_work	{ BPTR ofdex; ofdex = --fdex; while (PubGetNoWait()) ; if (fdex == ofdex) fdex++; else continue; }
static EXABYTE notify_abqt = 0;
#endif

#ifdef	ABAL32A
#include "extask.c"
#endif

/*
 *	D B M O T O R ()
 *	----------------
 *
 *	Operating Cycle : T-code switching motor.
 *	
 *	This function may be called by MAIN()
 *	or from the IOWORK execution loop
 *
 */

EXAWORD	fadj;		/* Tcode adjust value for calc and compare ops  */

EXAWORD	lldbmotor(EXAWORD previous_tcode)
{
	register EXAWORD tcode;
	register EXAWORD e;

	/* If Entry Tcode is not MOINS_UN then go to exection point */
	/* -------------------------------------------------------- */
	if ( previous_tcode != MOINS_UN ) {
		tcode = previous_tcode;
		goto dbentry;
		}

				/* ------------------------------------ */
	do { 			/* While not HARD ERROR (MOINS_UN) 	*/
				/* ------------------------------------ */
		do {    	/* While not SOFT ERROR (0) 		*/
				/* ------------------------------------ */

#include "exswit.c"

			default		:
					tcode = SOFTERROR;
					err_val = EXER_FUNCWOT; 
					continue;
			}

			/* Check for External Variable rewrite needed */
			/* ------------------------------------------ */
			    if ( extwrite & 1 ) { 

				/* Perform FIELD=NL rewrite operation */
				/* ---------------------------------- */
				tcode = extrite(worktypw,descptrw,workeepw,workptrw);

				/* Cancel REWRITE PENDING status flag */
				/* ---------------------------------- */
				extwrite &= 0x000E;
				}

#ifdef ABALME		/* If Extended memory Allowed */
			/* -------------------------- */
			    if ( extwrite & 2 ) { 

#ifndef LINEAR_MEM	/* If Not linear memory machine (Intel etc) */
			/* ---------------------------------------  */
				if ((tcode = xferout(keepvptr,keepvlen,keepvofs)) == SOFTERROR)
					continue;
#endif
				extwrite = 0; continue;
				}
#endif

		} while (tcode != SOFTERROR);

		/* Perform Error handling routines and STOP check */
		/* ---------------------------------------------- */
		if ( ExQui == 0 ) { tcode = erreurs(); }
		else		  { tcode = HARDERROR; }

	} while (tcode != HARDERROR) ;

	/* Indicate Execution Status Over */
	/* ------------------------------ */
	StopStatus = 1; return(MOINS_UN);
}

/*
 *	L L M O T O R ()
 *	----------------
 *	Simply calls the DB MOTOR for llmotor prototype compatiblity
 *
 */

EXAWORD	llmotor()
{
	return(lldbmotor(MOINS_UN));
}

