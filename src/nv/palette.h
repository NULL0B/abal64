//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_palette_h
#define _html_palette_h

#include "vga.h"

class	html_logical_palette : public html_vga {

	int	users;

public:

	html_logical_palette();
	~html_logical_palette();
	int	activate();
	int	establish();
	int	connect();
	int	disconnect();

	char buffer[256*4];

	};

#endif	// _html_palette_h


