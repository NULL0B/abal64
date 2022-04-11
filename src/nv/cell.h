//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cell_h
#define	_html_cell_h

#include "complex.h"
#include "celldesc.h"


class html_cell_component 	: public html_collection_component,
				  public html_cell_descriptor 		{
public:
	html_cell_component(int t=_HTML_TAG_TD);
	virtual	void	ondestroy();
	virtual void	setparent( html_basic_component * member );
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual int	layout ( html_layout * target );
	};

#endif	// _html_cell_h



