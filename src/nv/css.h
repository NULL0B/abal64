//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_css_h
#define _html_css_h

#define _CSS_COLOR		0x0000
#define _CSS_BACKGROUND		0x0001
#define _CSS_BACKGROUND_COLOR	0x0002
#define _CSS_HEIGHT		0x0003
#define _CSS_WIDTH		0x0004
#define _CSS_FONT_WEIGHT	0x0005
#define _CSS_FONT_STYLE		0x0006
#define _CSS_FONT_SIZE		0x0007
#define _CSS_FONT_FAMILY	0x0008
#define _CSS_MARGIN		0x0009
#define _CSS_MARGIN_TOP		0x000A
#define _CSS_MARGIN_LEFT	0x000B
#define _CSS_MARGIN_RIGHT	0x000C
#define _CSS_MARGIN_BOTTOM	0x000D
#define _CSS_LIST_STYLE_TYPE	0x000E
#define _CSS_EFT		0x000F
#define _CSS_PADDING		0x0010
#define _CSS_BORDER		0x0011
#define _CSS_ALIGN		0x0012
#define _CSS_TEXT_TRANSFORM	0x0013
#define _CSS_TEXT_DECORATION	0x0014
#define _CSS_TEXT_ALIGN		0x0015
#define _CSS_VERTICAL_ALIGN	0x0016

#include "filter.h"

class	css_parser : public ascii_stream_parser {


	int	getkeyword();
	void	members( html_style_node * sptr );

public:
	css_parser(html_ascii_stream * source);
	css_parser(html_text_descriptor * source);

	html_style_node * operation();
	
	};


#endif	// _html_css_h


