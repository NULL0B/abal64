//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_style_h
#define	_html_style_h

#include "complex.h"

#include "styldesc.h"

class html_style_component 	: public html_collection_component,
				  public html_style_descriptor		{
	cssi_selector *	iStyle;

public:
	html_style_component(int t=_HTML_TAG_STYLE);
	virtual	void	ondestroy();
	virtual int	layout( html_layout * target );
	virtual int	onparse( html_ascii_stream * source );
	virtual void	generate( html_output * target );
	};

#endif // _html_style_h





