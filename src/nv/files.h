//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_files_h 
#define  _html_files_h 
#include "streams.h" 

class	local_binary_file 	: public html_binary_stream {

public:
	local_binary_file();
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET" );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();

private:
	int	handle;

	};


class	local_ascii_file 	: public html_ascii_stream {

public:
	local_ascii_file();
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET"  );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();

private:
	FILE * handle;
	int	nature;
	};


#endif // _local_files_h 

