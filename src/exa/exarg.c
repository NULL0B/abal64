/*
 *
 *		E X E C U T E U R 	ABAL
 *		----------------------------
 *
 *		Copyright (c) 1987,2012 Amenesik / Sologic
 *
 *		Module  :	EXARG.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

#ifdef	ABAL21

#include "exptr.h"

/*
 *	R E S O L V E _ M E M B E R ( work )
 *	------------------------------------
 *	This function is called to resolve the base memory adresse
 *	for POINTER MEMBER variables.
 *
 *	It receives the variable identity which provides base information
 *	for the client member variable.
 *
 *	It returns the base memory adresse from which the member is
 *	is defined.
 *
 *	( This is a recursive function ! ! ! )
 */

EXAWORD	DynamicLength;

#ifdef	INTELASM2

/*	Prototype to function in MOTOR.ASM	*/
/*	----------------------------------	*/
BPTR	resolve_member( EXAWORD );

#else	/* PURE 'C' VERSIONS */	
	/* ----------------- */

BPTR	resolve_member( work )
EXAWORD	work;
{
	BPTR	ldesc;
	BPTR	lmem;
	BPTR	rptr;
	EXAWORD	type;

	/* Calculate Variable Table Descriptor Real Adresse */
	/* ------------------------------------------------ */
	if ( work & ISLOCAL ) {
		ldesc = ( LocalDataTable + (work & TOGLOBAL));
		lmem  = LocalDataSegment;
		}
	else	{
		ldesc = ( GlobalDataTable + work);
		lmem  = GlobalDataSegment;
		}

	/* Ensure Reference to Dynamic Variable */
	/* ------------------------------------ */
	if (! ((type = Tcodeword((ldesc))) & ISDYNAMIC ))
		return((BPTR) 0);

	/* Check for Reference to a member */
	/* ------------------------------- */
	if (!( type & ISMEMBER )) 
	{
		/* Add in Offset to final base memory */
		/* ---------------------------------- */
		lmem += (Tcodeword((ldesc + WORDSIZE)));
		ldesc += WORDSIZE;

	}
	else
	{
		/* Resolve Base Memory Reference for this Member */
		/* --------------------------------------------- */
		lmem = (resolve_member( (Tcodeword((ldesc+WORDSIZE)))) + (Tcodeword((ldesc + (2* WORDSIZE)))));
		ldesc += ( 2 * WORDSIZE );

		/* If this Member is not a pointer then Base is OK as is */
		/* ----------------------------------------------------- */
		if (!(type & ISPOINTER))
			return( lmem );

		}

	/* Return Pointer at Base Memory Location (MACRO) */
	/* ---------------------------------------------- */
	rptr = (TcodeGetPointer((lmem)));

	if ( *lmem == ALLOCATED_POINTER )
		DynamicLength = Tcodeword( (rptr-WORDSIZE) );
	else	
		DynamicLength = Tcodeword( ldesc ) ;

	return( rptr );
}

		/* -------- */
#endif	/* INTELASM */
		/* -------- */

EXAWORD	workfield=0;

BPTR	resolve_pointer( awdesc, awptr, awtyp, reg )
BPTR	awdesc;
BPTR	awptr;
EXAWORD	awtyp;
EXAWORD	reg;
{
	EXAWORD	temp;
	EXAWORD	temp2;

	/* Establish Base Pointer location */
	/* ------------------------------- */
	temp = Tcodeword( awdesc ); awptr += temp; awdesc += WORDSIZE;

#ifdef	POINTER_ARRAYS

	/* Detect and collect Index control information */
	/* -------------------------------------------- */
	if (awtyp & NDX1st) { 
		temp = ireg [reg];
		PtrIndexCheck( temp , awdesc );
		awptr += ( 5 * ( temp - 1 ) );
		if (awtyp & NDX2nd) {
			temp = areg [reg];
			temp2 = Tcodeword( awdesc); awdesc += WORDSIZE;
			PtrIndexCheck( temp , awdesc );
			awptr += ( (temp2 * 5) * ( temp - 1 ) );
			}
		}
#endif
	/* Return Final Pointer after collection */
	/* ------------------------------------- */
	if ( awptr )
		workfield=*awptr;
	else	
		workfield=0;
	return((awptr = TcodeGetPointer( (awptr) )));
}

#endif

#include "exglfe.c"	/* Global Local file and extended Variables	*/

EXAWORD	argtyp(vardex)
EXAWORD	vardex;
{
	if (vardex & ISLOCAL)
		return( ((EXAWORD) *(LocalDataTable + (vardex & TOGLOBAL))) & 3);
	else 
		return( ((EXAWORD) *(GlobalDataTable + vardex)) & 3);
}

#ifndef INTELASM2

#define	VERSION666_I32 

/* #BG 13/03/12
	Avec le Traducteur 32b, toutes les constantes numeriques sont cod�es sur 4 octets,
	avec le Traducteur 16b, toutes les constantes numeriques sont cod�es sur 2 octets.
	I32666 influe sur le type/longueur des constantes num�riques (#,%,:), cf argset(): 
	2 si I32666 vaut 0, 4 si I32666 vaut 1.
	Mais si I32666 vaut 0, quid des constantes r�ellement sur 3 ou 4 octets?
	Rq: La valeur de I32666 est modifiable par un Event 998, cf set_argset_special().

#ifdef VERSION666
	EXAWORD	I32666=1;
#else
	EXAWORD	I32666=0;
#endif
*/
#ifdef	ABAL64
EXAWORD	I32666=0;
#else
EXAWORD	I32666=0;
#endif

VOID	set_argset_special(v)
EXAWORD	v;
{
	I32666=v;
	return;
}

EXAWORD	get_argset_special()	{	return( I32666 );	}

/*	------	*/
/*	argset	*/
/*	------	*/
EXAWORD	argset(x,xvr,xset)
EXAWORD	x,xvr,xset;
{
	 register EXAWORD work;
	 register EXAWORD awtyp;
	 register BPTR  awdesc;
	 BPTR	 awptr;
	 EXAWORD awlen;
	 BINAIRE awval;
	 EXAWORD temp;
	 EXAWORD reg,temp2;
	 EXAWORD memref=1;
	 workfield = 0;

	switch ( x )
	{
	case 0 : /* IValue in tcode */
		 /* --------------- */
		switch ( xset )
		{
		case 0  : return(SOFTERROR);

#ifdef	VERSION666_I32

		/* --------------------------------------------------------- */
		/* IJM : 18/11/2003 : trying to find a solution for alliance */
		/* for 16 bit limit failure in 32 bit mode		     */
		/* 	CONV(CONV(v% and /7FFF) - CONV(v% and /8000))	     */
		/* --------------------------------------------------------- */

		/* --------------------------------------------------------- */
		/* If this code is activated several important test programs */
		/* go crazy, cbtsttre, testeur : its a shame since this is   */
		/* the way it should be for true 32 bit operation	     */
		/* the bug fix alternative is limiting for several reasons   */
		/* too bad huh : compatibillity 			     */
		/* --------------------------------------------------------- */

		/* ------------------------------------------- */
		/* Better Integer handling for Dual Tcode Mode */
		/* NB: This now respects the sign flag for 16  */
		/* bit integers which may expand to 32bit sign */
		/* or to the new OPEN ABAL 64bit types.	       */
		/* ------------------------------------------- */

		case 1	: 
			workval1 = Tcodeword( fdex );
			if ( I32666 ) 
			{
				if ( WORDSIZE > 4 )
				{
					worktyp1 = VARB_INT64;
					worklen1 = (4*ABALWORDSIZE);
				}
				else if ( WORDSIZE > 2 ) 
				{
					worktyp1 = VARB_INT32;
					worklen1 = (2*ABALWORDSIZE);
				}
				else	
				{
					worktyp1 = VARB_INT16;
					worklen1 = ABALWORDSIZE; 
				}	
			}
			else	
			{
				worktyp1 = 1; 
				worklen1 = 2;
			}
			break;

		case 2	: 
			workval2 = Tcodeword( fdex );
			if ( I32666 ) 
			{
				if ( WORDSIZE > 4 )
				{
					worktyp2 = VARB_INT64;
					worklen2 = (4*ABALWORDSIZE);
				}
				else if ( WORDSIZE > 2 ) 
				{
					worktyp2 = VARB_INT32;
					worklen2 = (2*ABALWORDSIZE);
				}
				else	
				{
					worktyp2 = VARB_INT16;
					worklen2 = ABALWORDSIZE; 
				}	
			}
			else	{
				worktyp2 = 1; 
				worklen2 = 2;
			}
			break;

		case 3	: 
			workval3 = Tcodeword( fdex );
			if ( I32666 ) 
			{
				if ( WORDSIZE > 4 )
				{
					worktyp3 = VARB_INT64;
					worklen3 = (4*ABALWORDSIZE);
				}
				else if ( WORDSIZE > 2 ) 
				{
					worktyp3 = VARB_INT32;
					worklen3 = (2*ABALWORDSIZE);
				}
				else	
				{
					worktyp3 = VARB_INT16;
					worklen3 = ABALWORDSIZE; 
				}	
			}
			else	
			{
				worktyp3 = 1; 
				worklen3 = 2;
			}
			break;
#else
		/* --------------------------------- */
		/* this is the code prior to ABAL 32 */
		/* --------------------------------- */
		case 1  : workval1 = Tcodeword( fdex ); worktyp1 = 1; worklen1 = 2; break;
		case 2  : workval2 = Tcodeword( fdex ); worktyp2 = 1; worklen2 = 2; break;
		case 3  : workval3 = Tcodeword( fdex ); worktyp3 = 1; worklen3 = 2; break;
#endif
		}
		fdex += WORDSIZE; ExFlgSgn = 0;
		return(GOODRESULT);

	case 1 : /* Conptr in tcode	*/
		switch ( xset )
		{
		case 0 : return(SOFTERROR);
		case 1 : 
			workptr1 = (TcodeConstants + (Tcodeword( fdex )));
			while (1) 
			{
				if ((worklen1 = (EXAWORD) *(workptr1++)))
					worktyp1 = VARB_STR;			
				else if (((worklen1 = (EXAWORD) *(workptr1++)) & 0x0080)) 
				{
					workptr1 = (GlobalConstants + Tcodeword((workptr1))); 
					continue;
				}
				else	worktyp1 = VARB_BCD;
				break;
			}
			break;

		case 2 : 
			workptr2 = (TcodeConstants + (Tcodeword( fdex )));
			while (1) 
			{
				if ((worklen2 = (EXAWORD) *(workptr2++)))
					worktyp2 = VARB_STR;			
				else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) 
				{
					workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
					continue;
				}
				else	worktyp2 = VARB_BCD;
				break;
			}
			break;

		case 3 : 
			workptr3 = (TcodeConstants + (Tcodeword( fdex )));
			while (1) 
			{
				if ((worklen3 = (EXAWORD) *(workptr3++)))
					worktyp3 = VARB_STR;			
				else if (((worklen3 = (EXAWORD) *(workptr3++)) & 0x0080)) 
				{
					workptr3 = (GlobalConstants + Tcodeword((workptr3))); 
					continue;
				}
				else	worktyp3 = VARB_BCD;
				break;
			}
			break;
		}
		fdex += WORDSIZE; ExFlgSgn = 0;
		return(GOODRESULT);

	case 2 : /* Varptr in tcode	*/
 		work = Tcodeword( fdex); fdex +=WORDSIZE; reg  = 0;
		break;
	case 3 : /* Reg_id in tcode	*/
		reg  = (EXAWORD) *(fdex++);
		work = (EXAWORD) freg [reg];
		x    = (EXAWORD) xreg [reg];
		break;
	case 4 : /* Reg_id in 2nd Arg	*/
		reg = xvr; work = freg [reg]; x = xreg [reg];
		break;
	case 5 : /* Varptr in 2nd Arg	*/
		work = xvr; reg = 0; x = VARIABLE;
		break;
	case 6 : /* Conptr in 2nd Arg	*/
		work = xvr; reg = 0; x = KONSTANT;
		break;
	case 7 : /* Tmpptr in 2nd Arg	*/
		work = xvr; reg = 0; x = TEMPDESC;
		break;
	default : /* God knows what !	*/
		err_val = ABAL_TCODCODE;
		return(SOFTERROR);
	}

	/*	Evaluate the pointer type	*/
	/*	-------------------------	*/

	switch ( x )
	{
	case IMMEDIAT :
		switch ( xset )
		{
		case 0  : 
#ifdef	VERSION666_I32
		case 1  :
			workval1 = work;
			if ( I32666 ) 
			{
				if ( WORDSIZE > 4 )
				{
					worktyp1 = VARB_INT64;
					worklen1 = (4*ABALWORDSIZE);
				}
				else if ( WORDSIZE > 2 ) 
				{
					worktyp1 = VARB_INT32;
					worklen1 = (2*ABALWORDSIZE);
				}
				else	
				{
					worktyp1 = VARB_INT16;
					worklen1 = (ABALWORDSIZE);
				}
			}
			else	
			{
				worktyp1 = 1;
				worklen1 = 2;
			}
			break;
		case 2  : 
			workval2 = work;
			if ( I32666 ) 
			{
				if ( WORDSIZE > 4 )
				{
					worktyp2 = VARB_INT64;
					worklen2 = (4*ABALWORDSIZE);
				}
				else if ( WORDSIZE > 2 ) 
				{
					worktyp2 = VARB_INT32;
					worklen2 = (2*ABALWORDSIZE);
				}
				else	
				{
					worktyp2 = VARB_INT16;
					worklen2 = (ABALWORDSIZE);
				}
			}
			else	
			{
				worktyp2 = 1;
				worklen2 = 2;
			}
			break;
		case 3  :
			workval3 = work;
			if ( I32666 ) 
			{
				if ( WORDSIZE > 4 )
				{
					worktyp3 = VARB_INT64;
					worklen3 = (4*ABALWORDSIZE);
				}
				else if ( WORDSIZE > 2 ) 
				{
					worktyp3 = VARB_INT32;
					worklen3 = (2*ABALWORDSIZE);
				}
				else	
				{
					worktyp3 = VARB_INT16;
					worklen3 = (ABALWORDSIZE);
				}
			}
			else	
			{
				worktyp3 = 1;
				worklen3 = 2;
			}
			break;
#else
		case 1	: workval1 = work; worktyp1 = 1; worklen1 = 2; break;
		case 2  : workval2 = work; worktyp2 = 1; worklen2 = 2; break;
		case 3  : workval3 = work; worktyp3 = 1; worklen3 = 2; break;
#endif
		}
		ExFlgSgn = 0; return(GOODRESULT);

	case KONSTANT :
		switch ( xset )
		{
		case 0 : return(SOFTERROR);
		case 1 : workptr1 = (TcodeConstants + work);
			while (1) 
			{
				if ((worklen1 = (EXAWORD) *(workptr1++)))
					worktyp1 = VARB_STR;			
				else if (((worklen1 = (EXAWORD) *(workptr1++)) & 0x0080)) 
				{
					workptr1 = (GlobalConstants + Tcodeword((workptr1))); 
					continue;
				}
				else	worktyp1 = VARB_BCD;
				break;
			}
			break;
		case 2 : workptr2 = (TcodeConstants + work);
			while (1) 
			{
				if ((worklen2 = (EXAWORD) *(workptr2++)))
					worktyp2 = VARB_STR;			
				else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) 
				{
					workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
					continue;
				}
				else	worktyp2 = VARB_BCD;
				break;
			}
			break;
		case 3 : workptr3 = (TcodeConstants + work);
			while (1) 
			{
				if ((worklen3 = (EXAWORD) *(workptr3++)))
					worktyp3 = VARB_STR;			
				else if (((worklen3 = (EXAWORD) *(workptr3++)) & 0x0080)) 
				{
					workptr3 = (GlobalConstants + Tcodeword((workptr3))); 
					continue;
				}
				else	worktyp3 = VARB_BCD;
				break;
			}
			break;
		}
		ExFlgSgn = 0;
		return(GOODRESULT);

	case PTRSTR   :
		awptr = preg [reg]; awlen = lreg [reg]; awtyp = VARB_STR;
		break;

	case PTRBCD   :
		awptr = preg [reg]; awlen = lreg [reg]; awtyp = VARB_BCD;
		break;
	case VARIABLE :
		/* Separate Global and Local references */
		/* ------------------------------------ */
		if (work & ISLOCAL) 
		{	
			awdesc = (LocalDataTable + (work & TOGLOBAL));
			awptr  = LocalDataSegment;
		}
		else
		{
			awdesc = (GlobalDataTable + work); 
			awptr = GlobalDataSegment; 
		}

		/* Collect variable type description */
		/* --------------------------------- */
		awtyp = Tcodeword( awdesc ); awdesc += WORDSIZE;

		/* Test for EXALONG pointer type variables */
		/* ------------------------------------ */

		if (awtyp & SPECIALE)
		{
			if (awtyp & ISDYNAMIC)
			{ 
				resolve_pointer_member( awdesc, awptr, awtyp );
				if ( workfield )
				{ 
					memref = workfield; 
				}
			}
			else if (awtyp & ISETENDU)
			{
				if (readhuge(awtyp,awdesc,xset,reg) == 0)
				{ 
					return(SOFTERROR); 
				}
				return(GOODRESULT);
			}	
			else
			{	
				if ( extvarb(awtyp,awdesc,xset,reg) == 0)
				{ 
					return(SOFTERROR);
				} 
				return(GOODRESULT);
			}
		}
		else 	
		{	
			/* Collect and Add short offset for this variable */
			/* ---------------------------------------------- */
			awptr += (Tcodeword( awdesc )); awdesc += WORDSIZE;
		}

		/* Perform type dependant Length collection */
		/* ---------------------------------------- */
		switch ( awtyp & VARB_ISOL ) 
		{
		case VARB_FOUR :
		case VARB_INT8 :
			awlen = 1;
			break;
		case VARB_INT16 : 
			awlen = (ABALWORDSIZE); 
			break;
		case VARB_INT32 : 
			awlen = (2*ABALWORDSIZE); 
			break;
		case VARB_INT64 : 
			awlen = (4*ABALWORDSIZE); 
			break;

		default:
			 awlen = Tcodeword( awdesc); 
			 awdesc += WORDSIZE;
		}

		/* Detect and collect Index control information */
		/* -------------------------------------------- */
		if (awtyp & NDX1st)
		{
			temp = ireg [reg];
			IndexCheck( temp , awdesc );
			awptr += ( awlen * ( temp - 1 ) );
			if (awtyp & NDX2nd)
			{
				temp = areg [reg];
				temp2 = Tcodeword( awdesc); awdesc += WORDSIZE;
				IndexCheck( temp , awdesc );
				if ( awptr )
				{
					awptr += ( (temp2 * awlen) * ( temp - 1 ) );
				}
			}
		}
	
		/* Detect and Establish Register pointer to string types */
		/*  ---------------------------------------------------- */
		if (( reg > 0 ) && ((awtyp & VARB_STR ) > VARB_INT16)) 
		{ 
			preg [reg] = awptr; 
			lreg [reg] = awlen; 
			xreg [reg] = ((awtyp & VARB_ISOL) | PTRSTATUS); 
		}
	
		awtyp &= VARB_ISOL;	/* Limit Arguament data type	*/

		/* Perform Integer corrections if required */
		/* --------------------------------------- */
		switch (awtyp) 
		{
		case VARB_FOUR	:
		case VARB_INT8  : 
			if ( ExFlgSgn == 1 ) {
				awval = (EXAWORD) *((BPTR) awptr); 
				}
			else 	{
				awval = (BINAIRE) ReadSchar( awptr );
				}
			break;
	
		case VARB_INT16 :
			if ( ExFlgSgn == 1 ) {
				awval = (EXAWORD) (balgetw(awptr) & 0x00FFFF);
				}
			else 	{
				awval = (BINAIRE) balgetw(awptr);
				}
			break;
		case VARB_INT32 :
			awval = balgetl(awptr);
			break;
		case VARB_INT64 :
			awval = balget64(awptr);
			break;
		}
		break;

	case TEMPDESC :
		/* Descripteur temporaire */
		/* ---------------------- */
		awptr = TcodeByteStack + work; 
		awtyp = Tcodeword( awptr); awptr += WORDSIZE;
		awlen = Tcodeword( awptr); awptr += WORDSIZE;
		awtyp &= VARB_ISOL;
		break;

	case CHARONLY  :
		awval = (BINAIRE) work; 
		awtyp = VARB_INT8;
		awlen = 1;
		awptr = (BPTR) 0;
		break;
	}

	ExFlgSgn = 0;
	switch ( xset ) 
	{
	case 1 : workptr1 = awptr; worklen1 = awlen; 
		 worktyp1 = awtyp; workval1 = awval;
		 break;
	case 2 : workptr2 = awptr; worklen2 = awlen; 
		 worktyp2 = awtyp; workval2 = awval;
		 break;
	case 3 : workptr3 = awptr; worklen3 = awlen; 
		 worktyp3 = awtyp; workval3 = awval;
		 break;
	default: return(SOFTERROR);
	}
	return(memref);
}

#endif

/*	Evaluates an arguament descripteur SET 1
 *	----------------------------------------
 */

EXAWORD argset1(x,xvr)
EXAWORD x;		/* Descripteur d'arguament	*/
			/* 0 = Integer dans T-code	*/
			/* 1 = Pointeur Constant	*/
			/* 2 = Pointeur Variable	*/
			/* 3 = Registre interpretation  */
			/* 4 = Register id is 2nd Arg	*/
			/* 5 = Variable Ptr is 2nd Arg  */
EXAWORD	xvr;		/* Second arguament may contain Register ID */
			/* Or actual Variable pointer	*/
{
	return(argset(x,xvr,1));
}

/*	Evaluates an arguament descripteur SET 2
 *	----------------------------------------
 */

EXAWORD argset2(x,xvr)
EXAWORD x;		/* Descripteur d'arguament	*/
			/* 0 = Integer dans T-code	*/
			/* 1 = Pointeur Constant	*/
			/* 2 = Pointeur Variable	*/
			/* 3 = Registre interpretation  */
			/* 4 = Register id is 2nd Arg	*/
			/* 5 = Variable Ptr is 2nd Arg  */
EXAWORD	xvr;		/* Second arguament may contain Register ID */
			/* Or actual Variable pointer	*/
{
	return(argset(x,xvr,2));
}

/*	Evaluates an arguament descripteur SET 3
 *	----------------------------------------
 */

EXAWORD argset3(x,xvr)
EXAWORD x;		/* Descripteur d'arguament	*/
			/* 0 = Integer dans T-code	*/
			/* 1 = Pointeur Constant	*/
			/* 2 = Pointeur Variable	*/
			/* 3 = Registre interpretation  */
			/* 4 = Register id is 2nd Arg	*/
			/* 5 = Variable Ptr is 2nd Arg  */
EXAWORD	xvr;		/* Second arguament may contain Register ID */
			/* Or actual Variable pointer	*/
{
	return(argset(x,xvr,3));
}

EXAWORD argsetw(x,xvr)
EXAWORD x;		/* Descripteur d'arguament	*/
			/* 0 = Integer dans T-code	*/
			/* 1 = Pointeur Constant	*/
			/* 2 = Pointeur Variable	*/
			/* 3 = Registre interpretation  */
			/* 4 = Register id is 2nd Arg	*/
			/* 5 = Variable Ptr is 2nd Arg  */
			/* 6 = Register ID 2nd Arg	*/
EXAWORD	xvr;		/* Second arguament may contain Register ID */
			/* Or actual Variable pointer	*/
{
	register EXAWORD work,temp;
	EXAWORD reg,temp2;
	EXAWORD memref=1;

	workfield=0;

	/*	Establish the Pointer wrt to arguament source
	 *	---------------------------------------------
	 */

	switch ( x )
	{
	case 0 : /* IValue in tcode	*/
	case 1 : /* Conptr in tcode	*/
	case 2 : /* Varptr in tcode	*/
		work = Tcodeword( fdex); 
		fdex +=WORDSIZE; reg  = 0;
		break;
	case 3 : /* Reg_id in tcode	*/
		reg  = (EXAWORD) *(fdex++);
		temp = xvr & 0x007F;
		work =  ((xvr & 0x0080) >> 7) + 2;
		StackCheck( ( temp + (WORDSIZE * 2) ));
		xreg [reg] = TEMPDESC; freg [reg] = worktop;
		workptr1 = (TcodeByteStack + worktop);
		worktop += (temp + (WORDSIZE * 2));
		TcodePmot( workptr1 , work ); workptr1 += WORDSIZE;
		TcodePmot( workptr1 , temp ); workptr1 += WORDSIZE; 
		worktyp1 = work; worklen1 = temp; workval1 = 0;
		return(GOODRESULT);
	case 4 : /* Register immediate Evaluate contents corectly ! */
		reg = xvr; work= freg [reg]; x = xreg [reg]; 
		break;
		case 5 : /* Varptr in 2nd Arg	*/
		work = xvr; reg = 0; x = VARIABLE;
		break;
	case 6 : /* Register immediate Force temp descriptor */
#ifdef	VERSION666
		if ( worklen1 >= 0xFFFFFFF0 ) {
#else
		if ( worklen1 >= 0xFFF0 ) {
#endif
			err_val = 114;
			return( SOFTERROR );
			}
		 StackCheck( (worklen1 + (2 * WORDSIZE)) );	
		 freg [xvr] = worktop; xreg [xvr] = TEMPDESC;
		 workptr1 = (TcodeByteStack + worktop);
		 TcodePmot( workptr1 , worktyp1); workptr1 += WORDSIZE;
		 TcodePmot( workptr1 , worklen1); workptr1 += WORDSIZE;
		 worktop += (worklen1 + ( 2 * WORDSIZE ));
		 return(GOODRESULT);
	case 7 : /* Tmpptr in 2nd Arg	*/
		work = xvr; reg = 0; x = TEMPDESC;
		break;
	default : /* God knows what !	*/
		err_val = ABAL_TCODCODE;
		return(SOFTERROR);
	}

	/*	Evaluate the pointer type
	 *	-------------------------
	 */

	switch ( x ) 
	{
	case IMMEDIAT : 
		workval1 = work; 
		worktyp1 = x;
		return(GOODRESULT);
	case KONSTANT : 
		err_val  = ABAL_TCODCODE;
		return(SOFTERROR);
	case PTRSTR   :
		workptr1 = preg [reg]; worklen1 = lreg [reg]; worktyp1 = VARB_STR;
		break;
	case PTRBCD   :
		workptr1 = preg [reg]; worklen1 = lreg [reg]; worktyp1 = VARB_BCD;
		break;
	case VARIABLE :
		if ( (work & ISLOCAL) != 0) {	/* Variable Locale */
			descptr = LocalDataTable + (work & TOGLOBAL);
			workptr1 = LocalDataSegment;
			}
		else 	{
			descptr = (GlobalDataTable + work); 
			workptr1 = GlobalDataSegment; 
			}

		worktyp1 = Tcodeword( descptr); descptr += WORDSIZE;

		if (( worktyp1 & SPECIALE) != 0) 
		{
			/* Test for DYNAMIC allocation variable */
			/* ------------------------------------ */
			if (worktyp1 & ISDYNAMIC) 
			{ 
				resolve_pointer_member( descptr, workptr1, worktyp1 );
				if ( workfield )
				{
					memref = workfield;
				}
			}
			else
			{
				if ((worktyp1 & ISETENDU) != 0 )
				{
					/* FIELD=E */
					if (readhuge(worktyp1,descptr,0,reg) == 0) 
						return(SOFTERROR);
				}	
				else
				{
					/* FIELD=NL */
					extwrite |= 0x0080;
					if ( extvarb(worktyp1,descptr,0,reg) == 0) 
						return(SOFTERROR);
					extwrite &= 0x007F;
				}
				return( GOODRESULT );
			}
		}
		else 	
		{
			workptr1 += (Tcodeword( descptr)); descptr += WORDSIZE;
		}

		switch ( worktyp1 & VARB_ISOL )
		{
		case VARB_FOUR  :
		case VARB_INT8  : 
			worklen1 = 1;
			break;
		case VARB_INT16 : 
			worklen1 = ABALWORDSIZE;
			break;
		case VARB_INT32 : 
			worklen1 = (2*ABALWORDSIZE);
			break;
		case VARB_INT64 : 
			worklen1 = (4*ABALWORDSIZE);
			break;
		default		:
			worklen1 = Tcodeword( descptr); 
			descptr += WORDSIZE;
		}

		if (( worktyp1 & NDX1st) != 0 )
		{
			temp = ireg [reg];
			IndexCheck(temp,descptr);
			workptr1 += ( worklen1 * ( temp - 1 ) );
			if (( worktyp1 & NDX2nd) != 0 )
			{
				temp = areg [reg];
				temp2 = Tcodeword( descptr); 
				descptr += WORDSIZE;
				IndexCheck(temp,descptr);
				workptr1 += ( (temp2 * worklen1) * ( temp - 1 ) );
			}
		}
		
		if (( reg > 0 ) && ((worktyp1 & VARB_STR) > VARB_INT16))
		{ 
			preg [reg] = workptr1; 
			lreg [reg] = worklen1; 
			xreg [reg] = ((worktyp1 & VARB_ISOL) | PTRSTATUS); 
		}

		/* Limit to basic data type */
		/* ------------------------ */
		worktyp1 &= VARB_ISOL;	

		switch (worktyp1)
		{
		case VARB_FOUR	:
		case VARB_INT8  : 
			workval1 = (BINAIRE) ReadSchar( workptr1 );
			break; 
		case VARB_INT16 :
			workval1 = balgetw(workptr1);
			break;
		case VARB_INT32 : 
			workval1 = balgetl(workptr1);
			break;
		case VARB_INT64 : 
			workval1 = balget64(workptr1);
			break;
		}
		break;

	/*	----------------------------------	*/
	/*	END OF ARGSETW : VARIABLE ANALYSIS	*/
	/*	----------------------------------	*/

	case TEMPDESC : /* Descripteur temporaire */
		workptr1 = (TcodeByteStack + work);
		worktyp1 = Tcodeword( workptr1); workptr1 += WORDSIZE;
		worklen1 = Tcodeword( workptr1); workptr1 += WORDSIZE;
	}

	return(memref);		/* Good result of operand preparation */
}

EXAWORD argsetx(xv,xr)
EXAWORD xv;	/* variable */
EXAWORD	xr;	/* register */
{ 
	register EXAWORD work,temp;
	EXAWORD reg,temp2;
	EXAWORD memref=1;
	EXAWORD x;

	workfield=0;
	work = xv;
	reg  = xr;
	x = VARIABLE;

	switch ( x )
	{
	case IMMEDIAT : 
		workval1 = work; 
		worktyp1 = x; 
		return(GOODRESULT);
	case KONSTANT : 
		err_val  = ABAL_TCODCODE;
		return(SOFTERROR); 
	case PTRSTR   :
		workptr1 = preg [reg]; worklen1 = lreg [reg]; worktyp1 = VARB_STR;
		break;
	case PTRBCD   :
		workptr1 = preg [reg]; worklen1 = lreg [reg]; worktyp1 = VARB_BCD;
		break;
	case VARIABLE :
		if ( (work & ISLOCAL) != 0)
		{	
			/* Variable Locale */
			descptr = LocalDataTable + (work & TOGLOBAL);
			workptr1 = LocalDataSegment;
		}
		else 	
		{
			descptr = (GlobalDataTable + work); 
			workptr1 = GlobalDataSegment; 
		}

		worktyp1 = Tcodeword( descptr); 
		descptr += WORDSIZE;

		if (( worktyp1 & SPECIALE) != 0) 
		{

			/* Test for DYNAMIC allocation variable */
			/* ------------------------------------ */
			if (worktyp1 & ISDYNAMIC)
			{ 

				resolve_pointer_member( descptr, workptr1, worktyp1 );
				if ( workfield ) { memref = workfield; }

			}
			else
			{
				if ((worktyp1 & ISETENDU) != 0 )
				{
					/* FIELD=E */
					if (readhuge(worktyp1,descptr,0,reg) == 0) 
						return(SOFTERROR);
				}	
				else
				{
					/* FIELD=NL */
					extwrite |= 0x0080;
					if ( extvarb(worktyp1,descptr,0,reg) == 0) 
						return(SOFTERROR);
					extwrite &= 0x007F;
				}
				return( GOODRESULT );
			}
		}
		else
		{
			workptr1 += (Tcodeword( descptr)); descptr += WORDSIZE;
		}

		switch ( worktyp1 & VARB_ISOL )
		{
		case VARB_FOUR  :
		case VARB_INT8  : worklen1 = 1; break;
		case VARB_INT16 : worklen1 = ABALWORDSIZE; break;
		case VARB_INT32 : worklen1 = (2*ABALWORDSIZE); break;
		case VARB_INT64 : worklen1 = (4*ABALWORDSIZE); break;
		default		: 
			worklen1 = Tcodeword( descptr); 
			descptr += WORDSIZE;
		}

		if (( worktyp1 & NDX1st) != 0 ) { 
			temp = ireg [reg];
			IndexCheck(temp,descptr);
			workptr1 += ( worklen1 * ( temp - 1 ) );
			if (( worktyp1 & NDX2nd) != 0 ) {
				temp = areg [reg];
				temp2 = Tcodeword( descptr); 
				descptr += WORDSIZE;
				IndexCheck(temp,descptr);
				workptr1 += ( (temp2 * worklen1) * ( temp - 1 ) );
				}
			}
		if (( reg > 0 ) && ((worktyp1 & VARB_STR) > VARB_INT16)) { 
			preg [reg] = workptr1; 
			lreg [reg] = worklen1; 
			xreg [reg] = ((worktyp1 & VARB_ISOL) | PTRSTATUS); 
			}

		/* Limit to basic data type */
		/* ------------------------ */
		worktyp1 &= VARB_ISOL;	

		switch (worktyp1)
		{
		case VARB_FOUR	:
		case VARB_INT8  : workval1 = (BINAIRE) ReadSchar( workptr1 ); break; 
		case VARB_INT16 : workval1 = balgetw(workptr1); break;
		case VARB_INT32 : workval1 = balgetl(workptr1);break;
		case VARB_INT64 : workval1 = balget64(workptr1);break;
		}
		break;

	/*	----------------------------------	*/
	/*	END OF ARGSETW : VARIABLE ANALYSIS	*/
	/*	----------------------------------	*/

	case TEMPDESC : /* Descripteur temporaire */
		workptr1 = (TcodeByteStack + work);
		worktyp1 = Tcodeword( workptr1); workptr1 += WORDSIZE;
		worklen1 = Tcodeword( workptr1); workptr1 += WORDSIZE;
	}
	return(memref);		/* Good result of operand preparation */
}

#ifdef	ABAL21

/*
 *	C R E A T E _ V A R B _ P O I N T E R ( target , source )
 *	---------------------------------------------------------
 *	Performs the update of the target REFERENCER variable with
 *	the information deduced from the source variable identifier
 *
 *	Note :	Variables in virtual memory or extended memory cannot
 *		be referenced by REFERENCER variables !
 *		Returns ERROR 118 to indicate this condition.
 *
 *		REFERENCER variables may receive the reference to a
 *		variable from another REFERENCER variable.
 *
 *		In this form the REFERENCER variable will inherit all
 *		of the characteristics of the referenced variable
 *		type, length and dimensions.
 *
 */

EXAWORD	create_reference( source, target )
EXAWORD	source;
EXAWORD	target;
{
	BPTR	sdesc;
	BPTR	sptr;
	EXAWORD	stype;

	BPTR	tdesc;
	BPTR	tptr;
	EXAWORD	ttype;

	EXAWORD	work;
	EXAWORD	reg;

	reg = 0;

	/* Calculate Source Pointers */
	/* ------------------------- */
	if (source & ISLOCAL) {	
		sdesc = (LocalDataTable + (source & TOGLOBAL));
		sptr  = LocalDataSegment;
		}
	else 	{
		sdesc = (GlobalDataTable + source); 
		sptr = GlobalDataSegment; 
		}

	/* Calculate Target Pointers */
	/* ------------------------- */
	if (target & ISLOCAL) {
		tptr  = LocalDataSegment;
		tdesc = (LocalDataTable + (target & TOGLOBAL));
		}
	else	{
	 	tdesc = (GlobalDataTable + target); 
		tptr  = GlobalDataSegment;
		}

	/* Check validity of Target */
	/* ------------------------ */
	if (!((ttype = Tcodeword((tdesc))) & ISDYNAMIC)) {
		err_val = 118;
		return( SOFTERROR );
		}

	/* Restore original Variable Type */
	/* ------------------------------ */
	ttype &= (ISDYNAMIC | ISMEMBER | ISPOINTER);

	TcodePmot((tdesc),ttype); tdesc += WORDSIZE;

	/* Allow evaluation of Redefinition pointers */
	/* ----------------------------------------- */
	if ( ttype & ISMEMBER ) {
		if (!(ttype & ISPOINTER)) {
			err_val = 118;
			return( SOFTERROR );
			}
		tptr = resolve_member((Tcodeword((tdesc))));
		tdesc += WORDSIZE;
		}

	if ( tptr == (BPTR) 0 ) {
		err_val = 118;
		return( SOFTERROR );
		}

	/* Establish Result Pointer storage pointer */
	/* ---------------------------------------- */
	tptr += Tcodeword((tdesc)); tdesc += WORDSIZE;

	/* Collect Source variable type */
	/* ---------------------------- */ 
	stype = Tcodeword( (sdesc) ); sdesc += WORDSIZE;


	if ((stype & SPECIALE) && (!(stype & ISDYNAMIC))) {
		err_val = 118;
		return( SOFTERROR );
		}

	/* Collect Base Variable Identifier */
	/* -------------------------------- */
	if ( stype & ISDYNAMIC ) {
		resolve_pointer_member( sdesc, sptr, stype );
		}
	else	{
		sptr += Tcodeword((sdesc));	
		sdesc += WORDSIZE;
		}

	if ( sptr == (BPTR) 0 ) {
		err_val = 118;
		return( SOFTERROR );
		}

	TcodePmot( (tdesc) , stype );	tdesc += WORDSIZE;
	

	/* Collect and establish data length */
	/* --------------------------------- */
	switch ( work & VARB_ISOL ) {
		case VARB_FOUR  :
		case VARB_INT8  : work = 1; break;
		case VARB_INT16 : work = ABALWORDSIZE; break;
		case VARB_INT32 : work = (2*ABALWORDSIZE); break;
		case VARB_INT64 : work = (4*ABALWORDSIZE); break;
		default		: work = Tcodeword( sdesc ); 
			 	  sdesc += WORDSIZE;
		}

	TcodePmot( (tdesc) , work );	tdesc += WORDSIZE;

	/* Collect and establish Index Limits */
	/* ---------------------------------- */
	if ( stype & NDX1st) {
		work = Tcodeword( (sdesc) ); 	sdesc += WORDSIZE;
		TcodePmot((tdesc),work);	tdesc += WORDSIZE;
		if ( stype & NDX2nd ) {
			work = Tcodeword( (sdesc) ); 	sdesc += WORDSIZE;
			TcodePmot((tdesc),work);	tdesc += WORDSIZE;
			}
		}

	/* Indicate succesful operation */
	/* ---------------------------- */
	return( GOODRESULT );

}

EXAWORD	element_reference( registre , target )
EXAWORD	registre;
EXAWORD	target;
{
	BPTR	tdesc;
	BPTR	tptr;
	EXAWORD	type;

	/* Ensure Register contains a variable */
	/* ----------------------------------- */
	if ( xreg [registre] != VARIABLE ) {
		err_val = 115;
		return( SOFTERROR );
		}

	/* Evaluate register to Workset */
	/* ---------------------------- */
	if ( argset( 4 , registre, 1 ) == SOFTERROR )
		return( SOFTERROR );

	/* Calculate Variable Table Descriptor Real Adresse */
	/* ------------------------------------------------ */
	if (target & ISLOCAL) {
		tptr  = LocalDataSegment;
		tdesc = (LocalDataTable + (target & TOGLOBAL));
		}
	else	{
	 	tdesc = (GlobalDataTable + target); 
		tptr  = GlobalDataSegment;
		}

	/* Ensure Dynamic Type Variable */
	/* ---------------------------- */
	if (!((type = Tcodeword((tdesc))) & ISDYNAMIC)) {
		err_val = 118;
		return( SOFTERROR );
		}

	/* Restore original Variable Type */
	/* ------------------------------ */
	type &= (ISDYNAMIC | ISMEMBER | ISPOINTER);

	TcodePmot((tdesc),type); tdesc += WORDSIZE;

	/* Allow evaluation of Redefinition pointers */
	/* ----------------------------------------- */
	if ( type & ISMEMBER ) {
		if (!(type & ISPOINTER)) {
			err_val = 118;
			return( SOFTERROR );
			}
		tptr = resolve_member((Tcodeword((tdesc))));
		tdesc += WORDSIZE;
		}

	if ( tptr == (BPTR) 0 ) {
		err_val = 118;
		return( SOFTERROR );
		}

	/* Establish Pointer to Pointer Storage Zone */
	/* ----------------------------------------- */
	tptr += Tcodeword((tdesc)); tdesc += WORDSIZE;

	/* Store Reference to Target Descriptor */
	/* ------------------------------------ */
	TcodePmot((tdesc), ((worktyp1 & VARB_ISOL))); tdesc += WORDSIZE;
	TcodePutPointer((tptr), workptr1 );
	TcodePmot((tdesc), worklen1);

	/* Indicate Success */
	/* ---------------- */
	return( GOODRESULT ); 

}

#endif
