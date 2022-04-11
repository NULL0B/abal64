//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_h
#define _html_cache_h

#include "streams.h"

class	html_cache	{

	static	char buffer[1024];

public:
	static	char	*	path_prefix;
	static	int		respect_colours;
	static	int		cache_counter;
	static	int		buffersize;
	static	void		set_path_prefix( char * pptr );
	static	char 	*	cache_file( char * xptr, html_stream * sptr );
	static	void		load_configuration();
	static	void		save_configuration();

	};


#endif	// _html_cache_h


