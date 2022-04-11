/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic		*/
/*									*/
/*		Module  :	EXCODE - C				*/
/*		Version :	1.4a					*/
/*		Date 	:	21/03/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "excode.h"		/* Common and Global Definitions	*/
#include "extrace.h"

#ifdef WEXADBDLL
#include "exdbglob.h"
#endif

#ifdef INTEL
#include "exprag0.h"		/* Stack Probes OFF			*/
#endif

#ifndef	UNIX
VPTR	Qalloc( unsigned short );	/* Quick allocation Prototype	*/
#endif

EXAWORD kode_b_lode( BPTR , EXAWORD , EXAWORD );
BPTR kode_lode( EXAWORD , EXAWORD );

#ifdef	ABAL64
extern EXAWORD	err_typ;
extern EXAWORD	err_len;
extern EXAWORD 	err_ptr;
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
#ifdef	ABAL64
	EXAWORD	local_type;
#endif

	/* Recover Error Value to be Returned */
	/* ---------------------------------- */
	if ( argset1(((fx >> 1) & 0x0003), 0 ) == SOFTERROR )
		return( SOFTERROR );
	else	
#ifdef	ABAL64
	{
		/* ------------------ */
		/* store the work set */
		/* ------------------ */
		err_len = worklen1;
		err_ptr = workptr1;

		switch ((err_typ = worktyp1))
		{
		case	VARB_INT8	:
		case	VARB_INT16	:
		case	VARB_INT32	:
		case	VARB_INT64	:
#endif
			/* ---------------------------- */
			/* check for 0 integer no error */
			/* ---------------------------- */
			if (( local_error = workval1 ) == 0 )
				return( GOODRESULT );
#ifdef	ABAL64
		}
	}
#endif

	/* ------------------------------------------ */
	/* Leave all until Error trap or end of stack */
	/* ------------------------------------------ */
	if ( f_leave() != SOFTERROR )
		err_val = local_error;
#ifdef	ABAL64
	else	err_typ = VARB_INT16;
#endif

	/* --------------------- */
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
