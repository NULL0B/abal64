#ifndef	_EXHTTP_C
#define	_EXHTTP_C

#include "exhttp.h"
#include "allocate.h"

static	char * 	temproot="/tmp/http";
static	int	tempnumber=0;

static	struct	http_cookie * HttpCookieHeap=(struct http_cookie *) 0;
static	struct	http_cookie * HttpCookieLast=(struct http_cookie *) 0;

static	int	http_cookie_hash( char * sptr )
{
	int	result = 0;
	if (  sptr )
		while ( *sptr ) 
			result += *(sptr++);
	return( result % _HTTP_COOKIE_HASH );
}

static	char *	http_allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return( sptr );
	else if (!( rptr = allocate( strlen( sptr )+1 ) ))
		return( rptr );
	else	return( strcpy(rptr,sptr ) );
}	

static	struct	http_cookie * allocate_cookie()
{
	struct	http_cookie * cptr = (struct http_cookie *) 0;
	if (!( cptr = (struct http_cookie *) allocate( sizeof( struct http_cookie ) ) ))
		return( cptr );
	else
	{
		memset( cptr, 0, sizeof( struct http_cookie ) );
		if (!( cptr->previous = HttpCookieLast ))
			HttpCookieHeap = cptr;
		else 	cptr->previous->next = cptr;
		HttpCookieLast = cptr;
		return( cptr );
	}
}

static	char *	http_retrieve_cookie( char * host, int port, char * object )
{
	struct	http_cookie * cptr;
	int	h;
	int	o;
	if ( host )	h = http_cookie_hash( host );
	else		h = 0;
	if ( object )	h = http_cookie_hash( object );
	else		h = 0;

	for (	cptr=HttpCookieHeap;
		cptr != (struct http_cookie *) 0;
		cptr = cptr->next )
	{
		if ( cptr->port != port )
			continue;
		else if ( cptr->hhash != h )
			continue;
		else if ( cptr->ohash != o )
			continue;
		if (( host ) && ( cptr->host ))
			if ( strcmp( host, cptr->host ) )
				continue;
		if (( host ) && ( cptr->host ))
			if ( strcmp( host, cptr->host ) )
				continue;
		break;	
	}
	return( cptr );
}

static	int	http_store_cookie( char * cookie, char * host, int port, char * object )
{
	struct	http_cookie * cptr;
	if (!( cptr = http_retrieve_cookie( host, port, object ) ))
	{
		if (!( cptr = allocate_cookie() ))
			return( 0 );
		else
		{
			cptr->port = port;
			if ( host )
			{
				cptr->host = http_allocate_string( host );
				cptr->hhash = http_cookie_hash( host );
			}
			if ( object )
			{
				cptr->object = http_allocate_string( object );
				cptr->ohash = http_cookie_hash( object );
			}
		}
	}

	if ( cptr->value )
		cptr->value = liberate( cptr->value );

	if ( cookie )
		cptr->value = http_allocate_string( cookie );

	return(1);
}


static	struct http_header * http_drop_header( struct http_header * fptr )
{
	if ( fptr )
	{
		if ( fptr->name )
			liberate( fptr->name );
		liberate( fptr );
	}
	return((struct http_header * ) 0);
}


struct http_response * http_drop_response( struct http_response * rptr )
{
	struct	http_header * fptr;
	if ( rptr )
	{
		while ((fptr = rptr->first) != (struct http_header *) 0)
		{
			rptr->first = fptr->next;
			http_drop_header( fptr );
		}
		if( rptr->message )
			liberate( rptr->message );
		liberate( rptr );
	}
	return((struct http_response *) 0);
}

struct http_request * http_drop_request( struct http_request * rptr )
{
	struct	http_header * fptr;
	if ( rptr )
	{
		while ((fptr = rptr->first) != (struct http_header *) 0)
		{
			rptr->first = fptr->next;
			http_drop_header( fptr );
		}
		if( rptr->method )
			liberate( rptr->method );
		if( rptr->object )
			liberate( rptr->object );
		liberate( rptr );
	}
	return((struct http_request *) 0);
}

int	http_request_line( int handle, char * method, char * object )
{
	char	buffer[MAX_HTTP_BUFFER];
	sprintf(buffer,"%s %s HTTP/1.0\r\n",method,object);
	return( putline_tcp( handle, buffer, strlen( buffer) ));
}


int	http_response_line( int handle, int status, char * message )
{
	char	buffer[MAX_HTTP_BUFFER];
	sprintf(buffer,"HTTP/1.0 %u %s\r\n",status,message);
	return( putline_tcp( handle, buffer, strlen( buffer) ));
}

int	http_header_field( int handle, char * name, char * value )
{
	char	buffer[MAX_HTTP_BUFFER];
	sprintf(buffer,"%s: %s\r\n",name,value);
	return( putline_tcp( handle, buffer, strlen( buffer) ));
}

static	int	http_headers( int handle, char * host )
{
	http_header_field(handle,"User-Agent","AbalSoapRpcClient/1.0");
	http_header_field(handle,"Accept","*/*");
	http_header_field(handle,"Host",host);
}

int	http_end_header( int handle )
{
	return( putline_tcp( handle, "\r\n", strlen("\r\n") ) );
}

int	http_content_length( int handle, char * filename )
{
	char	buffer[256];
	struct	stat	S;
	if ( stat( filename, &S ) < 0 )
		return(0);
	else
	{
		sprintf(buffer,"%lu",S.st_size);
		http_header_field(handle,"Content-Length",buffer);
		return( 0 );
	}
}

int	http_put_server_cookie( int handle, char * value )
{
	if ( value )
	{
		http_header_field(handle,"Set-Cookie",value);
	}
	return(0);
}

int	http_put_client_cookie( int handle, char * value )
{
	if ( value )
	{
		http_header_field(handle,"Cookie",value);
	}
	return(0);
}

int	http_send_file( int handle, char * filename )
{
	char	buffer[_HTTP_FILE_BUFFER];
	struct	stat	S;
	int	i=0;
	int	n=0;
	int	fh;
	
	if ((fh = open( filename, 0 )) < 0 )
		return( 0 );
	else if ( fstat( fh, &S ) < 0 )
	{
		close(fh);
		return(0);
	}
	else
	{
		while ( i < S.st_size )
		{
			if ((n = (S.st_size-i)) > _HTTP_FILE_BUFFER)
				n = _HTTP_FILE_BUFFER;
			if ( read( fh,buffer,n ) != n )
				break;
//			printf("send file tcp( %u + %u  of %u )\r\n",i,n,S.st_size);
			if ( write_tcp( handle,buffer, n ) != n )
				break;
			else	i += n;
		}
		close( fh );
		return( 0 );
	}
}

static	int	http_send_request( int handle, char * method, char * object, char * host, char * cookie )
{
	http_request_line( handle, method, object );
	http_headers( handle, host );
	http_put_client_cookie( handle, cookie );
	http_end_header( handle );
	return( 0 );
}

int	http_send_file_request( int handle, char * method, char * object, char * host, char * filename, char * cookie )
{
	http_request_line( handle, method, object );
	http_headers( handle, host );
	http_put_client_cookie( handle, cookie );
	http_content_length( handle, filename );
	http_end_header( handle );
	http_send_file( handle, filename );
	return( 0 );
}

static	struct	http_header * http_recv_field( int handle )
{
	char	buffer[MAX_HTTP_BUFFER];
	char *	sptr;
	int	l;
	struct	http_header * fptr;
	if (!(l = getline_tcp( handle, buffer, MAX_HTTP_BUFFER-1 ) ))
		return((struct http_header *) 0);
	else if (!( fptr = (struct http_header *) allocate( sizeof( struct http_header ) )))
		return( fptr );
	else	memset( fptr, 0, sizeof( struct http_header ) );
	if (!( fptr->name = allocate( l+1 ) ))
		return( http_drop_header( fptr ) );
	else	
	{
		strcpy((sptr = fptr->name),buffer);
		while ((*sptr != 0) && ( *sptr != ':')) sptr++;
		*(sptr++) = 0;
		while ((*sptr != 0) && ( *sptr == ' ')) sptr++;
		fptr->value = sptr;
		return( fptr );
	}
}	

static	struct	http_response * http_recv_response( int handle )
{
	char	buffer[MAX_HTTP_BUFFER];
	struct	http_response * rptr;
	struct	http_header * fptr;
	char *	sptr;
	if (!( rptr = (struct http_response *) allocate( sizeof( struct http_response ) ) ))
		return( rptr );
	else	memset( rptr, 0, sizeof( struct http_response ) );

	if (!( getline_tcp( handle, (sptr=buffer), MAX_HTTP_BUFFER-1 ) ))
		return( rptr );
	while ((*sptr != 0) && ( *sptr != ' ')) sptr++;
	*(sptr++) = 0;
	rptr->status = atoi( sptr );
	while ((*sptr != 0) && ( *sptr != ' ')) sptr++;
	*(sptr++) = 0;
	if (!( rptr->message = http_allocate_string( sptr ) ))
		return( rptr );
	while ((fptr = http_recv_field( handle )) != (struct http_header *) 0)
	{
		if (!( fptr->previous = rptr->last ))
			rptr->first = fptr;
		else	rptr->last->next = fptr;
		rptr->last = fptr;
	}
	return( rptr );
}

char *	http_header_value( struct http_header * hptr, char * name )
{
	struct	http_header * fptr;
	for (	fptr=hptr;
		fptr != (struct http_header *) 0;
		fptr = fptr->next )
		if (!( strcasecmp( fptr->name, name )))
			return( fptr->value );
	return((char *) 0);
}		

char *	http_get_server_cookie( struct http_header * hptr )
{
	return( http_header_value( hptr, "Set-Cookie" ) );
}

char *	http_get_client_cookie( struct http_header * hptr )
{
	return( http_header_value( hptr, "Cookie" ) );
}

int	http_file_response( int handle, struct http_response * rptr, char * filename )
{
	char	buffer[_HTTP_FILE_BUFFER];
	char *	clength;
	int	bytes;
	int	xfer=0;
	int	recvd=0;
	int	status;
	FILE * 	fh;
	if (( clength = http_header_value( rptr->first, "CONTENT-LENGTH" )) != (char *) 0)
 		bytes = atoi( clength );
	else	bytes = 0;
	status = rptr->status;
	if ( bytes )
	{
		if ((fh = fopen( filename, "w")) != (FILE *) 0)
		{
			while( recvd < bytes )		
			{
				if ((xfer = (bytes - xfer)) > _HTTP_FILE_BUFFER)
					xfer = _HTTP_FILE_BUFFER;
				if ( read_tcp( handle, buffer, xfer ) != xfer )
					break;
				else
				{	
					fwrite( buffer, xfer, 1, fh );
					recvd += xfer;
				}
			}
			fclose( fh );
		}
	}
	close_tcp( handle );
	http_drop_response( rptr );
	return( status );
}

int	http_recv_file_request( int handle, struct http_request * rptr, char * filename )
{
	char	buffer[_HTTP_FILE_BUFFER];
	char *	clength;
	int	bytes;
	int	xfer=0;
	int	recvd=0;
	FILE * 	fh;
	if (( clength = http_header_value( rptr->first, "CONTENT-LENGTH" )) != (char *) 0)
 		bytes = atoi( clength );
	else	bytes = 0;
	if ( bytes )
	{
		if ((fh = fopen( filename, "w")) != (FILE *) 0)
		{
			while( recvd < bytes )		
			{
				if ((xfer = (bytes - xfer)) > _HTTP_FILE_BUFFER)
					xfer = _HTTP_FILE_BUFFER;
				if ( read_tcp( handle, buffer, xfer ) != xfer )
					break;
				else
				{	
					fwrite( buffer, xfer, 1, fh );
					recvd += xfer;
				}
			}
			fclose( fh );
		}
	}
	return( bytes );
}

int	http_get( char * host, int port, char * object, char * infilename )
{
	char *	cookie;
	int	handle;
	struct	http_response * rptr;

	cookie = http_retrieve_cookie( host, port, object );

	if ((handle = connect_tcp( host, port )) == -1 )
		return( 500 );
	else if ( http_send_request( handle, "GET", object, host, cookie ) != 0)
	{
		close_tcp( handle );
		return( 501 );
	}
	else if (!(rptr = http_recv_response( handle )))
	{
		close_tcp( handle );
		return( 502 );
	}
	else if (!( http_store_cookie( http_get_server_cookie( rptr->first ), host, port, object ) ))
	{
		close_tcp( handle );
		return( 502 );
	}
	else 	return( http_file_response(handle, rptr, infilename ) );
}

int	http_post( char * host, int port, char * object, char * outfilename, char * infilename )
{
	char *	cookie;
	int	handle;
	struct	http_response * rptr;

	cookie = http_retrieve_cookie( host, port, object );

	if ((handle = connect_tcp( host, port )) == -1 )
		return(500);
	else if (  http_send_file_request( handle, "POST", object, host, outfilename, cookie ) != 0)
	{
		close_tcp( handle );
		return(501);
	}
	else if (!(rptr = http_recv_response( handle )))
	{
		close_tcp( handle );
		return(502);
	}
	else if (!( http_store_cookie( http_get_server_cookie( rptr->first ), host, port, object ) ))
	{
		close_tcp( handle );
		return( 502 );
	}
	else 	return( http_file_response(handle, rptr, infilename ) );
}

char *	http_tempname()
{
	char	tempnamebuffer[1024];
	char *	rptr;
	sprintf(tempnamebuffer,"%s/ex%uhttp%u.tmp",temproot,getpid(),++tempnumber);
	return( http_allocate_string( tempnamebuffer ) );

}

struct	http_request * http_recv_request( int handle )
{
	char	buffer[MAX_HTTP_BUFFER];
	struct	http_header  * fptr;	
	struct	http_request * rptr;
	char *	sptr;
	char *	optr;
	if (!( rptr = (struct	http_request *) allocate( sizeof( struct http_request ) ) ))
		return( rptr );
	else	memset( rptr, 0, sizeof( struct http_request ) );

	if (!( getline_tcp( handle,(sptr = buffer), MAX_HTTP_BUFFER-1 ) ))
		return( http_drop_request( rptr ) );
	else
	{
		while ((*sptr != 0) && ( *sptr != ' ')) sptr++;
		*(sptr++) = 0;
		if (!( rptr->method = http_allocate_string( buffer ) ))
			return( http_drop_request( rptr ) );
		optr = sptr;
		while ((*sptr != 0) && ( *sptr != ' ')) sptr++;
		*(sptr++) = 0;
		if (!( rptr->object = http_allocate_string( optr ) ))
			return( http_drop_request( rptr ) );
		while ((fptr = http_recv_field( handle )) != (struct http_header *) 0)
		{
			if (!( fptr->previous = rptr->last ))
				rptr->first = fptr;
			else	rptr->last->next = fptr;
			rptr->last = fptr;
		}
		if (!( rptr->host = http_header_value( rptr->first, "HOST" ) ))
			return( http_drop_request( rptr ) );
		else	return( rptr );
	}
}

	/* --------- */
#endif	/* _EXHTTP_C */
	/* --------- */


