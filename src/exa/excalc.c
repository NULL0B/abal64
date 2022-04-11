/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1991 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCALC - C				*/
/*		Version :	1.4c/2.1d				*/
/*		Date 	:	10/04/1996				*/
/*									*/
/*----------------------------------------------------------------------*/

/* Mises a jour: */
/* ------------  */
/*  19/05/99 : (#AT) Bug EXA-63 fixed. Corrections bounded with assigning to null pointers in ABAL */
/*  03/03/00 : (#BG) Bug EXA-75 fixed */

#ifdef	WIN32
#define	PRLEXADB
#endif

#ifdef AIX_VERS
#include <string.h>
#endif /* AIX_VERS */

#include "exmotor.h"		/* Header file for external and Defines */
#include "exmacro.h"		/* Executeur Check Macros		*/
#include "exvtype.h"		/* Variable data type definitions	*/

EXTERN	EXAWORD	FuseCount;
EXTERN	EXAWORD	adr_usr;
#ifdef	UNIX
EXTERN	EXAWORD	cico_use_abqt;
VOID	abqt();
#endif

#ifdef INTEL
#include "exprag0.h"		/* Stack probing OFF (Microsoft only)	*/
#endif

VOID	TcodePutWord( void * Tx, EXAWORD Vx )
{
	if ( WORDSIZE == 2 ) { *((WPTR16) Tx) = Vx; }
	else 		     { *((WPTR) Tx) = Vx;  }
}

EXAWORD	TempZone()
{
	StackCheck( (worklen1) );
	memcpy((BPTR) (TcodeByteStack + worktop) ,(BPTR) workptr1 , (USINT) worklen1);
	workptr1 = (BPTR) (TcodeByteStack + worktop); worktop += worklen1;
	StackCheck( (worklen2) );
	memcpy((BPTR) (TcodeByteStack + worktop) ,(BPTR) workptr2 , (USINT) worklen2);
	workptr2 = (BPTR) (TcodeByteStack + worktop); worktop += worklen2;
	return(GOODRESULT);
}

EXAWORD	get_to_global()	{	return( TOGLOBAL );	}
EXAWORD	get_is_local ()	{	return( ISLOCAL  );	}
EXAWORD	get_word_size()	{	return( WORDSIZE );	}

EXAWORD tkodgeti()
{
	EXAWORD	ix;
	ix = Tcodeword( fdex); fdex += WORDSIZE;
	return(ix);
}
#ifdef	ABAL64
EXAWORD tkodgetw64()
{
        EXAWORD ix;
        ix = TcodeWord64( fdex);
        fdex += WORD64SIZE;
        return(ix);
}
#endif
EXAWORD tkodgetw32()
{
	EXAWORD	ix;
	ix = TcodeWord32( fdex); 
	fdex += WORD32SIZE;
	return(ix);
}

EXAWORD tkodgetw16()
{
	EXAWORD	ix;
	ix = TcodeWord16( fdex); 
	fdex += WORD16SIZE;
	return(ix);
}

/*
 *	X M E M C P Y (  f  )
 *	---------------------
 */

VOID xmemcpy(f)
EXAWORD	f;
{
	err_val = 0;
if ( worklen1 > 0 ) {
		if (workptr1 == 0) {
			err_val = 118; return;
		}
	(VOID) memcpy( workptr1 , workptr2 ,(worklen2 = ( worklen2 > worklen1 ? worklen1 : worklen2 )));
	if ((worklen1 = (worklen1 - worklen2)) > 0 ) {
			if (!(workptr1 + worklen2)) {
				err_val = 118; return;
			}
		(VOID) memset((workptr1 + worklen2),f,worklen1);
		}
	}
return;
}

/*
 *	S T R 0 F I L L ( )
 *	-------------------
 */

EXAWORD	str0fill()
{
	if ( *(workptr3) == '-' ) {
		*(workptr1++) = '-'; 
		workptr3++; 
		worklen1--;
		}	
	if ((workval2 = (worklen1 - (workval1 = lenuze(workptr3,worklen1)) )) > 0)
	{
		if (!workptr1) 
		{
			err_val = 118;
			return SOFTERROR;
		}
		(VOID) memset(workptr1,'0',workval2);
  }
   if (!(workptr1 + workval2)) {
		err_val = 118;
		return SOFTERROR;
	}
	(VOID) memcpy((workptr1 + workval2),workptr3,workval1);
	return(1);
}

/*
 *	N U M C L E A N ()
 *	------------------
 */

VOID numclean()
{
	EXAWORD	x;
	BPTR	lptr;
	x = strlen(workptr1);
	if ( x >= worklen1)
		return;
	lptr = (workptr1 + x);
	x = worklen1 - x;
	for ( ; x > 0; x-- )
		*(lptr++) = ' '; 
	return;
}

/*
 *	V A R C O N V ( how )
 * 	---------------------
 */

#ifdef	VERSION666
#define	CONVSHIFT 8 
#endif

EXAWORD varconv(how)
EXAWORD	how;
{
	EXAWORD	flg;

	/*       Destination  H  : Source    L      	*/
	/*	----------------  -------------		*/
	switch ( (worktyp1 << 8) | (worktyp2 & 0x00FF) )	
	{
/* # # */	case 0x0000 :   
/* # % */	case 0x0001 :	
/* # L */	case 0x0005 :	
/* # H */	case 0x0006 :	*workptr1 = (EXABYTE) workval2; break;
/* # N */	case 0x0002 :   *workptr1 = (EXABYTE) bcdtoi(workptr2,worklen2); break;
/* # $ */	case 0x0003 :	*workptr1 = (EXABYTE) atoi(workptr2,worklen2); break;

/* % # */	case 0x0100 :	
/* % L */	case 0x0105 :	
/* % H */	case 0x0106 :	
/* % % */	case 0x0101 :	balputw((EXAWORD) workval2,workptr1); break;
/* % N */	case 0x0102 :   flg = (EXAWORD) bcdtoi(workptr2,worklen2);
				balputw( flg , workptr1 );
				break;
/* % $ */	case 0x0103 :   flg = (EXAWORD) atoi(workptr2,worklen2);
				balputw( flg , workptr1 );
				break;
/* L # */	case 0x0500 :	
/* L % */	case 0x0501 :	
/* L L */	case 0x0505 :	
/* L L */	case 0x0506 :	balputl((EXAWORD) workval2,workptr1); break;
/* % N */	case 0x0502 :   flg = (EXAWORD) bcdtol(workptr2,worklen2);
				balputl( flg , workptr1 );
				break;
/* L $ */	case 0x0503 :   flg = (EXAWORD) atol(workptr2,worklen2);
				balputl( flg , workptr1 );
				break;
/* L # */	case 0x0600 :	
/* L % */	case 0x0601 :	
/* L L */	case 0x0605 :	
/* L L */	case 0x0606 :	balput64((EXAWORD) workval2,workptr1); break;
/* % N */	case 0x0602 :   flg = (EXAWORD) bcdtol(workptr2,worklen2);
				balput64( flg , workptr1 );
				break;
/* L $ */	case 0x0603 :   flg = (EXAWORD) atol(workptr2,worklen2);
				balput64( flg , workptr1 );
				break;
		case 0x0200 :	
		case 0x0201 :	return(itobcd(workval2,workptr1,worklen1));
		case 0x0205 :	return(ltobcd(workval2,workptr1,worklen1));	
		case 0x0206 :	return(htobcd(workval2,workptr1,worklen1));
		case 0x0202 :	
			flg = 0; err_val = ABAL_NUM2BIG; 
			if ( (*workptr2 & 0x00F0) == 0x0040 )
				workptr2 = (BPTR) negbcdcpy( workptr2, worklen2 );

			if ( worklen1 < worklen2 ) { workptr2 = (BPTR) Squeeze(workptr2,worklen2); }
			/* Control Pour BCD NL=1 Qui Recoit -0 !!! */
			/* --------------------------------------- */
			if ((worklen1 == 1 ) && ((( *workptr2 & 0x0F ) > 0x09 ) || ((*workptr2 & 0x0F) == 0))) {
				*workptr1 = 0x0CF;
				return(1);
				}
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
			while ( worklen1 > 0 ) { *(workptr1++) = (EXABYTE) 0x00FF; worklen1--; }
			if ( worklen2 == 0 ) 	{ return(1);   }
			else			{ 
				if ((flg != 0 ) || (( *workptr2 & 0x00F0 ) > 0x0090 ))  { return(1); }
				else { return(flg); }
				}	

		case 0x0203 :	return(atobcd(workptr2,workptr1,worklen1,worklen2));

		case 0x0300 :	
		case 0x0301 : if ( how == 1 ) {
				StackCheck( MAXBCDSIZE );
				workptr3 = (TcodeByteStack + worktop);
				worktop += MAXBCDSIZE;
				itoa(workval2,workptr3,MAXBCDSIZE);
				return(str0fill());
				}
			      else { itoa(workval2,workptr1,worklen1); return(1); }
		case 0x0305 : if ( how == 1 ) {
				StackCheck( MAXBCDSIZE );
				workptr3 = (TcodeByteStack + worktop);
				worktop += MAXBCDSIZE;
				ltoa(workval2,workptr3,MAXBCDSIZE);
				return(str0fill());
				}
			      else { ltoa(workval2,workptr1,worklen1); return(1); }
		case 0x0306 : if ( how == 1 ) {
				StackCheck( MAXBCDSIZE );
				workptr3 = (TcodeByteStack + worktop);
				worktop += MAXBCDSIZE;
				ltoa(workval2,workptr3,MAXBCDSIZE);
				return(str0fill());
				}
			      else { ltoa(workval2,workptr1,worklen1); return(1); }
		case 0x0302 : if ( how == 1 ) {
				StackCheck( worklen1 );
				workptr3 = (TcodeByteStack + worktop);
				worktop += worklen1;
				bcdtoa(workptr2,worklen2,workptr3,worklen1);
				return(str0fill());
				}
			      else { 
				   bcdtoa(workptr2,worklen2,workptr1,worklen1); 
				   (VOID) numclean();
				   return(1); 
				   }
		case 0x0303 :	
			xmemcpy(0x0020); 
			if (err_val) return SOFTERROR;
			break;
		default	    :	return(SOFTERROR);
		}
	return(1);
}

#include "exarg.c"

/*
 *	Save a register to a Variable
 *	-----------------------------
 */

EXAWORD	vputs(reg,vardex)
EXAWORD	reg,vardex;
{
	if (argsetw(5,vardex) == SOFTERROR) { return(SOFTERROR); } /* Establish Dest ptr */
	if (argset(4,reg,2)   == SOFTERROR) { return(SOFTERROR); } /* Establish Srce ptr */
	return(varconv(1));			   /* Perform Conversion */
}


EXAWORD	negwork(k,s)
EXAWORD	k,s;
{
	BPTR	sptr;

	/* Evaluate Arguament to be Negated */
	/* -------------------------------- */
	if ( argsetw( (5 - k) , s ) == SOFTERROR ) {
		return(SOFTERROR); 
		}
	/* Test for Strings and Eliminate With Error */
	/* ----------------------------------------- */
	if ( worktyp1 > 2 ) { 
		err_val = ABAL_STR4NUM; return(SOFTERROR); 
		}

	/* Watch out for Register Result required */
	/* -------------------------------------- */
	if ( k == 1 ) 	{ 
		sptr = workptr1; 
		if (argsetw(6,s) == SOFTERROR) { return(SOFTERROR); }
		memcpy(workptr1,sptr,worklen1);
		}

	/* Check for and Negate Bcd Variables */
	/* ---------------------------------- */
	if ( worktyp1 == 2 ) { 	

		/* Watchout for and UnDo Negative Fixed Bcd Variables */
		/* -------------------------------------------------- */
		if ((((EXAWORD) *workptr1) & 0x00F0) == 0x0040 ) { 
			negbcd(workptr1,worklen1); 
			}
		
		/* Watchout for and Ignore Zero Values */
		/* ----------------------------------- */
		sptr = Squeeze(workptr1,worklen1);
		if ((( *sptr & 0x000F ) == 0x000F )
		||  ((( *sptr & 0x000F ) == 0x000A) && ((*(sptr + 1) & 0x00F0) == 0x00F0))) {
 			return(1);
			}

		/* Perform Negation */
		/* ---------------- */
		k = (EXAWORD) *workptr1; 
		switch ( k & 0x00F0 ) {
			case 0x00C0	: k &= 0x000F; k |= 0x00B0; break;
			case 0x00B0	: k &= 0x000F; k |= 0x00C0; break;
			default		: err_val = ABAL_BCDFORM; k = 0; break;
			}
		if ( k != 0 ) { *workptr1 = (EXABYTE) k; k = 1; }
		return(k);
		}

	/* Perform Integer Negation 8 and 16 bits */
	/* -------------------------------------- */
	switch (( worktyp1 & VARB_ISOL )) {
		case	VARB_INT16	:	
			if ( k == 1 ) {
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
				}
			else	{ 
				balputw( -(workval1) ,workptr1 ); 
				}
			return(GOODRESULT); 
		case	VARB_FOUR	:
		case	VARB_INT8	:
			if ( k == 1 ) {
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
				}
			else	{ 
				*workptr1 = (EXABYTE) -(workval1);
				}
			return(GOODRESULT); 
		case	VARB_INT32	:	
			if ( k == 1 ) 
			{
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
			}
			else	
			{
				balputl( -(workval1) ,workptr1 ); 
			}
			return(GOODRESULT); 
		case	VARB_INT64	:	
			if ( k == 1 ) 
			{
				freg[s] = -(workval1);
				xreg[s] = IMMEDIAT;
			}
			else	
			{
				balput64( -(workval1) ,workptr1 ); 
			}
			return(GOODRESULT); 
		}
	err_val = 1444;
	return( SOFTERROR );
}

/*
 *	ERRstatus = V A R C P Y ( Sdesc,Ddesc, Sndx, Dndx )
 *	---------------------------------------------------
 *	Copies Variable Source with auto convert to Variable Destination
 *
 */

EXAWORD varcpy(svar,dvar,si,di)
EXAWORD	svar;
EXAWORD	dvar;
EXAWORD	si;
EXAWORD	di;
{
	if ( si == di ) { 
		di = (COPYREG); 
		ireg [di] = ireg [si]; 
		areg [di] = areg [si]; 
		}
	freg [si] = svar; freg [di] = dvar;
	xreg [si] = VARIABLE; xreg [di] = VARIABLE;
	if (argset(4,si,2) == SOFTERROR) { return(SOFTERROR); }
	if (argsetw(4,di) == SOFTERROR) { return(SOFTERROR); }
	return(varconv(1));
}

EXAWORD f_pause(fx)
EXAWORD	fx;
{
	EXAWORD	x;
	prndest = 1;
#ifdef BUF_CICO
	x_bstart();
#endif
	fx = sf_print(fx); 	
#ifdef BUF_CICO
	x_bflush();
#endif
	while ((x = (EXAWORD) exio_getch()) != IO_RC) { 
		x_bell(); 
		}
	exio_putch(IO_RC);
	exio_putch(IO_LF);
	return(1);
}


EXAWORD	opb()
{
#ifdef	UNIX
	if ( mimo_kbhit() ) {
		return(1);
		}
	else 	{
		if ( cico_use_abqt )
			abqt();
		return(0);
		}
#else
	EXAWORD ret;
	ret = x_kbhit();
	if ( cico_use_abqt )
		abqt();
	return(ret);
#endif
}

/*
 *	C O M P I N T ( _fx , b , c )
 *	-----------------------------
 */

EXAWORD compint(_fx,b,c)
EXAWORD _fx;
BINAIRE	b;
BINAIRE	c;
{
switch (_fx & 0x0007) {
	case  0 : if ( b == c ) { break; }
		  fdex +=WORDSIZE; return(1);
	case  1 : if ( b != c ) { break; }
		  fdex +=WORDSIZE; return(1);
	case  2 : if ( c >= b ) { break; }
		  fdex +=WORDSIZE; return(1);
	case  3 : if ( c <= b ) { break; }
		  fdex +=WORDSIZE; return(1);
	case  4 : if ( c > b )  { break; }
		  fdex +=WORDSIZE; return(1);
	case  5 : if ( c < b )  { break; }
	case  6 : 
	case  7 : fdex +=WORDSIZE; return(1);
	}
	fdex = TcodeSegment + Tcodeword( fdex ); 
	return(1);
}

/*
 *	L E N U Z E (  cp , lenmax  )
 *	-----------------------------
 */
 
EXAWORD lenuze(BPTR cp, EXAWORD lenmax)
{
	register int x;

	for (x = 0 ; x < lenmax ; x++) {
		if (*(cp + x) == IO_NUL)
			break;
	}

	while( (--x >= 0) && (*(cp + x) == IO_ESP) );
	return(x+1);
}

/*
 *	L E N U Z E N D (  cp , lenmax  )
 *	---------------------------------
 */
#ifdef WIN32
EXAWORD lenuzend(BPTR cp, EXAWORD lenmax)
{
	EXAWORD i;

	for (i = 0 ; i < lenmax ; i++) {
		if (cp[i] == IO_NUL)
			break;
	}
	
	while(i != 0) {
		if (cp[i-1] == IO_ESP)
			i--;
		else
			break;
	}
	return(i);
}
#endif

#ifndef INTELASM1
/*
 *	L E N U S E (  cp , lenmax  )
 *	-----------------------------
 */

EXAWORD lenuse(BPTR cp, EXAWORD lenmax)
{
	register int x;

	x = lenmax;
	while( (--x >= 0) && (*(cp + x) == IO_ESP) );
	return(x+1);
}


/*
 *	I S I N C L ( )
 *	---------------
 *	Test for inclusion of String A (@workset1) in String B (@workset2)
 *
 */

EXAWORD	isincl()
{
	BPTR	 workptr4;
	EXAWORD  worklen4;
	BINAIRE	 x;
	register EXAWORD y,z;
	EXAWORD	 spclen;

spclen = worklen2;

/* Jump leading spaces in both strings */
/* ----------------------------------- */
/* #BG: 03/03/00 (begin) */
while ((worklen1 > 0) && (*workptr1 == IO_ESP)) { workptr1++; worklen1--; }
while ((worklen2 > 0) && (*workptr2 == IO_ESP)) { workptr2++; worklen2--; }
/* #BG: 03/03/00 (end) */

/* Test for 2 Blank Strings (OK INC) */
/* --------------------------------- */
if (( worklen1 == 0) && (worklen2 == 0)) { return(0); }
if (( worklen1 == 0) || (worklen2 == 0)) { return(1); }

/* Calculate length of 1st Operand */
/* ------------------------------- */
worklen1 = lenuse(workptr1,worklen1);

/* Main Body of Compare */
/* -------------------- */

while ((worklen1 > 0) && (worklen2 > 0)) { 
/* 1 - Find if the first character of string 1 exists in string 2 */
/* -------------------------------------------------------------- */
	while (( worklen2 > 0 ) && ( *workptr2 != *workptr1 )) {
		workptr2++; worklen2--;
		}
	if ( worklen2 == 0 ) { return(1); } /* Not included */
	if ( spclen > worklen2 ) {
		if ( *(workptr2 - 1) != IO_ESP ) { 
			workptr2++; worklen2--;
			continue;
			}
		} 

/* Establish Temporary worksets 3 & 4 */
/* ---------------------------------- */
	workptr3 = workptr1; worklen3 = worklen1;
	workptr4 = workptr2; worklen4 = worklen2;
	x = 1; y = 0; z = 0;
/* Compare byte for byte the 2 substrings , Multiple spaces become singles */
/* ----------------------------------------------------------------------- */
while (( worklen3 > 0 ) && ( worklen4 > 0)) {	
	if ( *workptr3 == IO_ESP ) {
		if ( y > 0 ) { workptr3++; worklen3--;continue; }
		y++;
		}
	else	{	y = 0;		}
	if ( *workptr4 == IO_ESP ) {
		if ( z > 0 ) { workptr4++; worklen4--;continue; }
		z++;
		}
	else	{	z = 0;		}
	if ( (x = ( ((EXAWORD) *(workptr3++)) - ((EXAWORD) *(workptr4++)) )) != 0) { break; }
	worklen3--; worklen4--;	
	}
/* There are several ways to exit from the Compare While loop		*/
/* ----------------------------------------------------------		*/
/*    - X is not equal to zero so we must continue the character search */
/*    - X is equal to zero and source string end reached		*/
/*    - X is equal to zero and Target string end reached		*/
/* -------------------------------------------------------------------- */
	if ( x == 0 ) {
		/* Check for End of Source String */
		/* ------------------------------ */
		if ( worklen3 == 0 ) { 

			/* Check for End of Target String */
			/* ------------------------------ */
			if ( worklen4 == 0 ) {

				/* End of Both Strings so Inclusion TRUE */
				/* ------------------------------------- */
				return(0); 
				}

			/* Target String not expired so test for SPACE */
			/* ------------------------------------------- */
			if ( *workptr4 == IO_ESP ) {

				/* OK Inclusion TRUE */
				/* ----------------- */
				return( 0 );
				}
			}
		else	{
			/* Check for End of Target String */
			/* ------------------------------ */
			if ( worklen4 == 0 ) {

				/* Check for Source contains only Space */
				/* ------------------------------------ */
				while ( worklen3 > 0 ) {

					/* Exit on First Non Space Character */
					/* --------------------------------- */
					if ( *(workptr3++) != IO_ESP ) {
						break;
						}
					worklen3--;
					}

				/* Check for End of Source String Reached */
				/* -------------------------------------- */
				if ( worklen3 == 0 ) {

					/* Inclusion TRUE */
					/* -------------- */
					return(0);
					}
				}
			}	
		}
	workptr2++; worklen2--;		
	}
return(1);	/* Not included */
}
#endif

/*
 *	U S M E M C M P ( sptr, rptr, slen, rlen )
 *	------------------------------------------ 
 *	Unsigned Memory Compare with length control of Both Zones
 *
 *	Result - > ZERO 		Zones are identical
 *	Result     LESS THAN ZERO 	Zone 1 is Less Than Zone 2 
 *	Result	   GREATER THAN ZERO	Zone 1 is Greater Than Zone 2
 *	
 *	Remarque : Les longeurs des zones peuvent etre ZERO qui provoque
 *		   une resultat correcte !
 *
 */

BINAIRE usmemcmp()
{
	register EXAWORD slen,rlen;

	slen = worklen1;
	rlen = worklen2;

	/* --------------------------------------------- */
	/* While Neither string length is ZERO		 */
        /* and while the characters under test are EQUAL */
	/* --------------------------------------------- */
	while (( slen > 0 ) && ( rlen > 0 )) { 
		if ( *workptr1 != *workptr2 ) { break; }
		slen--; rlen--; workptr1++; workptr2++;
		}

	/* Test for End of ( Either OR Both  ) Zone, length == 0 */
	/* ----------------------------------------------------- */
	if (( slen == 0) || ( rlen == 0 )) { return( slen - rlen ); }

	/* Otherwise Compare Fail Status Calculation */
	/* ----------------------------------------- */
	return( ((EXAWORD) *workptr1) - ((EXAWORD) *workptr2) );
}
#ifndef	PROLOGUE
#ifndef	DOS
#define	PRLEXADB
#endif
#endif

#ifdef	PRLEXADB
BINAIRE	isequalit()
{
	register BINAIRE x;

	/* JEQ, JNE, JGE, JLE, JGR and JLS */
	/* ------------------------------- */
	x = (worklen1 < worklen2 ? worklen1 : worklen2);

	/* Compare for Smallest string Length */
	/* ---------------------------------- */
	while ( x > 0 ) { 
		if ( *workptr1 != *workptr2 ) { 
			x = (BINAIRE) ( ((EXAWORD) *workptr1) - ((EXAWORD) *workptr2) ); 
			break; 
			}
		x--; workptr1++; workptr2++;
		}
	return(x);
}
#endif

/*
 *	C O M P S T R ( a )
 *	-------------------
 */


EXAWORD compstr(a)
EXAWORD	a;
{
	register BINAIRE	x;

	/* 	JEQ , JNE , JGR , JGE , JLS , JLE	*/
	/*	---------------------------------	*/
	if ( a < 6 ) 	{ 	x = isequalit();	}
	/*	JIN JNI 				*/
	/* 	-------					*/
	else 		{	x = isincl(); 		}

	switch	( a ) {
		case    6 :
		case	0 : if ( x != 0 ) { fdex +=WORDSIZE; return(1); }
			    break;
		case	7 :
		case	1 : if ( x == 0 ) { fdex +=WORDSIZE; return(1); }
			    break;
		case	2 : if ( x == 0 ) { break; }
		case	4 : if ( x > 0  ) { break; }
			    fdex +=WORDSIZE; return(1);
		case	3 : if ( x == 0 ) { break; }
		case	5 : if ( x < 0  ) { break; }
		default	  : fdex +=WORDSIZE; return(1);
		}
		fdex = (TcodeSegment + Tcodeword( fdex ) );
		return(1);
}


xmemchr(sp,c,sl)
BPTR	sp;
EXABYTE	c;
EXAWORD	sl;
{
	EXAWORD	x;
	x = 1;
	while ( sl > 0 ) {
		if ( *(sp++) == c ) { return(x); }
		x++; sl--;
		}
	return(0);
}

/*
 *	S T R C A L C ( calc )
 *	----------------------
 */

EXAWORD strcalc(calc)
EXAWORD	calc;			/* Operation Code 		*/
{
	register EXAWORD lr;
	EXAWORD	c,d;
lr = worklen3;
if ( (calc & 0x0003) == 0 ) {

	/* Test for Concatenation / Eliminate Space */
	/* ---------------------------------------- */
	if ( calc == 4 ) { 
		/* Calculate real lengths */
		/* ---------------------- */
		worklen1 = lenuse(workptr1,worklen1);
		worklen2 = lenuse(workptr2,worklen2); 
		} 
	/* Transfer 1st Operand */
	/* -------------------- */
	if ( worklen1 > worklen3 ) {
		worklen1 = worklen3;
		}
	if ( worklen1 > 0 ) {
		(VOID) memcpy( workptr3 , workptr1 , worklen1 );
		workptr3 += worklen1; worklen3 -= worklen1;
		}
	/* Transfer 2nd Operand */
	/* -------------------- */
	if ( worklen2 > worklen3 ) {
		worklen2 = worklen3;
		}
	if ( worklen2 > 0 ) {
		(VOID) memcpy( workptr3 , workptr2 , worklen2 );
		workptr3 += worklen2; worklen3 -= worklen2;
		}
	if ( worklen3 > 0 ) {
		(VOID) memset( workptr3 , IO_ESP , worklen3 );
		}
	return(1);
	}
else 	{ 
	while (( lr > 0) && (worklen1 > 0 ) && (worklen2 > 0)) {
		c = *(workptr1++); worklen1--;
		d = *(workptr2++); worklen2--;
		switch (calc) {
			case 1 : c -= d; break;
			case 2 : c *= d; break;
			case 3 : c /= d; break;
			case 5 : c &= d; break;
			case 6 : c |= d; break;
			case 7 : c += d; break;
			}
		*(workptr3++) = (EXABYTE) c; lr--;
		}
	while ( lr > 0) { *(workptr3++) = IO_ESP; lr--; }
	return(1);
	}		
}


/*	Returns an Integer Value of the Constante pointed to by CONDEX
 *	--------------------------------------------------------------
 */
BINAIRE valcon(condex)
EXAWORD	condex;
{
	EXAWORD	conlen;
	BPTR	conptr;
	conptr = (TcodeConstants + condex);
	while (1) {
		if ((conlen = *(conptr++)))
			return(atoi(conptr,conlen));
		else if ((conlen = *(conptr++)) & 0x0080)
			conptr = (GlobalConstants + (Tcodeword((conptr))));
		else	return(bcdtoi(conptr,conlen));
		}
}

/*	Returns an Integer Value of the temporary Variable pointed by TMPDEX
 *	--------------------------------------------------------------------
 */

BINAIRE valtmp(tmpdex)
EXAWORD	tmpdex;
{
if ( *(TcodeByteStack + tmpdex) == VARB_BCD ) { return(bcdtoi((TcodeByteStack + tmpdex + (2 * WORDSIZE)),(Tcodeword((TcodeByteStack + tmpdex + WORDSIZE))))); }
else	{ return(atoi((TcodeByteStack + tmpdex + (2 * WORDSIZE)),(Tcodeword((TcodeByteStack + tmpdex + WORDSIZE))))); }
}

/*	Returns an Integer Value of the Variable pointed to by VARDEX
 *	-------------------------------------------------------------
 */

BINAIRE valvar(vardex,reg)
EXAWORD vardex;
EXAWORD	reg;
{
freg [reg] = vardex; xreg [reg] = VARIABLE;
if (argset(4,reg,1) == SOFTERROR) {  return(SOFTERROR); }
switch ( worktyp1 ) {
	case 	VARB_FOUR  :  
	case 	VARB_INT8  :  
	case	VARB_INT32 :
	case	VARB_INT64 :
	case	VARB_INT16 : return(workval1);
	case	VARB_BCD   : return(bcdtoi(workptr1,worklen1));
	case	VARB_STR   : return(atoi(workptr1,worklen1));
	default		   : return(SOFTERROR);
	}
}

#include "exerror.c"	/* ERROR Management Functions              	*/
#include "exdata.c"	/* DATA  Management Functions  			*/
#include "extimer.c"	/* TIMER Management Functions			*/
#include "exlinda.c"	/* TASK  Management Functions			*/
#ifdef INTEL
#include "exprag1.h"
#endif
