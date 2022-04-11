/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXGLFE.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 

EXAWORD	varbset1()
{
	EXAWORD	reg;

/*	Establish Table and Memory Base Pointer Values		*/
/*	----------------------------------------------		*/
	
	if (worktyp1 & ISLOCAL) { 
		workptr3 = (LocalDataTable + (worktyp1 & TOGLOBAL)); 
		workptr1  = LocalDataSegment; 
		}
	else 	{ 
		workptr3 = (GlobalDataTable + worktyp1);
		workptr1 = GlobalDataSegment; 
		}

/*	Collect Variable type code and select type		*/
/*	----------------------------------------------		*/

	worktyp1 = Tcodeword( workptr3 ); 
	workptr3 += WORDSIZE;
	reg      = workval1;

	/* Test for EXALONG pointer type variables */
	/* ------------------------------------ */
	if (worktyp1 & SPECIALE) {

#ifdef	ABAL21
		/* Test for DYNAMIC allocation variable */
		/* ------------------------------------ */
		if (worktyp1 & ISDYNAMIC) { 

			resolve_pointer_member( workptr3, workptr1, worktyp1 );


			}
		else
#endif

		/* Test for EXTENDED allocation variable */
		/* ------------------------------------- */
		if (worktyp1 & ISETENDU)  { /* Variable Etendu	  */
			if (readhuge(worktyp1,workptr3,1,workval1) == 0) { return(SOFTERROR); }
			return(GOODRESULT);
			}	
		/* Otherwise VIRTUAL (FILE) variable */
		/* --------------------------------- */
		else 	{	
			if ( extvarb(worktyp1,workptr3,1,workval1) == 0) { return(SOFTERROR); } 
			return(GOODRESULT);
			}
		}
	else 	{	
		/* Collect and Add short offset for this variable */
		/* ---------------------------------------------- */
		workptr1 += (Tcodeword( workptr3 )); workptr3 += WORDSIZE;
		}

/* 	Establish Variable Length Value 	*/
/* 	------------------------------- 	*/
	switch ( worktyp1 & VARB_ISOL ) {
		case VARB_FOUR	:
		case VARB_INT8  : worklen1 = 1; break;
		case VARB_INT16 : worklen1 = ABALWORDSIZE; break;
		case VARB_INT32 : worklen1 = (2*ABALWORDSIZE); break;
		case VARB_INT64 : worklen1 = (4*ABALWORDSIZE); break;
		default		: worklen1 = Tcodeword( workptr3); 
				  workptr3 += WORDSIZE;
		}

/* 	Establish Index Values (if any) 	*/
/* 	------------------------------- 	*/
	if (worktyp1 & NDX1st) { 
		IndexCheck( (ireg [workval1]) , workptr3 );
		workptr1 += ( worklen1 * ( ireg [workval1] - 1 ) );
		if (worktyp1 & NDX2nd) {
			IndexCheck( ( areg [workval1] ) , ( workptr3 + WORDSIZE ) );
			workptr1 += ( ((Tcodeword( workptr3)) * worklen1) * ( areg [workval1] - 1 ));
			}
		}
	worktyp1 &= VARB_ISOL;

/* 	Perform Optimisation operations (#,% => Values : N,$ => RegPtr) */
/* 	--------------------------------------------------------------- */
	switch ( worktyp1 ) {
		case VARB_FOUR  : 
		case VARB_INT8  : if ( ExFlgSgn != 0 )	{ workval1 = (EXAWORD) *((BPTR) workptr1); }
				  else 			{ workval1 = (BINAIRE) ReadSchar( workptr1 ); /* *((EXCPTR) workptr1); */ }
				  break;
		case VARB_INT16 : workval1 = balgetw(workptr1);
				  break;
		case VARB_INT32 : workval1 = balgetl(workptr1);
				  break;
		case VARB_INT64 : workval1 = balget64(workptr1);
				  break;
		default		: if ( workval1 > 0 ) { 
					preg [workval1] = workptr1; 
					lreg [workval1] = worklen1; 
					xreg [workval1] = (worktyp1 | PTRSTATUS); 
					}

		}
	ExFlgSgn = 0; 
	return(GOODRESULT);

}

EXAWORD	varbset2()
{
	EXAWORD	reg;

/*	Establish Table and Memory Base Pointer Values		*/
/*	----------------------------------------------		*/
	
	if (worktyp2 & ISLOCAL)
	{ 
		workptr3 = (LocalDataTable + (worktyp2 & TOGLOBAL)); 
		workptr2  = LocalDataSegment; 
	}
	else 
	{ 
		workptr3 = (GlobalDataTable + worktyp2);
		workptr2 = GlobalDataSegment; 
	}

/*	Collect Variable type code and select type		*/
/*	----------------------------------------------		*/

	worktyp2 = Tcodeword( workptr3 ); 
	workptr3 += WORDSIZE;
	reg      = workval2;

	/* Test for EXALONG pointer type variables */
	/* ------------------------------------ */
	if (worktyp2 & SPECIALE) {

#ifdef	ABAL21
		/* Test for DYNAMIC allocation variable */
		/* ------------------------------------ */
		if (worktyp2 & ISDYNAMIC) { 

			resolve_pointer_member( workptr3, workptr2, worktyp2 );


			}
		else
#endif

		/* Test for EXTENDED allocation variable */
		/* ------------------------------------- */
		if (worktyp2 & ISETENDU)  { /* Variable Etendu	  */
			if (readhuge(worktyp2,workptr3,2,workval2) == 0) { return(SOFTERROR); }
			return(GOODRESULT);
			}	
		/* Otherwise VIRTUAL (FILE) variable */
		/* --------------------------------- */
		else 	{	
			if ( extvarb(worktyp2,workptr3,2,workval2) == 0) { return(SOFTERROR); } 
			return(GOODRESULT);
			}
		}
	else 	{	
		/* Collect and Add short offset for this variable */
		/* ---------------------------------------------- */
		workptr2 += (Tcodeword( workptr3 )); workptr3 += WORDSIZE;
		}

/* Establish Variable Length Value */
/* ------------------------------- */
switch ( worktyp2 & VARB_ISOL ) {
	case VARB_FOUR  : 
	case VARB_INT8  : worklen2 = 1; break;
	case VARB_INT16 : worklen2 = ABALWORDSIZE; break;
	case VARB_INT32 : worklen2 = (2*ABALWORDSIZE); break;
	case VARB_INT64 : worklen2 = (4*ABALWORDSIZE); break;
	default		: worklen2 = Tcodeword( workptr3); 
			  workptr3 += WORDSIZE;
	}

/* Establish Index Values (if any) */
/* ------------------------------- */
if (worktyp2 & NDX1st) { 
	IndexCheck( (ireg [workval2]) , workptr3 );
	workptr2 += ( worklen2 * ( ireg [workval2] - 1 ) );
	if (worktyp2 & NDX2nd) {
		IndexCheck( (areg [workval2]) , ( workptr3 + WORDSIZE ) );
		workptr2 += ( ((Tcodeword( workptr3)) * worklen2) * ( areg [workval2] - 1 ));
		}
	}

worktyp2 &= VARB_ISOL;

/* Perform Optimisation operations (#,% => Values : N,$ => RegPtr) */
/* --------------------------------------------------------------- */
switch ( worktyp2 ) {
	case VARB_FOUR  :
	case VARB_INT8  : if ( ExFlgSgn != 0 )	{ workval2 = (EXAWORD) *((BPTR) workptr2); }
			  else 			{ workval2 = (BINAIRE) ReadSchar( workptr2 ); /* *((EXCPTR) workptr2); */ }
			  break;
	case VARB_INT16 : workval2 = balgetw(workptr2); break;
	case VARB_INT32 : workval2 = balgetl(workptr2); break;
	case VARB_INT64 : workval2 = balget64(workptr2); break;
	default		: if ( workval2 > 0 ) { 
				preg [workval2] = workptr2; 
				lreg [workval2] = worklen2; 
				xreg [workval2] = (worktyp2 | PTRSTATUS); 
				}

	}
ExFlgSgn = 0; return(GOODRESULT);
}

EXAWORD	varbsetw()
{
	EXAWORD	reg;

	if (worktyp1 & ISLOCAL) 
	{ 
		workptr3 = LocalDataTable + (worktyp1 & TOGLOBAL);
		workptr1 = LocalDataSegment;
	}
	else 
	{
		workptr3 = GlobalDataTable + worktyp1;
		workptr1 = GlobalDataSegment; 
	}

	worktyp1 = Tcodeword( workptr3); 
	workptr3 += WORDSIZE;
	reg      = workval1;

	/* Test for EXALONG pointer type variables */
	/* ------------------------------------ */
	if (worktyp1 & SPECIALE) {

#ifdef	ABAL21
		/* Test for DYNAMIC allocation variable */
		/* ------------------------------------ */
		if (worktyp1 & ISDYNAMIC) { 

			resolve_pointer_member( workptr3, workptr1, worktyp1 );


			}
		else
#endif

		/* Test for EXTENDED allocation variable */
		/* ------------------------------------- */
		if (worktyp1 & ISETENDU)  { /* Variable Etendu	  */
			if (readhuge(worktyp1,workptr3,0,workval1) == 0) 
				return(SOFTERROR);
			return(GOODRESULT);
			}	
		/* Otherwise VIRTUAL (FILE) variable */
		/* --------------------------------- */
		else 	{	
			extwrite |= 0x0080;
			if ( extvarb(worktyp1,workptr3,0,workval1) == 0) {
				extwrite &= 0x007F; 
				ExFlgSgn = 0;
				return(SOFTERROR);
				}
			extwrite &= 0x007F; 
			ExFlgSgn = 0;
			return(GOODRESULT);

			}
		}
	else 	{	
		/* Collect and Add short offset for this variable */
		/* ---------------------------------------------- */
		workptr1 += (Tcodeword( workptr3 )); workptr3 += WORDSIZE;
		}

switch ( worktyp1 & VARB_ISOL ) {
	case VARB_FOUR  :
	case VARB_INT8  : worklen1 = 1; break;
	case VARB_INT16 : worklen1 = ABALWORDSIZE; break;
	case VARB_INT32 : worklen1 = (2*ABALWORDSIZE); break;
	case VARB_INT64 : worklen1 = (4*ABALWORDSIZE); break;
	default		: worklen1 = Tcodeword( workptr3); 
			  workptr3 += WORDSIZE;
	}
if (worktyp1 & NDX1st) { 
	IndexCheck((ireg [workval1]),workptr3);
	workptr1 += ( worklen1 * ( ireg [workval1] - 1 ) );
	if (worktyp1 & NDX2nd) {
		IndexCheck((areg [workval1]),(workptr3 + WORDSIZE));
		workptr1 += ( ((Tcodeword( workptr3)) * worklen1) * ((areg [workval1])  - 1 ) );
		}
	}

worktyp1 &= VARB_ISOL;

switch (worktyp1) {
	case VARB_FOUR	:
	case VARB_INT8  :
		if (!workptr1) {
			err_val = 118;
			return SOFTERROR;
		}
		workval1 = (BINAIRE) ReadSchar( workptr1 );
		break;
	case VARB_INT16 :
		if (!workptr1) {
			err_val = 118;
			return SOFTERROR;
		}
		workval1 = balgetw(workptr1);
		break;
	case VARB_INT32 : 
		if (!workptr1) {
			err_val = 118;
			return SOFTERROR;
		}
		workval1 = balgetl(workptr1);
		break;
	case VARB_INT64 : 
		if (!workptr1) {
			err_val = 118;
			return SOFTERROR;
		}
		workval1 = balget64(workptr1);
		break;
	default		: if (workval1 > 0) {
				preg [workval1] = workptr1;
				lreg [workval1] = worklen1;
				xreg [workval1] = (worktyp1 | PTRSTATUS); 
				}
	}

ExFlgSgn = 0; return(GOODRESULT);
}
