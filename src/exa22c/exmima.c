/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMIMA.C  				*/
/*		Date 	:	16/01/1997				*/
/*		Version :	1.4d / 2.1b				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef _EXMIMA_C
#define	_EXMIMA_C


/* 03/01/97: Pour agf */
#include "pubagf.h"

/*
 *	M I N I M A J I ( c )
 *	---------------------
 *	
 *	Converts lowercase c to uppercase ( including accented characters)
 *
 */

#ifdef	VMS_CHARSET
extern	EXAWORD	VmsCico;
#endif

#include "exlang.h"

EXAWORD	minimaji(c)
EXAWORD	c;
{

/*	Check for standard character without accent	*/
/* 	-------------------------------------------	*/
if ((c >= 'a') && (c <= 'z')) {	return( (c - ('a' - 'A')));	}

else if (( get_national_language == CYRILUK) 
     ||  ( get_national_language == CYRILFR)) {
	if (( c >= 0x00A0 ) && ( c <= 0x00AF ))
		return( (c - 0x0020) );
	else if (( c >= 0x00E0 ) && ( c <= 0x00EF ))
		return( (c - 0x0050) );
	else if ( c == 0x00F1 )
		return( 0x00F0 );
	else	return( c );
	}

else if ( get_national_language == MONGOL ) {
	if (( c >= 0x00A3 ) && ( c <= 0x00B0 ))
		return( (c - (0x00A3 - 0x0080)) );
	else if ((c >= 0x00EA) && ( c <= 0x00FE))
		return( (c - (0x00EA - 0x008E)) );
	else	return( c );
	}

#ifdef	VMS_CHARSET

	/* Check for VMS native or PROLOGUE standard */
	/* ----------------------------------------- */
	if ( VmsCico == 0 )	{

		/* VMS native character set */
		/* ------------------------ */
		switch ( c ) {

			case	0x00E4 : /* a umlaut  */
					 /* --------- */
					 if ( get_national_language == GERMAN) 
						return(0x00C4); 

			case	0x00E2 : /* a chapeau */
					 /* --------- */
			case	0x00E0 : /* a grave   */
					 /* --------- */
			case	0x00E5 : /* a dot     */
					 /* --------- */
			case	0x00E1 : /* a acute   */
					 /* --------- */
			case 	0x00E3 : /* a tilde   */
					 /* --------- */
					 return( 'A' );

			case	0x00E9 : /* e acute   */
					 /* --------- */
					 if (get_national_language == SPANISH)
						return(0x00C9);

			case	0x00E8 : /* e grave   */
					 /* --------- */
			case	0x00EA : /* e chapeau */
					 /* --------- */
			case	0x00EB : /* e umlaut  */
					 /* --------- */
					 return( 'E' );

			case	0x00F6 : /* o umlaut  */
					 /* --------- */
					 if (get_national_language == GERMAN) 
						return(0x00D6); 

			case	0x00F4 : /* o chapeau */
					 /* --------- */
			case	0x00F2 : /* o grave   */
					 /* --------- */
			case	0x00F5 : /* o tilde   */
					 /* --------- */
			case	0x00F3 : /* o accute  */
					 /* --------- */
					 return( 'O' );

			case 	0x00FC : /* u umlaut  */
					 /* --------- */
					 if (get_national_language == GERMAN)
						return(0x00DC);

			case	0x00FB : /* u chapeau */
					 /* --------- */
			case	0x00F9 : /* u grave   */
					 /* --------- */
			case	0x00FA : /* u accute  */
					 /* --------- */
					 return( 'U' );

			case	0x00EF : /* i trema   */
					 /* --------- */
			case	0x00EE : /* i chapeau */
					 /* --------- */
			case	0x00EC : /* i grave   */
					 /* --------- */
			case	0x00ED : /* i accute  */
					 /* --------- */
					 return( 'I' );

			case	0x00E7 : /* c sidilla */ 
					 /* --------- */
					 return( 'C' );

			case	0x00F1 : /* n tilde   */
					 /* --------- */
					 return( 'N' );

			default        : return( c );

			}

		}

#endif

switch ( c )	{

	case	0x0082 : if (get_national_language == SPANISH)
				return(0x0090);
	case	0x0088 :
	case	0x0089 :
	case	0x008A : return('E');

	case	0x0084 : if (get_national_language == GERMAN) 
				return(0x008E); 
	case	0x0083 :
	case	0x0085 :
	case	0x0086 :
	case	0x00A0 :
	case 	0x00CE :
	case	0x00A6 : return('A');

	case	0x0094 : if (get_national_language == GERMAN) 
				return(0x0099); 
	case	0x0093 :
	case	0x0095 :
	case	0x00A7 :
	case	0x00CF :
	case	0x00A2 : return('O');

	case 	0x0081 : if (get_national_language == GERMAN)
				return(0x009A);
	case	0x0096 : 
	case	0x0097 :
	case	0x00A3 : return('U');

	case	0x008B :
	case	0x008C :
	case	0x008D :
	case	0x00A1 : return('I');

	case	0x0087 : return('C');

	case	0x00A4 : if (get_national_language == SPANISH)
				return(0x00A5);
			 else	return('N');

	default	       : return(c);
	}
}

EXAWORD	majimini( c )
EXAWORD	c;
{
#ifdef	VMS_CHARSET

	/* Check for Native VMS character Set */
	/* ---------------------------------- */
	if ( VmsCico == 0 ) {

		/* Check for German langauge Config */
		/* -------------------------------- */
		if (get_national_language == GERMAN) {
			switch ( c ) {
				case 0x00D6 : return(0x00F6); /* O umlaut */
				case 0x00DC : return(0x00FC); /* U umlaut */
				case 0x00C4 : return(0x00E4); /* A umlaut */
				}
			}

		/* Check for Spanish langauge config */
		/* --------------------------------- */
		if ( get_national_language == SPANISH)
			if ( c == 0x00C9 )	/* N tilde */
				return(0x00E9); /* n tilde */

		}
#endif
	if (( get_national_language == CYRILUK) 
	||  ( get_national_language == CYRILFR)) {
		if (( c >= 0x0041 ) && ( c <= 0x005A ))
			return( (c + 0x0020) );
		else if (( c >= 0x0080 ) && ( c <= 0x008F ))
			return( (c + 0x0020) );
		else if (( c >= 0x0090 ) && ( c <= 0x009F ))
			return( (c + 0x0050) );
		else if ( c == 0x00F0 )
			return( 0x00F1 );
		else	return( c );
		}

	else if ( get_national_language == MONGOL ) {
		if (( c >= 0x0080 ) && ( c <= 0x008D ))
			return( (c + (0x00A3 - 0x0080)) );
		else if ((c >= 0x008E) && ( c <= 0x00B0))
			return( (c + (0x00EA - 0x008E)) );
		else	return( c );
		}

	/* Check for German langauge Config */
	/* -------------------------------- */
	if ( get_national_language == GERMAN) {
		switch ( c ) {
			case 0x0099 : return(0x0094); /* O umlaut */
			case 0x009A : return(0x0081); /* U umlaut */
			case 0x008E : return(0x0084); /* A umlaut */
			}
		}

	/* Check for Spanish langauge config */
	/* --------------------------------- */
	if ( get_national_language == SPANISH) {
		switch ( c ) {
			case 0x0090 : return(0x0082);	/* E acute */
			case 0x00A5 : return(0x00A4);	/* N tilde */
			}
		}

	/* Perform System dependant Translation */
	/* ------------------------------------ */
	return( (tolower( c )) );

}

#endif	/* _EXMIMA_C */
	/* --------- */
