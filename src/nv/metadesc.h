//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_meta_descriptor_h
#define _html_meta_descriptor_h

class	html_meta_descriptor {
public:
	html_string_field	* name;
	html_string_field	* content;
	html_string_field	* httpequiv;
	html_string_field	* scheme;
	html_meta_descriptor();
	void	ondestroy();
	};


#endif	// _html_meta_descriptor_h






