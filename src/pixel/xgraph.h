#ifndef	_x_graph_h
#define	_x_graph_h

struct	x_graph_descriptor {
	struct x_graph_zone {
		int	x;
		int	y;
		int	w;
		int	h;
		} zone;
	int	foreground;
	int	background;
	int	fontnumber;
	int	biosmode;
	void *	buffer;
	void *	rptr;
	void *	gptr;
	void *	bptr;
	int	length;
	int	value;
	unsigned long pixel;
	};

#define	_XGR_INIPIXEL	0x0001
#define	_XGR_LIBPIXEL	0x0002
#define	_XGR_FILZONE 	0x0003
#define	_XGR_PUTZONE 	0x0004
#define	_XGR_MIXZONE 	0x0005
#define	_XGR_XORZONE 	0x0006
#define	_XGR_GETZONE 	0x0007
#define	_XGR_MOVZONE 	0x0008
#define	_XGR_HIDE	0x0009
#define	_XGR_SHOW	0x000A
#define	_XGR_XFILZONE 	0x000B
#define	_XGR_ROUNDFILZONE 	0x000C
#define	_XGR_ROUNDFRAME 	0x000D
#define	_XGR_SHADZONE 	0x000E

#define	_XGR_PUTC	0x0020
#define	_XGR_FONTC	0x0021
#define	_XGR_PUTCAT	0x0022
#define	_XGR_FONTCAT	0x0023

#define	_XGR_PUTS	0x0024
#define	_XGR_FONTS	0x0025
#define	_XGR_PUTSAT	0x0026
#define	_XGR_FONTSAT	0x0027

#define	_XGR_PUTL	0x0028
#define	_XGR_FONTL	0x0029
#define	_XGR_PUTLAT	0x002A
#define	_XGR_FONTLAT	0x002B

#define	_XGR_SETCOL	0x002C
#define	_XGR_MARGIN	0x002D
#define	_XGR_TEXTSIZE	0x002E
#define	_XGR_VIEWPORT	0x002F
#define	_XGR_ATRIBUT	0x0030
#define	_XGR_MOUSEMASK	0x0031

#define	_XGR_SETSCALE	0x0032
#define	_XGR_GETSCALE	0x0033
#define	_XGR_ALIGN		0x0034
#define _XGR_GETHQFONT	0x0035
#define _XGR_SETHQFONT	0x0036

#define	_XGR_LOADFONT	0x0040
#define	_XGR_FONTSIZE	0x0041
#define	_XGR_USEFONT  	0x0042
#define	_XGR_VGAPAL	0x0043
#define	_XGR_LOADPAL	0x0044

#define	_XGR_COLOUR  	0x0060	/* set cico colours fg,bg 	*/
#define	_XGR_PALET   	0x0061	/* set colour switch f->g	*/
#define	_XGR_CURSOR  	0x0062	/* position text cursor c,l 	*/

#define	_XGR_SHADOWX	0x0063
#define	_XGR_SHADOWY	0x0064
#define	_XGR_SHADOWFG	0x0065

#define	_XGR_SYSFILE	0x0080	
#define	_XGR_PUTZONE8 	0x0084
#define	_XGR_MIXZONE8 	0x0085

#define	_XGR_ALLOCPSU	0x00A0
#define	_XGR_LIBERPSU	0x00A1
#define	_XGR_CONNECT	0x00A2
#define	_XGR_CAPTURE	0x00A3
#define	_XGR_REFRESH	0x00A4

#define	_XGR_SOFTWARE	0x00A5
#define	_XGR_HARDWARE	0x00A6
#define	_XGR_SHAREWARE	0x00A7
#define	_XGR_MOVEWARE	0x00A8

#define	_XGR_WMNAME	0x00B0
#define	_XGR_WMICON	0x00B1

#define	_XGR_PUBLISH	0x00B2
#define _XGR_PASTE      0x00B3

#define	_XGR_FONTLOAD	0x00C0
#define	_XGR_FONTDROP	0x00C1
#define	_XGR_FONTSPACE	0x00C2
#define	_XGR_LINESPACE	0x00C3
#define	_XGR_FONTNAME	0x00C4
#define	_XGR_COLOURMAP	0x00C5
#define	_XGR_FONTINFO	0x00C6

#define	_XGR_PIXELTYPE		0x00D0
#define	_XGR_PIXELSIZE		0x00D1
#define	_XGR_RGBPIXEL		0x00D2
#define	_XGR_PALPIXEL		0x00D3
#define	_XGR_GETRGB		0x00D4
#define	_XGR_SETPIXELTYPE	0x00D5
#define	_XGR_SETPIXELSIZE	0x00D6
#define	_XGR_BUILDRGB		0x00D7
#define	_XGR_NEWRGB		0x00D8
#define	_XGR_DEPIXEL		0x00D9
#define	_XGR_GETPALPIXEL	0x00DA

#define	_XGR_LINE	0x00E0
#define	_XGR_CIRCLE	0x00E1
#define	_XGR_IMAGE	0x00E2

int	x_graph( int, struct x_graph_descriptor * );

#endif /* _x_graph_h */






