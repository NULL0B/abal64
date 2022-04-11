#ifndef	_HTTPC_C
#define _HTTPC_C

#include "httpcli.c"

int	main( argc, argv )
int	argc;
char *  argv[];
{
	int	argi;
	char * 	sptr;
	char * 	fptr;
	char * 	rptr=(char * ) 0;
	char * 	lptr=(char * ) 0;
	char	ServerName[128];
	
	if ( argc == 1 ) {
		client_banner(); client_usage(argv[0]); return(0);
		}
	else	{
		for ( argi=1; argi < argc; argi++) {
			sptr = argv[argi];
			if ( *sptr == '-' ) {
				switch ( *(sptr+1) ) {
					case 's' :
					case 'S' : ShutDownFlag = 1; break;
					case 'a' :
					case 'A' : binary = 0; break;
					case 'b' :
					case 'B' : binary = 1; break;
					case 'l' :
					case 'L' : lptr = (sptr + 2); break;
					case 'r' :
					case 'R' : rptr = (sptr + 2); break;
					case 'v' :
					case 'V' : verbose = 1; break;
					default	 : client_banner();
						   printf("%s:error: Incorrect command line option: %s\n",argv[0],argv[argi]);
						   client_usage(argv[0]);
						   return(0);
					}
				}
			}
		if ( rptr == (char *) 0 )
			return(2);
		while (( *rptr ) && ( *rptr != '/' )) rptr++;
		if (( *rptr == '/' ) && ( *(rptr + 1) == '/')) {
			rptr += 2;
			fptr  = rptr;
			rptr  = ServerName;
			while (( *fptr ) && ( *fptr != '/' ))
				*(rptr++) = *(fptr++);
			*rptr = 0;
			rptr = ServerName;
			if ( *fptr == 0 ) fptr = (char *) "/";
			return( client_operation( rptr, fptr , lptr ) );
			}
		else	{
			if ( verbose )
				printf("%s:error:server missing %s",argv[0],rptr);
			else	return(3);
			}
		}
}

#endif	/* _HTTPC_C */
	/* -------- */

