#ifndef	_HTTP_H
#define	_HTTP_H

#undef	HTTP11

#include "basic.h"
#include "address.h"

#define	__HTTP_VERSION	BASIC_VERSION
#define	__HTTP_DATE	BASIC_DATE
#define	__HTTP_CRLF	"\r\n"

#define __HTTP_SHUTDOWN 	"Shutdown.Now"
#define __HTTP_STATISTICS 	"HttpStat.Htm"

#define __HTTP_PORT	80
#define	__HTTP_PREFIX	"http:"

#define	HTTPMSG		struct http_message
#define	HTTPVAR		struct http_variable

#define	HTTPMSGPTR	HTTPMSG PTR
#define	HTTPVARPTR	HTTPVAR PTR

HTTPVAR		{
	BPTR		name;
	BPTR		value;
	HTTPVARPTR	next;
	};

HTTPMSG		{
	BPTR		command;
	BPTR		object;
	BPTR		parameters;
	BPTR		version;
	HTTPVARPTR	variables;
	};

#ifdef	HTTP11
#define	_HTTP11				"HTTP/1.1"
#define	_HTTP_COMMAND_MAX 	8

#else
#define	_HTTP_COMMAND_MAX 	3
#endif


#define	_IB_SIZE 	2048
#ifdef	_HTTP_C

PUBLIC 	BPTR		InputBuffer=(BPTR) 0;

PRIVATE	SERVICE	HttpService;
PRIVATE	INT	ShutDownFlag=0;

static	BPTR	http_commands[_HTTP_COMMAND_MAX] = {
	(BPTR) "GET",
	(BPTR) "POST",
	(BPTR) "HEAD"
#ifdef	HTTP11
	,(BPTR) "PUT",
	(BPTR) "DELETE",
	(BPTR) "TRACE",
	(BPTR) "OPTIONS",
	(BPTR) "CONNECT"
#endif
	};
#else
EXTERN 	BPTR		InputBuffer;
#endif

#define _HTTP_METHOD_GET		0
#define _HTTP_METHOD_POST		1
#define _HTTP_METHOD_HEAD		2
#ifdef	HTTP11
#define _HTTP_METHOD_PUT		3
#define _HTTP_METHOD_DELETE		4
#define _HTTP_METHOD_TRACE		5
#define _HTTP_METHOD_OPTIONS		6
#define _HTTP_METHOD_CONNECT		7
#endif

#define _HTTP_VERSION			"HTTP/1.0"

#define	_HTTP_STATUS_SUCCESS   		"200 "
#define	_HTTP_STATUS_CREATED   		"201 "
#define	_HTTP_STATUS_ACCEPTED  		"202 "
#define	_HTTP_STATUS_PARTIAL   		"203 "
#define	_HTTP_STATUS_NOANSWER  		"204 "

#define	_HTTP_STATUS_MOVED		"301 "
#define	_HTTP_STATUS_FOUND		"302 "
#define	_HTTP_STATUS_METHOD		"303 "
#define	_HTTP_STATUS_NOCHANGE		"304 "

#define	_HTTP_STATUS_BAD      		"400 " 
#define	_HTTP_STATUS_UNAUTHORIZED 	"401 "
#define	_HTTP_STATUS_PAYMENT  		"402 "
#define	_HTTP_STATUS_FORBIDDEN		"403 "
#define	_HTTP_STATUS_NOTFOUND 		"404 "
#define	_HTTP_STATUS_PROXY_UNAUTHORIZED "407 "
#define	_HTTP_STATUS_INTERNAL 		"500 "
#define	_HTTP_STATUS_IMPLEMENTATION	"501 "
#define	_HTTP_STATUS_OVERLOADED    	"502 "
#define	_HTTP_STATUS_TIMEOUT       	"503 "

#define	_HTML_FILE			0
#define	_BMP_FILE			1
#define	_GIF_FILE			2
#define	_JPEG_FILE			3
#define	_WAV_FILE			4
#define	_MOV_FILE			5
#define	_BMF_FILE			6
#define	_ICO_FILE			7
#define	_EXE_FILE			8
#define	_COM_FILE			9
#define	_XP_FILE			10
#define	_AT_FILE			11
#define	_DNS_FILE			12
#define	_CLA_FILE			13
#define	_JAV_FILE			14

#define	__CONTENT_LENGTH	"Content-Length:"
#define	__CONTENT_TYPE 		"Content-Type:"
#define	__MULTIPART_FORM	"multipart/form-data"
#define	__FORM_DATA		"form-data; name="
#define	__CONTENT_DISPO		"Content-Disposition:"
#define	__ACCEPT_IMAGE 		"Accept:"
#define	__ACCEPT_LANGUAGE 	"Accept-Language:"
#define	__ACCEPT_AUTH	 	"Authorization:"
#define	__ACCEPT_PROXY_AUTH	"Proxy-Authorization:"
#define	__ACCEPT_PIXELS		"UA-pixels:"
#define	__ACCEPT_COLOUR		"UA-color:" 
#define	__ACCEPT_OS		"UA-OS:"
#define	__ACCEPT_CPU		"UA-CPU:"
#define	__ACCEPT_USER		"User-Agent:"
#define	__ACCEPT_CONNECTION 	"Connection:"
#define	__ACCEPT_HOST	 	"Host:"
#define	__PERSIST		"persist"
#define	__PRAGMA		"Pragma:"

/*	-------------------------------------------------------		*/
/*	Public Function Prototypes for the HTTP (client) Module 	*/
/*	-------------------------------------------------------		*/

PUBLIC	INT		initialise_http_service();
PUBLIC	INT		analyse_filetype( BPTR );
PUBLIC	INT		http_keyword( BPTR );
PUBLIC	HTTPVARPTR	liberate_http_variable(HTTPVARPTR);
PUBLIC 	HTTPVARPTR	allocate_http_variable();
PUBLIC	INT        	build_http_variable(HTTPMSGPTR,BPTR, BPTR);
PUBLIC	HTTPMSGPTR	liberate_http_message(HTTPMSGPTR);
PUBLIC	HTTPMSGPTR	allocate_http_message();
PUBLIC 	INT		http_putb( CONNECTIONPTR,BYTE);
PUBLIC 	INT		http_put( CONNECTIONPTR,BPTR,INT);
PUBLIC 	INT		http_put_message( CONNECTIONPTR, HTTPMSGPTR );
PUBLIC  HTTPVARPTR	http_get_variables( INT	);
PUBLIC	HTTPMSGPTR	http_get_message( CONNECTIONPTR	);
PUBLIC	BPTR		http_get_line( INT  );
PUBLIC	BPTR		http_get_boundary();
PUBLIC	INT		http_set_accept( BPTR );

PUBLIC	VOID	http_set_minor(INT v);
PUBLIC	VOID	http_set_major(INT v);
PUBLIC	WORD	http_get_major();
PUBLIC	WORD	http_get_minor();

PUBLIC	INT	http_set_content_type( BPTR );
PUBLIC	INT	http_use_encryption( INT );
PUBLIC	INT		HttpSendMessage( CONNECTIONPTR, BPTR, BPTR, BPTR ); 
PUBLIC	INT	http_set_authorization( BPTR );
PUBLIC	INT	http_set_proxy_authorization( BPTR );

/*	------		*/
/*	Macros 		*/
/*	------		*/
#define http_puts(h,s) http_put(h,s,strlen(s))
#define http_putl(h) if (http_putb(h,'\r') != 0) http_putb(h,'\n')
#define http_eot(h) (VOID) http_putb(h,0)


#endif	/* _HTTP_H */
	/* ------- */


