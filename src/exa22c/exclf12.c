/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCLF12.C 				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	17/02/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXCLF12_C
#define	_EXCLF12_C

/*
 *	Group C String functions
 *	------------------------
 *
 *	B = LEFT(A,X)	Left portion of A length X		Code 0
 *	WorkSet1 = Left( WorkSet2 , Workset3)
 *
 *	B = RIGHT(A,X)	Right portion of A length X		Code 1
 *	WorkSet1 = Right( WorkSet2 , Workset3)
 *
 *	B = SUBSTR(A,X,Y) Substring length Y indent X		Code 2
 *	WorkSet1 = Substr( WorkSet2 , TempSet , Workset3)
 *
 *	B = MOVE(A,X,Y)	Move memory from A[X] to B length Y	Code 3
 *	WorkSet1 = Move( WorkSet2 , TempSet , Workset3)
 *
 *	B = SWAP(A,X,Y) Swap memory zones A[X] & B Length Y	Code 4
 *	WorkSet1 = Swap( WorkSet2 , TempSet , Workset3)
 *
 *	B = PARSE(F,M) Extracts portion indicated by Mode	Code 5
 *	From the Filename F and places result in B
 *
 *	Errors :	
 *
 *	For Functions 0 -> 4 
 *	
 *		If WorkSet3 < Zero : Error NEGARG(113)
 *
 *	For Function 5
 *
 *		Possible Error DIEZTMP(114) if insuficient workspace
 *
 */

BPTR	create_tempzone_copy( xptr, xlen )
BPTR	xptr;
EXAWORD	xlen;
{
	BPTR	lptr;

	StackCheck( xlen );
	lptr = (TcodeByteStack + worktop);
	worktop += (xlen+1);
	memcpy( lptr, xptr, xlen );
	*(lptr + xlen) = 0;
	return( lptr );
}

EXAWORD f_clfc(x)
EXAWORD	x;			/* CLF subfunction code */
{
	EXAWORD	desc,descx;	/* Arguament Descriptor */
	EXABYTE	c;		/* Tempory Byte storage	*/
	EXAWORD	reg1;		/* Destination Register	*/
	BINAIRE	Indent;		/* TempSet Length Value	*/
	EXAWORD	Longeur;	/* Length Controle	*/
	BPTR	memorptr;
	BPTR	resulptr;
	EXAWORD	memorlen;


/* Collect Arguament descriptor Octets (MAX 4 , MIN 3 ) */
/* ---------------------------------------------------- */
desc = (EXAWORD) *(fdex++); descx = (EXAWORD) *(fdex++);

/* If Destination is Not a Register Establish Result Workset1 */
/* ---------------------------------------------------------- */
if ((desc & 0x0060) != 0x0060) { 
	if (argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) 
		return(SOFTERROR);
	}
/* Else collect register ID */
/* ------------------------ */
else	reg1 = (EXAWORD) *(fdex++);

/* Establish Source Workset2 */
/* ------------------------- */
if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR)
	return(SOFTERROR);

/* Establish Character variable Type Convert flag */
/* ---------------------------------------------- */
if (( descx & 0x0010 ) != 0 ) 
	/* MOVE SWAP SUBSTR (signed CHAR please) */
	ExFlgSgn = 0;
else	/* LEFT RIGHT (unsigned CHAR please) */ 
	ExFlgSgn = 1;

/* Collect 3rd Arguament (Length LEFT & RIGHT else Indent SUBSTR MOVE SWAP) */
/* ------------------------------------------------------------------------ */
if (argset(((descx & 0x0060) >> 5),0,3) == SOFTERROR) 	{ 
	ExFlgSgn = 0;
	return(SOFTERROR); 
	}

ExFlgSgn = 0;

/* LEFT / RIGHT BAL COMPATIBILLITY */
/* ------------------------------- */
if (( x < 2 ) && ( workval3 == 0 ) && (CompatibleBal))
	workval3 = 256;

/* Duplicate to Create TempSet */
/* --------------------------- */
Indent = workval3;

/* Collect 4th Arg for SUBSTR , MOVE and SWAP WorkSet3 */
/* --------------------------------------------------- */
if (( descx & 0x0010 ) != 0 ) { 
	ExFlgSgn = 1; /* Unsigned Characters */
	if (argset(((descx & 0x0006) >> 1),0,3) == SOFTERROR) { 
		ExFlgSgn = 0;
		return(SOFTERROR); 
		}
	ExFlgSgn = 0;
 	}	


/* Establish Destination for Register Results */
/* ------------------------------------------ */
if ( (desc & 0x0060 ) == 0x0060) {
	worktyp1 = 3; 
	if ( x != 5 )
		worklen1 = (EXAWORD) workval3;
	else	worklen1 = 256;

	if (argsetw(6,reg1) == SOFTERROR) 
		return(SOFTERROR);
	}

memorlen = 0;

/* Perform Destination and Source Type checking for SUBSTR LEFT and RIGHT */
/* ---------------------------------------------------------------------- */
if (x < 3) { /* If not MOVE fonction */
	if ((worktyp1 != 3) || (worktyp2 != 3)) 
		return(SOFTERROR);
	if ( workptr1 == workptr2 ) {
		memorptr = workptr1; memorlen = worklen1;
		StackCheck( memorlen );
		resulptr = (TcodeByteStack + worktop);
		worktop += worklen1;
		workptr1 = resulptr;
		}
	}

#ifdef	ABAL14
	/* Check for Function PARSE */
	/* ------------------------ */
	if ( x == 5 ) {
		if ((workptr2 = (BPTR) create_tempzone_copy( workptr2,(worklen2 = lenuse(workptr2, worklen2 )))) == (BPTR) 0)
			return(SOFTERROR);
		if ((x = fn_parser(workptr2,(BPTR) askbuf, workval3 )) != 0) {
			if ( x > worklen1 )
				x = worklen1;
			memcpy( workptr1, (BPTR) askbuf, x );
			worklen1 -= x;
			} 
		if ( worklen1 > 0 )
			memset( (workptr1+x), ' ', worklen1 );
		return(1);
		}
	
#endif

#ifndef INTELASM2

/* Perform Requested Function */
/* -------------------------- */
switch ( x ) 	{
		/* RIGHT */
		/* ----- */
		case	1 :	workptr2 += worklen2;	/* Calc Str End	*/
				workptr2 -= workval3;	/* Calc Start	*/
		/* LEFT  */
		/* ----  */
		case	0 :	if ( workval3 == 0) 
					workval3 = 256;
				break;

		/* SUBSTR */
		/* ------ */
		case	2 : 	Indent--;		/* Ajust towards 0  */
				workptr2+= Indent;	/* Add in increment */
				if (workval3 == 0) 
					workval3 = worklen1;
				break;

		/* MOVE and SWAP */
		/* ------------- */
		case 	3 :
		case	4 : Indent--;			/* Adjust towards 0 */
			    workptr2 +=Indent;		/* Add in increment */
			    worklen1 = workval3;	/* Establish lenres */
			    break;

		default   : unknown_tcode_error;
		}

Longeur = workval3;

/* Perform Memory transfer */
/* ----------------------- */
if ( x != 4 ) { 
	/* Not SWAP function */
	/* ----------------- */
	while (( worklen1 > 0 ) && ( Longeur > 0)) {
		*(workptr1++) = *(workptr2++);
		worklen1--; Longeur--;
		}
	}
else	{ 	/* SWAP function */
		/* ------------- */
	while (( worklen1 > 0 ) && ( Longeur > 0)) {
		c = *((BPTR) workptr2);
		*(workptr2++) = *(workptr1);
		*((BPTR) workptr1++) = c;
		worklen1--; Longeur--;
		}
	}

/*	Space Fill to End of String 	*/
/*	---------------------------	*/
while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--; }

#else

	workval1 = Indent;
	switch ( x ) {
		case 0 :	(VOID) clf_left();	break;
		case 1 :	(VOID) clf_right();	break;
		case 2 :	(VOID) clf_substr();	break;
		case 3 :	(VOID) clf_move();	break;
		case 4 :	(VOID) clf_swap();	break;

		default: 	unknown_tcode_error;

		}
#endif
/*	Check for Result Recopie Required	*/
/*	---------------------------------	*/
if ( memorlen > 0 )
	(VOID) memcpy(memorptr,resulptr,memorlen); 

return(1);

}
#endif	/* _EXCLF12_C */
	/* ---------- */
