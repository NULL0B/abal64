//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_param_h
#define	_html_param_h

#include "basic.h"

class html_parameter_descriptor {
public:
	html_string_field	*	name;
	html_string_field	*	value;

	html_parameter_descriptor();
	void	ondestroy();


	};


class html_parameter_component 	: public html_basic_component,
				  public html_parameter_descriptor 	{
public:
	html_parameter_component(int t=_HTML_TAG_PARAM);
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual	void	ondestroy();
	virtual void	setparent( html_basic_component * member );
	};

#endif // _html_param_h


