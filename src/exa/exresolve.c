#ifndef	_exresolve_c
#define	_exresolve_c

#ifdef	WIN32	
#define	__SEPARATOR	';'
#define	__PATHSEP	'\\'
#define	__MAXFILENAME	512
#else
#define	__SEPARATOR	':'
#define	__PATHSEP	'/'
#define	__MAXFILENAME	512
#endif

static	BYTE	ResolveNameBuffer[__MAXFILENAME+1];

/*	--------------------------------------		*/
/*	t e s t _ f i l e p a t h ( filename )	 	*/
/*	--------------------------------------		*/
/*	This function test the provided file		*/
/*	name parameter for existance and for		*/
/*	access by the current user returning		*/
/*	a true or false condition.			*/
/*	--------------------------------------		*/
static	EXAWORD	test_filepath( BPTR nptr )
{
	EX_FILE_HANDLE	h;
	if (!( nptr ))	return(0);
	
	/* printf("test_filepath( %s )\r\n",nptr ); */
		
	if (( h = OpenTcodeFile( nptr )) == EX_UNUSED_HANDLE)
		return(0);
	else	{
		CloseTcodeFile(h);
		return(1);
		}
}

static	BPTR	test_path_component( BPTR pptr, BPTR nptr )
{
	if (!( *pptr )) return((BPTR) 0);
	if ( *(pptr+strlen(pptr)-1) == __PATHSEP )
		sprintf(ResolveNameBuffer,"%s%s",pptr, nptr );
	else	sprintf(ResolveNameBuffer,"%s%c%s",pptr,__PATHSEP, nptr );
	if (!( test_filepath( ResolveNameBuffer ) ))
		return((BPTR) 0);
	else 	{
		return( ResolveNameBuffer );
		}
}

/*	------------------------------------------------------		*/
/*	r e s o l v e _ f i l e p a t h ( filename, variable )		*/
/*	------------------------------------------------------		*/
/*	This function attempts to locate or resolve a file of		*/
/*	the name provided by the filename parameter firstly		*/
/*	'as is' and eventually using the path list value.		*/
/*	The function returns either the original name or the		*/
/*	resolved name in an internal buffer.                 		*/
/*	------------------------------------------------------		*/
static	BPTR	resolve_filepath( BPTR nptr, BPTR vptr )
{
	BPTR		eptr;
	BPTR		sptr;
	BPTR		rptr;
	EXAWORD		c;

	/* ----------------------------------- */
	/* Check for exact match for this file */
	/* ----------------------------------- */
	if (!( nptr ))				return(nptr);
	else if (!( *nptr ))			return(nptr);
	else if ( test_filepath( nptr ) ) 	return(nptr);

	/* -------------------------------- */
	/* leading path separator explicite */
	/* -------------------------------- */
	else if ( *nptr == __PATHSEP )
 		return( nptr );
#ifdef	WIN32
	/* -------------------------------- */
	/* windows device name is explicite */
	/* -------------------------------- */
	else if ( *(nptr+1) == ':' )
 		return( nptr );
#endif
	/* -------------------------------- */
	/* Check Path List Provided : value */
	/* -------------------------------- */
	else if (!( eptr = vptr ))
		return( nptr );
	/* ----------------------------- */
	/* remove preceeding white space */
	/* ----------------------------- */
	while ( *eptr == ' ' ) eptr++;

	/* ---------------------------------- */
	/* Check all component paths in order */
	/* ---------------------------------- */
	while ( strlen( eptr ) != 0 ) {

		/* -------------------------------- */
		/* scan to path component separator */
		/*	':' for unix		    */
		/*	';' for windows		    */
		/* -------------------------------- */
		for ( sptr = eptr; *sptr; sptr++)
			if ( *sptr == __SEPARATOR )
				break;

		/* ----------------------------- */
		/* save terminator and terminate */
		/* ----------------------------- */
		c = *sptr; *sptr = 0;

		/* ------------------------- */
		/* Check this path component */
		/* ------------------------- */
		if ((rptr = test_path_component( eptr, nptr )) != (BPTR) 0) {
			*sptr = c;
			return( rptr );
			}

		/* --------------------------- */
		/* restore and test terminator */
		/* --------------------------- */
		if (!(*(sptr++) =  c)) 
			break;
		else	eptr=sptr;

		/* ----------------------------- */
		/* remove preceeding white space */
		/* ----------------------------- */
		while ( *eptr == ' ' ) eptr++;
		}

	/* -------------- */
	/* No alternative */
	/* -------------- */
	return( nptr );
}

#endif	/* _exresolve_c */
	/* ------------ */


