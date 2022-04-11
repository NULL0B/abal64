//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_http_h 
#define  _html_http_h 

#include "internet.h" 
#include "streams.h"

class	http_equivalence 	{
public:
	char 			* name;
	char 			* value;
	http_equivalence	* next;
	http_equivalence( char * nptr, char * vptr );
	~http_equivalence();
	};


class	remote_proxy 	{
public:
	static int	allow_proxy;
	static int	allow_http;
	static int	quick_dns;

	static char *	proxy_server;
	static char *	user_agent;
	static int	use_proxy;
	static char *	remote_options;
	static char *	remote_types;

	static	void	toggle_proxy();
	static	void	set_proxy(char * pptr);
	static	void	set_agent(char * pptr);

	static	void	set_remote_type(char * pptr);
	static	void	build_remote_options( int mode );

#ifdef	_NV11F
	static	int	remote_timeout;
	static	void	set_remote_timeout( char * pptr );
#endif

	static int	library_status;	// Controls Initialise/Liberate

	static int	persistant;

	static	int	garbage_collection();

	http_equivalence * 	variables;
	int			http_status;
	remote_proxy();

	static	void	authorise( char * pwptr );

	static	void	authoriseproxy( char * pwptr );

	static int	use_http_for_ftp;

	static	void	clear_connection();

	};


class	remote_file 	: 
	public html_ascii_stream,
	public remote_proxy	{
	
public:
	remote_file();
	~remote_file();
	virtual	int open( char * filename, char * filetype, char * xfermethod="GET", long ip_address=0L, int mode=1 );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();
	void	keepalive(int mode);
	int	unicode;	
	long		IpAddress;	// Stores IP address of connection
#ifdef	_NV11C
	void	activate_encryption( char * cryptcode );
#endif

private:
	int		compare( char * cptr );
	int		socket;		// Stores socket of connection
	};


class	remote_binary_file  : 	public html_binary_stream,
			    	public remote_proxy	{
	
public:
	remote_binary_file();
	~remote_binary_file();
	virtual	int open( char * filename, char * filetype, char * xfermethod );
	virtual	int close( char * filename );
	virtual int read( char * buffer, int length );
	virtual int status();
	long	IpAddress;	// Stores IP address of connection
#ifdef	_NV11C
	void	activate_encryption( char * cryptcode );
#endif

private:
	int		notwhite();
	int		skipwhite();
	int		getb();
	int		geti();
	void		ungetb(int c);
	int		compare( char * cptr );
	int		socket;		// Stores socket of connection
	int		ungotb;		// Stores an Ungot Character 
	};

#endif // _html_http_h 





