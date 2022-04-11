/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1998 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMOTOR - C				*/
/*		Version :	2.1e					*/
/*		Date 	:	02/09/1998				*/
/*									*/
/*----------------------------------------------------------------------*/


#include "exmotor.h"

/*	If Turbo 'C' or Microsoft	: Stack Probes OFF	*/
/*	-------------------------	------------------	*/

#ifdef INTEL
#include "exprag0.h"
#endif

#ifdef WIN32
EXTERN int __stdcall PubGetNoWait(void);
EXTERN EXAWORD mouse_arto;
//#define	let_windows_work	{ BPTR ofdex; ofdex = --fdex; while (PubGetNoWait()) ; if (fdex == ofdex) fdex++; else continue; }
#define	let_windows_work	{ BPTR ofdex; EXAWORD otcode; ofdex = --fdex; otcode = tcode; while (PubGetNoWait()) ; if (fdex == ofdex) { fdex++; tcode = otcode; } else continue; }
//#define	let_windows_work	{ BPTR ofdex; EXAWORD otcode; ofdex = fdex; otcode = tcode; while (PubGetNoWait()) ; fdex = ofdex; tcode = otcode; }
static EXABYTE notify_abqt = 0;
#endif

/*	Check for ABAL OPTION Programation Systeme	*/
/*	------------------------------------------	*/

#ifdef ABALPSYS
#include "exps.c"	
#endif

/*
 *	L L M O T O R ()
 *	----------------
 *
 *	Operating Cycle : T-code switching motor.
 *	
 *	This function may be called by MAIN()
 *	or from the IOWORK execution loop
 *
 */

EXAWORD	ExQui;		/* Identifier for Current LLMOTOR Level		*/
EXAWORD	fadj;		/* Tcode adjust value for calc and compare ops  */

EXAWORD	llmotor()
{
	register EXAWORD tcode;
	register EXAWORD e;

	do { 			/* While not Abort code (MOINS_UN) 	*/
		do {    	/* While not error (0) 			*/

#include "exswit.c"

			default		:
					tcode = SOFTERROR;
					err_val = EXER_FUNCWOT; 
					continue;
			}

			/* Check for External Variable rewrite needed */
			/* ------------------------------------------ */
			    if ( extwrite & 1 ) { 
				tcode = extrite(worktypw,descptrw,workeepw,workptrw);
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

	return(MOINS_UN);
}


/*
 *	M O T O R ( )
 *	-------------
 *
 *	Execution entry point from MAIN()
 *
 */

EXAWORD motor()
{

	/* Initialise T-Code Pointer */
	/* ------------------------- */
	fdex = TcodeSegment; 	/* Initialise T-Code Pointer	 */
	ExQui = 0;		/* Indicate 1st Level Entry	 */
	prndest  = 1;		/* Ensure Screen Device Selected */

	/* Enter Execution Loop */
	/* -------------------- */
	(VOID) llmotor();

	/* Establish file count and Liberate All memory	*/
	/* -------------------------------------------- */
	liberate_virtual_machine();

	return(0);

}

#ifdef INTEL
#include "exprag1.h"
#endif
