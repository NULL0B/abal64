//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_file_h
#define _html_cache_file_h

class	html_cache_host;

class	html_cache_entity : public html_cache_list {

public:
	html_cache_entity(html_cache_host * pptr);
	virtual void ondestroy();
	virtual	void parameters( FILE * handle );
	virtual	int parse( char * token, html_ascii_stream * handle );
	virtual	html_cache_node * member( char * token, html_ascii_stream * handle );
	virtual char * locate( char * vptr );
	virtual void   add( char* nptr, char * vptr );
	virtual html_cache_entity * copy();
	virtual int	outofdate( html_cache_entity * xptr );

	int		isvalid;
	int		hits;
	int	  	hashcode;
	char	*	name;		// Stores Logical Name of Entity
	int 		value;		// Stored Resolved Name of Entity

	html_cache_host * parent;	// Parent Host

	static	char	temporaryname[256];

	char		* temporary_filename();

	};

#endif	// _html_cache_file_h


