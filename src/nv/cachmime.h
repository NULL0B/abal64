//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_mime_h
#define _html_cache_mime_h

class	html_cache_mime : public html_cache_node {

public:	
	html_cache_mime(char * nptr=0, char * vptr=0); 
	virtual void ondestroy();		// Preforms specialist destruction
	virtual	void parameters( FILE * handle );
	virtual	int parse( char * token, html_ascii_stream * handle );

	char	* name;			// Mime Header Field Name
	int	  namehash;
	char	* value; 		// Mime Header Field Value
	int	  valuehash;
	};


#endif	// _html_cache_mime_h


