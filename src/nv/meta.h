//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_meta_h
#define _html_meta_h

#include "basic.h"

class	html_meta_component : 	public html_basic_component ,
				public	html_meta_descriptor	{

public:
	html_meta_component(int t);
	virtual void	ondestroy();
	virtual	int 	onparse( html_ascii_stream * source );
	virtual void	setparent( html_basic_component * member );
	virtual int	layout ( html_layout * target );
	virtual	void 	generate( html_output * target );
private:
	char *	refresh;
	};



#endif	// _html_meta_h







