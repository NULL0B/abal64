//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_raw_files_h
#define _html_raw_files_h

extern "C" {
	int	rawopen( char * );
	void	rawclose( int );
	int	rawread( int, char *, int );
	};



#endif	// _html_raw_files_h


