/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCLF12.C 				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	21/03/1997				*/
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
 *	B = ABALANFC(F,M) Converts the prologue mnemonic filename	Code 6 ( Abal 3 )
 *	to the host system format using external environment variables.
 *
 *	T = TOKENISE(S,I,P) Cuts a token from S returning it 	Code 7
 *	in T 
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
	EXABYTE	c;			/* Tempory Byte storage	*/
	EXAWORD	reg1;		/* Destination Register	*/
	BINAIRE	Indent;		/* TempSet Length Value	*/
	EXAWORD	Longeur;	/* Length Controle	*/
	BPTR	memorptr;
	BPTR	resulptr;
	EXAWORD	memorlen;
	EXAWORD	i;
	EXAWORD	j;
	EXAWORD	k;

	/* Collect Arguament descriptor Octets (MAX 4 , MIN 3 ) */
	/* ---------------------------------------------------- */
	desc = (EXAWORD) *(fdex++); descx = (EXAWORD) *(fdex++);

	/* If Destination is Not a Register Establish Result Workset1 */
	/* ---------------------------------------------------------- */
	if ((desc & 0x0060) != 0x0060)
	{ 
		if (argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) 
			return(SOFTERROR);
	}
	/* Else collect register ID */
	/* ------------------------ */
	else
		reg1 = (EXAWORD) *(fdex++);

	/* Establish Source Workset2 */
	/* ------------------------- */
	if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR)
		return(SOFTERROR);

	/* Establish Character variable Type Convert flag */
	/* ---------------------------------------------- */
	if (( descx & 0x0010 ) != 0 ) 
		/* MOVE SWAP SUBSTR TOKENISE (signed please) */
		ExFlgSgn = 0;
	else
		/* LEFT RIGHT (unsigned please) */ 
		ExFlgSgn = 1;

	/* Collect 2nd Arguament (Length for LEFT RIGHT, Indent for MOVE SWAP SUBSTR TOKENISE) in Workset3 */
	/* ---------------------------------------------------------------------------------- */
	if (argset(((descx & 0x0060) >> 5),0,3) == SOFTERROR)
	{ 
		ExFlgSgn = 0;
		return(SOFTERROR); 
	}

	ExFlgSgn = 0;

	/* LEFT / RIGHT BAL COMPATIBILITY */
	/* ------------------------------ */
	if (( x < 2 ) && ( workval3 == 0 ) && (CompatibleBal))
		workval3 = 256;

	/* #BG 18/06/20 TOKENISE 2 parameters compatibility
		Normalement TOKENISE a 3 parametres (var1, offset, var2) mais la doc indiquait 2 !
		Si TOKENISE est utilsee sans le parametre d'offset, alors on le fixe a 0 car workval3 n'est pas initialise ds ce cas
	*/
	if ( (x == 7) && !(descx & 0x0010) )
		workval3 = 0;

	/* Duplicate to Create TempSet */
	/* --------------------------- */
	Indent = workval3;

	/* Collect 4th Arguament for SUBSTR MOVE SWAP TOKENISE in WorkSet3 */
	/* --------------------------------------------------------------- */
	if (( descx & 0x0010 ) != 0 )
	{ 
		ExFlgSgn = 1; /* Unsigned Characters */
		if (argset(((descx & 0x0006) >> 1),0,3) == SOFTERROR)
		{ 
			ExFlgSgn = 0;
			return(SOFTERROR);
		}
		ExFlgSgn = 0;
 	}	

	/* Establish Destination for Register Results */
	/* ------------------------------------------ */
	if ( (desc & 0x0060 ) == 0x0060)
	{
		worktyp1 = 3; 
		if (( x != 5 ) 
		&&  ( x != 7 ) 
		&&  ( x != 6 ))
			worklen1 = (EXAWORD) workval3;
		else
			worklen1 = 256;

		if (argsetw(6,reg1) == SOFTERROR) 
			return(SOFTERROR);
	}

	memorlen = 0;

	/* Perform Destination and Source Type checking for SUBSTR LEFT and RIGHT */
	/* ---------------------------------------------------------------------- */
	if (x < 3)
	{
		/* If not MOVE fonction */
		if ((worktyp1 != 3) || (worktyp2 != 3)) 
			return(SOFTERROR);

		if ( workptr1 == workptr2 )
		{
			memorptr = workptr1; memorlen = worklen1;
			StackCheck( memorlen );
			resulptr = (TcodeByteStack + worktop);
			worktop += worklen1;
			workptr1 = resulptr;
		}
	}

	/* Check for Function PARSE */
	/* ------------------------ */
	if ( x == 5 )
	{
		if ((workptr2 = (BPTR) create_tempzone_copy( workptr2,(worklen2 = lenuse(workptr2, worklen2 )))) == (BPTR) 0)
			return(SOFTERROR);

		if ((x = fn_parser(workptr2,(BPTR) askbuf, workval3 )) != 0)
		{
			if ( x > worklen1 )
				x = worklen1;
			memcpy( workptr1, (BPTR) askbuf, x );
			worklen1 -= x;
		}

		if ( worklen1 > 0 )
			memset( (workptr1+x), ' ', worklen1 );
		return(1);
	}

	/* Check for Function ABALANFC */
	/* --------------------------- */
	else if ( x == 6)
	{
		if ( convert_mnemonics(2,workval3) == SOFTERROR )
			return( SOFTERROR );
		else
		{
			if ( worklen2 > worklen1 )
				worklen2 = worklen1;
			memcpy( workptr1, (BPTR) workptr2, worklen2);
			worklen1 -= worklen2;
		}

		if ( worklen1 > 0 )
			memset( (workptr1+worklen2), ' ', worklen1 );
		return(1);
	}
#ifdef	ABALV33
	/* -------------------------------- */
	/* Function T$ = TOKENISE(S$,I%,C$) */
	/* -------------------------------- */
	else if ( x == 7 )
	{
		/* --------------------------- */
		/* reset the result zone first */
		/* --------------------------- */
		memset( workptr1,' ', worklen1 );

		/* -------------------------------------- */
		/* adjust the start position towards zero */
		/* -------------------------------------- */
		if ( Indent )Indent--;

		/* -------------------------------------- */
		/*  scan forward from position to E.O.S	  */
		/* -------------------------------------- */
		for ( k=0, i=Indent; i < worklen2; i++ )
		{
			c = *(workptr2+i);

			/* ------------------------------ */
			/* test for punctuation character */
			/* ------------------------------ */
			for ( j=0; j < worklen3; j++ )
			{
				if ( c == *(workptr3 + j) )
					break;
			}

			if ( j < worklen3 )
			{
				k++;
				break;
			}
			else
			{
				*(workptr1+k) = c;
				k++;
				if ( k >= worklen1 )
					break;
			}
		}

		/* Fait pointer workptr2 sur le 2eme token pour l'appel suivant */
		for ( j=Indent; j < worklen2; j++ )
		{
			if ((j + k) >= worklen2) 
				*(workptr2+j) = ' ';
			else
				*(workptr2+j) = *(workptr2+j+k);
		}
		return( GOODRESULT );
	}	
#endif

#ifndef INTELASM2

	/* Perform Requested Function */
	/* -------------------------- */
	switch ( x ) 	
	{
	case	1 :	
		/* RIGHT */
		/* ----- */
		workptr2 += worklen2;	/* Calc Str End	*/
		workptr2 -= workval3;	/* Calc Start	*/

	case	0 :	
		/* LEFT  */
		/* ----  */
		if ( workval3 == 0) 
			workval3 = 256;
		break;


	case	2 :
		/* SUBSTR */
		/* ------ */
	 	Indent--;		/* Ajust towards 0  */
		workptr2+= Indent;	/* Add in increment */
		if (workval3 == 0) 
				workval3 = worklen1;
			break;

	case 	3 :
	case	4 : 
		/* MOVE and SWAP */
		/* ------------- */
		Indent--;			/* Adjust towards 0 */
		workptr2 +=Indent;		/* Add in increment */
		worklen1 = workval3;	/* Establish lenres */
		break;

	default   : 
		unknown_tcode_error;
	}

	Longeur = workval3;

	/* Perform Memory transfer */
	/* ----------------------- */
	if ( x != 4 ) 
	{ 
		/* Not SWAP function */
		/* ----------------- */
		while (( worklen1 > 0 ) && ( Longeur > 0)) 
		{
			*(workptr1++) = *(workptr2++);
			worklen1--; Longeur--;
		}
	}
	else
	{ 	
		/* SWAP function */
		/* ------------- */
		while (( worklen1 > 0 ) && ( Longeur > 0)) 
		{
			c = *((BPTR) workptr2);
			*(workptr2++) = *(workptr1);
			*((BPTR) workptr1++) = c;
			worklen1--; Longeur--;
		}
	}

	/*	Space Fill to End of String 	*/
	while ( worklen1 > 0 )
	{
		*(workptr1++) = IO_ESP;
		worklen1--;
	}

#else

	workval1 = Indent;
	switch ( x )
	{
	case 0 : (VOID) clf_left();		break;
	case 1 : (VOID) clf_right();	break;
	case 2 : (VOID) clf_substr();	break;
	case 3 : (VOID) clf_move();		break;
	case 4 : (VOID) clf_swap();		break;
	default: unknown_tcode_error;
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
