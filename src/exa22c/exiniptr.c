/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXINIPTR.C				*/
/*		Version	:	1.4c / 2.1a				*/
/*		Date 	:	29/01/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXINIPTR_C
#define	_EXINIPTR_C

#ifdef	ABAL21


VOID	establish_pointer_variable( storage, memptr, ptrtype )
BPTR	storage;
BPTR	memptr;
EXAWORD	ptrtype;
{
	TcodePutPointer((storage), memptr );
	*storage = ptrtype;
	return;
}


/*	--------------------------------------------------------------  */
/*	P O I N T E R I N I T I A L I S A T I O N ( type, dptr, mptr )	*/
/*	--------------------------------------------------------------  */

BPTR	PointerInitialisation( type, dptr, mptr )
EXAWORD	type;
BPTR	dptr;
BPTR	mptr;
{
	/* Initialise memory if not a Member Redefinition */
	/* ---------------------------------------------- */
	if (!(type & ISMEMBER)) {
		mptr += Tcodeword((dptr));
		dptr += WORDSIZE;
		/* Do not re-initialise Pointer Arguments */
		/* -------------------------------------- */
		if (!( type & 8 ))
			establish_pointer_variable( mptr, (BPTR) 0, 0 );
		}

	/* Step over redefinition linkage identity */
	/* --------------------------------------- */
	else	dptr += (WORDSIZE * 2); 

	/* Step over possible length */
	/* ------------------------- */
	if (( type & VARB_ISOL ) > VARB_INT16)
		dptr += WORDSIZE;

	/* Step over possible first dimension */
	/* ---------------------------------- */
	if (  type & NDX1st ) 
		dptr += WORDSIZE;

	/* Step over possible second dimension */
	/* ----------------------------------- */
	if (  type & NDX2nd ) 
		dptr += WORDSIZE;

	return( dptr );
	
}

	/* ------------ */
#endif	/* ABAL21 	*/
	/* ------------ */
#endif	/* _EXINIPTR_C	*/
	/* ------------ */
