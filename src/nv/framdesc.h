//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_frame_descriptor_h
#define _html_frame_descriptor_h


class html_frame_descriptor {
public:
	html_url_field		* src;
	html_string_field	* name;
	html_integer_field	* margin;
	html_string_field	* scrolling;
	html_boolean_field	* noresize;
	html_integer_field	* marginwidth;
	html_integer_field	* height;
	html_integer_field	* border;
	html_string_field	* frameborder;
	html_integer_field	* framespacing;
	html_frame_descriptor();
	void		ondestroy();
	};



#endif	// _html_frame_descriptor_h


