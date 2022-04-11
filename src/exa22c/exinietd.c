#ifndef	_EXINIETD_C
#define	_EXINIETD_C

BPTR	ExtendedMemoryInit( vtype , descptr )
EXAWORD	vtype;
BPTR	descptr;
{
	EXAWORD	a;
	EXAWORD	i;
	EXAWORD	l;
	EXAWORD	xi;

	/* Establish Memory storage offset */
	/* ------------------------------- */
	bigvofs = ((((ULONG) (Tcodeword((descptr + WORDSIZE)))) << 16) + ((ULONG) (Tcodeword(descptr))));
	descptr += (2 * WORDSIZE);

	/* Establish Variable length */
	/* ------------------------- */
	if ((vtype & VARB_ISOL) > 1) {
		bigvlen = Tcodeword( descptr ); descptr += WORDSIZE;
		}
	else	{
		bigvlen = ((vtype & 1) + 1);
		}

	/* Collect Dimension values */
	/* ------------------------ */
	if (vtype & 0x0020) { i = Tcodeword( descptr ); descptr += WORDSIZE; }
	else		    { i = 1;					 }

	if (vtype & 0x0040) { a = Tcodeword( descptr ); descptr += WORDSIZE; }
	else		    { a = 1;					 }


#ifndef	OPTIMISER
#ifdef	ABAL21
	if (!(DiezeEtendu & 0x0004)) {
#endif						/* ---------------------------- */
		xi = i;				/* Copy inner index value 	*/
						/* ---------------------------- */
		while ( a > 0 ) {		/* Outer 'Secondary index' Loop	*/
						/* ---------------------------- */
			i = xi;			/* Restore 'Primary index'	*/
						/* ---------------------------- */
			while ( i > 0 ) {	/* Inner 'Primary index' loop	*/
						/* ---------------------------- */

				/* -------------------------------------------- */
#ifndef LINEAR_MEM		/* If not linear memory (then segmented memory)	*/
				/* -------------------------------------------- */
				if ( xferin((bigbase = TcodeByteStack), bigvlen , bigvofs ) == SOFTERROR )
					return( (BPTR) 0 );

	/* ------------ */
#else	/* ! LINEAR_MEM */
	/* ------------ */

				bigbase = (BPTR) ( ExtendedMemory + bigvofs);

	/* ---------- */
#endif	/* LINEAR_MEM */
	/* ---------- */
				/* Perform data type selection */
				/* --------------------------- */
				switch ((vtype & VARB_ISOL)) {
					case 0 : *bigbase = (EXABYTE) 0; 	 break;
					case 1 : balputw( 0 , bigbase ); break;
					case 2 : *bigbase = (EXABYTE) 0x00CF;
						 if ((l = (bigvlen - 1)) > 0 ) {
							memset((bigbase+1),0x00FF,l);
							}
						 break; 
					case 3 : memset(bigbase,' ',bigvlen);
					}
#ifndef	LINEAR_MEM
				/* Rewrite to memory if non linear memory */
				/* -------------------------------------- */
				if ( xferout(bigbase , bigvlen , bigvofs ) == SOFTERROR )
					return( (BPTR) 0 );
#endif
				/* Advance to next variable offset */
				/* ------------------------------- */
				bigvofs += bigvlen;

				i--;
				}
			a--;
			}
#ifdef	ABAL21
		}
#endif
#endif

	/* Return final descriptor pointer */
	/* ------------------------------- */
	return( descptr );

}

#endif	/* _EXINIETD_C */
	/* ----------- */
