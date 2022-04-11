/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSQR - C				*/
/*		Date 	:	21/02/1989				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "exmath.h"

/*
 *	R A C I N E ( )
 *	---------------
 *	Calculates the SQUARE ROOT of the BCD @ WorkSet2 and stores
 *	the result @ WorkSet1 
 *	Returns either GOODRESULT ==> OK all went well during calculation
 *		    or SOFTERROR  ==> Error encountered stored in err_val
 *
 *			old = workptr2 / 2
 *			new = 0.5((a/old) + old)
 */

UBINAIR	Racine()
{
	UBINAIR	x;		/* Loop Control Variable	*/
	EXBPTR	resptr;		/* Result pointer		*/
	UBINAIR	reslen;		/* Result Length		*/
	EXBPTR	sqrptr;		/* Source pointer		*/
	UBINAIR	sqrlen;		/* Source Length		*/
	EXABYTE	zerofive[2];	/* Constant 0.5 :: CA 5F	*/
	EXABYTE	newapp[12];	/* 1st approximation		*/
	EXABYTE	oldapp[12];	/* 2nd approximation		*/

	/* Create Constant 0.5 */
	/* ------------------- */
	zerofive[0] = (EXABYTE) 0x00CA;	zerofive[1] = (EXABYTE) 0x005F;

	/* Duplicate Original Workset infos */
	/* -------------------------------- */	
	resptr = workptr1; reslen = worklen1;
	sqrptr = workptr2; sqrlen = worklen2;

	/* Calculate 1st approximation = Source / 2 */
	/* ---------------------------------------- */
	worklen3 = 12; workptr3 = (EXBPTR) newapp;
	worklen1 = 2;  workptr1 = (EXBPTR) zerofive;
	(void)	bcdcalc(2);

	for (x = 0; x < 12; x++ ) {

		/* Establish approximation result Pointer */
		/* -------------------------------------- */
		if ( x & 1 ) 	{
			workptr3 = (EXBPTR) newapp; 	
			workptr2 = (EXBPTR) oldapp; 	
			}
		else	{
			workptr3 = (EXBPTR) oldapp;
			workptr2 = (EXBPTR) newapp; 	
			}
		worklen3 = 12; worklen2 = 12;
	
		/* Divide Original Value by previous appoximation */
		/* ---------------------------------------------- */
		workptr1 = sqrptr; worklen1 = sqrlen;
		(void) bcdcalc(3);

		/* Add previous aproximation to Result */
		/* ----------------------------------- */
		workptr1 = workptr3;
		worklen1 = 12; worklen2 = 12; worklen3 = 12;
		(void) bcdcalc(1);

		/* Divide Result to Create new Approximation by 2 */
		/* ---------------------------------------------- */
		workptr1 = workptr3; workptr2 = (EXBPTR) zerofive;
		worklen1 = 12; worklen2 = 2; 
		if ( x == 11 ) {
			workptr3 = resptr; worklen3 = reslen;
			}
		else	{
			worklen3 = 12;
			}
		(void) bcdcalc(2);
		}
	return(1);
}




