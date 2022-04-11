/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXINIDCL.C				*/
/*		Version	:	1.4c / 2.1a				*/
/*		Date 	:	29/01/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXINIDCL_C
#define	_EXINIDCL_C

#ifdef	_ABAL_COMPILER

BPTR	_purge_extended_descriptor( type, dptr )
EXAWORD	type;
BPTR	dptr;
{
	/* Remove Long adresse */
	/* ------------------- */
	dptr += (2 * WORDSIZE);

	/* Remove String length */
	/* -------------------- */
	if (( type & 3 ) > 1)
		dptr += WORDSIZE;

	/* Remove first dimension */
	/* ---------------------- */
	if ( type & 0x0040 )
		dptr += WORDSIZE;

	/* Remove second dimension */
	/* ----------------------- */
	if ( type & 0x0020 )
		dptr += WORDSIZE;

	return( dptr );
}

BPTR	PointerInitialisation( x, desc, rb )
EXAWORD	x;
BPTR	desc;
BPTR	rb;
{
	return( purge_extended_descriptor( x, desc ) );
}

BPTR	ExtendedMemoryInit( x, desc )
EXAWORD	x;
BPTR	desc;
{
	return( purge_extended_descriptor( x, desc ) );
}

#endif

/*	---------------------------------------------------------	*/
/*	I N I T I A L I S E _ D A T A _ I M A G E ( desc, b, id )	*/
/*	---------------------------------------------------------	*/

/*

	This routine initialises the data storage space described by
	the data table provided, for either GLOBAL or LOCAL variables.

	It recieves 3 arguaments :

		1 - ID The number of variables to initialise
		    (unsigned short integer)

		2 - B The base of the pre-allocated memory area
		    to be initialised.	 
		    (unsigned char *)
	
		3 - DESC The pointer to the first Variable Descriptor in
		    the descriptor table.	
		    (unsigned char *)

	It returns the original base memory area pointer to it's caller.

	The two support functions "ExtendedMemoryInit" and 
	"PointerInitialisation" are required to initialise individual
	variables of the associated types. These two functions must  
	return the descriptor pointer to the next variable element.

*/

BPTR	initialise_data_image( desc, b, id )
BPTR	desc;
BPTR	b;
EXAWORD	id;
{
	BPTR	rb;
	BPTR	hb;
	EXAWORD	x,y,l,i,a,ll,li;
#if defined(RT_AIX) || defined(AVIION) || defined(LINUX)
	BPTR	ExtendedMemoryInit();
#else
	BPTR	ExtendedMemoryInit(EXAWORD,BPTR);
#endif
	EXAWORD	r;

	hb = rb = b;

	while ( id > 0 ) {	/* While more variables to Initialise	*/

		id--;

		/* 	Collect data type avoiding ATR bug holes	*/
		/*	----------------------------------------	*/
		do {	x = Tcodeword( desc); desc += WORDSIZE;	}

		while (( x & 0x0010 ) != 0 );

		/* Collect Variable memory adresse offset from table */
		/* ------------------------------------------------- */
		if (!(x & 0xFF00 )) {

			/* Normal Global variables (! FIELD=E etc ) */
			/* ---------------------------------------- */
			y = Tcodeword( desc); desc += WORDSIZE;

			}

		else 	{ 

#ifdef	ABAL14
#ifdef	ABAL21
			if ( x & ISDYNAMIC ) {
				if ((desc = (BPTR) PointerInitialisation( x, desc, rb )) != (BPTR) 0)
					continue;
				else	return( desc );
				}
			else 
#endif
			/* Eliminate virtual memory variables */
			/* ---------------------------------- */
			if ((x & 0x4000) != 0 ) {

				/* Variables in extended memory (FIELD=E) */
				/* -------------------------------------- */
				if ((desc = ExtendedMemoryInit(x,desc)) != (BPTR) 0)
					continue;
				else	return( desc );
				}
#endif

			/* Adjust descriptor for EXALONG variable offset */
			/* ------------------------------------------ */
			desc += (2 * WORDSIZE); y = 0;
			}

		/*	Calculate length	*/
		/*	----------------	*/
		if ((x & 0x0003) > 1 ) { 	/* If not Integer */
			l = Tcodeword( desc); 
			desc += WORDSIZE;
			}
		else 	l = ( x & 0x0001) + 1; /* Else Integer EXALONG/short */
		
		/*	Establish 1st Dimension	*/
		/*	-----------------------	*/
		if (( x & 0x0040 ) != 0 ) {	/* If first dimension	*/
			i = Tcodeword( desc); 
			desc += WORDSIZE;
			}
		else 	i = 1; 			/* Basic dimension	*/

		/*	Establish 2nd Dimension	*/
		/*	-----------------------	*/
		if (( x & 0x0020 ) != 0 ) {	/* If 2nd   dimension	*/
			a = Tcodeword( desc); 
			desc += WORDSIZE;
			}
		else 	a = 1; 			/* Basic dimension	*/

		/*	Perform if .NOT. Virtuel .NOR. ARG	*/
		/*	------------------------ --------- 	*/
		if (( x & 0x7F08 ) == 0 ) {		


			b = (BPTR) (rb + y);	

			li = i;		/* Save inner index Counter	*/

			while ( a > 0 ) {	
				a--;
				i = li;	/* Ensure inner index counter	*/
				while ( i > 0 ) {	
					i--;
					ll = l;
					switch ( x & 0x0007 ) {	
						case 0  : *((BPTR) (b++)) = 0;
							  continue;
						case 1  :
#ifdef	EVENBOUND
							 balputw(0 , b);
#else
							*((WPTR) b) = 0x0000;
#endif
							  b += WORDSIZE; 
							  continue;
						case 2  : *((BPTR) (b++)) = (EXABYTE) 0x00cf; ll--;
							  (VOID) memset(b,0x00FF,(USINT) ll);
							  b += ll; 
							  continue;
						case 3  : (VOID) memset(b,' ',(USINT) ll);
							  b += ll; 
							  continue;

#ifdef	_REGISTER_VARIABLES

						case 4  : 	
						case 5  : preg [( r = *(desc++))] = b;
							  lreg [r] = ll; freg [r] = 0;
							  xreg [r] = (x & 3);
							  b += ll; 
							  continue;
						case 6  :
						case 7  : preg [( r = *(desc++))] = b;
							  lreg [r] = ll; freg [r] = 0;
							  xreg [r] = (x & 3) | PTRSTATUS;
							  b += ll; 
							  continue;
	/* ------------------- */
#endif	/* _REGISTER_VARIABLES */
	/* ------------------- */
						default : return((BPTR) 0);
						} /* Switch end 	*/
					}	/* Next 1er Dimension	*/
				}		/* Next 2nd Dimension	*/
			}			/* Endif NOT external	*/
		}				/* Wend more variables	*/

	return( hb );

}

	/* ----------- */
#endif	/* _EXINIDCL_C */
	/* ----------- */
 
