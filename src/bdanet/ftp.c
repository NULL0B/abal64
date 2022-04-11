#ifndef	_FTP_C
#define	_FTP_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "files.h"
#include "ftp.h"

PRIVATE	SERVICE	FtpService;

PUBLIC	INT	ftp_parser( nptr, uptr )
BPTR	nptr;
URLPTR	uptr;
{
	INT	status=0;
	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base    = __FTP_PORT;

	if (!((status = parse_url_host( nptr, uptr )) & _URL_IS_HOST)) {
		strcpy( uptr->host, _LOCAL_HOST );
		status |= _URL_IS_HOST;
		}
	if (!(status & _URL_IS_PATH)) {
		strcpy( uptr->path, _LOCAL_PATH );
		status |= _URL_IS_PATH;
		}
	return( status );
}

PUBLIC	INT	initialise_ftp_service()
{
	INT	status;
	strcpy(FtpService.name,__FTP_PREFIX);
	FtpService.parse  = ftp_parser;
	FtpService.client = default_service_client;
	FtpService.nature = 0;
	return( add_url_service( (SERVICEPTR) & FtpService ) );
}

#endif	_FTP_C


