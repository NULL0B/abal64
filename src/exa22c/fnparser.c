/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPARSER.C				*/
/*		Version :	2.1d					*/
/*		Date 	:	10/04/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef _EXPARSER_C
#define _EXPARSER_C

#include "stdtypes.h"

BPTR	fnmemcpy(rptr , sptr , len )
BPTR	rptr;
BPTR	sptr;
EXAWORD	len;
{
	EXAWORD	x;
	for ( x = 0; x < len; x++ ) *(rptr + x ) = *(sptr + x );
	return( rptr );
}

EXABYTE	Majescule( c )
EXABYTE	c;
{
	if (( c >= 'a' ) && ( c <= 'z' )) {
		c &= (EXABYTE) 0x00DF;
		}
	return( c );
}

void	UpperCase( rptr , ri )
BPTR	rptr;
EXAWORD	ri;
{
	while ( ri > 0 ) {
		*rptr = (EXABYTE) Majescule( *rptr );
		rptr++; ri--;
		}
	return;
}

EXAWORD	fn_fields(sptr , rptr , mode )
BPTR	sptr;	/* Source file name string				*/
BPTR	rptr;	/* Pointer to Result Buffer 				*/
		/* ---------------------------------------------------- */
EXAWORD	mode;	/* Extraction type Bit definitions			*/
		/* ---------------------------------------------------- */
{
	EXAWORD	ri=0;

/*	Network Node Name Terminator 	*/
/*	----------------------------	*/
	if ( mode & 1 ) {
#ifdef	VMS
		*(rptr + (ri++)) = ':';
		*(rptr + (ri++)) = ':';
#endif
#ifdef	DOS
		*(rptr + (ri++)) = '\\';
		*(rptr + (ri++)) = '\\';
#endif
		*(rptr + (ri++)) = ' ';
		}

/*	Device Name Terminator		*/
/*	----------------------		*/
	if ( mode & 2 ) {
#ifdef	PROLOGUE
		*(rptr + (ri++)) = '.';
#else
#ifndef	UNIX
		*(rptr + (ri++)) = ':';
#endif
#endif
		*(rptr + (ri++)) = ' ';
		}

/*	Directory Punctuation	*/
/*	---------------------	*/
	if ( mode & 4 ) {
#ifdef	VMS
		*(rptr + (ri++)) = '[';
		*(rptr + (ri++)) = ' ';
		*(rptr + (ri++)) = '.';
		*(rptr + (ri++)) = ' ';
		*(rptr + (ri++)) = ']';
#else
#ifdef	UNIX
		*(rptr + (ri++)) = '/';
#else
		*(rptr + (ri++)) = '\\';
#endif
#endif
		*(rptr + (ri++)) = ' ';
		}

/*	Filename Punctuation ! */
/*	---------------------- */	
	if ( mode & 8 )
		*(rptr + (ri++)) = ' ';

/*	Extension Prefix	*/
/*	----------------	*/
	if ( mode & 16 ) {
#ifdef	PROLOGUE
		*(rptr + (ri++)) = '-';
#else
		*(rptr + (ri++)) = '.';
#endif
		*(rptr + (ri++)) = ' ';
		}

/*	Password Prefix		*/
/*	---------------		*/
	if ( mode & 32) {
#ifdef	PROLOGUE
		*(rptr + (ri++)) = ':';
#endif
		*(rptr + (ri++)) = ' ';
		}

/*	Version Number Prefix	*/
/*	---------------------	*/
	if ( mode & 64) {
#ifdef	VMS
		*(rptr + (ri++)) = ';';
#endif
		*(rptr + (ri++)) = ' ';
		}

	*(rptr + ri) = 0;
	return( ri );
}

EXAWORD	fn_parser(sptr , rptr , mode )

		/* ---------------------------------------------------- */
BPTR	sptr;	/* Source file name string				*/
BPTR	rptr;	/* Pointer to Result Buffer 				*/
		/* ---------------------------------------------------- */
EXAWORD	mode;	/* Extraction type Bit definitions			*/
		/* ---------------------------------------------------- */
		/*		   1	NetWork Node Name		*/
		/*		   2	Device Mnemonic			*/
		/*		   4	Path name only			*/
		/*		   8  	FileName portion		*/
		/*		   16	Extension and separator		*/
		/*		   32	Amenesik / Sologic Password		*/
		/*		   64   VMS Version Number 		*/
		/*		  128	Convert to Upper Case		*/
		/*		  256   Do not Terminate 1st byte	*/
		/*		        (used by execute_with_path)	*/
		/* 		  512   Return Required field separator */
		/* ---------------------------------------------------- */
{
	EXAWORD	ai;
	EXAWORD	bi;
        EXAWORD     ci;
        EXAWORD     di;
	EXAWORD	ri;
	EXAWORD	termine;
	BPTR	termptr;
#ifdef	PROLOGUE
	EXAWORD	implicite;
	implicite = 0;
#endif


	if (( mode & 0x0100 ) == 0 ) {
		/* Ensure NUL for Bruno */
		/* -------------------- */
		*rptr = (EXABYTE) 0;
		}

	/* Check for Field Separator Request */
	/* --------------------------------- */
	if ( mode & 0x0200 ) 
		return( fn_fields(sptr, rptr, mode ) );

	/* If No Current Object */
	/* -------------------- */
	if (sptr == (BPTR) 0 ) 
		return(0);

	/* Calculate and Test String Length */
	/* -------------------------------- */
	ai = 0;
	while 	  (( *(sptr + ai)  ) 
		&& (*(sptr + ai) != 0x000D) 
#ifndef WIN32
		&& (*(sptr + ai) != ' ') 
#endif
		)
			ai++;

#ifdef WIN32
	/* Scan backwards to eliminate trailing spaces */
	while (ai != 0) {
		if (*(sptr+ai-1) == ' ')	ai--;
		else				break;
	}
#endif

	if ( ai == 0 ) 
		return(0);

	/* Keep terminator and ensure ZERO termination */
	/* ------------------------------------------- */
	termptr = (sptr + ai); termine = *termptr; *termptr = 0;

	/* Zero out the result index */
	/* ------------------------- */
	ri = 0;

#ifdef	PROLOGUE

	/* ---------------------------------------------------- */
	/* PROLOGUE <  4.2 :    MD0.\*\*\filename.-ext:RRWW		*/
	/* PROLOGUE >= 4.2 : \\*\MD0.\*\filename.-ext:RRWW		*/
	/* ---------------------------------------------------- */

#ifdef	PRL42
	/* Check for and Transfer Network Node Name */
	/* ---------------------------------------- */
	if (( *sptr == '\\' ) && ( *(sptr = 1) == '\\' )) {

		if ( mode & 1 ) { 
			*(rptr + ri) = *(sptr++); ri++;
			*(rptr + ri) = *(sptr++); ri++; 
			}
		else	{
			sptr += 2;
			}

		ai -= 2;

		while ( *sptr != '\\' ) {
			if ( mode & 1 ) {
				*(rptr + ri) = *sptr; ri++;
				}
			sptr++; ai--;
			}
		if ( mode & 1 ) {
			*(rptr + ri) = *sptr; ri++;
			}
		sptr++; ai--;
		}
#endif

	/* Check for Device Mnmomic Present */
	/* -------------------------------- */
	if ( ai >= 3 ) {

		if ( *(sptr + 2) == '.' ) {
			if (( *sptr == 'i' ) || ( *sptr == 'I' )) {
				switch ( *(sptr + 1) ) {

					case 's' :
					case 'S' :
					case 'f' :
					case 'F' :
					case 'P' :
					case 'p' :
					/* Scan past Device Mnemonic */
					/* ------------------------- */
					if ( mode & 2 ) {
						fnmemcpy((BPTR) (rptr + ri) ,(BPTR) sptr , 3 );
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
					fnmemcpy((BPTR) (rptr + ri) ,(BPTR) sptr , 4 );
					ri += 4;
					}
				sptr += 4; ai -= 4;
				}
			}
		}
	bi = ai;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((bi > 0 ) && ( *(sptr + bi) != 0x005C )) 
		bi--;

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( *(sptr + bi) == 0x005C )
		bi++;

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
		 		*(rptr + ri) = *(sptr + bi); 
				ri++; 
				}
			bi++;
			}
		else	break;
		}

	/* Check for and Transfer 'Extension' */
	/* ---------------------------------  */
	while ( bi < ai ) {
		if ( *(sptr + bi) == ':' )
			break;
		else	{
			if ( mode & 16 ) {
		 		*(rptr + ri) = *(sptr + bi); 
				ri++; 
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

#endif

#ifdef	UNIX
#ifndef	VMS

	/* -------------------------------------------- */
	/* UNIX :    /r/r/filename.ext			*/
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

#endif
#endif

#ifdef	VMS

	/* -------------------------------------------- */
	/* VMS :    DUA0:[*.*.]filename.ext;version	*/
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
					fnmemcpy( (BPTR) (rptr + ri) , sptr , bi );
					ri += bi;
					*(rptr + ri) = ':'; ri++;
					}
				bi++;
				break;

		case '>' :
		case ']' :	/* Directory Path Separator Found */
				/* ------------------------------ */
				ci = bi; /*Keep End of Path Index */

				/* Scan to Start of PATH */
				/* --------------------- */
				while ((bi > 0 ) && ( *(sptr + bi) != '[' ) && ( *(sptr + bi) != '<') ) {
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

#endif

#ifdef	DOS
	/* -------------------------------------------- */
	/* DOS :    C:\*\*\filename.ext			*/
	/* -------------------------------------------- */

	/* Check for and transfer NetWork Node Name */
	/* ---------------------------------------- */
	if ( mode & 1 ) { }

	/* Check for and Transfer Device Mnemonic */
	/* -------------------------------------- */
	if ( ai >= 2 ) {
		if ( *(sptr + 1) == ':' ) { 
			if ( mode & 2 ) {
				fnmemcpy((BPTR) (rptr + ri),(BPTR) sptr , 2 );
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

#endif
	/* Return the Byte Count Transfered */
	/* -------------------------------- */
	*termptr = termine; *(rptr + ri) = 0; 

	if ( mode & 128 ) {

		/* Perform Upercase conversion */
		/* --------------------------- */
		UpperCase( rptr , ri );
		}

	return( ri );

}

#endif	/* _EXPARSER_C */
	/* ----------- */

