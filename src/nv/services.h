//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_services_h
#define _html_services_h

#include "string.h"
#include "service.h"

#define	_HTML_SERVICE_MAX 	12

#ifndef	_html_language_c
extern	"C"	{ extern char * servicekeyword[ _HTML_SERVICE_MAX ]; };
#define	_HTTP_SERVICE	    	servicekeyword[_SERVICE_HTTP]
#define	_FILE_SERVICE	    	servicekeyword[_SERVICE_FILE]
#define	_CONFIGURE_SERVICE	servicekeyword[_SERVICE_CONFIGURE]
#define	_PRINT_SERVICE    	servicekeyword[_SERVICE_PRINT]
#define	_FTP_SERVICE	    	servicekeyword[_SERVICE_FTP]
#define	_HTTPS_SERVICE    	servicekeyword[_SERVICE_HTTPS]
#define	_FETCH_SERVICE    	servicekeyword[_SERVICE_FETCH]
#define	_CACHE_SERVICE	    	servicekeyword[_SERVICE_CACHE]
#define	_MAILTO_SERVICE   	servicekeyword[_SERVICE_MAILTO]
#define	_MAILSEND_SERVICE 	servicekeyword[_SERVICE_MAILSEND]
#define	_JAVASCRIPT_SERVICE	servicekeyword[_SERVICE_JAVASCRIPT]
#define	_BOOKMARK_SERVICE	servicekeyword[_SERVICE_BOOKMARK]
#endif

#endif	// _html_services_h




