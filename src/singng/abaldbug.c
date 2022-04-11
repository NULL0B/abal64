#ifdef WIN32	/* GWB le 26/10/2007 */
#include <process.h>
#else
int system_arp(char *cde)
{
	char *arg[2]={cde,NULL};
	if (!fork()) execv(cde,arg);
	return(0);
}
#endif

struct	visual_debug	{
	char *	tcode;
	char *	parameters;
	int	isdebug;
	char *	rootpath;
	} runtime = { (char *) 0,(char *) 0,0,(char *) 0 };

#include "singappl.h"

extern	struct	application_parameters Application;
char *	getcwd();

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

/* activate_background_job : OS dependant function */
/* ----------------------------------------------- */
#ifdef WIN32 

public	int	activate_background_job( char * command )
{
	status_message(command,3);
	windows_create_process( command, FALSE );
	return(0);
}

#else

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

#endif /* activate_background_job : OS dependant function */

public	int	use_exa(char * xptr, char * fnptr, char * aptr)
{
	char *	dptr;
	char *	sptr;
	char *	command;
	char *	filename;
	int	arglen=0;
	int	i;
	int	n;
	char *app_objects,*exe_name;
#ifdef WIN32
	char 	svcwd[MAX_PATH];
	int	pathchange=0;
#endif

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
	
	if ( method_is_valid((app_objects = application_object_production()))) {
#ifdef WIN32
		/* save current directory */	
		/* ---------------------- */
		getcwd(svcwd,MAX_PATH);	
		/* change to new directory */	
		/* ----------------------- */
		chdir(app_objects);
		pathchange=1;
#else
		exe_name=filename;
		add_path_terminator(&app_objects);
		filename=relative_filename(exe_name, app_objects );
		exe_name=liberate(exe_name);
#endif
		app_objects=liberate(app_objects);
		}

	if (!( command = allocate( strlen( xptr ) + strlen( filename ) + 64 + arglen ) )) {
		filename = liberate( filename );
#ifdef WIN32
		if ( pathchange ) { chdir(svcwd); }
#endif
		return(0);
		}
	else	{
		if ( arglen > 0 )
			sprintf(command,"%s %s %s",xptr, filename,aptr );
		else	sprintf(command,"%s %s",xptr, filename );

		(void) activate_background_job( command );

#ifdef WIN32
		if ( pathchange ) { chdir(svcwd); }
#endif
		command  = liberate( command );
		filename = liberate( filename );
		return(1);
		}
}

public	int	use_runtime(char * aptr, char * bptr)
{
/* GWB le 09/10/2007 */
	char		xbuffer[512];
	char *	dptr,*filename;
	int ret;

	if (method_is_valid( aptr )
		&& (fn_parser(aptr,xbuffer,0x0010))
		&& ( upper_compare(xbuffer,".CPP")))
			{
			fn_parser(aptr,xbuffer,0x0008);
			dptr = application_object_production();
			if (method_is_valid(dptr))
				filename=relative_filename(xbuffer, dptr );
			else
				filename=allocate_string(xbuffer);

				/* savoir si c'est une librairie */
				if (Context.Form->isprogram)
					{
					if (!Context.Form->isoverlay)
#ifdef WIN32
						ret=_spawnl(_P_NOWAIT,filename,filename,NULL);
#else
						if (filename[0] != '/')
							{
							dptr=filename;
							filename=allocate(strlen(dptr)+3);
							strcpy(filename,"./");
							strcat(filename,dptr);
							liberate(dptr);
							};
						ret=system_arp(filename);
#endif
					}
				else if (Context.Form->isoverlay)
					{
					while (run_library(filename))
						{
						if (file_not_found(filename)==27) break;
						};
					}
		
			liberate(filename);
			return(ret);
			};
/* fin GWB le 09/10/2007 */
	if (!( SingConf ))
		return(0);
	else if (!( runtime.isdebug ))
		return( use_exa( SingConf->exa.program  , aptr, bptr ) );
	else	return( use_exa( SingConf->exadb.program, aptr, bptr ) );
}

public	int	use_abal_runtime(char * nptr, int automatic)
{
	char *	dptr;

	if (!( SingConf ))
		return( 0 );
	if ( nptr != (char *) 0) {
		if ( runtime.tcode )
			liberate( runtime.tcode );
		runtime.tcode = allocate_string( nptr );
		}
	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if (!(method_is_valid(runtime.rootpath))) {
			if (!(runtime.rootpath))
				runtime.rootpath=allocate(256);
			if (!( runtime.rootpath )) {
				allocate_failure();
				return(0);
				}
			if ( method_is_valid((dptr = application_object_production())) ) {
				strcpy(runtime.rootpath,dptr );
				dptr=liberate(dptr);
				}
			else	getcwd(runtime.rootpath,255);
			}
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

public	int	use_css_stylesheet( char * aptr, int automatic)
{
	char		xbuffer[512];
	if (!( aptr ))
		return(0);
	else if (!( fn_parser( aptr, xbuffer, 0x0010 ) ))
		return(0);
	else if (!( upper_compare( xbuffer, ".CSS"  ) ))
		return(0);
	else	{
		load_visual_style(aptr,strlen(aptr));
		sprintf(xbuffer,"%s : loaded",aptr);
		status_message(xbuffer,3);
		return(1);
		}
}


public	int	abal_runtime(char * aptr, int automatic)
{
	if ( use_abal_makefile( aptr, automatic ) )
		return(0);
	else if ( use_html_navigator( aptr, automatic ) )
		return( 0 );
	else if ( use_css_stylesheet( aptr, automatic ) )
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




