//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_column_h
#define _html_column_h

#include "complex.h"

class	html_column_descriptor {

public:
	html_integer_field	* span;
	html_string_field	* width;

	html_column_descriptor();
	void	ondestroy();
	void	generate( html_output * target );

	};

class	html_column_component : public html_basic_component,
				public html_column_descriptor {

public:
	html_column_component(int t=_HTML_TAG_COL);
	virtual void	ondestroy();
	virtual int	layout( html_layout * target );
	virtual int	onparse( html_ascii_stream * source );
	virtual void	generate( html_output * target );

	};

class	html_colgroup_component : public html_collection_component,
				  public html_column_descriptor 	{

public:
	html_colgroup_component(int t=_HTML_TAG_COLGROUP);
	virtual void	ondestroy();
	virtual int	layout( html_layout * target );
	virtual int	onparse( html_ascii_stream * source );
	virtual void	generate( html_output * target );
	virtual	int	addmember( html_basic_component * member );

	};



#endif	// _html_column_h




