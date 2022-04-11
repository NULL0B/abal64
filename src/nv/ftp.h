//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_ftp_h
#define _html_ftp_h

#include "services.h"

#include "ftpcfg.h"

class	ftp_client : ftp_configuration	{

public:
	ftp_client();

		int	ftp_get( char * mode, char * sptr, char * rptr );
		int	ftp_put( char * mode, char * sptr, char * rptr );

	static	void	parameter( char * nptr, char * vptr );

	static	void	garbage_collection();

	static	int	allow_ftp;
	
	};


#endif	// _html_ftp_h



