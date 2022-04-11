#ifndef	_RESOLVER_C
#define	_RESOLVER_C

#include "resolver.h"
#include "httpssl.h"

#include "fnparser.c"

PRIVATE	VOID	banner()
{
	printf("   Internet Access   Version %s \n",__BASIC_VERSION);
	printf("   Provisoire du %s \n",__BASIC_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

PRIVATE	VOID	usage(nptr)
	BPTR   nptr;
{
	printf("\nUsage : %s \n",nptr);
	show_global_usage();
#ifdef	_DNS_H
	dns_show_usage();
#endif
#ifdef	_HTTP_H
	http_show_usage();
#endif
	printf("        <remote_url> <service_specific_syntax>    \n");
	printf(" Examples : \n");
	printf("\t -a : Force Ascii  Transfer\n");
	printf("\t -b : Force Binary Transfer\n");
#ifdef	_DNS_H
	dns_show_example();
#endif
#ifdef	_HTTP_H
	http_show_example();
#endif
	return;
}

PRIVATE	INT	analyse_option( aptr )
	BPTR	aptr;
{
	INT	status=0;

	if ( verbose )
		printf("\t-%s\n",aptr);

	switch ( *(aptr++) ) {

#ifdef	_DNS_H
		case    'w' :
		case    'W' : 	dns_set_timeout((BPTR)  aptr ); 
				break;
		case    'h' :
		case    'H' : 	dns_add_host((BPTR)  aptr ); 
				break;
		case    'u' :
		case    'U' : 	dns_set_transport( __URL_TCP );
				break;
				
		case    'r' :
		case    'R' : 	dns_set_recursive(aptr); break;
#endif
#ifdef	_HTTP_H
		case	'p' :	
		case	'P' :	status = http_set_proxy( aptr ); break;
		case    'a' :
		case    'A' : 	status = http_set_ascii(aptr); break;
		case    'b' :
		case    'B' : 	status = http_set_binary(aptr); break;
		case    't' :
		case    'T' : 	status = http_set_accept(aptr); break;
#endif
		case	'd' :
		case	'D' : 	set_global_debug( aptr ); break;

		case	'v' :
		case	'V' : 	set_global_verbose( aptr ); break;
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
	BYTE	ConfigName[64];

	/* Attempt to allocate a standard line buffer */
	/* ------------------------------------------ */
	if ((linebuffer = allocate_zone( MAX_NAME_LENGTH )) == (BPTR) 0)
		status = 27;
	else	{
		fn_parser( nptr, ConfigName, 0x0007 );
		strcat( ConfigName, __RESOLVER_CONFIG );
		nptr = ConfigName;

		if ( verbose )
			printf("resolver configuration : %s \n",nptr );

		if ((handle = FileOpen( nptr , O_RDONLY )) >= 0 ) {

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
		}
	return(status);
}

PRIVATE	VOID	liberation()
{
	liberate_url_services();
#ifdef	_DNS_H
	liberate_dns_memory();
#endif
	return;
}

PRIVATE	INT	initialisation(config_file)
	BPTR	config_file;
{
#ifdef	_DNS_H
	initialise_dns_memory();
#endif
	if (( initialise_url_services() )
#ifdef	_DNS_H
	||  ( initialise_dns_service()  )
#endif
#ifdef	_FTP_H
     	||  ( initialise_ftp_service()  )
#endif
#ifdef	_PPP_H
	||  ( initialise_ppp_service()  )
#endif
#ifdef	_GOPHER_H
	||  ( initialise_gopher_service() )
#endif
#ifdef	_HTTP_H
	||  ( initialise_http_service() )
#endif
#ifdef	_HTTPSSL_H
	||  ( initialise_https_service() )
#endif
#ifdef	_MAIL_H 
	||  ( initialise_mail_service() )
#endif
	||  ( InternetConfiguration( config_file ) )) {
		liberation();
		return(0);
	 	}
	else 	return(1);
}

PRIVATE	INT 	service_main( remote_url, argc, argv )
	BPTR	remote_url;
	INT	argc;
	BPTR	argv[];
{
	INT		status=27;
	URLPTR		uptr=(URLPTR) 0;

	if (( remote_url  != (BPTR) 0 )
	&&  ((uptr = allocate_for_url( remote_url,0L )) != (URLPTR) 0 )) {
		status = service_url( uptr, argc, argv );
		uptr = liberate_for_url( uptr );
		}
	return( status );

}

PUBLIC	INT	main( argc, argv )
	INT	argc;
	BPTR	argv[];
{
	INT	status=0;
	INT	argi=1;
	BPTR  	aptr;

	if ( argc == argi ) {
		banner();
		usage(argv[0]);
		}
	else if ( initialisation(argv[0]) ) {
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
		liberation();
		}					
	return(status);
}


#endif	/* _RESOLVER_C */
	/* ----------- */


