/*
 *	A u t o M a t e ( )
 *	-------------------
 *	Initialisation of File Name Conversion routines
 *
 */	

int	strchk(char * aptr, char * bptr)
{
	while (( *aptr != 0) && ( *bptr != 0 )) {
		if ( *aptr != *bptr )
			return( *aptr - *bptr );
		else	{
			aptr++; bptr++;
			}
		}
	if (!( *aptr )) 
		return(0);
	else	return( *aptr - *bptr );
}
EXAWORD	AutoMate()
{
	EXAWORD	mode;
	BPTR	mateptr;

	/* Attempt to Read Environment Variable ABALANFC */
	/* --------------------------------------------- */
	if ((mateptr = (BPTR) getenv((BPTR)"ABALANFC")) == (BPTR) 0 )
		return(0);

	/* Position to Start of String */
	/* --------------------------- */
	while (( *mateptr != '=' ) && ( *mateptr != (EXABYTE) 0 )) 
		mateptr++;

	if ( *mateptr == (EXABYTE) 0 ) 
		return(0);

	mode = 0; mateptr++;

	/* Analysis of ANFC Conversion Control String */
	/* ------------------------------------------ */
	while ( *mateptr != (EXABYTE) 0 ) {
		switch ( *(mateptr++) ) {
			case 'u' :
			case 'U' : mode |= 1; break;
			case 'l' :
			case 'L' : mode |= 2; break;
#ifdef	ABAL14
			/* f<filename> indicates a file which contains ANFC */
			/* ------------------------------------------------ */
			case 'f' :
			case 'F' : mode |= 4; break;
#endif
			case 'm' :
			case 'M' : mode |= 8; break;
			}
		}

	return( mode );		

}

#define	IsAlpha(c) ((( (c) >='A' ) && ( (c) <= 'Z' )) || (( (c) >='a' ) && ( (c) <= 'z' ))) 
#define IsNumeric(c) (( (c) >='0' ) && ( (c) <= '9' )) 

EXAWORD	convert_mnemonics(EXAWORD workset,EXAWORD operation)
{
	BPTR	zerkptr;
	BPTR	workptr;
	EXAWORD	worklen;
	EXAWORD	z;
#ifdef	LINUX_MNEMONICS
	EXAWORD	other=0;
	EXAWORD	copied=0;
	EXAWORD	mz=0;
	EXAWORD	iz=0;
	EXAWORD	checkterm=0;
	BPTR	mnemptr=(BPTR) 0;
	BPTR	bildptr=(BPTR) 0;
#endif

	switch ( workset ) {
		case	0 :
		case	1 : workptr = workptr1; worklen = worklen1; break;
		case	2 : workptr = workptr2; worklen = worklen2; break;
		case	3 : workptr = workptr3; worklen = worklen3; break;
		default	  :
			err_val = 999;
			return( SOFTERROR );
		}

	/* -------------------------------- */
	/* Test for Auto Convertor Required */
	/* -------------------------------- */
	if ( operation != 0 ) {

		if (!( dieztmp ))
			zerkptr = workptr;
		else if (( worktop + worklen +2 ) > dieztmp ) {
			err_val = 114;
			return( SOFTERROR );
			}
		else	{
			zerkptr = (TcodeByteStack+worktop);
			worktop += (worklen + 2);
			}

		/*	If Automatic File Conversions Required		*/
		/*	--------------------------------------		*/
		for ( z = 0; z < worklen; z++ ) {
			switch ( operation & 3 ) {
				case 1	:	/* Convert to Upper */
						/* ---------------- */
					*(zerkptr + z) = toupper( (*(workptr+z)));
					break;
				case 2  :	/* Convert to Lower */
						/* ---------------- */
					*(zerkptr + z) = tolower( (*(workptr+z)));
					break;
				default	:
					*(zerkptr + z) = *(workptr+z);
				}
			}

		if ( dieztmp != 0 ) {
			*(zerkptr + z) = 0; workptr = zerkptr;
			}

#ifdef	LINUX_MNEMONICS

		/* Check for Mnemonics Conversion */
		/* ------------------------------ */
		if ( operation & 8 ) {
			mnemoffs = z = iz =0;
			while ( *(workptr+iz) != 0 ) {
	
				checkterm = 0;

				if ((iz > 0 			 )
				&&  (*(workptr+iz-1) != '/'	 )
				&&  (*(workptr+iz-1) != 0x005C   )) {
					iz++;
					continue;
					}

				/* ensure string long enough for mnemonic */
				/* -------------------------------------- */
				if ((!( *(workptr+iz+0) ))
				||  (!( *(workptr+iz+1) ))
				||  (!( *(workptr+iz+2) )))
					break;
 
				/* Detect Dos Things */
				/* ----------------- */
				if ( *(workptr+iz+1) == ':' )
					checkterm = 1;
				
				/* Detect Implicites IS,IP,IF */
				/* -------------------------- */
				else if (( *(workptr+iz) == 'i' )
				     ||  ( *(workptr+iz) == 'I' )) {
					switch ( *(workptr+iz+1) ) {
						case	's'	:
						case	'S'	:
						case	'p'	:
						case	'P'	:
						case	'f'	:
						case	'F'	:
							checkterm = 2;
							break;
						default		:
							checkterm=0;
						}
					}
				else	checkterm = 0;
	
				if (!( checkterm )) {
					/* Detect Numeric Figure after 2 Characters */
					/* ---------------------------------------- */
					if ((!( IsAlpha  ( (*(workptr+iz+0)) ) ))
					||  (!( IsAlpha  ( (*(workptr+iz+1)) ) ))
					||  (!( IsNumeric( (*(workptr+iz+2)) ) )) ) {
						iz++;
						continue;
						}
					else	checkterm=3;
					}			
				/* Detect Ressource Separator */
				/* -------------------------- */
				switch ((z = *(workptr + iz + checkterm ))) {
					case	0	: 	
					case	' '	:	
					case	'.'	:
					case	'/'	:
					case	0x005C	: /* backslash */
					case	':'	: 
						break;
					default		:
						iz++;
						continue;
					}

				/* Detect a substitution value */
				/* --------------------------- */
				/* terminate for getenv */
				*(workptr + iz + checkterm ) = 0;

				/* locate environment variable */
				if (!( mnemptr = getenv( (workptr+iz) ) )) {

					/* no so put it back , continue */
					/* ---------------------------- */
					*(workptr+iz+checkterm) = z;
					iz++;
					continue;
					}
				else if (!( strchk((workptr+iz),mnemptr ) )) {
					/* no so put it back , continue */
					/* ---------------------------- */
					*(workptr+iz+checkterm) = z;
					iz++;
					continue;
					}
				else if (((other = strlen(mnemptr)) > 0) 
				     &&   ( *(mnemptr + (other-1)) == '/' ))
					*(mnemptr + (other-1)) =0;

				/* Here we must rebuild the workstring */
				/* to contain the right hand porition  */
				/* the substitution value nad the rest */
				bildptr = &mnemzone[mnemoffs];

				/* cut and copy right hand portion */
				/* ------------------------------- */
				other = *(workptr+iz); *(workptr+iz) = 0;
				strcpy(bildptr,workptr);
				*(workptr+iz) = other;

				if (( iz != 0 )
				&&  ( *mnemptr == '/' ))
					mnemptr++;

				/* concatenate the substitution value */
				/* ---------------------------------- */
				strcat( bildptr, mnemptr );

				if ( z == '.' ) {
					if (( *(workptr+iz+checkterm+1) == '/' ) 
					||  ( *(workptr+iz+checkterm+1) == '\\' )) {
						/* convert ./ to / */
						*(workptr+iz+checkterm) = z;
						strcat(bildptr,(workptr+iz+checkterm+1));
						}
					else if ((!( *(workptr+iz+checkterm+1) )) 
					     ||  (   *(workptr+iz+checkterm+1)==' ')) {
						/* terminal DOT is simply removed */
						*(workptr+iz+checkterm) = z;
						}
					else 	{
						/* convert . to / */
						*(workptr+iz+checkterm) = '/';
						strcat(bildptr,(workptr+iz+checkterm));
						*(workptr+iz+checkterm) = z;
						}
					}
				else  if ( z != ':' )	{
					*(workptr+iz+checkterm) = z;
					strcat(bildptr,(workptr+iz+checkterm));
					}
				else	strcat(bildptr,(workptr+iz+checkterm+1));


				/* Here we do not increment to allow */
				/* mnemonics to redefine mnemonics   */
				/* --------------------------------- */
				copied=1;
				*(workptr+iz+checkterm) = z;
				workptr = bildptr;
				worklen = strlen(bildptr);
				mnemoffs += (worklen+2);
				} 
			}
		if (!( copied )) {
			strcpy(mnemzone,workptr);
			workptr = mnemzone;
			worklen = strlen(mnemzone);
			}
		for (z=0; z < worklen; z++ )
			if (*(workptr+z) == 0x005C ) /* is it backslash */
				*(workptr+z) = '/';  /* make it slash   */
#endif
		}
	switch ( workset ) {
		case	0 :
		case	1 : workptr1 = workptr; worklen1 = worklen; break;
		case	2 : workptr2 = workptr; worklen2 = worklen; break;
		case	3 : workptr3 = workptr; worklen3 = worklen; break;
		default	  :
			err_val = 999;
			return( SOFTERROR );
		}

	return( GOODRESULT );
}

