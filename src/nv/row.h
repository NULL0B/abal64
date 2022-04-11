//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_row_h
#define	_html_row_h

#include "complex.h"

#include "rowdesc.h"

class html_row_component 	: public html_collection_component,
				  public html_row_descriptor 		{
public:
	html_row_component(int t=_HTML_TAG_TR);
	virtual	void	ondestroy();
	virtual void	setparent( html_basic_component * member );
	virtual	void 	prefix(html_output * target);
	virtual void	adjust(int nature, long number);
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual int	layout ( html_layout * target );
	};

#endif	// _html_row_h




