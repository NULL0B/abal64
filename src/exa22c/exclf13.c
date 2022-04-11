#ifndef	_EXCLF13_C
#define	_EXCLF13_C

#ifdef	ABAL21
EXAWORD	transfer_code_pointer( result, source )
BPTR	result;
BPTR	source;
{
	EXAWORD	nature;
	EXAWORD	get_abal_pointer_type( BPTR );

	if (!( get_abal_pointer_type( source ) ))
		memset( result, 0, 5 );
	else	memcpy( result, source, 5 );
	return( GOODRESULT );
}
#endif

/*	Group D : Functions which generate strings from integer Arguaments
 *	------------------------------------------------------------------
 *
 *	GENER(X,Y)	Generate string of length X using character Y Code 0
 *	SPACE(X)	Generate string of blanks length X	      Code 1
 *	DATE(X)		Generate string of date element X	      Code 2
 *	KBF(X)		Return current function key string of X	      Code 3
 *	CURDIR   	Returns current directory   (.   , \  etc )   Code 4
 *	CURVOL   	Returns current logged unit (MD0 , C: etc )   Code 5
 *	HEX (X)		Generates the Hexa version of X		      Code 6
 *	CHR$(X)		Creates unicharacter string		      Code 7
 *	REPEAT(X,Y)	Generate String repeating string Y X times    Code 8
 *	Buff = CRYPT(X,Y) ;** Code / Mode			      Code 9
 *	SYSERROR	Recover BCD value of last system error	      Code 10
 *	PROCPTR		Attatch Procedure to provided Pointer $	      Code 11
 *	USERPTR		Attatch User Call to provided Pointer $	      Code 12
 *	SEGMPTR		Attatch Segment   to provided Pointer $	      Code 13
 *	RECV(BUFFER,IPC) Receive IPC Message			      Code 14	
 *	WAIT(BUFFER,IPC) Receive IPC Message			      Code 15	
 *	
 */

EXAWORD	f_clfd(x)
EXAWORD	x;
{
	EXAWORD	desc,descx,reg,bpflg;
	EXABYTE	c;
	EXAWORD	Longeur;



/* ReSet Back Patch of Register FLAG */
/* --------------------------------- */
 bpflg = 0;

/* Check for and collect Second Byte */
/* --------------------------------- */
if ((desc = (EXAWORD) *(fdex++)) & 1)
	descx = (EXAWORD) *(fdex++);

/* Check for Destination is a Register (Temporary Zone) */
/* ---------------------------------------------------- */ 
if ((desc & 0x0060) == 0x0060) { 
	/* Set Back Patch of Register FLAG */
	/* ------------------------------- */
	bpflg = 1;
	/* Collect Register ID Now */
	/* ----------------------- */
	reg = (EXAWORD) *(fdex++);  
	/* Check for and Evaluate 2nd Arguament */
	/* ------------------------------------ */
	if ( desc & 0x0010 ) {
		ExFlgSgn = 1;
		if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) { 
			ExFlgSgn = 0;
			return(SOFTERROR); 
			}
		ExFlgSgn = 0;
		}
	/* Compatibility Switch BAL 0 == 256 */
	/* --------------------------------- */
	if ((workval2 == 0) && ( x < 2) && (CompatibleBal))
		workval2 = 256; 

	/* Create Result Length With respect to function */
	/* --------------------------------------------- */
	switch ( x ) {	
#ifdef	ABAL21
		case 13 :
		case 12 :
		case 11 : worklen1 = 5; break;
#endif
		/* SPACE */
		case 1 : c = IO_ESP; worklen1 = workval2; break; 
		/* GENER */
		case 0 : worklen1 = (EXAWORD) workval2; break;
		case 6 :
		case 2 : worklen1 = 256; break;
		case 3 : 
		case 4 :
		case 8 :
		case 5 : worklen1 = 256; break;
#ifdef	ABAL14
		case 10: worklen1 =  12; break;
#endif
		/* CHR$ */
		case 7 : 
			/* Always UniCharacter */
			/* ------------------- */
			worklen1 = 1; 
			/* Select Character Source */
			/* ----------------------- */
			switch ( worktyp2 ) { 
				case VARB_STR   : c = *workptr2; break;
				case VARB_BCD   : workval2 = bcdtoi(workptr2,worklen2);
				case VARB_INT8  :
				case VARB_INT16 : c = (unsigned char) workval2; break;
				}
			workval2 = 1; 
			break;
		}
#ifdef	ABAL14
	/* String results except for SYSTERROR which returns a BCD */
	/* ------------------------------------------------------- */
	if ( x != 10 ) 	
		worktyp1 = VARB_STR;
	else	worktyp1 = VARB_BCD;
#else
	/* Always String Result : Establish Temporary Descriptor */
	/* ----------------------------------------------------- */
	worktyp1 = VARB_STR;
#endif

	if (argsetw(6,reg) == SOFTERROR) 
		return(SOFTERROR);
	}

else 	{
	/* Not a Register Destination */
	/* -------------------------- */

	/* Establish Destination Length protected Result Set */
	/* ------------------------------------------------- */
	if (argsetw(((desc & 0x0060) >> 5),0x00FF) == SOFTERROR) 
		return(SOFTERROR);

	/* Check for and Establish 2nd Arguament */
	/* ------------------------------------- */
	if (( desc & 0x0010 )
	&&  (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR))
		return(SOFTERROR);

	/* Special Case CHR$ and SPACE */
	/* --------------------------- */
	switch ( x ) {
		case 1 : c = IO_ESP; break;
		case 7 : 
			worklen1 = 1;
			switch ( worktyp2 ) { /* Get character for CHR$ */
				case VARB_STR   : c = *workptr2; break;
				case VARB_BCD   : workval2 = bcdtoi(workptr2,worklen2);
				case VARB_INT8  :
				case VARB_INT16 : c = (unsigned char) workval2; break;
				}
			 workval2 = 1; break;
		}
	}
/* Check for 3rg arguament */
/* ----------------------- */
if ((desc & 1) != 0) {
	/* Establish 3rd Arguament */
	/* ----------------------- */
	if (argset(((descx & 0x0060) >> 5),0,3) == SOFTERROR) 
		return(SOFTERROR);

	/* Collect the character for Gener */
	/* ------------------------------- */
	switch ( worktyp3 ) {
		case VARB_STR   : c = *workptr3; break;
		case VARB_BCD   : workval3 = bcdtoi(workptr3,worklen3);
		case VARB_INT8  :
		case VARB_INT16 : c = (unsigned char) workval3; break;
		}
	}
if ((x != 7) && ( worktyp2 == VARB_BCD )) { workval2 = bcdtoi(workptr2,worklen2); worktyp2 = 1;}
if ((x != 7) && ( worktyp2 == VARB_STR )) { workval2 =   atoi(workptr2,worklen2); worktyp2 = 1;}

/* Compatibility Switch BAL 0 == 256 */
/* --------------------------------- */
if ((workval2 == 0) && ( x < 2) && (CompatibleBal)) 
	workval2 = 256; 

/*	Perform the STRING Function 	*/
/*	---------------------------	*/
switch ( x ) {
#ifdef	ABAL21
	case 11 :	/* PROCPTR() : WORKPTR1 = PROCPTR( WORKVAL1 ) */
			/* ------------------------------------------ */
		if ( worktyp2 == 3 )
			return( transfer_code_pointer( workptr1, workptr2 ));
		else if ( worktyp2 < 2 )
			return( attatch_procedure_pointer( workptr1, workval2 ) );
		else	{
			err_val = 56;
			return(SOFTERROR);
			}

	case 12 :	/* USERPTR */

		if ( worktyp2 == 3 )
			return( transfer_code_pointer( workptr1, workptr2 ));
		else if ( worktyp2 < 2 ) {
			memset( workptr1, 0, 5 );
			*workptr1 = USER_POINTER;
			balputw(((EXAWORD) workval2),(workptr1+1));
			balputw(((EXAWORD) workval3),(workptr1+3));
			return( GOODRESULT );
			}
		else	{
			err_val = 56;
			return(SOFTERROR);
			}

	case 13 :	/* SEGMPTR */

		switch ( worktyp2 ) {
			case 3 :
				return( transfer_code_pointer( workptr1, workptr2 ));
			case 2 :
				workval2 = bcdtoi((BPTR) workptr2, worklen2);
 			case 1 :
			case 0 :
				*workptr1 = SEGMENT_POINTER;
				balputw( 0,(workptr1+1));
				balputw(((EXAWORD) workval2),(workptr1+3));
				return( GOODRESULT );
			default :
				err_val = 56;
				return(SOFTERROR);
			}


	case 15		:	/* WAIT(MESSAGE,IPC) */
	case 14 	:	/* RECV(MESSAGE,IPC) */
				/* ----------------- */
		 return( IpcRecv( workval2,(BPTR)  workptr1, worklen1, (x&1) ) );

#endif
#ifdef	ABAL14
	case 10:	/* SysError()	*/
			/* ----------	*/

		return(ltobcd(workptr1,worklen1,SystemError));
		
#endif
	case 9 : 	/* Crypt(x,y)	*/
			/* ----------	*/
		 (VOID) exa_crypt(workval2,workptr1,worklen1,workval3);
		 return(1);

	case 8 :	/* Gener$(x,y)  */
			/* -----------  */
		workptr2 = workptr3; worklen2 = worklen3;
		while (( worklen1 > 0 ) && ( workval2 > 0 )) {
			*(workptr1++) = *(workptr2++);
			worklen1--; worklen2--;
			if ( worklen2 == 0 ) {
				workval2--; worklen2 = worklen3;
				workptr2 = workptr3;
				}
			} 
		 while (worklen1 > 0) { *(workptr1++) = IO_ESP; worklen1--; }
		 return(1);
#ifndef INTELASM2
	case 0 :	/* GENER (x,c)			*/
	case 1 :	/* SPACE ( x (c == ' ') )  	*/
	case 7 :	/* CHR$  ( c )  		*/	
			/* ---------------------------- */
		 Longeur = workval2;
		 while ((worklen1 > 0) && (Longeur > 0)) { 
			*(workptr1++) = c; worklen1--; Longeur--; 
			}
		 return(1);
#else
	case 0 : worklen3 = (EXAWORD) c; 
		 clf_gener(); return(1);
	case 1 : clf_space(); return(1);
	case 7 : *workptr1 = c;	return(1);
#endif
		  /* --------------------------- */
	case 2 :  /* WORKPTR1 = DATE( WORKVAL2 ) */
		  /* --------------------------- */

		/* Reset Result Zone */
		/* ----------------- */
		memset( workptr1 , ' ' , worklen1 );

		/* Select Date Element */
		/* ------------------- */
		switch ( workval2 ) {
			case 5 :
			case 6 :
			case 7 : 

#ifdef PROLOGUE
				workval2--;
#endif

#ifdef	DOS
			case 8 :
#endif

			case 1 :
			case 2 :
			case 3 : /* Convert Date Result to Ascii String */
				 /* ----------------------------------- */
				  itoa(date(workval2),workptr1,worklen1);

				 /* Watch out for REAL LENGTH BACK PATCH */
				 /* ------------------------------------ */
				  if ( bpflg == 1 ) { 

					/* Calculate REAL LENGTH */
					/* --------------------- */
					worklen1 = lenuze(workptr1,worklen1);

					/* Ensure clean string for ABAL */
					/* ---------------------------- */
					*(workptr1 + worklen1) = ' ';

					/* Patch descriptor with REAL LENGTH */
					/* --------------------------------- */
					TcodePmot( (workptr1 - WORDSIZE) , worklen1 );
					}
				  break;

			case 4  :
					workval1 = date(1);
				  if( ((( workval1 % 4 ) == 0) && ((workval1 % 100) != 0)) || (( workval1 % 400) == 0))
					ymtabl[1] = 29;
				  else  ymtabl[1] = 28;
				  workval1 = date(2) - 1; workval2 = 0;
				  while ( workval1 > 0 ) { 
					workval2 += (EXAWORD) ymtabl[workval1 -1]; 
					workval1--;
					}
				  workval2 += date(3);
				  itoa(workval2,workptr1,worklen1); break;
#ifndef	PROLOGUE
#ifndef	DOS
			case 8  : itoa( (((date(5) * date(6))) % 10) ,workptr1,worklen1);break;
#endif
#else
			case 8  : PrlDate8((BPTR) workptr1, worklen1); break; 
#endif
			}
		 break;
	case 6 : worktyp2 &= 1; 
		 worktyp2 += 1; 
		 worktyp2 *= 2;
		 if ( worklen1 < worktyp2 ) { 
			err_val = ABAL_BUF2SMALL; 
			return(SOFTERROR); 
			}
		 if ((worktyp2 = itohex((EXAWORD) workval2,workptr1,worktyp2)) < worklen1 )
			 memset((workptr1 + worktyp2),' ',(worklen1 - worktyp2));
		 break; 
	case 3 :
		/* -------------------- */
		/* $ = KBF ( key_id % ) */
		/* -------------------- */

		/* Limit to 8 bits if Type # */
		/* ------------------------- */ 
		if (( worktyp2 & VARB_ISOL ) == 0 )
			workval2 = (workval2 & 0x00FF);

		/* Ensure Unsigned Value */
		/* --------------------- */
		worklen3 = (EXAWORD) workval2;
#ifdef	ABAL21
		if ( worklen3 >= 1000 )
			 return( IpcRecv( (worklen3-1000),(BPTR)  workptr1, worklen1, (EventChannel & 1) ) );

		else	{
#endif
			/* Test for Exceeding KBF count */
			/* ---------------------------- */
			if (worklen3 > (conf(9) + 0x007F)) {

				/* Function Key unknown Return ERROR 111 */
				/* ------------------------------------- */
				err_val = 111; return(SOFTERROR);
				}

			/* Reset the Zone to Spaces */
			/* ------------------------ */
			memset( (BPTR) workptr1 , ' ', worklen1 );

			if ( worklen1 > 32 )
				worklen1 = 32;

			/* Perform KBF Read function KEY */
			/* ----------------------------- */
			if ((worklen3 = lcfo((USINT) workval2,(BPTR) workptr1,(USINT) worklen1)) == MOINS_UN) { 
				err_val = 111;
				return(SOFTERROR); 
				}
			else	err_val = 0;
#ifdef	ABAL21
			}
#endif
		/* OK now perform exit routines */
		/* ---------------------------- */
		break;

	case 4 :	/* $ = CURVOL() */
			/* ------------ */
		 return(excwdir(workptr1,worklen1,0));

	case 5 :	/* $ = CURDIR() */
			/* ------------ */
		 return(excwdir(workptr1,worklen1,1));

 	default : err_val = EXER_SYNTAX; return(SOFTERROR);

	}

	/* Padd with spaces if required */
	/* ---------------------------- */
	if (((x = lenuze(workptr1,worklen1)) < worklen1 )
	&&  (( worklen1 - x ) > 0 ))
		(VOID) memset((workptr1 + x),' ',(worklen1 - x)); 

return(1);
}

	/* ---------- */
#endif  /* _EXCLF13_C */
	/* ---------- */
