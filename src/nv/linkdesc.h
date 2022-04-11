//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_link_descriptor_h
#define _html_link_descriptor_h

class	html_link_descriptor {
public:
	html_url_field		* href;
	html_string_field	* hreflang;
	html_string_field	* charset;

	html_lowercase_field	* type;
	html_uppercase_field	* rel;
	html_uppercase_field	* rev;
	html_uppercase_field	* media;
	html_uppercase_field	* target;

	html_link_descriptor();
	void	ondestroy();
	};


#endif	// _html_link_descriptor_h







