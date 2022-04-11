//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_url_h 
#define  _html_url_h 

#include "services.h"

class	standard_url {
public:
	standard_url(char * vptr=0,char * pptr=0);
	~standard_url();
	void	usebase( char * uptr, char * bptr );
	void	addstring( char * uptr );
	void	usemethod( char * mptr );
	void	addtype( char * tptr );
	char * value;
	char * type;
	static	char *	filepart( char * cptr );

	};


#endif // _html_url_h 

