#ifndef	_PPPS_C
#define	_PPPS_C

#include "http.h"
#include "ppp.h"
#include "lcp.h"
#include "httpsock.c"
#include "httpfile.c"
#include "dns.h"
#include "url.h"
#include "internet.h"
#include "url.c"
#include "ftp.c"
#include "http.c"
#include "mail.c"
#include "ppp.c"
#include "httpcnx.c"
#include "dnsmem.c"
#include "dnsvis.c"
#include "dnsget.c"
#include "dnsput.c"
#include "dns.c"

PRIVATE	VOID	banner()
{
	printf("   Point to Point Protocol Server Version %s \n",__HTTP_VERSION);
	printf("   Provisoire du %s \n",__HTTP_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

PRIVATE	VOID	usage( mptr )
	BPTR	mptr;
{
	return;
}

PRIVATE	INT 	operation( cptr )
	BPTR	cptr;
{
	URLPTR		ServerUrl=(URLPTR) 0;
	CONNECTIONPTR	SocketHandle=(CONNECTIONPTR) 0;
	INT		status=0;

	/* ------------------------------------- */
	/* Prepare Address Package of Connection */
	/* ------------------------------------- */
	if ( verbose )
		printf("ppps.operation(%s)\n",cptr);

	if ((ServerUrl = allocate_for_url( "ppp://0.0.0.0/",0L )) == (URLPTR) 0) {
		printf("ppps:url allocation failure\n");
		status = 27;
		}
	/* ----------------------------------------------- */
	/* Attempt to Open the Type of Connection Required */
	/* ----------------------------------------------- */
	else 	{
		if ((SocketHandle = open_connection(ServerUrl->transport,( ServerUrl->port ? ServerUrl->port : ServerUrl->base ),	ServerUrl )) == (CONNECTIONPTR) 0) {
			printf("ppps:connection failure\n");
			status = 44;
			}
		else	{
			status = 0;
			SocketHandle = close_connection( SocketHandle );
			}
		}
	ServerUrl = liberate_for_url( ServerUrl );
	return(status);	/* OK : Success */
	
}

PRIVATE	VOID	liberation()
{
	TerminateUrlServices();
	liberate_dns_memory();
	return;		/* OK : Success */
}

PRIVATE	INT 	initialisation()
{
	initialise_dns_memory();
	if ( InitialiseUrlServices() )
		return( 0 );
	else if (( InitialiseDns()  ) 
	     ||  ( InitialiseFtp()  ) 
	     ||  ( InitialiseHttp() ) 
	     ||  ( InitialiseMail() )
	     ||  ( InitialisePpp() ) ) {
		liberation();
		return(0);
	 	}
	else 	return(1);
}


INT	integer_option( aptr )
BPTR	aptr;
{
	INT	v=0;
	if (( *aptr == 0 ) || ( *aptr == ' ' ))
		return(1);
	else 	{
		while ((*aptr) && ( *aptr >= '0' ) && ( *aptr <= '9' )) {
			v *= 10;
			v += (*(aptr++) - '0');
			}	
		return( v );
		}
}

PRIVATE	INT	analyse_option( aptr )
	BPTR	aptr;
{
	INT	status=0;
	switch ( *(aptr++) ) {
		case	'd' :
		case	'D' :	debug   = integer_option( aptr );
		case	'v' :
		case	'V' :	verbose = integer_option( aptr );
				break;
		default	    : 	status = 30;
		}
	return(status);
}

PUBLIC	INT	main( argc, argv )
	INT	argc;
	BPTR	argv[];
{
	INT	status=0;
	INT	argi=1;
	BPTR	aptr;

	if ( argc == argi ) {
		banner();
		usage(argv[0]);
		}
	else if ( initialisation() ) {
		while ( argi < argc ) {
			aptr = argv[argi++];
			if ( *aptr == '-' ) {
				aptr++;
				if ( analyse_option( aptr ) == 0 )
					continue;
				else	{
					banner();
					printf("\n * * Syntax Error * *\n");
					usage(argv[0]);
					break;
					}
				}
			else	{
				status = operation( aptr );
				break;
				}
			}
		liberation();
		}					
	return(status);
}



#endif	/* _PPPS_C */
	/* ------- */

