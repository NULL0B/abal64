/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AORECOV.C   				*/
/*		Version :	1.4a					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_RECOVERY_C
#define	_RECOVERY_C

#include "aomain.h"
#include "aorecov.h"

EXAWORD	branches[256];
EXAWORD	branche_index;

void	initialise_recovery()
{
	Salvage 	= (RECOVERY) 0;
	Storage 	= (RECOVERY) 0;
	branche_index	= 0;
	return;
}

void	terminate_recovery()
{
	RECOVERY	lptr;

	while ((lptr = Storage) != (RECOVERY) 0 ) {
		Storage = lptr->next;
		free( lptr );
		}
	return;
}

EXAWORD	push_branche_offset( si )
EXAWORD	si;
{
	if ( branche_index < 256 ) {
		branches[branche_index++] = si;
		return( VRAI );
		}
	else	return( FAUX );
}

EXAWORD	pop_branche_offset()
{
	if ( branche_index > 0 ) {
		branche_index--;
		return( branches[branche_index] );
		}
	return( MOINS_UN );

}

EXAWORD	allocate_for_recovery(sptr, si, sl)
BPTR	sptr;
EXAWORD	si;
EXAWORD	sl;
{
	RECOVERY	lptr;

	/* Check for Structure available on free list */
	/* ------------------------------------------ */
	if ((lptr = Storage) != (RECOVERY) 0)
		Storage = lptr->next;

	/* Attempt to Allocate new Recovery Structure */
	/* ------------------------------------------ */
	else if ((lptr = (RECOVERY) malloc( sizeof( struct recovery ) )) == (RECOVERY) 0)
		return( FAUX );

	/* Structure available for Recovery */
	/* -------------------------------- */
	lptr->offset = si;
	lptr->length = sl;

	/* Transfer Zone to be Saved */
	/* ------------------------- */
	memcpy((BPTR) lptr->buffer, (sptr + si), sl );

	/* Include in Salvage List */
	/* ----------------------- */
	lptr->next    = Salvage;
	Salvage       = lptr;

	/* Indicate Success */
	/* ---------------- */
	return( VRAI );

}

void	perform_recovery( sptr )
BPTR	sptr;
{
	RECOVERY	lptr;

	while ((lptr = Salvage) != (RECOVERY) 0) {

		/* Remove from SALVAGE and add to STORAGE */
		/* -------------------------------------- */
		Salvage 	= Salvage->next;
		lptr->next 	= Storage;
		Storage 	= lptr;

		/* Test for Recovery Required */
		/* -------------------------- */	
		if ( sptr != (BPTR) 0 ) {
			/* Restore original Tcode contents */
			/* ------------------------------- */
			memcpy((BPTR) (sptr + lptr->offset), (BPTR) lptr->buffer, lptr->length );
			restitution((sptr + lptr->offset));
			}
		}

	/* Reset Sub Branche offset index */
	/* ------------------------------ */
	branche_index	= 0;

	return;

}

#endif	/* _RECOVERY_C */
	/* ----------- */

