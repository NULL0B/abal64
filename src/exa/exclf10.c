/*  
 *	Group A String functions
 *	------------------------
 *
 * 0	B = LARGE( A )	Convert to upper case
 * 1	B = SMALL( A )	Convert to lower case
 * 2	B = SHL  ( A )	Shift left
 * 3	B = SHR  ( A )	Shift right
 * 4	B = INV  ( A )	Invert string
 * 567	B = FM   ( A )	Converts Ascii to FMT
 * 8	B = ENV  ( A )	Returns the current value of environment variable 'A'
 * 9	B = AFM  ( A )	Converts Format code string to Ascii string
 *	( Depends on definition of FMTOA )
 */

EXAWORD f_clfa(x)
EXAWORD	x;
{
	EXAWORD	desc,reg,memorlen;
	BPTR	memorptr;
	BPTR	resulptr;

	switch ( x ) {
		case 5  :	desc = 0x0054; break;
		case 6  :	desc = 0x0056; break;
		case 7  :	desc = 0x0040; break;
		default :	desc = (EXAWORD) *(fdex++); break;
		}
	/* Check for Destination REGISTER */
	/* ------------------------------ */
	if ( (desc & 0x0060) != 0x0060) {
		/* Evaluate Destination ! Register */
		/* ------------------------------- */
		if (argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) 
			return(SOFTERROR);
		if ( x != 7 ) 	{ 
			if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) 
				return(SOFTERROR); 
			}
		else 	{ 
			worklen2 = (EXAWORD) *(fdex++); worktyp2 = VARB_STR;
			workptr2 = fdex; fdex += worklen2;
			}
		}
	else 	{
		/* Establish Destination : REGISTER */
		/* -------------------------------- */
		reg = (EXAWORD) *(fdex++); 
		if ( x != 7 ) { 
			if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) 
				return(SOFTERROR);
			}
		else 	{
		 	workptr2 = fdex; worklen2 = 1; worktyp2 = VARB_STR; 
			while ( *(fdex++) != (EXABYTE) 0x00FF ) { worklen2++; }
			}
		worktyp1 = VARB_STR;
		if ( x == 8 ) 	
			worklen1 = 256;
		else	worklen1 = (EXAWORD) worklen2;

		if (argsetw(6,reg) == SOFTERROR) 
			return(SOFTERROR);

		}
	if ((( x <  5 ) || ( x > 7))
	&&  ((worktyp2 != VARB_STR) || (worktyp1 != VARB_STR))) {
		err_val = EXER_PARAM;
		return(SOFTERROR); 
		}

	/* Forward treatment */
	/*-------------------*/
	if (workptr1 == workptr2) {
		memorlen = worklen1; memorptr = workptr1;
		StackCheck( worklen1 );
		resulptr = (TcodeByteStack + worktop);
		worktop += worklen1;
		workptr1 = resulptr;
		}
	else 	memorlen = 0;

#ifndef	INTELASM2

	switch ( x ) {
/* LARGE */	case 0 :
/* SMALL */	case 1 : break;
/*  SHL  */	case 2 :
/*  SHR  */	case 3 :
			 while (( worklen2 > 0) && ( *workptr2 == IO_ESP )) {
					workptr2++; worklen2--;
					}
			 if (( x == 3 ) && (worklen2 > 0)) {
				 if ((desc = lenuse(workptr2,worklen2)) > worklen1) {
					workptr2 += (desc - worklen1);
					worklen2 = worklen1; 			 
					}
				 else 	worklen2 = desc;
				 desc = worklen1 - worklen2;
				 while ( desc > 0 ) { 	
					*(workptr1++) = IO_ESP;
					desc--; worklen1--;
					}
				}
			 break;

/*  INV  */	case 4 : workptr2 += (worklen2-1); break;
/*  FMT  */	case 5 :
/*  FMT  */	case 6 :
/*  FMT  */	case 7 : break;
/*  ENV  */	case 8 : if (ExaEnviron() == SOFTERROR) 
				return(SOFTERROR);
			 worklen1 = 0; break;

		case 9 : break;

#ifdef	ABAL21
/* PARSE */	case 10: /* V$ = PARSE( "PROC|USER|SEGM PTR <token>" ) */ 
#endif

/*  ???  */	default: unknown_tcode_error;
		}
/* Main treatment */
/*----------------*/
while (( worklen2 > 0 ) && ( worklen1 > 0 )) {
	switch ( x ) {
/* LARGE */	case 0 : *(workptr1++) = (EXABYTE) minimaji((EXAWORD) *(workptr2++)); break;
/* SMALL */	case 1 : *(workptr1++) = (EXABYTE) majimini((EXAWORD) *(workptr2++)); break;
/*  SHL  */	case 2 :
/*  SHR  */	case 3 : *(workptr1++) = *(workptr2++); break;
/*  INV  */	case 4 : *(workptr1++) = *(workptr2--); break;
/*  FMV  */	case 5 :
/*  FMR  */	case 6 : return(atofmt( workptr2,worklen2, workptr1, worklen1 ));
/*  AFM  */     case 9 : return(fmtoa(  workptr2,worklen2, workptr1, worklen1 ));
/*  FMT  */	case 7 : while (( worklen1 > 0 ) && ( worklen2 > 0 )) {
				*(workptr1++) = *(workptr2++);
				worklen1--; worklen2--;
				}
			 if (( worklen1 == 0 ) && ( worklen2 != 0 )) { 
				err_val = ABAL_BUF2SMALL; return(SOFTERROR); 
				}
			 worklen2 = 1; worklen1++; 
	  	default: break;
		}
	worklen2--; worklen1--;
	} /* Wend */

while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--; } 

#else
	switch ( x ) {
/* LARGE */ 	case 0 : 
			while ((worklen1 > 0) && (worklen2 > 0)) {
				*(workptr1++) = (EXABYTE) minimaji((EXAWORD) *(workptr2++) );
				worklen1--; worklen2--;
				}
			 while ( worklen1 > 0 ) {
				*(workptr1++) = IO_ESP; worklen1--;
				}
			 break;
/* SMALL */	case 1 : 
			while ((worklen1 > 0) && (worklen2 > 0)) {
				*(workptr1++) = (EXABYTE) majimini((EXAWORD) *(workptr2++) );
				worklen1--; worklen2--;
				}
			 while ( worklen1 > 0 ) {
				*(workptr1++) = IO_ESP; worklen1--;
				}
			 break;

/* SHL   */	case 2 : clf_shl();	break;
/* SHR   */	case 3 : clf_shr();	break;
/* INV   */	case 4 : clf_inv();	break;
/*  FMV  */	case 5 :
/*  FMR  */	case 6 : return(atofmt( workptr2,worklen2, workptr1, worklen1 ));
/*  AFM  */     case 9 : return(fmtoa(  workptr2,worklen2, workptr1, worklen1 ));
/*  FMT  */	case 7 : while (( worklen1 > 0 ) && ( worklen2 > 0 )) {
				*(workptr1++) = *(workptr2++);
				worklen1--; worklen2--;
				}
			  if (( worklen1 == 0 ) && ( worklen2 != 0 )) { 
				err_val = ABAL_BUF2SMALL; 
				return(SOFTERROR); 
				}
			  worklen2 = 1; worklen1++;
			  break;

/* ENV  */	case 8 :  if (ExaEnviron() == SOFTERROR) 
				return(SOFTERROR); 
		}
#endif

/* End treatment */
/*---------------*/
if ( memorlen > 0 ) 
	(VOID) memcpy(memorptr,resulptr,memorlen);

return(1);		
}

