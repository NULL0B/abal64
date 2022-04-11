/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCLF - C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	26/11/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
/* #define	DEBUG_ATTACH */
#ifndef	_EXCLF_C
#define	_EXCLF_C



#include "exf.h"		/* CLF functions Header			*/

#ifdef INTEL
#include "exprag0.h"		/* Stack Probes Off			*/
#endif

#include "exevent.c"		/* External Event Management functions 	*/

#include "expower.c"		/* B.C.D Standard form functions	*/

#ifndef PROLOGUE
#ifdef VMS
#include "exvmsdate.c"		/* VMS Date management functions	*/
#else
#include "exdate.c"		/* UNIX Date management functions	*/
#endif
#endif

#include "exprob.c"		/* Problematic functions (portabillity)	*/

/*	
 *	I S A V E ( Reg , n )
 *	---------------------
 *	Store Valeur 'n' to Register Reg
 *	
 */

VOID	isave(reg,x)
EXAWORD	reg,x;
{
if ( reg == 0 ) { 
	if ( worktyp1 == 1 ) { 
		balputw(x,workptr1); 	
		}
	else 	*((CPTR) workptr1) = (char) x;	
	}
else 	{ 
	freg [reg] = x; 
	xreg [reg] = 0; 
	}
return;
}

/*
 *	X T R A N S ( cptr1 , cptr2 , len , wot )
 *	-----------------------------------------
 *	Allows transcoding of a character
 *
 */

EXAWORD	xtrans( cptr1, cptr2, len , wot )
BPTR	cptr1;
BPTR	cptr2;
EXAWORD	len;
EXAWORD	wot;
{
	while ( len > 0 )
		if ( (EXAWORD) *(cptr1) == wot )
			return((wot = (EXAWORD) *(cptr2))); 
		else 	{ 
			cptr1++; 
			cptr2++; 
			len--; 
			}
	return(wot);
}

#include "exclf1.c"

#ifdef	ABAL21
#include "exclf6.c"		/* Pointer management functions		*/
#endif

#include "exclf7.c"
#include "exclf8.c"
#include "exclf9.c"


#ifdef	PROLOGUE
#undef	getenv
#include "exgetenv.c"
#endif

EXAWORD	ExaEnviron()
{
	/* Check String Length and Test for Error 114 */
	/* ------------------------------------------ */
	worklen2 = lenuse(workptr2,worklen2);
	StackCheck( worklen2 );

	/* Reset Result Variable To SPACE */
	/* ------------------------------ */
	(VOID) memset((BPTR) workptr1,' ',(USINT) worklen1);

	/* If Not An Empty String */
	/* ---------------------- */
	if ( worklen2 > 0 ) {

		/* Transfer to Temporary Zone */
		/* -------------------------- */
		memcpy((BPTR) (TcodeByteStack + worktop),workptr2,worklen2);

		/* Terminate for Systeme */
		/* --------------------- */
		*(TcodeByteStack + worktop + worklen2) = (EXABYTE) 0;

		/* Perform Systeme Environment Research */
		/* ------------------------------------ */
		if ((workptr3 = (BPTR) Mgetenv((BPTR) (TcodeByteStack + worktop))) != (BPTR) 0)

			/* Calculate Result Length */
			/* ----------------------- */
			if ((worklen3 = strlen((BPTR) workptr3)) > 0)

				/* Transfer result to Result Zone */
				/* ------------------------------ */
				(VOID) memcpy((BPTR) workptr1,(BPTR) workptr3, ( worklen3 > worklen1 ? worklen1 : worklen3 ));
		}

	/* Return GOOD Result (No Errors) */
	/* ------------------------------ */
	return(1);
}

#include "exclf10.c"

/*
 *	E X V A R P T R ( desc )
 *	------------------------
 *	Returns the offset of a variable WRT the Variable Base Segment
 */

EXAWORD	exvarptr( desc )
EXAWORD	desc;
{
	EXAWORD	reg,work;
	EXAWORD	awtyp,awlen;
	EXAWORD	temp,temp2;
	BPTR	awdesc;

	err_val = 0;

	if ( desc == 3 ) 
		reg = (EXAWORD) *(fdex++);
	else	{
		freg [ 0 ] = Tcodeword( fdex ); 
		xreg [ 0 ] = (desc & 3);
		fdex += WORDSIZE; reg = 0;
		}
	if ( xreg [ reg ] != VARIABLE ) { 
		err_val = ABAL_STR4NUM; 
		return(MOINS_UN);  
		}
	if ( freg [ reg ] & ISLOCAL  ) 
		awdesc = LocalDataTable; 
	else	awdesc = GlobalDataTable; 

	awdesc += ( freg [ reg ] & TOGLOBAL );
	awtyp = Tcodeword( awdesc ); awdesc += WORDSIZE;
	work  = Tcodeword( awdesc ); awdesc += WORDSIZE;
	if     ( awtyp & SPECIALE  ) 
		awdesc += WORDSIZE;
	switch ( awtyp & VARB_ISOL ) {
		case VARB_INT8 : awlen = 1; break;
		case VARB_INT16: awlen = 2; break;
		default	       : awlen = Tcodeword( awdesc); 
				 awdesc += WORDSIZE;
		}
	if (( awtyp & NDX1st) != 0 ) { 
		temp = ireg [reg];
		IndexCheck( temp , awdesc );
		work += ( awlen * ( temp - 1 ) );
		if (( awtyp & NDX2nd) != 0 ) {
			temp = areg [reg];
			temp2 = Tcodeword( awdesc); awdesc += WORDSIZE;
			IndexCheck( temp , awdesc );
			temp2 *= awlen; work += ( (temp2 * awlen) * ( temp - 1 ) );
			}
		}
	return( work );		
}

#include "exclf11.c"
#include "exclf12.c"
#include "exclf13.c"
#include "exclf14.c"
#include "exclf15.c"
#include "exclf5.c"

#ifdef INTEL
#include "exprag1.h"
#endif

	/* -------- */
#endif	/* _EXCLF_C */
	/* -------- */
