//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_frameset_h
#define	_html_frameset_h

#include "complex.h"


class html_frameset_component 	: public html_based_component,
				  public html_frameset_descriptor 	{
public:
	html_frameset_component(int t=_HTML_TAG_FRAMESET);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual html_basic_component* 	getmap(char * nptr);
	virtual	void	 	addmap(html_basic_component * nptr);
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual	html_basic_component * 	addactive( html_active_component * aptr );
	virtual char *		getbase();
	};

#endif	// _html_frameset_h









