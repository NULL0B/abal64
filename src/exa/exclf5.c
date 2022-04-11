/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXCLF5.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 

#ifdef	ABAL21

#ifndef	_EXCLF5_C
#define	_EXCLF5_C

/*
 *	F _ C L F 5 
 *	-----------
 *	I% =	VALIDPTR ( <POINTER> )		code 0
 *	I% =    LOADGO(H%,C$)			code 3
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

EXAWORD	clf5_validptr()
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
			case VARB_FOUR	: 
			case VARB_INT8 : 
				*workptr1 = nature; break;
			case VARB_INT16 : 
				balputw( nature,workptr1); break;
			case VARB_INT32 : 
				balputl( nature,workptr1); break;
			case VARB_INT64 : 
				balput64( nature,workptr1); break;
			default: err_val = 20; return( SOFTERROR );
			}
		} 

	return(GOODRESULT);
}
	
EXAWORD	clf5_loadgo()
{
	EXAWORD	adesc;
	EXAWORD	xdesc;
	EXAWORD	result;
	EXAWORD	nature;
	BYTE	cr[2];

	/* collect arg descriptors */
	/* ----------------------- */
	if ((adesc = (EXAWORD) *(fdex++)) & 1)
		xdesc = (EXAWORD) *(fdex++);
	else	xdesc = 0;

	/* Evaluate desired result */
	/* ----------------------- */
	if ((adesc & 0x0060) == 0x0060)
		result = *(fdex++);
	else if ( argsetw(((adesc & 0x0060) >> 5),0) == SOFTERROR) 
			return(SOFTERROR);
	
	/* Collect file handle */
	/* ------------------- */
	if (argset(((adesc & 0x0006) >> 1),0,2) == SOFTERROR)
		return(SOFTERROR);
	else	{
		/* Check for integer assign handle */
		switch ( worktyp2 ) {
			case	VARB_FOUR	:
			case	VARB_INT8	:
			case	VARB_INT16	:
			case	VARB_INT32	:
			case	VARB_INT64	:
				break;
			default			:
				err_val = 115;
				return(SOFTERROR);
			}
		}

	/* Control file handle for Validity */
	/* -------------------------------- */
	if ( check_valid_assign_handle((lfh = (EXAWORD) workval2 )) == SOFTERROR )
		return( SOFTERROR );

	/* Store Assign Handle for Conf(27) */
	/* -------------------------------- */
	LastHandle = lfh;	

	/* Establish File control variables */
	/* -------------------------------- */
	if ((err_val = loadfich()) != 0)
		return( SOFTERROR );	

	/* check for and collect command line parameter */
	/* -------------------------------------------- */
	if ( adesc & 0x0001) {
		if (argset(((xdesc & 0x0060) >> 5),0,2) == SOFTERROR)
			return(SOFTERROR);
		else if ( worktyp2 != VARB_STR ) {
			err_val = 115;
			return(SOFTERROR);
			}
		}
	else	{
		worklen2=1;
		workptr2=cr;
		cr[0]=13; cr[1]=0;
		}

	/* perform the loadgo operation */
	/* ---------------------------- */
	worklen3=0;

	nature = standard_loadgo();

	/* Store to desired result type */
	/* ---------------------------- */
	if (( adesc & 0x0060) == 0x0060 ) { 
		freg [result] = (EXAWORD) nature;
		xreg [result] = 0;
		}
	else 	{
	 	switch ( worktyp1 ) {
			case VARB_FOUR	: 
			case VARB_INT8 : 
				*workptr1 = nature; break;
			case VARB_INT16 : 
				balputw( nature,workptr1); break;
			case VARB_INT32 : 
				balputl( nature,workptr1); break;
			case VARB_INT64 : 
				balput64( nature,workptr1); break;
			default: err_val = 20; return( SOFTERROR );
			}
		} 

	return(GOODRESULT);
}

EXAWORD	f_clf5( opcode )
EXAWORD	opcode;
{
	switch ( opcode ) {
		case	0	: return( clf5_validptr() );
		case	3	: return( clf5_loadgo()   );
		default		: err_val = 56; return( SOFTERROR );
		}
}


#endif	/* _EXCLF5_C */
	/* --------- */
#endif	/* ABAL21    */
	/* --------- */
