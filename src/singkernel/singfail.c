#ifndef	_singfail_c
#define	_singfail_c

#define	_SING_ERROR		"sing::error"
#define	_FILE_NOT_FOUND		"File Not Found"
#define	_INCORRECT_FILETYPE	"Incorrect File Type"
#define	_CANNOT_CREATE_FILE	"Unable to Create File"
#define	_FILE_SHARE_FAILURE	"File already open"
#define	_ALLOCATION_FAILURE	"Memory Allocation"
#define	_GENERAL_FAILURE	"General Failure"
#define	_CONFIG_ERROR		"Incorrect configuration"
#define	_TRIGGER_ERROR		"No Free Widget Triggers"
#define	_WHOOPS			"Failure" 

public int	report_accept_error( char * lptr, char * mptr )
{
	if ( consoletype() ) 
		return( accept_error( lptr, mptr ) );
	else	{
		printf("\n%s : %s : %s \n",_SING_ERROR,lptr,mptr);
		return(27);
		}
}

public	int	file_not_found( char * filename ) 	{ return( report_accept_error( _FILE_NOT_FOUND, filename ) ); }
public	int	incorrect_filetype( char * filename ) 	{ return( report_accept_error( _INCORRECT_FILETYPE , filename ) ); }
public	int	creation_failure( char * filename )	{ return( report_accept_error( _CANNOT_CREATE_FILE, filename ) ); }
public	int	fileshare_failure( char * filename )	{ return( report_accept_error( _FILE_SHARE_FAILURE, filename ) ); }
public	void	allocate_failure()			{ report_accept_error( _ALLOCATION_FAILURE , _WHOOPS ); }
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

