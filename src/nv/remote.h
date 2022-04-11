//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_remote_h 
#define  _html_remote_h 

#include "internet.h" 
#include "streams.h"

class	remote_proxy	{

	static int	allow_proxy;
	static char *	proxy_server;
	static int	use_proxy;
	static char *	remote_options;

	static int	use_http_for_ftp;

	static	void	toggle_proxy();
	static	void	set_proxy(char * pptr);
	static	void	set_remote_option(char * pptr);

	};

class	remote_file 	: 
		public html_ascii_stream,
		public remote_proxy  
	{
	
public:
	remote_file();
	~remote_file();
	virtual	int open( char * filename, char * filetype );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();

private:
	static int	library_status;	// Controls Initialise/Liberate
	int		socket;		// Stores socket of connection

	};

class	remote_binary_file  :
		public html_binary_stream,
		public remote_proxy  
	{

public:
	remote_binary_file();
	virtual	int open( char * filename, char * filetype );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();

private:
	static int	library_status;	// Controls Initialise/Liberate
	int		socket;		// Stores socket of connection

	};

#endif // _html_remote_h 




