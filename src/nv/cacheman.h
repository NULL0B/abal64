#ifndef _html_cache_manager_h
#define	_html_cache_manager_h

#include "files.h"
#include "cachtoke.h"
#include "transfer.h"
//	----------------------------------------------------------------------
//	 Hierarchy or Relationships of classes described in this header file
//	----------------------------------------------------------------------
//
//	CacheConfiguration
//	     |
//	CacheManager
//	     |
//	CacheManagerClient
//
//	----------------------------------------------------------------------
//				Description	
//	----------------------------------------------------------------------
//
 
#include "mimedef.h"

#define	_CACHE_HASH 	357
#define	_CACHE_VERSION 	"1.1a"
#define	_CACHE_PREFIX   "0000"
#define	_CACHE_EXT      "tmp"

#define	_CACHE_BOOKS	"nvcacheb"
#define	_CACHE_ADDRESS	"nvcachea"
#define	_CACHE_RECORDS	"nvcacher"
#define	_CACHE_TOKENS 	"nvcachet"
#define	_CACHE_FIELDS 	"nvcachef"

#include "cachconf.h"

class	html_cache_authorize	{

public:
	html_cache_authorize *	previous;
	html_cache_authorize *	next;
	long			identity;
	char		*	value;

public:
	html_cache_authorize( long aid=0L, char * aval=(char*)0);
	~html_cache_authorize();
};


class	html_cache_manager : public 	html_cache_configuration {

	html_cache_records * 	cachebase;
	html_mime_field    *	mimefield;

	html_cache_authorize *	firstauth;
	html_cache_authorize *	lastauth;
	html_cache_authorize *	certificate;


	int			cachebasecheck();
	int			perform_purge( char * cptr );
	int			perform_inspect( char * cptr, standard_url * uptr );
	int			perform_export( char * cptr, standard_url * uptr );
	int			perform_books( char * cptr, standard_url * uptr );
	int			service_prefix( char * sptr );
	int			perform_authorize( char * cptr, standard_url * rptr );
	html_cache_authorize * 	get_authorization();
	static 	void		release_options();
	static	void		analyse_option(char * nptr, char * vptr);
	static	void		analyse_command(char * cptr);
	static	char *		pName;
	static	char *		pWord;
	static	char *		pFile;
	static	char *		pUrl;
#ifdef	_NV11D
	int			wild_export( char * cptr, standard_url * uptr );
#endif
	void			export_item( char * tgtname, char * srcname );

public:
	html_cache_manager();
	~html_cache_manager();

	int 			transferin( html_transfer * xptr, char * nptr, html_ascii_stream * sptr, long transferlength, int chunked=0 );
	int  			resolve( char * sptr, char * tptr, int mode=1 );
	int			refresh(html_mime_field * previous, html_mime_field * current );
	long			getaddress();
	void			setaddress(long a);
	html_mime_field * 	validate( html_transfer * xptr, html_ascii_stream * source,html_mime_field * previous=0, html_mime_field * current=0 );
	html_mime_field *	contract(html_ascii_stream * source);
	html_mime_field *	contract();
	int			addbook( char * dptr );
	int			request( standard_url * uptr );
	char			* temporary_filename();
	char			* get_authority(char * sptr=0);

	};


class	html_cache_manager_client	{
	static	int	cacheready();
public:
	html_cache_manager_client();
	static	void	release();
	static	int	request( standard_url * uptr );
	static	int  	isknown( char * sptr, char * tptr );
	static	long	getaddress();
	static	void	setaddress(long a);
	static	int	addbookmark( char * dptr );
	static	html_cache_manager * cache;
	static	unsigned int	     clients;	
	};

#endif	// _html_cache_manager_h




