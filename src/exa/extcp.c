#ifndef	_EXTCP_C
#define	_EXTCP_C

#include "extcp.h"

//#define	DEBUG_TCP

int	close_tcp( int handle )
{
	if ( handle != -1 )
	{	
		shutdown( handle, 2 );
		close( handle );
	}
	return( -1 );
}

int	getline_tcp( int h, char * b, int blen )
{
	unsigned char c[4];
	int		o=0;
	while (o < blen) {
		if ( recv( h, c, 1, MSG_WAITALL ) <= 0 )
			break;
		else if ( c[0] == '\r' )
			continue;
		else if ( c[0] == '\n' )
			break;
		else if ( c[0] == '\t' )
			c[0] = ' ';
		else	{
			*(b+o) = c[0];
			o++;
			}
		}
	*(b+o) = 0;
#ifdef	DEBUG_TCP
	printf("%s\r\n",b);
#endif
	return(o);
}

int	connect_tcp( char * host, int port )
{
	int	handle;
	int	status=0;
	int	optval=60;
	char *	wptr;
	unsigned  char tempxfer[4];
	struct  hostent *hp=(struct hostent *) 0;
	struct sockaddr_in address;
	struct sockaddr_in server;
	int	worker;
	int	length=sizeof( struct sockaddr );

	/* ------------------ */
	/* open server socket */
	/* ------------------ */
	if ((handle = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		return( -1 );
	}
	/* ------------------------- */
	/* set server handle options */
	/* ------------------------- */
	else if ( setsockopt(handle, SOL_SOCKET, (SO_KEEPALIVE | SO_REUSEADDR), (int *) & optval, sizeof( optval )) < 0 )
	{
		return( -1 );
	}

	/* ---------------------------- */
	/* bind handle to local address */
	/* ---------------------------- */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(0);
	if ( bind(handle, &server, sizeof( struct sockaddr )) < 0 ) 
	{
		return( -1 );
	}

	/* ----------------- */
	/* resolve host name */
	/* ----------------- */
     	if (!(hp = gethostbyname(host)))
		return( -1 );
	else 	
	{
		/* -------------------------- */
		/* attempt to connect to host */
		/* -------------------------- */
		server.sin_family = AF_INET;
		memcpy(tempxfer, hp->h_addr_list[0],4);
		memcpy(&server.sin_addr.s_addr,tempxfer,4);
		server.sin_port = htons(port);
		if ( connect( handle, 
			(struct sockaddr *) & server,
			sizeof( struct sockaddr ) ) < 0 )
		{
			return( -1 );
		}
		return( handle );
	}
}

int	listen_tcp( int port, int clients )
{
	int	handle;
	int	status=0;
	int	optval=60;
	char *	wptr;
	unsigned  char tempxfer[4];
	struct  hostent *hp=(struct hostent *) 0;
	struct sockaddr_in address;
	struct sockaddr_in server;
	int	worker;
	int	length=sizeof( struct sockaddr );

	/* ------------------ */
	/* open server socket */
	/* ------------------ */
	if ((handle = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		return( -1 );
	}
	/* ------------------------- */
	/* set server handle options */
	/* ------------------------- */
	else if ( setsockopt(handle, SOL_SOCKET, (SO_KEEPALIVE | SO_REUSEADDR), (int *) & optval, sizeof( optval )) < 0 )
	{
		close_tcp( handle );
		return( -1 );
	}

	/* ---------------------------- */
	/* bind handle to local address */
	/* ---------------------------- */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(port);
	if ( bind(handle, &server, sizeof( struct sockaddr )) < 0 ) 
	{
		close_tcp( handle );
		return( -1 );
	}
	/* --------------------------- */
	/* enable socket for listening */
	/* --------------------------- */
	else if ( listen( handle, clients ) < 0 ) 
	{
		close_tcp( handle );
		return( -1 );
	}
	else	return( handle );
}

int	read_tcp(int handle, char * buffer, int length )
{
	return( recv( handle, buffer, length,MSG_WAITALL ) );
}

int	write_tcp(int handle, char * buffer, int length )
{
	return( send( handle, buffer, length, 0 ) );
}

int	putline_tcp(int handle, char * buffer, int length )
{
#ifdef	DEBUG_TCP
	printf("%s",buffer);
#endif
	return( send( handle, buffer, length, 0 ) );
}

int	service2port_tcp( char * name )
{
	struct	servent *	service;
	if (!( service = getservbyname( name, "tcp" )))
		return(0);
	else	return( ntohs(service->s_port) );
}
	/* -------- */
#endif	/* _EXTCP_C */
	/* -------- */

