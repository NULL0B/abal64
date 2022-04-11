//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cssi_h
#define _html_cssi_h

#include "string.h"
#include "vga.h"
#include "border.h"
// Forward references to classes

class	html_colour_field;
class	html_horizontal_alignment;
class	html_vertical_alignment;
class	html_percent_field;
class	html_integer_field; 

#define	_CSS1_FONT		0x0000
#define	_CSS1_COLOR		0x0001
#define	_CSS1_BACKGROUND	0x0002
#define	_CSS1_WORD		0x0003
#define	_CSS1_LETTER		0x0004
#define	_CSS1_TEXT		0x0005	
#define	_CSS1_VERTICAL		0x0006
#define	_CSS1_LINE		0x0007
#define	_CSS1_MARGIN		0x0008
#define	_CSS1_PADDING		0x0009
#define	_CSS1_BORDER		0x000A
#define	_CSS1_WIDTH		0x000B
#define	_CSS1_HEIGHT		0x000C
#define	_CSS1_FLOAT		0x000D
#define	_CSS1_CLEAR		0x000E
#define	_CSS1_DISPLAY		0x000F
#define	_CSS1_WHITE		0x0010
#define	_CSS1_LIST		0x0011

#define	_CSS1_FAMILY		0x0012
#define	_CSS1_SERIF		0x0013
#define	_CSS1_SANS		0x0014
#define	_CSS1_OURSIVE		0x0015
#define	_CSS1_FANTASY		0x0016
#define	_CSS1_MONOSPACE		0x0017
#define	_CSS1_STYLE		0x0018
#define	_CSS1_NORMAL		0x0019
#define	_CSS1_ITALIC		0x001A
#define	_CSS1_OBLIQUE		0x001B
#define	_CSS1_VARIANT		0x001C
#define	_CSS1_SMALL		0x001D
#define	_CSS1_CAPS		0x001E
#define	_CSS1_WEIGHT		0x001F
#define	_CSS1_BOLD		0x0020
#define	_CSS1_BOLDER		0x0021
#define	_CSS1_LIGHTER		0x0022
#define	_CSS1_SIZE		0x0023
#define	_CSS1_LARGER		0x0024
#define	_CSS1_SMALLER		0x0025
#define	_CSS1_RGB		0x0026
#define	_CSS1_TRANSPARENT	0x0027
#define	_CSS1_IMAGE		0x0028
#define	_CSS1_URL		0x0029
#define	_CSS1_NONE		0x002A
#define	_CSS1_REPEAT		0x002B
#define	_CSS1_X			0x002C
#define	_CSS1_Y			0x002D
#define	_CSS1_NO		0x002E
#define	_CSS1_ATTACHMENT	0x002F
#define	_CSS1_SCROLL		0x0030
#define	_CSS1_FIXED		0x0031
#define	_CSS1_POSITION		0x0032
#define	_CSS1_TOP		0x0033
#define	_CSS1_CENTER		0x0034
#define	_CSS1_BOTTOM		0x0035
#define	_CSS1_LEFT		0x0036
#define	_CSS1_RIGHT		0x0037
#define	_CSS1_SPACING		0x0038
#define	_CSS1_DECORATION	0x0039
#define	_CSS1_UNDERLINE		0x003A
#define	_CSS1_OVERLINE		0x003B
#define	_CSS1_THROUGH		0x003C
#define	_CSS1_BLINK		0x003D
#define	_CSS1_ALIGN		0x003E
#define	_CSS1_BASELINE		0x003F
#define	_CSS1_SUB		0x0040
#define	_CSS1_SUPER		0x0041
#define	_CSS1_MIDDLE		0x0042
#define	_CSS1_TRANSFORM		0x0043
#define	_CSS1_CAPITALIZE	0x0044
#define	_CSS1_UPPERCASE		0x0045
#define	_CSS1_LOWERCASE		0x0046
#define	_CSS1_JUSTIFY		0x0047
#define	_CSS1_INDENT		0x0048
#define	_CSS1_AUTO		0x0049
#define	_CSS1_SPACE		0x004A
#define	_CSS1_TYPE		0x004B
#define	_CSS1_MEDIUM		0x004C
#define	_CSS1_XX		0x004D
#define	_CSS1_LARGE		0x004E
#define	_CSS1_INLINE		0x004F
#define	_CSS1_BLOCK		0x0050
#define	_CSS1_ITEM 		0x0051
#define	_CSS1_PRE  		0x0052
#define	_CSS1_NOWRAP		0x0053

#define	_CSS1_DISC		0x0054
#define	_CSS1_CIRCLE		0x0055
#define	_CSS1_SQUARE		0x0056
#define	_CSS1_DECIMAL		0x0057
#define	_CSS1_UPPER		0x0058
#define	_CSS1_LOWER		0x0059
#define	_CSS1_ALPHA		0x005A
#define	_CSS1_ROMAN		0x005B
#define	_CSS1_THIN 		0x005C
#define	_CSS1_THICK		0x005D

#define	_CSS1_DOTTED		0x005E
#define	_CSS1_DASHED		0x005F
#define	_CSS1_SOLID		0x0060
#define	_CSS1_DOUBLE		0x0061
#define	_CSS1_GROOVE		0x0062
#define	_CSS1_RIDGE		0x0063
#define	_CSS1_INSET		0x0064
#define	_CSS1_OUTSET		0x0065

#define	_CSS1_BOTH 		0x0066

#define	_CSS1_INSIDE		0x0067
#define	_CSS1_OUTSIDE		0x0068

#define	_CSS1_MAX		0x0069

	// Length Item sign value [.value] units
	// EM Element Font Height
	// EX Element X Width
	// PX Pixel Value
	// IN Inches == 2.54 CM
	// CM = 10 MM
	// MM
	// PC = 12 PT
	// PT = 1/72 IN
	// PERCENTAGE 

#define	_CSSI_FONT_FAMILY		1
#define	_CSSI_FONT_STYLE		2
#define	_CSSI_FONT_VARIANT		3
#define	_CSSI_FONT_WEIGHT		4
#define	_CSSI_FONT_SIZE			5

#define	_CSSI_COLOR			10
#define	_CSSI_BACKGROUND_COLOR		11
#define	_CSSI_BACKGROUND_IMAGE		12
#define	_CSSI_BACKGROUND_REPEAT		13
#define	_CSSI_BACKGROUND_ATTACH		14
#define	_CSSI_BACKGROUND_POSITION	15

#define	_CSSI_WORD_SPACING		20
#define	_CSSI_LETTER_SPACING		21
#define	_CSSI_TEXT_DECORATION		22
#define	_CSSI_VERTICAL_ALIGN		23
#define	_CSSI_TEXT_TRANSFORM		24
#define	_CSSI_TEXT_ALIGN		25
#define	_CSSI_TEXT_INDENT		26
#define	_CSSI_LINE_HEIGHT		27

#define	_CSSI_MARGIN_TOP		30
#define	_CSSI_MARGIN_RIGHT		31
#define	_CSSI_MARGIN_BOTTOM		32
#define	_CSSI_MARGIN_LEFT		33
#define	_CSSI_PADDING_TOP		40
#define	_CSSI_PADDING_RIGHT		41
#define	_CSSI_PADDING_BOTTOM		42
#define	_CSSI_PADDING_LEFT		43
#define	_CSSI_BORDER_TOP_WIDTH		50
#define	_CSSI_BORDER_RIGHT_WIDTH	51
#define	_CSSI_BORDER_BOTTOM_WIDTH	52
#define	_CSSI_BORDER_LEFT_WIDTH		53
#define	_CSSI_BORDER_TOP_COLOR		60
#define	_CSSI_BORDER_RIGHT_COLOR	61
#define	_CSSI_BORDER_BOTTOM_COLOR	62
#define	_CSSI_BORDER_LEFT_COLOR		63
#define	_CSSI_BORDER_TOP_STYLE		70
#define	_CSSI_BORDER_RIGHT_STYLE	71
#define	_CSSI_BORDER_BOTTOM_STYLE	72
#define	_CSSI_BORDER_LEFT_STYLE		73

#define	_CSSI_HEIGHT			80
#define	_CSSI_WIDTH			81
#define	_CSSI_FLOAT			82
#define	_CSSI_CLEAR			83
#define	_CSSI_DISPLAY			84
#define	_CSSI_WHITE_SPACE		85

#define	_CSSI_LIST_TYPE			90
#define	_CSSI_LIST_IMAGE		91
#define	_CSSI_LIST_POSITION		92

class	html_css1;



//	-------------------------------------------------------------
//	CSSI PROPERTY HEIRARCHY DIAGRAM
//	-------------------------------------------------------------
//
//		PROPERTY
//		   |
//		*--*-------*-------*
//		|	   |	   |
//	     ATRIBUT	COLOUR	STRING
//				   |
//				*--*----*
//			        |	|
//			       URL    LENGTH	
//
//	-------------------------------------------------------------

class	cssi_property	{
	static char * SingleFormatString;
	static char * DoubleFormatString;
	static char * TripleFormatString;

public:	int	identity;
	int	value;
	cssi_property * next;
	cssi_property(int t=-1,int v=-1);
	~cssi_property();
	virtual	void	ondestroy();
	virtual	int	integervalue();
	virtual	char *	stringvalue();
#ifdef	_DEBUG_CSSI
	virtual	void	display();
#endif
	};

class	cssi_colour_property : public cssi_property	{
	int	rvalue;
	int	gvalue;
	int	bvalue;
public:	cssi_colour_property(int t=-1, int r=0, int g=0, int b=0);
	cssi_colour_property(int t=-1,long v=0L);
	virtual	int	integervalue();
#ifdef	_DEBUG_CSSI
	virtual	void	display();
#endif

	};

class	cssi_string_property : public cssi_property, html_string {

	char	* value;

public:	cssi_string_property(int t=-1,char * v=(char *) 0);
	virtual	void	ondestroy();
	virtual	char *	stringvalue();
#ifdef	_DEBUG_CSSI
	virtual	void	display();
#endif
	};

class	cssi_length_property : public cssi_string_property	{
	char	* units;
public:	cssi_length_property(int t=-1,char * v=(char *) 0);

	};

class	cssi_url_property : public cssi_string_property	{

public:	cssi_url_property( int t=-1, char * uptr=(char *) 0 );
#ifdef	_DEBUG_CSSI
	virtual	void	display();
#endif

	};


class	cssi_property_list {

public:
	cssi_property_list();
	~cssi_property_list();

	void	addproperty( cssi_property * pptr );

	cssi_property * first;
	cssi_property * last;

#ifdef	_DEBUG_CSSI
	void	display(int mode);
#endif
	};


class	cssi_selector {

public:	cssi_selector(char * nptr=(char *) 0);
	~cssi_selector();

	void	addtag	( cssi_property * pptr );
	void	addproperty( cssi_property * pptr );
	cssi_property	   * locate( int item );
	cssi_selector	   * resolve( char * token, char * klass );

#ifdef	_DEBUG_CSSI
	void	display();
#endif
	cssi_property_list * tags;
	cssi_property_list * properties;
	cssi_selector	   * next;
	int		     users;

	static cssi_selector * destroy( cssi_selector * sptr );

	int 	useborder( border_descriptor * bptr );
	int 	usecolours(html_colour_field * text=0,html_colour_field * bgcolor=0);
	int 	usealign(html_horizontal_alignment* align=0,html_vertical_alignment * valign=0 );
	int 	usesizes(html_percent_field * width=0,html_integer_field * height=0 );

	};

class	style_node	{

public:
	char		* url;
	style_node 	* previous;
	style_node 	* next;
	cssi_selector	* contents;

	style_node(cssi_selector * sptr, char * nptr=(char *) 0);
	~style_node();

	};


class	html_style_manager	{

	style_node	*	firststyle;
	style_node	*	laststyle;

public:	html_style_manager();
	virtual		void	addstyle( cssi_selector * sptr, char * uptr=(char  *) 0 );
			void	ondestroy();
	cssi_selector	*	reuse_style( char * uptr );
	cssi_selector	* 	resolve( char * token, char * klass, char * ytem );
	html_style_manager	*	previous;

	};
	
#endif	// _html_cssi_h




