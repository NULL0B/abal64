#ifndef	_vprod_c
#define	_vprod_c

public	FILE * open_production_target( char * nptr, int type )
{
	return(fopen(nptr,"w"));
}

public 	void	close_production_target( FILE * h, char * nptr )
{
	if ( h != (FILE*) 0 )
		fclose( h );
	return;
}

#endif	/* _vprod_c */
	/* -------- */

