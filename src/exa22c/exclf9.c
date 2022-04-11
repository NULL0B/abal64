/*
 *	Group 9 B.C.D. Trigonometrical and mathematical functions
 *	---------------------------------------------------------
 *	
 *	0) -	BCDr = ATN ( BCDs )	Arctangent
 *	1) -	BCDr = COS ( BCDs ) 	Cosinus
 *	2) -	BCDr = EXP ( BCDs )	Exponant
 *	3) -	BCDr = LOG ( BCDs )	Logarithm
 *	4) -	BCDr = SIN ( BCDs )	Sinus
 *	5) -	BCDr = SQR ( BCDs )	Square root ( Racine carree )
 *	6) -	BCDr = TAN ( BCDs )	Tangential
 *
 *	This module is compiled only with the EXBL option defined, otherwise
 *	all functions of this group return 	ERROR : 56
 *						Function not supported
 *
 */

#ifdef EXBL
#include	"extrig.c"		/* Include trig functions	*/
#else
EXAWORD	f_clf9( x )
EXAWORD	x;
{
	switch ( x ) {
		default :
			err_val = EXER_CONFWOT; return(SOFTERROR);
		}
}
#endif
