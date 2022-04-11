EXAWORD	negwork(k,s)
EXAWORD	k,s;
{
	BPTR	sptr;

	/* Evaluate Arguament to be Negated */
	/* -------------------------------- */
	if ( argsetw( (5 - k) , s ) == SOFTERROR ) {
		return(SOFTERROR); 
		}
	/* Test for Strings and Eliminate With Error */
	/* ----------------------------------------- */
	if ( worktyp1 > 2 ) { 
		err_val = ABAL_STR4NUM; return(SOFTERROR); 
		}

	/* Watch out for Register Result required */
	/* -------------------------------------- */
	if ( k == 1 ) 	{ 
		sptr = workptr1; 
		if (argsetw(6,s) == SOFTERROR) { return(SOFTERROR); }
		memcpy(workptr1,sptr,worklen1);
		}

	/* Check for and Negate Bcd Variables */
	/* ---------------------------------- */
	if ( worktyp1 == 2 ) { 	

		/* Watchout for and UnDo Negative Fixed Bcd Variables */
		/* -------------------------------------------------- */
		if ((((EXAWORD) *workptr1) & 0x00F0) == 0x0040 ) { 
			negbcd(workptr1,worklen1); 
			}
		
		/* Watchout for and Ignore Zero Values */
		/* ----------------------------------- */
		sptr = Squeeze(workptr1,worklen1);
		if ((( *sptr & 0x000F ) == 0x000F )
		||  ((( *sptr & 0x000F ) == 0x000A) && ((*(sptr + 1) & 0x00F0) == 0x00F0))) {
 			return(1);
			}

		/* Perform Negation */
		/* ---------------- */
		k = (EXAWORD) *workptr1; 
		switch ( k & 0x00F0 ) {
			case 0x00C0	: k &= 0x000F; k |= 0x00B0; break;
			case 0x00B0	: k &= 0x000F; k |= 0x00C0; break;
			default		: err_val = ABAL_BCDFORM; k = 0; break;
			}
		if ( k != 0 ) { *workptr1 = (EXABYTE) k; k = 1; }
		return(k);
		}

	/* --------------------------------------- */
	/* Perform Integer Negation 8,16,32,64bits */
	/* --------------------------------------- */
	switch (( worktyp1 & VARB_ISOL )) {
		case	VARB_INT16	:	
			if ( k == 1 ) {
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
				}
			else	{ 
				balputw( -(workval1) ,workptr1 ); 
				}
			return(GOODRESULT); 
		case	VARB_FOUR	:
		case	VARB_INT8	:
			if ( k == 1 ) {
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
				}
			else	{ 
				*workptr1 = (EXABYTE) -(workval1);
				}
			return(1); 
		case	VARB_INT32	:	
			if ( k == 1 ) {
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
				}
			else	{ 
				balputl( -(workval1) ,workptr1 ); 
				}
			return(GOODRESULT); 
		case	VARB_INT64	:	
			if ( k == 1 ) {
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
				}
			else	{ 
				balput64( -(workval1) ,workptr1 ); 
				}
			return(GOODRESULT); 
		}
	err_val = 444;
	return( SOFTERROR );
}


