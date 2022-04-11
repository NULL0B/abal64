#ifndef	_DNSS_C
#define	_DNSS_C
#define ____FAR_DATA
#include "dnserv.c"

PRIVATE	INT silence=0;

INT	integer_option( aptr )
BPTR	aptr;
{
	INT	v=0;
	if (!( *aptr ))
		v++;
	else 	{
		while ((*aptr) && ( *aptr >= '0' ) && ( *aptr <= '9' ))
			v = ((v * 10) + (*(aptr++) -'0'));
		}
	return( v );
}

INT	main( argc, argv )
INT	argc;
BPTR  	argv[];
{
	INT	argi;
	BPTR	pptr=(BPTR) "53";
	BPTR	nptr=(BPTR) 0;
	BPTR	sptr=(BPTR) 0;

	if ( argc == 1 ) {
		dns_server_banner(); dns_server_usage(argv[0]); return(0);
		}
	else	{
		for ( argi=1; argi < argc; argi++) {
			sptr = argv[argi];
			if ( *sptr == '-' ) {
				switch ( *(sptr+1) ) {
					case 'a' :
					case 'A' : SetConnectionAddress( (BPTR) (sptr + 2) );
						   break;
					case 'r' :
					case 'R' : set_recursive( (sptr + 2) ); 
						   break;
					case 'U' :
					case 'u' : DnsTransport = SOCK_STREAM; 
						   break;
					case 's' :
					case 'S' : silence = 1; break;
					case 'p' :
					case 'P' : pptr = (sptr + 2); break;
					case 'n' :
					case 'N' : nptr = (sptr + 2); break;
					case 'd' :
					case 'D' :
					case 'v' :
					case 'V' : if (!(silence))
							verbose = integer_option( (sptr+2) ); 
						   break;	
					case 't' :
					case 'T' : TraceName = (sptr+2); break;
					default	 : dns_server_banner();
						   printf("%s:error: Incorrect command line option: %s\n",argv[0],argv[argi]);
						   dns_server_usage(argv[0]);
						   return(0);

					}
				}
			else	return( dns_server_operation( pptr, nptr, sptr ) );
			}
		dns_server_banner();
		printf("%s:error: Configuration File parameter required \n",argv[0]);
		dns_server_usage(argv[0]);
		return(0);
		}
}

#endif	/* _DNSS_C */
	/* -------- */



