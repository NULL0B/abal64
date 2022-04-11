//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_table_descriptor_h
#define	_html_table_descriptor_h

#include "backgr.h"
class html_table_descriptor	:  
		public html_background_descriptor,
		public virtual html_element_descriptor  {
public:
	char *				caption;
	html_horizontal_alignment	*align;
	html_percent_field		*width;
	html_integer_field		*border;
	html_integer_field		*cellspacing;
	html_integer_field		*cellpadding;
	html_colour_field		*bgcolor;
	int				cellborder;
	int				rowcounter;
	int				cellcounter;
	int				cellwidth;
	int				cellrowcounter;
	int				cellwidths[64];
	html_dimensions			*contents;
	border_descriptor		*Border;
	html_table_descriptor();
	void		ondestroy();
	void		release_dimensions();
	};


#endif	// _html_table_descriptor_h




