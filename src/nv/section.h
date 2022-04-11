//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_section_h
#define	_html_section_h

#include "complex.h"

class html_section_component 	: public html_collection_component {

public:
	html_section_component(int t=_HTML_TAG_ADDRESS);
	virtual int	layout ( html_layout * target );
	};

#endif	// _html_section_h

