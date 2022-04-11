//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_gif_h
#define _html_gif_h

#define	GIF_SIGNATURE "GIF"

#define	GIF_MAX_LZW	12
#define	GIF_MAX_BITS	4097

#define	GIF_TERMINATOR  ';'
#define	GIF_EXTENSION   '!'
#define	GIF_START_IMAGE ','

#include "vga.h"

class	html_gif : html_vga  {

	html_binary_stream * fstream;
	char		   * gifname;

	int	getbyte();
	long 	getlong();
	int 	getword();
	int 	getversion();
	int 	getextension();
	int	nextrow(html_logical_image * iptr);
	char * 	getcolourmap(int colours);
	void	usecolourmap(char * bmptr, int nombre );

	int   	getlzw(html_logical_image * iptr,int counter);
	void	razlzw();

//	GIF DECODER MACHINE VARIABLES
//	-----------------------------
	int   * prefix;
	unsigned char  * suffix;
	unsigned char  * stack;
	
	int	stackp;
	char *	rowpointer;
	int	pixel;
	int	maxpixel;

	unsigned char	queue[256];

	int	bytecounter;
	int	thisrow;
	int	datasize;
	int	clearcode;
	int	available;
	char	firstchar;
	int	oldcode;
	int	codesize;
	int	codemask;
	unsigned long	datum;
	int	bits;
	int	transparence;
	int	istransparent;

public:
	html_gif( html_binary_stream * source );
	~html_gif();
	html_logical_image * parse(html_logical_image * iptr=0);

	int	Version;

 	int	Columns;
 	int	Rows;
	int	GlobalMapOption;

	int	BackGround;

	int	GlobalMapSize;
	char *	GlobalMap;
	int	Colours;
	int	FloatAspect;
	int	RecordType;

	int	Interlaced;
	int	PassCount;

	char	palette[256];


	};

#endif	// _html_gif_h



