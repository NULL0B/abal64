/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCODE - C				*/
/*		Version :	1.4a					*/
/*		Date 	:	05/10/1990				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "excode.h"		/* Common and Global Definitions	*/

#ifdef INTEL
#include "exprag0.h"		/* Stack Probes OFF			*/
#endif

#ifndef	UNIX
VPTR	Qalloc( EXAWORD );	/* Quick allocation Prototype		*/
#endif

#include "exsegm.c"		/* Gestion des Segments			*/
#include "exproc.c"		/* Gestion des Procedures		*/

#ifdef	ABAL21

/*	-----------------------------------------------------		*/
/*	Retour de Segment ou Procedure avec Remontee d'erreur		*/
/*	-----------------------------------------------------		*/
/*	F _ R T E ( )							*/
/*	-------------							*/

EXAWORD	f_leave()
{
	/* Repeat Until Error Trap Encountered or End of Stacked Contexts */
	/* -------------------------------------------------------------- */
	while (!( sicico & ERROR_TEST )) {

		/* If Current Context is a Procedure */
		/* --------------------------------- */
		if (sicico & ONSEM_PRC) {
			if ( procedure_exit(0) == SOFTERROR )
				return( SOFTERROR );
			}

		/* Otherwise it must be a Segment */
		/* ------------------------------ */
		else 	{
			if ( ret_seg( 0 ) == SOFTERROR )
				break;
			}
		}

	/* Indicate Success to Caller */
	/* -------------------------- */
	return( GOODRESULT );
}

EXAWORD	f_rte( fx )
EXAWORD	fx;
{
	EXAWORD	local_error;
	EXAWORD	x,y;

	/* Recover Error Value to be Returned */
	/* ---------------------------------- */
	if ( argset1(((fx >> 1) & 0x0003), 0 ) == SOFTERROR )
		return( SOFTERROR );
	else	local_error = workval1;

	if ( local_error == 0 )
		return( GOODRESULT );

	/* Leave all until Error trap or end of stack */
	/* ------------------------------------------ */
	if ( f_leave() != SOFTERROR )
		err_val = local_error;

	/* Indicate Error Status */
	/* --------------------- */
	return( SOFTERROR ); 

}
#else
EXAWORD	f_rte()
{
	err_val = 56;
	return( SOFTERROR );
}
#endif

#ifdef INTEL	
#include "exprag1.h"		/* Stack Probes ON			*/
#endif
