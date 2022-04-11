#ifndef	_vpalette_c
#define	_vpalette_c

public	int 	visual_palette( char * filename, int length )
{
#ifdef WIN32

	return( load_palette_byexa( filename ) );

#else
	char *	sfic;
	char *	sptr;
	int	status=0;
	int	l;
	int	i;
	if (( filename != (char *) 0)
	&&  ((l = strlen(filename)) != 0)) {
		if (!( system_imagepath ))
			system_imagepath = configuration_item("IMAGEPATH");
		/* detect redirection of term by configuration variable */
		if ((sfic = configuration_item( filename )) != (char *) 0) {
			strcpy(fontbuffer,sfic);
			return( load_palette( fontbuffer ) );
			}
		else if ( fn_parser( filename, fontbuffer, 0x0007 ) != 0) {
			/* Palette with Path Info  */
			strcpy(fontbuffer,filename);
			return( load_palette( fontbuffer ) );
			}
		else if (!( sptr = system_imagepath )) {
			/* no alternative image paths */
			strcpy(fontbuffer,filename);
			return( load_palette( fontbuffer ) );
			}
		else if (!( check_image_paths() )) {
			/* still no alternative image paths */
			strcpy(fontbuffer,filename);
			return( load_palette( fontbuffer ) );
			}
		else	{
			for ( i=0; i < system_imagepaths; i++ ) {
				sprintf(fontbuffer,"%s%s",imagepath[i],filename);
				if (!( status = load_palette( fontbuffer ) ))
					return(0);
				else	continue;
				}
			}
		}
	return( 40 );
#endif
}

#endif	/* _vpalette_c */


