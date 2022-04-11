//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_style_descriptor_h
#define _html_style_descriptor_h

#include "mime.h"

class	cssi_selector;

class html_style_descriptor {

public:
	html_lowercase_field		*type;
	html_uppercase_field		*media;
	html_style_descriptor();
	void				ondestroy();

	static	int			usestyle;
	static	int			prefered;
	static	char 		*	preference;
	static	void			setpreference( char * stylename );


	};

#endif	// _html_style_descriptor_h


