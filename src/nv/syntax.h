
//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef _html_syntax_h
#define _html_syntax_h

#include "string.h"
#include "streams.h"
#include "language.h"

class	html_language : public html_string	{

public:
	static int		resolve( html_ascii_stream * source );
	static int	 	resolveinput( char * nptr );
	static char *	 	resolveinput( int id );
	static int	 	resolveshape( char * nptr );
	static char *	 	resolveshape( int id );
	static char *		colour ( int id );
	static int		colour ( char * nptr );
	static int		colour ( int rv, int gv, int bv );
	static int		hexdigit( int c );
	static const char * 	keyword( int v );
	static const char * 	media( int v );
	static int 	 	media( char * nptr );
	static const char * 	relation( int v );
	static int 	 	relation( char * nptr );

	};

#endif // _html_syntax_h








