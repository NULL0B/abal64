/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *	Module  : ATR
 *	Fichier : FN_PARSE.C
 *	Version : 2.1f
 *	Date    : 22/11/95
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Decoupage d'un nom de fichier]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *	18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	11/09/90 : Correction bug prologue ou IP,IF et IS etaient consideres
 *		   comme des noms de fichier.
 *	04/12/90 : Prototypage fn_memcpy pour non LINT_ARGS
 *	------------ 2.1d -------------------------------------------------
 *	22/11/95 : version dediee 2.1
 */

#ifdef LINT_ARGS
static char *fnmemcpy(char *,char *,int);
#else /* ! LINT_ARGS */
static char *fnmemcpy();
#endif /* LINT_ARGS */

static char *fnmemcpy(rptr , sptr , len )
char *rptr;
char *sptr;
int  len;
{
	int	x;
	for ( x = 0; x < len; x++ ) *(rptr + x ) = *(sptr + x );
	return( rptr );
}

int	fn_parser(sptr , rptr , mode )

		/* ---------------------------------------------------- */
char *sptr;	/* Source file name string				*/
char *rptr;	/* Pointer to Result Buffer 				*/
		/* ---------------------------------------------------- */
int	mode;	/* Extraction type Bit definitions			*/
		/* ---------------------------------------------------- */
		/*		   1	NetWork Node Name		*/
		/*		   2	Device Mnemonic			*/
		/*		   4	Path name only			*/
		/*		   8  	FileName portion		*/
		/*		   16	Extension and separator		*/
		/*		   32	Amenesik / Sologic Password		*/
		/*		   64   vms Version Number 		*/
		/* ---------------------------------------------------- */
{
	int	ai;
	int	bi;
        int     ci;
#ifdef vms
        int     di;
#endif
	int	ri;
	int	termine;
	char	*termptr;
#ifdef	prologue
	int	implicite;
	implicite = 0;
#endif /* prologue */

	/* If No Current Object */
	/* -------------------- */
	if (sptr == (char *) 0 ) {  return(0);  }

	/* Calculate and Test String Length */
	/* -------------------------------- */
	ai = 0;
	while (( *(sptr + ai) != 0 ) && (*(sptr + ai) != 0x000D)) ai++;
	if ( ai == 0 ) 		    { return(0); }

	/* Keep terminator and ensure ZERO termination */
	/* ------------------------------------------- */
	termptr = (sptr + ai); termine = *termptr; *termptr = 0;

	/* Zero out the result index */
	/* ------------------------- */
	ri = 0;

#ifdef	prologue

	/* -------------------------------------------- */
	/* Amenesik / Sologic :    MD0.\*\*\filename.-ext:RRWW		*/
	/* -------------------------------------------- */

	/* Check for and Transfer Network Node Name */
	/* ---------------------------------------- */
	if ( mode & 1 ) { }

	/* Check for Implicte device identifiers */
	/* ------------------------------------- */
	if ( ai >= 3 ) {

		if ( *(sptr + 2) == '.' ) {
			if (( *sptr == 'i' ) || ( *sptr == 'I' )) {
				switch ( *(sptr + 1) ) {

					case 's' :
					case 'S' :
					case 'f' :
					case 'F' :
					case 'p' :
					case 'P' :
					/* Scan past Device Mnemonic */
					/* ------------------------- */
					if ( mode & 2 ) {
						fnmemcpy((char *) (rptr + ri) ,(char *) sptr , 3 );
						ri += 3;
						}
					sptr += 3; ai -= 3;
					implicite = 1;
					}
				}
			}
		}

	/* Check for and Transfer Device Mnemonic */
	/* -------------------------------------- */
	if (( ai >= 4 ) && ( implicite == 0 )) {
		if ( *(sptr + 3) == '.' ) {
			if (( *(sptr + 2) >= '0' ) && ( *(sptr + 2) <= '9' )) {

				/* Scan past Device Mnemonic */
				/* ------------------------- */
				if ( mode & 2 ) {
					fnmemcpy((char *) (rptr + ri) ,(char *) sptr , 4 );
					ri += 4;
					}
				sptr += 4; ai -= 4;
				}
			}
		}
	bi = ai;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((bi > 0 ) && ( *(sptr + bi) != 0x005C )) { bi--; }

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( *(sptr + bi) == 0x005C ) {
		bi++;
		}

	/* Check for and perform PathName transfer */
	/* --------------------------------------- */
	if ( mode & 4 ) {
		for ( ci = 0; ci < bi; ci++ ) {
			*(rptr + ri) = *(sptr + ci); ri++;
			}
		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( bi < ai ) {
		if (( *(sptr + bi) != '.') && ( *(sptr +bi ) != '-' ) && ( *(sptr +bi ) != ':' ) ) {
			if ( mode & 8 ) {
		 		*(rptr + ri) = *(sptr + bi); ri++; 
				}
			bi++;
			}
		else	{
			break;
			}
		}

	/* Check for and Transfer 'Extension' */
	/* ---------------------------------  */
	while ( bi < ai ) {
		if ( *(sptr + bi) == ':' ) {
			break;
			}
		else	{
			if ( mode & 16 ) {
		 		*(rptr + ri) = *(sptr + bi); ri++; 
				}
			bi++;
			}
		}

	/* Check for and Transfer 'Cles d'access' */
	/* -------------------------------------  */
	if ( mode & 32 ) {
		while ( bi < ai ) {
	 		*(rptr + ri) = *(sptr + bi); 
			ri++; bi++;
			}
		}

#endif /* prologue */

#ifdef	unix
#ifndef	vms

	/* -------------------------------------------- */
	/* Unix :    /r/r/filename.ext			*/
	/* -------------------------------------------- */

	/* Check for and Transfer Network Node Name */
	/* ---------------------------------------- */
	if ( mode & 1 ) { }

	bi = ai;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((bi > 0 ) && ( *(sptr + bi) != '/' )) { bi--; }

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( *(sptr + bi) == '/' ) {
		bi++;
		}

	/* Check for and perform PathName transfer */
	/* --------------------------------------- */
	if ( mode & 4 ) {
		for ( ci = 0; ci < bi; ci++ ) {
			*(rptr + ri) = *(sptr + ci); ri++;
			}
		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( bi < ai ) {
		if ( *(sptr + bi) == '.') {
			break; 
			}
		else	{
			if ( mode & 8 ) {
		 		*(rptr + ri) = *(sptr + bi); ri++;
				}
			bi++;
			}
		}

	/* Check for and Transfer Extension */
	/* -------------------------------- */
	if ( mode & 16 ) {
		while ( bi < ai ) {
	 		*(rptr + ri) = *(sptr + bi); 
			ri++; bi++;
			}
		}

#endif /* ! vms */
#endif /* unix */

#ifdef	vms

	/* -------------------------------------------- */
	/* Vms :    DUA0:[*.*.]filename.ext;version	*/
	/*	    *$*:filename.ext;version		*/
	/* -------------------------------------------- */
	bi = ai;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((bi > 0 ) && ( *(sptr + bi) != ':' ) && ( *(sptr + bi) != ']') ) { bi--; }

	switch ( *(sptr + bi) ) {

		case ':' :	/* Logical Name Separator Found */
				/* ---------------------------- */

				if ( mode & 4 ) {
					fnmemcpy( (char *) (rptr + ri) , sptr , bi );
					ri += bi;
					*(rptr + ri) = ':'; ri++;
					}
				bi++;
				break;

		case ']' :	/* Directory Path Separator Found */
				/* ------------------------------ */
				ci = bi; /*Keep End of Path Index */

				/* Scan to Start of PATH */
				/* --------------------- */
				while ((bi > 0 ) && ( *(sptr + bi) != '[' )) {
					bi--; 
					}
				di = 0; /* Zero Start of DEVICE */

				/* Check for and Extract Device */
				/* ---------------------------- */
				if ( mode & 2 ) {
					while ( di < bi ) {
						*(rptr + ri) = *(sptr + di);
						di++; ri++;
						}
					}

				/* Check for and Extract PATH */
				/* -------------------------- */
				while ( bi <= ci ) {
					if ( mode & 4 ) {
						*(rptr + ri) = *(sptr + bi);
						ri++;
						}
					bi++;
					}
				break;

		default  :	/* Simple Filename or Logical Name */
				/* ------------------------------- */
				break;

		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( bi < ai ) {
		if ( *(sptr + bi) == '.') { 
			break;
			}
		else	{
			if ( mode & 8) {
		 		*(rptr + ri) = *(sptr + bi); ri++; 
				}
			bi++;
			}
		}

	/* Check for and Transfer Extension */
	/* -------------------------------- */
	while ( bi < ai ) {
		if ( *(sptr + bi) == ';' ) {
			break;
			}
		if ( mode & 16 ) {
		 	*(rptr + ri) = *(sptr + bi); ri++;
			}
		bi++;
		}

	/* Check for and Transfer Version Number */
	/* ------------------------------------- */
	if ( mode & 64 ) {
		while ( bi < ai ) {
	 		*(rptr + ri) = *(sptr + bi);
			ri++; bi++;
			}
		}

#endif /* vms */

#ifdef	msdos
	/* -------------------------------------------- */
	/* Ms/Dos :    C:\*\*\filename.ext		*/
	/* -------------------------------------------- */

	/* Check for and transfer NetWork Node Name */
	/* ---------------------------------------- */
	if ( mode & 1 ) { }

	/* Check for and Transfer Device Mnemonic */
	/* -------------------------------------- */
	if ( ai >= 2 ) {
		if ( *(sptr + 1) == ':' ) { 
			if ( mode & 2 ) {
				fnmemcpy((char *) (rptr + ri),(char *) sptr , 2 );
				ri += 2;
				}
			sptr += 2; ai-= 2; 
			}
		}
	bi = ai;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((bi > 0 ) && ( *(sptr + bi) != 0x005C )) { bi--; }

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( *(sptr + bi) == 0x005C ) {
		bi++;
		}

	/* Check for and perform PathName transfer */
	/* --------------------------------------- */
	if ( mode & 4 ) {
		for ( ci = 0; ci < bi; ci++ ) {
			*(rptr + ri) = *(sptr + ci); ri++;
			}
		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( bi < ai ) {
		if ( *(sptr + bi) == '.') { 
			break;
			}
		else	{
			if ( mode & 8 ) {
		 		*(rptr + ri) = *(sptr + bi); ri++;
				}
			bi++;
			}
		}

	/* Check for and Transfer Extension */
	/* -------------------------------- */
	if ( mode & 16 ) {
		while ( bi < ai ) {
	 		*(rptr + ri) = *(sptr + bi); 
			ri++; bi++;
			}
		}

#endif /* msdos */
	/* Return the Byte Count Transfered */
	/* -------------------------------- */
	*termptr = termine; *(rptr + ri) = 0; return( ri );

}

