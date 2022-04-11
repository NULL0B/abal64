#ifndef	_HTTPSERV_C
#define	_HTTPSERV_C

#include "fnparser.c"

PRIVATE	BPTR	ServerName=(BPTR) 0;
PRIVATE	BPTR	HomeUrl=(BPTR) 0;
PRIVATE	BPTR  	TraceName=(BPTR) 0;

PRIVATE	BYTE	ServerIdentity[256];
PRIVATE	BYTE	HomePath[256];
PRIVATE	INT	PrivateServer=0;
PRIVATE	BYTE 	PrivateIdentity[256];
PRIVATE	LONG	ConnectionCounter=0L;

PRIVATE	INT	report_failure( mptr )
	BPTR	 mptr;
{
	if ( trace_active ) {
		trace_puts(ServerIdentity);
		trace_puts(":error: "); trace_puts(mptr); trace_putw(errno);
		trace_line();
		terminate_trace();
		}
	printf("%s:error: %s (%d) \n",ServerIdentity,mptr,errno);
	if ( errno )
		return( errno );
	else	return( 1 );
}

PRIVATE	INT	privatise( nptr )
	BPTR 	nptr;
{
	BPTR	 sptr;
	struct  hostent PTR hp=(struct hostent PTR) 0;
	ADDRESS 	MyAddress;

	if ( verbose )
		printf("http:server(%s).private\n",nptr);

	if (( *nptr >= '0' ) && ( *nptr <= '9' ))
		MyAddress.sin_addr.s_addr = inet_addr( nptr );
	else if ((hp = gethostbyname(nptr)) == (struct hostent *) 0)
		return( 1 );
	else	memcpy((BPTR) &MyAddress.sin_addr,(BPTR)hp->h_addr_list[0],hp->h_length);

	if ((sptr = socketname((ADDRPTR) &MyAddress)) != (BPTR) 0) {
		strcpy(PrivateIdentity,sptr);
		PrivateServer = 1;
		}
	return( 0 );
}

PRIVATE	INT	compare_address( aptr, bptr )
	BPTR  aptr;
	BPTR  bptr;
{
	while (( *aptr ) && ( *bptr )) {
		if (( *aptr == ':' ) && ( *bptr == ':' ))
			return(1);
		else if ( *(aptr++) != *(bptr++) )
			return(0);
		}
	if ( *(aptr++) != *(bptr++) )
		return(0);
	else	return(1);
}

PRIVATE	INT	authorised_access( cptr )
	BPTR 	cptr;
{
	if ( verbose )
		printf("%s.verification(%s)",ServerIdentity,cptr);
	if ( compare_address( cptr, PrivateIdentity ) ) {
		if ( verbose )
			printf(" : Accepted\n");
		return( 1 );
		}
	else	{
		if ( verbose )
			printf(" : Rejected\n");
		return( 0 );
		}
}

PRIVATE	INT	http_putb( SocketHandle, c )
	INT	SocketHandle;
	BYTE	c;
{
	if ( SocketWrite(SocketHandle,(BPTR) & c, 1 ) != 1 )
		return(0);
	else	return(1);
}

PRIVATE	INT	http_put( SocketHandle, mptr, mlen )
	INT	SocketHandle;
	BPTR  mptr;
	INT	mlen;
{
	if ( SocketWrite(SocketHandle,mptr,mlen) != mlen )
		return(0);
	else	return(1);
}

#define http_puts(h,s) http_put(h,s,strlen(s))
#define http_putl(h) if (http_putb(h,'\r') != 0) http_putb(h,'\n')
#define http_eot(h) (VOID) http_putb(h,0)

PRIVATE	INT	http_response( SocketHandle,reportcode,reporttext)
	INT	SocketHandle;
	BPTR  reportcode;
	BPTR	reporttext;
{
	if ( verbose ) {
		printf(	"%s.response: %s %s %s\n\n",
			ServerIdentity,
			_HTTP_VERSION,
			reportcode,
			reporttext);
		}
	if ( trace_active ) {
		trace_puts( ServerIdentity );
		trace_puts( ".response: ");
		trace_puts( _HTTP_VERSION  );
		trace_puts( " ");
		trace_puts( reportcode     );
		trace_puts( " ");
		trace_puts( reporttext     );
		trace_line();
		}

	if (( http_puts(SocketHandle, _HTTP_VERSION )  != 0 )
	&&  ( http_putb(SocketHandle,' '       )     !* 0 )
	&&  ( http_puts(SocketHandle,reportcode)     != 0 ) 
	&&  ( http_puts(SocketHandle,reporttext)     != 0 )) {
		http_putl(SocketHandle);
		}
	return( 0 );		
}

PRIVATE	VOID	http_server_error(SocketHandle,errorcode,errortext)
	INT	SocketHandle;
	BPTR  errorcode;
	BPTR	errortext;
{
	BPTR	 eptr;

	http_response( SocketHandle, errorcode, errortext );
	http_eot( SocketHandle );
	return;
}

PRIVATE	INT	http_keyword( aptr )
	BPTR	aptr;
{
	INT	i;
	for ( i=0; i < _HTTP_COMMAND_MAX; i++ )
		if ( compare_tokens( aptr, http_commands[i] ) )
			return(i);
	return( -1 );
}

PRIVATE	INT	transmit_text( SocketHandle, nptr )
	INT	SocketHandle;
	BPTR	nptr;
{
	INT     handle;
	BYTE	c;
	BYTE	LineBuffer[83];
	INT	lbi=0;

	if ((handle = FileOpen(nptr,O_RDONLY)) < 0)
		http_server_error(SocketHandle,_HTTP_STATUS_NOTFOUND, "Not found");
	else	{
/*		http_response(SocketHandle,_HTTP_STATUS_SUCCESS, "OK");	*/
		while ( FileRead(handle,(BPTR) & c, 1) == 1) {
			switch (c) {
				case 0	    :
				case 0x001A :
					if ( lbi != 0 ) {
						LineBuffer[lbi++] = '\r';
						LineBuffer[lbi++] = '\n';
						http_put( SocketHandle,LineBuffer,lbi);
						lbi = 0;
						}
					break;
				case '\r'   :
					continue;
				case '\n'   :
					if ( lbi != 0 ) {
						LineBuffer[lbi++] = '\r';
						LineBuffer[lbi++] = '\n';
						http_put( SocketHandle,LineBuffer,lbi);
						lbi = 0;
						}
					continue;
				default	    :
					if ( lbi == 80 ) {
						LineBuffer[lbi++] = '\r';
						LineBuffer[lbi++] = '\n';
						http_put( SocketHandle,LineBuffer,lbi);
						lbi = 0;
						}
					LineBuffer[lbi++] = c;
					continue;
				}
			break;
			}
		http_eot( SocketHandle );
		FileClose(handle);
		}
	return(0);
}

PRIVATE	INT	transmit_binary( SocketHandle, nptr )
	INT	SocketHandle;
	BPTR	nptr;
{
	INT     handle;
	INT	bytesread=0;
	BYTE	LineBuffer[256];

	if ((handle = FileOpen(nptr,O_RDONLY)) < 0)
		http_server_error(SocketHandle,_HTTP_STATUS_NOTFOUND, "Not found");
	else	{
/*		http_response(SocketHandle,_HTTP_STATUS_SUCCESS, "OK");	*/
		while ((bytesread = FileRead(handle,LineBuffer,256)) > 0)
			http_put( SocketHandle, LineBuffer, bytesread );
		FileClose(handle);
		}
	return(0);
}

PRIVATE	BYTE	PrefixedFile[256];

PRIVATE	INT	http_get(SocketHandle, nptr )
	INT	SocketHandle;
	BPTR  nptr;
{
	BPTR 	aptr;
	BPTR  pptr;

	aptr = nptr;
	while (( *aptr ) && ( *aptr != '\n' )) {
		if (( *aptr == '\r' ) || ( *aptr == ' '))
			break;
		else	aptr++;
		}

	*aptr = 0;

	/* ----------------- */
	/* http:get filename */
	/* ----------------- */
	if ( *nptr == '/' ) nptr++;

	if (*nptr == 0  ) 

		nptr = HomeUrl;

	else if ( HomePath[0] != 0 ) {
		strcpy( PrefixedFile, HomePath );
		strcat( PrefixedFile, nptr );
		nptr = PrefixedFile;
		}

	localise_url( nptr );

#ifdef	FORKING_SERVER
#else
	if ( compare_tokens( nptr, __HTTP_SHUTDOWN ) ) {
		http_response(SocketHandle,_HTTP_STATUS_SUCCESS, "OK : CLIENT SHUTDOWN REQUEST ACCEPTED");
		return(1);
		}			
#endif

	if ( verbose )
		printf("%s.get(%s)\n",ServerIdentity,nptr);

	if ( trace_active ) {
		trace_puts( ServerIdentity );
		trace_puts( ".get(");
		trace_puts( nptr   );
		trace_puts( ")");
		trace_line();
		}

	switch ( analyse_filetype( nptr ) ) {
		case	_HTML_FILE :
			transmit_text( SocketHandle, nptr );
			break;
		case	_GIF_FILE  :
		case    _BMP_FILE  :
		case    _WAV_FILE  :
		case    _EXE_FILE  :
		case    _COM_FILE  :
		case    _AT_FILE  :
		case    _BMF_FILE  :
		case    _XP_FILE  :
		case    _DNS_FILE  :
			transmit_binary( SocketHandle, nptr );
			break;
		default	:
			http_server_error(SocketHandle,_HTTP_STATUS_NOTFOUND, "Not found");
			break;
		}

	return(0);
}

PRIVATE	INT 	http_command(SocketHandle,filename )
	INT	SocketHandle;
	BPTR 	filename;
{
	BPTR  aptr;

	/* Scan Command line and step over command prefix */
	/* ---------------------------------------------- */
	while ( *filename == ' ' ) 	filename++;
	aptr = filename;
	while (( *filename ) && ( *filename != ' ' ))
		filename++;

	*(filename++) = 0;
	while ( *filename == ' ' ) 	filename++;
		
	switch ((http_keyword( aptr ))) {
		case	_HTTP_METHOD_GET :
			return( http_get(SocketHandle, filename ) );
		case	_HTTP_METHOD_HEAD		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_CHECKOUT		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_SHOWMETHOD		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_PUT		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_DELETE		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_POST		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_LINK		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_UNLINK		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_CHECKIN		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_TEXTSEARCH		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_SPACEJUMP		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_SEARCH		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_REPLY		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		case	_HTTP_METHOD_EXIT		:
			http_server_error(SocketHandle,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");
			return(0);
		default		  :
			http_server_error(SocketHandle,_HTTP_STATUS_BAD, "Bad request");
			return(0);
		}
}

PRIVATE	INT 		child_worker( cptr )
	CONNECTIONPTR	cptr;
{
	INT	where=0;
	INT	done=0;
	INT	nbytes;
	BYTE	reply;
	BYTE	Command[MAX_NAME_LENGTH];
	INT	status=0;
	INT	SocketHandle=cptr->newsocket;

	/* Collect HTTP command from client */
	/*--------------------------------- */

	where = 0;
	while (1) {
		if ((MAX_NAME_LENGTH - where) == 0)
			break;
		if ((nbytes = SocketRead(SocketHandle,&Command[where],MAX_NAME_LENGTH-where)) < 0)
			break;
		where += nbytes;
		if ( where > 0 ) {
			if ( Command[where-1] == '\n' ) {
				Command[where] = 0;
				if ( trace_active ) 
					trace_puts( Command );
				status = http_command( SocketHandle, Command );
				break;
				}
			}
		}
	return(status);
}

#ifdef	BEFORE_03041997	

	/* --------------------------------------- */
	/* OLD HTTP SERVER OPERATION using SOCKETS */
	/* --------------------------------------- */

PRIVATE	INT	server_operation( pptr, nptr, hptr )
	BPTR	pptr;
	BPTR	nptr;
	BPTR	hptr;
{
	INT	SocketHandle=0;
	INT	NewSocketHandle=0;
	INT	packetsize=0;
	INT	status=0;
	BPTR	irqptr=(BPTR) 0;
	ADDRESS myaddr;
	ADDRESS hisaddr;
	struct  hostent PTR hp=(struct hostent PTR) 0;

	strcpy(ServerIdentity,"http:server:init");

	if ( verbose ) server_banner();

	if ( TraceName != (BPTR) 0 )
		activate_trace( TraceName );

	if ((ServerName = nptr) == (BPTR) 0)
		ServerName = "**anonymous**";
	else if ((status = privatise( ServerName )) != 0)
		return( report_failure( "Privatisation Failure" ));

	HomeUrl    = hptr; HomePath[0] = 0;

	fn_parser(hptr, HomePath, 0x0006);

	sprintf(ServerIdentity,"http:server(%s)",ServerName);

	set_port_address( pptr );

	/* ----------- */
	/* S O C K E T */
	/* ----------- */
	if ((SocketHandle = socket(AF_INET,SOCK_STREAM,0)) < 0)
		return( report_failure( "socket() : creation failure" ));

	memset((BPTR) &myaddr, 0, sizeof( ADDRESS ));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(PortAddress);

	/* ------- */
	/* B I N D */
	/* ------- */
	if ( bind(SocketHandle,(ADDRPTR) &myaddr, sizeof( ADDRESS )) < 0 ) {
		SocketClose(SocketHandle);
		return( report_failure( "bind() : connection failure" ));
		}

	/* ----------- */
	/* L I S T E N */
	/* ----------- */
	if ( listen(SocketHandle,MAX_CLIENTS) < 0 ) {
		SocketClose(SocketHandle);
		return( report_failure( "listen() : connection failure" ));
		}

	if ( verbose )
		printf("%s @ %s Awaiting Client Connection \n",ServerIdentity,socketname((ADDRPTR) &myaddr));

	if ( trace_active ) {
		trace_puts( ServerIdentity );
		trace_puts( " @ ");
		trace_puts( socketname((ADDRPTR) &myaddr));
		trace_puts( "Awaiting Client Connection");
		trace_line();
		}

	while (1) {
		/* ----------- */
		/* A C C E P T */
		/* ----------- */
		packetsize = sizeof( ADDRESS );
		if ((NewSocketHandle = accept(SocketHandle,(ADDRPTR) &hisaddr, &packetsize )) < 0 ) {
			SocketClose(SocketHandle);
			return( report_failure( "accept() : connection failure" ));
			}

		/* ------- */
		/* F O R K */
		/* ------- */
		if ( verbose )
			printf(	"%s.request(%s)\n",
				ServerIdentity,
				socketname((ADDRPTR) &hisaddr));

		if ( trace_active ) {
			trace_puts( ServerIdentity );
			trace_puts( " request from ");
			trace_puts( socketname((ADDRPTR) &hisaddr));
			trace_line();
			}


		if ( PrivateServer ) {
			if (!( authorised_access((irqptr = socketname((ADDRPTR) &hisaddr))) )) {
				http_server_error(SocketHandle,_HTTP_STATUS_UNAUTHORIZED, "Access to this server is currently restricted");
				SocketClose( NewSocketHandle );
				continue;
				}
			}
#ifdef	FORKING_SERVER

		switch ( fork() ) {
			case	-1 : SocketClose(SocketHandle);
				     return( report_failure( "fork() : process creation failure" ));
			case	 0 :
				SocketClose(SocketHandle);
#endif
				status = child_worker(NewSocketHandle);
				SocketClose(NewSocketHandle);
#ifdef	FORKING_SERVER
				exit(0);
			default	   :
				SocketClose(NewSocketHandle);
			}

#else	/* ! FORKING_SERVER */

			/* PROLOGUE DEDICATED SERVER EXIT REQUEST */
			/* -------------------------------------- */
			if ( status ) {
				if ( verbose )
					printf("%s.shutdown\n",ServerIdentity);
				if ( trace_active ) {
					trace_puts( ServerIdentity );
					trace_puts( ".shutdown" );
					trace_line();
					terminate_trace();
					}
				break;
				SocketClose(SocketHandle);
				shutdown(SocketHandle,2);
				}
#endif	/* FORKING_SERVER */

		}
	return(0);
}

	/* ------------------------------------------ */
#else	/* ! BEFORE_03041997 :->:->:-> AFTER_03041997 */
	/* ------------------------------------------ */

	/* -------------------------------------------------- */
	/* NEW HTTP SERVER OPERATION using CONNECTION and URL */
	/* -------------------------------------------------- */

PRIVATE	INT	http_server_operation( nptr, hptr )
	BPTR  nptr;
	BPTR  hptr;
{
	CONNECTIONPTR	Connection=(CONNECTIONPTR) 0;
	URLPTR		ServerUrl=(URLPTR) 0;
	INT		packetsize=0;
	INT		status=0;
	BPTR		irqptr=(BPTR) 0;

	if ( verbose ) http_server_banner();

#ifdef	_TRACE_H
	if ( TraceName != (BPTR) 0 )
		activate_trace( TraceName );
#endif

	/* -------------------------------------------------- */
	/* Establish operational scope PUBLIC or PRIVATE=name */
	/* -------------------------------------------------- */
	if ((ServerName = nptr) == (BPTR) 0)
		ServerName = "public";
	else if ((status = privatise( ServerName )) != 0)
		return( report_failure( "Privatisation Failure" ) );

	sprintf(ServerIdentity,"http:(%s)",ServerName);

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

				/* ------------------------------------- */
				/* A Client Connection has been Detected */
				/* ------------------------------------- */
				if ( verbose )
					printf("HTTP REQUEST From %s At %lu \n",socketname((ADDRPTR) &ServerUrl->address[ServerUrl->adrindex]),time((LPTR) 0));
				
				/* ---------------------------------- */
				/* Perform Service Operation Required */
				/* ---------------------------------- */
				status = child_worker(Connection);

				/* ----------------------------- */
				/* Release the Client Connection */
				/* ----------------------------- */
				drop_connection( Connection );

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
	return(status);
}

	/* --------------- */
#endif	/* BEFORE_03041997 */
	/* --------------- */





#endif	/* _HTTPSERV_C */
	/* ----------- */


