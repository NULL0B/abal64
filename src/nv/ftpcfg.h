//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_ftp_cfg_h
#define _html_ftp_cfg_h

class	ftp_configuration {
public:
	static  void	setexec( char * vptr );
	static	void	setstdin( char * vptr );
	static	void	setstdout( char * vptr );
	static  void	setproxy( char * vptr );
	static  void	setusername( char * vptr );
	static  void	setpassword( char * vptr );

	static	char *	ftpexec;
	static	char *	ftpstdin;
	static	char *	ftpstdout;
	static	char *	ftpproxy;
	static	char *	username;
	static	char *	password;
	};

#endif	// _html_ftp_cfg_h


