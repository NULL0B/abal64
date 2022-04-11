//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_base_h
#define _html_base_h

#include "basic.h"

class	html_base_component : 	public html_basic_component ,
				public	html_base_descriptor	{

public:
	html_base_component(int t);
	virtual void	ondestroy();
	virtual	int 	onparse( html_ascii_stream * source );
	virtual void	setparent( html_basic_component * member );
	virtual	void 	generate( html_output * target );

	};



#endif	// _html_base_h







