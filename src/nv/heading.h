//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_heading_h
#define	_html_heading_h

#include "text.h"

#include "headdesc.h"

class html_heading_component 	: public html_collection_component,
				  public html_heading_descriptor 	{
public:
	html_heading_component(int t=_HTML_TAG_H1);
	virtual	void	ondestroy();
	virtual int	onparse( html_ascii_stream * source );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual void 	generate( html_output * target );
	virtual int	closemember(int c, int n);
	virtual int	layout ( html_layout * target );

	};


#endif	// _html_heading_h



