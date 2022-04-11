#ifndef	_URL_C
#define	_URL_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"

PRIVATE	SERVICELIST	Services;

/*	------------------------------------------	*/
/*	PUBLIC	URL / SERVICES INTERFACE FUNCTIONS	*/
/*	------------------------------------------	*/

PUBLIC	VOID	normalise_url( nptr )
	BPTR 	nptr;
{
	BPTR	 pptr;
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '\\' )
			*pptr = '/';
		}
}

PUBLIC	VOID	localise_url( nptr )
	BPTR 	nptr;
{
#ifdef	UNIX
	BPTR	pptr;
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '\\' )
			*pptr = '/';
		}
	if (*nptr == '/') nptr++;
#endif
#ifdef	PROLOGUE
	BPTR	pptr;
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '/' )
			*pptr = '\\';
		}
	if (*nptr == '\\') nptr++;
#endif
	return;
}

PUBLIC	INT 		default_service_client( uptr, argc, argv )
	URLPTR		uptr;
	INT		argc;
	BPTR  		argv[];
{
	return(0);
}


PUBLIC	INT 	parse_url_path( nptr, uptr )
	BPTR	nptr;		/* URL Specification to be analysed	*/
	URLPTR	uptr;		/* URL Result Descriptor PoINTer	*/
{
	INT	tlen;

	/* Detect and Handle FilePath/Name Component */
	/* ----------------------------------------- */
	if (( nptr == (BPTR) 0 )
	||  ((tlen = strlen(nptr)) >= _MAX_URL_OBJECT ))
		return( _INVALID_URL_PATH );			
	else if (!( tlen ))
		return( 0 );
	else	{
		strcpy( uptr->path, nptr );
		return(_URL_IS_PATH);
		}
}

PUBLIC	INT 	parse_url_host( nptr, uptr )
	BPTR	nptr;		/* URL Specification to be analysed	*/
	URLPTR	uptr;		/* URL Result Descriptor PoINTer	*/
{
	BPTR 	tptr;
	INT	tlen;
	INT	status=0;

	/* Detect Host Name Component */
	/* -------------------------- */
	if (( *nptr == '/' ) && ( *(nptr + 1) == '/' )) {

		/* Extract Host Name Component */
		/* --------------------------- */
		nptr += 2; tptr = uptr->host; tlen = _MAX_URL_HOST;
		while ((tlen) && ( *nptr ) && ( *nptr != '/' ) && ( *nptr !=':')) {
			*(tptr++) = *(nptr++);
			tlen--;
			}
		if (!(tlen))
			return( _INVALID_URL_HOST );			
		else	*tptr = 0;

		/* Detect Host Port Component */
		/* -------------------------- */
		if ( *nptr == ':' ) {

			/* Extract Host Port Component */
			/* --------------------------- */
			nptr++; tlen = 0;
			while (( *nptr >= '0' ) && ( *nptr <= '9' ))
				tlen = ((tlen * 10) + ( *(nptr++) - '0' ));

			uptr->port = tlen;
			}
		status = _URL_IS_HOST;
		}
	return( (parse_url_path(nptr,uptr) | status) );
}


PUBLIC	INT parse_url_service( sptr, fptr, uptr )

				/* ------------------------------------ */
	BPTR	sptr;		/* Service Name to be localised 	*/
	BPTR	fptr;		/* URL Specification to be analysed	*/
	URLPTR	uptr;		/* URL Result Descriptor PoINTer	*/
				/* ------------------------------------ */

{
	SERVICENODEPTR	nptr;
	if ((nptr = Services.first) != (SERVICENODEPTR) 0) {
		do	{
			if (((uptr->service = nptr->contents) != (SERVICEPTR) 0)
			&&  ( compare_tokens( nptr->contents->name, sptr )))
				return( (nptr->contents->parse( fptr, uptr ) | _URL_IS_SERVICE));
			}
		while ((nptr = nptr->next) != (SERVICENODEPTR) 0);
		}
	return( _INVALID_URL_SERVICE );
}

PUBLIC	INT		add_url_service( sptr )
	SERVICEPTR	sptr;
{
	SERVICENODEPTR	nptr;
	if ((nptr = (SERVICENODEPTR) allocate_zone( sizeof( SERVICENODE ) )) != (SERVICENODEPTR) 0) {
		nptr->contents = sptr;
		nptr->next     = (SERVICENODEPTR) 0;
		if ((nptr->previous = Services.last) == (SERVICENODEPTR) 0)
			Services.first = nptr;
		else	Services.last->next = nptr;
		Services.last = nptr;
		return(0);
		}
	else	return( 27 );
}

PUBLIC	INT	drop_url_service( nptr )
	BPTR	nptr;
{

	return(0);
}

PUBLIC	INT	initialise_url_services()
{
	Services.services = 0;
	Services.first    = (SERVICENODEPTR) 0;
	Services.last     = (SERVICENODEPTR) 0;
	return(0);
}

PUBLIC	INT	liberate_url_services()
{
	SERVICENODEPTR	nptr;
	while ((nptr = Services.first) != (SERVICENODEPTR) 0) {
		Services.first = nptr->next;
		if ((nptr->contents != (SERVICEPTR) 0)
		&&  (nptr->contents->nature          ))
			nptr->contents = liberate_zone( nptr->contents );
		nptr = liberate_zone( nptr );
		}
	return(0);
}
	
PUBLIC	INT	parse_url( nptr, uptr )
	BPTR	nptr;
	URLPTR	uptr;
{
	BPTR 	tptr;
	BPTR 	sptr;
	INT	tlen;
	char	sname[_MAX_LABEL];

	/* ------------------------------- */
	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->service = (SERVICEPTR) 0;
	uptr->port    = 0; uptr->base    = 0;
	uptr->host[0] = 0; uptr->path[0] = 0;

	/* ------------------------------------------------- */
	/* Ensure URL is normalised WRT INTERNET Conventions */
	/* ------------------------------------------------- */
	normalise_url( nptr );

	/* -------------------------- */
	/* Detect Service Name Prefix */
	/* -------------------------- */
	tptr = sname; sptr = nptr; tlen = _MAX_LABEL;
	while ((tlen) && ( *sptr ) 
	&& 	( *sptr != '/' ) 
	&&      ( *sptr != ':' )
	&&      ( *sptr != ' ' )
	&&      ( *sptr != '?' )) {
		*(tptr++) = *(sptr++);
		tlen--;
		}
	if (!( tlen ))
		return( (uptr->status = _INVALID_URL ));
	else	{
		/* Analyse Service Name Prefix */
		/* --------------------------- */
		if ( *sptr == ':' ) {

			/* Service Name Prefix Extracted */
			/* ----------------------------- */
			*(tptr++) = *(sptr++); *tptr = 0;
			return(((uptr->status = parse_url_service( sname, sptr, uptr )) & _INVALID_URL) );

			}
		else 	{

			if ( *sptr == '/' )
				/* Possible Local Server Prefix */
				/* ---------------------------- */
				return(((uptr->status = parse_url_host( nptr, uptr )) & _INVALID_URL) );

			else	/* Possible FilePath/Name */
				/* ---------------------- */
				return(((uptr->status = parse_url_path( nptr, uptr )) & _INVALID_URL) );
			}
		}

}

PUBLIC	INT 		service_url( 
	URLPTR		uptr,
	INT		argc,
	BPTR		argv[] )
{
	SERVICEPTR	sptr;

	if (( uptr != (URLPTR) 0)
	&&  ((sptr = uptr->service) != (SERVICEPTR) 0))
		return( sptr->client( uptr, argc, argv ));
	else	return(0);

}


PUBLIC	VOID	url_copy_object( rptr, sptr )
	URLPTR	rptr;
	URLPTR 	sptr;
{
	INT	i=0;
	for ( i=0; i < (_MAX_URL_OBJECT-1); i++ )
		if (!( rptr->path[i] = sptr->path[i] ))
			break;

	rptr->path[i] = 0;
	return;
}

PUBLIC	BPTR	interpret_url( uptr )
	URLPTR	uptr;
{
	BPTR	buffer=(BPTR) 0;
	if (( uptr != (URLPTR) 0) 
	&&  (!( uptr->status & _INVALID_URL ))
	&&  (( buffer = allocate_zone( strlen(uptr->host)+strlen(uptr->path)+ 32 )) != (BPTR) 0)) {
		
		if ( uptr->service != (SERVICEPTR) 0 ) {
			strcpy(buffer,uptr->service->name);
			strcat(buffer,"//");
			strcat(buffer,uptr->host);
			strcat(buffer,uptr->path);
			}

		else	{
			strcpy(buffer,"//");
			strcat(buffer,uptr->host);
			strcat(buffer,uptr->path);
			}
		}
	return(buffer);
}

PUBLIC	VOID	show_url( uptr )
	URLPTR	uptr;
{
	BPTR	bptr=(BPTR) 0;
	if (( uptr != (URLPTR) 0) 
	&&  (!( uptr->status & _INVALID_URL ))
	&&  ((bptr = interpret_url( uptr )) != (BPTR) 0)) {
		printf("\tURL[ %s ]\n",bptr);
		bptr = liberate_zone( bptr );
		}
	return;
}

PUBLIC	URLPTR	liberate_for_url( uptr )
	URLPTR	uptr;
{
	INT	i;
	if ( uptr != (URLPTR) 0 ) {
		if ( uptr->althost != (BPTR) 0 )
			uptr->althost = liberate_zone( uptr->althost );
		for ( i=0; i < uptr->headers; i++ )
			if ( uptr->header[i] )
				uptr->header[i] = liberate_zone( uptr->header[i] );
		uptr->headers = 0;
		uptr = liberate_zone( uptr );
		}
	return( uptr );
}

PUBLIC	URLPTR	allocate_for_url( nptr, ladresse )
	BPTR	nptr;
	LONG	ladresse;
{
	INT	i;
	URLPTR	uptr=(URLPTR) 0;

	if ((uptr = (URLPTR) allocate_zone( sizeof( URL ) )) != (URLPTR) 0) {
		uptr->headers	= 0;
		for ( i=0; i < _MAX_HEADERS; i++ )
			uptr->header[i] = (BPTR) 0;
		uptr->status    = 0;
		uptr->transport = 0;
		uptr->service   = (SERVICEPTR) 0;
		uptr->port      = 0;
		uptr->base      = 0;
		uptr->maxadr    = 0;
		uptr->adrindex  = 0;
		if ((uptr->explicite = ((LONG) (uptr->address[0].sin_addr.s_addr = ladresse))) != 0L)
			uptr->maxadr++;
		uptr->althost   = (BPTR) 0;
		memset(uptr->host,0,_MAX_URL_HOST);
		memset(uptr->path,0,_MAX_URL_OBJECT);
		memset(uptr->address,0,(sizeof( ADDRESS )*_MAX_URL_ADDR));
		/* ------------------------------------------------------ */
		/* If a valid URL String pointer has been provided Use it */
		/* ------------------------------------------------------ */
		if ( nptr != (BPTR) 0 ) {
			/* ------------------------------------------- */
			/* Parse the name string (watching for errors) */
			/* ------------------------------------------- */
			if  ( parse_url( nptr, uptr ) & _INVALID_URL )
				uptr = liberate_for_url( uptr );
			/* ------------------------------------------- */
			/* Resolve URL Host Name to Internet Address   */
			/* ------------------------------------------- */
			else if (!( uptr->explicite )) {
				if ( resolve_internet_host( uptr ) != 0 )
					uptr = liberate_for_url( uptr );
				}
			}
		}
	return( uptr );
}

PUBLIC	URLPTR	copy_url( optr )
	URLPTR	optr;
{
	URLPTR	uptr=(URLPTR) 0;
	if ( optr != (URLPTR) 0 ) {
		if ((uptr = allocate_for_url((BPTR) 0,0L)) != (URLPTR) 0) {
			uptr->status  = optr->status;
			uptr->service = optr->service;
			uptr->port    = optr->port;
			uptr->base    = optr->base;
			strcpy(uptr->host, optr->host);
			strcpy(uptr->path, optr->path);
			uptr->maxadr   = optr->maxadr;
			uptr->adrindex = optr->adrindex;
			memcpy(uptr->address, (BPTR) optr->address,(sizeof( ADDRESS ) * _MAX_URL_ADDR));
			}
		}
	return( uptr );
}

PUBLIC	INT	verify_url( uptr, aptr )
	URLPTR	uptr;
	ADDRPTR aptr;
{
	if ((uptr != (URLPTR) 0)
	&&  (aptr != (ADDRPTR) 0)
	&&  (uptr->address[uptr->adrindex].sin_addr.s_addr == aptr->sin_addr.s_addr ))
		return(1);
	else	return(0);
}


PUBLIC	WORD	url_set_alt_header( uptr, nptr )
	URLPTR	uptr;
	BPTR	nptr;
{
	if ( uptr->headers < _MAX_HEADERS ) {
		if (!( uptr->header[uptr->headers] = allocate_zone( strlen( nptr ) + 1 ) ))
			return( 27 );
		else	{
			if ( verbose )
				printf(" alt header : %s \r\n",nptr);
			strcpy( uptr->header[uptr->headers++], nptr );
			return( 0 );
			}
		}
	else	return( 46 );
}
		
PUBLIC	WORD	url_set_alt_host( uptr, nptr )
	URLPTR	uptr;
	BPTR	nptr;
{
	if ( uptr->althost != (BPTR) 0 )
		uptr->althost = liberate_zone( uptr->althost );

	if ((uptr->althost = allocate_zone( strlen( nptr ) + 1 )) != (BPTR) 0 ) {
		strcpy( uptr->althost, nptr );
		for ( nptr=uptr->althost; *nptr; nptr++ ) {
			if ( *nptr == '/' ) {
				*nptr = 0;
				break;
				}
			}
		return(0);
		}
	else	return( 27 );
}

#endif	/* _URL_C */
	/* ------ */





