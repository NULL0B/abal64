//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_head_h
#define	_html_head_h

#include "complex.h"

class html_head_descriptor	{

public:
	standard_url * 	base;
	int		isindex;

	};

class html_head_component 	: public html_collection_component,
				  public html_head_descriptor 		{
public:
	html_head_component(int t=_HTML_TAG_HEAD);
	virtual int	layout( html_layout * target );
	};


#endif	// _html_head_h


