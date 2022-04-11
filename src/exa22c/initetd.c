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

					/* ---------------------------- */
	xi = i;				/* Copy inner index value 	*/
					/* ---------------------------- */
	while ( a > 0 ) {		/* Outer 'Secondary index' Loop	*/
					/* ---------------------------- */
		i = xi;			/* Restore 'Primary index'	*/
					/* ---------------------------- */
		while ( i > 0 ) {	/* Inner 'Primary index' loop	*/
					/* ---------------------------- */

			/* -------------------------------------------- */
#ifndef LINEAR_MEM	/* If not linear memory (then segmented memory)	*/
			/* -------------------------------------------- */
			(VOID) xferin((bigbase = base_temp), bigvlen , bigvofs );

	/* ------------ */
#else	/* ! LINEAR_MEM */
	/* ------------ */

			bigbase = (BPTR) ( bigvbase + bigvofs);

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
			xferout(bigbase , bigvlen , bigvofs );
#endif
			/* Advance to next variable offset */
			/* ------------------------------- */
			bigvofs += bigvlen;

			i--;
			}
		a--;
		}

	/* Return final descriptor pointer */
	/* ------------------------------- */
	return( descptr );

}
