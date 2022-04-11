//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_output_zone_h
#define	_html_output_zone_h

#include "printer.h"

class	html_output_zone : 	public	html_printer,
				public html_zone_descriptor {

public:

	html_output_zone(int nbc=64, int nbl=16 );
	~html_output_zone();

	virtual	int 	outputbyte( int c );
	int 		getbyte( int c, int l );
	virtual	int	width();
	};




#endif	// _html_output_zone_h


