//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_ftp_url_h
#define _ftp_url_h

class	ftp_url	{

public:	char	* hostname;
	char	* username;
	char	* password;
	char	* object;
	ftp_url( char * vptr, char * uptr, char * wptr );
	~ftp_url();
	int	open( FILE * handle, int useproxy=0 );
	int	close( FILE * handle, int useproxy=0 );

	};
	

#endif	// _ftp_url_h





