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

#ifdef	ABAL64
/*	---------------------------------------------------------	*/
/*	  e s t a b l i s h _ p o i n t e r _ r e f e r e n c e 	*/
/*	---------------------------------------------------------	*/
/*	when an ABAL64 EXA is running an ABAL32 or 16 program the	*/
/*	PROGRAM pointer size is only 5 bytes so here we store the	*/
/*	offset of the procedure linkage in the indirect program,	*/
/*	instead of the full pointer. 					*/
/*	This presumes the Procedure Pointer is in the same tcode	*/
/*	program unit since it is relative to the Tcode Context.		*/
/*	---------------------------------------------------------	*/
VOID	establish_pointer_reference( storage, memptr, ptrtype )
BPTR	storage;
EXAWORD	memptr;
EXAWORD	ptrtype;
{
	TcodePmot32((storage+1), memptr );
	*storage = (ptrtype | PROGRAM_OFFSET);
	return;
}
#endif

/*	---------------------------------------------------------	*/
/*	   e s t a b l i s h _ p o i n t e r _ v a r i a b l e		*/
/*	---------------------------------------------------------	*/
/*	store a complete ABALPTRSIZE pointer variable as value of	*/
/*	an ABAL PTR variable of NATURAL ABALPTRSIZE.			*/ 
/*	---------------------------------------------------------	*/
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

	/* ------------------------- */
	/* Remove String length */
	/* -------------------- */
	switch ( (type & VARB_ISOL) )
	{
	case	VARB_BCD	:
	case	VARB_STR	:
		dptr += WORDSIZE;
	}

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
