//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_frameset_descriptor_h
#define _html_frameset_descriptor_h

class html_frameset_descriptor	{
public:
	html_string_field	* rows;
	html_string_field	* cols;
	html_integer_field	* border;
	html_string_field	* frameborder;
	html_integer_field	* framespacing;
	html_integer_field	* noresize;
	html_frameset_descriptor();
	void		ondestroy();

	};

#endif	// _html_frameset_descriptor_h



