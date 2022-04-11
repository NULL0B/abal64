#ifndef	_PPP_C
#define	_PPP_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "files.h"
#include "ppp.h"

PRIVATE	SERVICE	PppService;

PRIVATE	INT	ppp_parser( nptr, uptr )
	BPTR  	nptr;
	URLPTR	uptr;
{
	BPTR 	tptr;
	INT	tlen;
	INT	status;

	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base    	= __PPP_PORT;
	uptr->transport = __PPP_TRANSPORT;

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

PUBLIC	INT	initialise_ppp_service()
{
	INT	status;
	strcpy(PppService.name,__PPP_PREFIX);
	PppService.parse  = ppp_parser;
	PppService.client = default_service_client;
	PppService.nature = 0;
	return( add_url_service( (SERVICEPTR) & PppService ) );
}

#endif	_PPP_C




