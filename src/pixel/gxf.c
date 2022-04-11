#include <stdio.h>

#ifdef	unix
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#endif

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xmd.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>
#include <X11/Xatom.h>
#ifdef	USING_X_TOOLSKET
#include <X11/Xmu/StdSel.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Toggle.h>
#include <X11/Xaw/Viewport.h>
#endif

#include "stdfmf.h"

Display * 	displayptr=(Display*) 0;
Window		windowptr=0;
char *		displayname=(char *) 0;
int		screen=0;
GC		gcon=(GC)0;
XGCValues	values;
unsigned long	valuemask=0;
int		FontCount=0;
char	**	FontNames=(char **) 0;
XFontStruct 	FontInfo;
Visual	*	vis;
unsigned int	visdepth;
unsigned int	visbpp; 


#define	allocate	malloc
#define	liberate	free

int	verbose=0;
int	lister=0;
int	hexer=0;
int	optimise=0;
int	pointG=0;
char *	stub="font";

#ifndef	public
#define	public
#endif
#ifndef	private
#define	private static
#endif

static unsigned char ansi_iso_character_set[256] = {
   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   10,  11,  12,  13,  14,  15,  16,  17,  18,  19,
   20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
   30,  31,  32,  33,  34,  35,  36,  37,  38,  39,
   40,  41,  42,  43,  44,  45,  46,  47,  48,  49,
   50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
   60,  61,  62,  63,  64,  65,  66,  67,  68,  69,
   70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
   80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
   90,  91,  92,  93,  94,  95,  96,  97,  98,  99,
  100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
  110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
  120, 121, 122, 123, 124, 125, 126, 127, 176, 177,
  178, 180, 181, 182, 183, 184, 185, 186, 187, 188,
  189, 190, 191, 192, 193, 194, 195, 197, 198, 199,
  200, 201, 202, 203, 204, 205, 206, 207, 158, 159,
  208, 173, 155, 156, 254, 157, 179, 210, 209, 211,
  166, 174, 170, 196, 212, 169, 248, 241, 253, 213,
  250, 230, 227, 249, 214, 215, 167, 175, 172, 171,
  216, 168, 'A', 'A', 'A', 'A', 142, 143, 146, 128,
  238, 144, 222, 223, 226, 228, 231, 240, 221, 165,
  234, 236, 242, 243, 153, 239, 232, 247, 251, 252,
  154, 244, 224, 225, 133, 160, 131, 255, 132, 134,
  145, 135, 138, 130, 136, 137, 141, 161, 140, 139,
  235, 164, 149, 162, 147, 233, 148, 246, 237, 151,
  163, 150, 129, 245, 229, 152 
  };


/*	--------------------------------------		*/
/*	a l l o c a t e _ f o n t _ c e l l ()		*/
/*	--------------------------------------		*/

private	struct standard_cell * allocate_font_cell( int width, int height )
{
	struct standard_cell * cptr=(struct standard_cell *) 0;
	if (( width > 0 ) && ( height > 0 )) {
		if (( cptr = allocate( sizeof(struct standard_cell) + ( width*height ) - 1 )) != (struct standard_cell *) 0) {
			cptr->width 	= width;
			cptr->height	= height;
			memset( &cptr->matrix,0,(width*height));
			}
		}
	return( cptr );
}

private	void	fill_font_cell( 
			struct standard_cell * cptr,
			int atx, int aty, int nbx, int nby, int state )
{
	int	x;
	int	y;
	for (	y=0; y < nby; y++ ) {
		if ( y < cptr->height ) {
			for (	x=0; x < nbx; x++ ) {
				if ( x < cptr->width )
					cptr->matrix[((aty+y)*cptr->width)+(atx+x)] = state;
				else	break;
				}
			}
		else	break;
		}
	return;
}

/*	-------------------------------		*/
/*	c o p y  _ f o n t _ c e l l ()		*/
/*	-------------------------------		*/

private	void	copy_font_cell( struct standard_cell * rptr, struct standard_cell * sptr )
{
	int	r;
	int	c;
	for (r=0; r < rptr->height; r++ ) {
		if ( r < sptr->height ) {
			for (c=0; c < rptr->width;  c++ ) {
				if ( c < sptr->width ) 
					rptr->matrix[(r*rptr->width)+c]=sptr->matrix[(r*sptr->width)+c];
				else	break;
				}
			}
		else	break;
		}			
	return;
}

#include "fontrite.c"

static	void	liberate_font(	struct standard_font  *  fptr)
{
	int	i;
	struct standard_cell  * cptr;
	if (!( fptr ))
		return;
	for ( i=0; i < 256; i++ ) {
		if (!( cptr = fptr->cell[i]))
			continue;
		liberate( cptr );
		}
	liberate( fptr );
}

static	struct standard_font  * allocate_font()
{
	int	i;
	struct standard_font  * fptr;
	if (!( fptr = allocate( sizeof( struct standard_font ) ) ))
		return( fptr );
	else	{
		fptr->width=0;	fptr->height=0;			
		fptr->margin=0;	fptr->flags=0;		
		fptr->buffer=(char *) 0;
		fptr->buffersize=0;
		for ( i=0; i < 256; i++ )
			fptr->cell[i] = (struct standard_cell *) 0;
		return( fptr );
		}
}

public	int	font_semi_graphics( struct standard_font * fptr )
{
	int	i;
	int	fw;
	int	fh;
	int	latx;
	int	ratx;
	int	taty;
	int	baty;
	int	rnbx;
	int	lnbx;
	int	bnby;
	int	tnby;
	struct	standard_cell * cptr;
	struct	standard_cell * kptr;

	/* Collect font dimensions and Calculate Semi Graphic Infos */
	/* -------------------------------------------------------- */
	fw  = fptr->width; 			fh = fptr->height;

	latx = (fw/2);	if (!(fw & 1))  { latx--; }	ratx = (latx+2);
	taty = (fh/2);	if (!(fh & 1))  { taty--; } 	baty = (taty+2);

	rnbx = (fw - ratx);		bnby = (fh - baty);
	lnbx = (fw - latx);		tnby = (fh - taty);

	/* from vertical to less than ALPHA */
	/* -------------------------------- */
	for (i=179; i < 224; i++ ) { 


		/* Load or Allocate the Character Cell */
		/* ----------------------------------- */
		while (!( cptr = fptr->cell[i] ))
			if (!( fptr->cell[i] = allocate_font_cell( fw, fh ) ))
				return(27);

		/* Check Cell Dimensions or Re-allocate */
		/* ------------------------------------ */
		if (( cptr->width  < fw )
		||  ( cptr->height < fh )) { 
			if (!( kptr = allocate_font_cell( fw, fh ) ))
				return(27);
			liberate( cptr );
			fptr->cell[i] = kptr;
			cptr = kptr;
			}

		/* Wipe the character cell */
		/* ----------------------- */
		switch ( i ) {
			case	219	: /* full square */
				fill_font_cell(cptr,0,0,fw,fh,1);
				break;

			case	223	: /* top half */
				fill_font_cell(cptr,0,0,fw,baty,1);
				break;

			case	220	: /* bottom half */
				fill_font_cell(cptr,0,baty,fw,bnby,1);
				break;

			case	221	: /* left half */
				fill_font_cell(cptr,0,0,ratx,fh,1);
				break;
			case	222	: /* right half */
				fill_font_cell(cptr,ratx,0,rnbx,fh,1);
				break;
			default		:
				fill_font_cell(cptr,0,0,fw,fh,0);
			}

		/* FULL  VERTICAL   */
		/* ---------------- */
		/* Codes requiring first full vertical bar */
		switch ( i ) {
			case	179 :
			case	180 :
			case	181 :
			case	182 :
			case	185 :
			case	186 :
			case	195 :
			case	197 :
			case	198 :
			case	199 :
			case	204 :
			case	206 :
			case	215 :
			case	216 :
				/* full height first vbar */
				fill_font_cell(cptr, latx,0,1,fh,1);
				break;
			}

		/* Codes requiring second full vertical bar */
		switch ( i ) {
			case	182 :
			case	185 :
			case	186 :
			case	199 :
			case	206 :
			case	215 :
				/* full height second vbar */
				fill_font_cell(cptr, ratx,0,1,fh,1);
				break;

			}

		/* LEFT  HORIZONTAL */
		/* ---------------- */
		/* Codes requiring first  short left horizontal bar */
		switch ( i ) {
			case	180	:
			case	181	:
			case	182	:
			case	184	:
			case	185	:
			case	187	:
			case	190	:
			case	191	:
			case	203	:
			case	206	:
			case	215	:
			case	217	:
				fill_font_cell(cptr, 0,baty,latx+1,1,1);
				break;
			}

		/* Codes requiring first  long left horizontal bar */
		switch ( i ) {
			case	183	:
			case	188	:
			case	189	:
			case	208	:
			case	210	:
				fill_font_cell(cptr, 0,baty,ratx+1,1,1);
			}

		/* Codes requiring second  short left horizontal bar */
		switch ( i ) {
			case 181	:
			case 184	:
			case 185	:
			case 188	:
			case 190	:		
			case 202	:
			case 206	:
				fill_font_cell(cptr, 0,taty,latx+1,1,1);
				break;
			}
		/* Codes requiring second long  left horizontal bar */
		switch ( i ) {
			case	187	:
				fill_font_cell(cptr, 0,taty,ratx+1,1,1);
				break;
			}

		/* RIGHT HORIZONTAL */
		/* ---------------- */
		/* Codes requiring first  short right horizontal bar */
		switch ( i ) {
			case	201	:
			case	203	:
			case	204	:
			case	206	:
				fill_font_cell(cptr,ratx,baty,rnbx,1,1);
			}

		/* Codes requiring first  long  right horizontal bar */
		switch ( i ) {
			case	192	:
			case	195	:
			case	198	:
			case	218	:
			case	200	:
			case	211	:
			case	212	:
			case	213	:
			case	214	:
				fill_font_cell(cptr,latx,baty,lnbx,1,1);
			}

		/* Codes requiring second short right horizontal bar */
		switch ( i ) {
			case	200	:
			case	202	:
			case	204	:
			case	206	:
				fill_font_cell(cptr,ratx,taty,rnbx,1,1);
			}
		/* Codes requiring second long  right horizontal bar */
		switch ( i ) {
			case	198	:
			case	201	:
			case	212	:
			case	213	:
				fill_font_cell(cptr,latx,taty,lnbx,1,1);
			}

		/* FULL  HORIZONTAL */
		/* ---------------- */
		/* Codes requiring first  full horizontal bar */
		switch ( i ) {
			case	193	:
			case	194	:
			case	196	:
			case	197	:
			case	202	:
			case	205	:
			case	207	:
			case	209	:
			case	215	:
			case	216	:
				/* full height first hbar */
				fill_font_cell(cptr, 0,baty,fw,1,1);
				break;
			}

		/* Codes requiring second full horizontal bar */
		switch ( i ) {
			case	203	:
			case	205	:
			case	207	:
			case	209	:
			case	216	:
				/* full height second hbar */
				fill_font_cell(cptr, 0,taty,fw,1,1);
				break;
			}

		/* UPPER VERTICAL */
		/* Codes requiring first long upper vertical */
		switch (i) {
			case	189	:
			case	190	:
			case	192	:
			case	193	:
			case	200	:
			case	208	:
			case	211	:
			case	212	:
			case	217	:
				fill_font_cell(cptr, latx, 0, 1, baty+1, 1 );
			}

		/* Codes requiring first short upper vertical */
		switch (i) {
			case	188	:
			case	202	:
			case	206	:
			case	207	:
				fill_font_cell(cptr, latx, 0, 1, taty+1, 1 );
			}

		/* Codes requiring second long upper vertical */
		switch (i) {
			case	188	:
			case	189	:
			case	208	:
			case	211	:
				fill_font_cell(cptr, ratx, 0, 1, baty+1, 1 );
			}

		/* Codes requiring second short upper vertical */
		switch (i) {
			case	200	:
			case	202	:
			case	204 	:
			case	206	:
				fill_font_cell(cptr, ratx, 0, 1, taty+1, 1 );
			}

		/* Codes requiring first  long  lower vertical */
		switch (i) {
			case	184 	:
			case	201	:
			case	213 :
				fill_font_cell(cptr,latx,taty,1,tnby,1);
			}
		/* Codes requiring first  short lower vertical */
		switch (i) {
			case	183 :
			case	187 :
			case	191 :
			case	194 :
			case	203 :
			case	206 :
			case	209 :
			case	210 :
			case	214 :
			case	218	:
				fill_font_cell(cptr,latx,baty,1,bnby,1);
			}
		/* Codes requiring second long  lower vertical */
		switch (i) {
			case	187 :
				fill_font_cell(cptr,ratx,taty,1,tnby,1);
			}
		/* Codes requiring second short lower vertical */
		switch (i) {
			case	201 :
			case	203 :
			case	183 :
			case	204 :
			case	206 :
			case	210 :
			case	214 :
				fill_font_cell(cptr,ratx,baty,1,bnby,1);
			}

		}
	/* Success */
	/* ------- */
	return(0);
}

static int GetBPPForDepth(int depth)
{
	XPixmapFormatValues *format;
	int nformats;
	int i;
	int bpp;
	format = XListPixmapFormats(displayptr, &nformats);
	for (i = 0; i < nformats; i++)
		if (format[i].depth == depth)
			break;
	if (i == nformats) {	return(0);	}
	bpp = format[i].bits_per_pixel;
	XFree(format);
	if ((bpp != 1) && (bpp != 8) && (bpp != 16) && (bpp != 32))
		return(0);
	else	return( bpp );
}


int	shift_count( unsigned int bitmask )
{
	int result=0;
	while (( (bitmask >> result) << result) == bitmask)
		result++;
	if ( result )
		result--;
	return( result );
}

void	drop_x_fonts()
{
	int	i;
	return;
}

void	terminate()
{
	if ( displayptr )
		XCloseDisplay( displayptr );
	return;
}
		
int	initialise()
{
	int	i;

	if ((!( displayptr )) 
	&&  (!(displayptr = XOpenDisplay(displayname))))
		return(56);

	screen 	= DefaultScreen(displayptr);
	windowptr = XCreateSimpleWindow(
			displayptr, RootWindow(displayptr,screen),
			20,20,100,100,1,
			BlackPixel(displayptr,screen),
			WhitePixel(displayptr,screen)  );
  	gcon = XCreateGC(displayptr,windowptr,valuemask,&values);
	XSetForeground(displayptr,gcon,BlackPixel(displayptr,screen));
	XSetBackground(displayptr,gcon,WhitePixel(displayptr,screen));
	return(0);
}


int	is_white( char * bptr, int c, int bytes )
{
	int	i;
	bptr += (c*bytes);
	for (i=0; i < bytes; i++)
		if ( (*(bptr+i) & 0x00FF) != 0x00FF)
			return(0);
	return(1);
}


struct	standard_cell * extract_image_data( 
			int character, 
			XImage * iptr,
			int width,
			int bytes
			)
{
	struct	standard_cell * cptr=(struct standard_cell *) 0;
	int	l,c,w,h;
	char *	bptr;
	char *	dptr;
	if (!( iptr ))
		return(cptr);
	else if (!( bptr = iptr->data ))
		return(cptr);
	else if (!( w = iptr->bytes_per_line ))
		return(cptr);
	else if (!( h = iptr->height ))
		return(cptr);
	else if (!( cptr = allocate((l= (sizeof( struct standard_cell ) + ( width * h ))))))
		return( cptr );
	else	memset( cptr, 0, l );	
#ifdef	DEBUGGXF
	if ( verbose ) { printf("character : %c (w=%u,h=%u) \r\n",character,width,h); }
#endif
	dptr = &cptr->matrix[0];
	cptr->width = width;
	cptr->height= h;
	for ( l=0; l < h; l++ ) {
#ifdef	DEBUGGXF
		if ( verbose ) { printf("\t"); }
#endif
		for ( c = 0; c < width; c++ ) {
			if ( is_white( bptr, c, bytes ) )
				*(dptr+c) = 0;
			else	*(dptr+c) = 1;
			}
		dptr += width;
		bptr += iptr->bytes_per_line;
#ifdef	DEBUGGXF 
		if ( verbose ) { printf("\r\n"); }
#endif
		}
#ifdef	DEBUGGXF
	if ( verbose ) { printf("\r\n"); }
#endif
	return(cptr);
}
			

struct	standard_font * load_X11_font( char * symbolic )
{

	struct	standard_cell *	cellptr;
	struct	standard_font * fmfptr;
	char 	s[16];
	int	c,cc;
	int	i;
	int	viewsize=0;
	int	width=0;
	int	height=0;
	int	cellwidth;
	int	cellheight;
	XFontStruct * fptr;
	XCharStruct * cptr;
	Pixmap	      p;
	XImage 	    * iptr=(XImage *) 0;

	vis 	= DefaultVisual(displayptr,screen);
	visdepth= DefaultDepth(displayptr,screen);

#ifdef	DEBUGGXF
	if ( verbose ) { printf("font : %u/%u : %s \n",i,FontCount,symbolic); }
#endif
	if (!( visbpp 	= GetBPPForDepth(visdepth) ))
		return((struct standard_font *) 0);

	else if (!( fptr = XLoadQueryFont(displayptr,symbolic) ))
		return((struct standard_font *) 0);

	else if (!(p = XCreatePixmap( 
			displayptr,windowptr,
			/* 200,200, */
			(cellwidth = (fptr->max_bounds.rbearing+1)),(cellheight = fptr->max_bounds.ascent+fptr->max_bounds.descent),
			visdepth))) {
		XFreeFont(displayptr,fptr);
		return((struct standard_font *) 0);
		}

	else  if (!( fptr->per_char ))
		return((struct standard_font *) 0);
	else if (!( fmfptr = allocate_font() )) 
		return((struct standard_font *) 0);

	else	{
		fmfptr->width  = cellwidth;
		fmfptr->height = cellheight;
	  	gcon = XCreateGC(displayptr,windowptr,valuemask,&values);
		XSetForeground(displayptr,gcon,BlackPixel(displayptr,screen));
		XSetBackground(displayptr,gcon,WhitePixel(displayptr,screen));
		XSetFont(displayptr,gcon,fptr->fid);
#ifdef	DEBUGGXF
		if ( verbose ) {
			printf("Pixmap : %u origin at 0,%u : w=%u, h=%u\n",p,fptr->ascent,fptr->max_bounds.rbearing,fptr->max_bounds.ascent+fptr->max_bounds.descent);
			printf("\tmax : w=%d, h=%d ( lb=%d, rb=%d, a=%d,d=%d )\n",
				fptr->max_bounds.width,
				fptr->max_bounds.ascent+fptr->max_bounds.descent,
				fptr->max_bounds.lbearing,
				fptr->max_bounds.rbearing,
				fptr->max_bounds.ascent,fptr->max_bounds.descent);
			}
#endif
		for ( 	cptr=fptr->per_char,c=fptr->min_char_or_byte2;
			c<fptr->max_char_or_byte2;
			c++,cptr++ ) {
			if ( c >= 32 ) {
				s[0] = c; s[1] = 0;
				XSetForeground(displayptr,gcon,WhitePixel(displayptr,screen));
				XFillRectangle(displayptr,p,gcon,0,0,cellwidth,cellheight);
				XSetForeground(displayptr,gcon,BlackPixel(displayptr,screen));
				XDrawImageString(displayptr,p,gcon,0,fptr->ascent,s,1); 
#ifdef	DEBUGGXF
				if ( verbose ) {
					printf("\tchar : %u : w=%d, h=%d ( lb=%d, rb=%d, a=%d,d=%d )\n",
						c,
						cptr->width,
						cptr->ascent+cptr->descent,
						cptr->lbearing,
						cptr->rbearing,
						cptr->ascent,cptr->descent);
					}
#endif
				if (!( cellwidth ))
					break;
				else if ((iptr = XGetImage( displayptr,p,0,0,cellwidth,cellheight,AllPlanes,ZPixmap)) != (XImage*) 0) {
					cellptr = extract_image_data( c, iptr,(cptr->width+1), (iptr->bytes_per_line/cellwidth));
					if ( c < 128 )
						fmfptr->cell[c] = cellptr;
					else if ((cc = ansi_iso_character_set[c]) >= 128)
						fmfptr->cell[cc] = cellptr;
					else if ( cellptr )
						liberate( cellptr );
					XDestroyImage( iptr );
					}
				else	break;
				}
			}

		XFreeGC(displayptr,gcon);
		XFreePixmap(displayptr, p);
		XFreeFont(displayptr,fptr);
		return( fmfptr );
		}
}



int	doit(char * aptr)
{
	int	i;
	char *	symbolic;
	char	newname[256];
	int	fontcounter=0;
	struct	standard_font * fmfptr;
	char **	sptr;

	FontNames = XListFonts(displayptr,aptr,10000,&FontCount);

	for ( sptr=FontNames,i=0; i < FontCount; i++ ) {

		symbolic = *(sptr+i);

		if ( lister ) {
			printf("font : %u/%u : %s \n",i,FontCount,symbolic);
			continue;
			}
		else if (!( fmfptr = load_X11_font( symbolic ) ))
			continue;

		else	{
			if ( pointG )
				font_semi_graphics( fmfptr );
			sprintf(newname,"%s%u.fmf",stub,++fontcounter);						
			if (!(  write_standard_font( newname, fmfptr ) ))
				printf("%s\t:\t%s\r\n",newname,symbolic);
			liberate_font( fmfptr );
			}
		 }

	drop_x_fonts();
	return(0);
}

int	option(char * aptr)
{
	switch ( *aptr ) {
		case	'g'	:
			pointG=1;
			break;
			
		case	'r'	:
			stub = (aptr+1);
			break;
		case	'h'	:
			hexer=1;
			break;
		case	'v'	:
			verbose=1;
			break;
		case	'l'	:
			lister=1;
			break;
		}
	return(0);
}


int	main(int argc, char * argv[] )
{
	int	status;
	int	argi;
	char *	aptr;
	if ( argc == 1 ) {
		printf("\n   X Font Grabber : Version 1.1a.0.01 ");
		printf("\n   Provisoire du 20/02/2004 ");
		printf("\n   Copyright (c) 2004,2006 Amenesik / Sologic \n\n ");
		return(0);
		}

	if ((status = initialise()) != 0)
		return(status);
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
			option((aptr+1));
		else if ((status = doit(aptr)) != 0)
			break;
		}
	terminate();
	return(status);
}










