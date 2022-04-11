#ifndef	_sysfile_c
#define	_sysfile_c

static	char	SystemFileName[256];

PUBLIC	char	*	sysfilename( char * nptr )
{
	int	i;
	for ( i=0; *(nptr+i) != 0; i++ ) 
#ifndef	UNIX
		if ((SystemFileName[i] = *(nptr+i)) == '/')
			SystemFileName[i] = '\\';
#else
		if ((SystemFileName[i] = *(nptr+i)) == '\\')
			SystemFileName[i] = '/';
#endif
	SystemFileName[i++] = 0;
	return( SystemFileName );
}




#endif	/* _sysfile_c */


