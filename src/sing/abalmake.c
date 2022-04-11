#ifndef	_abalmake_c
#define	_abalmake_c

/*	------------------------------------------	*/
/* 			ABALMAKE.C			*/
/*			----------			*/
/*	Encapsulation of the project update launch	*/
/*	mechanisms and its configuration.		*/
/*	Initial configuration information is read	*/
/*	from the centralised configuration manager	*/
/*	------------------------------------------	*/

struct	makefile_config	{
	char	*	program;
	char	*	filename;
	char	*	defines;
	char	*	output;
	int		forcebuild;
	int		showdates;
	int		touche;
	} Amake = { (char *) 0,(char *) 0,(char *) 0,(char *) 0,0,0,0 };

public	int	not_white_string( char * sptr )
{
	if (!( sptr ))		return(0);
	else if (!( *sptr ))	return(0);
	for (	; *sptr != 0; sptr++ )
		if ( *sptr != ' ' )
			return(1);
	return(0);
}
		

/*	------------------------------------------	*/
/*	r e s e t _ m a k e f i l e _ c o n f i g	*/
/*	------------------------------------------	*/
/*	Simply releases all configuration fields	*/
/*	prior to request from configuration manager	*/
/*	for reconfiguration.				*/
/*	------------------------------------------	*/

public	void	reset_makefile_config()
{
	if ( Amake.program )
		liberate( Amake.program );
	if ( Amake.defines )
		liberate( Amake.defines );
	if ( Amake.output )
		liberate( Amake.output );
	if ( Amake.filename )
		liberate( Amake.filename );
	Amake.program = Amake.filename = Amake.defines = Amake.output = (char *) 0;
	Amake.forcebuild = Amake.showdates = Amake.touche = 0;
	return;
}


/*	------------------------------------------	*/
/*	c o n f i g u r e _ m a k e f i l e ()		*/
/*	------------------------------------------	*/
/*	Receives the configuration request from 	*/
/*	the configuration manager on configuration	*/
/*	loading, file or ldap, or after modification	*/ 
/*	------------------------------------------	*/

public	void	configure_makefile()
{
	int	c;
	char *	optr;
	reset_makefile_config();
	if (!( SingConf ))
		return;
	if ( SingConf->amake.program ) 
		Amake.program = allocate_string( SingConf->amake.program );
	if ( not_white_string( SingConf->amake.path ) ) 
		Amake.output = allocate_string( SingConf->amake.path );
	if ( SingConf->amake.define )
		Amake.defines = allocate_string( SingConf->amake.define);
	if (( optr = SingConf->amake.options ) != (char *) 0) {
		while ((c = *(optr++)) != 0) {
			switch ( c ) {
				case	'b'	:
				case	'B'	:
					Amake.forcebuild=1;
					break;
				case	't'	:
				case	'T'	:
					Amake.touche=1;
					break;
				case	'd'	:
				case	'D'	:
					Amake.showdates=1;
					break;
				}
			}
		}
	return;
}

public	int	use_abal_makefile(char * aptr, int automatic)
{
	int		status;
	char	*	sptr;
	char	*	command;
	int		alen=0;
	char		xbuffer[64];

	if (!( upper_compare( aptr, "MAKEFILE" ) )) {
		if (!( fn_parser( aptr, xbuffer, 0x0010 ) ))
			return(0);
		if ((!( upper_compare( xbuffer, ".MF"  ) ))
		&&  (!( upper_compare( xbuffer, ".MAK" ) )))
			return(0);
		}

	if ( Amake.filename )
		liberate( Amake.filename );

	Amake.filename = allocate_string( aptr );

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_amake( 
				&Amake.program, 
				&Amake.filename,
				&Amake.output,  
				&Amake.defines,
				&Amake.forcebuild,
				&Amake.showdates,
				&Amake.touche ) == 27 )
			return(27);
		}

	alen = strlen( aptr );
	if ( Amake.program )
		alen += strlen( Amake.program );
	if ( Amake.defines )
		alen += strlen( Amake.defines );
	if ( not_white_string(  Amake.output ) )
		alen += strlen( Amake.output );
	alen += 64;

	if (!( command = allocate( 512 ) ))
		return(27);

	sptr = command;

	if ( Amake.program )
		sprintf(sptr,"%s ",Amake.program);
	else	sprintf(sptr,"%s ","amake");
	sptr += strlen(sptr);

	if ( Amake.forcebuild ) { 
		sprintf(sptr,"%s ","-b");
		sptr += strlen(sptr);
		}

	if ( Amake.showdates ) {
		sprintf(sptr,"%s ","-d");
		sptr += strlen(sptr);
		}

	if ( Amake.touche ) {
		sprintf(sptr,"%s ","-t");
		sptr += strlen(sptr);
		}

	/* Test for report file required */
	/* and ensure silent otherwise	 */

	if (!( not_white_string( Amake.output ) )) {
		sprintf(sptr,"%s ","-s");
		sptr += strlen(sptr);
		}

	sprintf(sptr,"%s ",aptr);
	sptr += strlen(sptr);

	if ( Amake.defines ) {
		sprintf(sptr,"%s ",Amake.defines);
		sptr += strlen(sptr);
		}

	if ( not_white_string( Amake.output ) ) {
		sprintf(sptr," > %s",Amake.output );
		sptr += strlen(sptr);
		}

	x_event(35);

#ifndef	__SING_FORK
	(void) close_graphics(og);
#endif

	status_message(command,3);	

#ifdef WIN32
	windows_create_process( command,TRUE );
#else
	if ( use_system_d() != 0 )
		status = SystemV( command );
	else 	status = system( command );
	if ( status == -1 )
		system_failure( command );

#endif

#ifndef	__SING_FORK
	(void) open_graphics();		draw_console();
#endif
	x_event(33);

	liberate( command );

	if (( Amake.output  ) &&  ( *(Amake.output) != 0)) {
		use_editor(Amake.output,0);	
		}
	return(1);
}

#endif	/* _abalmake_c */


