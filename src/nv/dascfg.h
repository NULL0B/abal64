//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_distant_access_configuration_h
#define _distant_access_configuration_h

class	distant_access_configuration	{

public:
	static	int	usedas;
	static	int	retries;
	static	int	timeout;
	static	int	triesleft;
	static	int	reconfigured;
	static	char *	dllname;
	static  char *  profile;
	static  char *  telephone;
	static  char *  username;
	static  char *  password;


	static	void	setprofile( char * nptr );
	static	void	setdllname( char * nptr );
	static	void	setname( char * nptr );
	static	void	setcode( char * nptr );
	static	void	setnumber( char * nptr );
	static	void	setusage( int v );
	static	void	terminate();
	static	void	release();
	static	void	parameter( char * tptr, char * vptr );

	};


#endif	// _distant_access_configuration_h


