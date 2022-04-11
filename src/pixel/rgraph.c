#ifndef	_r_graph_c
#define	_r_graph_c

#if defined(WIN32)
#include <windows.h>
#include "wincicoapi.h"
#endif

#include <string.h>
#include "xgraph.h"
#include "stdpsu.h"

static	struct x_graph_descriptor xGd;	

int	initialisepixel(int mode)
{
	xGd.biosmode = mode;
	return( x_graph( _XGR_INIPIXEL, & xGd ) );
}

int	activatepixel(int width,int height,int style )
{
	xGd.biosmode = ((width << 16) | height);
	xGd.zone.x = style;
	return( x_graph( _XGR_INIPIXEL, & xGd ) );
}

int	liberatepixel()
{
	return( x_graph( _XGR_LIBPIXEL, & xGd ) );
}

int	get_pixel_size()
{
	return( x_graph( _XGR_PIXELSIZE, & xGd ) );
}

int	get_pixel_format()
{
	return( x_graph( _XGR_PIXELTYPE, & xGd ) );
}

int	set_pixel_size(int v)
{
	xGd.zone.x = v;
	return( x_graph( _XGR_SETPIXELSIZE, & xGd ) );
}

int	set_pixel_format(int v)
{
	xGd.zone.x = v;
	return( x_graph( _XGR_SETPIXELTYPE, & xGd ) );
}

int	put_logical_pixel(char * rptr, int r, int g, int b )
{
	xGd.zone.x = r; xGd.zone.y = g; xGd.zone.w = b;
	xGd.buffer = rptr;
	return( x_graph( _XGR_RGBPIXEL, & xGd ) );
}

int	pixel_to_rgb( int pixel, int *r, int *g, int *b )
{
	xGd.zone.x = pixel;
	xGd.rptr   = r;
	xGd.gptr   = g;
	xGd.bptr   = b;
	return( x_graph( _XGR_DEPIXEL, &xGd ) );

}

int	put_palette_pixel(char * rptr, int v )
{
	xGd.zone.x = v; 
	xGd.buffer = rptr;
	return( x_graph( _XGR_PALPIXEL, & xGd ) );
}

int	get_palette_pixel( int v )
{
	xGd.zone.x = v; 
	return( x_graph( _XGR_GETPALPIXEL, & xGd ) );
}

int	hide()
{
	return( x_graph( _XGR_HIDE, & xGd ) );
}

int	show(int x,int y,int w,int h)
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	return( x_graph( _XGR_SHOW, & xGd ) );
}

int	filzone ( int x, int y, int w, int h, int colour )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.foreground = colour;
	return( x_graph( _XGR_FILZONE, & xGd ) );
}

int	xfilzone ( int x, int y, int w, int h, int colour )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.foreground = colour;
	return( x_graph( _XGR_XFILZONE, & xGd ) );
}

int	shadzone ( int x, int y, int w, int h, int colour )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.foreground = colour;
	return( x_graph( _XGR_SHADZONE, & xGd ) );
}

int	rounded_filzone ( int x, int y, int w, int h, int colour )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.foreground = colour;
	return( x_graph( _XGR_ROUNDFILZONE, & xGd ) );
}

int	rounded_frame ( int x, int y, int w, int h, int colour )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.foreground = colour;
	return( x_graph( _XGR_ROUNDFRAME, & xGd ) );
}

int 	SetCicoPixelColumn( int x )
{
	xGd.zone.x = x;
 	return( x_graph( _XGR_SETCOL, & xGd ) );
}

int 	CicoFontMargin( int x )
{
	xGd.zone.x = x;
 	return( x_graph( _XGR_MARGIN, & xGd ) );
}

int	xorzone ( int x, int y, int w, int h, int colour )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.foreground = colour;
	return( x_graph( _XGR_XORZONE, & xGd ) );
}


int	putzone ( int x, int y, int w, int h, char * buffer )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.buffer = buffer;
	return( x_graph( _XGR_PUTZONE, & xGd ) );
}

int	mixzone ( int x, int y, int w, int h, char * buffer )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.buffer = buffer;
	return( x_graph( _XGR_MIXZONE, & xGd ) );
}

int	putzone8( int x, int y, int w, int h, char * buffer )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.buffer = buffer;
	return( x_graph( _XGR_PUTZONE8, & xGd ) );
}

int	mixzone8 ( int x, int y, int w, int h, char * buffer )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.buffer = buffer;
	return( x_graph( _XGR_MIXZONE8, & xGd ) );
}

int	getzone ( int x, int y, int w, int h, char * buffer )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	xGd.buffer = buffer;
	return( x_graph( _XGR_GETZONE, & xGd ) );
}

int	movezone ( int x, int y, int xx, int yy, int w, int h )
{
	return(56);
}

int	init_mimo()		{ return(0); }
int	fin_mimo()		{ return(0); }
int	activate_mimo()		{ return(x_event(0)); }
int	inhibit_mimo()		{ return(x_event(7)); }
int	get_mimo_type()		{ return(x_event(1)); }
int	get_mimo_par()		{ return(x_event(2)); }
int	get_mimo_lin()		{ return(x_event(3)); }
int	get_mimo_col()		{ return(x_event(4)); }
int	flush_mimo()		{ return(x_event(6)); }
int	get_mimo_row()		{ return(x_event(8)); }
int	get_mimo_column()	{ return(x_event(9)); }
int	get_mimo_mask()		{ return(x_event(5)); }

int	set_mimo_mask(int v)	
{
	xGd.zone.x = v;
 	return( x_graph( _XGR_MOUSEMASK, & xGd ) );
/*
	x_putch(27); x_putch('Z');
	x_putch((v & 0x00FF));
	x_putch(((v >> 8) & 0x00FF));
 */
	return;
}

int	cicoatribut(int v)	
{
	xGd.zone.x = v;
 	return( x_graph( _XGR_ATRIBUT, & xGd ) );
}

int	mimo_kbhit()		{ return(x_event(22)); }
int	mimo_getch()		{ return(x_event(23)); }
int	use_new_mimo()		{ return(0); }

char *	sysfilename(char * nptr)
{ 
	xGd.buffer = nptr; 
	(void) x_graph(_XGR_SYSFILE, &xGd);
	return( xGd.buffer );
}

int	vgapalette(char * bptr, int d, int n )
{
	xGd.value = d; xGd.length = n;
	xGd.buffer = bptr;
	return( x_graph( _XGR_VGAPAL, & xGd ) );
}

int	loadguifont(int id, char * bptr, int blen )
{
	xGd.fontnumber = id;
	xGd.buffer = bptr;
	xGd.length = blen;
	return( x_graph( _XGR_LOADFONT, & xGd ) );
}

int	use_base_font(int id)
{
	xGd.fontnumber = id;
	return( x_graph( _XGR_USEFONT, & xGd ) );
}

int	guifontsize(int id)
{
	xGd.fontnumber = id;
	return( x_graph( _XGR_FONTSIZE, & xGd ) );
}

int	cicocursor(int x, int y )
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	return( x_graph( _XGR_CURSOR, & xGd ) );
}

int	cicocolour(int f, int b )
{
	xGd.foreground = f;
	xGd.background = b;
	return( x_graph( _XGR_COLOUR, & xGd ));
}

int	cicopalette(int c, int v )
{
	xGd.foreground = c;
	xGd.background = v;
	return( x_graph( _XGR_PALET, & xGd ));
}

int	PixelPutC( int v )
{
	xGd.value = v;
	return( x_graph( _XGR_PUTC, & xGd ) );
}

int	PixelFontC(int fid,int v)
{
	xGd.fontnumber = fid;
	xGd.value = v;
	return( x_graph( _XGR_FONTC, & xGd ) );
}

int	PixelPutCat( int x, int y, int v )
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.value  = v;
	return( x_graph( _XGR_PUTCAT, & xGd ) );
}

int	PixelFontCat(int x, int y, int fid,int v)
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.fontnumber = fid;
	xGd.value = v;
	return( x_graph( _XGR_FONTCAT, & xGd ) );
}


/*	STRING VERSIONS		*/

int	PixelPutS( char * sptr)
{
	xGd.buffer = sptr;
	return( x_graph( _XGR_PUTS, & xGd ) );
}

int	PixelFontS(int fid,char * sptr)
{
	xGd.fontnumber = fid;
	xGd.buffer = sptr;
	return( x_graph( _XGR_FONTS, & xGd ) );
}

int	PixelPutSat( int x, int y, char * sptr)
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.buffer = sptr;
	return( x_graph( _XGR_PUTSAT, & xGd ) );
}

int	PixelFontSat(int x, int y, int fid, char * sptr )
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.fontnumber = fid;
	xGd.buffer = sptr;
	return( x_graph( _XGR_FONTSAT, & xGd ) );
}

/*	STRING+LENGTH VERSIONS		*/

int	PixelPutL( char * sptr, int slen)
{
	xGd.buffer = sptr; xGd.length = slen;
	return( x_graph( _XGR_PUTL, & xGd ) );
}

int	PixelFontL(int fid,char * sptr, int slen )
{
	xGd.fontnumber = fid;
	xGd.buffer = sptr; xGd.length = slen;
	return( x_graph( _XGR_FONTL, & xGd ) );
}

int	textsizelen(int fid,char * sptr, int slen )
{
	xGd.fontnumber = fid;
	xGd.buffer = sptr; xGd.length = slen;
	return( x_graph( _XGR_TEXTSIZE, & xGd ) );
}

int	textsize(int fid,char * sptr )
{
	return( textsizelen( fid, sptr, strlen( sptr) ) );
}

int	PixelPutLat( int x, int y, char * sptr, int slen)
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.buffer = sptr; xGd.length = slen;
	return( x_graph( _XGR_PUTLAT, & xGd ) );
}

int	PixelFontLat(int x, int y, int fid, char * sptr, int slen )
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.fontnumber = fid;
	xGd.buffer = sptr; xGd.length = slen;
	return( x_graph( _XGR_FONTLAT, & xGd ) );
}

STDPSUPTR	liberate_pixel_storage( STDPSUPTR bptr )
{
	xGd.buffer=(char *) bptr;
	(void) x_graph( _XGR_LIBERPSU, & xGd );
	return( xGd.buffer );
}

void 	capture_pixel_storage( STDPSUPTR bptr )
{
	xGd.buffer=(char *) bptr;
	(void) x_graph( _XGR_CAPTURE, & xGd );
	return;
}

void 	refresh_pixel_storage( STDPSUPTR bptr )
{
	xGd.buffer=(char *) bptr;
	(void) x_graph( _XGR_REFRESH, & xGd );
	return;
}

STDPSUPTR	allocate_graphic_storage( WORD x, WORD y, WORD w, WORD h )
{
	xGd.zone.x = x; xGd.zone.y = y;
	xGd.zone.w = w; xGd.zone.h = h;
	(void) x_graph( _XGR_ALLOCPSU, & xGd );
	return( xGd.buffer );
}

BPTR	connect_pixel_row(STDPSUPTR xptr, WORD  r)
{
	xGd.buffer = xptr; xGd.value = r;
	(void) x_graph( _XGR_CONNECT, & xGd );
	return( xGd.buffer );
}

WORD	collect_pixel_row(STDPSUPTR xptr,WORD atcol ,WORD atrow, WORD nbcol, BPTR rptr )
{
	char * sptr;
	if (!( nbcol )) return(0);
	xGd.buffer = xptr; 
	xGd.value = atrow;
	(void) x_graph( _XGR_CONNECT, & xGd );
	if ((sptr = xGd.buffer) != (char *) 0) 
		memcpy(rptr,sptr,(nbcol*xptr->descriptor[6]));
	return(0);
}

void 	background_pixel_capture(STDPSUPTR bptr )
{
	xGd.buffer=(char *) bptr;
	(void) x_graph( _XGR_SOFTWARE, & xGd );
	return;
}

void 	foreground_pixel_capture(STDPSUPTR bptr )
{
	xGd.buffer=(char *) bptr;
	(void) x_graph( _XGR_SHAREWARE, & xGd );
	return;
}

void 	cancel_pixel_capture( STDPSUPTR bptr )
{
	xGd.buffer=(char *) bptr;
	(void) x_graph( _XGR_HARDWARE, & xGd );
	return;
}

void 	move_pixel_capture( STDPSUPTR bptr, int x, int y )
{
	xGd.buffer=(char *) bptr;
	xGd.zone.x = x;
	xGd.zone.y = y;
	(void) x_graph( _XGR_MOVEWARE, & xGd );
	return;
}

void	cicowindow( int x,int y,int w,int h )
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.zone.w = w;
	xGd.zone.h = h;
	(void) x_graph( _XGR_VIEWPORT, & xGd );
	return;
}

int	windowtitle( char * sptr )
{
	xGd.buffer=(char *) sptr;
	(void) x_graph( _XGR_WMNAME, & xGd );
	return(0);
}

int	windowicon( char * sptr )
{
	xGd.buffer=(char *) sptr;
	(void) x_graph( _XGR_WMICON, & xGd );
	return(0);
}

int	publish_selection(char * mptr, int mlen)
{
	xGd.buffer = (char *) mptr;
	xGd.length = mlen;
	return( x_graph( _XGR_PUBLISH, & xGd ) );
}


int	paste_selection(char * mptr, int mlen)
{
	xGd.buffer = (char *) mptr;
	xGd.length = mlen;
	return( x_graph( _XGR_PASTE, & xGd ) );
}


int	standard_load_font( char * fontname )
{
	xGd.buffer = (char *) fontname;
	return( x_graph( _XGR_FONTLOAD, & xGd ) );
}

int	standard_drop_font( int fontid )
{
	xGd.length = fontid;
	return( x_graph( _XGR_FONTDROP, & xGd ) );
}


int	set_letter_spacing( int fontid )
{
	xGd.length = fontid;
	return( x_graph( _XGR_FONTSPACE, & xGd ) );
}

int	set_line_spacing( int fontid )
{
	xGd.length = fontid;
	return( x_graph( _XGR_LINESPACE, & xGd ) );
}

int	set_shadow_colour(int v)
{
	xGd.length = v;
	return( x_graph( _XGR_SHADOWFG, & xGd ) );
}

int	set_shadow_width(int v)
{
	xGd.length = v;
	return( x_graph( _XGR_SHADOWX, & xGd ) );
}

int	set_shadow_height(int v)
{
	xGd.length = v;
	return( x_graph( _XGR_SHADOWY, & xGd ) );
}

char *	standard_font_name( int number )
{
	xGd.length = number;
	xGd.buffer = (char *) 0;
	x_graph( _XGR_FONTNAME, & xGd );
	return( xGd.buffer );
}


char *	get_vga_palette()
{
	x_graph( _XGR_COLOURMAP, & xGd );
	return( xGd.buffer );
}

int	get_xgr_scale()
{
	x_graph(_XGR_GETSCALE, & xGd );
	return( xGd.zone.x );
}

int	set_xgr_scale(int v)
{
	xGd.zone.x = v;
	x_graph(_XGR_SETSCALE, & xGd );
	return( 0 );
}

/*	----------------------------------------------------------------- */
/*	il y a une draw line dans vline qui effectue le travail reel !!!! */
/*	----------------------------------------------------------------- */
int visual_line(int fx,int fy,int tx,int ty,int thick ,int pixel)
{
	xGd.zone.x = fx;
	xGd.zone.y = fy;
	xGd.zone.w = tx;
	xGd.zone.h = ty;
	xGd.foreground = pixel;
	xGd.length = thick;
	x_graph(_XGR_LINE, & xGd );
	return(0);
}

int drawcircle(int fx,int fy,int tx,int ty, int colour, int type)
{
	xGd.zone.x = fx;
	xGd.zone.y = fy;
	xGd.zone.w = tx;
	xGd.zone.h = ty;
	xGd.foreground = colour;
	xGd.length = type;
	x_graph(_XGR_CIRCLE, & xGd );
	return(0);
}

int	drawimage(int x, int y, int w , int h, void * vptr, int o )
{
	xGd.zone.x = x;
	xGd.zone.y = y;
	xGd.zone.w = w;
	xGd.zone.h = h;
	xGd.buffer = vptr;
	xGd.length = o;
	x_graph(_XGR_IMAGE, & xGd );
	return(0);
}

int	textalign(int x, int y, int w , int h, int f, char * mptr, int mlen, int a)
{
	xGd.zone.x 	= x;
	xGd.zone.y 	= y;
	xGd.zone.w 	= w;
	xGd.zone.h 	= h;
	xGd.buffer 	= mptr;
	xGd.length 	= mlen;
	xGd.fontnumber 	= f;
	xGd.value  	= a;
	x_graph(_XGR_ALIGN, & xGd );
	return(0);
}

int	get_logical_pixel( char * vptr, int * rptr, int * gptr, int * bptr )
{
	xGd.buffer = vptr;
	xGd.rptr   = rptr;
	xGd.gptr   = gptr;
	xGd.bptr   = bptr;
	return( x_graph( _XGR_GETRGB, &xGd ) );
}

int	make_rgb_pixel( int r, int g, int b )
{
	xGd.zone.x = r;
	xGd.zone.y = g;
	xGd.zone.w = b;
	return( x_graph( _XGR_NEWRGB, &xGd ) );
}

unsigned long get_rgb_pixel( int r, int g ,int b )
{
	xGd.zone.x = r;
	xGd.zone.y = g;
	xGd.zone.w = b;
	(void) x_graph( _XGR_BUILDRGB, &xGd );
	return( xGd.pixel );
}

char *	guifontinfo( int number )
{
	xGd.length = number;
	x_graph( _XGR_FONTINFO, &xGd );
	return(  xGd.buffer );
}

char *	guifontname( int number )
{
	xGd.length = number;
	x_graph( _XGR_FONTNAME, &xGd );
	return(  xGd.buffer );
}

int	gethqfont(void)
{
		x_graph( _XGR_GETHQFONT, &xGd );
		return( xGd.value);
}

int	sethqfont(int v)
{
		xGd.value = v;
		return( x_graph( _XGR_SETHQFONT, &xGd ));
}

#endif	/* _r_graph_c */


