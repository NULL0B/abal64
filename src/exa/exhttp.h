#ifndef	_EXHTTP_H
#define	_EXHTTP_H

#include "extcp.h"

#define	MAX_HTTP_BUFFER	8192
#define	_HTTP_FILE_BUFFER 8192
#define	_HTTP_COOKIE_HASH 157	
struct	http_cookie
{
	struct	http_cookie * previous;
	struct	http_cookie * next;
	char *	value;
	int	vhash;
	char *	host;
	int	hhash;
	int	port;
	char *	object;
	int	ohash;
};

struct	http_header
{
	struct http_header * previous;
	struct http_header * next;
	char	*	name;
	char	*	value;
};

struct	http_response
{
	int	status;
	char	version[16];
	char *	message;
	struct	http_header * first;
	struct	http_header * last;
};

struct	http_request
{
	char *	method;
	char *	object;
	char *	host;
	struct	http_header * first;
	struct	http_header * last;
};

int			http_get( char * host, int port, char * object, char * infilename );
int			http_post( char * host, int port, char * object, char * outfilename, char * infilename );
struct	http_request * 	http_recv_request( int handle );
char *			http_tempname();
struct http_request * http_drop_request( struct http_request * rptr );
struct http_response * http_drop_response( struct http_response * rptr );
int	http_request_line( int handle, char * method, char * object );
int	http_response_line( int handle, int status, char * message );
int	http_header_field( int handle, char * name, char * value );
int	http_content_length( int handle, char * filename );
int	http_send_file( int handle, char * filename );
char *	http_header_value( struct http_header * hptr, char * name );
int	http_file_response( int handle, struct http_response * rptr, char * filename );
int	http_recv_file_request( int handle, struct http_request * rptr, char * filename );
int 	http_end_header( int handle );

	/* --------- */
#endif	/* _EXHTTP_H */
	/* --------- */

