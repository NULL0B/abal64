#ifndef	_visual_help
#define	_visual_help

private	char * 	NatRoot[8] = { "en", "fr", "it","es","de","nl","pt", "xx" };

#ifdef WIN32

int ExecuteHelp( const char* HelpFullPathName, const char* Index, const char* Navigator);

private	int	prefixed_url( char * sptr)
{
	int	i;

	if ((sptr[0]=='/') && (sptr[1]=='/'))
		return 1;

	for (i=0; (sptr[i]!=0) && (sptr[i]!=':') ; i++ );

	if ((sptr[i]==':') && (sptr[i+1]=='/') && (sptr[i+2]=='/'))
		return 1;

	return 0;
}		

public 	int	visual_help( char * sptr )
{
	char * cptr;
	int	r;
	HINSTANCE hExe;
   static char path_buffer[_MAX_PATH];
   static char drive[_MAX_PATH];
   static char dir[_MAX_PATH];
   static char fname[_MAX_PATH];
   static char ext[_MAX_PATH];

	if (!( sptr ))
		return(30);

   _splitpath( sptr, drive, dir, fname, ext );

	if ((*drive=='\0') && (*dir=='\0') && system_docpath )
		{
		// nom de fichier seul
		r = visual_national_language(-1);
		sprintf(path_buffer,"%s%s\\%s",system_docpath,NatRoot[r],sptr);
		sptr = path_buffer;
		}
	else if (!prefixed_url(sptr))
		{
		// fichier avec chemin
		strcpy(path_buffer, sptr);
		for (cptr=path_buffer; *cptr != 0; cptr++ )
			if ( *cptr == '/' )
				*cptr = '\\';
		sptr = path_buffer;
		}

	hExe = ExecuteHelp( sptr, NULL, system_navigator);
	return 0;
}

#else

private	int	prefixed_url( char * sptr)
{
	int	i;
	if ( *sptr == '/' )
		return(1);
	else	{
		for (i=0; *(sptr+i) != 0; i++ )
			if ( *(sptr+i) == ':' )
				break;
		if ( *(sptr+i) != ':' )
			return(0);
		else	return(1);
		}
}

public 	int	visual_help( char * sptr )
{
	char * command;
	char * cptr;
	char * nv;
	char * filename;
	int	r;
	if (!( sptr ))
		return(30);
	else if (!( nv = system_navigator ))
		return(30);

	if ( system_docpath != (char *) 0) {
		if (!( prefixed_url( sptr ) )) {
			r = visual_national_language(-1);
			sprintf(fontbuffer,"%s%s/%s",system_docpath,NatRoot[r],sptr);
			sptr = fontbuffer;
			}
		}

	if (!( filename = allocate_string( sptr )))
		return(27);

	else if (!( command = allocate( strlen( nv ) + strlen( filename ) + 64 ) )) {
		liberate( filename );
		return(27);
		}
	else	{
		for (cptr=filename; *cptr != 0; cptr++ )
			if ( *cptr == 0x005C )
				*cptr = '/';

		sprintf(command,"%s %s",nv, filename );

#if defined(UNIX)
		switch ( fork() ) {
			case	0	:
				system( command );
				exit(0);
			}

#elif defined(WIN32)
		system( command );

#else
		(void) close_graphics();
		system( command );
		(void) open_graphics();
#endif

		command  = liberate( command );
		filename = liberate( filename );
		return(0);
		}
}

#endif

#endif	/* _visual_help */
	/* ------------ */


