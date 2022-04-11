//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_streams_h 
#define  _html_streams_h 

#include "output.h"
#include "types.h"
#include "mime.h"
#include "options.h"

class	html_stream {
public:
	html_mime_field * header;
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET" )=0;
	virtual	int close( char * filename )=0;
	virtual int read( char * buffer, int length )=0;
	virtual int status()=0;
	};

class	html_binary_stream : public html_stream {
public:
	html_binary_stream();
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET" );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();
	};

class	html_ascii_stream : public html_stream {
public:
	html_ascii_stream(int a=0);

	virtual	int open( char * filename, char * filetype, char * xfermethod="GET" );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();
	virtual void conversion( char * charset );

	virtual void putb( int c );	// USed by Script Processors

	void		ungetb( int c );
	void		ungets( char * sptr );
	int 		getb();
	int 		geti();
	int 		skipwhite();
	int 		skipvalue();
	int 		notwhite();
	int 		token_legal( int c );
	int 		upper_legal( int c );
	int 		get_tagname( char * buffer, int length );
	int 		get_token( char * buffer, int length );
	int 		get_value( char * buffer, int length );
	int 		get_integer();
	char * 		get_string();
	standard_url * 	get_url();
	int 		flush_tag();
	int 		skipcomment();
	int	convert;

	int		ungotch;		// Holds Un Got Character
	char *  	ungots;			// Holds ungot string
	int		comment;		// comment character
	};

 
#endif // _html_streams_h 






