//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cell_descriptor_h
#define	_html_cell_descriptor_h


#include "backgr.h"
class html_cell_descriptor :  	
	public 	html_background_descriptor,
	public virtual html_element_descriptor {
public:
	html_boolean_field		*nowrap;
	html_integer_field		*rowspan;
	html_integer_field		*colspan;
	html_horizontal_alignment	*align;
	html_vertical_alignment		*valign;
	html_percent_field		*width;
	html_integer_field		*height;
	html_dimensions			*contents;
	html_colour_field		*bgcolor;
	html_colour_field		*txcolor;
	border_descriptor		*Border;
	html_cell_descriptor();
	void				ondestroy();
	void				release_dimensions();
	int				iscaption;
	};

#endif	// _html_cell_descriptor_h



