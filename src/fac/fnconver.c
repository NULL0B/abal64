// ***********************************************************************************************
// * fnconver.c
// * Conversion d'un nom de fichier pour LINUX (ne pas utiliser pour Twin ou Windows)
// *
// * Fichier provenant de l'équipe Moscou. Pour simplifier l'intégration au projet fac,
// * les infos des includes originaux (allocate.h et stdtype.h) sont intégrés 
// * directement dans le code
// ***********************************************************************************************

#if defined(__linux__)

#ifndef	_fn_convertor_c
#define	_fn_convertor_c

// --- Provenance de l'include stdtype.h 
#define BYTE unsigned char
#define WORD unsigned short int
#define LONG unsigned long
#define XPTR *	
#define BPTR BYTE XPTR
#define WPTR WORD XPTR
#define LPTR LONG XPTR
// --- fin

// --- Provenance de l'include allocate.h 
#ifndef	allocate
#define	allocate malloc
#endif
#ifndef	liberate
#define liberate free
#endif
// --- fin

// --- VVVV Debut du code original VVVV ------------------------------------------------------- 
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "fnconver.h"

#define	locate_variable(p)	getenv(p)
#define	IsAlpha(c) ((( (c) >='A' ) && ( (c) <= 'Z' )) || (( (c) >='a' ) && ( (c) <= 'z' ))) 
#define IsNumeric(c) (( (c) >='0' ) && ( (c) <= '9' )) 

static	BYTE	ConversionBuffer[_CONVERSION_LIMIT];
static	BYTE	MnemonicBuffer[_CONVERSION_LIMIT];
static	WORD	mnemoffs=0;

/* Workzone used for the substitution of mnemonic values by env values */
static	int	strchk(char * aptr, char * bptr)
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

unsigned short	fn_convertor( unsigned char* workptr, unsigned char* resultptr, unsigned short mode )
{
	BPTR	zerkptr;
	WORD	worklen;
	WORD	z;
	WORD	i;
	WORD	other=0;
	WORD	iz=0;
	WORD	checkterm=0;
	BPTR	mnemptr=(BPTR) 0;
	BPTR	buildptr=(BPTR) 0;

	zerkptr = ConversionBuffer;
	worklen = strlen( workptr );

	/*	If Automatic File Conversions Required		*/
	/*	--------------------------------------		*/
	for ( z = 0; z < worklen; z++ ) {
		if ( *(workptr + z) == _BACKSLASH )
			*(zerkptr + z) = '/';
		else	{
			switch ( mode & 3 ) {
				case 	_CONVERT_UPPER :
					*(zerkptr + z) = toupper( (*(workptr+z)));
					break;
				case	_CONVERT_LOWER :
					*(zerkptr + z) = tolower( (*(workptr+z)));
					break;
				default	:
					*(zerkptr + z) = *(workptr+z);
				}
			}
		}	

	*(zerkptr + z) = 0; 

	buildptr = workptr = zerkptr;

	/* Check for Mnmeonics Conversion */
	/* ------------------------------ */
	if ( mode & _CONVERT_MNEMONICS ) {

		mnemoffs = z = iz =0;

		while ( *(workptr+iz) != 0 ) {

			checkterm = 0;

			if ((iz > 0 			 )
			&&  (*(workptr+iz-1) != '/'	 )) {
				iz++;
				continue;
				}

			/* ensure string long enough for mnemonic */
			/* -------------------------------------- */
			if ((!( *(workptr+iz+0) ))
			||  (!( *(workptr+iz+1) ))
			||  (!( *(workptr+iz+2) )))
				break;
 
			/* Detect Implicites IS,IP,IF */
			/* -------------------------- */
			if (( *(workptr+iz) == 'i' )
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
					break;
				default		:
					iz++;
					continue;
				}

			/* Detect a substitution value */
			/* --------------------------- */
			/* terminate for getenv */
			*(workptr + iz + checkterm ) = 0;

			/* locate substitution value */
			/* ------------------------- */
			if (!( mnemptr = locate_variable( (workptr+iz) ) )) {

				/* no so put it back , continue */
				/* ---------------------------- */
				*(workptr+iz+checkterm) = (BYTE) z;
				iz++;
				continue;
				}
			else if (!( strchk((workptr+iz),mnemptr ) )) {
				/* no so put it back , continue */
				/* ---------------------------- */
				*(workptr+iz+checkterm) = (BYTE) z;
				iz++;
				continue;
				}
			else if (((other = strlen(mnemptr)) > 0) 
			     &&   ( *(mnemptr + (other-1)) == '/' ))
				*(mnemptr + (other-1)) =0;

			/* Here we must rebuild the workstring */
			/* to contain the left  hand portion   */
			/* the substitution value and the rest */
			/* ----------------------------------- */
			buildptr = &MnemonicBuffer[mnemoffs];

			/* cut and copy left  hand portion */
			/* ------------------------------- */
			other = *(workptr+iz); *(workptr+iz) = 0;
			strcpy(buildptr,workptr);
			*(workptr+iz) = (BYTE) other;

			if (( iz != 0 )
			&&  ( *mnemptr == '/' ))
				mnemptr++;

			/* concatenate the substitution value */
			/* ---------------------------------- */
			strcat( buildptr, mnemptr );

			if ( z == '.' ) {
				if ( *(workptr+iz+checkterm+1) == '/' )  {
					/* convert ./ to / */
					*(workptr+iz+checkterm) = (BYTE) z;
					strcat(buildptr,(workptr+iz+checkterm+1));
					}
				else if ((!( *(workptr+iz+checkterm+1) )) 
				     ||  (   *(workptr+iz+checkterm+1)==' ')) {
					/* terminal DOT is simply removed */
					*(workptr+iz+checkterm) = (BYTE) z;
					}
				else 	{
					/* convert . to / */
					*(workptr+iz+checkterm) = '/';
					strcat(buildptr,(workptr+iz+checkterm));
					*(workptr+iz+checkterm) = (BYTE) z;
					}
				}
			else 	{
				*(workptr+iz+checkterm) = (BYTE) z;
				strcat(buildptr,(workptr+iz+checkterm));
				}

			/* Here we do not increment to allow */
			/* mnemonics to redefine mnemonics   */
			/* --------------------------------- */
			*(workptr+iz+checkterm) = (BYTE) z;
			workptr = buildptr;
			worklen = strlen(buildptr);
			mnemoffs += (worklen+2);
			} 
		}

	/* Transfer to the Result Buffer */
	/* ----------------------------- */
	for (i=0; *(buildptr+i) != 0; i++ ) 
		*(resultptr+i) = *(buildptr+i);

	*(resultptr+i) = 0;

	return( i );
}

#endif /* _fn_converter_c */

#endif /* BDA_UNIX */
