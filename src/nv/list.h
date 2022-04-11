//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_list_h
#define	_html_list_h

#include "complex.h"

#include "listdesc.h"

class html_list_component 	: public html_collection_component,
				  public html_list_descriptor 		{

	void			calculate_indent();
	html_text_descriptor * 	build_prefix(int thisitem);

public:
	html_list_component(int t=_HTML_TAG_UL);
	virtual	void	ondestroy();
	virtual	void 	prefix(html_layout * target);
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	layout ( html_layout * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual int	addmember( html_basic_component * member );
	int	counter;
	int	item_counter;
	int	indent_width;
	int	listyle;
	};

#endif	// _html_list_h



