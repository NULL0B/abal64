//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_heading_descriptor_h
#define _html_heading_descriptor_h

#include "fonting.h"

class	cssi_selector;

class html_heading_descriptor : public virtual html_element_descriptor	{
public:
	html_colour_field		*bgcolor;
	html_colour_field		*txcolor;
	int				size;
	html_horizontal_alignment * 	align;
	html_font_image		  *	ImageData;
	html_image_descriptor	  *	Image;
	border_descriptor		*Border;
	html_heading_descriptor();
	void	ondestroy();
	void	release_image();
	};

#endif	// _html_heading_descriptor_h







