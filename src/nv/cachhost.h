//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_host_h
#define _html_cache_host_h


class	html_cache_host : public html_cache_list {

public:
	html_cache_host();
	virtual void ondestroy();
	virtual	void parameters( FILE * handle );
	virtual	int  parse( char * token, html_ascii_stream * handle );
	virtual	html_cache_node * member( char * token, html_ascii_stream * handle );

	int		hits;
	int	  	hashcode;
	char	*	name;		// Stores Host Name String
	char	*	value;		// Stores the Internet Address

	};


#endif	// _html_cache_host_h


