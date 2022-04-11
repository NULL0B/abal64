
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	AOMATH.C				*/
/*		Version :	2.1b					*/
/*		Date 	:	11/05/1994				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_AOMATH_C
#define	_AOMATH_C

#include "aomain.h"
#include "aobib.h"
#include "aomath.h"
#include "abalcico.h"

/*
 *--------------------------------------------------------------------------
 *
 *	B.C.D. Functions
 *	----------------
 *
 *--------------------------------------------------------------------------
 */

/*
 *	B C D E V A L ( bcd , len )
 *	---------------------------
 *
 *	Performs BCD string analysis and returns number of digits
 *	Entier   digits  Contained in the  High octet 
 *	Fraction digits  Contained in the Low octet
 *	Returns MOINS_UN if head error !
 */

EXAWORD	bcdeval(bcd,len)
BPTR	bcd;			/* Pointer to BCD String	*/
EXAWORD	len;			/* Maximum length of string	*/
{
	register EXAWORD  x,flg; /* Quick work registers		*/
	EXAWORD	head,tail;	/* Control and counters		*/
	EXAWORD	digits;		/* Real Valid decimales		*/

	head = 0; tail = 0; flg = 0; digits = 0;

	switch ( ( (EXAWORD) *bcd & 0x00F0 ) ) {
		default		: err_val = ABAL_BCDFORM; return(MOINS_UN);
		case 0x00C0	:
		case 0x00B0	: break;
		}

	while ( len > 0 ) {
		len--;
		switch ( ((x = (EXAWORD) *(bcd++)) & 0x00F0) ) {
			case 0x00A0	: goto EVALP2;
			case 0x00F0	: goto EVALEXIT;
			case 0x00C0	:
			case 0x00B0	: break;
			case 0x0000	: if ( flg == 0 ) { break; }
			default		: flg = 1; head++;
			}
		switch ( x & 0x000F ) {
			case 0x000A	: goto EVALP1;
			case 0x000C	:
			case 0x000B	: 
			case 0x000F	: goto EVALEXIT;
			case 0x0000	: if ( flg == 0 ) { continue; }
			default		: flg = 1; head++;
			}
		}
EVALP1:
	while ( len > 0 ) {
		len--;
		switch ( ((x = (EXAWORD) *(bcd++)) & 0x00F0) ) {
			case 0x00F0	: 
			case 0x00C0	:
			case 0x00B0	: 
			case 0x00A0	: goto EVALEXIT;
			case 0x0000	: tail++; break;
			default		: digits = ( ++tail ); 
			}
EVALP2:
		switch ( x & 0x000F ) {
			case 0x000F	: 
			case 0x000C	:
			case 0x000B	: 
			case 0x000A	: goto EVALEXIT;
			case 0x0000	: tail++; break;
			default		: digits = ( ++tail ); 
			}
		}
EVALEXIT:
	return(  ((head  << 8 ) | digits ) );
}

/* 
 *	B C D E T D ( bcd , n1 , n2 , n3 , n4 , e , n5 )
 *	------------------------------------------------
 *
 *	Converts Compressed BCD to Expanded BCD
 *	with the inclusion of the required
 *	leading and trailing zeros.
 */

void bcdetd(bcd,n1,n2,n3,n4,e,bcdslen)
BPTR	bcd;			/* Points to BCD String */
EXAWORD	n1;			/* Leading zeros	*/
EXAWORD	n2;			/* Trailing zeros	*/
EXAWORD	n3;			/* Matrix Element	*/
EXAWORD	n4;			/* Starting position	*/
BYTE	e;			/* End of string byte	*/
EXAWORD	bcdslen;			/* Maximum length of BCD */

{
	BYTE *rp;
/*	----------	*/
/*	BYTE *rrp;	*/
/*	----------	*/
	register EXAWORD  x,flg;

flg = 0;
if ( e != 0 ) { e = (BYTE) 0x00FF; }
rp  = (BYTE *) (&mathwork[n3][n4]); /* Calculate start position */
/* ----------------------------------  */
/* rrp = (BYTE *) (&mathwork[2][n4]);  */
/* ----------------------------------  */

/*	Place leading Zeros	*/
/*	-------------------	*/

while ( n1 >  0) { *(rp++) = 0; n1--; }

/*	Expand BCD Compressed digits	*/
/*	----------------------------	*/

do {
	x = (EXAWORD) *(bcd++); bcdslen--;
	switch ( x & 0x00F0 ) {
		case 0x00F0 : bcdslen = 0; continue;
		case 0x00A0 : flg = 1;
		case 0x00E0    :
		case 0x00D0    :
		case 0x00C0    : 
		case 0x00B0    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (BYTE) ( x >> 4 ); n4++;
				/* ------------------ */
				/*  *(rrp++) = 0; */
				/* ------------------- */
		}
	switch ( x & 0x000F ) {
		case 0x000F : bcdslen = 0; continue;
		case 0x000A : flg = 1;
		case 0x000E    :
		case 0x000D    :
		case 0x000C    : 
		case 0x000B    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (BYTE) ( x & 0x000F); n4++;
				/* ------------------ */
				/* *(rrp++) = 0; */
				/* ------------------ */
		}

	} /* WEND */
while (( bcdslen > 0) && (n4 < BCDDIG ));

/*	Place trailing Zeros	*/
/*	--------------------	*/
							  /* ------------------ */
while ( (n2 != 0) && ( n4 < BCDDIG )) { *(rp++) = 0; /* *(rrp++) = 0; */ n2--; n4++; }
							  /* ------------------ */
/* 	Terminate String 	*/
/*	----------------	*/

*rp = e; return;
}


/*
 *	B C D C P R ( etd , rp , rl , n , rsig )
 *	----------------------------------------
 *
 *	Converts Expanded BCD to Compressed BCD after calculations
 *	and stores the result directly to the result operand
 */

EXAWORD	bcdcpr(etd,rp,rl,n,rsig)
BPTR	etd;			/* Points to expanded BCD Form	*/
BPTR	rp;			/* Result storage zone		*/
EXAWORD rl;			/* Result length		*/
EXAWORD	n;			/* Power factor for decimal point */
EXAWORD	rsig;			/* Sign High nibble 		*/
{
        register EXAWORD x,y;
		 EXAWORD hf,ctrl;
		 BPTR	wptr;		 

	n++; 	/* Adjust Power position from ZERO */

	while ( (BINAIRE) n < 0 ) { n++; etd--; }

	/*	Ignore Header Zeros	*/
	/*	-------------------	*/
	
	while (( *etd == 0 ) && ( (BINAIRE) n > 0 )) {	etd++; n--; }

	/* Check for Result Overflow */
	/* ------------------------- */

	if ( n > (rl * 2) ) {
		err_val = ABAL_NUM2BIG;
		return(SOFTERROR);
		}

	/*	Establish entry conditions	*/
	/*	--------------------------	*/
	
	hf = 0; wptr = rp;

	if ( n == 0 ) 	{ /* Power count expired so set Header */
		*(rp++) = (BYTE) (rsig | 0x000A);
		etd--; rl--; y = 0; ctrl = 0;
		}
	else 		{ y = rsig; ctrl = 1; }
	
	/*	Collect the rest of the digits		*/
	/*	------------------------------		*/

while ( rl > 0 ) {
	n--;	/* Decrement Power Count */

	switch ( (x = (EXAWORD) *(etd++) ) ) {
		case 0x000F :
		case 0x000E :
		case 0x000D :
		case 0x000C :
		case 0x000B :
		case 0x000A : goto CPREXIT;
		case 0x0000 : break;
		default	    : hf = 1;
		}

	if ( ctrl == 0 ) { /* Put First nibble to One Side */
			   /* ---------------------------- */

		if ( n == 0 ) { /* Power expired so Place DP */
				/* ------------------------- */
			*(rp++) = (BYTE) ( 0x00A0 | x ); rl--; 
			continue; 
			}
		else 	{
		 	y = (x << 4); ctrl = 1; 
			}

		}
	else	{	/* Establish and store 2nd Nibble */
			/* ------------------------------ */

		if ( n == 0 ) {	/* Power Expired so place DP */
				/* ------------------------- */
			*(rp++) = (BYTE) ( y | 0x000A); rl--; 
			y = ( x << 4); continue; 
			}

		else	{ /* Power Still Active so Store and Continue */
			  /* ---------------------------------------- */ 
			*(rp++) = (BYTE) ( y | x ); rl--;
			ctrl = 0; continue;

			}	/* ENDIF */

		}		/* ENDIF */

	} 			/* WEND  */

	/*	Don't lose the possible last digit ! 	*/
	/*	------------------------------------	*/
CPREXIT:
	if (( ctrl == 1 ) && ( rl > 0 )) { 
		*(rp++) = (BYTE) ( y | 0x000F); rl--;
		}

	/*	Fill to end of BCD string with FF	*/
	/*	---------------------------------	*/

	while ( rl > 0 ) { *(rp++) = (BYTE) MOINS_UN; rl--; }

	/*	Correct for zero if neccessary		*/
	/*	------------------------------		*/

	if ( hf == 0 ) { *wptr = (BYTE) 0x00CF; }
 	return(1);
}


/*
 *	B C D M U L ( go , fin1 , fin2 )
 *	--------------------------------
 *
 *	Multiplication of 2 Extended BCD Numbers
 *
 */

EXAWORD bcdmul(go,fin1,fin2)
EXAWORD	go;
EXAWORD	fin1;
EXAWORD	fin2;
{

register	BYTE  	*rdigit,*ydigit;
		BYTE  	*xdigit;
		BYTE  	*ygo;
		BYTE  	*end1,*end2;
#ifdef DUMBCC
		EXAWORD	genix;
#endif

end1 = &mathwork[1][fin1]; 
end2 = &mathwork[0][fin2];
ygo = (BYTE *) (&mathwork[0][0] + go);
for ( xdigit = (&mathwork[1][0] + go) ; xdigit >= end1; xdigit-- ) {
	if ( ((EXAWORD) *xdigit) != 0x0000 ) {
		rdigit = (BYTE *) (xdigit + (BCDDIG*2));
		for ( ydigit = ygo ; ydigit >= end2; ydigit-- ) {
#ifdef DUMBCC
			genix   = (EXAWORD) *rdigit;
			genix  += ( (EXAWORD) *ydigit * (EXAWORD) *xdigit );
			*rdigit = (BYTE) genix;
			genix   = (EXAWORD) *(rdigit - 1);
			genix  += ( (EXAWORD) *rdigit / 10 );
			*(rdigit - 1) = (BYTE) genix;			 
			genix = *rdigit;
			genix %= 10;
			*rdigit = (BYTE) genix;
#else
			*rdigit += (BYTE) ( (*ydigit)  *  (*xdigit) );
			*(rdigit - 1) += (BYTE) ( (*rdigit) / 10 );
			*rdigit %= 10;
#endif
			rdigit--;
			}	/* Next YDIGIT	*/
		}		/* Endif !zero	*/
	}			/* Next XDIGIT	*/
return( (EXAWORD) (rdigit - &mathwork[3][0]) );
}

/*
 *	B C D A D D ( deb , fin )
 *	-------------------------
 *
 *	Addition of 2 Extended BCD Numbers
 *
 */

EXAWORD bcdadd(deb,fin)
EXAWORD	deb;
EXAWORD fin;
{
	register BYTE	 *wp;
	register EXAWORD  x;

wp = (BYTE *) &mathwork[0][deb]; x = 0;

do {
	*(wp + (2 * BCDDIG)) =  ((x = (*wp + *(wp + BCDDIG) + (x / 10) )) % 10);
	wp--;
	}
while ( --deb >= fin );	
if ( x > 9 ) { *(wp + (2 * BCDDIG)) = (BYTE) (x / 10); }
return(--fin);
}


/*  
 *	D I V S U B ( a , b , l )
 *	-------------------------
 *
 *	This routine performs subtraction of the divisor from the
 *	dividend for the BCD Division routine.
 *	The result is stored in the 4th work zone and the carry 
 *	status is returned. If the carry is set then the subtraction
 *	has failed so we must lose the result and keep the previous
 *	dividend which will then take into account its next digit to
 *	the right, and the divisor will be shifted to the right.
 *	If the carry is cleared (0) then the subtraction was good and
 *	we must increment the result digit count, and transfer the
 * 	result of subtraction to the dividend zone for further subtraction.
 */

EXAWORD divsub(a,b,l)
BPTR	 a;				/* Pointer to Start of Divisor  */
BPTR	 b;				/* Pointer to start of dividend */
EXAWORD	l;				/* Number of digits to subtract */
{
	register BINAIRE x;		/* Work registers		*/
	register EXAWORD cari;		/* Carry value			*/
		 BPTR  rp;		/* Result pointer (Register)	*/

rp = (BPTR) (&mathwork[3][(l - 1)]);  /* Start adresse of result	*/
a += (l - 1 ); b += (l - 1 ); cari = 0;	/* Calculate start of subtract 	*/
        				/* for dividend and divisor	*/
          				/* Ensure Carry is clear	*/
while ( l > 0 ) {			/* While not end of count	*/

 if ( (x = (BINAIRE) (((EXAWORD) *(b--)) - (((EXAWORD) *(a--)) + cari))) < 0) { 
	x += 10; cari = 1;
	}
 else	{ cari = 0; }
 *(rp--) = x; l--;			/* Calculate subtract result	*/
  }
return(cari);				/* Return carry status		*/
}



/*  
 *	B C D D I V ( debut , fin , mindigits )
 *	---------------------------------------
 *
 *	Division between 2 extended BCD Numbers.
 *	This Algorithm uses re-iterative subtraction.
 *
 */

EXAWORD bcddiv(debut,fin,mindigits)
EXAWORD	debut;
EXAWORD	fin;
EXAWORD mindigits;
{
	register BINAIRE digits,control;
	BPTR   dividend;
	BPTR	 divisor;
	BPTR	 hp;
	BINAIRE	temp,resultat;	
	EXAWORD	shft;

/*	Initialisation of the 3 pointers and 2 control counters		
 *	-------------------------------------------------------
 */

/* Transfer divisor to new divisor zone */
/* ------------------------------------ */
(void) memcpy((BPTR) &mathwork[2][0],(BPTR) &mathwork[1][0] , BCDDIG);

dividend = (BPTR) &mathwork[0][debut]; /* Establish Dividend start 	*/
resultat = debut;			 /* Establish Result start   	*/
divisor	 = (BPTR) &mathwork[2][debut]; /* Establish Divisor  start 	*/

/*	Establish position of the first non zero digit of Divisor
 *	---------------------------------------------------------
 */

control = debut; shft = 0;

while ( *divisor == 0) { divisor++; control++; } 

/*	Calculate length of divisor
 *	---------------------------
 */
temp = control; hp = divisor; digits = control;
while ( control <= fin ) {
	if ( *hp != 0) { temp = control; }
	control++; hp++;
	}

digits = temp - digits + 1;
if (digits < mindigits) { digits = mindigits; }

while ( divsub(divisor,dividend,digits) == 1 ) {  digits++; divisor--;
						  *divisor = 0; debut--; 
						  shft++; } 

resultat += ( digits - 1 );
control = (BCDDIG*2) - resultat -1 ;		/* Establish digit loop count 	*/

if (  (BINAIRE) control <= 0 ) { return(debut); }
/*	Outer Loop on number of digits possible (BCDBYT)
 *	--------------------------------------------
 */

do {

    /* 	Inner loop on succesful subtraction result
     *  ------------------------------------------
     */

    while ( divsub(divisor,dividend,digits) == 0 ) { /* While no Borrow   */

      mathwork[4][resultat] += 1;		/* Increment Result digit */
      memcpy(dividend,(BPTR) &mathwork[3][0],digits);  /* Replace with new digits */
      }

    /*	Failed to subtract without borrow
     *	---------------------------------
     */


    /* Advance and Zero RESULT Byte pointer */
    /* ------------------------------------ */
    resultat++; mathwork[4][resultat] = 0;

    /* Check for more Dividend digits */
    /* ------------------------------ */
    if ( *dividend == 0) 	{ dividend++; 		}
    else 			{ divisor--; digits++;  }

    /* Decrement Control Counter */
    /* ------------------------- */
    control--; 	
}
while ( control > 0 ); 			/* While still more to do */
return( shft );				/* Return last byte point */
}



/* 
 *	B C D M O D ( debut , fin )
 *	---------------------------
 *
 *	Reste apres division de 2 nombre BCD (etd)
 *
 */

void	bcdmod(debut,fin)
EXAWORD	debut;
EXAWORD	fin;
{
	EXAWORD	digits;
	BPTR	dividend;
	BPTR	divisor;
	EXAWORD	powplus,x;

dividend = (BPTR) &mathwork[0][debut];
divisor	 = (BPTR) &mathwork[1][debut];
digits	 = (fin - debut + 1);
x = digits; powplus = 1;
while ( x > 0 ) {
	if ( *divisor != (BYTE) 0 ) { break; }
	else { powplus++; divisor++; x--; }
	}
if ( x > 0 ) {
	while ( powplus > 0 ) {
		while ( divsub(divisor,dividend,digits) == 0 ) {
			(void) memcpy(dividend,(BPTR) &mathwork[3][0],digits);
			}
		powplus--; divisor--;
		}
	}
/* (void) memcpy((BPTR) &mathwork[2][debut],dividend,digits); */
return;		/* (debut); */
}

/* 
 *		B C D C A L C ( a )
 *		-------------------
 *		Called from EXMOTOR-C
 *
 *	This Routine is the Entry point for All B.C.D. Arithmetic.
 *	The routine accepts 4 arguaments.
 *	Arg 1 is the code of the operation to be performed
 *		0 = Addition
 *		1 = Soustraction
 *		2 = Multiplication
 *		3 = Division
 *		4 = Modulus
 *	Arguaments have already been evaluated and are contained in
 *	workptr1,workptr2, & workptr3.
 */

#define	ADDITION	0
#define	SUBTRACTION	1
#define	MULTIPLY	2
#define	DIVISION	3
#define	MODULUS		4

EXAWORD bcdcalc(a,workptr1,worklen1,workptr2,worklen2,workptr3,worklen3)

EXAWORD	a;			/* Operation Code 	*/
BPTR	workptr1;
EXAWORD	worklen1;
BPTR	workptr2;
EXAWORD	worklen2;
BPTR	workptr3;
EXAWORD	worklen3;

{
	
	EXAWORD	real1,frac1,real2,frac2,go,stp,v;
	EXAWORD	sigb,sigc,pow,powd,powv,powm,rsig;
	EXAWORD	digits;
	register EXAWORD x,y;
	BYTE	e,em;
	BPTR	bcd;
	EXAWORD	len;
	BYTE 	*rp;
	EXAWORD flg,n2,n4;

	(void) memset((BPTR) &mathwork[0][0],0x0000,(48 * 6));

	switch	( a ) {
		case DIVISION 	: e = 0; em = 0; break;
		case MODULUS	: e = 0x000F; em = 0; break;
		case MULTIPLY	: e = 0; em = 0; break;
		default		: e = 0x000F; em = 0x000F;	
		}

	for ( x = BCDBYT ; x < BCDDIG ; x++) 	{ mathwork[2][x] = e ; } 


bcd = workptr1; len = worklen1; real1 = 0; frac1 = 0; y = 0; digits = 0;

while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & 0x00F0) ) {
		case 0x00A0	: goto EVALP2;
		case 0x00F0	: goto EVALEXIT;
		case 0x00C0	:
		case 0x00B0	: break;
		case 0x0000	: if ( y == 0 ) { break; }
		default		: y = 1; real1++;
		}
	switch ( x & 0x000F ) {
		case 0x000A	: goto EVALP1;
		case 0x000C	:
		case 0x000B	: 
		case 0x000F	: goto EVALEXIT;
		case 0x0000	: if ( y == 0 ) { continue; }
		default		: y = 1; real1++;
		}
	}
EVALP1:
while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & 0x00F0) ) {
		case 0x00F0	: 
		case 0x00C0	:
		case 0x00B0	: 
		case 0x00A0	: goto EVALEXIT;
		case 0x0000	: digits++; break;
		default		: frac1 = ( ++digits ); 
		}
EVALP2:
	switch ( x & 0x000F ) {
		case 0x000F	: 
		case 0x000C	:
		case 0x000B	: 
		case 0x000A	: goto EVALEXIT;
		case 0x0000	: digits++; break;
		default		: frac1 = ( ++digits ); 
		}
	}
EVALEXIT:
if ((( real1 | frac1 ) == 0 ) && ( a > SUBTRACTION) ) {
	return(bcdcpr((BPTR) &mathwork[2][0],workptr3,worklen3,1,0x00C0)); 
	}
sigb = (((EXAWORD) *workptr1 ) & 0x00F0); pow = real1;

bcd = workptr2; len = worklen2; frac2 = 0; real2 = 0; y = 0; digits = 0;

while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & 0x00F0) ) {
		case 0x00A0	: goto EVALP22;
		case 0x00F0	: goto EVALEXIT2;
		case 0x00C0	:
		case 0x00B0	: break;
		case 0x0000	: if ( y == 0 ) { break; }
		default		: y = 1; real2++;
		}
	switch ( x & 0x000F ) {
		case 0x000A	: goto EVALP12;
		case 0x000C	:
		case 0x000B	: 
		case 0x000F	: goto EVALEXIT2;
		case 0x0000	: if ( y == 0 ) { continue; }
		default		: y = 1; real2++;
		}
	}
EVALP12:
while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & 0x00F0) ) {
		case 0x00F0	: 
		case 0x00C0	:
		case 0x00B0	: 
		case 0x00A0	: goto EVALEXIT2;
		case 0x0000	: digits++; break;
		default		: frac2 = ( ++digits ); 
		}
EVALP22:
	switch ( x & 0x000F ) {
		case 0x000F	: 
		case 0x000C	:
		case 0x000B	: 
		case 0x000A	: goto EVALEXIT2;
		case 0x0000	: digits++; break;
		default		: frac2 = ( ++digits ); 
		}
	}
EVALEXIT2:
if (( frac2 | real2 ) == 0 ) {
	switch ( a ) {
		case ADDITION    :
		case SUBTRACTION : break;
		case MULTIPLY    : 
			return(bcdcpr((BPTR) &mathwork[2][0],workptr3,worklen3,1,0x00C0)); 
		default		 : 
			err_val = ABAL_NDXZERO;
			return(SOFTERROR); 
		}
	}

sigc = ( (EXAWORD) *workptr2 ) & 0x00F0; 
powv = real2; powd = frac2; pow += real2; powm = frac1;

if (real1 >= real2) 	{ x = real1 - real2 ; y = 0; go = BCDBYT - real1; }
else 			{ y = real2 - real1;  x = 0; go = BCDBYT - real2; }

if (frac1 >= frac2) 	{ frac2 = frac1 - frac2; stp = (BCDBYT - 1) + frac1; frac1 = 0; }
else 			{ frac1 = frac2 - frac1; stp = (BCDBYT - 1) + frac2; frac2 = 0; }

n2 = frac1; flg = 0;

rp  = (BYTE *) (&mathwork[0][(n4 = go)]); /* Calculate start position */

/*	Place leading Zeros	*/
/*	-------------------	*/

while ( y  >  0) { *(rp++) = 0; y--; }

/*	Expand BCD Compressed digits	*/
/*	----------------------------	*/

do {
	y = (EXAWORD) *(workptr1++); worklen1--;
	switch ( y & 0x00F0 ) {
		case 0x00F0 : worklen1 = 0; continue;
		case 0x00A0 : flg = 1;
		case 0x00E0    :
		case 0x00D0    :
		case 0x00C0    : 
		case 0x00B0    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (BYTE) ( y >> 4 ); n4++;
		}
	switch ( y & 0x000F ) {
		case 0x000F : worklen1 = 0; continue;
		case 0x000A : flg = 1;
		case 0x000E    :
		case 0x000D    :
		case 0x000C    : 
		case 0x000B    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (BYTE) ( y & 0x000F); n4++;
		}

	} /* WEND */

while (( worklen1 > 0) && (n4 < BCDDIG ));

/*	Place trailing Zeros	*/
/*	--------------------	*/

while ( (n2 != 0) && ( n4 < BCDDIG )) { *(rp++) = 0; n2--; n4++; }

/* 	Terminate String 	*/
/*	----------------	*/

*rp = e;

n2 = frac2; flg = 0; y = x;

rp  = (BYTE *) (&mathwork[1][(n4 = go)]); /* Calculate start position */

/*	Place leading Zeros	*/
/*	-------------------	*/

while ( y  >  0) { *(rp++) = 0; y--; }

/*	Expand BCD Compressed digits	*/
/*	----------------------------	*/

do {
	y = (EXAWORD) *(workptr2++); worklen2--;
	switch ( y & 0x00F0 ) {
		case 0x00F0 : worklen2 = 0; continue;
		case 0x00A0 : flg = 1;
		case 0x00E0    :
		case 0x00D0    :
		case 0x00C0    : 
		case 0x00B0    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (BYTE) ( y >> 4 ); n4++;
		}
	switch ( y & 0x000F ) {
		case 0x000F : worklen2 = 0; continue;
		case 0x000A : flg = 1;
		case 0x000E    :
		case 0x000D    :
		case 0x000C    : 
		case 0x000B    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (BYTE) ( y & 0x000F); n4++;
		}

	} /* WEND */

while (( worklen2 > 0) && (n4 < BCDDIG ));

/*	Place trailing Zeros	*/
/*	--------------------	*/

while ( (n2 != 0) && ( n4 < BCDDIG )) { *(rp++) = 0; n2--; n4++; }

/* 	Terminate String 	*/
/*	----------------	*/

*rp = em;

switch ( a ) {
	case	ADDITION   :
			if (sigb == sigc) {
				x   = ( BCDBYT - (y = bcdadd(stp,go)) );
				return(bcdcpr((BPTR) (&mathwork[2][((BINAIRE) y)]),workptr3,worklen3,x,sigb));
				}
			else {
REALSUB:
				rsig = sigb; v = go;
				if ( divsub((BPTR) &mathwork[1][go],(BPTR) &mathwork[0][go],(stp - go + 1) )) {
					if ( rsig == 0x00C0 ) 	{ rsig = 0x00B0; 	}
					else 			{ rsig = 0x00C0; 	}
					(void) divsub((BPTR) &mathwork[0][go],(BPTR) &mathwork[1][go],(stp - go + 1));
					}
				memcpy((BPTR) &mathwork[2][go],(BPTR) &mathwork[3][0],(stp - go + 1));
				pow = (BCDBYT - go );
				return(bcdcpr((BPTR) (&mathwork[2][((BINAIRE) v)]),workptr3,worklen3,pow,rsig));
				}
	case	SUBTRACTION :
			if (sigb == sigc) { goto REALSUB; }
			else {
				x = (BCDBYT - (y = bcdadd(stp,go)));
				return(bcdcpr((BPTR) (&mathwork[2][((BINAIRE) y)]),workptr3,worklen3,x,sigb));
				}
	case	MULTIPLY     :
			if (sigb == sigc)	{ rsig = 0x00C0;  }
			else 			{ rsig = 0x00B0; }
			x = ((stp + 1) - (y = bcdmul(stp,go,go))) - ((powm + frac1) * 2);
			return(bcdcpr((BPTR) (&mathwork[3][((BINAIRE) y)]),workptr3,worklen3,x,rsig));

	case	DIVISION     :
			if (sigb == sigc) 	{ rsig = 0x00C0;  }
			else 			{ rsig = 0x00B0; }
			x   = (BCDBYT - (y = bcddiv(go,stp,powv))) + powd;
			return(bcdcpr((BPTR) (&mathwork[4][((BINAIRE) y)]),workptr3,worklen3,x,rsig));
	case	MODULUS      :
			bcdmod(go,stp);
			return(bcdcpr((BPTR) (&mathwork[0][((BINAIRE) go)]),workptr3,worklen3,(BCDBYT - go),0x00C0));
	}
return(0);
}

#ifndef	_AOMATH_C

/* 
 *	B C D A R R ( bcds , bcdr , ls , lr , n )
 *	-----------------------------------------
 *
 *	Arrondi d'un BCD
 *
 */


EXAWORD bcdarr(bcds,bcdr,ls,lr,n)
BPTR	bcds;
BPTR	bcdr;
EXAWORD	ls,lr;
EXAWORD	n;
{
	 BYTE *	mp;
register EXAWORD head;
	 BYTE	c,d;
	 BINAIRE limit;
	 EXAWORD rsig,tail;
	 BINAIRE x;
#ifdef DUMBCC
	 EXAWORD genix;
#endif

/*
 *	Test for inverted BCD and convert if required
 *	---------------------------------------------
 */
switch ( (((EXAWORD) *bcds) & 0x00F0 ) ) {
	case 0x00C0   	:
	case 0x00B0   	: break;
	default		: err_val = ABAL_BCDFORM; 
			  return(SOFTERROR);
	}

c = 0x000F;			/* End of string Marker		*/

/*	Evaluation de la chaine BCD	*/
/*	---------------------------	*/
head = bcdeval(bcds,ls);		/* Collect Real and Fraction Count */
rsig = ((EXAWORD) *bcds ) & 0x00F0; 	/* Collect Sign byte		   */
tail = (head & 0x00FF);			/* Real number of decimals	   */
head &= 0xFF00; head >>= 8;		/* Calculate Real and Fractions    */

/*	Conversion en forme Etendu	*/
/*	--------------------------	*/
bcdetd(bcds,1,n,3,0,c,ls);	/* Expand String for Arrondi	*/
mp = &mathwork[3][1];		/* Pointer to BCD EtD		*/
*(mp - 1) = 0;		/* Set zero head		*/
d =  *(mp + head + n );		/* Get byte at arrondi point	*/

/*	Now Test for 1 of Three conditions
 *	1 - Byte is less than or equal to 3 => no arrondi needed
 *	2 - Byte is greater than 4 => arrondi immediate
 *	3 - Byte is equal to 4 so arrondi of all decimals needed
 */

if ( d > 3 ) {

	if (( d > 4 ) && ( d < 10 )) { 
		*(mp + head + n - 1) += 1; *(mp + head + n) = c; 
		}
	else	{
		/* Ensure Terminated */
		/* ----------------- */
		*(mp + head + n) = c; 
		}
/*
 *	-------------------------------------------------------------------
 *	Arrondi sur toute la partie decimale 	(Methode Scientifique)
 *	-------------------------------------------------------------------
 *
 *	if (( d == 4 ) && ( d < 10 )) {
 *
 *		Rounding of all decimals digits	
 *		-------------------------------	
 *
 *		for ( x = head + tail; x >= head + n; x-- ) {
 *			if ( *(mp + x) > 4 ) { *(mp + x -1 ) += 1; }
 *			*(mp + x ) = 0;
 *			}
 *		}
 *
 *	-------------------------------------------------------------------
 */

	/*	Correction of partie entier	*/
	/*	---------------------------	*/
	for ( x = head + n - 1; x >= 0 ; x-- ) {
		if ( *(mp + x) > 9 ) { 
			*(mp + x -1 ) += 1; 
#ifdef DUMBCC
			genix = *(mp + x);
			genix %= 10;
			*(mp + x) = (BYTE) genix;
#else
			*(mp + x) %= 10; 
#endif
			} 
		else 	{ break; }
		} 
	}
else	{
	/* Ensure Terminated */
	/* ----------------- */
	*(mp + head + n) = c; 
	}

/*	Suprimer les chiffres perdues	*/
/*	-----------------------------	*/
mp = &mathwork[3][head+n+1]; 
if ((BINAIRE) (tail - n ) > 0 ) { 
	for (x = (tail-n); x > 0 ; x-- ) { *mp = c; mp++; }
	}

/*	Reconstitute la chaine BCD	*/
/*	--------------------------	*/

x = bcdcpr((BPTR) &mathwork[3][0],bcdr,lr,head+1,rsig);

/*	Check For -Zero and Convert to +Zero	*/
/* 	------------------------------------    */

if ( bcdeval(bcdr,lr) == 0 ) { *bcdr = 0x00CF; }

return(x);
}

/* 
 *	B C D F I X ( bcds , bcdr , ls , lr , n , fixflg )
 *	--------------------------------------------------
 *
 *	Cadrage d'un BCD : Physical memory reorganisation
 *	resulting in a Right aligned packed decimal string
 *
 */

EXAWORD bcdfix(bcds,bcdr,ls,lr,n,fixflg)
BPTR	bcds;
BPTR	bcdr;				/* BCD String pointers */
EXAWORD	ls,lr;				/* BCD String lengths  */
EXAWORD	n;				/* Number of decimals  */
EXAWORD	fixflg;				/* Controls negate fix */
{

register EXAWORD head,tail;		/* Original digit counts	*/
	 EXAWORD wmax,wuse;		/* Space use contollers		*/
	 EXAWORD x,y;			/* General variables		*/
	 BPTR	fxr;			/* Duplicate result pointer	*/
	 EXAWORD fxl;			/* Duplicate result length	*/
	 BPTR	wptr;			/* unpacked string pointer	*/

/* Duplicate and Save result pointer */
/* --------------------------------- */
fxr = bcdr; fxl = lr;

/* Evaluate Source BCD string REAL:FRACTION */
/* ---------------------------------------- */

tail = ((head = bcdeval(bcds,ls)) & 0x00FF); head >>= 8;


/* Check for Numeric Result too long */
/* --------------------------------- */
if ( (wmax = (lr * 2)) < (wuse = (head + ( n > 0 ? ( n + 2 ) : 1)))) { 
	err_val = ABAL_BCD2LONG; return(SOFTERROR); 
	}

/* Convert to unpacked Decimal string */
/* ---------------------------------- */
bcdetd(bcds,(wmax - wuse),( n > tail ? ( n - tail ) : 0),3,0,0,ls);

/* Calculate Total Real Digits (including Zeros) */
/* --------------------------------------------- */
head += ( wmax - wuse);

/* Establish Work Zone and perform Sign Positioning */
/* ------------------------------------------------ */
if ( head > 0 ) {
	*(bcdr++) = (BYTE) (( *bcds & 0x00F0 ) | *((wptr = (BPTR) &mathwork[3][0])));
	head--;
	wptr++;
	lr--;
	}
else	{
	*(bcdr++) = (BYTE) (( *bcds & 0x00F0 ) | 0x000A);
	wptr = (BPTR) &mathwork[3][0];
	head = 0x020;
	lr--;
	}

/* Collect and store the unpacked digits to packed digits */
/* ------------------------------------------------------ */
while ( lr > 0 ) {	
	if ( head > 0 ) { x = (EXAWORD) *(wptr++); head--; 	}
	else		{ x = 0x000A; head--;		}
	if ( head > 0 ) { y = (EXAWORD) *(wptr++); head--; 	}
	else		{ y = 0x000A; head--;		}
	*(bcdr++) = (BYTE) ( ( x << 4) | y ); lr--;
	}

/*	Check For -Zero and Convert to +Zero	*/
/* 	------------------------------------    */

if ( bcdeval(fxr,fxl) == 0 ) { *fxr = (BYTE) (( (EXAWORD) *fxr & 0x000F ) | 0x00C0); }

return(1);
}


/* 
 *	B C D I N T ( bcds , bcdr , ls , lr )
 *	-------------------------------------
 *
 *	Partie Etier d'un BCD
 *
 */

EXAWORD bcdint(bcds,bcdr,ls,lr)
BPTR	bcds,bcdr;
EXAWORD	ls,lr;
{
	register EXAWORD x,y;
		 EXAWORD head,tail;
		 BPTR	wptr;
#ifdef DUMBCC
		 EXAWORD genix;
#endif
		 	
	x = bcdeval(bcds,ls);		/* Evaluate BCD String	*/
	tail = x & 0x00FF;		/* Collect decimal part */
	x &= 0xFF00; x >>= 8; 		/* Calculate power (+1)	*/
	head = x + 1;			/* Save power value +1	*/
	y = ((EXAWORD) *bcds) & 0x00F0;	/* Collect Sign byte	*/
	bcdetd(bcds,1,0,3,0,0x000F,ls);	/* Expand string	*/
	if ( y == 0x00B0 ) {		/* Negative rounding 	*/
		if ( tail > 0 ) {
			tail = 1;		/* Carry set to Start	*/
			wptr = (BPTR) &mathwork[3][0];	/* Pointer initialised	*/
			for ( ; (BINAIRE) x >= 0; x-- ) { /* For head count */
				*(wptr + x) += tail;	  /* Correct 4 cari */
				tail = *(wptr + x) / 10;  /* Calc new cari  */
				if ( tail > 0 )  { 
#ifdef DUMBCC
					genix = (EXAWORD) *(wptr + x);
					genix %= 10;
					*(wptr + x) = (BYTE) genix;
#else
					*(wptr + x) %= 10; 
#endif
					} 
				}	/* END FOR X = X to -1 step -1	*/
			}		/* ENDIF   tail > 0		*/
		}			/* ENDIF   y == 0x00B0		*/
	mathwork[3][head] = (BYTE) 0x000F;	/* Terminate ETD string	*/
	x = bcdcpr((BPTR) &mathwork[3][0],bcdr,lr,head,y);

	/*	Check For -Zero and Convert to +Zero	*/
	/* 	------------------------------------    */

	if ( bcdeval(bcdr,lr) == 0 ) { *bcdr =  0x00CF; }
	
	return(x);
}

/* 
 *	B C D D E C ( bcds , bcdr , ls , lr )
 *	-------------------------------------
 *
 *	Partie Decimale d'un BCD
 *
 */
EXAWORD	bcddec(bcds,bcdr,ls,lr)
BPTR	bcds,bcdr;
EXAWORD	ls,lr;
{
	register EXAWORD x,y;
		 EXAWORD flag;

if ( bcdeval(bcds,ls) == 0 )  { (void) itobcd(0,bcdr,lr); return(1); } 

if (( ls > 0 ) && ( lr > 0 )) {

	/*	Test for leading separator	*/
	/*	--------------------------	*/
	x = (EXAWORD) *(bcds++); ls--;
	if (( x & 0x000F ) == 0x000A ) { flag = 1; }
	else { flag = 0; }

	/*	Place New Header byte	*/
	/* 	--------------------- 	*/
	*(bcdr++) = (BYTE) ((x &= 0x00F0) | 0x000A); lr--;

	/* 	Perform FP function	*/
	/*	-------------------	*/
	while (( ls > 0 ) && ( lr > 0 )) {
		switch ( flag )	{
			case 0  :
				x = (EXAWORD) *(bcds++); ls--;
				if (( x & 0x00F0 ) == 0x00A0 ) {
					flag = 2; continue;
					}
				if (( x & 0x000F ) == 0x000A ) {
					flag = 1;
					}
				continue;
			case 1  :
				*(bcdr++) = *(bcds++); ls--; lr--;
				continue;
			case 2  :
				y = ((x & 0x000F) << 4);
				x = *(bcds++); ls--;
				y |= (( x & 0x00F0) >> 4);
				*(bcdr++) = (BYTE) y; lr--;
				continue;
			}
		}
	/* 	Perform string filler		*/
	/*	---------------------		*/
	if ( flag == 2 ) { y = (((x & 0x000F) << 4) | 0x000F); 	}
	else 		 { y = 0x00FF; 				}
	while ( lr > 0 ) { *(bcdr++) = (BYTE) y; lr--; y = 0x00FF; 	}
	return(1);
	}
else { err_val = ABAL_BCDFORM; return(SOFTERROR); }
}

#endif	/* ! _AOMATH_C */
	/* ----------- */

#endif	/* _AOMATH_C */
	/* --------- */

