#ifndef	_HTTPCNX_C
#define	_HTTPCNX_C

#include "udp.c"

PRIVATE	LONG	ConnectionAddress=INADDR_ANY;

PUBLIC	VOID		SetConnectionAddress( aptr )
	BPTR		aptr;
{
	if (( *aptr >= '0' ) && ( *aptr <= '9' ))
		ConnectionAddress = inet_addr( aptr );
	return;
}


PUBLIC	CONNECTIONPTR	liberate_for_connection( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr != (CONNECTIONPTR) 0)
		cptr = liberate_zone( cptr );
	return( cptr );
}

PUBLIC	CONNECTIONPTR	allocate_for_connection()
{
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;

	if ((cptr = (CONNECTIONPTR) allocate_zone( sizeof( CONNECTION ) )) != (CONNECTIONPTR) 0) {

		cptr->remote = (URLPTR) 0;
		cptr->socket = 0;
		cptr->newsocket = 0;
		cptr->status = 0;
		memset((char *) &cptr->address, 0,sizeof( struct sockaddr_in ));

		}
	return( cptr );
}

PUBLIC	CONNECTIONPTR	copy_connection( optr )
	CONNECTIONPTR	optr;
{
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;
	if ( optr != (CONNECTIONPTR) 0) {

		if ((cptr = allocate_for_connection()) != (CONNECTIONPTR) 0) {
			if ((cptr->remote = copy_url( optr->remote )) == (URLPTR) 0) {
				cptr->status  = _URL_COPY;
				cptr = liberate_for_connection( cptr );
				}
			else	{
				cptr->status    = (optr->status | _URL_COPY);
				cptr->socket    = optr->socket;
				cptr->newsocket = optr->newsocket;
				optr->newsocket = 0;
				memcpy( (BPTR) & cptr->address, (BPTR) & optr->address, sizeof( ADDRESS ) );
				}			
			}
		}
	return( cptr );
}

PRIVATE	INT	internet_error( mptr )
	BPTR		mptr;
{
	printf("\nInternet:error:%d:%s\n",errno,mptr);
	return( (errno ? errno : 666) );
}

PRIVATE	VOID	show_connection_status( status )
	INT	status;
{
	printf(" :-( ");
	if ( status & _URL_SOCKET  )
		printf("S");
	else	printf("s");
	if ( status & _URL_BOUND   )
		printf("B");
	else	printf("b");
	if ( status & _URL_CONNECT )
		printf("C");
	else	printf("c");
	if ( status & _URL_LISTEN  )
		printf("L");
	else	printf("l");
	if ( status & _URL_ACCEPT  )
		printf("A");
	else	printf("a");
	if ( status & _URL_DATAGRAM)
		printf("D");
	else	printf("d");
	printf(" )-: ");
	return;
}

/* -------------------------------------------------------------------- */
/*	R E S O L V E _ I N T E R N E T _ H O S T ( urlptr )		*/
/* -------------------------------------------------------------------- */
/*									*/
/*	This function performs conversion of the host identification	*/
/*	string field of the parameter 'urlptr' to its respective	*/
/*	internet address.						*/
/*									*/
/* -------------------------------------------------------------------- */

PUBLIC	INT	resolve_internet_host( urlptr )
	URLPTR	urlptr;
{
	struct  hostent PTR hp=(struct hostent PTR) 0;
	BPTR	nptr;
	INT	i;
	nptr = urlptr->host;

	memset((BPTR) urlptr->address, 0,sizeof( struct sockaddr_in ) * _MAX_URL_ADDR );
	for (	urlptr->urlindex = urlptr->maxadr = i = 0;
		i < _MAX_URL_ADDR;
		i++ ) {
		urlptr->address[i].sin_family = AF_INET;
		urlptr->address[i].sin_port   = htons((urlptr->port ? urlptr->port : urlptr->base));
		}
	if ( strlen(nptr) > 0 ) {


		if (( *nptr >= '0' ) && ( *nptr <= '9' ))
			/* ----------------------------------------------------- */
			/* E X P L I C I T E    I N T E R N E T    A D D R E S S */
			/* ----------------------------------------------------- */
			urlptr->address[urlptr->maxadr++].sin_addr.s_addr = inet_addr( nptr );

		else 
			/* --------------------------------------------- */
			/* D N S   R E S O L V E R   A C T I V A T I O N */
			/* --------------------------------------------- */
			if (!(urlptr->maxadr = DnsResolve( nptr, (ADDRPTR)  urlptr->address, _MAX_URL_ADDR  )))
				return( internet_error("DnsResolve() failed") );

		}

	urlptr->status |= _URL_RESOLVED;
	return(0);

}

PUBLIC	VOID		drop_connection( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr != (CONNECTIONPTR) 0 ) {

		if ((cptr->status & _URL_LISTEN)
		&&  (cptr->status & _URL_ACCEPT))
			(VOID) SocketClose( cptr->newsocket );

		cptr->newsocket = 0;

		}
	return;
}

/* -------------------------------------------------------------------- */
/*		C L O S E _ C O N N E C T I O N ( cptr ) 		*/
/* -------------------------------------------------------------------- */
/*									*/
/*	This function provides for generalised connection closure	*/
/*	irrespective of the internal state of the connection control	*/
/*	package, and [TCP|UDP] / [CLIENT|SERVER] nature of connection	*/
/*									*/
/*	The parameter 'cptr' must be of type CONNECTIONPTR and must	*/
/*	point to a valid allocated CONNECTION control structure or	*/
/*	be a NULL pointer.						*/
/*									*/
/* -------------------------------------------------------------------- */

PUBLIC	CONNECTIONPTR	close_connection( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr != (CONNECTIONPTR) 0 ) {

		if (!( cptr->status & _URL_COPY )) {

			/* Not a Copy so close Master Socket */
			/* --------------------------------- */
			if ( cptr->status & _URL_SOCKET )
				SocketClose( cptr->socket );
			}
		else	{

			/* Close Accepted Connection if TCP */
			/* -------------------------------- */
			if ((cptr->status & _URL_LISTEN)
			&&  (cptr->status & _URL_ACCEPT))
				(VOID) SocketClose( cptr->newsocket );

			/* Liberate Copied URL */
			/* ------------------- */
			cptr->remote = liberate_for_url( cptr->remote );

			}
		cptr = liberate_for_connection( cptr ); 
		}
	return( cptr );
}

/* -------------------------------------------------------------------- */
/*	S H O W   C O N N E C T I O N  ( cptr )				*/
/* -------------------------------------------------------------------- */
/*	This function provides for the visualisation of a valid		*/
/*	connection context in the following format :			*/
/*									*/
/*	CNX/<type>[ <local_address> <socket_number> <remote_address> ]	*/
/*									*/
/* -------------------------------------------------------------------- */
PUBLIC	VOID		show_connection( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr != (CONNECTIONPTR) 0 ) {
		if ( cptr->status & _URL_DATAGRAM )
			printf("\tCNX/UDP[ ");
		else	printf("\tCNX/TCP[ ");
/* Local  */	printf("%s",socketname((ADDRPTR) & cptr->address ));

/* Socket */	if ( cptr->status & _URL_DATAGRAM )
	 		printf(" :-> %u <-: ",cptr->socket);
		else if ( cptr->status & _URL_LISTEN )
	 		printf(" <-: %u <-: ",cptr->socket);
	 	else	printf(" :-> %u :-> ",cptr->socket);

/* Remote */	if ( cptr->remote != (URLPTR) 0 )
			printf("%s",socketname((ADDRPTR) & cptr->remote->address[cptr->remote->adrindex] ));
		printf(" ]\n");
		}
	return;
}

/* -------------------------------------------------------------------- */
/*	   O P E N  _ C O N N E C T I O N ( type, service, uptr )	*/
/* -------------------------------------------------------------------- */
/*									*/
/*									*/
/*	This function provides for generalised socket oriented		*/
/*	connection for client and servers.				*/
/*									*/
/*	The parameter 'urlptr' identifies the HOST in the case of 	*/
/*	client connections, and will be used to receive CLIENT		*/
/*	identification in the case of host connections.			*/
/*									*/
/*	The parameter 'type' identifies the nature of the connection	*/
/*	which may be one of the following :				*/
/*									*/
/*	      	SOCK_STREAM 	indicates TCP VIRTUAL CIRCUIT		*/
/*	   	SOCK_DGRAM	indicates UDP DATAGRAM			*/
/*									*/
/*	The parameter 'service' identifies the service port number	*/
/* 	for this end of the connection and may be :			*/
/*									*/
/*		ZERO		indicates a client connection		*/
/*		NOTZERO		indicates a server connection		*/
/*									*/
/*	This gives the following four basic types of connection		*/
/*									*/
/*	- TCP CLIENT	ALLOCATE,INITIALISE,SOCKET,BIND and CONNECT	*/
/*	- TCP SERVER	ALLOCATE,INITIALISE,SOCKET,BIND and LISTEN 	*/
/*	- UDP CLIENT	ALLOCATE,INITIALISE,SOCKET,BIND 		*/
/*	- UDP SERVER	ALLOCATE,INITIALISE,SOCKET,BIND 		*/
/*									*/
/*	Which are represented and made available by the macros   	*/
/*	defined in the header file 'INTERNET.H'				*/
/* -------------------------------------------------------------------- */

PUBLIC	CONNECTIONPTR	open_connection( type, service, urlptr )
	INT		type;
	INT		service;
	URLPTR		urlptr;
{
	CONNECTIONPTR	cptr;

	/* --------------- */
	/* A L L O C A T E */
	/* --------------- */
	if ((cptr = allocate_for_connection()) == (CONNECTIONPTR) 0)
		return( cptr );

	/* ----------- */
	/* S O C K E T */
	/* ----------- */
	if ((cptr->socket = socket(AF_INET,type,0)) < 0)
		return( close_connection( cptr ) );
	else	cptr->status |= _URL_SOCKET;

	/* ------- */
	/* B I N D */
	/* ------- */
	cptr->address.sin_family = AF_INET;
	cptr->address.sin_addr.s_addr = htonl(ConnectionAddress /* INADDR_ANY */);
	cptr->address.sin_port = htons(service);
	if ( bind(cptr->socket,(struct sockaddr_in *) &cptr->address, sizeof( struct sockaddr_in)) < 0 )
		return( close_connection( cptr ) );
	else	cptr->status |= _URL_BOUND;

	/* -------------------------------------------- */
	/* 	       TCP VIRTUAL CIRCUITS 		*/
	/*		(type=SOCK_STREAM) 		*/
	/* -------------------------------------------- */
	/* 	LISTEN  for SERVER ( service ! 0)	*/
	/* 	CONNECT for CLIENT ( service = 0)	*/
	/* -------------------------------------------- */
	if ( type == SOCK_STREAM ) {

		if ( service  ) {
			/* ----------- */
			/* L I S T E N */
			/* ----------- */
			if ( listen(cptr->socket,MAX_CLIENTS) < 0 )
				return( close_connection( cptr ) );
			else	cptr->status |= _URL_LISTEN;
			}
		else	{
			/* ------------- */
			/* C O N N E C T */
			/* ------------- */
			while ((connect(cptr->socket,(struct sockaddr *) & urlptr->address[urlptr->adrindex], sizeof( struct sockaddr ))) < 0 ) {
				urlptr->adrindex++;
				if ( urlptr->adrindex >= urlptr->maxadr )
					return( close_connection( cptr ) );
				}
			cptr->status |= _URL_CONNECT;
			}

		}

	else	{
		cptr->status |= _URL_DATAGRAM;
		}

	/* ------------- */
	/* S U C C E S S */
	/* ------------- */
	cptr->remote = urlptr;

	if ( verbose )
		show_connection( cptr );

	return( cptr );

}

PUBLIC	CONNECTIONPTR	establish_connection( cptr, uptr )
	CONNECTIONPTR	cptr;
	URLPTR		uptr;
{
	CONNECTIONPTR	connection=(CONNECTIONPTR) 0;

	if ( cptr != (CONNECTIONPTR) 0 ) {

		if ( cptr->status & _URL_DATAGRAM ) {
			if (( connection = copy_connection( cptr )) != (CONNECTIONPTR) 0) {
				connection->remote = uptr;
				if ( verbose )
					show_connection( cptr );
				}
			}
		else	connection = open_connection( SOCK_DGRAM, 0, uptr );

		}

	return( connection );

}

PRIVATE	INT	select_connection( handle, delay )
	INT	handle;
	INT	delay;
{
	struct timeval TimeOut;
	fd_set	       rfds;
	FD_ZERO( & rfds );
	FD_SET( handle, & rfds );
	TimeOut.tv_sec = (LONG) (delay & 0x000F);
	TimeOut.tv_usec = 0L;
	if ( select( handle+1, & rfds , (VPTR) 0, (VPTR) 0, (struct timeval PTR) & TimeOut ) > 0 )
		return(1);
	else	return(0);
}


PUBLIC	CONNECTIONPTR	accept_connection( cptr, timeout )
	CONNECTIONPTR	cptr;
	INT		timeout;
{
	INT	packetsize = sizeof( ADDRESS );

	if ( cptr != (CONNECTIONPTR) 0 )  {

		if ((   timeout  )
		&&  (!(	select_connection( cptr->socket, timeout ) )) )
			return( (CONNECTIONPTR) 0 );

		/* TCP VIRTUAL CIRCUIT indicates LISTEN */
		/* ------------------------------------ */
		if ( cptr->status & _URL_LISTEN ) {
			/* ----------- */
			/* A C C E P T */
			/* ----------- */
			if ((cptr->newsocket = 
				accept(	cptr->socket,
					(ADDRPTR) &cptr->remote->address[cptr->remote->adrindex],
					(IPTR) &packetsize 
				      )) < 0 )
				cptr = close_connection( cptr );
			else	cptr->status |= _URL_ACCEPT;
			}

		/* UDP DATAGRAM is not in mode LISTEN */
		/* ---------------------------------- */
		else	{
			if ( udp_peek( 	cptr->socket,cptr->remote) <= 0 )
				cptr = close_connection( cptr );
			else	cptr->newsocket = cptr->socket;
			}
		}
	return( cptr );
}



#endif	/* _HTTPCNX_C */	
	/* ---------- */

