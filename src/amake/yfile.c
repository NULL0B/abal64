#ifndef	_yfile_c
#define	_yfile_c

char	rootbuffer[256];
char	rootconvert[256];
char	modbuffer[256];
char	ficbuffer[256];

void	set_root( char * sptr )
{
	if (!( fn_parser( sptr, rootbuffer, 0x0007 ) )) {
		if ( homepath )
			strcpy(rootbuffer,homepath);
		}
	else if (( rootbuffer[0] != '/'  )  
	     &&  ( rootbuffer[0] != '\\' )){
		strcpy(rootconvert,homepath);
		strcat(rootconvert,rootbuffer);
		strcpy(rootbuffer,rootconvert);
		}
	return;
}

void	scan_illegal_characters( char * sptr )
{
	for (	; *sptr != 0; sptr++ ) {
		switch ( *sptr ) {
			case	0x0023	:
			case	0x0025	:
				*sptr = '_';
			}
		}
	return;
}

char	* use_root( char * sptr, int mode )
{
	if ( (*(sptr+0) == '.')
	&&   (*(sptr+1) == '.')
	&&   (*(sptr+2) == '/')) {
		if ( (*(sptr+3) == '.')
		&&   (*(sptr+4) == '.')
		&&   (*(sptr+5) == '/')) {
			sptr+=6;
			if ( mode )
				return( symbolic_filename(sptr));
			else	return( sptr );
			}
		else	sptr += 3;
		}
	else if ( (*(sptr+0) == '.')
	     &&   (*(sptr+1) == '/'))
		sptr+=2;
	else if ( *sptr == '.' ) {
		if ( mode )
			return( symbolic_filename(sptr));
		else	return( sptr );
		}

	sprintf( rootconvert,"%s%s",rootbuffer, sptr );
	if ( mode )
		return( symbolic_filename(rootconvert) );
	else	return( rootconvert ) ;
}


char	*	build_output_filename( struct project * pptr, char * fileroot, int * filetype )
{
	struct	section * sptr;
	struct	member * mptr;

	if ( *(fileroot+1) == ':' )
		sprintf(filebuffer,"%s",fileroot);
	else if ( *fileroot == '.' ) 
		sprintf(filebuffer,"%s",fileroot);
	else if ((( sptr = locate_postfixed_section( pptr, fileroot,".DIR")) != (struct section *) 0) 
	     &&  (( mptr = locate_member( sptr, "Output.Dir")) != (struct member *) 0)) 
		sprintf(filebuffer,"%s%s",mptr->value,fileroot);
	else if ((( sptr = locate_postfixed_section( pptr, "Project",".DIR")) != (struct section *) 0) 
	     &&  (( mptr = locate_member( sptr, "Output.Dir")) != (struct member *) 0)) 
		sprintf(filebuffer,"%s%s",mptr->value,fileroot);
	else	sprintf(filebuffer,"%s",fileroot);
	*filetype = TYPE_PROGRAM; 
	scan_illegal_characters( filebuffer );
	if ( filebuffer[0] == '.' )
		return( use_root( filebuffer,1 ) ) ;
	else	return( symbolic_filename( filebuffer ) );
}

char	*	localise_source_filename()
{
	FILE *	h;
	char *	nptr;
	char * nomfic;

	scan_illegal_characters( filebuffer );
	if ( filebuffer[0] == '.' ) {
		if (!( nptr = use_root( filebuffer,1 ) ))
			return( nptr );
		}
	else if (!( nptr = symbolic_filename( filebuffer ) ))
		return( nptr );

	if (!( nomfic = resolve_filename( nptr ) ))
		return((char *) 0);
	
	if (!( h = fopen( nomfic, "r" ) ))
		return((char *) 0);
	else	{
		fclose(h);
		return( nptr );
		}
}


char	*	build_source_filebuffer( struct project * pptr, char * fileroot )
{
	struct	section * sptr;
	struct	member * mptr;
	int	i;
	char *	nptr;

	if ( *(fileroot+1) == ':' ) {
		sprintf(filebuffer,"%s",fileroot);
		return((char *) 0);
		}
	if ( *fileroot == '.' )  {
		sprintf(filebuffer,"%s",fileroot);
		return((char *) 0);
		}

	if (( sptr = locate_postfixed_section( pptr, fileroot,".DIR")) != (struct section *) 0) {
		for ( i=0; i < 1024; i++ ) {
			sprintf(filebuffer,"Source.Dir%u",i);
			if (!( mptr = locate_member( sptr, filebuffer )) != (struct member *) 0)
				break;
			else	{
				sprintf(filebuffer,"%s%s",mptr->value,fileroot);
				if (!( nptr = localise_source_filename() ))
					continue;
				else	return( nptr );
				}
			}
		}

	if (( sptr = locate_postfixed_section( pptr, "Project",".DIR")) != (struct section *) 0) {
		for ( i=0; i < 1024; i++ ) {
			sprintf(filebuffer,"Source.Dir%u",i);
			if (!( mptr = locate_member( sptr, filebuffer )) != (struct member *) 0)
				break;
			else	{
				sprintf(filebuffer,"%s%s",mptr->value,fileroot);
				if (!( nptr = localise_source_filename() ))
					continue;
				else	return( nptr );
				}
			}
		}

	if ( sourcedir ) {
		sprintf(filebuffer,"%s%s",sourcedir,fileroot);
		return((char *) 0);
		}
	else	{
		sprintf(filebuffer,"%s",fileroot);
		return((char *) 0);
		}
}

char	*	build_source_filename( struct project * pptr, char * fileroot, int * filetype )
{
	struct	section * sptr;
	struct	member 	* mptr;
	char		* nptr;
	char		* nomfic;

	if (( nptr = build_source_filebuffer( pptr, fileroot  )) != (char *) 0) {
		*filetype = TYPE_SOURCE; 
		return(nptr);
		}
	else	{
		*filetype = TYPE_SOURCE; 
		scan_illegal_characters( filebuffer );
		if ( filebuffer[0] == '.' )
			return( use_root( filebuffer,1 ) ) ;
		else	return( symbolic_filename( filebuffer ) );
		}
}

char	*	build_module_filename( struct project * pptr, char * fileroot, int * filetype )
{
	struct	section * sptr;
	struct	member * mptr;

	if ( *(fileroot+1) == ':' )
		sprintf(filebuffer,"%s",fileroot);
	else if ( *fileroot == '.' ) 
		sprintf(filebuffer,"%s",fileroot);
	else if ((( sptr = locate_postfixed_section( pptr, fileroot,".DIR")) != (struct section *) 0) 
	     &&  (( mptr = locate_member( sptr, "Module.Dir")) != (struct member *) 0))  {
		strcpy(filebuffer,mptr->value);
		strcat(filebuffer,fileroot);
		}
	else if ((( sptr = locate_postfixed_section( pptr, "Project",".DIR")) != (struct section *) 0) 
	     &&  (( mptr = locate_member( sptr, "Module.Dir")) != (struct member *) 0)) { 
		strcpy(filebuffer,mptr->value);
		strcat(filebuffer,fileroot);
		}
	else	sprintf(filebuffer,"%s",fileroot);
	*filetype = TYPE_MODULE; 
	scan_illegal_characters( filebuffer );
	fileroot = filebuffer;
	if ( *fileroot == '.' )
		fileroot = use_root( fileroot, 0 );
	if (!( fn_parser( fileroot, modbuffer , 0x000F )))
		return( symbolic_filename( fileroot ) );
	else	{
		strcat( modbuffer, ".o" );
		return( symbolic_filename( modbuffer ) );
		}
}

char	*	build_filename( struct project * pptr, char * fileroot, int * filetype )
{
	struct	section * sptr;
	struct	member * mptr;
	char *	testroot;
	*filetype = TYPE_UNKNOWN; 

	if ( *fileroot == '.' ) 
		testroot = use_root( fileroot,0 );
	else	testroot = fileroot;

	if (!(fn_parser( testroot, filebuffer, 16|128 ))) {
		sprintf(filebuffer,"%s",fileroot);
		scan_illegal_characters( filebuffer );
		return( symbolic_filename( filebuffer ) );
		}
	else if ( compare( filebuffer,".AT") )
		return( build_output_filename( pptr, fileroot, filetype ) );
	else if ( compare( filebuffer, ".O") )
		return( build_module_filename( pptr, fileroot, filetype ) );
	else	return( build_source_filename( pptr, fileroot, filetype ) );
}

#endif	// _yfile_c

