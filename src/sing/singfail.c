#ifndef	_singfail_c
#define	_singfail_c

#define	_SING_ERROR		"sing::error"
#define	_FILE_NOT_FOUND		"File Not Found"
#define	_INCORRECT_FILETYPE	"Incorrect File Type"
#define	_CANNOT_CREATE_FILE	"Unable to Create File"
#define	_FILE_SHARE_FAILURE	"File already open"
#define	_ALLOCATION_FAILURE	"Memory Allocation"
#define	_GENERAL_FAILURE	"General Failure"
#define	_IMAGE_FAILURE		"Unable to create image file"
#define	_CONFIG_ERROR		"Incorrect configuration"
#define	_TRIGGER_ERROR		"No Free Widget Triggers"
#define	_WHOOPS			"Failure" 
#define	_LINKER_FAILURE		"Abal Tcode Link Error"
#define	_CONFLICT_FAILURE	"Conflicting ressource filenames"
#define	_QUOTE_COUNT		"Incorrect quote count in"
#define	_CONSTANT_SIZE		"String constant exceeding limit"
#define	_DATABASE_ALERT		"Database Model Editor"
#define	_FLOWCHART_ALERT	"Flowchart Model Editor"
#define	_DATABASE_DELETE	"Unable to Delete Database File"
#define	_FORK_FAILURE   	"Unable to Fork New Process"
#define	_SYSTEM_FAILURE   	"Unable to Launch System Command"
#define	_ENVIRONMENT_FAILURE   	"The environment variable is not defined"

public int	report_accept_error( char * lptr, char * mptr )
{
	if (!( Context.compiling ))
		if ( consoletype() ) 
			return( accept_error( lptr, mptr ) );
	printf("\n%s : %s : %s \n",_SING_ERROR,lptr,mptr);
	return(27);
}

public	int	file_not_found( char * filename ) 	{ return( report_accept_error( _FILE_NOT_FOUND, filename ) ); }
public	int	incorrect_filetype( char * filename ) 	{ return( report_accept_error( _INCORRECT_FILETYPE , filename ) ); }
public	int	creation_failure( char * filename )	{ return( report_accept_error( _CANNOT_CREATE_FILE, filename ) ); }
public	int	fileshare_failure( char * filename )	{ return( report_accept_error( _FILE_SHARE_FAILURE, filename ) ); }
public	int	linker_failure( char * filename )	{ return( report_accept_error( _LINKER_FAILURE, filename ) );	} 
public	int	image_creation_failure(char * filename)	{ return( report_accept_error( _IMAGE_FAILURE, filename ) );	} 
public	int	allocate_failure()			{ return(report_accept_error( _ALLOCATION_FAILURE , _WHOOPS ) ); }
public	int	name_conflict_failure( char * filename ){ return( report_accept_error( _CONFLICT_FAILURE, filename ) ); }
public	int	database_editor_failure(char * mptr)	{ return( report_accept_error( _DATABASE_ALERT, mptr ) ); }
public	int	database_delete_failure(char * mptr)	{ return( report_accept_error( _DATABASE_DELETE, mptr ) ); }
public	int	flowchart_editor_failure(char * mptr)	{ return( report_accept_error( _FLOWCHART_ALERT, mptr ) ); }
public	int	cannot_fork_process(char * mptr)	{ return( report_accept_error( _FORK_FAILURE, mptr ) ); }
public	int	system_failure(char * mptr)		{ return( report_accept_error( _SYSTEM_FAILURE, mptr ) ); }
public	int	environment_failure(char * mptr)	{ return( report_accept_error( _ENVIRONMENT_FAILURE, mptr ) ); }

public	void	general_failure( int code )
{
	char	message[32];
	sprintf(message,"error : %s",code);
	report_accept_error( _GENERAL_FAILURE, message );
	return;
}

public	int 	incorrect_configuration( char * nptr )
{
	report_accept_error( _CONFIG_ERROR, nptr );
	return(56);
}

public	void	report_quote_count(  char* mptr )
{
	report_accept_error(_QUOTE_COUNT, mptr );
	return;
}

public	void	report_constant_size(  char* mptr )
{
	report_accept_error(_CONSTANT_SIZE, mptr );
	return;
}

public	int	no_free_triggers( char * nptr, char * lptr )
{
	char *	mptr;
	if (!( lptr ))
		report_accept_error( _TRIGGER_ERROR, nptr );
	else if (!( nptr ))
		report_accept_error( _TRIGGER_ERROR, lptr );
	else if (( mptr = allocate( strlen( nptr ) + strlen( lptr ) + 16 )) != (char *) 0) {
		sprintf(mptr,"%s : %s",nptr,lptr);
		report_accept_error( _TRIGGER_ERROR, mptr );
		liberate( mptr );
		}
	else	report_accept_error( _TRIGGER_ERROR, nptr );
	return(0);
}

public	int	editor_failure( char * mptr, char * eptr )
{
	report_accept_error( mptr, eptr );
	return(0);
}

#endif	/* _singfail_c */

