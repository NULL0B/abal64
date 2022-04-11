#ifndef	_HTTPS_C
#define	_HTTPS_C

#include "https.h"
#include "fnparser.c"

PRIVATE	VOID	http_server_banner()
{
	printf("   HTTP: Server  Version %s \n",__BASIC_VERSION);
	printf("   Provisoire du %s \n",__BASIC_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

PRIVATE	VOID	http_trace_banner()
{
	trace_puts("HTTP Server Version ");
	trace_puts( __BASIC_VERSION );
	trace_line();
	trace_puts("Provisoire du ");
	trace_puts( __BASIC_DATE );
	trace_line();
	trace_puts("Copyright (C) 1997 Amenesik / Sologic ");
	trace_line();
	return;
}

PRIVATE	VOID	http_server_usage( nptr )
	BPTR	nptr;
{
	printf("\n Usage %s \n",nptr);
	show_server_usage();
	show_global_usage();
	printf("         <home_document>        : Server Home Page              \n");
	return;
}

PRIVATE	INT	report_failure( mptr )
	BPTR	 mptr;
{
	if ( trace_active ) {
		trace_puts("HTTPS FAILURE ");
		trace_puts(mptr); trace_putw(errno);
		trace_line();
		terminate_trace();
		}
	printf("HTTPS FAILURE %s (%d) \n",mptr,errno);
	if ( errno )
		return( errno );
	else	return( 1 );
}

PRIVATE	VOID	http_show_request( aptr )
	ADDRPTR	aptr;
{
	LONG	when=time((LPTR) 0);

	if ( verbose )
		printf( "HTTP Request  %lu At %lu From %s \n",
			HttpStat.ConnectionCount,
			when,
			socketname(aptr)
			);

	if ( trace_active ) {
		trace_puts("HTTP Request  ");
		trace_putl( HttpStat.ConnectionCount );
		trace_puts( " At ");
		trace_putl( when );
		trace_puts( " From ");
		trace_puts( socketname( aptr ) );
		trace_line();
		}
	return;
}

PRIVATE	VOID	http_show_response( reportcode,reporttext )
	BPTR  	reportcode;
	BPTR	reporttext;
{
	LONG	when=time((LPTR) 0);

	if ( verbose )

		printf(	"HTTP Response %lu At %lu %s %s %s \n",
			HttpStat.ConnectionCount,
			when,
			_HTTP_VERSION,
			reportcode,
			reporttext
			);

	if ( trace_active ) {
		trace_puts( "HTTP Response "  );
		trace_putl( HttpStat.ConnectionCount );
		trace_puts( " At ");
		trace_putl( when );
		trace_puts( " ");
		trace_puts( _HTTP_VERSION  );
		trace_puts( " ");
		trace_puts( reportcode     );
		trace_puts( " ");
		trace_puts( reporttext     );
		trace_line();
		}
	return;
}

PRIVATE	INT		http_response( cptr,reportcode,reporttext)
	CONNECTIONPTR	cptr;
	BPTR  		reportcode;
	BPTR		reporttext;
{
	http_show_response( reportcode, reporttext );

	if (( http_puts(cptr, _HTTP_VERSION) != 0 )
	&&  ( http_putb(cptr, ' '      )     != 0 )
	&&  ( http_puts(cptr,reportcode)     != 0 ) 
	&&  ( http_puts(cptr,reporttext)     != 0 )) {
		http_putl(cptr);
		}
	return( 0 );		
}

PRIVATE	VOID		http_server_error(cptr,errorcode,errortext)
	CONNECTIONPTR	cptr;
	BPTR		errorcode;
	BPTR		errortext;
{
	BPTR	 eptr;
	HttpStat.FailureCount++;
	http_response( cptr, errorcode, errortext );
	http_eot( cptr );
	return;
}

#define	____HTTP_REPORT_OK


PRIVATE	VOID		http_content_type( connection, mode )
	CONNECTIONPTR	connection;
	INT		mode;
{
	http_puts(connection,__CONTENT_TYPE);
	switch ( mode ) {
		case	_HTML_FILE :
			http_puts(connection," text/html\r\n");
			break;			
		case	_GIF_FILE  :
			http_puts(connection," image/gif\r\n");
			break;
		case    _BMP_FILE  :
			http_puts(connection," image/bmp\r\n");
			break;
		case    _BMF_FILE  :
			http_puts(connection," image/bmf\r\n");
			break;
		case    _WAV_FILE  :
			http_puts(connection," sound/wav\r\n");
			break;
		case    _EXE_FILE  :
			http_puts(connection," exec/exe\r\n");
			break;
		case    _COM_FILE  :
			http_puts(connection," exec/exe\r\n");
			break;
		case    _AT_FILE   :
			http_puts(connection," exec/at\r\n");
			break;
		case    _XP_FILE   :
			http_puts(connection," exec/xp\r\n");
			break;
		default		:
			http_puts(connection," */*\r\n");
			break;
		}
	http_puts(connection,"\r\n");
	return;
}

PRIVATE	VOID		http_success( cptr,mode )
	CONNECTIONPTR	cptr;
	INT		mode;
{
	HttpStat.SuccessCount++;
#ifdef	____HTTP_REPORT_OK
	http_response(cptr,_HTTP_STATUS_SUCCESS, "OK");
	http_content_type(cptr, mode );
#else
	http_show_response(_HTTP_STATUS_SUCCESS, "OK");
#endif
	return;
}

PRIVATE	INT	transmit_text( cptr, message, mode )
	CONNECTIONPTR	cptr;
	HTTPMSGPTR	message;
	INT		mode;
{
	INT     handle;
	BYTE	c;
	BYTE	LineBuffer[83];
	INT	lbi=0;

	if ((handle = FileOpen(message->object,O_RDONLY)) < 0)
		http_server_error(cptr,_HTTP_STATUS_NOTFOUND, "Not found");
	else	{
		http_success( cptr,mode );
		while ( FileRead(handle,(BPTR) & c, 1) == 1) {
			switch (c) {
				case 0	    :
				case 0x001A :
					if ( lbi != 0 ) {
						LineBuffer[lbi++] = '\r';
						LineBuffer[lbi++] = '\n';
						http_put( cptr,LineBuffer,lbi);
						lbi = 0;
						}
					break;
				case '\r'   :
					continue;
				case '\n'   :
					if ( lbi != 0 ) {
						LineBuffer[lbi++] = '\r';
						LineBuffer[lbi++] = '\n';
						http_put( cptr,LineBuffer,lbi);
						lbi = 0;
						}
					continue;
				default	    :
					if ( lbi == 80 ) {
						LineBuffer[lbi++] = '\r';
						LineBuffer[lbi++] = '\n';
						http_put( cptr,LineBuffer,lbi);
						lbi = 0;
						}
					LineBuffer[lbi++] = c;
					continue;
				}
			break;
			}
		http_eot( cptr );
		FileClose(handle);
		}
	return(0);
}

PRIVATE	INT	transmit_binary( cptr, message, mode )
	CONNECTIONPTR	cptr;
	HTTPMSGPTR	message;
	INT		mode;
{
	INT     handle;
	INT	bytesread=0;
	BYTE	LineBuffer[256];

	if ((handle = FileOpen(message->object,O_RDONLY)) < 0)
		http_server_error(cptr,_HTTP_STATUS_NOTFOUND, "Not found");
	else	{
		http_success( cptr, mode );
		while ((bytesread = FileRead(handle,LineBuffer,256)) > 0)
			http_put( cptr, LineBuffer, bytesread );
		FileClose(handle);
		}
	return(0);
}

#include "httpstat.c"

PRIVATE	INT 		analyse_http_object( message )
	HTTPMSGPTR	message;
{
	BPTR	nptr=(BPTR) 0;

	/* ------------------------------ */
	/* Collect Message Object Pointer */
	/* ------------------------------ */
	if ((nptr = message->object) == (BPTR) 0)

		/* ------------------------------ */
		/* The Object Field Must Be VALID */
		/* ------------------------------ */
		return( __HTTP_CMD_FAILURE );

	else	/* ----------------------------- */
		/* Step over HOST/PATH separator */
		/* ----------------------------- */
		if ( *nptr == '/' ) nptr++;

	/* -------------------------------- */
	/* Detect Internal Command ShutDown */
	/* -------------------------------- */
	if ( compare_tokens( nptr, __HTTP_SHUTDOWN ) )
		return( __HTTP_CMD_SHUTDOWN );
	/* -------------------------------- */
	/* Detect Internal Command SendStat */
	/* -------------------------------- */
	else if ( compare_tokens( nptr, __HTTP_STATISTICS ) )
		return( __HTTP_CMD_STATISTICS );

	else if ( *nptr == 0 ) {
				
		/* ----------------------------------- */
		/* Default Request must be Established */
		/* ----------------------------------- */
		if ((HomePage == (BPTR) 0)
		||  (!(strlen(HomePage)))
		||  ((nptr = allocate_for_string( HomePage )) == (BPTR) 0))
			return( __HTTP_CMD_FAILURE );
		else	{
			/* ----------------------------------------- */
			/* Release original and Replace with Default */
			/* which will be released by message release */
			/* ----------------------------------------- */
			message->object = liberate_zone( message->object );
			message->object = nptr;

			}
		}

	else if ( HomePath[0] ) {

		/* ---------------------------------------- */
		/* Requests Must be Restricted to Home Path */
		/* ---------------------------------------- */
		strcpy( InputBuffer, HomePath );
		strcat( InputBuffer, nptr );
		if ((nptr = allocate_for_string( InputBuffer )) == (BPTR) 0)
			return( __HTTP_CMD_FAILURE );
		else	{
			/* ----------------------------------------- */
			/* Release original and Replace with Default */
			/* which will be released by message release */
			/* ----------------------------------------- */
			message->object = liberate_zone( message->object );
			message->object = nptr;

			}

		}

	/* ------------------------------------------------------ */
	/* Scan Object Name String to Find Terminator of any kind */
	/* ------------------------------------------------------ */
	while ( ( *nptr ) 
	&& 	( *nptr != ' '  ) 
	&& 	( *nptr != '?'  )
	&& 	( *nptr != '\r' )
	&& 	( *nptr != '\n' )
	&& 	( *nptr != '\t' ) )	nptr++;

	/* ---------------------------------------- */
	/* Detect and Set Message Parameter Pointer */
	/* ---------------------------------------- */
	if ( *nptr == '?' ) message->parameters = (nptr+1);

	/* -------------------- */
	/* Force 'C' terminator */
	/* -------------------- */
	*(nptr++) = 0;

	/* -------------------------------------- */
	/* Ensure URL/FILESPEC has been localised */
	/* -------------------------------------- */
	localise_url( message->object );

	/* -------------------------------------------------------- */
	/* Indicate Enquiry (with parameters) or Retrieve (without) */
	/* -------------------------------------------------------- */
	if ( message->parameters == (BPTR) 0 )
		return( __HTTP_CMD_TRANSFER );
	else	return( __HTTP_CMD_ENQUIRY  );

}

PRIVATE	INT		http_enquiry(cptr,message) 
	CONNECTIONPTR	cptr;
	HTTPMSGPTR	message;
{
	http_server_error(cptr,_HTTP_STATUS_NOTFOUND, "Not found");
	return( 0 );
}

PRIVATE	INT		http_retrieval( cptr, message )
	CONNECTIONPTR	cptr;
	HTTPMSGPTR	message;
{
	INT	mode=0;

	switch ((mode = analyse_filetype( message->object )) ) {

		case	_HTML_FILE :
			transmit_text( cptr, message, mode );
			break;

		case	_GIF_FILE  :
		case    _BMP_FILE  :
		case    _WAV_FILE  :
		case    _EXE_FILE  :
		case    _COM_FILE  :
		case    _AT_FILE   :
		case    _BMF_FILE  :
		case    _XP_FILE   :

			transmit_binary( cptr, message, mode );
			break;

		default	:
			http_server_error(cptr,_HTTP_STATUS_NOTFOUND, "Not found");
			break;
		}

	return(0);
}

PRIVATE	INT		http_get(cptr,message) 
	CONNECTIONPTR	cptr;
	HTTPMSGPTR	message;
{
	BPTR 	nptr=(BPTR) 0;
	BPTR 	aptr=(BPTR) 0;
	BPTR  	pptr=(BPTR) 0;
	INT	terminator=0;

	/* ----------------------------- */
	/* Analyse Message Object Nature */
	/* ----------------------------- */
	switch ( analyse_http_object( message ) ) {

		case	__HTTP_CMD_SHUTDOWN	:

			if (!( silence )) {
				HttpStat.SuccessCount++;
				http_response(cptr,_HTTP_STATUS_SUCCESS, "OK : CLIENT SHUTDOWN ACCEPTED");
				return(1);	/* !!!! FORCES SHUTDOWN !!!! */
				}
			else	{
				http_server_error(cptr,_HTTP_STATUS_UNAUTHORIZED, "Shutdown Refused");
				return(0);
				}

		case	__HTTP_CMD_STATISTICS	:
			return( http_statistics( cptr ) );

		case	__HTTP_CMD_ENQUIRY	:
			return( http_enquiry( cptr, message ) );

		case	__HTTP_CMD_TRANSFER	:
			if ( http_retrieval( cptr, message ) == 0 )
				return( 0 );

		case	__HTTP_CMD_FAILURE	:

		default				:

			http_server_error(cptr->newsocket,_HTTP_STATUS_NOTFOUND, "Not found");
			return(0);
		}

}

PRIVATE	INT 		http_command(cptr, message )
	CONNECTIONPTR	cptr;
	HTTPMSGPTR	message;
{
	if ( verbose )
		show_http_message( message );

	switch ((http_keyword( message->command ))) {
		case	_HTTP_METHOD_GET :
			return( http_get( cptr, message ) );
		case	_HTTP_METHOD_HEAD		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_POST		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
#ifdef	_HTTP11
		case	_HTTP_METHOD_PUT		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_DELETE		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_TRACE 		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_CONNECT		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_OPTIONS		:
			http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
#endif
		default		  :
			http_server_error(cptr,_HTTP_STATUS_BAD, "Bad request");
			return(0);
		}
}

PRIVATE	INT		command_failure( cptr )
	CONNECTIONPTR	cptr;
{
	http_server_error(cptr,_HTTP_STATUS_UNAUTHORIZED, "Access to this server is currently restricted");
	return(0);
}

PRIVATE	INT 		child_worker( cptr )
	CONNECTIONPTR	cptr;
{
	HTTPMSGPTR	message=(HTTPMSGPTR) 0;
	INT		status=0;

	/* --------------------------------------- */
	/* Attempt to Receive a VALID HTTP message */
	/* --------------------------------------- */
	if ((message = http_get_message(cptr)) != (HTTPMSGPTR) 0) {

		/* ----------------------------------------- */
		/* Interpret and Perform Request if Possible */
		/* ----------------------------------------- */
		status = http_command( cptr, message  );

		/* ------------------------------- */
		/* Release this message controller */
		/* ------------------------------- */
		message = liberate_http_message( message );

		}

	else	/* -------------------------------------------------- */
		/* Respond to Connection Attempt by a Command Failure */
		/* -------------------------------------------------- */
		command_failure( cptr );

	return(status);
}

/*
 *	------------------------------------------------------------
 *	H T T P _ I N I T I A L I S A T I O N ( home_page )
 *	------------------------------------------------------------
 *	This function will be called upon HTTP module startup in order
 *	to ensure that the internal control structures have been
 *	correctly initialised and constructed.
 *	The home file name provided will be used for clients providing
 *	no path name component in the request.
 *	------------------------------------------------------------
 */

PRIVATE	VOID	reset_statistics()
{
	HttpStat.StartUpDate 		= time((LPTR) 0);
	HttpStat.ConnectionCount	= 0L;
	HttpStat.SuccessCount		= 0L;
	HttpStat.FailureCount		= 0L;
	return;
}

PRIVATE	INT 	http_initialisation( home_page )
	BPTR	home_page;
{
	INT	status=0;

	reset_statistics();
	initialise_dns_memory();
	HomePage 	= (BPTR) 0;
	HomePath[0] 	= 0;
	if (((status = initialise_url_services()) != 0 )
	||  ((status = initialise_dns_service() ) != 0 )
	||  ((status = initialise_http_service()) != 0 ))

		/* ------------------------------- */
		/* Indicate Initialisation Failure */
		/* ------------------------------- */
		return( status );

	else	{

		/* --------------------------------- */
		/* Establish Home Page and Home Path */
		/* --------------------------------- */
		HomePage     = home_page; 
		HomePath[0] = 0;
		fn_parser(home_page, HomePath, 0x0006);

		/* Allocate Input Buffer */
		/* --------------------- */
		if ((status = allocate_input_buffer()) != 0)
			return( status );

		/* ------------------------------------------------- */
		/* Indicate Initialisation Success and Start Server  */
		/* ------------------------------------------------- */
		else	return( start_server() );

		}
}

/*
 *	------------------------------------------------------------
 *	H T T P _ L I B E R A T I O N ( status )
 *	------------------------------------------------------------
 *	This function will be called to ensure the correct liberation
 *	of the internal structures required by the HTTP. 
 *	It will return the status value provided by its caller.
 *	------------------------------------------------------------
 */

PRIVATE	INT	http_liberation( status )
	INT	status;
{

	(VOID) close_server();

	liberate_input_buffer();

	liberate_url_services();

	/* Release all Pre-Allocation Queues */
	/* --------------------------------- */
	liberate_dns_memory();

	/* And return Provided Status */
	/* -------------------------- */
	return( status );
}

/*
 *	------------------------------------------------------------
 *	H T T P _ S E R V E R _ O P E R A T I O N ( name, homepage )
 *	------------------------------------------------------------
 *	This function provides the HTTP Server operation cycle in the
 *	following manner :
 *
 *	if 	initialisation 
 *	and	url allocation 
 *	and	server connection are successful
 *
 *		process received requests until termination required
 *
 *	liberation of all ressources and return status to caller.
 *
 *	------------------------------------------------------------
 */

PRIVATE	INT	http_server_operation( home_page )
	BPTR  	home_page;
{
	CONNECTIONPTR	Connection=(CONNECTIONPTR) 0;
	URLPTR		ServerUrl=(URLPTR) 0;
	INT		packetsize=0;
	INT		status=0;
	BPTR		irqptr=(BPTR) 0;

	/* ---------------------------------- */
	/* Initialise HTTP Management Context */
	/* ---------------------------------- */
	if ((status = http_initialisation(home_page)) != 0)
		return( http_liberation( status ) );

	else if ( verbose ) 
		http_server_banner();

#ifdef	_TRACE_H

	if ( trace_active )
		http_trace_banner();

#endif

	/* ------------------------------------- */
	/* Prepare Address Package of Connection */
	/* ------------------------------------- */
	if ((ServerUrl = allocate_for_url( "http://0.0.0.0/",0L )) == (URLPTR) 0)
		status = report_failure( "URL Failure" );

	/* ----------------------------------------------- */
	/* Attempt to Open the Type of Connection Required */
	/* ----------------------------------------------- */
	else if ((Connection = 	open_connection
					(	
					ServerUrl->transport,
						(
					 	ServerUrl->port ? 
						ServerUrl->port : 
						ServerUrl->base 
						),
					ServerUrl 
					)
				) != (CONNECTIONPTR) 0) {

		/* ---------------------------------------- */
		/* Enter Operational Loop Awaiting Messages */
		/* ---------------------------------------- */
		while (1) {

			/* ----------------------------------------- */
			/* Wait for a Client Connection (no timeout) */
			/* ----------------------------------------- */
			if ( accept_connection( Connection, 0 ) == (CONNECTIONPTR) 0) {

				/* ----------------------------------- */
				/* Connection Failure so must be Error */
				/* ----------------------------------- */
				status = report_failure( "accept() : connection failure" );
				break;

				}
			else	{

				/* ------------------------- */
				/* Adjust Connection Counter */
				/* ------------------------- */
				HttpStat.ConnectionCount++;

				/* ------------------------------------- */
				/* A Client Connection has been Detected */
				/* ------------------------------------- */
				http_show_request((ADDRPTR) &ServerUrl->address[ServerUrl->adrindex] );

				if (!( is_authorised( (ADDRPTR) &ServerUrl->address[ServerUrl->adrindex] ) ))
					/* ----------------------------------------- */
					/* Unauthorised Access : Restricted to ADMIN */
					/* ----------------------------------------- */
					http_server_error(Connection,_HTTP_STATUS_UNAUTHORIZED, "Access to this server is currently restricted");

				else	/* ---------------------------------- */
					/* Perform Service Operation Required */
					/* ---------------------------------- */
					status = child_worker(Connection);

				/* ----------------------------- */
				/* Release the Client Connection */
				/* ----------------------------- */
				drop_connection( Connection );

				/* ----------------------------------- */
				/* Check for Shutdown Request Received */
				/* ----------------------------------- */
				if ((!( silence ))
				&&  (   status   )) {
					status = 0; break;
					}
				}
			}

		/* --------------------- */
		/* Closure of Connection */
		/* --------------------- */
		Connection = close_connection( Connection );

		}

	/* --------------------------------------------------- */
	/* Release the URL structure used for client reception */
	/* --------------------------------------------------- */
	ServerUrl    = liberate_for_url( ServerUrl );

	/* --------------------------------------- */
	/* Return Resulting Status Value to Caller */
	/* --------------------------------------- */
	return(http_liberation(status));
}

PRIVATE	INT	perform_shutdown( hostname )
	BPTR	hostname;
{
	INT		argc=1;
	BPTR		argv[2];
	INT		status=0;
	BPTR		HostName=(BPTR) 0;
	URLPTR		urlptr=(URLPTR) 0;
	argv[0] = "GET"; argv[1] = (BPTR) 0;
	if (!(status = http_initialisation( " " ))) {
		if ((HostName = allocate_zone( MAX_NAME_LENGTH )) != (BPTR) 0) {
			strcpy( HostName, hostname );
			normalise_url( HostName );
			strcat(HostName,__HTTP_SHUTDOWN);
			if ( verbose )
				printf("HTTP Shutdown %s \n",HostName );
			if ((urlptr = allocate_for_url( HostName,0L )) != (URLPTR) 0) {
				status = service_url( urlptr, argc,(BPTR PTR) & argv[0] );
				urlptr = liberate_for_url( urlptr );
				}
			else	status = report_failure( "URL Failure" );

			HostName = liberate_zone( HostName );

			}
		else	status = report_failure( "Allocation Failure" );

		http_liberation(status);

		}
	else	status = report_failure( "Initialisation Failure" );

	return(status);
}


PUBLIC	INT	main( argc, argv )
	INT	argc;
	BPTR	argv[];
{
	INT	argi=1;
	BPTR	sptr=(BPTR) 0;

	if ( argc == 1 ) {
		http_server_banner(); 
		http_server_usage(argv[0]); 
		}
	else	{
		for ( argi=1; argi < argc; argi++) {
			sptr = argv[argi];

			if ( *sptr == '-' ) {

				switch ( *(sptr+1) ) {

					case 'X' :
					case 'x' : return( perform_shutdown( (sptr+2) ) );

					case 's' :
					case 'S' : set_server_silence( (sptr + 2) );
						   break;
					case 'v' :
					case 'V' : set_server_verbose( (sptr + 2) );
						   break;
					case 'd' :
					case 'D' : set_server_debug( (sptr + 2) );
						   break;
					case 'n' :
					case 'N' : set_server_master((sptr + 2));
						   break;
					case 't' :
					case 'T' : set_server_trace((sptr + 2));
						   break;
					default	 : http_server_banner();
						   printf("%s:error: Incorrect command line option: %s\n",argv[0],argv[argi]);
						   http_server_usage(argv[0]);
						   return(0);

					}
				}
			else	return( http_server_operation( sptr ) );
			}
		http_server_banner();
		printf("%s:error: Home page parameter required \n",argv[0]);
		http_server_usage(argv[0]);
		}
	return(0);
}

#endif	/* _HTTPS_C */
	/* -------- */


