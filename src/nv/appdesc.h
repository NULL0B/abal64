//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_applet_descriptor_h
#define	_html_applet_descriptor_h


class html_applet_descriptor : 	public html_image_descriptor  {
public:
	html_url_field			*codebase;
	html_string_field		*code;
	html_string_field		*name;

	html_applet_descriptor();
	void		ondestroy();

	};

#endif	// _html_applet_descriptor_h



