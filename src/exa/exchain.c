/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCHAIN - C				*/
/*		Date 	:	09/05/1990				*/
/*		Version :	1.4a 					*/
/*									*/
/*----------------------------------------------------------------------*/
/* INCLUDE file for EXNGF.C						*/
/*----------------------------------------------------------------------*/
#ifndef	EXCHAINC		/* If not already included		*/
#define EXCHAINC		/* Avoid multiple inclusions		*/
				/* ------------------------------------ */

#include "exngf.h"

/*
 *	S F _ C H A I N ( )
 *	-------------------
 *
 *	This function is called to initialise or liberate a CHAIN 
 *	operation for the next STOP instruction.
 *	The file table is inspected for a valid filename entry
 *	which is then analysed and prepared as a tcode file name
 *	with the addition of default paths and extensions
 *	The Aguament file is also prepared and FILETERM terminated.
 *
 *	On entry : FDEX ==> possible NGF arguaments
 *
 *	Returns  : ZERO ==> No Error ELSE error value
 *
 *	Possible Errors :	27	no memory for arg storage
 *				30	empty filename string
 *				56	incorrect file assign type
 *
 */

EXAWORD	sf_chain()
{
#ifdef RT_AIX
	BPTR	allocate_for_assign( );
	void	liberate_for_assign( );
#else
	BPTR	allocate_for_assign( EXAWORD, EXAWORD );
	void	liberate_for_assign( BPTR );
#endif
	/* Clear all Error variables */
	/* ------------------------- */
	errno = 0; err_val = 0; 

	/* Test for annulation of CHAIN */
	/* ---------------------------- */
	if ( lfh == 0 )
		return((chain = 0));

	/* Eliminate Empty Strings */
	/* ----------------------- */
	if ( fidname == (BPTR) 0 ) 
		return(30);

	/* Eliminate all highlevel file access methods */
	/* ------------------------------------------- */
	if ( fidperm & NGF_TYP )     
		return(56);

	/* Check for Buffer already Existant */
	/* --------------------------------- */
	if ( fidperm & 0x0200 ) { 

		/* If True then liberate it */
		/* ------------------------ */
		liberate(fidbuff); 
		fidperm &= 0xFDFF; 
		fidbuff = (BPTR) 0; 
		}

	/* Evaluate Argument */
	/* ----------------- */
	if ( fargset(2) != SOFTERROR ) {

		/* Attempt to Allocate Permanant storage space for ARG */
		/* --------------------------------------------------- */
		if ((workptr1 = (BPTR) allocate((USINT) worklen2+2)) == (BPTR) 0)
			return(EXER_MEMFULL); 

		/* For BAL compatibillity remove leading Spaces */
		/* -------------------------------------------- */
		while ( worklen2 > 0 ) {
			if ( *workptr2 != ' ' ) 
				break;
			else	{ 
				workptr2++; worklen2--; 
				}
			}

		/* Copy ARG to arg storage Zone */
		/* ---------------------------- */
		if ( worklen2 > 0 )
			memcpy(workptr1,workptr2,(USINT) worklen2);

		/* Terminate Arguament String */
		/* -------------------------- */
		*(workptr1 + worklen2) = (EXABYTE) 0x000D;
		*(workptr1 + worklen2 + 1) = (EXABYTE) 0x0000;

		/* Establish File Control Table Infos */
		/* ---------------------------------- */
		fidbuff =  workptr1; 		/* Pointer to ARG string 	*/
		fidblen =  (worklen2 + 2);	/* Total Length of ARG	 	*/
		fidperm |= 0x0200;		/* Indicate buffer needs liberate	*/
		chain   =  lfh;			/* Indicate Chainage Table ID	*/
		err_val =  0;			/* Clear Error Value		*/
		}
	else 	{
		/* If Error Indicates no Further ARGS */
		/* ---------------------------------- */
		if ( err_val == ABAL_TCODCODE ) {

			/* Reset File Control Table Infos OK */
			/* --------------------------------- */
			fidbuff = (BPTR) 0; 	/* No Buffer			*/
			fidblen = 0;		/* No Buffer			*/
			err_val = 0; 		/* Clear Errors			*/
			chain   = lfh;		/* Indicate Chainage Table ID	*/
			}
		}

	/* If no Error has occured Analysis of Filename */
	/* -------------------------------------------- */
	if ( err_val == 0 ) {

		/* Prepare TCODE FILE NAME */
		/* ----------------------- */
		worklen1 = TcodeFileName( (BPTR) askbuf , fidname );

		/* Allocate permenant storage in ASSIGN TABLE */
		/* ------------------------------------------ */
		if ((workptr1 = (BPTR) allocate_for_assign((USINT) (worklen1+1), lfh )) != (BPTR) 0 ) {

			/* Store in file table having liberated original */
			/* --------------------------------------------- */
			(void) memcpy( (BPTR) workptr1 , (BPTR) askbuf , (USINT) worklen1 );
			*(workptr1 + worklen1) = FILETERM;
			liberate_for_assign((BPTR) fidurl );	
			fidurl = workptr1;
			fidname = workptr1;
			}
		else	/* Signal Memory allocation error */
			/* ------------------------------ */
			err_val = 27;
		} 

	/* Return Resulting Error Value */
	/* ---------------------------- */
	return(err_val);
}

#endif	/* EXCHAINC */
	/* -------- */

/* ------ */
/* E.O.F. */
/* ------ */
