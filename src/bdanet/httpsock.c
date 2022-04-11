#ifndef	_HTTPSOCK_C
#define _HTTPSOCK_C

INT	verbose=0;
INT	debug=0;
INT	PortAddress=0;
BYTE  	workbuffer[2048];

PUBLIC	BPTR 	socketname( sptr )
ADDRPTR 	sptr;
{
	BPTR aptr = (BPTR) & sptr->sin_addr;
	sprintf(workbuffer,"%u.%u.%u.%u:%u",
			( *(aptr + 0) & 0x00FF),
			( *(aptr + 1) & 0x00FF),
			( *(aptr + 2) & 0x00FF),
			( *(aptr + 3) & 0x00FF),
			ntohs(sptr->sin_port));
	return( (BPTR) workbuffer);
}

socketpoke( sptr, v )
ADDRPTR sptr;
INT	v;
{
	BPTR aptr = (BPTR ) & sptr->sin_addr;
	*(aptr + 3) = (v & 0x000FF);
	return;
}

BPTR socketerror( v )
INT	v;
{
	BPTR eptr=(BPTR) 0;
	switch ( v ) {
		case	115 : eptr = (BPTR ) "Connection Refused";
				break;
		default		: eptr = (BPTR) "Unknown as yet";
		}
	return( (BPTR) eptr );
}

VOID set_port_address( pptr )
BPTR pptr;
{
	PortAddress = 0;
	while ( *pptr ) {
		if ((*pptr >= '0') && (*pptr <= '9')) {
			PortAddress *= 10;
			PortAddress += (INT) (*(pptr++) - '0');
			}
		else	break;
		}
	if ( PortAddress == 0 )
		PortAddress = __HTTP_PORT;
	return;
}

VOID	normalise_url( nptr )
BPTR 	nptr;
{
	BPTR	 pptr;
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '\\' )
			*pptr = '/';
		}
}

VOID	localise_url( nptr )
BPTR 	nptr;
{
	BPTR	pptr;
#ifdef	UNIX
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '\\' )
			*pptr = '/';
		}
	if (*nptr == '/') nptr++;
#endif
#ifdef	PROLOGUE
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '/' )
			*pptr = '\\';
		}
	if (*nptr == '\\') nptr++;
#endif
	return;
}


#endif


