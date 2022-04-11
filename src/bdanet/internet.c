#ifndef	_INTERNET_C
#define	_INTERNET_C

#define	____FAR_DATA

#define	__INTERNET_CONFIG (BPTR) "internet.cfg"

#include "http.h"
#include "httpsock.c"
#include "httpfile.c"
#include "dns.h"
#include "url.h"
#include "internet.h"
#include "url.c"
#include "ftp.c"
#include "http.c"
#include "mail.c"
#include "httpcnx.c"
#include "dnsmem.c"
#include "dnsvis.c"
#include "dnsget.c"
#include "dnsput.c"
#include "dns.c"


static	void	banner()
{
	printf("   Internet Access   Version %s \n",__HTTP_VERSION);
	printf("   Provisoire du %s \n",__HTTP_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

VOID	usage(nptr)
BPTR   nptr;
{
	printf("\nUsage : %s ",nptr);
	printf("\n        [ -a<address>    ] : Set IP Address       ");
	printf("\n        [ -v ]             : Activate Messages    ");
	printf("\n        [ -d ]             : Activate Debug       ");
	printf("\n        [ -h<primarydns> ] : Set primary DNS Host ");
	printf("\n        [ -r[a | d | ]   ] : Inhibit DNS Recursive ");
	printf("\n        [ -u ]	     : Inhibit DNS UDP use TCP");
	printf("\n        <remote_url> <service_specific_syntax>    ");
	printf("\n Examples : ");
	printf("\n        http://hostname/filename GET  <local_file> ");
	printf("\n        dns://hostname GET <domain> <type> <class> ");
	return;
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

		case	'a' :
		case	'A' :	SetConnectionAddress( (BPTR) aptr );
				break;
		case    'h' :
		case    'H' : 	DnsAddHost((BPTR)  aptr ); 
				break;
		case    'u' :
		case    'U' : 	DnsTransport   = __URL_TCP;
				break;
				
		case    'r' :
		case    'R' : 	set_recursive(aptr); break;

		case	'd' :
		case	'D' : 	debug = integer_option( aptr );
		case	'v' :
		case	'V' : 	verbose = integer_option( aptr ); 
				break;
		default	    : 	status = 30;
		}
	return(status);
}

PRIVATE	INT	InternetConfiguration(nptr)
BPTR		nptr;
{
	BPTR	linebuffer;
	INT	status=0;
	INT	handle=0;
	INT	llen=0;

	/* Attempt to allocate a standard line buffer */
	/* ------------------------------------------ */
	if ((linebuffer = allocate_zone( MAX_NAME_LENGTH )) == (BPTR) 0)
		status = 27;

	else if ((handle = FileOpen( nptr , O_RDONLY )) >= 0 ) {

		if ( verbose )
			printf("internet configuration : %s \n",nptr );

		while ((llen = FileGetLine( handle, linebuffer, MAX_NAME_LENGTH )) != 0) {

			/* Avoid Empty Lines */
			/* ----------------- */
			while (*linebuffer == ' ')
				linebuffer++;
			if ( *linebuffer == 0 )
				continue;
			else if (( *(linebuffer++) = '-')
			     &&  ((status = analyse_option( linebuffer )) != 0 ))
				break;
			}
		(VOID) FileClose( handle );
		}
	linebuffer = liberate_zone( linebuffer );
	return(status);
}

static	int	initialisation()
{
	initialise_dns_memory();
	if ( InitialiseUrlServices() )
		return( 0 );
	else if (( InitialiseDns()  ) 
	     ||  ( InitialiseFtp()  ) 
	     ||  ( InitialiseHttp() ) 
	     ||  ( InitialiseMail() )
	     ||  ( InternetConfiguration(__INTERNET_CONFIG) )) {
		TerminateUrlServices();
		liberate_dns_memory();
		return(0);
	 	}
	else 	return(1);
}

int 	service_main( remote_url, argc, argv )
char *	remote_url;
int	argc;
char *  argv[];
{
	int		status=0;
	URL		HostUrl;
	URLPTR		urlptr=(URLPTR) 0;
	CONNECTIONPTR	cptr=(CONNECTIONPTR) 0;
	if ( remote_url  != (char *) 0 ){
		urlptr = (URLPTR) &HostUrl;
		if ( parse_url( remote_url, urlptr ) != 0)
			return;
		if (( urlptr->status & _URL_IS_HOST )
		&&  ( resolve_internet_host( urlptr ) == 0)) {

			switch ( urlptr->transport ) {
				case __URL_TCP : cptr = connect_tcp_client( urlptr );
						 break;
				case __URL_UDP : cptr = connect_udp_client( urlptr );
						 break;
				default	       : cptr = (CONNECTIONPTR) 0;
				}
			if (cptr != (CONNECTIONPTR) 0) {
				status = ServiceUrl( cptr, argc, argv );
				cptr = close_connection( cptr );
				return( status );
				}
			}
		}
	return( 0 );
}

int	main( argc, argv )
int	argc;
char *  argv[];
{
	int	status=0;
	int	argi=1;
	char *	aptr;
	URL	Result;
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
				status = service_main( aptr,(argc - argi), & argv[argi] );
				break;
				}
			}
	    	TerminateUrlServices();
		liberate_dns_memory();
		}					
	return(status);
}


#endif	/* _INTERNET_C */
	/* ----------- */

