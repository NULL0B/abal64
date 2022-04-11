//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_colour_h 
#define  _html_colour_h 

#define	_HTML_COLOUR_BLACK	0x0000
#define	_HTML_COLOUR_RED	0x0001
#define	_HTML_COLOUR_GREEN	0x0002
#define	_HTML_COLOUR_BROWN	0x0003
#define	_HTML_COLOUR_NAVY	0x0004
#define	_HTML_COLOUR_PURPLE	0x0005
#define	_HTML_COLOUR_CYAN	0x0006
#define	_HTML_COLOUR_SILVER	0x0007
#define	_HTML_COLOUR_GREY	0x0008
#define	_HTML_COLOUR_PINK	0x0009
#define	_HTML_COLOUR_LIME	0x000A
#define	_HTML_COLOUR_YELLOW	0x000B
#define	_HTML_COLOUR_BLUE	0x000C
#define	_HTML_COLOUR_MAGENTA	0x000D
#define	_HTML_COLOUR_SKY	0x000E
#define	_HTML_COLOUR_WHITE	0x000F

#define	_HTML_COLOUR_MAX	0x0010

//	--------------------------------------------------------------------
//			H T M L _ C O L O U R
//	--------------------------------------------------------------------
class	html_colour {

public:
	html_colour(int v=0,int r=0,int g=0,int b=0);
	int	approximation();
	int	rvalue;
	int	gvalue;
	int	bvalue;
	int	value;
	};

#endif // _html_colour_h 
