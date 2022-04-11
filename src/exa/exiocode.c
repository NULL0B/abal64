/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXIOCODE.C				*/
/*		Date 	:	16/01/1997				*/
/*		Version :	1.4d / 2.1b				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXIOCODE_C
#define	_EXIOCODE_C

/* 03/01/97: Pour agf */
#include "pubagf.h"

/*
 *	I S T E X T ( c )
 *	-----------------
 *
 */

#ifdef	VMS_CHARSET
extern	EXAWORD	VmsCico;
#endif

EXAWORD istext(c)
EXABYTE	c;
{
	if ( ( c == ' ') 
	||   (( c >= 'A') && ( c <= 'Z')) 
	||   (( c >= 'a') && ( c <= 'z')) )
		return(0);
#ifdef	VMS_CHARSET
	if ( VmsCico == 0 ) {

		if (( c >= 0x00C0 ) && ( c <= 0x00CF ))
			return( 0 );
		if (( c >= 0x00D1 ) && ( c <= 0x00D6 ))
			return( 0 );
		if (( c >= 0x00D9 ) && ( c <= 0x00DC ))
			return( 0 );
		if (( c >= 0x00E0 ) && ( c <= 0x00EF ))
			return( 0 );
		if (( c >= 0x00F1 ) && ( c <= 0x00F6 ))
			return( 0 );
		if (( c >= 0x00F9 ) && ( c <= 0x00FF ))
			return( 0 );

		/* FALSE */
		return( 1 );
		}
#endif
	if (( NationalLanguage == CYRILUK) 
	||  ( NationalLanguage == CYRILFR)) {
		if ((( c >= 0x0080 ) && ( c <= 0x00AF ))
		||  (( c >= 0x00E0 ) && ( c <= 0x00F1 )))
			return( 0 );
		else	return( 1 );
		}
	else if ( NationalLanguage == MONGOL ) {
		if ( ((c >= 0x0080) && ( c <= 0x00B0 ))
		||   ((c >= 0x00EA) && ( c <= 0x00FE )) )
			return(	0 );
		else	return( 1 );
		}
	else	{
		if ( (( c >= 0x0080) && ( c <= 0x00a8 )) 
		||   (( c >= 0x00b5) && ( c <= 0x00be )) 
		||   (( c >= 0x00c6) && ( c <= 0x00cf )) 
		||   (( NationalLanguage == GERMAN ) && ( c == 0x00d2)) )
			return( 0 );
		else	return( 1 );
		}
}

/*
 *	I S S I G N ( c )
 *	-----------------
 *
 */

EXAWORD	issign(c)
EXABYTE	c;
{
	
	if  ( ((fbcdp != ' ') && (c == fbcdp)) 	
	||    ((fbcdm != ' ') && (c == fbcdm)) )
		return(0); 
	else	return(1);
}

/*
 *	I S C H I F F ( c )
 *	-------------------
 *
 */

EXAWORD ischiff(c)
EXABYTE	c;
{
	if (( c >= '0') && ( c <= '9' )) 
		return(0);
#ifdef	ABAL14
	if ( ( fmthex != 0 )
	&&   ( (( c >= 'A') && ( c <= 'F' )) 
	   ||  (( c >= 'a') && ( c <= 'f' )) ) )
		return(0); 
#endif
	return(1);
}

/*
 *	I S C O D E ( c )
 *	-----------------
 *
 */

EXAWORD iscode(c)
EXABYTE	c;
{
	if ( (( c >= 0x0021) && ( c <= 0x002f)) 
	||   (( c >= 0x003a) && ( c <= 0x0040)) 
	||   (( c >= 0x005b) && ( c <= 0x0060)) 
	||   (( c >= 0x007b) && ( c <= 0x007e)) )
		return(0);
#ifdef	VMS_CHARSET
	if ( VmsCico == 0 ) {

		if (( c >= 0x0080 ) && ( c <= 0x00BF ))
			return( 0 );
  
		switch ( c ) {
			case 0x00A6 : /* Semi Graphical characters */
			case 0x00BE :
			case 0x00F0 :
			case 0x00A4 :
			case 0x00AD :
			case 0x00DE :
			case 0x00AF :
			case 0x00AE :
			case 0x00B8 :
			case 0x00AC :
			case 0x00D0 : /* End of Semi Graphics */
			case 0x00D7 :
			case 0x00D8 :
			case 0x00F7 :
			case 0x00F8 : return( 0 );
			
			}

		/* FAUX */
		return( 1 );
		}
#endif
	if ( (( c >= 0x00a9) && ( c <= 0x00b4)) 
	||   (( c >= 0x00bf) && ( c <= 0x00c5)) 
	||   ( c >= 0x00d0)  )
		return(0);
	else	return(1);
}

/*
 *	I S V I R G ( c )
 *	-----------------
 *
 */

EXAWORD	isvirg(c)
EXABYTE	c;
{
	if (( c == ',' ) || ( c == '.' )) 
		return(0);
	else 	return(1);
}


/* 
 *	K O D C H K ( c )
 *	-----------------
 *
 *	IOF Low level ASK routine character validty tests
 *	-------------------------------------------------
 */

EXAWORD	kodchk(c)
EXABYTE	c;
{
	if (issign(c)  == 0) { return(0x0040); }
	if (isvirg(c)  == 0) { return(0x0008); }
	if (ischiff(c) == 0) { return(0x0002); }
	if (istext(c)  == 0) { return(0x0001); }
	if (iscode(c)  == 0) { return(0x0004); }	
	return(0);
}

#endif	/* _EXIOCODE_C */
	/* ----------- */
