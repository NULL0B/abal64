#ifndef	_HTTP_C
#define	_HTTP_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "url.h"
#include "files.h"
#include "http.h"
#include "httpssl.h"
#include "abalssl.h"

#include <time.h>

#ifdef	_HTTP11
PRIVATE	WORD	HttpPersist=0;
#endif

PRIVATE	WORD	HttpRequestEncryption=0;
PRIVATE	WORD	HttpTransferMode=0;
PRIVATE	BPTR	BoundaryMark=(BPTR) 0;
PRIVATE	BYTE	BoundaryBuffer[64];
PRIVATE	BPTR	ContentType=(BPTR) 0;

#include "httpmem.c"
#include "httpput.c"
#include "httpget.c"

#define	__CLIENT_ACCEPTS "*/*"

PRIVATE	BPTR	ClientAccepts=(BPTR) 0;
PRIVATE	BPTR	Authorization=(BPTR) 0;
PRIVATE	BPTR	ProxyAuthorization=(BPTR) 0;

static	WORD	VersionMajor=1;
static	WORD	VersionMinor=0;

PUBLIC	VOID	http_set_minor(INT v) { VersionMinor = v; }
PUBLIC	VOID	http_set_major(INT v) { VersionMajor = v; }
PUBLIC	WORD	http_get_major() { return( VersionMajor ); }
PUBLIC	WORD	http_get_minor() { return( VersionMinor ); }

PUBLIC	INT	http_set_ascii( pptr )
	BPTR	pptr;
{
	HttpTransferMode = 1;
	return(0);
}

PUBLIC	INT	http_set_binary( pptr )
	BPTR	pptr;
{
	HttpTransferMode = 2;
	return(0);
}

PUBLIC	INT	http_use_encryption( v )
	INT	v;
{
	HttpRequestEncryption = v;
	return(0);
}

PUBLIC	INT	http_set_authorization( pptr )
	BPTR	pptr;
{
	Authorization = liberate_zone( Authorization );
	if ((Authorization = allocate_for_string( pptr )) == (BPTR) 0)
		return( 27 );
	else	return( 0 );
}

PUBLIC	INT	http_set_proxy_authorization( pptr )
	BPTR	pptr;
{
	ProxyAuthorization = liberate_zone( ProxyAuthorization );
	if ((ProxyAuthorization = allocate_for_string( pptr )) == (BPTR) 0)
		return( 27 );
	else	return( 0 );
}

PUBLIC	INT	http_set_accept( pptr )
	BPTR	pptr;
{
	ClientAccepts = liberate_zone( ClientAccepts );
	if ((ClientAccepts = allocate_for_string( pptr )) == (BPTR) 0)
		return( 27 );
	else	return( 0 );
}

PUBLIC	BPTR	http_get_boundary()
{
	if (!( ContentType ))
		return((BPTR) 0);
	else if (!( compare_tokens( ContentType, __MULTIPART_FORM  ) ))
		return((BPTR) 0);
	else 	return( BoundaryMark );
}

PUBLIC	INT	http_set_content_type( pptr )
	BPTR	pptr;
{
	ContentType = liberate_zone( ContentType );
	if ((ContentType = allocate_for_string( pptr )) == (BPTR) 0)
		return( 27 );
	else 	{
		if ( compare_tokens( ContentType , __MULTIPART_FORM  ) )
			sprintf((BoundaryMark=BoundaryBuffer),
				"--%lu--%lx--%lu--",time(0),time(0),time(0));
		else	BoundaryMark=(BPTR) 0;
		return( 0 );
		}
}

#ifdef	_HTTP11
PUBLIC	INT	http_set_persist( value )
	INT	value;
{
	if ( VersionMinor )
		HttpPersist = value;
	else	HttpPersist = 0;
	return(0);
}

PUBLIC	INT	http_may_persist( value )
{
	return( HttpPersist );
}
#endif


PUBLIC	INT	allocate_input_buffer()
{

	if ((InputBuffer = allocate_zone( _IB_SIZE )) == (BPTR) 0 )
		return( 27 );
	else	return(0);
}

PUBLIC	VOID	liberate_input_buffer()
{

	if ( InputBuffer != (BPTR) 0)
		InputBuffer = liberate_zone( InputBuffer );
	return;
}

PUBLIC	INT	http_keyword( aptr )
	BPTR	aptr;
{
	INT	i;
	for ( i=0; i < _HTTP_COMMAND_MAX; i++ )
		if ( compare_tokens( aptr, http_commands[i] ) )
			return(i);
	return( -1 );
}

PRIVATE	INT	receive_text( SocketHandle, lptr )
	INT		SocketHandle;
	BPTR		lptr;
{
	INT	length=0;
	INT	FileHandle=0;
	BYTE	lbl=0;
	INT	new_line=0;
	INT	characters=0;

	if ( lptr != (BPTR) 0)
		FileHandle = FileCreate( lptr );
	
	while ((lbl = tcp_readb( SocketHandle )) > 0 ) {
		if ( lptr == (BPTR) 0)
			printf("%c",lbl);
		switch (( lbl & 0x00FF )) {
			case	'<'  :
				if ((!( new_line ))
				&&  ( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,__HTTP_CRLF,2) != 2 ))
					break;
				characters = 0;
				if (( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,& lbl,1 ) != 1 ))
					break;
				else	{
					characters++;
					continue;
					}
			case	'\n' :
				new_line = 1;
				characters = 0;
				if (( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,& lbl, 1 ) != 1 ))
					break;
				else	continue;
			case    ' '  :
				if ( characters > 160 )
				if (( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,__HTTP_CRLF,2) != 2 ))
					break;
				else	characters = 0;
			default	     :
				new_line = 0;
				characters++;

				if (( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,& lbl, 1 ) != 1 ))
					break;
				else	continue;
			}
		break;
		}
	if ( FileHandle )
		FileFlush( FileHandle );

	return(0);
}

PRIVATE	INT	receive_binary( SocketHandle,lptr )
	INT	SocketHandle;
	BPTR	lptr;
{
	INT	length=0;
	INT	FileHandle=0;
	BYTE	LineBuffer[256];
	INT	lbi=0;
	INT	lbl=0;

	if ( lptr )
		FileHandle = FileCreate( lptr );

	while (1) {
		if ((lbl = SocketRead(SocketHandle,LineBuffer, 256 )) < 0 )
			break;
		if ( lbl == 0 )
			break;
		else if ( FileHandle >= 0 ) {
			if ( FileWrite( FileHandle,LineBuffer,lbl ) != lbl )
				break;
			}
		}
	if ( FileHandle )
		FilePurge( FileHandle );
	return(0);
}

PRIVATE	INT	http_client_error( mptr )
	BPTR	mptr;
{
	if ( verbose )
		printf("%s : %d\n",mptr,errno);
	return( 7 );
}

PUBLIC	INT	analyse_filetype( nptr )
	BPTR	nptr;
{
	INT	i=0;
	for( i = strlen(nptr); i > 0; i-- )
		if ( *(nptr + (i-1)) == '.' )
			break;
	if ( i > 0 ) {
		if (( compare_tokens( (nptr + i), "htm" ) != 0 )
		||  ( compare_tokens( (nptr + i), "html" ) != 0 ))
			return( _HTML_FILE );
		else if ( compare_tokens( (nptr + i), "bmp" ) != 0 )
			return( _BMP_FILE );
		else if ( compare_tokens( (nptr + i), "gif" ) != 0 )
			return( _GIF_FILE );
		else if ( compare_tokens( (nptr + i), "wav" ) != 0 )
			return( _WAV_FILE );
		else if ( compare_tokens( (nptr + i), "mov" ) != 0 )
			return( _MOV_FILE );
		else if ( compare_tokens( (nptr + i), "bmf" ) != 0 )
			return( _BMF_FILE );
		else if ( compare_tokens( (nptr + i), "at" ) != 0 )
			return( _AT_FILE );
		else if ( compare_tokens( (nptr + i), "xp" ) != 0 )
			return( _XP_FILE );
		else if ( compare_tokens( (nptr + i), "exe" ) != 0 )
			return( _EXE_FILE );
		else if ( compare_tokens( (nptr + i), "dns" ) != 0 )
			return( _DNS_FILE );
		else if ( compare_tokens( (nptr + i), "ico" ) != 0 )
			return( _ICO_FILE );
		else if ( compare_tokens( (nptr + i), "cla" ) != 0 )
			return( _CLA_FILE );
		else if ( compare_tokens( (nptr + i), "jav" ) != 0 )
			return( _JAV_FILE );
		else if (( compare_tokens( (nptr + i), "jpg" ) != 0 )
		     ||  ( compare_tokens( (nptr + i), "jpeg" ) != 0 ))
			return( _JPEG_FILE );
		}
	return(-1);
}



PRIVATE	INT	http_get_response( handle )
	INT 	handle;
{
	INT		v;
	INT		status=0;
	HTTPVARPTR	variables=(HTTPVARPTR) 0;
	HTTPVARPTR	vptr=(HTTPVARPTR) 0;

	/* --------------------------------------------------------------- */
	/* HTTP/1.0 Prefixed Responses indicate the standard Response Type */
	/* which will be followed by a status code and staus message	   */
	/* and perhaps if all is ok ( or even not ) will be followed by	   */
	/* HTTP variables NAME: VALUE\r\n				   */
	/* --------------------------------------------------------------- */
	if (((v = tcp_readb( handle )) == 'H')
	&&  ((v = tcp_readb( handle )) == 'T')
	&&  ((v = tcp_readb( handle )) == 'T')
	&&  ((v = tcp_readb( handle )) == 'P')
	&&  ((v = tcp_readb( handle )) == '/') 
	&&  ((v = tcp_readb( handle )) == '1') 
	&&  ((v = tcp_readb( handle )) == '.') 
	&&  ((v = tcp_readb( handle )) == '0')) {

		/* -------------------------------------------- */
		/* Step Over White Space to MESSAGE STATUS CODE */
		/* -------------------------------------------- */
		while ((v = tcp_readb( handle )) == ' ');

		/* --------------------------------------- */
		/* Collect Status Code as an Integer Value */
		/* --------------------------------------- */
		status = 0;
		do	{
			if (( v >= '0' ) && ( v <= '9')) {
				status *= 10;
				status += (v - '0');
				}
			else	break;
			}
		while ((v = tcp_readb(handle)) != ' ');

		if ( verbose & 2 )
			printf("\tHTTP/1.0 %u ",status);

		/* ----------------------------------------- */
		/* Greater than Success ( must be an error ) */
		/* ----------------------------------------- */
		if ( status >= 400 ) {
			if ( verbose & 2 )
				printf(" * * ERROR * *\n");
			return( status );
			}
		/* --------------------------------- */
		/* Step over status message since OK */
		/* --------------------------------- */
		while ((v = tcp_readb( handle )) != '\n')
			if (( verbose & 2 ) && ( v != '\r' ))
				printf("%c",v);

		if ( verbose & 2 )	
			printf(	"%c",v );

		if ( status > 200 ) {
			if ( verbose & 2 )
				printf(" * *SUCCESS * *\n");
			return( status );
			}

		/* ----------------------------------------- */
		/* Attempt to Collect List of HTTP Variables */
		/* ----------------------------------------- */
		if ((variables = http_get_variables( handle )) != (HTTPVARPTR) 0) {

			if ( verbose )
				show_http_variables( variables );

			/* ---------------------------------------------- */
			/* Scan List of Variables to Find "Content-Type:" */
			/* ---------------------------------------------- */
			vptr = variables;
			do	{
				if ((vptr->name  != (BPTR) 0)
				&&  (vptr->value != (BPTR) 0)
				&&  (compare_tokens( vptr->name, __CONTENT_TYPE ))) {

					/* -------------------------------- */
					/* Is "Content-Type:" Text or Image */
					/* -------------------------------- */
					if (wildcomp( vptr->value, "text/*" ) == 0)
						status = _HTML_FILE;
					else if (wildcomp( vptr->value, "image/*" ) == 0 )
						status = _GIF_FILE;
					else if (wildcomp( vptr->value,"applet/java" ) == 0 )
						status = _CLA_FILE;
					else	status = -1;
					break;
					}
				}
			while ((vptr = vptr->next) != (HTTPVARPTR) 0);

			/* --------------------------------- */
			/* Release the List of Variables Now */
			/* --------------------------------- */
			while ((vptr = variables) != (HTTPVARPTR) 0) {
				variables = vptr->next;
				vptr = liberate_http_variable( vptr );
				}
			}
		else 	status =-1;

		return( status );

	
		}
	else	

		/* ---------------------------- */
		/* Incorrect HTTP/1.0 Signature */
		/* ---------------------------- */
		return( -1 );



}

/** 	---------------------------------------------------------- 	**/
/** 	PUTF( Socket, Command, Host, RemoteObject, [LocalObject] ) 	**/
/** 	---------------------------------------------------------- 	**/

PRIVATE INT 		http_putf(connection, cptr, hptr, fptr, lptr )
	CONNECTIONPTR	connection;
	BPTR		cptr;
	BPTR 		hptr;
	BPTR 		fptr;
	BPTR 		lptr;
{
	return(0);
}

PRIVATE	VOID		http_reception( nature, connection, lptr )
	INT		nature;
	CONNECTIONPTR	connection;
	BPTR		lptr;
{
	switch ( HttpTransferMode ) {
		case	1	:	/* Explicite Ascii Text Mode */
			receive_text( connection->socket, lptr );
			return;
		case	2	:	/* Explicite Binary     Mode */
			receive_binary( connection->socket, lptr );
			return;
		default		:	/* Not Specified */
			switch ( nature ) {
				case	_CLA_FILE  :
				case	_GIF_FILE  :
				case    _BMP_FILE  :
				case    _WAV_FILE  :
				case    _BMF_FILE  :
				case    _AT_FILE   :
				case    _XP_FILE   :
					receive_binary( connection->socket, lptr );
				case	204	   :
					return;
				case	_JAV_FILE  :
				case	_HTML_FILE :
				default		   :
					receive_text( connection->socket, lptr );
					return;
			}
		}
	return;
}

PUBLIC	INT		HttpSendMessage( connection, cptr, hptr, fptr ) 
	CONNECTIONPTR	connection;
	BPTR		cptr;
	BPTR 		hptr;
	BPTR 		fptr;
{
	HTTPMSGPTR	message=(HTTPMSGPTR) 0;
	INT	l=0;
	INT	status=0;
	BYTE	lbuffer[16];

	/* --------------------------------- */
	/* Allocate for Basic Message Fields */
	/* --------------------------------- */
	if (((message = allocate_http_message()) != (HTTPMSGPTR) 0)
	&&  ((message->command = allocate_for_string( cptr )) != (BPTR) 0)
	&&  ((message->object  = allocate_for_string( fptr )) != (BPTR) 0)
	&&  ((message->version = allocate_for_string( 

#ifdef	_HTTP11
			( HttpPersist ? _HTTP11 : _HTTP_VERSION )
#else
			_HTTP_VERSION 
#endif
			)) != (BPTR) 0)) {

		/* ------------------------ */
		/* Build HTTP/1.0 Variables */
		/* ------------------------ */
		build_http_variable( message, 	__ACCEPT_HOST, hptr);
		build_http_variable( message, 	__ACCEPT_USER	 ,GetUserAgent() );
#ifdef		_HTTP11
		if ( HttpPersist )
			build_http_variable( message, 	__ACCEPT_CONNECTION,__PERSIST );
#else
		build_http_variable( message, 	__ACCEPT_CPU	 ,"x86");
		build_http_variable( message, 	__ACCEPT_OS	 ,HostSystemName());
#endif
		build_http_variable( message, 	__ACCEPT_LANGUAGE,"fr,en");

		if ( ProxyAuthorization ) {
			build_http_variable( message, 	__ACCEPT_PROXY_AUTH, ProxyAuthorization );
			ProxyAuthorization = liberate_zone( ProxyAuthorization );
			}
		if ( Authorization ) {
			build_http_variable( message, 	__ACCEPT_AUTH, Authorization );
			Authorization = liberate_zone( Authorization );
			}

		switch ( http_keyword( message->command ) ) {

			case	_HTTP_METHOD_GET	:
				if ( HttpRequestEncryption )
					build_http_variable( message, 	__PRAGMA 	 , "ensure" );

			case	_HTTP_METHOD_HEAD	:
				build_http_variable( message, 	__ACCEPT_IMAGE 	 ,(ClientAccepts != (BPTR) 0 ? ClientAccepts : (BPTR) "*/*"));
				break;

#ifdef	_HTTP_METHOD_PUT
			case	_HTTP_METHOD_PUT	:
#endif
			case	_HTTP_METHOD_POST	:
				build_http_variable( message, 	__CONTENT_TYPE 	 ,(ContentType != (BPTR) 0 ? ContentType : (BPTR) "application/x-www-form-urlencoded") );
				if ( connection->length != 0 ) {
					sprintf(lbuffer,"%u",connection->length);
					build_http_variable( message, 	__CONTENT_LENGTH , lbuffer );
					}				

				break;
			}

		/* -------------------------------------- */
		/* Display Message if Required by options */
		/* -------------------------------------- */
		if ( verbose ) {

			printf( "HTTP Request  0 At %lu To %s \n",
				time(0),
				hptr );

			show_http_message( message );

			}

		/* ------------------------- */
		/* Send Message to HTTP Host */
		/* ------------------------- */
		http_put_message( connection, message );

		}
	else	status = -1;

	/* ----------------------------------- */
	/* Release the message we received NOW */
	/* ----------------------------------- */
	message = liberate_http_message( message );

	return( status );

}

/** 	---------------------------------------------------------- 	**/
/** 	GETF( Socket, Command, Host, RemoteObject, [LocalObject] ) 	**/
/** 	---------------------------------------------------------- 	**/

PRIVATE INT 		http_getf(connection, cptr, hptr, fptr, lptr )
	CONNECTIONPTR	connection;
	BPTR		cptr;
	BPTR 		hptr;
	BPTR 		fptr;
	BPTR 		lptr;
{
	INT		status;

	if ((status = HttpSendMessage( connection, cptr, hptr, fptr )) == 0) {

		if ( verbose )
			printf( "HTTP Response 0 At %lu From %s \n",
				time(0),
				hptr	);

		/* ---------------------------------------- */
		/* Analyse Response (may be immediate Data) */
		/* ---------------------------------------- */
		if ((status = http_get_response( connection->newsocket )) != -1 ) {

			/* Test for Explicite GET rather than HEAD */
			/* --------------------------------------- */
			if ( http_keyword(cptr) != _HTTP_METHOD_HEAD )

				/* Check for Response Received */
				/* --------------------------- */
				if ( status != 204 )
					/* ----------------------------------------------- */
					/* Was prefixed by an HTTP Header of "status" type */
					/* ----------------------------------------------- */
					http_reception( status,connection, lptr  );

			}

		/* ------------------------------------------------------- */
		/* Otherwise unknown response type so interpret local type */
		/* ------------------------------------------------------- */
		else if ( lptr == (BPTR) 0 )

			/* ------------------------------------ */
			/* No local type so Echo Text reception */
			/* ------------------------------------ */
			receive_text( connection->socket, lptr );


		else	/* ------------------------------------- */
			/* Perform TEXT or BINARY mode reception */
			/* ------------------------------------- */
			http_reception( analyse_filetype( lptr ), connection,lptr );

		}

	/* ------------- */
	/* And return OK */
	/* ------------- */
	return( 0 );

}

PRIVATE	INT	http_build_report(error, cmdptr, hostptr, target )
	INT	error;
	BPTR	cmdptr;
	BPTR	hostptr;
	BPTR	target;
{
	INT	handle;
	if ((handle = FileCreate(target)) > 0 ) {
		file_puts( handle, "<HTML><HEAD><TITLE>HTTP REPORT</TITLE> </HEAD>\r\n" );
		file_puts( handle, "<BODY><H1 ALIGN=CENTER> HTTP ERROR REPORT </H1>\r\n");
		switch ( error ) {
			case	30 :
				file_puts( handle, "Syntax Error : " );
				break;
			case	40 :
				file_puts( handle, "Host Failure : " );
				break;
			default	   :
				file_puts( handle, "Http Failure : " );
				break;
			}
		file_puts( handle, cmdptr );
		file_puts( handle, " URL ");
		file_puts( handle, hostptr );
		file_puts( handle, "\r\n");
		file_puts( handle, "</BODY></HTML>\r\n" );
		FileFlush(handle);
		}
	return(0);
}

PRIVATE INT 		HttpClient( uptr, argc, argv )
	URLPTR		uptr;
	INT		argc;
	BPTR  		argv[];
{
	BPTR  		hptr=(BPTR) 0;
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;

	/* ----------------------------------------------- */
	/* Rebuild URL string for transmission to the HOST */
	/* ----------------------------------------------- */
	if ( allocate_input_buffer() != 0 )
		return( 0 );
	else if ((hptr = interpret_url( uptr )) == (BPTR) 0)
		return(0);

	/* ----------------------------- */
	/* Interpret the Command Keyword */
	/* ----------------------------- */
	switch ( http_keyword( argv[0] ) ) {
		case	_HTTP_METHOD_HEAD :
		case	_HTTP_METHOD_GET  :
			/** ---------------------------------------------------------- **/
			/** GETF( Socket, Command, Host, RemoteObject, [LocalObject] ) **/
			/** ---------------------------------------------------------- **/
			if ((cptr = client_connection( uptr )) != (CONNECTIONPTR) 0) {
				http_getf( cptr, argv[0], hptr, cptr->remote->path, argv[1] );
				cptr = close_connection( cptr );
				}
			else 	{
				if ( verbose ) {
					printf("Host Failure ");
					show_url( uptr );
					}
				http_build_report(40,argv[0], hptr, argv[1] );
				}
			break;

#ifdef	_HTTP_METHOD_PUT
		case	_HTTP_METHOD_PUT  :
#endif
		case	_HTTP_METHOD_POST :
			/** ---------------------------------------------------------- **/
			/** PUT ( Socket, Command, Host, RemoteObject, [LocalObject] ) **/
			/** ---------------------------------------------------------- **/
			if ((cptr = client_connection( uptr )) != (CONNECTIONPTR) 0) {
				http_putf( cptr, argv[0], hptr, cptr->remote->path, argv[1] );
				cptr = close_connection( cptr );
				}
			else if ( verbose ) {
				printf("Host Failure ");
				show_url( uptr );
				}
			break;
		default			   :
			if (verbose)
				printf("* * HTTP Incorrect Command : %s * *\n",argv[0]);
			http_build_report(30,argv[0], hptr, argv[1] );
		}

	hptr = liberate_zone( hptr );
	liberate_input_buffer();
	return(0);
}

PRIVATE	INT	HttpParser( nptr, uptr )
	BPTR	nptr;
	URLPTR	uptr;
{
	INT	status;

	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base      = __HTTP_PORT;
	uptr->transport = __URL_TCP;

	if (!((status = parse_url_host( nptr, uptr )) & _URL_IS_HOST)) {
		strcpy( uptr->host, _LOCAL_HOST );
		status |= _URL_IS_HOST;
		}
	if (!(status & _URL_IS_PATH)) {
		strcpy( uptr->path, _LOCAL_PATH );
		status |= _URL_IS_PATH;
		}
	return( status );
}

PUBLIC	INT	initialise_http_service()
{
	INT	status;
	SetUserAgent("HTTPC/1.1");
	strcpy(HttpService.name,__HTTP_PREFIX);
	HttpService.parse     = HttpParser;
	HttpService.client    = HttpClient;
	HttpService.nature = 0;
	if (ClientAccepts == (BPTR) 0)
		status = http_set_accept( __CLIENT_ACCEPTS );
	return( add_url_service( (SERVICEPTR) & HttpService ) );
}

PRIVATE	INT	HttpsParser( nptr, uptr )
	BPTR	nptr;
	URLPTR	uptr;
{
	INT	status;

	/* Initialise(reset) Result Fields */
	/* ------------------------------- */
	uptr->base      = __HTTPS_PORT;
	uptr->transport = __URL_TCP;

	if (!((status = parse_url_host( nptr, uptr )) & _URL_IS_HOST)) {
		strcpy( uptr->host, _LOCAL_HOST );
		status |= _URL_IS_HOST;
		}
	if (!(status & _URL_IS_PATH)) {
		strcpy( uptr->path, _LOCAL_PATH );
		status |= _URL_IS_PATH;
		}
	return( status );
}

PUBLIC	INT	initialise_https_service()
{
	SetUserAgent(__HTTPS_AGENT);
	strcpy(HttpsService.name,__HTTPS_PREFIX);
	HttpsService.parse     = HttpsParser;
	HttpsService.client    = HttpClient;
	HttpsService.nature = 0;
	return( add_url_service( (SERVICEPTR) & HttpsService ) );
}

PUBLIC	VOID	http_show_usage()
{
	printf("         [ -t<http_types>     ] : Set Client Acceptance\n");
	return;
}

PUBLIC	VOID	http_show_example()
{
	printf("        http://hostname/filename GET  <local_file> \n");
	printf("        https://hostname/filename GET  <local_file> \n");
	return;
}

#endif	/* _HTTP_C */
	/* ------- */


