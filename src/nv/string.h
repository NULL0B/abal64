//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_string_h
#define	_html_string_h

class	html_string {

public:
	static char * 	detect( char * sptr, char * rptr );
	static int	length( const char * sptr );
	static char * 	copy( char * lptr, const char * rptr );
	static char * 	join( char * lptr, const char * rptr );
	static int	compare( const char * aptr, const char * bptr );
	static char *   allocate( const char * sptr );
	static char *   allocate( int n );
	static void     liberate( char * sptr );
	static void     uppercase( char * sptr );
	static void     lowercase( char * sptr );
	static char *   concatenate( const char * sptr, const char * tptr );
	static int	to_integer( char * sptr );
	static int	to_boolean( char * sptr, int truevalue=1 );
	static int	compare( const char * aptr, const char * bptr, int character );
	static int	compare( int character, const char * aptr, const char * bptr );

	static int	length( int character, const char * sptr );
	static char * 	notwhite( char * sptr );
	static int  	wildcomp( char * sptr, char * wildptr );
	static int	resolve_macro( char * buffer );
	static char *	selection_template( char * cptr );
	static char * 	remove_method( char * sptr );
	static void   	resolve_macros( char * vptr );
	static int	to_service( char * vptr );
	static int	ucompare( const char * aptr, const char * bptr );
	};

#endif	// _html_string_h








