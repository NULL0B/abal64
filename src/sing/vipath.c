public	int	system_imagepaths=0;
private	char *	system_imagework=(char *) 0;
public	char *	imagepath[10];


public	int	check_image_paths()
{
	char	*	sptr;
	int		i;
	if (!( sptr = system_imagepath ))
		return(0);
	else if (!( system_imagepaths )) {
		if ( system_imagework )
			liberate( system_imagework );
		if (!( system_imagework = allocate_string( sptr )))
			return(0);
		else	sptr = system_imagework;
		while ( *sptr != 0 ) {
			imagepath[system_imagepaths++] = sptr;

			for (i=0; *(sptr+i) != 0; i++ )
#ifdef WIN32
				if (( *(sptr+i) == ';' )
				||  ( *(sptr+i) == ',' )
				||  ( *(sptr+i) == '|' ))
					break;
#else
				if (( *(sptr+i) == ':' )
				||  ( *(sptr+i) == '|' ))
					break;
#endif

			if (!( *(sptr+i) ))
				sptr+=i;
			else	{
				*(sptr+i) = 0;
				sptr += (i+1);
				}
			}
		}
	return( system_imagepaths );
}


