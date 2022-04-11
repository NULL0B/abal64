//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_parser_h 
#define  _html_parser_h 

#include "streams.h"

class	html_compiler  {

public:	
	static int			operation(html_ascii_stream * source);

private:
	int	thistag;
	void	putb( int c );
	};



#endif // _html_parser_h 

