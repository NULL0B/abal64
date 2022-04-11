//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_division_h
#define	_html_division_h

#include "complex.h"

#include "divdesc.h"

class html_division_component 	: public html_collection_component,
				  public html_division_descriptor 	{
public:
	html_division_component(int t=_HTML_TAG_DIV);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	};

#endif	// _html_division_h


