#ifndef	_HTTPCLI_C
#define	_HTTPCLI_C

#include "http.h"
#include "url.h"
#include "internet.h"
#include "dns.h"
#include "httpsock.c"
#include "httpfile.c"

int	binary=0;

int	ShutDownFlag=0;

char	ClientBuffer[2048];

void	client_banner()
{
	printf("   HTTP: Client  Version %s \n",__HTTP_VERSION);
	printf("   Provisoire du %s \n",__HTTP_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

void	client_usage(nptr)
char * nptr;
{
	printf("\nUsage : %s ",nptr);
	printf("\n        [ -a ]              : Set Ascii  Transfer  ");
	printf("\n        [ -b ]              : Set Binary Transfer  ");
	printf("\n        [ -s ]              : Shutdown HTTPS       ");
	printf("\n        [ -v ]              : Activate Messages    ");
	printf("\n        [ -l<local_file>  ] : Specify  Local  File ");
	printf("\n        -r<remote>          : Specify  Remote  URL \n");
	return;
}

void	echo_buffer( bptr, blen )
char *	bptr;
int	blen;
{
	while ( blen ) {
		if ( *bptr >= 0x0020 )
			printf("%c",*(bptr++));
		else	break;
		blen--;
		}
	return;
}


int	receive_text( SocketHandle, lptr )
int	SocketHandle;
char *	lptr;
{
	int	length=0;
	char	c;
	int	FileHandle=0;
	int	lbi=0;
	int	lbl=0;
	int	new_line=0;
	int	characters=0;
	char	LineBuffer[MAX_NAME_LENGTH];
	char	TempBuffer[2];

	if ( lptr != (char *) 0)
		if ((FileHandle = FileCreate( lptr )) < 0)
			printf("http:client file creation failure\n");

	
	while ((lbl = SocketRead(SocketHandle,TempBuffer, 1 )) > 0 ) {
		if ( TempBuffer[0] == 0 )
			break;
		if ( lptr == (char *) 0)
			printf("%c",TempBuffer[0]);
		switch (( TempBuffer[0] & 0x00FF )) {
			case	'<'  :
				if ((!( new_line ))
				&&  ( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,__HTTP_CRLF,2) != 2 ))
					break;
				characters = 0;
				if (( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,TempBuffer,lbl ) != lbl ))
					break;
				else	{
					characters++;
					continue;
					}
			case	'\n' :
				new_line = 1;
				characters = 0;
				if (( FileHandle != 0 )
				&&  ( FileWrite( FileHandle,TempBuffer,lbl ) != lbl ))
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
				&&  ( FileWrite( FileHandle,TempBuffer,lbl ) != lbl ))
					break;
				else	continue;
			}
		break;
		}
	if ( FileHandle )
		FileFlush( FileHandle );

	return(0);
}

int	receive_binary( SocketHandle,lptr )
int	SocketHandle;
char *	lptr;
{
	int	length=0;
	char	c;
	int	FileHandle=0;
	char	LineBuffer[256];
	int	lbi=0;
	int	lbl=0;

	
	if ((FileHandle = FileCreate( lptr )) < 0)
		printf("http:client binaryfile creation failure\n");

	while (1) {
		if ((lbl = SocketRead(SocketHandle,LineBuffer, 256 )) < 0 )
			break;
		if ( lbl == 0 )
			break;
		else if ( FileHandle >= 0 ) {
			if ( verbose ) 
				printf("http:client binaryfile write\n");
			if ( FileWrite( FileHandle,LineBuffer,lbl ) != lbl )
				break;
			}
		}
	if ( FileHandle ) {
		if ( verbose )
			printf("http:client binaryfile flush\n");
		FilePurge( FileHandle );
		}
	return(0);
}

int	http_client_error( mptr )
char *	mptr;
{
	if ( verbose )
		printf("%s : %d\n",mptr,errno);
	return( 7 );
}

int 	http_getf(SocketHandle, fptr, lptr, hptr )
int	SocketHandle;
char * fptr;
char * lptr;
char * hptr;
{
	char *  cptr=(char *) http_commands[_HTTP_METHOD_GET];
	int	l=0;

	if ( verbose )
		printf("http:client %s %s AS %s \n",cptr,fptr,(lptr != (char *) 0 ? lptr : "stdout") );

	sprintf(ClientBuffer,"%s %s HTTP/1.0\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\nHost: %s\r\n\r\n",
				cptr,fptr,
				__ACCEPT_IMAGE,
				__ACCEPT_LANGUAGE,
				__ACCEPT_PIXELS,
				__ACCEPT_COLOUR,
				__ACCEPT_OS,
				__ACCEPT_CPU,
				__ACCEPT_USER,
				hptr);

	if ( verbose )
		printf("%s",ClientBuffer);
	if  ( SocketWrite( SocketHandle, ClientBuffer, (l=strlen(ClientBuffer))) != l)
		return( http_client_error("SocketWrite() failure") );

	if ( lptr == (char *) 0 )
		receive_text( SocketHandle, lptr );
	else
	switch ( analyse_filetype( lptr ) ) {
		case	_HTML_FILE :
			receive_text( SocketHandle, lptr );
			break;
		case	_GIF_FILE  :
		case    _BMP_FILE  :
		case    _WAV_FILE  :
		case    _BMF_FILE  :
		case    _AT_FILE  :
		case    _XP_FILE  :
			receive_binary( SocketHandle, lptr );
			break;
		default		:
			if ( binary )
				receive_binary( SocketHandle, lptr );
			else	receive_text( SocketHandle, lptr );
		}
	return( 0 );

}



int	client_operation( nptr, fptr, lptr )
char *  nptr;
char *  fptr;
char *  lptr;
{
	int	SocketHandle=0;
	char *	hptr;
	char	HostBuffer[64];
	struct  sockaddr_in myaddr;
	struct  sockaddr_in hisaddr;
	struct  hostent *hp=(struct hostent *) 0;

	set_port_address("80");

	/* ----------- */
	/* S O C K E T */
	/* ----------- */
	if ((SocketHandle = socket(AF_INET,SOCK_STREAM,0)) < 0)
		return( http_client_error("socket() failed") );
	else	{
		memset((char *) &myaddr, 0,sizeof( ADDRESS ));
		myaddr.sin_family = AF_INET;
		myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		myaddr.sin_port = htons(0);

		/* ------- */
		/* B I N D */
		/* ------- */
		if ( bind(SocketHandle,(ADDRPTR) &myaddr, sizeof( ADDRESS)) < 0 )
			return( http_client_error("bind() failed") );
		memset((char *) &hisaddr, 0,sizeof( ADDRESS ));
		hisaddr.sin_family = AF_INET;
		hisaddr.sin_port   = htons(PortAddress);

		/* ------------------------- */
		/* G E T H O S T B Y N A M E */
		/* ------------------------- */
		if (( *nptr >= '0' ) && ( *nptr <= '9' ))
			hisaddr.sin_addr.s_addr = inet_addr( nptr );
		else	{

			if ((hp = gethostbyname(nptr)) == (struct hostent *) 0)
				return( http_client_error("gethostbyname() failed") );
			memcpy((char *) &hisaddr.sin_addr,(char *)hp->h_addr_list[0],hp->h_length);
			}

		/* ------------- */
		/* C O N N E C T */
		/* ------------- */
		if ((connect(SocketHandle,(ADDRPTR) & hisaddr, sizeof( struct sockaddr ))) < 0 )
			return( http_client_error("connect() failed") );
		else if ( verbose )
			printf("http:client connect to %s \n",socketname((ADDRPTR) &hisaddr));

		strcpy((hptr =  HostBuffer), socketname((ADDRPTR) &hisaddr));
		while ( *hptr )
			if ( *hptr == ':' )
				*hptr = 0;
			else	hptr++;

		if ( ShutDownFlag )
			http_getf( SocketHandle, __HTTP_SHUTDOWN, lptr, HostBuffer );
		else 	http_getf( SocketHandle, fptr, lptr, HostBuffer );


		/* --------------- */
		/* S H U T D O W N */
		/* --------------- */
		(void) shutdown(SocketHandle,2);

		SocketClose( SocketHandle );

		}
	return( 0 );
}

#endif	/* _HTTPCLI_C */
	/* ---------- */


