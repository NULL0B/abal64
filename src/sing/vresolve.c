#ifndef	_vresolve_c
#define	_vresolve_c

#ifdef	WIN32	
#define	__SEPARATOR	';'
#define	__PATHSEP	'\\'
#define	__MAXFILENAME	512
#else
#define	__SEPARATOR	':'
#define	__PATHSEP	'/'
#define	__MAXFILENAME	512
#endif

/*	--------------------------------------		*/
/*	t e s t _ f i l e p a t h ( filename )	 	*/
/*	--------------------------------------		*/
/*	This function test the provided file		*/
/*	name parameter for existance and for		*/
/*	access by the current user returning		*/
/*	a true or false condition.			*/
/*	--------------------------------------		*/
private	int	test_filepath( char * nptr )
{
	FILE * h;
	if (!( nptr ))	return(0);
	
	if ( style_echo ) {
		printf("test_filepath( %s )\r\n",nptr );
		}	
		
	if (!( h = fopen( nptr, "r" ) ))
		return(0);
	else	{
		fclose(h);
		return(1);
		}
}

private	char *	test_path_component( char * pptr, char * nptr )
{
	char	wbuffer[__MAXFILENAME+1];
	if (!( *pptr )) return((char *) 0);
	if ( *(pptr+strlen(pptr)-1) == __PATHSEP )
		sprintf(wbuffer,"%s%s",pptr, nptr );
	else	sprintf(wbuffer,"%s%c%s",pptr,__PATHSEP, nptr );
	if (!( test_filepath( wbuffer ) ))
		return((char *) 0);
	else 	{
		liberate( nptr );
		return( allocate_string( wbuffer ) );
		}
}

/*	------------------------------------------------------		*/
/*	r e s o l v e _ f i l e p a t h ( filename, variable )		*/
/*	------------------------------------------------------		*/
/*	This function attempts to locate or resolve a file of		*/
/*	the name provided by the filename parameter firstly		*/
/*	'as is' and eventually activetool the path list value.		*/
/*	The function returns either the original name or the		*/
/*	resolved name in an allocated zone, the original name		*/
/*	will have been freed.						*/
/*	------------------------------------------------------		*/
public 	char *	resolve_filepath( char * nptr, char * vptr )
{
	char	*	eptr;
	char 	*	sptr;
	char 	*	rptr;
	int		c;

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
		if ((rptr = test_path_component( eptr, nptr )) != (char *) 0) {
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

public	char *	resolve_stylepath( char * nptr, char * pptr )
{
	return( resolve_filepath( nptr, pptr ) );
}

public	char *	resolve_componentpath( char * nptr, char * pptr )
{
	return( resolve_filepath( nptr, pptr ) );
}

#endif	/* _vresolve_c */
	/* ----------- */


