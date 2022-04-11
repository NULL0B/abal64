//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_table_h
#define	_html_table_h

#include "complex.h"
#include "tabldesc.h"

class	html_table_output;

class html_table_component 	: public html_collection_component,
				  public html_table_descriptor 		{
public:
	html_table_component(int t=_HTML_TAG_TABLE);
	virtual	void	ondestroy();
	virtual void	adjust(int nature, long number);
	virtual int 	onparse( html_ascii_stream * source );
	virtual int	layout ( html_layout * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual void 	generate( html_output * target );
	virtual int	addmember( html_basic_component * member );
	virtual void	setparent( html_basic_component * member );

	html_output		* catcher;

	};


#endif	// _html_table_h




