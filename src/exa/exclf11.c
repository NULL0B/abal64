/*
 *	Functions which return integer results :
 *	----------------------------------------
 *
 *	0) -	I% = HASH ( S$, L% ) Check Sum XOR of bytes in string.
 *	1) -	I% = DEC    ( S$,L% )	 Conversion string hexa => Integer
 *	2) -	I% = LEN ( Arguament )	 Returns the real length of ARG
 *	3) -	I% = LEN$( Arguament )	 Returns the length in use of ARG
 *	4) -	I% = SIGN ( Bcd )	 Returns the sign of an integer
 *	5) -	I% = INDEX(String,C)	 Finds position of 'c' in string
 *	6) -	I% = INSTR(String,string,deb) Test for string in String
 *	7) -	I% = VARPTR(Arguament)	 Returns offset from base of ARG
 *	8) -    I% = FMINT( Bcd )	 Returns number of Real Digits
 *	9) -	I% = FMFP ( Bcd )	 Returns number of fractional digits
 *	10)-    I% = POWER( Bcd )	 Returns Decimal Power Factor for StdFm
 *	11)-    I% = CHECKFMT( V, F$ )	 Check Variable against format
 *	12)-	I% = WEEKDAY(D,M,Y)	 Returns the Week Day Numbered 1 to 7
 *	13)-	I% = RUNTIME(String)	 Returns the DLL Number of the DLL NAME
 *	14)-	I% = WILDCOMP(String,String) Performs the standard wild compare
 *	15)-    I% = CHDIR(String)	Changes directory (at *!$?ing last)
 */

EXAWORD	f_clfb(x)
EXAWORD x;
{
EXAWORD i;
EXAWORD	desc,reg,descx,regx,work,tlen;
EXAWORD	ix,xl,yl,xx;
BPTR	tptr;
	
if ((desc = (EXAWORD) *(fdex++)) & 1)
	descx = (EXAWORD) *(fdex++);

if (( desc & 0x0060) != 0x0060 ) 
{
	reg = 0; 
	if ( argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) 
		return(SOFTERROR);
}
else 	
{
	reg = (EXAWORD) *(fdex++);
	if ( WORDSIZE > 4 )
		worktyp1 = VARB_INT64;
	else if ( WORDSIZE > 2 )
		worktyp1 = VARB_INT32;
	else	worktyp1 = VARB_INT16;
}

if ( x == 7 ) 
	work = exvarptr((desc & 0x0006) >> 1);
else	{
	if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
		return(SOFTERROR);
	if ( ( desc & 1) 
	&&   ( argset(((descx & 0x0060) >> 5),0,3) == SOFTERROR ) )
		return(SOFTERROR);
	}
	
switch ( x ) {
	case 0 : /* 	arg1 = CHECKSUM( S$, L% )	*/
		 /*	-------------------------	*/
		 x = 0;
		 while (worklen2 > 0) { 
			x += (EXAWORD) *(workptr2++); 
			worklen2--; 
			}
		x %= workval3;
		break;

	case 1 : /*	arg1 = DEC ( arg2 , arg3 )	*/
		 /* ----------------------------------- */
		if ( workval3 == 0 ) 
		{
		 
			err_val = ABAL_STR4NUM; 
			return(SOFTERROR); 
		}
		if ( workval3 <  0 ) 
		{
		 
			err_val = ABAL_NUM2BIG; 
			return(SOFTERROR); 
		}
		switch ( worktyp1 & VARB_ISOL ) 
		{
			case	VARB_INT8	:
				if ( workval3 <= 2 )
					break;
				else	 
				{
					err_val = ABAL_NUM2BIG; 
					return(SOFTERROR); 
				}

			case	VARB_INT16	:
				if ( workval3 <= 4 )
					break;
				else	 
				{
					err_val = ABAL_NUM2BIG; 
					return(SOFTERROR); 
				}

			case	VARB_INT32	:
				if ( workval3 <= 8 )
					break;
				else	 
				{
					err_val = ABAL_NUM2BIG; 
					return(SOFTERROR); 
				}
			case	VARB_INT64	:
				if ( workval3 <= 16 )
					break;
				else	 
				{
					err_val = ABAL_NUM2BIG; 
					return(SOFTERROR); 
				}
			default			:
				err_val = ABAL_NUM2BIG; 
				return(SOFTERROR); 

		}

		/* Ensure all characters to be converted are legal */
		/* ----------------------------------------------- */
		for ( xx = 0; xx < workval3; xx++ ) 
		{

			x = toupper( (*(workptr2+xx)) );
			if ((( x >= 'A' ) && ( x <= 'F' )) || ((x >= '0') && ( x <= '9')))
				continue;

			err_val = ABAL_STR4NUM; 
			return(SOFTERROR);
		}

		/* Perform Conversion From HEXA to Decimal */
		/* --------------------------------------- */
		x = hextoi(workptr2,(EXAWORD) workval3); 
		break;

	case 2 : /*	arg1 = LEN ( arg2 )		*/
		 /*	-------------------		*/
		 x = worklen2;break;

	case 3 : /*	arg1 = LEN$( arg2 )		*/
		 /* 	-------------------		*/

		 x = lenuse(workptr2,worklen2); break;

	case 4 : /*	arg1 = SGN( arg2 )		*/
		 /* ----------------------------------- */
		if ( worktyp2 == VARB_STR ) {
			err_val = ABAL_BCDFORM; 
			return(SOFTERROR);
			}
		else if ( worktyp2 != VARB_BCD ) 
		{
			x = 0;
			if ( workval2 > 0 )
				x++;
			else if( workval2 < 0 )
				x--;
		}
		else	
		{
			switch( (EXAWORD) *workptr2 & 0x00F0 ) 
			{
			case 0x00B0 :
				 if ( bcdeval(workptr2,worklen2) != 0 ) 
					x = MOINS_UN;
				 else	x = 0;
				 break;
			case 0x0040 : x = MOINS_UN; break; 
			case 0x00C0 :
				 if ( bcdeval(workptr2,worklen2) != 0 ) 
					x = 1;
				 else	x = 0;
				 break;	
			default	    : err_val = ABAL_BCDFORM; 
				      return(SOFTERROR);
			}
		}
		break;

	case 5 :
		/*	arg1 = INDEX( arg2 , arg3 )	*/
		/*	---------------------------	*/
		x = 0; regx = 1;
		if ( (worklen3 = lenuse(workptr3,worklen3)) == 0 )
			worklen3 = 1; 

		while ( worklen2 > 0 ) 
		{
			/* Check for First EXABYTE match */
			/* -------------------------- */
			if ( *workptr2 == *workptr3 ) 
			{
				if ( worklen3 <= 1 ) { x = regx; break; }
				ix = 1; xl = (worklen2 - 1); yl = worklen3 - 1;

				/* Compare the Two Strings */
				/* ----------------------- */
				while (( xl > 0 ) && ( yl > 0 )) 
				{
					if ( *(workptr2 + ix) != *(workptr3 + ix) )
						break;

					ix++; xl--; yl--;
				}
				/* If End of Test String Reached */
				/* ----------------------------- */
				if ( yl == 0 ) { x = regx; break; }
			}
			/* Advance pointers and decrement Counters */
			/* --------------------------------------- */
			worklen2--; regx++; workptr2++;
		}
		break;

	case 6 : /*	arg1 = INSTR( arg2 ,arg3 ,arg4 )	*/
		 /*	-------------------------------- 	*/
		 tptr = workptr3; 
		 if ((tlen = lenuse(workptr3,worklen3)) == 0)
		 	tlen = 1; 
		 if ( argset(((descx & 0x0006) >> 1),0,3) == SOFTERROR)
			return(SOFTERROR); 
		 x = 0;
		 if ((workval3 > 0 ) && ( workval3 <= worklen2)) {
			 x = 1;
			 if (workval3 <= 0) 
				workval3 = 1; 
			 workptr2 += (workval3 - 1); 
			 worklen2 -= (workval3 - 1);
			 while (( worklen2 > 0 ) && ( tlen > 0 )) {
				if ( *(workptr2++) != *(tptr++) ) { 
					x = 0; 
					break; 
					}
				worklen2--; tlen--; 
				}
			if (( x == 1 ) && ( tlen != 0 )) 
				x = 0; 
			}
		break;

	case 7 : /*	arg1 = VARPTR( Arg2 )			*/
		 /*	---------------------			*/
		if (( work == MOINS_UN) && ( err_val != 0 )) 
			return(SOFTERROR);
		else	x = work; 	
		break;	

	case 8 : /* 	arg1 = FMINT( Arg2 )			*/
		 /* ------------------------------------------- */
		x = ((bcdeval(workptr2,worklen2) & 0xFF00) >> 8); 
		break;

	case 9 : /* 	arg1 = FMFP( Arg2 )			*/
		 /* ------------------------------------------- */
		x = (bcdeval(workptr2,worklen2) & 0x00FF); 
		break;

	case 10: /*     arg1 = POWER( Arg2 )  (Resets ERR_VAL)	*/
		 /* ------------------------------------------- */
		x = bcdpower(workptr2,worklen2);
		if ( err_val != 0 ) 
			return(SOFTERROR);
		break;

	case 11: /* 	result = CHECKFMT( V , F$ )			*/
		 /* -------------------------------------------- */	
		x = sf_check_format();
		if ( err_val != 0 ) 
			return(SOFTERROR);
		break;

	case 13 : /* 	I% = RUNTIME( String )     			*/
		 /* -------------------------------------------- */	
		x = get_dll_number( workptr2, worklen2 );
		if ( err_val != 0 ) 
			return(SOFTERROR);
		break;

	case 14 :
		for (i=0; i< worklen2; i++ ) {
 			if ( *(workptr2+i) == ' ' )
				break;
			else	*(TcodeByteStack+worktop+i) = *(workptr2+i);
			}
		*(TcodeByteStack+worktop+i)=0; i++;
		worklen2 = i;
		for (i=0; i< worklen3; i++ ) {
 			if ( *(workptr3+i) == ' ' )
				break;
			else	*(TcodeByteStack+worktop+i+worklen2) = *(workptr3+i);
			}
		*(TcodeByteStack+worktop+i+worklen2)=0; i++;
		worklen3 = i;
		x = wildcomp((TcodeByteStack+worktop),(TcodeByteStack+worktop+worklen2));
		break;

	case 12 : /* result = WEEKDAY( D, M, Y ) */
		  /* --------------------------- */
	
		/* Ensure Day parameter is an Integer */
		/* ---------------------------------- */
		if ( worktyp2 == VARB_BCD )
			workval2 = bcdtoi(workptr2,worklen2);
		else if ( worktyp2 == VARB_STR )
			workval2 = exatoi(workptr2,worklen2);
		

		/* Ensure Month parameter is an Integer */
		/* ------------------------------------ */
		if ( worktyp3 == VARB_BCD )
			workval3 = bcdtoi(workptr3,worklen3);
		else if ( worktyp3 == VARB_STR )
			workval3 = exatoi(workptr3,worklen3);
		
		xx = workval3;


		/* Collect Year parameter */
		/* ---------------------- */
		if ( argset(((descx & 0x0006) >> 1),0,3) == SOFTERROR ) 
			return(SOFTERROR);
		/* Ensure Year parameter is an Integer */
		/* ---------------------------------- */
		else if ( worktyp3 == VARB_BCD )
			workval3 = bcdtoi(workptr3,worklen3);
		else if ( worktyp3 == VARB_STR )
			workval3 = exatoi(workptr3,worklen3);
		
		x = datedays(workval2,xx,workval3);

		break;

	case 15 :
		for (i=0; i< worklen2; i++ ) {
 			if ( *(workptr2+i) == ' ' )
				break;
			else	*(TcodeByteStack+worktop+i) = *(workptr2+i);
			}
		*(TcodeByteStack+worktop+i)=0; i++;
		if ((x = chdir(TcodeByteStack+worktop)) != 0) {
			traitfilerror(MOINS_UN,errno);
			x = errno;
			}
		break;

	default : unknown_tcode_error;

	}

/* Save Result to Register or Variable */
/* ----------------------------------- */
isave(reg,x);
return(GOODRESULT);
}

