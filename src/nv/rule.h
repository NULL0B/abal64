//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_rule_h
#define	_html_rule_h

#include "basic.h"

class html_rule_component 	: public html_basic_component, 
				  public html_rule_descriptor 		{

public:
	html_rule_component(int t=_HTML_TAG_HR);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual int	layout ( html_layout * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	};

#endif // _html_rule_h

