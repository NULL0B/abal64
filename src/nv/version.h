//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_version_component_h
#define _html_version_component_h

#include "complex.h"

class	html_version_descriptor	{

public:
	html_string_field	* cite;
	html_date_field		* datetime;

	html_version_descriptor();
	void		ondestroy();

	};

class	html_version_component	:
	public	html_collection_component,
	public	html_version_descriptor	{

public:
	html_version_component(int t);
	virtual	void	ondestroy();
	virtual	int onparse( html_ascii_stream * source );
	virtual	void generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual void	setparent( html_basic_component * member );

	};


#endif	// _html_version_component_h


