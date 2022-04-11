//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_colour_h
#define	_html_layout_colour_h

#include "layitem.h"

class	html_layout_colour : public html_layout_item {

public:
	html_layout_colour(html_layout_font * fptr);

	virtual	void	commit(html_output * target);

	};


#endif	// _html_layout_colour_h




