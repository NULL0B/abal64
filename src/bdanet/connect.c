#ifndef	_CONNECT_C
#define	_CONNECT_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "timeval.h"
#include "abalssl.h"

#ifdef WIN32
#define Portable_srandom	srand
#else
#define Portable_srandom	srandom
#endif

#define	_HTTP11

BYTE	SSL_ErrorBuf[256];

#define	SIGNAL_verbose	(verbose & 128)
#define	SSL_verbose	(verbose & 256)

#ifdef	_HTTP11
CONNECTIONPTR	Online=(CONNECTIONPTR) 0;
#endif

/*	------------------------------		*/
/*	SOCKET SIGNAL CATCHER for UNIX		*/
/*	------------------------------		*/
#ifdef	AIX
#define	__sighandler_t unsigned long int
#endif

#ifdef UNIX
PRIVATE	__sighandler_t	socketstate=SIG_DFL;
#endif

PRIVATE	INT	sockethit=0;

PUBLIC	WORD	get_tls_mode();

#ifdef UNIX

PUBLIC	VOID	socketcatcher( INT signal )
{
	sockethit++;
	return;
}

PUBLIC	VOID	start_socket_catcher(int socket, char * message )
{
	sockethit=0;
	socketstate = signal(SIGPIPE,socketcatcher);
	return;
}

PUBLIC	VOID	close_socket_catcher(int socket, char * message, int ecode )
{
	(void) signal(SIGPIPE,socketstate);
	socketstate = SIG_DFL;
	if ( sockethit ) {
		if ( SIGNAL_verbose )
			printf("socket catcher failure at %lu : %s : %u \r\n",time((long) 0),message,ecode);
		}
	return;
}

#else

#define start_socket_catcher(a,b)
#define close_socket_catcher(a,b,c)

#endif


PUBLIC	INT	socketreader( INT handle, BPTR buffer, INT length )
{
	INT	status;
	start_socket_catcher(handle,"socket read");
	status = read( handle, buffer, length );
	close_socket_catcher(handle,"socket read",errno);
	return( status );
}

PUBLIC	INT	socketwriter( INT handle, BPTR buffer, INT length )
{
	INT	status;
	start_socket_catcher(handle,"socket write");
	status = write( handle, buffer, length );
	close_socket_catcher(handle,"socket write",errno);
	return( status );
}

#ifdef	SYSTEM_SSL
#include "abalssl.c"
#endif	/* SYSTEM_SSL */


PUBLIC	INT	tcp_readb( handle )
	INT	handle;
{
	BYTE	c;
	if ( SocketRead( handle, ( BPTR) & c, 1 ) == 1 ) {
		return( (c & 0x00FF) );
		}
	else	return( 0xFF00 );
}



PUBLIC	INT	tcp_readw( handle )
	INT	handle;
{
	 INT	v;
	v = tcp_readb( handle );
	v <<= 8; v &= 0xFF00;
	v |= tcp_readb( handle );
	return( (v & 0xFFFF) );
}

PUBLIC 	INT 	tcp_write( handle, bptr, blen )
	INT	handle;
	BPTR	bptr;
	INT	blen;
{
	blen = SocketWrite( handle, bptr, blen );
	return( blen );
}

PUBLIC	INT	tcp_read( handle, bptr, blen )
	INT	handle;
	BPTR	bptr;
	INT	blen;
{
#define	_OPTIMISED_HTTP
#ifdef	_OPTIMISED_HTTP
	return( SocketRead( handle, bptr, blen ) );
#else
	while ( blen > 0 ) {
		*(bptr++) = tcp_readb( handle );
		blen--;
		}
	return( blen );
#endif
}

PUBLIC 	INT	udp_write( handle, bptr, blen, aptr )
	INT	handle;
	BPTR	bptr;
	INT	blen;
	URLPTR 	aptr;
{
	return((blen = sendto( handle, bptr, blen , 0,(ADDRPTR) & aptr->address[aptr->adrindex], sizeof( ADDRESS ))));
}

PUBLIC	INT	udp_read( handle, bptr, blen, aptr)
	INT	handle;
	BPTR	bptr;
	INT	blen;
	URLPTR 	aptr;
{
	INT	alen=sizeof( ADDRESS );
	return((blen = recvfrom( handle, bptr, blen , 0,(ADDRPTR) & aptr->address[aptr->adrindex], (IPTR) & alen )));
}

PUBLIC	INT	udp_peek( handle, aptr )
	INT	handle;
	URLPTR 	aptr;
{
	INT	alen=sizeof( ADDRESS );
	BYTE	buffer[16];
	return(recvfrom( handle,(BPTR) buffer, 16, MSG_PEEK,(ADDRPTR) & aptr->address[aptr->adrindex], (IPTR) & alen ));
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
		cptr->flags	= 0;
		cptr->service	= 0;
		cptr->duplicate	= 0;
		cptr->remote	= (URLPTR) 0;
		cptr->socket	= 0;
		cptr->newsocket	= 0;
		cptr->status	= 0;
		cptr->worker	= 0;
		cptr->connected	= cptr->alive 	= 0L;
		cptr->timeout	= 0;
		cptr->length 	= 0;
		cptr->context   = cptr->object = cptr->newobject = (void *) 0;
		cptr->next = cptr->previous = (CONNECTIONPTR) 0;
		memset((char *) &cptr->address, 0,sizeof( struct sockaddr_in ));
		cptr->cryptage  = 0;
		cptr->is_ssl	= 0;
		cptr->certify	= 0;
		reset_cryptage( &cptr->coding );
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
				cptr->context   = optr->context;
				cptr->object    = optr->object;
				cptr->newobject = optr->newobject;
				memcpy( (BPTR) & cptr->address, (BPTR) & optr->address, sizeof( ADDRESS ) );
				}			
			}
		}
	return( cptr );
}

PRIVATE	INT	internet_error( mptr )
	BPTR		mptr;
{
	if ( verbose )
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
#if defined(UNIX) || defined(WIN32)
PUBLIC 	INT	ResolveHostsByName(char * nptr, char * rptr, INT nb )
{
	struct  hostent *hp=(struct hostent *) 0;

     	if ((hp = gethostbyname(nptr)) == (struct hostent *) 0)
		return( 0 );
	else	{
		memcpy((BPTR) rptr, (BPTR) hp->h_addr_list[0],sizeof(long));
		return( 1 );
		}

}
#endif

PRIVATE	long	HostsBuffer[ _MAX_URL_ADDR ];

PUBLIC 	INT	ResolveHostsByName(char * , char * , INT );
PUBLIC	INT	resolve_internet_host( urlptr )
	URLPTR	urlptr;
{
	struct  hostent PTR hp=(struct hostent PTR) 0;
	BPTR	nptr;
	INT	i;
#ifdef	UNIX
#else
	INT	ResolveHostsByName(char far * , char far * , INT );
#endif
	nptr = urlptr->host;

	memset((BPTR) urlptr->address, 0,(sizeof( struct sockaddr_in ) * _MAX_URL_ADDR));

	for ( 	urlptr->adrindex = urlptr->maxadr = i=0; 
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
			urlptr->explicite = 
			(LONG) ((urlptr->address[urlptr->maxadr++].sin_addr.s_addr = inet_addr( nptr )));

			/* --------------------------------------------- */
			/* D N S   R E S O L V E R   A C T I V A T I O N */
			/* --------------------------------------------- */
		else if (!(urlptr->maxadr = ResolveHostsByName( nptr, HostsBuffer, _MAX_URL_ADDR ) ))
			return( internet_error("DnsResolve() failed") );
		else	{
			for ( i=0; i < urlptr->maxadr; i++ )
				urlptr->address[i].sin_addr.s_addr = HostsBuffer[i];
			}

		}

	urlptr->status |= _URL_RESOLVED;
	return(0);

}

#ifdef	SYSTEM_SSL
PUBLIC	VOID	MakeObjectDead( ssl )
	SSL	*ssl;
{
	if ( ssl ) {
		ssl_tcp_shutdown( ssl );
		}
	return;
}
#else
PUBLIC	VOID	MakeObjectDead( void* ssl )
{
	return;
}
#endif

PUBLIC	VOID	MakeSocketDead( sid )
	WORD	sid;
{
	if ( sid != -1)  {
		(VOID) shutdown(sid,2);
		(VOID) SocketClose(sid);
		}
	return;
}

PUBLIC	VOID		drop_connection( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr != (CONNECTIONPTR) 0 ) {

		if ((cptr->status & _URL_LISTEN)
		&&  (cptr->status & _URL_ACCEPT)) {
#ifdef	DEATH_EATER
			if ( cptr->worker <= 0 )  {
#else
			if (!( cptr->worker ))  {
#endif
				if ( cptr->newobject )
					MakeObjectDead( cptr->newobject );
				MakeSocketDead( cptr->newsocket );
				}
			else	{
				if ( verbose & 512 ) {
					printf("Child Worker(%u) : socket(%u) \r\n",cptr->worker,cptr->newsocket);
					}
				/* try this */
				if ( cptr->newsocket > 0 ) {
					close(cptr->newsocket );
					}
				cptr->worker=0;
				}
			}
		cptr->newsocket = 0;
		cptr->newobject = (VPTR) 0;
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

#ifdef	SYSTEM_SSL
			close_ssl_connection( cptr );
#endif
			/* Not a Copy so close Master Socket */
			/* --------------------------------- */
			if ( cptr->status & _URL_SOCKET ) {

				if (!( cptr->alive ))
					MakeSocketDead( cptr->socket );
				else	return( (CONNECTIONPTR) 0 );

				}
			}
		else	{

			/* Close Accepted Connection if TCP ACCEPT */
			/* --------------------------------------- */
			if ((cptr->status & _URL_LISTEN)
			&&  (cptr->status & _URL_ACCEPT))
				MakeSocketDead( cptr->newsocket );

			/* Liberate Copied URL */
			/* ------------------- */
			cptr->remote = liberate_for_url( cptr->remote );

			}
		cptr = liberate_for_connection( cptr ); 
		}
	return( cptr );
}

#ifdef	_HTTP11
/* -------------------------------------------------------------------- */
/*		P E R S I S T _ C O N N E C T I O N ( cptr ) 		*/
/* -------------------------------------------------------------------- */
/*									*/
/*	This function provides for generalised persistance of the	*/
/*	connection .
/*									*/
/*	The parameter 'cptr' must be of type CONNECTIONPTR and must	*/
/*	point to a valid allocated CONNECTION control structure or	*/
/*	be a NULL pointer.						*/
/*									*/
/* -------------------------------------------------------------------- */

PUBLIC	VOID		clear_persistance()
{
	if ( Online )
		Online = close_connection( Online );

	return;
}

PUBLIC	CONNECTIONPTR	persist_connection( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr != (CONNECTIONPTR) 0 )
		return((Online = cptr));
	else	return((CONNECTIONPTR) 0);
}

#endif

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
PRIVATE	int	KeepAlive=1;

PRIVATE	CONNECTIONPTR	ServiceSocket( type, service )
	INT		type;
	INT		service;
{
	INT		optval=1;
	CONNECTIONPTR	cptr;

	if ((cptr = allocate_for_connection()) == (CONNECTIONPTR) 0)
		return( cptr );

	/* ----------- */
	/* S O C K E T */
	/* ----------- */
	if ((cptr->socket = socket(AF_INET,(type&3),0)) < 0)
		return( close_connection( cptr ) );
	else	cptr->status |= _URL_SOCKET;

	optval = 60;
	
	(void) setsockopt(cptr->socket, SOL_SOCKET, (SO_KEEPALIVE | SO_REUSEADDR), (IPTR) & optval, sizeof( optval ));

	/* ------- */
	/* B I N D */
	/* ------- */
	cptr->address.sin_family = AF_INET;
	cptr->address.sin_addr.s_addr = htonl(INADDR_ANY);
	cptr->address.sin_port = htons(service);
	if ( bind(cptr->socket,(ADDRPTR) &cptr->address, sizeof( struct sockaddr_in)) < 0 )
		return( close_connection( cptr ) );
	else	cptr->status |= _URL_BOUND;

	return( cptr );

}

PRIVATE CONNECTIONPTR	FirstAlive=(CONNECTIONPTR) 0;
PRIVATE CONNECTIONPTR	LastAlive=(CONNECTIONPTR) 0;

PUBLIC	VOID		drop_live_connections()
{
	CONNECTIONPTR	cptr;
	while ((cptr = FirstAlive) != (CONNECTIONPTR) 0) {
		FirstAlive = cptr->next;
		cptr->alive = 0L;
		cptr = close_connection( cptr );
		}
	LastAlive = FirstAlive = (CONNECTIONPTR) 0;
}


PUBLIC	VOID		connection_not_alive( cptr )
	CONNECTIONPTR	cptr;
{
	if ( cptr->alive ) {
		if (!( cptr->previous ))
			FirstAlive = cptr->next;
		else 	cptr->previous = cptr->next;
		if (!( cptr->next ))
			LastAlive = cptr->previous;
		else	cptr->next->previous = cptr->previous;
		cptr->next = cptr->previous = (CONNECTIONPTR) 0;
		cptr->alive = 0L;
		}
	return;
}

PUBLIC	VOID		keep_connection_alive( cptr )
	CONNECTIONPTR	cptr;
{
	URLPTR		urlptr;

	if (!( cptr->alive )) {
		if ((urlptr = cptr->remote) != (URLPTR) 0) {
			if (!( urlptr->explicite ))
				urlptr->explicite = urlptr->address[urlptr->adrindex].sin_addr.s_addr;
			cptr->alive = urlptr->explicite;
			
			if ((cptr->previous = LastAlive) != (CONNECTIONPTR) 0)
				LastAlive->next = cptr;
			else	FirstAlive      = cptr;
			LastAlive = cptr;
			}
		}
	return;
}

PRIVATE CONNECTIONPTR	is_connection_alive( urlptr )
	URLPTR		urlptr;
{
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;
	if ( urlptr->explicite != 0L ) {
		for ( 	cptr=FirstAlive;
			cptr != (CONNECTIONPTR) 0;
			cptr = cptr->next )
			if ( cptr->alive == urlptr->explicite ) {
				cptr->remote = urlptr;
				break;
				}
		}
	return( cptr );
}

#ifdef	_HTTP11
PRIVATE CONNECTIONPTR	is_persistant( newurl )
	URLPTR		newurl;
{
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;
	URLPTR		oldurl;

	if ((cptr = Online) != (CONNECTIONPTR) 0) {

		Online = (CONNECTIONPTR) 0;

		if ((oldurl = cptr->remote) != (URLPTR) 0) {

			if (( oldurl->port == newurl->port )
			&&  ( compare_tokens( &oldurl->host, &newurl->host ) )) {
				url_copy_object( oldurl, newurl );
				newurl = liberate_for_url( newurl );
				}
			else	{
				oldurl = liberate_for_url( oldurl );
				cptr = close_connection( cptr );
				}
			}
		else	{
			cptr = close_connection( cptr );
			oldurl = liberate_for_url( oldurl );
			}
		}

	return(cptr);
}
#endif

PUBLIC	CONNECTIONPTR	open_ssl_connection( type, service, urlptr )
	INT		type;
	INT		service;
	URLPTR		urlptr;
{
	INT		fcode;
	CONNECTIONPTR	cptr;


	if ((cptr = ServiceSocket( type, service )) == (CONNECTIONPTR) 0)
		return( cptr );

	else	
	{
		if ( type & 4 )
			cptr->is_ssl=1;
		if ( type & 8 )
			cptr->certify=1;
		else if ( type & 16 )
			cptr->certify=2;
		else	cptr->certify=0;
		type &= 3;	
	}

	/* -------------------------------------------- */
	/* 	       TCP VIRTUAL CIRCUITS 		*/
	/*		(type=SOCK_STREAM) 		*/
	/* -------------------------------------------- */
	/* 	LISTEN  for SERVER ( service ! 0)	*/
	/* 	CONNECT for CLIENT ( service = 0)	*/
	/* -------------------------------------------- */
	if ( type == SOCK_STREAM ) 
	{

		if ( service  ) 
		{
			/* ----------- */
			/* L I S T E N */
			/* ----------- */
			if ( listen(cptr->socket,MAX_CLIENTS) < 0 )
				return( close_connection( cptr ) );
			else	cptr->status |= _URL_LISTEN;
		}
		else	
		{
			/* ------------- */
			/* C O N N E C T */
			/* ------------- */
			while(1) 
			{
				if ( verbose & 8 )
					printf("SSL_connect(%u of %u) to %s\n",
						urlptr->adrindex,
						urlptr->maxadr,
						socketname((ADDRPTR) & urlptr->address[urlptr->adrindex] ));

				if ((fcode = connect( 	cptr->socket,	
					(struct sockaddr *) & urlptr->address[urlptr->adrindex], 
					sizeof( struct sockaddr ) )) 
					>= 0 ) 
				{

					cptr->connected = urlptr->address[urlptr->adrindex].sin_addr.s_addr;
#ifdef	SYSTEM_SSL
					if (!( tls_client_handshake( cptr, type, urlptr->host ) ))
						return( close_connection( cptr ) );
					if ( verbose ) 
					{
						printf("SSL_connect(pid=%u,h=%x)\r\n",getpid(),cptr->object);
					}
#endif
					break;
				}

				else	
				{
					printf("SSL_connection failed\r\n");

					cptr = close_connection( cptr );

					urlptr->adrindex++;
					if ( urlptr->adrindex >= urlptr->maxadr )
						return( cptr );
					else if ((cptr = ServiceSocket( type , service )) == (CONNECTIONPTR) 0)
						return( cptr );
				}
			}

			cptr->status |= _URL_CONNECT;
			cptr->newsocket = cptr->socket;
			setsockopt( cptr->socket, SOL_SOCKET, SO_KEEPALIVE, (char*) & KeepAlive, sizeof( int ) );
		}

	}

	else	
	{
		cptr->status |= _URL_DATAGRAM;
	}

	/* ------------- */
	/* S U C C E S S */
	/* ------------- */
	cptr->remote = urlptr;
	cptr->service = service;
	cptr->flags   = type;

	return( cptr );


}

PUBLIC	CONNECTIONPTR	open_connection( type, service, urlptr )
	INT		type;
	INT		service;
	URLPTR		urlptr;
{
	INT		fcode;
	CONNECTIONPTR	cptr;

	urlptr->adrindex = 0;

	if ( type & 4 )
		return( open_ssl_connection( type , service, urlptr ) );

	else	type &= 3;

#ifdef	_HTTP11
	if ((cptr = is_persistant( urlptr )) != (CONNECTIONPTR) 0) {
		return( cptr );
		}

	else 
#endif
	      if ((cptr = is_connection_alive( urlptr ))  != (CONNECTIONPTR) 0) {
			return( cptr );
			}

	else if ((cptr = ServiceSocket( type, service )) == (CONNECTIONPTR) 0)
		return( cptr );
	
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
			while(1) {
				if ( verbose & 8 )
					printf("connect(%u of %u) to %s\n",
						urlptr->adrindex,
						urlptr->maxadr,
						socketname((ADDRPTR) & urlptr->address[urlptr->adrindex] ));
					
				if ((fcode = connect( 	cptr->socket,	
						(struct sockaddr *) & urlptr->address[urlptr->adrindex], 
						sizeof( struct sockaddr ) )) 
						>= 0 ) {
					cptr->connected = urlptr->address[urlptr->adrindex].sin_addr.s_addr;
					break;
					}

				else	{

					cptr = close_connection( cptr );

					urlptr->adrindex++;
					if ( urlptr->adrindex >= urlptr->maxadr )
						return( cptr );
					else if ((cptr = ServiceSocket( type , service )) == (CONNECTIONPTR) 0)
						return( cptr );
					}
				}

			cptr->status |= _URL_CONNECT;
			cptr->newsocket = cptr->socket;
			setsockopt( cptr->socket, SOL_SOCKET, SO_KEEPALIVE, (char*) & KeepAlive, sizeof( int ) );
			}

		}

	else	{
		cptr->status |= _URL_DATAGRAM;
		}

	/* ------------- */
	/* S U C C E S S */
	/* ------------- */
	cptr->remote  = urlptr;
	cptr->service = service;
	cptr->flags   = type;

	return( cptr );

}

PUBLIC	CONNECTIONPTR	make_connection( type, service, urlptr, s )
	INT		type;
	INT		service;
	URLPTR		urlptr;
	INT		s;
{
	CONNECTIONPTR	cptr;

	urlptr->adrindex = 0;

	/* --------------- */
	/* A L L O C A T E */
	/* --------------- */
	if ((cptr = allocate_for_connection()) == (CONNECTIONPTR) 0)
		return( cptr );

	/* ----------- */
	/* S O C K E T */
	/* ----------- */
	cptr->socket = s;
	cptr->status |= _URL_SOCKET;

	/* ------- */
	/* B I N D */
	/* ------- */
	cptr->address.sin_family = AF_INET;
	cptr->address.sin_addr.s_addr = htonl(INADDR_ANY);
	cptr->address.sin_port = htons(service);
	if ( bind(cptr->socket,(ADDRPTR) &cptr->address, sizeof( struct sockaddr_in)) < 0 )
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
			while(1) {
				if ( verbose & 8 )
					printf("connect(%u of %u) to %s\n",
						urlptr->adrindex,
						urlptr->maxadr,
						socketname((ADDRPTR) & urlptr->address[urlptr->adrindex] ));
					
				if ( connect( 	cptr->socket,	
						(struct sockaddr *) & urlptr->address[urlptr->adrindex], 
						sizeof( struct sockaddr ) )
						>= 0 )
					break;
				else	{
					urlptr->adrindex++;
					if ( urlptr->adrindex >= urlptr->maxadr )
						return( close_connection( cptr ) );
					}
				}

			cptr->status |= _URL_CONNECT;
			cptr->newsocket = cptr->socket;
			setsockopt( cptr->socket, SOL_SOCKET, SO_KEEPALIVE, (char*) & KeepAlive, sizeof( int ) );
			}

		}

	else	{
		cptr->status |= _URL_DATAGRAM;
		}

	/* ------------- */
	/* S U C C E S S */
	/* ------------- */
	cptr->remote = urlptr;
	cptr->service = service;
	cptr->flags   = type;


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
				}
			}
		else	connection = open_connection( SOCK_DGRAM, 0, uptr );

		}

	return( connection );

}

PUBLIC 	INT	select_connection( handle, delay )
	INT	handle;
	INT	delay;
{
	int		status;
	struct timeval TimeOut;
	fd_set	       rfds;
	fd_set	       wfds;
	fd_set	       xfds;
	FD_ZERO( & rfds );
	FD_ZERO( & wfds );
	FD_ZERO( & xfds );
	FD_SET( handle, & rfds );
	TimeOut.tv_sec  = (LONG) (delay & 0xFFFF);
	TimeOut.tv_usec = 0L;
	if ((status = select((handle+1),(VPTR) & rfds ,(VPTR) & wfds, (VPTR) & xfds ,(VPTR) & TimeOut )) > 0 )
		return(1);
	else if ( status == 0 )
		return( 0 );
	else 	{
		if ( verbose ) {
			printf("** error(%u) : cnx.select(%u) : pid(%u) ** \r\n",errno,handle,getpid());
			}
		return( 0 );
		}
}


PUBLIC	INT		await_connection( cptr, timeout )
	CONNECTIONPTR	cptr;
	INT		timeout;
{
	if ((!( timeout ))
	&&  (!( (timeout = cptr->timeout ) )))
		return(0);
	else if ( select_connection( cptr->socket, timeout ) )
		return(1);
	else 	return(-1);
}

PUBLIC	CONNECTIONPTR	accept_connection( cptr, timeout )
	CONNECTIONPTR	cptr;
	INT		timeout;
{
	INT	sslerr=0;
	INT	packetsize = sizeof( ADDRESS );

	if ( cptr != (CONNECTIONPTR) 0 )  {

		if ( await_connection(cptr,timeout) < 0 )
			return( (CONNECTIONPTR) 0 );

		/* TCP VIRTUAL CIRCUIT indicates LISTEN */
		/* ------------------------------------ */
		if ( cptr->status & _URL_LISTEN ) {
			
			/* ----------- */
			/* A C C E P T */
			/* ----------- */
			/* ------------------------------- */
			/* handle standard socket : accept */
			/* ------------------------------- */
			if ((cptr->newsocket = 
				accept(	cptr->socket,
					(ADDRPTR) &cptr->remote->address[cptr->remote->adrindex],
					(IPTR) &packetsize 
				      )) < 0 )
				return((cptr = close_connection( cptr )));

#ifdef	SYSTEM_SSL
			/* ------------------------------- */
			/* check for and handle SSL accept */
			/* ------------------------------- */
			if ( cptr->context ) {

				if (!( cptr->newobject = SSL_new( cptr->context ) ))
					return( (CONNECTIONPTR) 0 );
				else	{
					SSL_set_fd( cptr->newobject, cptr->newsocket );

	/* 
	 *	FCH ANALYSE 
	 *	quand on est serveur
	 *	ici, il faudrait prendre en compte le mode pass‚ dans httpopenserver
	 *	pour faire un SSL_set_verify pour demander un eventuel certificat au client.
	 *	Mais attention, ‡a ne doit ˆtre systŠmatique, en cas de ren‚gociation en cours 
	 *	de route
	 */
					switch ( cptr->certify ) {
						case	2 :
							if ( SSL_verbose )
								printf("SSL enforced client certification \r\n");
							SSL_set_verify( cptr->newobject,SSL_VERIFY_FAIL_IF_NO_PEER_CERT|SSL_VERIFY_PEER,NULL);
							break;
						case	1 :
							if ( SSL_verbose )
								printf("SSL relaxed client certification \r\n");
							SSL_set_verify( cptr->newobject,SSL_VERIFY_PEER,NULL);
							break;
						default	  : /* ZERO : 0 */
							if ( SSL_verbose )
								printf("SSL no client certification \r\n");
							SSL_set_verify( cptr->newobject,SSL_VERIFY_NONE,NULL);
							break;
						}
	/*
	 *	refuse normalement dŠs le d‚but si pas de certificat 
	 *	ou accepte un certificat du client (pas de callback de verif)
	 *	mais lorsque le client renvoie un nouveau Client Hello, ‡a bloque quelque part... 
	 *	(je n'ai pas encore eu le temps de chercher)
	 *	accepte normalement si pas de certificat, ou accepte un certificat du client (pas de callback de verif)
	 *	mais lorsque le client renvoie un nouveau Client Hello, ‡a bloque quelque part... 
	 */

					if ((sslerr= ssl_tcp_accept( cptr->newobject )) < 1 ) {
						if ( SSL_verbose ) {
							printf("SSL_accept failure : time=%lu address=%s return=%u ssl_error=%u, errno=%u \r\n",
								time((long) 0),
								socketname((ADDRPTR) & cptr->remote->address[cptr->remote->adrindex] ),
								sslerr,	SSL_get_error(cptr->newobject,sslerr),errno);
								cptr->status |= _URL_ACCEPT;
#ifdef UNIX
#ifndef	AIX
							while ((sslerr = ERR_get_error())) 
								if ( ERR_error_string( sslerr, SSL_ErrorBuf ) != (char *) 0) 
									printf("SSL ERR : %lu : %s \r\n",sslerr,SSL_ErrorBuf );
#endif
#endif
							}
						drop_connection( cptr );
						return( (CONNECTIONPTR) 0 );
						}
					}
				}
#endif
			/* ---------------------------- */
			/* Remember the accepted status */
			/* ---------------------------- */
			setsockopt( cptr->newsocket, SOL_SOCKET, SO_KEEPALIVE, (char*) & KeepAlive, sizeof( int ) );
			cptr->status |= _URL_ACCEPT;

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



#endif	/* _CONNECT_C */	
	/* ---------- */




