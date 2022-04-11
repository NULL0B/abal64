//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_lodriver_h
#define _lodriver_h

#define	_DRIVER_DLL_INITIALISE	0
#define	_DRIVER_DLL_COLOUR 	1
#define	_DRIVER_DLL_CONNECT	2
#define	_DRIVER_DLL_START	3
#define	_DRIVER_DLL_PRINT	4
#define	_DRIVER_DLL_END		5
#define	_DRIVER_DLL_LIBERATE	6
#define	_DRIVER_DLL_MARGINS 	7
#define	_DRIVER_DLL_CONTROL 	8
#define	_DRIVER_DLL_FUNCTION	9

#define	_FORCE_GRAYSCALE	0x4000
#define	_PAPER_TYPE		0x3F00	/* 00 A4, 01 A3, 10 A3 , 11 A1*/
#define	_PIXEL_SIZE		0x0070	/* 01 : 8bit, 10 : 16bit , 11 : 24bit , 100 : 32bit */
#define	_PAGE_QUALITY  		0x0080
#define	_PAGE_ALIGNMENT		0x000B
#define	_PAGE_LANDSCAPE		0x0004
#define	_ALIGN_LEFT		0x0001
#define	_ALIGN_RIGHT		0x0002
#define	_ALIGN_CENTER		0x0003
#define	_ALIGN_NONE 		0x0000
#define	_ALIGN_MARGIN		0x0008

#define	_RED_WEIGHT	54	/* 299 : PS : GIF */
#define	_GREEN_WEIGHT	183	/* 587 : PS : GIF */
#define	_BLUE_WEIGHT	19	/* 114 : PS : GIF */

#define	_PAPER_SHIFT	8
#define	_PIXEL_SHIFT	4

#if defined(WIN32)

#define	_RED_SHIFT8		 0
#define	_RED_SHIFT16	11
#define	_RED_SHIFT32	16

#define	_GREEN_SHIFT8	 2
#define	_GREEN_SHIFT16	 5
#define	_GREEN_SHIFT32	 8

#define	_BLUE_SHIFT8	 6
#define	_BLUE_SHIFT16	 0
#define	_BLUE_SHIFT32	 0

#else

#define	_RED_SHIFT8	 0
#define	_RED_SHIFT16	11
#define	_RED_SHIFT32	 8

#define	_GREEN_SHIFT8	 2
#define	_GREEN_SHIFT16	 5
#define	_GREEN_SHIFT32	16

#define	_BLUE_SHIFT8	 6
#define	_BLUE_SHIFT16	 0
#define	_BLUE_SHIFT32	24

#endif

#define	_RED_MASK8	 0x0007
#define	_RED_MASK16	 0x001F
#define	_RED_MASK32	 0x00FF

#define	_GREEN_MASK8	 0x0003
#define	_GREEN_MASK16	 0x003F
#define	_GREEN_MASK32	 0x00FF

#define	_BLUE_MASK8	 0x0007
#define	_BLUE_MASK16	 0x001F
#define	_BLUE_MASK32	 0x00FF

#define	_PRINT_TEXT	0
#define	_PRINT_LINE	1
#define	_PRINT_CIRCLE	2
#define	_PRINT_IMAGE	3
#define	_PRINT_FILL	4
#define	_PRINT_XFILL	5
#define	_PRINT_ROUNDFILL	6 /*FCH24022006*/
#define	_PRINT_ROUNDFRAME	7 /*FCH24022006*/

#define	_RED_CORRECTION8	 0x0005
#define	_RED_CORRECTION16	 0x0003
#define	_GREEN_CORRECTION8	 0x0006
#define	_GREEN_CORRECTION16	 0x0002
#define	_BLUE_CORRECTION8	 0x0005
#define	_BLUE_CORRECTION16	 0x0003

void	set_colour_options( int options );
int	colour_map_luminence( int v );
int	truecolour_luminence( char * , int offset );
int	luminence( char * bptr, int offset );
int	get_page_control( char ** s, int * l); 
void	extract_colour( int p, int * r, int * g, int * b);

int	redmask=_RED_MASK8;
int	greenmask=_GREEN_MASK8;
int	bluemask=_BLUE_MASK8;

int	colourmapping=1;
int	pixelsize=1;
int	textfiltering=0;

extern	int	PaperWidth;
extern	int	PaperHeight;
extern	int	DotsPerInch;

struct	prn_colour	{
	int	red;
	int	green;
	int	blue;
	int	value;
	};

struct	text_item	{
	struct	text_item * next;
	int	type;
	int	atx;
	int	aty;
	int	w;
	int	h;
	int	font;
	int	bytes;
	struct	prn_colour foreground;
	struct 	prn_colour background;
	int	atribut;
	int	align;
	char *	message;
	struct	standard_image * image;
	};

struct	text_item * get_text_item();


#endif	// _lodriver_h


