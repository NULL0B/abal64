/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSTD.C 				*/
/*		Date 	:	08/07/1994				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBSTD_C
#define	_EXDBSTD_C

BPTR	exadb_strcpy( rptr, sptr )
BPTR	rptr;
BPTR	sptr;
{
	BPTR	xptr;
	xptr = rptr;
	while ( *sptr )
		*(rptr++) = *(sptr++);
	*rptr = 0;
	return( xptr );
}

BPTR	exadb_strcat( rptr, sptr )
BPTR	rptr;
BPTR	sptr;
{
	BPTR	xptr;
	xptr = rptr;
	while ( *rptr )
		rptr++;
	exadb_strcpy( rptr, sptr );
	return( xptr );

}
 
EXAWORD	exadb_strlen( sptr )
BPTR	sptr;
{
	EXAWORD	l;
	for ( l = 0; *sptr; l++, sptr++);
	return( l );
}

#endif	/* _EXDBSTD_C */
	/* ---------- */
