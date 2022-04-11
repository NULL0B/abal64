
//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_border_h
#define _html_border_h

class	border_descriptor {
public:	int	style[4];
	int	colour[4];
	int	width[4];
	int	margin[4];
	int	space[4];
	border_descriptor();
	int	control();
	};

#endif	// _html_border_h


