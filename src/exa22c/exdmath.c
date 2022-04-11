/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDMATH.C 				*/
/*		Date 	:	19/04/1993				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDMATH_C
#define	_EXDMATH_C

/*	Variables du travail en B.C.D.					*/
/*	------------------------------					*/

#ifdef INTEL

	/* Work Zone for Assembler BCD Library	*/
	/* -----------------------------------  */

EXAWORD	rgm0;
EXAWORD	rgm1;
EXAWORD	rgm3;

/*
 *	These are now in BCD Libraray
 *	-----------------------------
 *
 *	EXABYTE	zona[48];
 *	EXABYTE	zonb[48];
 *	EXABYTE	zonr[48];
 *	EXABYTE	zoni[48];
 *	EXABYTE	zon4[48];
 */

#endif	/* INTEL */

EXABYTE	mathwork[6][BCDDIG];		/* B.C.D Work zones		*/
EXAWORD	rsig;				/* Result Sign			*/

#ifdef	ABAL_RTL
BINAIRE		workval1;
BINAIRE		workval2;
BINAIRE		workval3;
#endif

	/* ---------- */
#endif	/* _EXDMATH_C */
	/* ---------- */
	
