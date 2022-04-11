struct	visual_debug	{
	char *	tcode;
	char *	parameters;
	int	isdebug;
	char *	rootpath;
	} runtime = { (char *) 0,(char *) 0,0,(char *) 0 };


#ifdef	__SING_FORK
struct	job_control	{
	int	count;
	int	state;
	void *	previous;
	} JobMan = { 0,0, (void *) 0 };


public	void	job_catcher(int sid)
{
	return;
}

private	void	install_job_catcher()
{
	if (!( JobMan.state )) {
		JobMan.state++;
		}
	return;
}
#endif



public	int	activate_background_job( char * command )
{
	status_message(command,3);
#ifndef	__SING_FORK
	(void) close_graphics(og);
#else
	install_job_catcher();
	switch ( fork() ) {
		case	0	:
#endif
			system( command );
#ifndef	__SING_FORK

			(void) open_graphics();
			draw_console();
			status_message("completed",3);
#else
			exit(0);
		}
#endif
	return(0);
}

public	int	use_exa(char * xptr, char * fnptr, char * aptr)
{
	char *	sptr;
	char *	command;
	char *	filename;
	int	arglen=0;
	int	i;
	int	n;
	if (!( xptr ))	return(30);

	for ( i=0; *(fnptr+i) != ' '; i++ ) {
		if (!( *(fnptr+i)  ))
			break;
		else if ( *(fnptr+i) == '.' ) 
			break;
#ifdef	PROLOGUE
		else if ( *(fnptr+i) == '-' )
			break;
#endif
		}
	if (( aptr )
	&&  ( *aptr != 0)) {
		for ( arglen=0; *(aptr+arglen) != 0; arglen++);
		}

	if (!( filename = allocate( (i+16) )))
		return(0);
	else	n = i;

	for ( i=0; *(fnptr+i) != ' '; i++ ) {
		if ( i >= n )
			break;
		else if (!( *(filename + i ) = *(fnptr+i) ))
			break;
		}

	*(filename+i) = 0;
	
	if (!( command = allocate( strlen( xptr ) + strlen( filename ) + 64 + arglen ) )) {
		filename = liberate( filename );
		return(0);
		}
	else	{
		if ( arglen > 0 )
			sprintf(command,"%s %s %s",xptr, filename,aptr );
		else	sprintf(command,"%s %s",xptr, filename );

		(void) activate_background_job( command );

		command  = liberate( command );
		filename = liberate( filename );
		return(1);
		}
}

public	int	use_runtime(char * aptr, char * bptr)
{
	if (!( SingConf ))
		return(0);
	else if (!( runtime.isdebug ))
		return( use_exa( SingConf->exa.program  , aptr, bptr ) );
	else	return( use_exa( SingConf->exadb.program, aptr, bptr ) );
}

public	int	use_abal_runtime(char * nptr, int automatic)
{
	if (!( SingConf ))
		return( 0 );
	if ( nptr != (char *) 0) {
		if ( runtime.tcode )
			liberate( runtime.tcode );
		runtime.tcode = allocate_string( nptr );
		}
	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_debug_parameters(	
			&runtime.tcode,
			&runtime.parameters,
			&runtime.isdebug,
			&SingConf->exadb.program,
			&runtime.rootpath,
			&SingConf->exa.program
			 ) == 27 )
			return(0);

		}

	return( use_runtime(runtime.tcode, runtime.parameters ) );

}

#include "abalmake.c"

public	int	abal_runtime(char * aptr, int automatic)
{
	if ( use_abal_makefile( aptr, automatic ) )
		return(0);
	else if ( use_html_navigator( aptr, automatic ) )
		return( 0 );
	else	{
		runtime.isdebug = 0;
		if ( runtime.tcode )
			runtime.tcode = liberate( runtime.tcode );
		runtime.tcode = allocate_string( aptr );
		return( use_abal_runtime((char *) 0, automatic) );
		}
}

public	int	abal_debuger(char * aptr, int automatic)
{
	if ( use_abal_makefile( aptr, automatic ) )
		return(0);
	else	{
		runtime.isdebug = 1;
		if ( runtime.tcode )
			runtime.tcode = liberate( runtime.tcode );
		runtime.tcode = allocate_string( aptr );
		return( use_abal_runtime((char *) 0, automatic) );
		}
}




