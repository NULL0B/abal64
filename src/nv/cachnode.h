//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_node_h
#define _html_cache_node_h


class	html_cache_node	: public html_cache_configuration {

public:
	html_cache_node(char * tptr="N");	// Generic Constructor

	virtual void	ondestroy();		
	virtual	void	export( FILE * handle );
	virtual	void	parameters( FILE * handle );
	virtual	int	import( html_ascii_stream * handle );
	virtual	int	parse( char * token, html_ascii_stream * handle );
	
		int	calculate_hash( char * token );

	html_cache_node * previous;	// Previous Node
	html_cache_node * next;		// Next node

	char		* tagname;	// Type of Node

	};




#endif	// _html_cache_node_h


