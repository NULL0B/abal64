//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_link_h
#define _html_link_h

#include "basic.h"

class	html_link_component : 	public 	html_basic_component ,
				public	html_link_descriptor	{

public:
	html_link_component(int t);
	virtual	void	ondestroy();
	virtual void	setparent( html_basic_component * member );
	virtual	int onparse( html_ascii_stream * source );
	virtual	void generate( html_output * target );


	};




#endif	// _html_link_h








