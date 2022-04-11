#ifndef _EXRPC_C	
#define	_EXRPC_C	

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXRPC.C  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	27/11/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXRPC	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/
/*	This module is a test client for the new internet service for 	*/
/*	the processing of remote program attachment requests and remote	*/
/*	procedure calls from distant remote program clients.		*/
/*	The client sends requests for program attachment and procedure	*/
/*	invocation prior to integration of this underneath the standard	*/
/*	ABAL instructions.						*/
/*----------------------------------------------------------------------*/

#include "exrps.h"
#include "exdll.h"


static	struct  remote_program_server RPC = {
	0,
	256,
	_DEFAULT_ABAL_RPS_PORT,
	AF_INET,
	2
	};

int	exatoi( char * s, int l )
{
	return( atoi( s ) );
}

static	int	failure(char * message, int evalue )
{
	printf("\nerror:%u:%s\n",evalue,message);
	return( evalue );
}

static	int	option( char * aptr )
{
	switch ( *(aptr++) )
	{
	case	'v'	:
		RPC.verbose=1;
		return(0);
	case	'p'	:
		RPC.port = atoi( aptr );
		return(0);
	default		:
		return(31);
	}
}

int	procedure_exit_value( int v )
{
	return( 1 );
}

int	procedure_exit_string( int type, char * value, int length )
{
	return( 1 );
}

int	program_client( char * aptr )
{
	int	h;
	int	status;
	struct	program_url	url;
	memset( &url,0,sizeof( struct program_url ));

	/* -------------------------------------- */
	/* split the url into its component parts */
	/* -------------------------------------- */
	if ((status = analyse_url( &url, aptr )) != 0 )
		return( failure( "url analysis",status ));

	if ( RPC.verbose )
		show_url( &url );
	
	if ((h = open_program_client( &url )) < 0 )
		return( failure( "opening program client",0));
	else
	{
		/* ------------------- */
		/* operation of client */
		/* ------------------- */
		if ( RPC.verbose )
			printf("process %u connected to host: %s:%u \n",getpid(),url.host,url.port );

		status = use_program_client( h, &url, RPC.verbose );

		/* ------------------- */
		/* end  of  connection */
		/* ------------------- */
		if ( RPC.verbose )
			printf("process %u disconnecting from host: %s:%u \n",getpid(),url.host,url.port );

		status = close_program_client( h );
		return( status );
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
		else if ((status = program_client( aptr )) != 0 )
			return(status);
		else 	continue;
	}
	return(0);
}			

static int	banner()
{
	printf("\n   Abal Remote Program Client : Version %u.%u%c.%u.%u ",3,3,'b',0,1);
	printf("\n   Provisoire du 27/11/2010 ");
	printf("\n   Copyright (c) 2010 Amenesik / Sologic \n\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}
	/* -------- */
#endif	/* _EXRPC_C */
	/* -------- */

