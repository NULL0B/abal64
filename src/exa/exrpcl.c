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
#include "exvtype.h"
#include "exrpcl.h"
#include "abalrpc.h"

char * rpc_parse_parameter( char * );

static	int	(*setexitvalue)(int) = (void *) 0;
static	int	(*setexitstring)(int,char *, int) = (void *) 0;

void	set_exit_connection( void * v, void * s )
{
	setexitvalue = v;
	setexitstring = s;
}

void	show_url( struct program_url * uptr )
{
	if ( uptr )
	{
		if ( uptr->service )
			printf("service=%s\n",uptr->service);
		if ( uptr->host )
			printf("host=%s\n",uptr->host);
		if ( uptr->port )
			printf("port=%u\n",uptr->port);
		if ( uptr->program )
			printf("program=%s\n",uptr->program);
		if ( uptr->procedure )
			printf("procedure=%s\n",uptr->procedure);
		if ( uptr->parameters )
			printf("parameters=%s\n",uptr->parameters);
	}
	return;
}	

static char *	allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return((char *) 0);
	else if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	return( strcpy( rptr, sptr ) );
}

int	analyse_url( struct program_url * uptr, char * sptr )
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
		if (!( uptr->service = allocate_string( buffer ) ))
			return( 27 );
		else if (!( uptr->port = atoi( buffer )))
		{
			if (!( service = getservbyname( buffer,"tcp" )))
				return(30);
			else	uptr->port = ntohs(service->s_port);
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
		if (!( uptr->program = allocate_string( buffer ) ))
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
		if (!( uptr->program = allocate_string( buffer ) ))
			return( 27 );
		else if (!( uptr->parameters = allocate_string( wptr ) ))
			return( 27 );
	}
	else if (!( uptr->program = allocate_string( wptr ) ))
		return( 27 );

	return( 0 );
}

static	void *	drop_abal_rpcc( struct abal_remote_procedure_context * kptr )
{
	if ( kptr )
	{
		if ( kptr->socket != -1 )
		{
			shutdown( kptr->socket, 2 );
			close( kptr->socket );
		}
		liberate( kptr );
	}
	return((void *) 0);
}

/*	------------------------------------------	*/
/*	  o p e n _ p r o g r a m _ c l i e n t		*/
/*	------------------------------------------	*/
/*	the parameter aptr is an url of the form	*/
/*	service://host:port/object?parameters		*/
/*	------------------------------------------	*/
void *	open_program_client( struct program_url * url )
{
	struct abal_remote_procedure_context * kptr;
	int	status=0;
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

	if (!( kptr = allocate( sizeof ( struct abal_remote_procedure_context ) )))
		return( kptr );
	else
	{
		memset( kptr, 0, sizeof ( struct abal_remote_procedure_context ));
		kptr->socket = -1;
	}

	if (!( url->service ))
	{
		return( drop_abal_rpcc( kptr ) );
	}
	else if ( strcmp(url->service,"abalrpc" ) )
	{
		return( drop_abal_rpcc( kptr ) );
	}
	else if (!( url->host ))
	{
		return( drop_abal_rpcc( kptr ) );
	}
	else if (!( url->program ))
	{
		return( drop_abal_rpcc( kptr ) );
	}
	else if (!( url->port ))
	{
		return( drop_abal_rpcc( kptr ) );
	}

	/* ------------------ */
	/* open server socket */
	/* ------------------ */
	if ((kptr->socket = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		return( drop_abal_rpcc( kptr ) );
	}
	/* ------------------------- */
	/* set server socket options */
	/* ------------------------- */
	else if ( setsockopt(kptr->socket, SOL_SOCKET, (SO_KEEPALIVE | SO_REUSEADDR), (int *) & optval, sizeof( optval )) < 0 )
	{
		return( drop_abal_rpcc( kptr ) );
	}

	/* ---------------------------- */
	/* bind socket to local address */
	/* ---------------------------- */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(0);
	if ( bind(kptr->socket, &server, sizeof( struct sockaddr )) < 0 ) 
	{
		return( drop_abal_rpcc( kptr ) );
	}

	/* ----------------- */
	/* resolve host name */
	/* ----------------- */
     	if (!(hp = gethostbyname(url->host)))
		return( drop_abal_rpcc( kptr ) );
	else 	
	{
		/* -------------------------- */
		/* attempt to connect to host */
		/* -------------------------- */
		server.sin_family = AF_INET;
		memcpy(tempxfer, hp->h_addr_list[0],4);
		memcpy(&server.sin_addr.s_addr,tempxfer,4);
		server.sin_port = htons(url->port);
		if ( connect( kptr->socket, 
			(struct sockaddr *) & server,
			sizeof( struct sockaddr ) ) < 0 )
		{
			return( drop_abal_rpcc( kptr ) );
		}
		return( kptr );
	}
}

int	attach_program_client( void * h, struct program_url * url, char * xptr  )
{
	char	buffer[4096];
	char *	rptr;
	int	v=0;
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) return( 0);
		
	sprintf(buffer,"ATTACH %s%s\r\n",(url->program+1),xptr);
	write_tcp( kptr->socket, buffer, strlen(buffer), 0 );
	getline_tcp( kptr->socket,(rptr = buffer), 16 );
	if ((*rptr == 'O') && (*(rptr+1) == 'K'))
	{
		for (	v=0,rptr+=3; *rptr > ' '; rptr++ )
		{
			if ((*rptr >= '0') && ( *rptr<='9'))
				v = ((v*10) + (*rptr -'0'));
			else	break;
		}
		return( v );
	}
	else	return( 0 );
}

static	int	exit_remote_value( char * sptr, int bytes )
{
	if (!( setexitvalue ))
		return(118);
	else
	{
		(*setexitvalue)( rpc_parse_hex_value( &sptr, bytes ) );
		return(0);
	}
}

static	int	exit_remote_string( char * sptr, int type )
{
	char	buffer[8192];
	int		length;
	length = atoi(sptr);

	if (!( sptr = rpc_parse_parameter( sptr )))
		return( 33 );
	else
	{
		rpc_parse_hex_string(buffer, &sptr, length );
		if (!( setexitstring ))
			return(118);
		else if (!( (*setexitstring)( type,buffer, length ) ))
			return( 34 );
		else	return( 0 );
	}
}

int	exit_program_client( void * h )
{
	int	type;
	int	value;
	char *	rptr;
	char *	sptr;
	char	buffer[8193];
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) return( 0);
	if (!( getline_tcp( kptr->socket, buffer, 8192) ))
		return( errno );
	else if (!( rptr = rpc_parse_parameter( buffer )))
		return( 330 );
	else if ( strcmp( buffer,"EXIT" ) )
	{
		if ( strcmp( buffer, "ERROR" ) )
			return( 331 );	
		else	return( atoi( rptr ) );
	}
	else if (!( sptr = rpc_parse_parameter( rptr )))
		return( 332 );
	else
	{
		switch ( *rptr )
		{
		case	'B'	: return( exit_remote_value( sptr, 1 ) );
		case	'W'	: return( exit_remote_value( sptr, 2 ) );
		case	'L'	: return( exit_remote_value( sptr, 4 ) );
#ifdef	ABAL64
		case	'H'	: return( exit_remote_value( sptr, 8 ) );
#endif
		case	'N'	: return( exit_remote_string( sptr, VARB_BCD ));
		case	'S'	: return( exit_remote_string( sptr, VARB_STR ));
		default		: return( 0 );
		}
	}
}

int	call_program_client( void * h, int procid , char * pptr )
{
	char	buffer[4096];
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) return( 0);
	if (!( pptr ))
		sprintf(buffer,"CALL #%u\r\n",procid);
	else	sprintf(buffer,"CALL #%u(%s)\r\n",procid,pptr);
	if ( write_tcp( kptr->socket, buffer, strlen(buffer), 0 ) < 0 )
		return( 400+errno );
	else	return( exit_program_client( h ) );
}

int	call_program_parameters( void * h, int argc, char * argv )
{
	char	buffer[4096];
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) return( 0);
	sprintf(buffer,"ARGS %u ",argc);
	if ( write_tcp( kptr->socket, buffer, strlen(buffer), 0 ) < 0 )
		return( 400+errno );
	else if ( write_tcp( kptr->socket, argv, strlen(argv), 0 ) < 0 )
		return( 400+errno );
	else if ( write_tcp( kptr->socket, "\r\n", strlen("\r\n"), 0 ) < 0 )
		return( 400+errno );
	else if ( getline_tcp( kptr->socket, buffer, 16 ) )
		return( 0 );
	else	return( 400+errno );
}


int	detach_program_client( void * h )
{
	char	buffer[4096];
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) return( 0);
	sprintf(buffer,"DETACH\r\n");
	write_tcp( kptr->socket, buffer, strlen(buffer), 0 );
	getline_tcp( kptr->socket, buffer, 16 );
	return( 0 );
}

int	use_program_client( void * h, struct program_url * url, int verbose )
{
	char	buffer[4096];
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) return( 0);

	/* ----------------------- */
	/* send program attachment */
	/* ----------------------- */
	attach_program_client( h, url,".at" );

	if (!( url->procedure ))
		sprintf(buffer,"LDGO 0\r\n");
	else if (!( url->parameters ))
		sprintf(buffer,"CALL %s\r\n",(url->procedure+1));
	else	sprintf(buffer,"CALL %s(%s)\r\n",(url->procedure+1),url->parameters);
	if ( verbose ) printf("send: %s",buffer);
	write_tcp( kptr->socket, buffer, strlen(buffer), 0 );
	if ( getline_tcp( kptr->socket, buffer, 16 ) )
	if ( verbose ) printf("recv: %s\r\n",buffer);

	detach_program_client( h );

	sprintf(buffer,"STOP\r\n");
	if ( verbose ) printf("send: %s",buffer);
	write_tcp( kptr->socket, buffer, strlen(buffer), 0 );
	if ( getline_tcp( kptr->socket, buffer, 16 ) )
	if ( verbose ) printf("recv: %s\r\n",buffer);

	return(0);
}

void * close_program_client( void * h )
{
	struct abal_remote_procedure_context * kptr;
	if (!( kptr = h )) 
		return( (void *) 0);
	else	return( drop_abal_rpcc( kptr ) );
}

	/* -------- */
#endif	/* _EXRPC_C */
	/* -------- */

