/* 
 *	Group 8	Miscellaneaus functions
 *	-------	-----------------------
 *	
 *	0) -	N = ABS 	( N )	Valeur absolu numerique
 *	1) -	A = INCLUD( n , B , n )	Inclusion dans une chaine
 *	2) -	A = TRAN ( s , s , s , n ) Transcodage d'un chaine
 *	3) -	A = INSERT( n , B , n )	Insertion dans une chaine
 *
 *	4) - 	A = MKDIR( path )	Creation of a local directory
 *	5) - 	A = RMDIR( path )	Removal  of a local directory
 *
 */

EXAWORD f_clf8(x)
EXAWORD	x;
{
	EXAWORD	desc,reg,descx,descy,tran;
#ifdef	INSERT_WITHOUT_MEMORY
	EXAWORD	offset;
#endif
	BPTR	codptr;
	EXAWORD	Longeur;
	BINAIRE	Indent;
	BINAIRE	Kontrol;

/* Collect 1st ARG descriptor byte */
/* ------------------------------- */
desc = (EXAWORD) *(fdex++); descx = 0; descy = 0;

/* Check for and Collect Second ARG descriptor byte */
/* ------------------------------------------------ */
if ((desc & 1) != 0) {
	descx = (EXAWORD) *(fdex++); 
	/* Check for and Collect Third  ARG descriptor byte */
	/* ------------------------------------------------ */
	if (( descx & 1 ) != 0) { descy = (EXAWORD) *(fdex++);}
	}
/* If Not Register destination */
/* --------------------------- */
if ((desc & 0x0060) != 0x0060) {
	/* Establish result WorkSet1 */
	/* ------------------------- */
	if (argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) { return(SOFTERROR); }
	/* Establish 2nd Arg (Indent or 2nd String) */
	/* ---------------------------------------- */
	if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) { return(SOFTERROR); }
	reg = 0;
	}
/* Else Establish Register result Workset1 */
/* --------------------------------------- */
else { 	reg = (EXAWORD) *(fdex++);	
	/* Collect 2nd Arg for Result length determination */
	/* ----------------------------------------------- */
	if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) { return(SOFTERROR); }
	switch ( x ) {

		/*	Special case for ABS	*/
		/* 	--------------------	*/
		case 0  : worktyp1 = worktyp2;
			  if ( worktyp2 == VARB_BCD ) {
				worklen1 = (EXAWORD) 12;
				if (argsetw(6,reg) == SOFTERROR) {
					return(SOFTERROR);
					}
				}
			  break;

		default : worktyp1 = VARB_STR; worklen1 = (EXAWORD) worklen2;
			  if (argsetw(6,reg) == SOFTERROR) { return(SOFTERROR); }
			  break;
		}
	} /* End else */
/* Establish 3rd Arg if Existant */
/* ----------------------------- */
if ( (desc & 1) != 0 ) { if (argset(((descx & 0x0060) >> 5),0,3) == SOFTERROR) { return(SOFTERROR); } }

/* Perform requested function */
/* -------------------------- */
switch ( x ) {
	/* WorkSet1 = MKDIR(WorkSet2)  */
	/* --------------------------- */
	case	4 :
		StackCheck( worklen2 );
		(VOID) memcpy((BPTR) (TcodeByteStack + worktop),(BPTR) workptr2,(USINT) worklen2);
		workptr2 = (BPTR) (TcodeByteStack + worktop);
		worktop += worklen2;
		worklen2 = lenuze( workptr2, worklen2 );
		*(workptr2 + worklen2) = (EXABYTE) 0;
		if ( mkdir( workptr2, 0666 ) == -1 )
			isave(reg,58);
		else	isave(reg,0);
		break;

	/* WorkSet1 = RMDIR(WorkSet2)  */
	/* --------------------------- */
	case	5 :
		StackCheck( worklen2 );
		(VOID) memcpy((BPTR) (TcodeByteStack + worktop),(BPTR) workptr2,(USINT) worklen2);
		workptr2 = (BPTR) (TcodeByteStack + worktop);
		worktop += worklen2;
		worklen2 = lenuze( workptr2, worklen2 );
		*(workptr2 + worklen2) = (EXABYTE) 0;
		if ( rmdir( workptr2 ) == -1 )
			isave(reg,58);
		else	isave(reg,0);
		break;

	/* WorkSet1 = ABS ( WorkSet2 ) */
	/* --------------------------- */
	case 0  : switch ( worktyp1 ) {
			case VARB_INT8  : 
			case VARB_INT16 : 
			case VARB_INT32 : 
			case VARB_INT64 : 
				isave(reg,abs(workval2)); 
				break;

			case VARB_BCD   : 

				/* Create Temporary Copy of Source */
				/* ------------------------------- */
				StackCheck( worklen2 );
				(VOID) memcpy((BPTR) (TcodeByteStack + worktop),(BPTR) workptr2,(USINT) worklen2);
				workptr2 = (BPTR) (TcodeByteStack + worktop);
				*(workptr2 + worklen2) = (EXABYTE) 0x00FF;
				worktop += worklen2;

				/* Check for Negative Fixed */
				/* ------------------------ */
				if ((((EXAWORD)(*workptr2)) & 0x00F0) == 0x0040) { 
					if ((workptr2 = (BPTR) negbcdcpy(workptr2,worklen2)) == (BPTR) 0 ) {
						return(SOFTERROR);
						}
					}

				/* Perform Sign Conversion to Positive */
				/* ----------------------------------- */
				 *workptr2 = (EXABYTE) ((((EXAWORD) *workptr2) & 0x000F) | 0x00C0);

				/* Store to Result Variable */
				/* ------------------------ */
				 return(varconv(0));

			case VARB_STR   :
			default: err_val = EXER_PARAM; return(SOFTERROR);
			}
		  break;	

	case 1  : /* Workptr1 = INCLUD ( Workval2 , Workptr3 , TempSet ) */
		  /* ------------------------------------------------- */
		Indent = workval2;
		if ( (descx & 0x0010) != 0) {
			if (argset(((descx & 0x0006) >> 1),0,2) == SOFTERROR) { return(SOFTERROR); }
			if ( workval2 == 0 ) { workval2 = 256; }
			}
		else { workval2 = worklen3; }
		Kontrol = worklen1;
		if ( Indent <= Kontrol ) {
			Indent--;
			workptr1 += Indent; worklen1 -= Indent;
			Longeur = workval2;
			while (( Longeur > 0 ) && ( worklen1 > 0 )) {
				*(workptr1++) = *(workptr3++);
				Longeur--; worklen1--;
				}
			}
		break;

	case 2  : /* A = TRAN(Identif,Coder,length,Object) */
		  /* ------------------------------------- */
		  codptr = workptr3;

		/* Collect Substitution string length */
		/* ---------------------------------- */
		  if ( argset((descx & 0x0006) >> 1,0,3) == SOFTERROR ) { return(SOFTERROR); }
		  tran = workval3;
		  if ( workval3 < 0 ) { err_val = ABAL_NEGARG; return(SOFTERROR);   }

		/* Collect String to be Translated */
		/* ------------------------------- */
		  if ( argset((descy & 0x0060) >> 5,0,3) == SOFTERROR ) { return(SOFTERROR); }

		/* Perform String Translation */
		/* -------------------------- */
		  while (( worklen3 > 0 ) && ( worklen1 > 0)) {
			*(workptr1++) = (EXABYTE) xtrans(workptr2,codptr,tran,(EXAWORD) *(workptr3++));
			worklen1--; worklen3--;
			}
		/* Perform Right hand space padding */
		/* -------------------------------- */
		  while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--;  }
		  break;

	case 3  : /* A = INSERT(debut,chaine,longeur)	*/
		  /* ---------------------------------- */
		Indent = workval2;
		if ( (descx & 0x0010) != 0) {
			if (argset(((descx & 0x0006) >> 1),0,2) == SOFTERROR) { return(SOFTERROR); }
			if ( workval2 == 0 ) { workval2 = 256; }
			}
		else { workval2 = worklen3; }

		Kontrol = worklen1;
		if ( Indent <= Kontrol ) {
			Indent--;
			workptr1 += Indent; worklen1 -= Indent;
			StackCheck( worklen1 );
			workptr2 = (TcodeByteStack + worktop);
			memcpy(workptr2,workptr1,worklen1);
			worktop += worklen1;
			Longeur = workval2;
			while (( Longeur > 0 ) && ( worklen1 > 0 )) {
				*(workptr1++) = *(workptr3++);
				Longeur--; worklen1--;
				}
			if ( worklen1 > 0) { memcpy(workptr1,workptr2,worklen1); }
			}
#ifdef	INSERT_WITHOUT_MEMORY
		Kontrol = worklen1;
		Longeur = workval2;

		if (( Indent <= Kontrol )
		&&  ( Longeur > 0       )) {
			Indent--;
			workptr1 += Indent; worklen1 -= Indent;
			if ( Longeur < worklen1 ) {
				/* ----------------------------- */
				/* inserted length is less than  */
				/* remainder to the right of the */
				/* point of insertion            */
				/* ----------------------------- */
				for ( offset=(worklen1-1); offset > Longeur; offset-- )
					*(workptr1+offset) = *(workptr1+offset-1);
				}
			while (( Longeur > 0 ) && ( worklen1 > 0 )) {
				*(workptr1++) = *(workptr3++);
				Longeur--; worklen1--;
				}
			}
#endif
		break;
	default : err_val = EXER_FUNCWOT; return(SOFTERROR);
	}
return(1);
}
