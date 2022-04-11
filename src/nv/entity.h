//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_entity_h
#define	_html_entity_h

#include "streams.h"
#include "files.h"
#include "http.h"
#include "textdesc.h"
#include "transfer.h"
#include "cacheman.h"
#include "ftp.h"

class	html_entity : 	public 	html_ascii_stream,
				html_transfer,
				html_cache_manager_client,
				ftp_client {
public:
	html_entity(int mode=0);
	~html_entity();
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET" );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();
	virtual void conversion( char * charset );
	virtual	void putb( int c );
	html_mime_field * determine_content_type( char * filename, char * filetype );
	standard_url	* redirection(char * hptr=(char *) 0);
	void		keepalive(int mode );
	static	int	nokeepalive;
	int		remote_status;
private:
	remote_file *	connector;
	html_ascii_stream * source;
	html_text_descriptor * forward;
	int	fwb;
	int	nature;
	};

class	html_binary_entity : 	public 	html_binary_stream,
					html_transfer,
					html_cache_manager_client,
					ftp_client {

public:
	html_binary_entity();
	~html_binary_entity();
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET" );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();
	char *	    getname();
	char *		ressourcename;
	html_mime_field * determine_content_type( char * filename, char * filetype );
	standard_url	* redirection(char * hptr=(char *) 0);
	void		keepalive(int mode );
	int		remote_status;
private:
	remote_file *	connector;
	html_binary_stream * source;

	};

#endif	// _html_entity_h


