//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_pixel_h
#define _html_layout_pixel_h

#include "layinput.h"

class	html_layout_pixel : public html_layout_input {

public:

	html_layout_pixel(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	virtual	void	commit( html_output * target );

	};



#endif	// _html_layout_pixel_h


