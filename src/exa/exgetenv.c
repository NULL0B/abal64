/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXGETENV - C				*/
/*		Version	:	1.4c					*/
/*		Date 	:	09/04/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Offers a GETENV function for Amenesik / Sologic executeurs		*/
/*	------------------------------------------------		*/
/*	IP	:	Implicite program				*/
/*	IF	:	Implicite fichier				*/
/*	IS	:	Implicite systeme				*/
/*	LO	:	Implicite imprimante				*/
/*	------------------------------------------------		*/

EXABYTE	envbuf[256];	/* Buffer for Pointer Return			*/


EXAWORD	prlsys_getenv( BPTR );
EXAWORD	setenv( BPTR, BPTR );
BPTR	getenv( BPTR );

EXABYTE	PrlEnvBuf[512];

BPTR	getenv( token )
BPTR	token;
{
	EXAWORD	nl;
	EXAWORD	result;
	BPTR	PrlEnvBuffer = (BPTR) PrlEnvBuf;
	memset((BPTR) PrlEnvBuf, ' ', 512 );
	*(PrlEnvBuffer + 0x0000) = 0x0009;	/* Lecture 		*/
	*(PrlEnvBuffer + 0x0009) = 1;		/* This station		*/
	*(PrlEnvBuffer + 0x000B) = 0;		/* Format Systeme	*/
	memcpy( (PrlEnvBuffer+0x000E), token, (nl = strlen(token)));
	*((WPTR) (PrlEnvBuffer + 0x000C)) = (nl+2);
	*((WPTR) (PrlEnvBuffer + 0x0001)) = (nl+14);
	*((WPTR) (PrlEnvBuffer + 0x0003)) = (512 - (nl + 14));
	*((BPTR PTR) (PrlEnvBuffer + 0x0005)) = (BPTR) (PrlEnvBuffer+nl+14);
	if (( result = prlsys_getenv( PrlEnvBuffer )) != 0)
		return((BPTR) 0);
	else	{
		result = *((WPTR) (PrlEnvBuffer+14+nl));
		*(PrlEnvBuffer + 16 + nl + result) = 0;
		return((BPTR) (PrlEnvBuffer + 16 + nl) );
		}

}

EXAWORD	setenv( token, valeur )
BPTR	token;
BPTR	valeur;
{
	EXAWORD	vl=0;
	EXAWORD	nl;
	EXAWORD	result;
	BPTR	PrlEnvBuffer = (BPTR) PrlEnvBuf;

	if (valeur == (BPTR) 0)
		return( 30 );
	if ((vl = strlen( valeur )) == 0) 	
		return( 31 );

	*(PrlEnvBuffer + 0x0000) = 0x0006; /* Ecriture	 */

	*(PrlEnvBuffer + 0x0009) = 1;		/* This station		*/
	*(PrlEnvBuffer + 0x000B) = 0;		/* Format Systeme	*/
	memcpy( (PrlEnvBuffer+0x000E), token, (nl = strlen(token)));
	*((WPTR) (PrlEnvBuffer + 0x000C)) = (nl+2);

	memcpy((PrlEnvBuffer+0x0010+nl),valeur,vl);
	*((WPTR) (PrlEnvBuffer + 0x000E +nl)) = (vl+2);

	*((WPTR) (PrlEnvBuffer + 0x0001)) = 12;
	*((WPTR) (PrlEnvBuffer + 0x0003)) = vl+nl+4;
	*((BPTR PTR) (PrlEnvBuffer + 0x0005)) = (BPTR) (PrlEnvBuffer+12);

	return( prlsys_getenv( PrlEnvBuffer ));


}


BPTR	Mgetenv( eptr )
BPTR	eptr;
{
	EXAWORD	x;
	EXAWORD	i;
	EXAWORD	l;
	BPTR	lenv;
	BPTR	getenv( BPTR );

#ifdef	ABAL14

	/* Reset Result Length field */
	/* ------------------------- */
	envbuf[0] = 0; envbuf[1] = 0;

#ifdef	ABAL21
	if ((lenv = getenv((BPTR) eptr)) != (BPTR) 0)
		return( lenv );
#else
	/* Attempt to read environnement variable using Amenesik / Sologic Function */
	/* -------------------------------------------------------------- */
	if ( prl_getenv((BPTR) eptr , (BPTR) envbuf ) == 0 ) {

		/* Collect and control Result length */
		/* --------------------------------- */
		if (( i = *((WPTR) (envbuf))) != 0 ) {

			/* Terminate String and Return Pointer to Value */
			/* -------------------------------------------- */
			envbuf[i+2] = (EXABYTE) 0; return((BPTR) & envbuf[2] );

			}

		}

#endif
#endif

	/* Check for Internal Executeur Variable */
	/* ------------------------------------- */
	for (x=0; x < 4; x++ ) {

		switch ( x ) { 

			case 0 : lenv = (BPTR) "IP";	/* Implicite Programme	*/
				 break;			/* -------------------- */
			case 1 : lenv = (BPTR) "IF";	/* Implicite Fichier	*/
				 break;			/* -------------------- */
			case 2 : lenv = (BPTR) "LO";	/* Implicite Imprimante	*/
				 break;			/* -------------------- */
			case 3 : lenv = (BPTR) "IS";	/* Implicite systeme	*/
				 break;			/* -------------------- */ 
			}

		/* Perform Variable Compare */
		/* ------------------------ */
		for (i=0,l=2;l>0;l--) {
			if ( *(lenv +i) != *(eptr +i) )
				break;
			else	i++;
			}
		/* If Compare Success */
		/* ------------------ */
		if ((l == 0) && (i == 2) && ( *(eptr + 2) == (EXABYTE) 0) ) {

			/* Implicite systeme require special handling */
			/* ------------------------------------------ */
			if ( x == 3 ) {
				(VOID) prlvolis((BPTR) envbuf , 4, x); 
				i = 4;
				}
			else	{
				/* If Variable LO or Amenesik / Sologic version > 3.3/3.sr/4.1 */
				/* ------------------------------------------------- */
				if (( check33() == 0 ) || ( x == 2 )) {

					/* Collect Station Parameter and Create Mnemonic */
					/* --------------------------------------------- */
					(VOID) prlvolif((BPTR) envbuf , 4, x ); 
					i = 4;
					}
				else	{
					/* Amenesik / Sologic 3.3 / 3.Sr or Greater and ! LO */
					/* --------------------------------------- */
					(VOID) GetSousRep((BPTR) envbuf , 255 , x );
					for ( i = 0; i < 255; i++ ) 
						if ( envbuf[i] == 0x000D ) 
							break;

					}
				}

			/* Terminate and Return pointer to value */
			/* ------------------------------------- */
			envbuf[i] = (EXABYTE) 0; return((BPTR) envbuf);
			}

		}
	return( (BPTR) 0 );
}

