//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_allocation_h
#define _html_layout_allocation_h

class html_layout_font;
class html_layout_body;
class html_layout_link;
class html_layout_byte;
class html_layout_bytes;
class html_layout_zone;
class html_layout_text;
class html_layout_line;
class html_layout_image;
class html_layout_bmp;
class html_layout_button;
class html_layout_check;
class html_layout_pixel;
class html_layout_edit;
class html_layout_select;
class html_layout_textarea;

class html_layout_table;

class	html_layout_allocation {
		
public:
	static html_layout_font		* font_heap;
	static html_layout_body		* body_heap;
	static html_layout_link		* link_heap;
	static html_layout_byte		* byte_heap;
	static html_layout_bytes	* bytes_heap;
	static html_layout_text		* text_heap;
	static html_layout_zone		* zone_heap;
	static html_layout_line		* line_heap;

	static html_layout_image	* image_heap;
	static html_layout_bmp		* bmp_heap;
	static html_layout_button	* button_heap;
	static html_layout_check	* check_heap;
	static html_layout_pixel	* pixel_heap;
	static html_layout_edit		* edit_heap;
	static html_layout_select	* select_heap;
	static html_layout_textarea	* textarea_heap;
	static html_layout_table	* table_heap;

	};

#endif	// _html_layout_allocation_h



