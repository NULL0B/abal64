//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_host_file_h
#define _html_host_file_h

#include "isam.h"

#define	CacheHostIndex 	64
#define	CacheHostRecord	64

class	cache_host_file	: public standard_isam {

public:
	cache_host_file( char * nptr );
	~cache_host_file();

	};


#endif	// _html_host_file_h


