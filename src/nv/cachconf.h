//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_configuration_h
#define _html_cache_configuration_h


class	html_cache_configuration {

public:
	static	int		  modified;
	static	int		  cache_bookmarks;
	static	int		  cache_behaviour;
	static	int		  cache_refresh;
	static	char		* cache_books_name;
	static	char		* cache_address_name;
	static	char		* cache_records_name;
	static	char		* cache_fields_name;
	static	char		* cache_tokens_name;
	static	char		* path;
	static	char		* listfile;
	static	long		  cache_items;
	static	void	set_cache_path( char * vptr );
	static	void	set_cache_list( char * vptr );
	static	void	set_cache_items( int i );
	
	};

#endif	// _html_cache_configuration_h


