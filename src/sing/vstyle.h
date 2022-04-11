#ifndef	_vstyle_h
#define	_vstyle_h

struct	style_zone	{
	int	x;
	int	y;
	int	w;
	int	h;
	};

#ifndef	_singdbed_h

#define	_style_expected_dash		30
#define	_style_expected_colon		31
#define	_style_expected_semicolon	32
#define	_style_expected_token		33
#define	_style_incorrect_keyword	34
#define	_style_expected_url		35
#define	_style_expected_left_brace	36
#define	_style_expected_right_brace	37
#define _style_undefined_class		38
#define	_style_expected_comma		39
#define	_file_not_found			40
#define	_style_expected_value		41
#define	_exceeding_style_limit		103
#define	_allocation_failure		27
#define	_end_of_style			48

struct	style_definition	{
	struct	style_definition * next;
	char 			 * name;
	char 			 * value;
	int			   hash;
	};

struct	element_dimension	{
	int	type;		/* type of the quantity 	*/		
	int	value;		/* value of the quantity 	*/
#ifdef	ABAL32A
	int	state;		/* set or default		*/
	char 	token[32];	/* original source 		*/
#endif
	};

#ifdef	ABAL32A
struct	element_class		{
	struct	element_style	*	style;
	struct	element_class	*	next;
	struct	element_class	*	previous;
	};

struct	element_file		{
	char *	name;
	int	hash;
	struct	element_class *	first;
	struct	element_class *	last;
	struct	element_file * 	next;
	struct	element_file * 	previous;
	};
#endif

struct	element_position	{
	int	type;
	int	option;
	struct	element_dimension top;
	struct	element_dimension right;
	struct	element_dimension bottom;
	struct	element_dimension left;
	};

struct	element_sizes 	{
	struct	element_dimension top;
	struct	element_dimension right;
	struct	element_dimension bottom;
	struct	element_dimension left;
	};

struct	element_frame 	{
	int	top;
	char *	topimage;
	int	topright;
	char *	toprightimage;
	int	right;
	char *	rightimage;
	int	bottomright;
	char *	bottomrightimage;
	int	bottom;
	char *	bottomimage;
	int	bottomleft;
	char *	bottomleftimage;
	int	left;
	char *	leftimage;
	int	topleft;
	char *	topleftimage;
	};

struct	element_colour	{
#ifdef	ABAL32A
	int	type;
#endif
	int	red;
	int	green;
	int	blue;
	int	entry;
	};

struct	element_style	{

	char			*	name;
	int				hash;
	struct	element_style	*	next;
	struct	element_style	*	previous;

#ifdef	ABAL32A
	char			*	alias;
	char			*	basename;
	struct	element_file 	*	owner;
	char			*	filename;
	char			*	fileline;
	char			*	fontname;
	int				derivations;
	int				applied;
#endif

	/*	Element Rendering Sizes		*/
	/* 	-----------------------		*/
	struct	element_sizes		marginsize;
	struct	element_sizes		bordersize;
	struct	element_frame 		bordertype;
	struct	element_sizes		paddingsize;

	struct	element_dimension	cellwidth;
	struct	element_dimension	cellheight;
	struct	element_dimension	textindent;

	struct	element_dimension	wordspacing;
	struct	element_dimension	linespacing;
	struct	element_dimension	letterspacing;

	struct	element_position	cellposition;
	struct	element_colour		backgroundcolour;
	struct	element_colour		bordercolour;
	struct	element_colour		textcolour;

	struct	element_colour		margincolour;
	char			*	marginimage;
	int				marginalign;
	int				marginrepeat;

	struct	element_dimension	shadowwidth;
	struct	element_dimension	shadowheight;
	struct	element_colour		shadowcolour;

	int				borderalign;
	int				rounding;

	char			*	backgroundimage;
	int				backgroundalign;
	int				backgroundrepeat;
	int				backgroundattach;

	int				verticalalign;
	int				textalign;
	int				textatribut;
	int				textfont;
	int				nature;
	int				item;
	};


static	char *	_style_keyword[] = {
	(char *)	"margin",
	(char *)	"border",
	(char *)	"padding",
	(char *)	"text",
	(char *)	"background",
	(char *)	"colour",
	(char *)	"align",
	(char *)	"repeat",
	(char *)	"attach",
	(char *)	"font",
	(char *)	"width",
	(char *)	"height",
	(char *)	"top",
	(char *)	"right",
	(char *)	"bottom",
	(char *)	"left",
	(char *)	"center",
	(char *)	"justify",
	(char *)	"none",
	(char *)	"outset",
	(char *)	"inset",
	(char *)	"ridge",
	(char *)	"groove",
	(char *)	"convex",
	(char *)	"concave",
	(char *)	"solid",
	(char *)	"double",
	(char *)	"dashed",
	(char *)	"dotted",
	(char *)	"fixed",
	(char *)	"scroll",
	(char *)	"x",
	(char *)	"y",
	(char *)	"both",
	(char *)	"auto",
	(char *)	"px",
	(char *)	"tx",
	(char *)	"perc",
	(char *)	"mm",
	(char *)	"url",
	(char *)	"style",
	(char *)	"class",
	(char *)	"image",
	(char *)	"black",
	(char *)	"navy",
	(char *)	"green",
	(char *)	"cyan",
	(char *)	"red",
	(char *)	"magenta",
	(char *)	"brown",
	(char *)	"grey",
	(char *)	"silver",
	(char *)	"blue",
	(char *)	"lime",
	(char *)	"sky",
	(char *)	"pink",
	(char *)	"purple",
	(char *)	"yellow",
	(char *)	"white",
	(char *)	"rgb",
	(char *)	"makefit",
	(char *)	"bestfit",
	(char *)	"bold",
	(char *)	"underline",
	(char *)	"shadow",
	(char *)	"position",
	(char *)	"home",
	(char *)	"line",
	(char *)	"transparent",
	(char *)	"edit",
	(char *)	"disk",
	(char *)	"rounded",
	(char *)	"tile",
	(char *)	"small",
	(char *)	"decoration",
	(char *)	"color",
	(char *)	"word",
	(char *)	"letter",
	(char *)	"spacing",
	(char *)	"normal",
	(char *)	"vertical",
	(char *)	"baseline",
	(char *)	"sub",
	(char *)	"super",
	(char *)	"middle",
	(char *)	"overline",
	(char *)	"blink",
	(char *)	"through",
	(char *)	"content",
	(char *)	"float",
	(char *)	"indent",
	(char *)	"static",
	(char *)	"relative",
	(char *)	"absolute",
	(char *)	"important",
	(char *)	"trigger",
	(char *)	"corner",
	(char *)	"ihm", 
	(char *)	"cell",
	(char *)	"up",
	(char *)	"down",
	(char *)	"grip",
	(char *)	"hole",
	(char *)	"shade",
	(char *)	"fill",
	(char *)	"vconvex",
	(char *)	"hconvex",
	(char *)	"vconcave",
	(char *)	"hconcave",
	(char *)	"alias",
	(char *)	"file",
	(char *) 	"cover"
 	};

#define _keyword_margin		0x000
#define _keyword_border		0x001
#define _keyword_padding	0x002
#define _keyword_text		0x003
#define _keyword_background	0x004
#define _keyword_colour		0x005
#define _keyword_align		0x006
#define _keyword_repeat		0x007
#define _keyword_attach		0x008
#define _keyword_font		0x009
#define _keyword_width		0x00a
#define _keyword_height		0x00b
#define _keyword_top		0x00c
#define _keyword_right		0x00d
#define _keyword_bottom		0x00e
#define _keyword_left		0x00f
#define _keyword_center		0x0010
#define _keyword_justify	0x0011
#define _keyword_none		0x0012
#define _keyword_outset		0x0013
#define _keyword_inset		0x0014
#define _keyword_ridge		0x0015
#define _keyword_groove		0x0016
#define _keyword_convex		0x0017
#define _keyword_concave	0x0018
#define _keyword_solid		0x0019
#define _keyword_double		0x001a
#define _keyword_dashed		0x001b
#define _keyword_dotted		0x001c
#define _keyword_fixed		0x001d
#define _keyword_scroll		0x001e
#define _keyword_x		0x001f
#define _keyword_y		0x0020
#define _keyword_both		0x0021
#define _keyword_auto		0x0022
#define _keyword_px		0x0023
#define _keyword_tx		0x0024
#define _keyword_perc		0x0025
#define _keyword_mm		0x0026
#define _keyword_url		0x0027
#define _keyword_style		0x0028
#define _keyword_class		0x0029
#define _keyword_image		0x002a
#define _keyword_black		0x002b
#define _keyword_navy		0x002c
#define _keyword_green		0x002d
#define _keyword_cyan		0x002e
#define _keyword_red		0x002f
#define _keyword_magenta	0x0030
#define _keyword_brown		0x0031
#define _keyword_grey		0x0032
#define _keyword_silver		0x0033
#define _keyword_blue		0x0034
#define _keyword_lime		0x0035
#define _keyword_sky		0x0036
#define _keyword_pink		0x0037
#define _keyword_purple		0x0038
#define _keyword_yellow		0x0039
#define _keyword_white		0x003a
#define _keyword_rgb		0x003b
#define _keyword_makefit	0x003c
#define _keyword_bestfit	0x003d
#define _keyword_bold		0x003e
#define _keyword_underline	0x003f
#define _keyword_shadow		0x0040
#define _keyword_position	0x0041
#define _keyword_home		0x0042
#define _keyword_line		0x0043
#define _keyword_transparent	0x0044
#define _keyword_edit		0x0045
#define _keyword_disk		0x0046
#define _keyword_rounded	0x0047
#define _keyword_tile		0x0048
#define _keyword_small		0x0049
#define _keyword_decoration	0x004a
#define _keyword_color		0x004b
#define _keyword_word		0x004c
#define _keyword_letter		0x004d
#define _keyword_spacing	0x004e
#define _keyword_normal		0x004f
#define _keyword_vertical	0x0050
#define _keyword_baseline	0x0051
#define _keyword_sub		0x0052
#define _keyword_super		0x0053
#define _keyword_middle		0x0054
#define _keyword_overline	0x0055
#define _keyword_blink		0x0056
#define _keyword_through	0x0057
#define _keyword_content	0x0058
#define _keyword_float		0x0059
#define _keyword_indent		0x005A
#define	_keyword_static		0x005B
#define	_keyword_relative	0x005C
#define	_keyword_absolute	0x005D
#define	_keyword_important	0x005E
#define	_keyword_trigger  	0x005F
#define	_keyword_corner   	0x0060
#define	_keyword_ihm 	  	0x0061
#define	_keyword_cell 	  	0x0062
#define	_keyword_up 	  	0x0063
#define	_keyword_down 	  	0x0064
#define	_keyword_grip 	  	0x0065
#define	_keyword_hole 	  	0x0066
#define	_keyword_shade 	  	0x0067
#define	_keyword_fill 	  	0x0068
#define _keyword_vconvex	0x0069
#define _keyword_hconvex	0x006A
#define _keyword_vconcave	0x006B
#define _keyword_hconcave	0x006C
#define _keyword_alias		0x006D
#define _keyword_file		0x006E
#define _keyword_cover		0x006F
#define	_max_style_keywords	0x0070

#define	_MAX_STYLE		52

#define	_BORDER_NONE		0
#define	_BORDER_OUTSET		1
#define	_BORDER_INSET		2
#define	_BORDER_RIDGE		3
#define	_BORDER_GROOVE		4
#define	_BORDER_SOLID		5
#define	_BORDER_DASH 		6
#define	_BORDER_DOT  		7

#define	_STYLE_DPI	90		/* dots per inch (pixels per inch in fact)	*/
#define	_STYLE_MMPI	25.4		/* mm per   inch				*/
#define	_STYLE_PTPI	72		/* points per inch				*/
#define	_STYLE_PTPP	12		/* points per pica				*/
#define	_STYLE_PCPI	6		/* picas  per inch	 			*/

#define	_IN_DIMENSION	'in'
#define	_MM_DIMENSION	'mm'
#define	_CM_DIMENSION	'cm'
#define	_PT_DIMENSION	'pt'
#define	_PC_DIMENSION	'pc'
#define	_EM_DIMENSION	'em'

#define	_AUTO_DIMENSION		0
#define	_PIXEL_DIMENSION	1
#define	_TEXT_DIMENSION		2
#define	_PERCENT_DIMENSION	3
#define	_ELEMENT_DIMENSION	4
#define	_CELL_DIMENSION		5
#define	_PROP_DIMENSION		7
#define	_PLUS_DIMENSION		8
#define	_FIXED_DIMENSION	9

#define	_ALIGN_NONE		0
#define	_ALIGN_RIGHT		1
#define	_ALIGN_LEFT		2
#define	_ALIGN_CENTER		3
#define	_ALIGN_JUSTIFY		4
#define	_ALIGN_STRETCH		5
#define	_ALIGN_ADJUST 		6
#define	_ALIGN_SPRITE 		0x0400


#define	_REPEAT_NONE		0
#define	_REPEAT_X		1
#define	_REPEAT_Y		2
#define	_REPEAT_BOTH		3

#define	_ATTACH_FIXED		0
#define	_ATTACH_SCROLL		1

#define	_TEXT_BOLD		0x0100
#define	_TEXT_UNDERLINE		0x0200
#define	_TEXT_SHADOW		0x0400
#define	_TEXT_OVERLINE		0x0800
#define	_TEXT_STRIKE	 	0x1000
#define	_TEXT_BLINK 		0x2000


#define	visual_window_frame	0x0000
#define	visual_button_frame	0x0001
#define	visual_page_frame	0x0002
#define	visual_check_frame	0x0003
#define	visual_radio_frame	0x0004
#define	visual_switch_frame	0x0005
#define	visual_select_frame	0x0006
#define	visual_outset_frame	0x0007
#define	visual_inset_frame	0x0008
#define	visual_groove_frame	0x0009
#define	visual_ridge_frame	0x000A
#define	visual_edit_frame	0x000B
#define	visual_form_frame	0x000C
#define	visual_image_frame	0x000D
#define	visual_vscroll_frame	0x000F
#define	visual_hscroll_frame	0x0010
#define	visual_table_frame	0x0011
#define	visual_progress_frame	0x0012
#define	max_default_style	0x0013
#define	visual_select_frameup		0x0014
#define	visual_select_framedown		0x0015
#define	visual_select_framebtn		0x0016
#define	visual_select_framescroll	0x0017

#ifndef WIN32
#ifndef	public
#define	public
#endif
#ifndef	private
#define	private	static
#endif
#endif

public 	int	use_default_style(int);
public 	void	detect_default_style();

#endif	/* _vstyle_c */
	/* --------- */

#endif	/* _vstyle_h */
	/* --------- */


