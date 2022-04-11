//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_attribut_h
#define	_html_attribut_h

#include "complex.h"
#include "divdesc.h"

class html_attribut_component 	: public html_collection_component,
					 html_division_descriptor  {

public:
	html_attribut_component(int t=-1);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int 	layout ( html_layout * target );
	virtual int	ontrace( html_output * target );
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	};

#endif	// _html_attribut_h



