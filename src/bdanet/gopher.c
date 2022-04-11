#ifndef	_GOPHER_C
#define	_GOPHER_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "files.h"
#include "gopher.h"

PRIVATE	SERVICE	GopherService;

PUBLIC	INT	gopher_parser( nptr, uptr )
BPTR	nptr;
URLPTR	uptr;
{
	INT	status=0;
	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base    = __GOPHER_PORT;

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

PUBLIC	INT	initialise_gopher_service()
{
	INT	status;
	strcpy(GopherService.name,__GOPHER_PREFIX);
	GopherService.parse  = gopher_parser;
	GopherService.client = default_service_client;
	GopherService.nature = 0;
	return( add_url_service( (SERVICEPTR) & GopherService ) );
}

#endif	_GOPHER_C



