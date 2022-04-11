#include "http.h"
#include "url.h"
#include "url.c"
#include "ftp.c"
#include "http.c"
#include "mail.c"

#define	_TEST_COUNT	22

static	char * _TEST_DATA[ _TEST_COUNT ] = {
	(char * ) "\0",
	(char * ) "/path/file.ext",
	(char * ) "//server",
	(char * ) "//server:33",
	(char * ) "//server/path/file.ext",
	(char * ) "//server:33/path/file.ext",
	(char * ) "ftp:",
	(char * ) "ftp://server",
	(char * ) "ftp://server:33",
	(char * ) "ftp://server/path/file.ext",
	(char * ) "ftp://server:33/path/file.ext",
	(char * ) "http:",
	(char * ) "http://server",
	(char * ) "http://server:77",
	(char * ) "http://server/path/file.ext",
	(char * ) "http://server:77/path/file.ext",
	(char * ) "http://www.w3.org/WWW/Protocoles/HTTP/AsImplemented.html",
	(char * ) "ftp://www.w3.org/WWW/Protocoles/HTTP/AsImplemented.html",
	(char * ) "mailto:",
	(char * ) "mailto:[jamie]",
	(char * ) "mailto:[jamie@prl.com]",
	(char * ) "http://132.147.160.77/path/document.html"

	};

static	URL	TestUrl;

void	ShowUrl( nptr, uptr )
URLPTR	uptr;
{
	printf("\nURL(%s)\t[",nptr); 
	if (( uptr != (URLPTR) 0) 
	&&  ( uptr->status != _INVALID_URL )) {
		if ( uptr->service != (SERVICEPTR) 0 )
			printf("\n\tService : %s ",uptr->service->name);
		if ( strlen(uptr->host) ) {
			printf("\n\tHost    : %s ",uptr->host);
			printf("\n\tPort    : %d ",(uptr->port ? uptr->port : uptr->base));
			}
		if ( strlen( uptr->path ) )
			printf("\n\tPath    : %s ",uptr->path);
		}
	else	printf("\t** INVALID **");
	printf("\n\t]\n");
	return;
}

int	itest()
{
	if ( InitialiseFtp() ) 
		return(0);
	else if ( InitialiseHttp() ) 
		return(0);
	else if ( InitialiseMail() ) 
		return(0);
	else	return(1);
}

int	main( argc, argv )
int	argc;
char *  argv[];
{
	int	argi;
	int	status;
	printf("   URL Service Analyser\n");
	if ( argc == 1 ) {
		argc = _TEST_COUNT;
		argv = _TEST_DATA;
		}
	if ( InitialiseUrlServices() == 0 ) {
		if ( itest() ) {
		    for (argi=1; argi < argc; argi++) {
			if ((status = parse_url( argv[argi],(URLPTR) & TestUrl )) & _INVALID_URL  )
				printf("Incorrect HTTP URL : %s : 0x0%x  \n",argv[argi],status);
			else 	ShowUrl(argv[argi], (URLPTR) & TestUrl );
			}
		    TerminateUrlServices();
		    }
		}
	return(0);
}


