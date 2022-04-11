//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_background_descriptor_h
#define _html_background_descriptor_h

class	cssi_selector;
class	html_basic_component;
class	html_background_descriptor {

public:
	html_background_descriptor();
	void	ondestroy();
	void	onlayout(html_basic_component * parent);
	void	usestyle( cssi_selector * sptr );
	html_url_field		*background;
	html_logical_image	*ImageData;
	static	char *	backgroundimage;
	static	void	setbackground( char * sptr );
	};

#endif	// _html_background_descriptor_h


