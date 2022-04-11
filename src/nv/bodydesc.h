//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_body_descriptor_h
#define _html_body_descriptor_h

#include "logimage.h"
#include "border.h"
#include "backgr.h"

class html_body_descriptor : 	
	public 	html_background_descriptor,
	public  virtual html_element_descriptor {
public:
	html_colour_field	*text;
	html_colour_field	*link;
	html_colour_field	*bgcolor;
	html_colour_field	*vlink;
	html_colour_field	*alink;
	html_date_field		*datestamp;
	html_horizontal_alignment	*align;

	static	int	text_colour;
	static	int	wash_colour;
	static	int	link_colour;
	static	int	done_colour;
	static	int	actv_colour;
	static	int	body_colour;
	border_descriptor *Border;

	html_body_descriptor();
	void		ondestroy();
	};

#endif	// _html_body_descriptor_h



