#ifdef	ABAL21

#ifndef	_EXCLF5_C
#define	_EXCLF5_C

/*
 *	F _ C L F 5 
 *	-----------
 *	I% =	VALIDPTR ( <POINTER> )		code 0
 *
 */

EXAWORD	get_abal_pointer_type( tptr )
BPTR	tptr;
{
	EXAWORD	nature=0;
	if ( tptr != (BPTR) 0 ) {
		switch (((nature = *tptr) & 0x00FF)) {
			case REFERENCED_POINTER	:
			case ALLOCATED_POINTER	: 
			case CONSTANT_POINTER	: 
			case PROCEDURE_POINTER	: 
			case SEGMENT_POINTER	: 
			case USER_POINTER	: 
			case PROGRAM_POINTER	: break;
			default			: nature = 0;
			}
		}
	return( nature );
}

EXAWORD	f_clf5( opcode )
EXAWORD	opcode;
{
	EXAWORD	adesc;
	EXAWORD	target;
	BPTR	tdesc;		/* Descriptor Pointer		*/
	BPTR	tptr;		/* Memory Storage Pointer	*/
	BPTR	resolve_member(EXAWORD);
	EXAWORD	result;
	EXAWORD	nature;

	/* Ensure test argument is a variable or a register */
	/* ------------------------------------------------ */
	switch (((adesc = (EXAWORD) *(fdex++)) & 0x0017)) {
		case 0x0014	: /* Variable */
		case 0x0016	: /* Register */
			break;	
		default		:
			err_val = 115;
			return( SOFTERROR );
		}

	/* Evaluate desired result */
	/* ----------------------- */
	if ((adesc & 0x0060) == 0x0060)
		result = *(fdex++);
	else if ( argsetw(((adesc & 0x0060) >> 5),0) == SOFTERROR) 
			return(SOFTERROR);
	
	if (( adesc & 0x0006) == 0x0006) {
		if ( argset(4,*(fdex++),2) == SOFTERROR )
			return( SOFTERROR );
		tptr = workptr2;
		}
	else	{
		/* Collect Target Variable Identifier */
		/* ---------------------------------- */
		target = Tcodeword( (fdex) ); fdex += WORDSIZE;

		/* ----------------------------------------- */
		/* Establish storage adresse of this pointer */
		/* ----------------------------------------- */
		/* Resolve and Check Target */
		/* ------------------------ */
		if ( target & ISLOCAL ) {
			tdesc = (LocalDataTable + (target & TOGLOBAL));
			tptr  = LocalDataSegment;
			}
		else	{
			tdesc = (GlobalDataTable + target);
			tptr  = GlobalDataSegment;
			}

		if (!((target = (Tcodeword((tdesc)))) & ISDYNAMIC)) {
			if ((target & VARB_ISOL) != VARB_STR) {
				err_val = 118;
				return( SOFTERROR );
				}
			else 	{
				fdex -= WORDSIZE;
				if ( argset(2,0,2) == SOFTERROR )
					return( SOFTERROR );
				tptr = workptr2;
				}
			}
		else	{
			tdesc += WORDSIZE;

			/* Allow evaluation of Redefinition pointers */
			/* ----------------------------------------- */
			if ( target & ISMEMBER ) {

				/* Ensure this is a pointer type */
				/* ----------------------------- */
				if (!(target  & ISPOINTER)) {
					if ((target & VARB_ISOL) != VARB_STR) {
						err_val = 118;
						return( SOFTERROR );
						}
					else 	{
						fdex -= WORDSIZE;
						if ( argset(2,0,2) == SOFTERROR )
							return( SOFTERROR );
						tptr = workptr2;
						}
					}
				else	{
	
					/* Resolve the area pointed to by member indirection */
					/* ------------------------------------------------- */
					if (( tptr = resolve_member((Tcodeword((tdesc))))) == (BPTR) 0) {
						err_val = 118;
						return( SOFTERROR );
						}

					/* Step over Member Variable Identifier */
					/* ------------------------------------ */
					tdesc += WORDSIZE;
	
					/* Evaluate Storage Adresse of this pointer */
					/* ---------------------------------------- */
					tptr += Tcodeword((tdesc)); tdesc += WORDSIZE;

					}
				}
			else	{
				/* Evaluate Storage Adresse of this pointer */
				/* ---------------------------------------- */
				tptr += Tcodeword((tdesc)); tdesc += WORDSIZE;
				}
			}
		}

	nature = get_abal_pointer_type( tptr );


	/* Store to desired result type */
	/* ---------------------------- */
	if (( adesc & 0x0060) == 0x0060 ) { 
		freg [result] = (EXAWORD) nature;
		xreg [result] = 0;
		}
	else 	{
	 	switch ( worktyp1 ) {
			case 0 : *workptr1 = nature; break;
			case 1 : balputw( nature,workptr1); break;
			default: err_val = 20; return( SOFTERROR );
			}
		} 

	return(GOODRESULT);
}
	

#endif	/* _EXCLF5_C */
	/* --------- */
#endif	/* ABAL21    */
	/* --------- */
