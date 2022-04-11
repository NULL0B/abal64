#ifndef _EXMPEGCL_C	
#define	_EXMPEGCL_C	

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMPEGCL.C  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	27/11/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXMPEGC	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/
/*	This module is a test client for the new internet service for 	*/
/*	the processing of remote mpeg attachment requests and remote	*/
/*	procedure calls from distant remote mpeg clients.		*/
/*	The client sends requests for mpeg attachment and procedure	*/
/*	invocation prior to integration of this underneath the standard	*/
/*	ABAL instructions.						*/
/*----------------------------------------------------------------------*/

#include "exmpegs.h"


static	struct  remote_mpeg_server MPEGC = {
	0,
	256,
	_DEFAULT_ABAL_MPEGS_PORT,
	AF_INET,
	2
	};

static	void	show_url( struct mpeg_url * uptr )
{
	if ( uptr )
	{
		if ( uptr->host )
			printf("host=%s\n",uptr->host);
		if ( uptr->port )
			printf("port=%u\n",uptr->port);
		if ( uptr->mpeg )
			printf("mpeg=%s\n",uptr->mpeg);
		if ( uptr->procedure )
			printf("procedure=%s\n",uptr->procedure);
		if ( uptr->parameters )
			printf("parameters=%s\n",uptr->parameters);
	}
	return;
}	

#include "exmpeg.c"
static	int	failure(char * message, int evalue )
{
	return( -1 );
}

static	void *	allocate( int n )
{
	return((void *) malloc( n ) );
}

static	void * liberate( void * v )
{
	if ( v )
		free( v );
	return((void *) 0);
}

static	char *	allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return((char *) 0);
	else if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	return( strcpy( rptr, sptr ) );
}

int	analyse_mpeg_url( struct mpeg_url * uptr, char * sptr )
{
	char *	wptr=sptr;
	char 	buffer[8192];
	int	i;
	int	phase=0;
	struct	servent *	service;

	/* ---------------------------------- */
	/* collect and convert service prefix */
	/* ---------------------------------- */
	if (( i = extract_portion( buffer, &wptr, ":" )) > 0 )
	{
		if (!( uptr->port = atoi( buffer) ))
		{
			if (!( service = getservbyname( buffer,0 )))
				return(30);
			else	uptr->port = service->s_port;
		}
		wptr++;
	}		
	if (( *wptr == '/' ) && ( *(wptr+1) == '/' ))
		wptr += 2;
	if (( i = extract_portion( buffer, &wptr, "/" )) > 0 )
		if (!( uptr->host = allocate_string( buffer ) ))
			return( 27 );

	if (( i = extract_portion( buffer, &wptr, "#" )) > 0 )
	{
		if (!( uptr->mpeg = allocate_string( buffer ) ))
			return( 27 );
		else if (( i = extract_portion( buffer, &wptr, "?" )) > 0 )
		{
			if (!( uptr->procedure = allocate_string( buffer ) ))
				return( 27 );
			else if (!( uptr->parameters = allocate_string( wptr ) ))
				return( 27 );
		}
		else if (!( uptr->procedure = allocate_string( wptr ) ))
			return( 27 );
	}
	else if (( i = extract_portion( buffer, &wptr, "?" )) > 0 )
	{
		if (!( uptr->mpeg = allocate_string( buffer ) ))
			return( 27 );
		else if (!( uptr->parameters = allocate_string( wptr ) ))
			return( 27 );
	}
	else if (!( uptr->mpeg = allocate_string( wptr ) ))
		return( 27 );

	if ( MPEGC.verbose )
		show_url( uptr );
	
	return( 0 );
}

/*	------------------------------------------	*/
/*	     o p e n _ m p e g _ c l i e n t		*/
/*	------------------------------------------	*/
/*	the parameter aptr is an url of the form	*/
/*	service://host:port/object?parameters		*/
/*	------------------------------------------	*/
int	open_mpeg_client( char * aptr )
{
	int	status=0;
	int	h=0;
	int	hh;
	int	optval=60;
	char *	wptr;
	char	buffer[4096];
	unsigned  char tempxfer[4];
	struct  hostent *hp=(struct hostent *) 0;
	struct sockaddr_in address;
	struct sockaddr_in server;
	int	worker;
	int	length=sizeof( struct sockaddr );
	struct	mpeg_url url = { 0, (char *) 0, (char *) 0, (char *) 0, (char *) 0 };
	struct	timeval TimeOut;
	fd_set	r;
	fd_set 	w;
	fd_set	x;

	/* -------------------------------------- */
	/* split the url into its component parts */
	/* -------------------------------------- */
	if ((status = analyse_mpeg_url( &url, aptr )) != 0 )
	{
		return( failure( "url analysis",status ));
	}
	else if (!( url.host ))
	{
		return( failure( "url requires //host",31 ));
	}
	else if (!( url.port ))
	{
		return( failure( "url requires port:",33 ));
	}

	/* ------------------ */
	/* open server socket */
	/* ------------------ */
	if ((h = socket(MPEGC.domain,SOCK_STREAM,0)) < 0)
	{
		return( failure("socket creation",errno) );
	}
	/* ------------------------- */
	/* set server socket options */
	/* ------------------------- */
	else if ( setsockopt(h, SOL_SOCKET, (SO_KEEPALIVE | SO_REUSEADDR), (int *) & optval, sizeof( optval )) < 0 )
	{
		close( h );
		return( failure("socket options",errno) );
	}

	/* ---------------------------- */
	/* bind socket to local address */
	/* ---------------------------- */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(0);
	if ( bind(h, &server, sizeof( struct sockaddr )) < 0 ) 
	{
		close( h );
		return( failure("socket bind",errno) );
	}

	/* ----------------- */
	/* resolve host name */
	/* ----------------- */
     	if (!(hp = gethostbyname(url.host)))
		return( failure("resolving host name",errno) );
	else 	
	{
		/* -------------------------- */
		/* attempt to connect to host */
		/* -------------------------- */
		server.sin_family = MPEGC.domain;
		memcpy(tempxfer, hp->h_addr_list[0],4);
		memcpy(&server.sin_addr.s_addr,tempxfer,4);
		server.sin_port = htons(url.port);
		if ( connect( h, 
			(struct sockaddr *) & server,
			sizeof( struct sockaddr ) ) < 0 )
		{
			close( h );
			return( failure("socket connect",errno) );
		}
	}

	/* ------------------------ */
	/* return the socket handle */
	/* ------------------------ */
	return( h );

}

int	puts_mpeg_client( int h, char * s )
{
	return( send( h, s, strlen(s),0) );
}

int	putc_mpeg_client( int h, int c )
{
	char	b[2];
	b[0] = c;
	b[1] = 0;
	return( puts_mpeg_client( h, b ) );
}

int	close_mpeg_client( int h )
{
	/* ------------------- */
	/* end  of  connection */
	/* ------------------- */
	shutdown(h,2);
	close(h);
	return(-1);
}

int	option_mpeg_client( char * aptr )
{
	switch ( *(aptr++) )
	{
	case	'-'	:
		if (!( strcmp( aptr, "ip" ) ))
			MPEGC.domain = AF_INET;
		else if (!( strcmp( aptr, "ipv6" ) ))
			MPEGC.domain = AF_INET6;
		return(0);

	case	'v'	:
		MPEGC.verbose=1;
		return(0);
	case	'p'	:
		MPEGC.port = atoi( aptr );
		return(0);
	default		:
		return(31);
	}
}

	/* ----------- */
#endif	/* _EXMPEGCL_C */
	/* ----------- */

