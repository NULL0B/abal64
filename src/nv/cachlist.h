//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_list_h
#define _html_cache_list_h


class	html_cache_list	: public html_cache_node {

public:
	html_cache_list(char * tptr="L");	// Generic Constructor
	virtual void ondestroy();		// Preforms specialist destruction
	virtual	void export( FILE * handle );
	virtual	int import( html_ascii_stream * handle );
	virtual	html_cache_node * member( char * token, html_ascii_stream * handle );

	html_cache_node * first;	// Top of List
	html_cache_node * last;		// End of List

	};




#endif	// _html_cache_list_h


