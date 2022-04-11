/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMATH - C				*/
/*		Version :	1.4c					*/
/*		Date 	:	20/04/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "exmath.h"

#ifdef	ABAL_RTL
#define	worktop	TcodeByteIndex
extern	EXAWORD	TcodeByteIndex;
#include "exdmath.c"
#include "expower.c"
#endif

#ifdef INTEL
#include "exprag0.h"
#endif

/* 
 * --------------------------------------------------------------------------
 * These routines are only used for debugging the bcd functions !
 * --------------------------------------------------------------------------
 */

EXAWORD	sux=1;

#ifdef DIVBUG
VOID divsubview(a,b,l)
BPTR	a,b;
EXAWORD	l;
{
	register BINAIRE x;
	printf("\nDigits = %d : Debut Dend = %04.1X Debut Vsor = %04.1X ",l,b,a);
	printf("\n\t");
	for ( x = 0 ; x < l ; x++ ) {
		printf("%02.1X ",*b);
		b++;
		}
	printf("\t-\n\t");
	for ( x = 0 ; x < l ; x++) {
		printf("%02.1X ",*a);
		a++;
		}
	return;
}
#endif
#ifdef BCDBUG
/*	Visualise une chaine BCD en form Compresse
 *	------------------------------------------
 */

VOID viewbcd(cp,ln)
BPTR	cp;
BINAIRE	ln;
{
	BINAIRE x;
	EXABYTE c;
printf("\nChaine BCD @ %04.1XH  : ",cp);
for (x = 0 ; x < ln ; x++) { c = *(cp++); printf("%02.1X ",c); }
return;
}


/*	Visualise BCD en form Etendu.
 *	-----------------------------
 */

viewetd(go,whch,stp)
EXAWORD go;
EXAWORD whch;
EXAWORD stp;
{
	BPTR	cp;
	EXAWORD	x,y;
	EXABYTE	c;

cp = (BPTR) &mathwork[whch][go]; y = stp - go;
printf("\nChaine ETD @ %04.1XH  length %04.1XH: ",cp,y);
for (x = 0 ; x <= y ; x++) { c = *(cp++); printf("%02.1X ",c); }
return;
}

VOID etdvisu(pow,sig,deb)
EXAWORD	pow,sig,deb;
{
	EXAWORD	x,y;

	printf("\nCompression of Numeric ECD to Numeric BCD\n");
	printf("\nPower factor supplied %04.1X , Sign supplied %04.1X ",pow,sig);
	printf("\nStart of Compression  %04.1X ",deb);
	printf("\nExponant digits (0 -> 23) \n");
	for ( x = 0; x < 24 ; x++) {    if ( x == deb ) { printf("DEB"); }
					else { printf("%02.1X ",x); }}
	printf("\n");
	for ( x = 0; x < 24 ; x++) {
		y = (EXAWORD) mathwork[2][x];
		printf("%02.1X ",y);
		}
	printf("\nMantissa digits (24 -> 47) \n");
	for ( x = 24; x < 48 ; x++) { if ( x == deb ) { printf("DEB"); }
					else { printf("%02.1X ",x); }}

	printf("\n");
	for ( x = 24; x < 48 ; x++) {
		y = (EXAWORD) mathwork[2][x];
		printf("%02.1X ",y);
		}
	return;
}

#endif

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
		case BCD_NegI	:
		default		: err_val = ABAL_BCDFORM; return(MOINS_UN);
		case BCD_Pos	:
		case BCD_NegR	: break;
		}

	while ( len > 0 ) {
		len--;
		switch ( ((x = (EXAWORD) *(bcd++)) & BCD_MaskH) ) {
			case BCD_Sep_H	: goto EVALP2;
			case BCD_MaskH	: goto EVALEXIT;
			case BCD_Pos	:
			case BCD_NegR	: break;
			case 0x0000	: if ( flg == 0 ) { break; }
			default		: flg = 1; head++;
			}
		switch ( x & BCD_MaskL ) {
			case BCD_Sep_L	: goto EVALP1;
			case 0x000C	:
			case 0x000B	: 
			case BCD_MaskL	: goto EVALEXIT;
			case 0x0000	: if ( flg == 0 ) { continue; }
			default		: flg = 1; head++;
			}
		}
EVALP1:
	while ( len > 0 ) {
		len--;
		switch ( ((x = (EXAWORD) *(bcd++)) & BCD_MaskH) ) {
			case BCD_MaskH	: 
			case BCD_Pos	:
			case BCD_NegR	: 
			case BCD_Sep_H	: goto EVALEXIT;
			case 0x0000	: tail++; break;
			default		: digits = ( ++tail ); 
			}
EVALP2:
		switch ( x & BCD_MaskL ) {
			case BCD_MaskL	: 
			case 0x000C	:
			case 0x000B	: 
			case BCD_Sep_L	: goto EVALEXIT;
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

VOID bcdetd(bcd,n1,n2,n3,n4,e,bcdslen)
BPTR	bcd;			/* Points to BCD String */
EXAWORD	n1;			/* Leading zeros	*/
EXAWORD	n2;			/* Trailing zeros	*/
EXAWORD	n3;			/* Matrix Element	*/
EXAWORD	n4;			/* Starting position	*/
EXABYTE	e;			/* End of string byte	*/
EXAWORD	bcdslen;			/* Maximum length of BCD */

{
	EXABYTE *rp;
/*	----------	*/
/*	EXABYTE *rrp;	*/
/*	----------	*/
	register EXAWORD  x,flg;

flg = 0;
if ( e != IO_NUL ) { e = (EXABYTE) BCD_Filler; }
rp  = (EXABYTE *) (&mathwork[n3][n4]); /* Calculate start position */
/* ----------------------------------  */
/* rrp = (EXABYTE *) (&mathwork[2][n4]);  */
/* ----------------------------------  */

/*	Place leading Zeros	*/
/*	-------------------	*/

	while ( n1 >  0) 
		{ *(rp++) = IO_NUL; n1--; }

/*	Expand BCD Compressed digits	*/
/*	----------------------------	*/

do {
	x = (EXAWORD) *(bcd++); bcdslen--;
	switch ( x & BCD_MaskH ) {
		case BCD_MaskH : bcdslen = 0; continue;
		case BCD_Sep_H : flg = 1;
		case 0x00E0    :
		case 0x00D0    :
		case 0x00C0    : 
		case 0x00B0    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (EXABYTE) ( x >> 4 ); n4++;
				/* ------------------ */
				/*  *(rrp++) = IO_NUL; */
				/* ------------------- */
		}
	switch ( x & BCD_MaskL ) {
		case BCD_MaskL : bcdslen = 0; continue;
		case BCD_Sep_L : flg = 1;
		case 0x000E    :
		case 0x000D    :
		case 0x000C    : 
		case 0x000B    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (EXABYTE) ( x & BCD_MaskL); n4++;
				/* ------------------ */
				/* *(rrp++) = IO_NUL; */
				/* ------------------ */
		}

	} /* WEND */
while (( bcdslen > 0) && (n4 < BCDDIG ));

/*	Place trailing Zeros	*/
/*	--------------------	*/
							  /* ------------------ */
while ( (n2 != 0) && ( n4 < BCDDIG )) { *(rp++) = IO_NUL; /* *(rrp++) = IO_NUL; */ n2--; n4++; }
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
	EXAWORD	 bcdeos=BCD_MaskL;	
        register EXAWORD x,y;
		 EXAWORD hf,ctrl;
		 BPTR	wptr;		 

	if (*((wptr = "\0BUGBCD0A0F")) != 0)
		bcdeos = BCD_Sep_L;

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
		*(rp++) = (EXABYTE) (rsig | BCD_Sep_L);
		bcdeos = BCD_MaskL;
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
			*(rp++) = (EXABYTE) ( BCD_Sep_H | x ); rl--; 
			bcdeos = BCD_MaskL;
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
			*(rp++) = (EXABYTE) ( y | BCD_Sep_L); rl--; 
			bcdeos = BCD_MaskL;
			y = ( x << 4); continue; 
			}

		else	{ /* Power Still Active so Store and Continue */
			  /* ---------------------------------------- */ 
			*(rp++) = (EXABYTE) ( y | x ); rl--;
			ctrl = 0; continue;

			}	/* ENDIF */

		}		/* ENDIF */

	} 			/* WEND  */

	/*	Don't lose the possible last digit ! 	*/
	/*	------------------------------------	*/
CPREXIT:
	if (( ctrl == 1 ) && ( rl > 0 )) { 
		*(rp++) = (EXABYTE) ( y | bcdeos); rl--;
		}

	/*	Fill to end of BCD string with FF	*/
	/*	---------------------------------	*/

	while ( rl > 0 ) { *(rp++) = (EXABYTE) MOINS_UN; rl--; }

	/*	Correct for zero if neccessary		*/
	/*	------------------------------		*/

	if ( hf == 0 ) { *wptr = (EXABYTE) 0x00CF; }

 	return(1);
}

/* 
 *	Conversion des donnees
 *	----------------------
 */

#include "exconv.c"	/*	Include Conversion routines	*/
			/*	---------------------------	*/
			/*	Integer to assci  		*/
			/*	Ascii to integer  		*/
			/*	Integer to hexadecimale		*/
			/*	Hexadecimale to integer		*/
			/*	BCD to integer			*/
			/*	integer to BCD			*/
			/*	BCD to Ascii			*/
			/*	Ascii to BCD			*/
			/*	Negate BCD			*/
			/*	---------------------------	*/


/* 
 *	Q C O M P ( a , x , y )
 *	----------------------- 
 *
 *	Quick Compare function for Sign or Exponant length Compares
 *
 */

EXAWORD	qcomp(a,x,y)
EXAWORD	a,x,y;
{
	/* Quick treatment due to different signs */
	/* -------------------------------------- */
	switch (a) {
		case	0 : return(0); 	/* JCP is FALSE */
		case	1 : return(1);	/* JNE is TRUE	*/
		case	2 :		/* JGE */
		case	4 :		/* JGR */
			if (x  > y ) return(1);
			else return(0); /* Is False */
		case	3 :		/* JLE */
		case	5 :		/* JLS */
			if (x < y ) return(1);
			else return(0);
		default   : return(0);
		}
}
#ifndef INTELASM1
/* 
 *	COMPBCD ( comp_code, bcdptr1, bcdptr2 )
 *	---------------------------------------
 *	Called from EXMOTOR-C
 *
 *	Numerical BCD Compare routines =, !=, <, >, <=, >=
 *	--------------------------------------------------
 */

EXAWORD	compbcd(a,b,c)
EXAWORD	a;
BPTR	b;
BPTR	c;
{
	register EXAWORD x,y;
	EXAWORD	xx,xy;
	EXAWORD	h,s;
	EXABYTE	*wptr;

	/*	Test for inverted BCD and convert if required
         *	---------------------------------------------
	 */

	while ( (xx = (((EXAWORD) *b) & BCD_MaskH)) == BCD_NegI) { b = (BPTR) negbcdcpy(b,worklen1); }
	while ( (xy = (((EXAWORD) *c) & BCD_MaskH)) == BCD_NegI) { c = (BPTR) negbcdcpy(c,worklen2); }

	/* Evaluate both strings Now Tant Pis */
	/* ---------------------------------- */
	x = bcdeval(b,worklen1); y = bcdeval(c,worklen2);
	if (( x == 0 ) && ( xx == 0x00B0)) {
		*b = (EXABYTE) (( ((EXAWORD) *b ) & 0x000F) | (xx = 0x00C0));
		}
	if (( y == 0 ) && ( xy == 0x00B0)) {
		*c = (EXABYTE) (( ((EXAWORD) *c ) & 0x000F) | (xy = 0x00C0));
		}

	/*	Test first for different Signs
 	 *	------------------------------
	 */

	if ( xx != xy ) {
		x = xx ; y = xy;
BCDQCOMP:
		switch (a) {
			case	0 : return(0); 	/* JCP is FALSE */
			case	1 : return(1);	/* JNE is TRUE	*/
			case	2 :		/* JGE */
			case	4 :		/* JGR */
				if (x  > y ) { return(1); }
				return(0);      /* Is False */
			case	3 :		/* JLE */
			case	5 :		/* JLS */
				if (x < y ) { return(1); }
			default   : return(0);
			}
		}

	if ( xx == 0x00C0 ) 	{ s = 1; }
	else			{ s = 0; }

	/*	Test first for different lengths
 	 *	--------------------------------
	 */
	if (( x | y ) == 0 ) {	/* Comparing Zero to Zero */
		switch ( a ) {
			case 0 :  
			case 2 :
			case 3 : return(1);
			case 1 :
			case 4 :
			case 5 :
			default : return(0);
			}
 		}
	if ((x == 0 ) || (y == 0)) {	/* Comparing Zero with something */
		if (( s == 0 ) && ( a > 1 )) { /* Perform Neg Swap GR/LS */
			s = x; x = y; y = s;
			}
		goto BCDQCOMP;
		}

	if ( (x & 0xFF00) != (y & 0xFF00) ) { /* Exponant powers differ */
		if (( s == 0 ) && ( a > 1 )) { /* Perform Neg Swap GR/LS */
			s = x; x = y; y = s;
			}
		goto BCDQCOMP;
		}

	/*	We got here so we must Perform the EXALONG compare
	 *	-----------------------------------------------
	 */
	h = (( x  >> 8 ) + ((x & BCD_Filler) > (y & BCD_Filler) ? (x & BCD_Filler) : ( y & BCD_Filler)));
	bcdetd(b,0,(h-(x & 0x00FF)),0,0,IO_NUL,worklen1); bcdetd(c,0,(h-(y & 0x00FF)),1,0,IO_NUL,worklen2);
	wptr = (EXABYTE *) &mathwork[0][0];
	while ( h > 0 ) {
	   x = *wptr; y = *(wptr + BCDDIG);
	   switch ( s ) {
		case 1 :	/* Signs Posative */
		switch ( a ) {
/* JEQ	*/		case 0 : if ( x != y ) { return(0); }
				 else { break; }
/* JNE  */		case 1 : if ( x != y ) { return(1); }
				 else { break; }
/* JGE  */		case 2 : if ( x < y ) { return(0); }
				 if ( x > y ) { return(1); }
				 else { break; }
/* JLE  */		case 3 : if ( x > y ) { return(0); }
				 if ( x < y ) { return(1); }
				 else { break; }
/* JGR	*/		case 4 : if ( x > y ) { return(1); }
				 if ( x < y ) { return(0); }
				 else { break; }
/* JLS  */		case 5 : if ( x <  y ) { return(1); }
				 if ( x >  y ) { return(0); }
				 else { break; }
/* JIN | JNI */		default : return(0);	
			}
		   break;
		default :
		case 0  :	/* Signs Negative */
		switch ( a ) {
/* JEQ	*/		case 0 : if ( x != y ) { return(0); }
				 else { break; }
/* JNE  */		case 1 : if ( x != y ) { return(1); }
				 else { break; }
/* JGE  */		case 2 : if ( x < y ) { return(1); }
				 if ( x > y ) { return(0); }
				 else { break; }
/* JLE  */		case 3 : if ( x > y ) { return(1); }
				 if ( x < y ) { return(0); }
				 else { break; }
/* JGR	*/		case 4 : if ( x > y ) { return(0); }
				 if ( x < y ) { return(1); }
				 else { break; }
/* JLS  */		case 5 : if ( x <  y ) { return(0); }
				 if ( x >  y ) { return(1); }
				 else { break; }
/* JIN | JNI */		default : return(0);	
			}
		   break;

		}
		wptr++; h--;
	   }

	/*	If we get Here then the strings are equal	*/
	/*	-----------------------------------------	*/

	switch ( a ) {
		case 2 :
		case 3 :
		case 0 :	return(1);
		case 1 :
		case 4 :
		case 5 :
		default :	return(0);		
		}
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

register	EXABYTE  	*rdigit,*ydigit;
		EXABYTE  	*xdigit;
		EXABYTE  	*ygo;
		EXABYTE  	*end1,*end2;
#ifdef DUMBCC
		EXAWORD	genix;
#endif

end1 = &mathwork[1][fin1]; 
end2 = &mathwork[0][fin2];
ygo = (EXABYTE *) (&mathwork[0][0] + go);
for ( xdigit = (&mathwork[1][0] + go) ; xdigit >= end1; xdigit-- ) {
	if ( ((EXAWORD) *xdigit) != 0x0000 ) {
		rdigit = (EXABYTE *) (xdigit + (BCDDIG*2));
		for ( ydigit = ygo ; ydigit >= end2; ydigit-- ) {
#ifdef DUMBCC
			genix   = (EXAWORD) *rdigit;
			genix  += ( (EXAWORD) *ydigit * (EXAWORD) *xdigit );
			*rdigit = (EXABYTE) genix;
			genix   = (EXAWORD) *(rdigit - 1);
			genix  += ( (EXAWORD) *rdigit / 10 );
			*(rdigit - 1) = (EXABYTE) genix;			 
			genix = *rdigit;
			genix %= 10;
			*rdigit = (EXABYTE) genix;
#else
			*rdigit += (EXABYTE) ( (*ydigit)  *  (*xdigit) );
			*(rdigit - 1) += (EXABYTE) ( (*rdigit) / 10 );
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
	register EXABYTE	 *wp;
	register EXAWORD  x;

wp = (EXABYTE *) &mathwork[0][deb]; x = 0;

do {
	*(wp + (2 * BCDDIG)) =  ((x = (*wp + *(wp + BCDDIG) + (x / 10) )) % 10);
	wp--;
	}
while ( --deb >= fin );	
if ( x > 9 ) { *(wp + (2 * BCDDIG)) = (EXABYTE) (x / 10); }
return(--fin);
}

#endif

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
(VOID) memcpy((BPTR) &mathwork[2][0],(BPTR) &mathwork[1][0] , BCDDIG);

#ifdef DIVBUG
	printf("\nDivision BCD : Debut = %d  Fin = %d ",debut,fin);
	viewetd(debut,0,fin);
	viewetd(debut,2,fin);
	viewetd(debut,4,fin);
#endif

dividend = (BPTR) &mathwork[0][debut]; /* Establish Dividend start 	*/
resultat = debut;			 /* Establish Result start   	*/
divisor	 = (BPTR) &mathwork[2][debut]; /* Establish Divisor  start 	*/

/*	Establish position of the first non zero digit of Divisor
 *	---------------------------------------------------------
 */

control = debut; shft = 0;

while ( *divisor == IO_NUL) { divisor++; control++; } 

/*	Calculate length of divisor
 *	---------------------------
 */
temp = control; hp = divisor; digits = control;
while ( control <= fin ) {
	if ( *hp != IO_NUL) { temp = control; }
	control++; hp++;
	}

digits = temp - digits + 1;
if (digits < mindigits) { digits = mindigits; }

while ( divsub(divisor,dividend,digits) == 1 ) {  digits++; divisor--;
						  *divisor = IO_NUL; debut--; 
						  shft++; } 
#ifdef DIVBUG
	divsubview(divisor,dividend,digits);
#endif

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

#ifdef DIVBUG
	printf("*");
#endif

      mathwork[4][resultat] += 1;		/* Increment Result digit */
      memcpy(dividend,(BPTR) &mathwork[3][0],digits);  /* Replace with new digits */
      }

    /*	Failed to subtract without borrow
     *	---------------------------------
     */

#ifdef DIVBUG
    printf("%02.1X ",mathwork[4][resultat]);
#endif

    /* Advance and Zero RESULT Byte pointer */
    /* ------------------------------------ */
    resultat++; mathwork[4][resultat] = IO_NUL;

    /* Check for more Dividend digits */
    /* ------------------------------ */
    if ( *dividend == IO_NUL) 	{ dividend++; 		}
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

VOID	bcdmod(debut,fin)
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
	if ( *divisor != (EXABYTE) 0 ) { break; }
	else { powplus++; divisor++; x--; }
	}
if ( x > 0 ) {
	while ( powplus > 0 ) {
		while ( divsub(divisor,dividend,digits) == 0 ) {
			(VOID) memcpy(dividend,(BPTR) &mathwork[3][0],digits);
			}
		powplus--; divisor--;
		}
	}
/* (VOID) memcpy((BPTR) &mathwork[2][debut],dividend,digits); */
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

#ifndef INTELASM1
EXAWORD bcdcalc(a)
#else
EXAWORD	xbcdcalc(a)
#endif

EXAWORD	a;			/* Operation Code 	*/
{
	
	EXAWORD	real1,frac1,real2,frac2,go,stp,v;
	EXAWORD	sigb,sigc,pow,powd,powv,powm;
	EXAWORD	digits;
	register EXAWORD x,y;
	EXABYTE	e,em;
	BPTR	bcd;
	EXAWORD	len;
	EXABYTE 	*rp;
	EXAWORD flg,n2,n4;
	EXAWORD	prec1,prec2,i;

	(VOID) memset((BPTR) &mathwork[0][0],0x0000,(48 * 6));

	/*	Test for inverted BCD and convert if required	*/
        /*	---------------------------------------------	*/

	if ( (((EXAWORD) *workptr1) & BCD_MaskH ) == BCD_NegI ) { workptr1 = (BPTR) negbcdcpy(workptr1,worklen1); }
	if ( (((EXAWORD) *workptr2) & BCD_MaskH ) == BCD_NegI ) { workptr2 = (BPTR) negbcdcpy(workptr2,worklen2); }

	switch	( a ) {
		case DIVISION 	: e = IO_NUL; em = IO_NUL; break;
		case MODULUS	: e = 0x000F; em = IO_NUL; break;
		case MULTIPLY	: e = IO_NUL; em = IO_NUL; break;
		default		: e = 0x000F; em = 0x000F;	
		}

	for ( x = BCDBYT ; x < BCDDIG ; x++) 	{ mathwork[2][x] = e ; } 


bcd = workptr1; len = worklen1; real1 = 0; frac1 = 0; y = 0; digits = 0;

while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & BCD_MaskH) ) {
		case BCD_Sep_H	: goto EVALP2;
		case BCD_MaskH	: goto EVALEXIT;
		case BCD_Pos	:
		case BCD_NegR	: break;
		case 0x0000	: if ( y == 0 ) { break; }
		default		: y = 1; real1++;
		}
	switch ( x & BCD_MaskL ) {
		case BCD_Sep_L	: goto EVALP1;
		case 0x000C	:
		case 0x000B	: 
		case BCD_MaskL	: goto EVALEXIT;
		case 0x0000	: if ( y == 0 ) { continue; }
		default		: y = 1; real1++;
		}
	}
EVALP1:
while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & BCD_MaskH) ) {
		case BCD_MaskH	: 
		case BCD_Pos	:
		case BCD_NegR	: 
		case BCD_Sep_H	: goto EVALEXIT;
		case 0x0000	: digits++; break;
		default		: frac1 = ( ++digits ); 
		}
EVALP2:
	switch ( x & BCD_MaskL ) {
		case BCD_MaskL	: 
		case 0x000C	:
		case 0x000B	: 
		case BCD_Sep_L	: goto EVALEXIT;
		case 0x0000	: digits++; break;
		default		: frac1 = ( ++digits ); 
		}
	}
EVALEXIT:
	prec1 = digits;
sigb = (((EXAWORD) *workptr1 ) & BCD_MaskH); pow = real1; 

bcd = workptr2; len = worklen2; frac2 = 0; real2 = 0; y = 0; digits = 0;

while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & BCD_MaskH) ) {
		case BCD_Sep_H	: goto EVALP22;
		case BCD_MaskH	: goto EVALEXIT2;
		case BCD_Pos	:
		case BCD_NegR	: break;
		case 0x0000	: if ( y == 0 ) { break; }
		default		: y = 1; real2++;
		}
	switch ( x & BCD_MaskL ) {
		case BCD_Sep_L	: goto EVALP12;
		case 0x000C	:
		case 0x000B	: 
		case BCD_MaskL	: goto EVALEXIT2;
		case 0x0000	: if ( y == 0 ) { continue; }
		default		: y = 1; real2++;
		}
	}
EVALP12:
while ( len > 0 ) {
	len--;
	switch ( ((x = (EXAWORD) *(bcd++)) & BCD_MaskH) ) {
		case BCD_MaskH	: 
		case BCD_Pos	:
		case BCD_NegR	: 
		case BCD_Sep_H	: goto EVALEXIT2;
		case 0x0000	: digits++; break;
		default		: frac2 = ( ++digits ); 
		}
EVALP22:
	switch ( x & BCD_MaskL ) {
		case BCD_MaskL	: 
		case 0x000C	:
		case 0x000B	: 
		case BCD_Sep_L	: goto EVALEXIT2;
		case 0x0000	: digits++; break;
		default		: frac2 = ( ++digits ); 
		}
	}
EVALEXIT2:
	prec2 = digits;
if (( frac2 | real2 ) == 0 ) {
	switch ( a ) {
		case ADDITION    :
		case SUBTRACTION : break;
		case MULTIPLY    : 
			return(bcdcpr((BPTR) &mathwork[2][0],workptr3,worklen3,1,BCD_Pos)); 
		default		 : 
			err_val = ABAL_NDXZERO;
			return(SOFTERROR); 
		}
	}

if ((( real1 | frac1 ) == 0 ) && ( a > SUBTRACTION) ) {
	return(bcdcpr((BPTR) &mathwork[2][0],workptr3,worklen3,1,BCD_Pos)); 
	}

sigc = ( (EXAWORD) *workptr2 ) & BCD_MaskH; 
powv = real2; powd = frac2; pow += real2; powm = frac1;

if (real1 >= real2) 	{ x = real1 - real2 ; y = 0; go = BCDBYT - real1; }
else 			{ y = real2 - real1;  x = 0; go = BCDBYT - real2; }

if (frac1 >= frac2) 	{ frac2 = frac1 - frac2; stp = (BCDBYT - 1) + frac1; frac1 = 0; }
else 			{ frac1 = frac2 - frac1; stp = (BCDBYT - 1) + frac2; frac2 = 0; }

n2 = frac1; flg = 0;

rp  = (EXABYTE *) (&mathwork[0][(n4 = go)]); /* Calculate start position */

/*	Place leading Zeros	*/
/*	-------------------	*/

while ( y  >  0) { *(rp++) = IO_NUL; y--; }

/*	Expand BCD Compressed digits	*/
/*	----------------------------	*/

do {
	y = (EXAWORD) *(workptr1++); worklen1--;
	switch ( y & BCD_MaskH ) {
		case BCD_MaskH : worklen1 = 0; continue;
		case BCD_Sep_H : flg = 1;
		case 0x00E0    :
		case 0x00D0    :
		case 0x00C0    : 
		case 0x00B0    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (EXABYTE) ( y >> 4 ); n4++;
		}
	switch ( y & BCD_MaskL ) {
		case BCD_MaskL : worklen1 = 0; continue;
		case BCD_Sep_L : flg = 1;
		case 0x000E    :
		case 0x000D    :
		case 0x000C    : 
		case 0x000B    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (EXABYTE) ( y & BCD_MaskL); n4++;
		}

	} /* WEND */

while (( worklen1 > 0) && (n4 < BCDDIG ));

/*	Place trailing Zeros	*/
/*	--------------------	*/

while ( (n2 != 0) && ( n4 < BCDDIG )) { *(rp++) = IO_NUL; n2--; n4++; }

/* 	Terminate String 	*/
/*	----------------	*/

*rp = e;

n2 = frac2; flg = 0; y = x;

rp  = (EXABYTE *) (&mathwork[1][(n4 = go)]); /* Calculate start position */

/*	Place leading Zeros	*/
/*	-------------------	*/

while ( y  >  0) { *(rp++) = IO_NUL; y--; }

/*	Expand BCD Compressed digits	*/
/*	----------------------------	*/

do {
	y = (EXAWORD) *(workptr2++); worklen2--;
	switch ( y & BCD_MaskH ) {
		case BCD_MaskH : worklen2 = 0; continue;
		case BCD_Sep_H : flg = 1;
		case 0x00E0    :
		case 0x00D0    :
		case 0x00C0    : 
		case 0x00B0    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (EXABYTE) ( y >> 4 ); n4++;
		}
	switch ( y & BCD_MaskL ) {
		case BCD_MaskL : worklen2 = 0; continue;
		case BCD_Sep_L : flg = 1;
		case 0x000E    :
		case 0x000D    :
		case 0x000C    : 
		case 0x000B    : break;
		case 0x0000    : if ( flg == 0 ) { break; } 
		default        : flg = 1;
				*(rp++)  = (EXABYTE) ( y & BCD_MaskL); n4++;
		}

	} /* WEND */

while (( worklen2 > 0) && (n4 < BCDDIG ));

/*	Place trailing Zeros	*/
/*	--------------------	*/

while ( (n2 != 0) && ( n4 < BCDDIG )) { *(rp++) = IO_NUL; n2--; n4++; }

/* 	Terminate String 	*/
/*	----------------	*/

*rp = em;

switch ( a ) {
#ifndef INTELASM1
	case	ADDITION   :
			if (sigb == sigc) {
				x   = ( BCDBYT - (y = bcdadd(stp,go)) );
				return(bcdcpr((BPTR) (&mathwork[2][((BINAIRE) y)]),workptr3,worklen3,x,sigb));
				}
			else {
REALSUB:
				rsig = sigb; v = go;
				if ( divsub((BPTR) &mathwork[1][go],(BPTR) &mathwork[0][go],(stp - go + 1) )) {
					if ( rsig == BCD_Pos ) 	{ rsig = BCD_NegR; 	}
					else 			{ rsig = BCD_Pos; 	}
					(VOID) divsub((BPTR) &mathwork[0][go],(BPTR) &mathwork[1][go],(stp - go + 1));
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
			if (sigb == sigc)	{ rsig = BCD_Pos;  }
			else 			{ rsig = BCD_NegR; }
			x = ((stp + 1) - (y = bcdmul(stp,go,go))) - ((powm + frac1) * 2);
		        for ( i = prec1+prec2+x+y ; i < BCDDIG ; i++)  { mathwork[3][i] = 0x0F ; } 
			return(bcdcpr((BPTR) (&mathwork[3][((BINAIRE) y)]),workptr3,worklen3,x,rsig));
#endif
	case	DIVISION     :
			if (sigb == sigc) 	{ rsig = BCD_Pos;  }
			else 			{ rsig = BCD_NegR; }
			x   = (BCDBYT - (y = bcddiv(go,stp,powv))) + powd;
			return(bcdcpr((BPTR) (&mathwork[4][((BINAIRE) y)]),workptr3,worklen3,x,rsig));
	case	MODULUS      :
			bcdmod(go,stp);
			return(bcdcpr((BPTR) (&mathwork[0][((BINAIRE) go)]),workptr3,worklen3,(BCDBYT - go),BCD_Pos));
	}
return(0);
}

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
	 EXABYTE *	mp;
register EXAWORD head;
	 EXABYTE	c,d;
	 EXAWORD rsig,tail;
	 BINAIRE x;
#ifdef DUMBCC
	 EXAWORD genix;
#endif

/*
 *	Test for inverted BCD and convert if required
 *	---------------------------------------------
 */
switch ( (((EXAWORD) *bcds) & BCD_MaskH ) ) {
	case BCD_NegI 	: bcds = (BPTR) negbcdcpy(bcds,ls);
	case 0x00C0   	:
	case 0x00B0   	: break;
	default		: err_val = ABAL_BCDFORM; 
			  return(SOFTERROR);
	}

c = BCD_MaskL;			/* End of string Marker		*/

/*	Evaluation de la chaine BCD	*/
/*	---------------------------	*/
head = bcdeval(bcds,ls);		/* Collect Real and Fraction Count */
rsig = ((EXAWORD) *bcds ) & BCD_MaskH; 	/* Collect Sign byte		   */
tail = (head & 0x00FF);			/* Real number of decimals	   */
head &= 0xFF00; head >>= 8;		/* Calculate Real and Fractions    */

/*	Conversion en forme Etendu	*/
/*	--------------------------	*/
bcdetd(bcds,1,n,3,0,c,ls);	/* Expand String for Arrondi	*/
mp = &mathwork[3][1];		/* Pointer to BCD EtD		*/
*(mp - 1) = IO_NUL;		/* Set zero head		*/
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
 *			*(mp + x ) = IO_NUL;
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
			*(mp + x) = (EXABYTE) genix;
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

/* Test for inverted BCD and convert if required */
/* --------------------------------------------- */

if ( (((EXAWORD) *bcds) & BCD_MaskH ) == BCD_NegI ) { bcds = (BPTR) negbcdcpy(bcds,ls); }

/* Evaluate Source BCD string REAL:FRACTION */
/* ---------------------------------------- */

tail = ((head = bcdeval(bcds,ls)) & 0x00FF); head >>= 8;


/* Check for Numeric Result too EXALONG */
/* --------------------------------- */
if ( (wmax = (lr * 2)) < (wuse = (head + ( (n > 0) ? ( n + 2 ) : 1)))) { 
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
	*(bcdr++) = (EXABYTE) (( *bcds & BCD_MaskH ) | *((wptr = (BPTR) &mathwork[3][0])));
	head--;
	wptr++;
	lr--;
	}
else	{
	*(bcdr++) = (EXABYTE) (( *bcds & BCD_MaskH ) | 0x000A);
	wptr = (BPTR) &mathwork[3][0];
	head = 0x020;
	lr--;
	}

/* Collect and store the unpacked digits to packed digits */
/* ------------------------------------------------------ */
while ( lr > 0 ) {	
	if ( head > 0 ) { x = (EXAWORD) *(wptr++); head--; 	}
	else		{ x = BCD_Sep_L; head--;		}
	if ( head > 0 ) { y = (EXAWORD) *(wptr++); head--; 	}
	else		{ y = BCD_Sep_L; head--;		}
	*(bcdr++) = (EXABYTE) ( ( x << 4) | y ); lr--;
	}

/*	Check For -Zero and Convert to +Zero	*/
/* 	------------------------------------    */

if ( bcdeval(fxr,fxl) == 0 ) { *fxr = (EXABYTE) (( (EXAWORD) *fxr & 0x000F ) | 0x00C0); }

/* Convert Negative values to Inverted format */
/* ------------------------------------------ */


if ( (((EXAWORD) *fxr) & BCD_MaskH ) == BCD_NegR ) { 
	if ( fixflg != 0 ) { negbcd(fxr,fxl); }
	}

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
		 	
	if ( (((EXAWORD) *bcds) & BCD_MaskH ) == BCD_NegI ) { bcds = (BPTR) negbcdcpy(bcds,ls); }
	x = bcdeval(bcds,ls);		/* Evaluate BCD String	*/
	tail = x & BCD_Filler;		/* Collect decimal part */
	x &= 0xFF00; x >>= 8; 		/* Calculate power (+1)	*/
	head = x + 1;			/* Save power value +1	*/
	y = ((EXAWORD) *bcds) & BCD_MaskH;	/* Collect Sign byte	*/
	bcdetd(bcds,1,0,3,0,BCD_MaskL,ls);	/* Expand string	*/
	if ( y == BCD_NegR ) {		/* Negative rounding 	*/
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
					*(wptr + x) = (EXABYTE) genix;
#else
					*(wptr + x) %= 10; 
#endif
					} 
				}	/* END FOR X = X to -1 step -1	*/
			}		/* ENDIF   tail > 0		*/
		}			/* ENDIF   y == BCD_NegR		*/
	mathwork[3][head] = (EXABYTE) BCD_MaskL;	/* Terminate ETD string	*/
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
		 BPTR iptr;
		 EXAWORD ilen;
		 EXAWORD zero_check;

if ( (((EXAWORD) *bcds) & BCD_MaskH ) == BCD_NegI ) 
	bcds = (BPTR) negbcdcpy(bcds,ls);

if ( bcdeval(bcds,ls) == 0 )  { 
#ifdef	OLD_SLOW_FP
	(VOID) itobcd(0,bcdr,lr);
#else
	/* --------------------------- */
	/* Optimisation 21/01/1993 IJM */
	/* --------------------------- */
	memset( bcdr, 0x00FF, lr ); *bcdr = 0x00C0;
#endif
	return(GOODRESULT); 
	}

if (( ls > 0 ) && ( lr > 0 )) {

	/*	Test for leading separator	*/
	/*	--------------------------	*/
	x = (EXAWORD) *(bcds++); ls--;
	if (( x & BCD_MaskL ) == BCD_Sep_L ) 
		flag = 1; 
	else 	flag = 0;

	zero_check = 0;

	/*	Place New Header byte	*/
	/* 	--------------------- 	*/
	ilen = lr;
	iptr = bcdr; 
	*(bcdr++) = (EXABYTE) ((x &= BCD_MaskH) | BCD_Sep_L); lr--;

	/* 	Perform FP function	*/
	/*	-------------------	*/
	while (( ls > 0 ) && ( lr > 0 )) {
		switch ( flag )	{
			case 0  :
				/* --------------------------------------- */
				/* This condition is the pre-decimal-point */
				/* Digit removal phase. Detection of the   */
				/* nibble 0x00A passes into phase 1 which  */
				/* Transfers all remaining digits directly */
				/* to the result whilst checking for none  */
				/* Detection of the nibble 0x00A0 passes   */
				/* into phase 2 where the fractional digit */	
				/* Transfer is performed in desynchronised */
				/* fashion.				   */
				/* --------------------------------------- */
				x = (EXAWORD) *(bcds++); ls--;
				if (( x & BCD_MaskH ) == BCD_Sep_H )
					flag = 2;
				else	if (( x & BCD_MaskL ) == BCD_Sep_L )
						flag = 1;
				continue;
			case 1  :
				/* --------------------------------- */
				/* Synchronised EXABYTE shift operation */
				/* --------------------------------- */
				if (((y = *bcds))
				&&  ((y &  0x00F0) != 0x00F0)
				&&  (y !=  0x000F))
					zero_check++;
				*(bcdr++) = *(bcds++); ls--; lr--;
				continue;
			case 2  :
				/* ------------------------------------- */
				/* Desynchronised NIBBLE shift operation */
				/* ------------------------------------- */
				y = ((x & BCD_MaskL) << 4);
				x = *(bcds++); ls--;
				y |= (( x & BCD_MaskH) >> 4);
				if ((y)
				&&  ((y &  0x00F0) != 0x00F0)
				&&  (y !=  0x000F))
					zero_check++;
				*(bcdr++) = (EXABYTE) y; lr--;
				continue;
			}
		}
	/* 	Perform string filler		*/
	/*	---------------------		*/
	if ( ! (zero_check) ) {
		if ((flag != 2 ) || (( x & 0x000F) < 1 ) || (( x & 0x000F ) > 9 )) {
			memset( iptr, 0x00FF, ilen );
			*iptr = 0x00C0;
			return( GOODRESULT );
			}
		}
	if ( flag == 2 ) 
		y = (((x & BCD_MaskL) << 4) | BCD_MaskL); 	
	else 	y = BCD_Filler; 
	while ( lr > 0 ) { 
		*(bcdr++) = (EXABYTE) y; 
		lr--; y = BCD_Filler; 	
		}
	return( GOODRESULT );
	}
else 	{ 
	err_val = ABAL_BCDFORM; 
	return(SOFTERROR); 
	}
}

#ifdef	ABAL_RTL

/*
 *	B C D _ A R I T H M E T I C ( op, ap, al, bp, bl, rp, rl )
 *	----------------------------------------------------------
 *	This function performs the routing for the various bcd
 *	arithmetical operations. 
 *		Numbered as follows :
 *			ADD 1
 *			SUB 2
 *			MUL 3
 *			DIV 4
 *			MOD 5
 *
 */	

EXAWORD	bcd_arithmetic( opcode, ap, al, bp, bl, rp, rl )
EXAWORD	opcode;
BPTR	ap;
EXAWORD	al;
BPTR	bp;
EXAWORD	bl;
BPTR	rp;
EXAWORD	rl;
{
	workptr1 = ap; worklen1 = al;
	workptr2 = bp; worklen2 = bl;
	workptr3 = rp; worklen3 = rl;
	return( bcdcalc(opcode) );	
}

/*
 *	B C D _ C O M P A R E
 *	---------------------
 *	Opcode : 0 EQUAL
 *		 1 NOT EQUAL
 *		 2 GREATER OR EQUAL
 *		 3 LESS OR EQUAL
 *		 4 GREATER
 *		 5 LESS
 *
 *	Returns 1 to indicate Condition True, or 0 to indicate false.
 */		
 

EXAWORD	bcd_compare( opcode, ap, al, bp, bl )
EXAWORD	opcode;
BPTR	ap;
EXAWORD	al;
BPTR	bp;
EXAWORD	bl;
{
	workptr1 = ap; worklen1 = al;
	workptr2 = bp; worklen2 = bl;
#ifdef	INTELASM1
	return( bcdcomp( opcode ) );	
#else
	return( compbcd( opcode, workptr1, workptr2 ));
#endif
}

/*
 *	B C D _ T R A N S F E R ( rp, rl, sp, sl )
 *	------------------------------------------
 *	This function is provided to perform  complicated bcd
 *	variable copy transfer operations.
 *
 */

EXAWORD	bcd_transfer( workptr1, worklen1, workptr2, worklen2 )
BPTR	workptr1;
EXAWORD	worklen1;
BPTR	workptr2;
EXAWORD	worklen2;
{
	EXAWORD	flg;
	
	flg = 0; err_val = ABAL_NUM2BIG; 

	/* Perform UNFIX for FIXED Negative Values */
	/* --------------------------------------- */
	if ( (*workptr2 & 0x00F0) == 0x0040 )
		workptr2 = (BPTR) negbcdcpy( workptr2, worklen2 );

	/* Squeeze Source if Length greater than Result length */
	/* --------------------------------------------------- */
	if ( worklen1 < worklen2 ) 
		workptr2 = (BPTR) Squeeze(workptr2,worklen2);

	/* Control Pour BCD NL=1 Qui Recoit -0 !!! */
	/* --------------------------------------- */
	if ((worklen1 == 1 ) && ((( *workptr2 & 0x0F ) > 0x09 ) || ((*workptr2 & 0x0F) == 0))) {
		*workptr1 = 0x0CF;
		return(1);
		}

	/* Perform Nibble transfer from source to result */
	/* --------------------------------------------- */
	while ((worklen1 > 0) && (worklen2 > 0)) {
		if ( flg == 0 ) {
			switch ( *workptr2 & 0x00F0 ) {
				case 0x00A0 :
				case 0x00F0 : flg = 1;
				}
			switch ( *workptr2 & 0x000F ) {
				case 0x000A :
				case 0x000F : flg = 1;
				}
			}
		*(workptr1++) = *(workptr2++);
		worklen1--; worklen2--;
		}

	/* Padd Result With BCD filler character */
	/* ------------------------------------- */
	for ( ; worklen1 > 0; worklen1-- )
		*(workptr1++) = (EXABYTE) 0x00FF; 

	/* Check for Error or Succes Return */
	/* -------------------------------- */
	if ( worklen2 == 0 ) 
		return(1);
	else	{ 
		if ((flg != 0 ) || (( *workptr2 & 0x00F0 ) > 0x0090 )) 
			return(1);
		else	return(flg);
		}	

} 
#endif

#ifdef INTEL
#include "exprag1.h"
#endif

