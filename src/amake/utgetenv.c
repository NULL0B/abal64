/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXGETENV - C				*/
/*		Date 	:	05/09/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Offers a GETENV function for Amenesik / Sologic executeurs		*/
/*	------------------------------------------------		*/
/*	IP	:	Implicite program				*/
/*	IF	:	Implicite systeme				*/
/*	LO	:	Implicite imprimante				*/
/*	------------------------------------------------		*/

BYTE	envbuf[64];	/* Buffer for Pointer Return			*/

BPTR	Mgetenv( eptr )
BPTR	eptr;
{
	WORD	x;
	WORD	i;
	WORD	l;
	BPTR	lenv;
	BPTR	getenv( BPTR );

	for (x=0; x < 3; x++ ) {
		switch ( x ) { 
			case 0 : lenv = (BPTR) "IP";	/* Implicite Programme	*/
				 break;
			case 1 : lenv = (BPTR) "IF";	/* Implicite Fichier	*/
				 break;
			case 2 : lenv = (BPTR) "LO";	/* Implicite Imprimante	*/
				 break;
			}

		/* Perform Variable Compare */
		/* ------------------------ */
		for (i=0,l=2;l>0;l--) {
			if ( *(lenv +i) != *(eptr +i) ) {
				break;
				}
			else	{
				i++;
				}
			}
		/* If Compare Success */
		/* ------------------ */
		if ((l == 0) && (i == 2) && ( *(eptr + 2) == (BYTE) 0) ) {
			(VOID) prlvolif((BPTR) envbuf , 4, x );
			envbuf[3] = (BYTE) 0;
			return((BPTR) envbuf);
			}
		else	return( getenv( (BPTR) eptr ) );
		}
	return( (BPTR) 0);		/* Return NUL Pointer	*/

}


