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
	switch (vtype & VARB_ISOL) {
		case VARB_FOUR  :
		case VARB_INT8  : bigvlen = 1; break;
		case VARB_INT16 : bigvlen = ABALWORDSIZE; break;
		case VARB_INT32 : bigvlen = (2*ABALWORDSIZE); break;
		case VARB_INT64 : bigvlen = (4*ABALWORDSIZE); break;
		default		: bigvlen = Tcodeword( descptr); 
				  descptr += WORDSIZE; 
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
					case VARB_FOUR  :
					case VARB_INT8  : *bigbase = (EXABYTE) 0; break;
					case VARB_INT16 : balputw( 0 , bigbase ); break;
					case VARB_INT32 : balputl(0L , bigbase); break;
					case VARB_INT64 : balput64(0L , bigbase); break;
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
