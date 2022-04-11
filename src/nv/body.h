//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_body_h
#define	_html_body_h

#include "complex.h"

#include "bodydesc.h"

class html_body_component 	: public html_collection_component,
				  public html_body_descriptor 		{

public:
	html_body_component(int t=_HTML_TAG_BODY);
	virtual	void	ondestroy();
	virtual int onparse( html_ascii_stream * source );
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual void	generate( html_output * target );
	};
#endif	// _html_body_h


