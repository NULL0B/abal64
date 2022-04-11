//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_bmp_h
#define _html_bmp_h

#define	BMP_SIGNATURE "BM"

#include "vga.h"

class	html_bmp : html_vga {
	html_binary_stream * fstream;
public:
		html_bmp( html_binary_stream * source );
	html_logical_image * parse(html_logical_image * iptr=0);
	char   		getbyte();
	long 	int 	getlong();
	short 	int 	getword();
	 	int 	getpixel();
		int	pixelid;
		int	pixelbyte;
	long	int	bytecounter;
 	long 	int 	FileSize;
 	short 	int 	Resolution1;
 	short 	int 	Resolution2;
 	long 	int 	PixelOffset;
 	long 	int	HeaderSize;
 	long 	int	Columns;
 	long 	int	Rows;
 	short	int	Planes;
 	short 	int	BitsPerPixel;
 	long 	int	Compression;
 	long 	int	CompSize;
 	long 	int 	Xscale;
 	long 	int 	Yscale;
 	long 	int 	ColourCount;
 	long 	int 	ImportantColourCount;
	short	int	PixelsPerByte;
	char		Palette[256][4];
	char		Colours[256];
	long	int	ByteControl;
		int	garbage;
	};

#endif	// _html_bmp_h


