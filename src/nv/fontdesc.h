//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_font_descriptor_h
#define _html_font_descriptor_h

class html_font_descriptor {
public:
	html_integer_field	* size;
	html_string_field	* face;
	html_colour_field	* color;
	html_colour_field	* bgcolor;

	static	int	bold_colour;
	static	int	ital_colour;
	static	int	strong_colour;
	static	int	emph_colour;

	html_font_descriptor();
	void		ondestroy();



	};




#endif	// _html_font_descriptor_h


