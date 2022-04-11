//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_script_descriptor_h
#define _html_script_descriptor_h

class	html_script_descriptor	{
public:
	html_url_field		* src;
	html_string_field	* type;
	html_string_field	* srclang;	// Depreciated 42
	html_boolean_field	* defer;
	html_script_descriptor();
	void	ondestroy();

	static	char * default_script;

	};




#endif	// _html_script_descriptor_h



