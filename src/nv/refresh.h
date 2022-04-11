//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_refresh_h
#define _html_refresh_h

class	html_refresh_control {

public:
	static	char *	target;
	static	int	timeout;
	static	int	working;

	static	void	activate( char * cptr );
	static	void	terminate( char * cptr );




#endif	// _html_refresh_h



