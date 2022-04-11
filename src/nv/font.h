//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_font_h
#define	_html_font_h

#include "complex.h"
#include "fontdesc.h"

class html_font_component 	: public html_collection_component,
				  public html_font_descriptor 		{
public:
	html_font_component(int t=_HTML_TAG_FONT);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual int	addtext(int c);

private:
	int	macroflag;
	};

#endif	// _html_font_h

