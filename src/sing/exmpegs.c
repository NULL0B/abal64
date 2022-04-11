#ifndef _EXMPEGS_C	
#define	_EXMPEGS_C	
#undef	_FORKING
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMPEGS.C  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	27/11/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXMPEGS	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/
/*	This module is the front end providing an internet service for 	*/
/*	the processing of remote mpeg attachment requests and remote	*/
/*	procedure calls from distant remote mpeg clients.		*/
/*	The service is built around the runtime library shared object	*/
/*	often refered to as the abal call through extension offering 	*/
/*	mpeg loading and execution as a shared library instead of as	*/
/*	the more usual stand alone mpeg known as exa.		*/
/*----------------------------------------------------------------------*/
#define __USE_LARGEFILE64
#define	__USE_FILE_OFFSET64

#include "exmpegs.h"

static	struct  remote_mpeg_server MPEGS = {
	0,
	256,
	_DEFAULT_ABAL_MPEGS_PORT,
	AF_INET,
	2,
	""
	};


static	int	failure(char * message, int evalue )
{
	printf("\nerror:%u:%s\n",evalue,message);
	return( evalue );
}

static	void	consume_data( char * buffer )
{
	if ( MPEGS.verbose )
		printf("%s",buffer);
	return;
}

static	void	mpeg_client(int h)
{
	struct	abal_mpeg_handle * aph=(struct abal_mpeg_handle *) 0;
	char	command[4097];
	char *	sptr;

	if ( MPEGS.verbose )
		printf("mpeg client connection: pid=%u\n",getpid());

	while (1) 
	{
		if ( read_command( h, command, 4096 ) != 0 )
		{
			consume_data( command );
		}
	}

	if ( MPEGS.verbose )
		printf("mpeg client shutdown: pid=%u\n",getpid());
	shutdown(h,SHUT_RDWR);
	close(h);
#ifdef	_FORKING
	exit(0);
#else
	return;
#endif
}

static	int	mpeg_server( char * aptr, int domain, int port, int clients )
{
	int	status=0;
	int	h=0;
	int	hh;
	int	optval=60;
	char *	wptr;
	unsigned  char tempxfer[4];
	struct  hostent *hp=(struct hostent *) 0;
	struct sockaddr_in address;
	struct sockaddr_in server;
	int	worker;
	int	length=sizeof( struct sockaddr );

	struct	timeval TimeOut;
	fd_set	r;
	fd_set 	w;
	fd_set	x;

	/* ------------------ */
	/* open server socket */
	/* ------------------ */
	if ((h = socket(domain,SOCK_STREAM,0)) < 0)
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
	server.sin_port = htons(port);
	if ( bind(h, &server, sizeof( struct sockaddr )) < 0 ) 
	{
		close( h );
		return( failure("socket bind",errno) );
	}
	/* --------------------------- */
	/* enable socket for listening */
	/* --------------------------- */
	else if ( listen( h, clients ) < 0 ) 
	{
		close( h );
		return( failure("socket listen",errno) );
	}

	while (1)
	{
		if ( MPEGS.verbose )
			printf("%s: select\n",aptr);
		FD_ZERO(&r);
		FD_ZERO(&w);
		FD_ZERO(&x);
		FD_SET(h,&r);
		TimeOut.tv_sec = (unsigned long) MPEGS.seconds;
		TimeOut.tv_usec = (unsigned long) 0;
		if ((status = select( h+1, &r, NULL, NULL ,&TimeOut )) < 0 )
			continue;
		else if ((hh = accept( h, &address, &length )) < 0 )
			continue;
#ifdef	_FORKING
		else if ((worker = fork()) != 0)
		{
			shutdown(hh,SHUT_RDWR);
			close(hh);
			continue;
		}
#endif
		else	mpeg_client(hh);
	}
	return(0);
}

static	int	option( char * aptr )
{
	switch ( *(aptr++) )
	{
	case	'-'	:
		if (!( strcmp( aptr, "ip" ) ))
			MPEGS.domain = AF_INET;
		else if (!( strcmp( aptr, "ipv6" ) ))
			MPEGS.domain = AF_INET6;
		return(0);

	case	'v'	:
		MPEGS.verbose=1;
		return(0);
	case	'p'	:
		MPEGS.port = atoi( aptr );
		return(0);
	case	'r'	:
		MPEGS.root = aptr;
		return(0);
	default		:
		return(31);
	}
}

static	int	operation(int argc, char * argv[])
{
	int	status;
	int	argi;
	char *	aptr;
	for (	argi=1; argi < argc; argi++ )
	{
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
		{
			if ((status = option( (aptr+1) )) != 0)
				return(status);
			else 	continue;
		}
		else if ((status = mpeg_server( aptr, MPEGS.domain, MPEGS.port, MPEGS.clients )) != 0 )
			return(status);
		else 	continue;
	}
	return(0);
}			

static int	banner()
{
	printf("\n   Abal MPEG Server : Version %u.%u%c.%u.%u ",3,3,'b',0,1);
	printf("\n   Provisoire du 27/11/2010 ");
	printf("\n   Copyright (c) Amenesik / Sologic \n\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}
	/* -------- */
#endif	/* _EXMPEGS_C */
	/* -------- */

