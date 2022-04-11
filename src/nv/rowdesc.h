//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_row_descriptor_h
#define	_html_row_descriptor_h

#include "backgr.h"
class html_row_descriptor	:  
	public 	html_background_descriptor,
	public  virtual html_element_descriptor {
public:
	html_horizontal_alignment 	*align;
	html_vertical_alignment 	*valign;
	html_colour_field		*bgcolor;
	html_colour_field		*txcolor;

	html_dimensions			*contents;

	int				cellcounter;
	int				maxcounter;
	int				*cellwidths;
	int				*cellcolours;
	int				*cellborders;
	long				*cellimages;
	border_descriptor		*Border;
	int				iscaption;

	html_row_descriptor();
	void		ondestroy();
	void		release_dimensions();

	};

#endif	// _html_row_descriptor_h









