//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_title_h
#define	_html_title_h

#include "text.h"

class html_title_component 	: public html_text_component {

public:
	html_title_component(int t=_HTML_TAG_TITLE );
	virtual int addtext( int c );
	virtual int layout ( html_layout * target );
	virtual int ontrace( html_output * target );
	virtual int closemember(int c, int n);

private:
	int	title_closed;

	};


#endif	// _html_title_h


