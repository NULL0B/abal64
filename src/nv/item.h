//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_item_h
#define	_html_item_h

#include "complex.h"

class html_item_descriptor {
public:
	html_uppercase_field	*type;
	html_integer_field	*value;
	html_item_descriptor();
	void		ondestroy();
	};

class html_item_component 	: public html_collection_component,
				  public html_item_descriptor 		{
public:
	html_item_component(int t=_HTML_TAG_LI);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void	setparent( html_basic_component * member );
	virtual int	layout ( html_layout * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	};

#endif	// _html_item_h

