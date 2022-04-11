#ifndef	_MAIL_C
#define	_MAIL_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "files.h"
#include "mail.h"

PRIVATE	SERVICE	MailService;

PRIVATE	INT	mail_parser( nptr, uptr )
	BPTR	nptr;
	URLPTR	uptr;
{
	BPTR 	tptr;
	INT	tlen;

	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base    = __MAIL_PORT;
	if ( *(nptr++) != '[' )
		return( _INVALID_URL_HOST );
	while (( *nptr ) && ( *nptr == ' ' ))
		nptr++;
	if ((!( *nptr )) || ( *nptr == ']' ))
		return( _INVALID_URL_HOST );

	tptr = uptr->host;
	tlen = _MAX_URL_HOST;
	while ((tlen) && (*nptr) && (*nptr != ']') && (*nptr != ' ')) {
		if ( *nptr == '@' ) {
			*(tptr++) = '.';
			nptr++;
			}
		else	*(tptr++) = *(nptr++);
		tlen--;
		}

	if (!( tlen ))
		return( _INVALID_URL_HOST );
	else	*tptr = 0;
	
	while (( *nptr ) && ( *nptr == ' ' ))
		nptr++;

	if ( *(nptr++) != ']' )
		return( _INVALID_URL_HOST );

	while (( *nptr ) && ( *nptr == ' ' ))
		nptr++;

	if ( *nptr )
		return( _INVALID_URL_HOST );
	else	return( _URL_IS_HOST );	
}

PUBLIC	INT	initialise_mail_service()
{
	INT	status;
	strcpy(MailService.name,__MAIL_PREFIX);
	MailService.parse  = mail_parser;
	MailService.client = default_service_client;
	MailService.nature = 0;
	return( add_url_service( (SERVICEPTR) & MailService ) );
}

#endif	_MAIL_C



