//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_bmp_h
#define _html_layout_bmp_h

#include "layimage.h"

class	html_layout_bmp : public html_layout_image {

	border_descriptor * border;
public:
	html_layout_bmp(html_image_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			int pwidth,
			html_layout_font * fptr,
			border_descriptor * bptr,
			html_layout_item * aptr=0  );

	void		oninit(
		html_image_descriptor * dptr, 
		int atline,
		int oflines,
		int cwidth,
		int pwidth,
		html_layout_font * fptr,
		border_descriptor * bptr,
		html_layout_item * aptr=0 );

	virtual	void	commit( html_output * target );

	};



#endif	// _html_layout_bmp_h



