//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cache_token_h
#define _html_cache_token_h

#define	_MAX_CACHE_TOKEN 48

#define	_MAX_CACHE_ITEMS (_MAX_CACHE_TOKEN / sizeof( long ))

#include <stdio.h>

#include "mime.h"
#include "isam.h"
#include "cachconf.h"

class	html_cache_entity;

//	----------------------------
//	CLASS : HTML_CACHE_REFERENCE
//	----------------------------

class	html_cache_reference	{

public:
	html_cache_reference();
	void	reset();
	int	add(int i, long v);

	long	values[_MAX_CACHE_ITEMS];

	};



//	------------------------
//	CLASS : HTML_CACHE_TOKEN
//	------------------------

class	html_cache_token	:	public	standard_misam,
					html_cache_configuration {

public:	 html_cache_token( char * nptr );
	~html_cache_token();

	long	resolve_record();
	int 	resolve( char * host, char * token, html_cache_reference * rptr );
	int 	resolve( char * token, html_cache_reference * rptr );
	char *	reverse( html_cache_reference * rptr );
	char *	reverse( long rvalue );
	char	qbuffer[256];

	};


class	html_cache_fields	:	public	standard_misam,
					html_cache_configuration {

	html_cache_token * 	tokens;
	html_cache_reference	reference;
	long			working;

public:	 html_cache_fields( char * nptr, html_cache_token * tptr  );
	~html_cache_fields();

	int	add_field( long owner, char * nptr, char * vptr );
	int	del_field( long owner, char * nptr );
	void	del_fields( long owner );
	int	check_field( long owner, char * nptr, char * vptr );

	html_mime_field  * first_field( long owner );
	html_mime_field  * next_field ( long owner );

	};


class	html_cache_record	{

public:	long	item;
	void	reset();

	};


class	html_cache_records	:	public	standard_misam,
						html_cache_configuration {

	standard_misam		* cacheaddress;
	standard_misam		* cachebooks;
	html_cache_token 	* cachetokens;
	html_cache_fields	* cachefields;
	html_cache_reference	  reference;
	char			  tempname[256];
	char			  qbuffer[256];
	long			thisaddress;

public:	 html_cache_records( char * bptr="books", char * rptr="records", char * fptr="fields", char * tptr="tokens", char * aptr="address" );
	~html_cache_records();


	void			release( long rvalue );
	int			resolve( char * uptr, int mode=1 );
	int			resolve( char * host, char * url, int mode=1 );
	int			resolve( int item , char * hostname, char * url );
	int			validate( );
	int			addbook(char * dptr);
	long			getaddress();
	void			setaddress(long a);
	char *			firstbook();
	char *			nextbook();
	void			purge_uri(char * uptr=(char *) 0);
	void			purge_book(char * uptr=(char *) 0);
	char * 			next_uri();
	char * 			first_uri();
	char *			target();
	void			add_field( char * nptr, char * vptr );
	void			del_field( char * nptr );
	html_cache_record	record;
	html_mime_field  * 	first_field();
	html_mime_field  * 	next_field ();
	long			hostid;
	
	};



#endif	// _html_cache_token_h




