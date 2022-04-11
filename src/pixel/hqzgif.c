//	------------------------------------------------------------------
//	Project		Staff Screamer : Graphical Screener Library Z.XP
//	------------------------------------------------------------------

#ifndef	_screener_gif_c
#define _screener_gif_c

#include <stdio.h>

#if defined(WIN32)
#include "bda.h"
#ifndef	BPTR
#define	BPTR PIXIBYTE FAR PTR
#endif
#ifndef	WPTR
#define	WPTR WORD FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif
#include "stdimage.h"
#include "rgraphapi.h"
#endif

#include "zalloc.h"
#include "vimage.h"

#define	gif_consume_block		1
#define	gif_skip_block			2
#define	gif_comment_extension		3
#define	gif_consume_comment		4
#define	gif_control_extension		5
#define	gif_application_extension	6
#define	TrueShade(a) (palette[(a)])
#define	GreyShade(a) (((a) & 0x000F) | 0x0010)


#define	GIF_SIGNATURE "GIF"

#define	GIF_MAX_LZW	12
#define	GIF_MAX_BITS	4097

#define	GIF_TERMINATOR  ';'
#define	GIF_EXTENSION   '!'
#define	GIF_START_IMAGE ','

int	vga_approximation(int  r, int  g, int  b );

extern	int	force_host_style;
extern	int	inhibit_transparence;
static	FILE	* fstream=(FILE *) 0;
static		char	* gifname;
static		int   	* prefix;
static		unsigned char  * suffix;
static		unsigned char  * stack;
static		short int	stackp;
static		short int	pixel;
static		short int	maxpixel;
static		unsigned char	queue[256];
static		short int	bytecounter;
static		short int	thisrow;
static		short int	datasize;
static		short int	clearcode;
static		short int	available;
static		char	firstchar;
static		short int	 oldcode;
static		short int	codesize;
static		short int	codemask;
static		char *	rowpointer;
static		unsigned long	datum;
static		short int	bits;
static		short int	transparence;
static		short int	istransparent;
static		short int	Version;
static		short int	Columns;
static		short int	Rows;
static		short int	GlobalMapOption;
static		short int	BackGround;
static		short int	GlobalMapSize;
static		char * GlobalMap;
static		char * VgaMap;
static		short int	Colours;
static		short int	FloatAspect;
static		short int	RecordType;
static		short int	Interlaced;
static		short int	PassCount;
static		char	palette[256];
static		char *	hiqpalette;
static		int	hiq=0;
static		int	pixelsize=1;
static		int	colourmaped=1;

char *	getcolourmap( short int );
static unsigned short int	getbyte();
static unsigned short int	getword();
static long	getlong();
static void	razlzw();
int	getlzw(struct standard_image * iptr, int counter);
int	getversion();

void	terminate_gif()
{
	if ( prefix ) {
		liberate((char *) prefix );
		prefix = (unsigned int  *) 0;
		}
	if ( suffix ) {
		liberate((char *) suffix );
		suffix = (unsigned char *) 0;
		}
	if ( stack ) {
		liberate((char *)  stack );
		stack  = (unsigned char *) 0;
		}
	if ( GlobalMap ) {
		liberate((char *) GlobalMap );
		GlobalMap  = (char *) 0;
		}
	VgaMap = (char *) 0;

	if ( fstream != (FILE *) 0 ) {
		fclose( fstream );
		fstream = (FILE *) 0;
		}
	return;
}

int 	initialise_gif( char * filename )
{
	short int	i;

	if ((fstream = fopen( sysfilename(filename), "rb")) == (FILE *) 0) 
		return(40);

	RecordType = GIF_TERMINATOR;

	// Reset Internal Image Palette
	for ( i=0; i < 256; i++ )
		palette[i] = (char)i;

	prefix = (int  *) 0;
	suffix = (unsigned char *) 0;
	stack  = (unsigned char *) 0;
	transparence  = 0;
	istransparent = 0;
	pixelsize   = get_pixel_size();
	colourmaped = get_pixel_format();

	if ((Version = getversion()) != 0) {

		Columns 		= getword();
		Rows    		= getword();

		GlobalMapOption 	= getbyte();
		GlobalMapSize   	= (2 << (GlobalMapOption & 0x0007));
		Colours           = -GlobalMapSize;
		BackGround	= getbyte();
		FloatAspect	= getbyte();
		
		if ( GlobalMapOption & 0x0080 ) {
			/* Global Map */
			GlobalMap = getcolourmap( GlobalMapSize );
			}

		RecordType = getbyte();
		bytecounter=0;

		return(0);

		}
	else	return(56);

}

void	usecolourmap( char * bptr, short int nombre )
{
	short int	i,r,g,b;
	
	if (!( inhibit_transparence )) {
		if (( nombre >= 32 )
		&&  ( *(bptr+(16*3)) == 1)
		&&  ( *(bptr+(16*3)+1) == 1)
		&&  ( *(bptr+(16*3)+2) == 1)
		&&  ( (*(bptr+(24*3)+0) & 0x00FF) == 0x00FE)
		&&  ( (*(bptr+(24*3)+1) & 0x00FF) == 0x00FE)
		&&  ( (*(bptr+(24*3)+2) & 0x00FF) == 0x00FE))
			force_host_style = 1;
		else	force_host_style = 0;
		}
	else	force_host_style = 0;

	for (	i=0; i < nombre; i++ ) {

		if (( i < 32 )
		&&  ( force_host_style  )) {
			bptr+=3;
			palette[i] = (char)i;
			}
		else	{
			r = (*(bptr++) & 0x00FF);
			g = (*(bptr++) & 0x00FF);
			b = (*(bptr++) & 0x00FF);
			palette[i] = vga_approximation( r,g,b);
			}
		}
	return;
}

char *	getcolourmap( short int colours )
{
	char * 	rptr=(char *) 0;
	short int	rlen;
	if ( fstream ) {
		if ((rptr = allocate((rlen = (colours * 3)))) != (char *) 0) {
			if ( fread( rptr, rlen, 1, fstream ) == 1 ) {
				usecolourmap( rptr, colours );
				return( rptr );
				}
			else	liberate( rptr );
			}
		}
	return( (char *) 0 );
}

int	getversion()
{
	char signature[3];
	if ( fstream ) {
		if (( fread(signature, 3,1,fstream ) == 1 )
		&&  ( signature[0] == 'G' )
		&&  ( signature[1] == 'I' )
		&&  ( signature[2] == 'F' )) {
			if ( fread(signature, 3,1,fstream ) == 1 ) {
				if  (( signature[0] == '8' )
				&&   ( signature[1] == '7' )
				&&   ( signature[2] == 'a' ))
					return(87);
				else if (( signature[0] == '8' )
				&&       ( signature[1] == '9' )
				&&       ( signature[2] == 'a' ))
					return(89);
				}
			}
		}
	return(0);
}

int	nextrow(struct standard_image * iptr)
{
	if (!( Interlaced ))
		thisrow++;
	else	{
		switch (PassCount) {
			case 1	:
				thisrow += 8;
				if ( thisrow >= Rows ) {
					PassCount++;
					thisrow = 4;
					}
				break;

			case 2	:
				thisrow += 8;				
				if ( thisrow >= Rows ) {
					PassCount++;
					thisrow = 2;
					}
				break;

			case 3	:
				thisrow += 4;				
				if ( thisrow >= Rows ) {
					PassCount++;
					thisrow = 1;
					}
				break;

			case 4	:
				thisrow += 2;
				if ( thisrow >= Rows ) {
					PassCount++;
					thisrow = 0;
					}
				break;
			default	:
				return(-1);

			}
		}

	if ((rowpointer = connect_pixel_row(iptr->storage, thisrow )) == (char *) 0)
		return(-1);
	else	return(thisrow);
}

int	getextension()
{
	short int	es = gif_skip_block;
	unsigned short int	length;
	
	if ( fread((char *) queue, 2,1,fstream ) != 1)
		return(-1);
	length = (queue[1] & 0x00FF);

	switch ( queue[0] & 0x00FF ) {
		case 0x0f9:	es = gif_control_extension; 	break;
		case 0x001:	es = gif_skip_block;	    	break;
		case 0x0ff:	es = gif_application_extension;	break;
		case 0x0fe:	es = gif_consume_comment;	break;
		}
            
	if (length) {
		if ( fread((char *) queue, length,1,fstream ) != 1 )
			return(-1);
		}
	else	{
		RecordType = getbyte();
		bytecounter=0;
		return(0);
		}

	while (1) {

		switch ( es ) {
			case	gif_consume_block		:

				if ((length = (queue[0] & 0x00FF)) != 0) {
					if ( fread((char *) queue, length,1,fstream ) != 1)
						return(-1);
					else	{
						es = gif_skip_block;
						continue;
						}
					}
				else	{
					RecordType = getbyte();
					bytecounter=0;
					return(0);
					}

			case	gif_skip_block			:
				if ( fread((char *) queue, 1,1,fstream ) != 1)
					return(-1);
				else	{
					es = gif_consume_block;
					continue;
					}

		        case gif_comment_extension		:
				if ((length = (queue[0] & 0x00FF)) != 0) {
					if ( fread((char *) queue, length,1,fstream ) != 1)
						return(-1);
					else	{
						es = gif_consume_comment;
						continue;
						}
					}
				else	{
					RecordType = getbyte();
					bytecounter=0;
					return(0);
					}

		        case gif_consume_comment		:
				if ( fread((char *) queue, 1,1,fstream ) != 1)
					return(-1);
				else	{
					es = gif_comment_extension;
					continue;
					}

			case	gif_control_extension		:

				if ( queue[0] & 1 ) {				
			                transparence  = queue[3];
                			istransparent = 1;
					}

				// We can load the animation timer from this block

				if ( fread((char *) queue, 1,1,fstream ) != 1)
					return(-1);
				else	{
					es = gif_consume_block;
					continue;
					}


			case	gif_application_extension	:

				if ( fread((char *) queue, 1,1,fstream ) != 1)
					return(-1);
				else	{
					es = gif_consume_block;
					continue;
					}
			default					:
				return(-1);

			}

		}


}

struct standard_image * parse_gif(struct standard_image * iptr)
{
	char	*	cptr;
	char	*	pptr;
	int		nbc;
	short int	r=0;
	short int	c=0;
	short int	w=0;
	short int	h=0;
	short int	x=0;
	short int	y=0;
	short int	o=0;
	short int	locals;
	short int	colours;
	short int	i;
	short int	lcolourmap=0;
	char *  colourmap=(char *) 0;

	if (!( iptr )) {
		if (!(iptr=allocate( sizeof( struct standard_image ) ) )) 
			return(iptr);
		else	{
			iptr->users=1;
			iptr->palette=0;
			iptr->format=0;
			}
		}
	else	iptr->users++;

	/* detect high quality */
	/* ------------------- */
	if ( colourmaped ) 
		hiq=get_image_quality();
	else	hiq=0;

	if ( hiq ) {
		if (!( iptr->palette )) {
			if (!( iptr->palette = allocate( 1024 ) ))
				return( iptr );
			memset(iptr->palette,0,1024);
			}
		}

	if ( fstream ) {

		while ( RecordType == GIF_EXTENSION )
			if (getextension() == -1)
				return(iptr);

		if ( RecordType == GIF_START_IMAGE )  {

			// -----------------------------
			// GIF DECODER Operational cycle
			// -----------------------------

			x = getword();	// X Offset (These may need to be 
			y = getword();	// Y Offset  swapped around if not ok)
			w = getword();  // Image Width
			h = getword();  // ImageHeight
			o = getbyte();	// Interlaced options, Colours

			if ( o & 0x0040 ) { Interlaced = 1; PassCount = 1; }
			else		  { Interlaced = 0; PassCount = 0; }

			if (( Rows   < h  ) 
			||  (Columns < w  ) 
			||  (Version == 87)) {
				Rows = h; Columns = w;
				x    = 0;  y = 0;
				}

			if (( h == 0 ) || ( w == 0 )) {
				h = Rows; w = Columns;
				}

			maxpixel = w;

			// -------------------------------------------------
			// Pre-Allocate All Row Buffers Now in Logical Image
			// -------------------------------------------------
			iptr->rows = Rows; iptr->columns = Columns;

			iptr->storage = allocate_graphic_storage(0,0,Columns,Rows);

			iptr->format = iptr->storage->descriptor[6]; /* was forced to 1 */

			if (!( o & 0x0080 )) {	// Use Global Colour Map
				colourmap = GlobalMap;
				colours   = Colours;
				locals    = 0;
				}
			else	{	// Local Colour Map 
				locals = (2 << (o & 7));
				colours =  -locals;
				lcolourmap=1;
				colourmap = getcolourmap( colours );
				}

			if ( istransparent )
				iptr->users = 2;


			if ( hiq ) {
				/* collect colour information */
				/* -------------------------- */
				nbc = -colours;
				hiqpalette = iptr->palette;
				for (cptr=colourmap,pptr=iptr->palette, i=0; i < 256; i++ ) {
					if ( i < nbc ) {
						*(pptr++) = *(cptr++);
						*(pptr++) = *(cptr++);
						*(pptr++) = *(cptr++);
						*(pptr++) = 0;
						}
					else	break;
					}
				}
			else	hiqpalette = (char *) 0;
		
			// LZW Start
			// ---------
			i = getbyte();

			if ((datasize = (i & 0x00FF)) > GIF_MAX_LZW)
				return( iptr ); // Error

			clearcode = (1 << datasize);

			razlzw(); datum = bits = 0;

			// Allocate GIF buffers
			// --------------------
			if ((!(prefix)) 
			&&  ((prefix = (int   *) allocate( (GIF_MAX_BITS * sizeof(int)) )) == (int   *) 0))
				return( iptr ); // Error
			else	memset(prefix,0,(GIF_MAX_BITS * sizeof(int)));
			if ((!(suffix)) 
			&&  ((suffix = (unsigned char *) allocate( (GIF_MAX_BITS * sizeof(char )) )) == (unsigned char *) 0))
				return( iptr ); // Error
			if ((!(stack)) 
			&&  ((stack = (unsigned char *) allocate( (GIF_MAX_BITS * sizeof(char )) )) == (unsigned char *) 0))
				return( iptr ); // Error


			if ( clearcode >= GIF_MAX_BITS )
				return( iptr );
			for ( i=0; i < clearcode; i++ )
				*(suffix + i) = i;

			stackp = 0;

			if ((rowpointer = connect_pixel_row(iptr->storage,(thisrow = 0))) ==(char *) 0) {
				return( iptr );
				}
			else	{
				pixel = 0;
				}

			while ((i = getbyte()) != 0)

				// Read LZW block
				if ( getlzw(iptr, i ) != 0 )
					break;


			}

		
		// 'S seo leth-bhreac .. feumaidh ...
		if ( gifname != (char *) 0 ) {
			liberate( gifname );
			gifname = (char *) 0;
			}

		// Thilg a-mach a'mhapa na dathan coimhearsnachdail
		// ------------------------------------------------
		if (( colourmap != (char *) 0 ) 
		&&  ( lcolourmap != 0         )) {
			liberate( colourmap );
			colourmap = (char *) 0;
			lcolourmap = 0;
			}

		if ( fstream != (FILE *) 0 ) {
			fclose( fstream );
			fstream = (FILE *)0;
			}
		}
	return( iptr );
}

void	razlzw()
{
	available = (clearcode + 2);
	oldcode = -1;
	codesize = (datasize + 1);
	codemask = ((1 << codesize) - 1);
	return;
}

static	void	gifputpixel(char * rb, int o, int v)
{
	char * pptr;
	if ( colourmaped )
		*(rb + o) = v;
	else if (( pptr = hiqpalette ) != (char *) 0) {
		pptr += ((v & 0x00FF)*4);
		put_logical_pixel( (rb+(o*pixelsize)),*pptr&0x00FF,*(pptr+1)& 0x00FF,*(pptr+2)&0x00FF);
		}
	else if (!( pptr = GlobalMap )) {
		if (!( pptr = VgaMap ))
			pptr = get_vga_palette();
		if (!( pptr ))
			return;
		pptr += ((v & 0x00FF)*4);
		put_logical_pixel( (rb+(o*pixelsize)),*pptr&0x00FF,*(pptr+1)& 0x00FF,*(pptr+2)&0x00FF);
		}
	else	{
		pptr += ((v & 0x00FF)*3);
		put_logical_pixel( (rb+(o*pixelsize)),*pptr&0x00FF,*(pptr+1)& 0x00FF,*(pptr+2)&0x00FF);
		}
	return;
}

int	getlzw(struct standard_image * iptr, int counter)
{
    	short int code;
    	short int incode;
	unsigned char	*ch;
	unsigned char   pixie;

	if (!(fstream))
		return(-1);
	else if ( fread((char *) queue, counter, 1, fstream ) != 1 )
		return(-1);
	for ( ch = queue; counter-- > 0; ch++ ) {
		/* Feed the next byte short into the decoder's 32-bit input buffer. */

		datum += (((unsigned long) *ch) << bits); bits += 8;

		/* Check for underflow of decoder's 32-bit input buffer. */
		while (bits >= codesize) {

			/* -------------------------------------------  */
			/* Get the leading variable-length symbol 	*/
			/* from the data stream 			*/
			/* -------------------------------------------  */
			code = (datum & codemask);
			datum >>= codesize;
			bits -= codesize;

			/* -------------------------------------------  */
			/* Reset the dictionary to its original state,	*/
			/* if requested 				*/
			/* -------------------------------------------  */
			if (code == clearcode) {
				razlzw();
				continue;
				}

			/* -------------------------------------------  */
			/* Check for explicit end-of-stream code 	*/
			/* -------------------------------------------  */
			if (code == (clearcode + 1))
				return(0);

			if (oldcode == -1) {
				pixie = suffix[code];
				if (( istransparent ) &&  ( pixie == transparence )) {
					pixie = 0;
					}
				else if (!( hiq )) {
					if ( colourmaped ) {
						pixie = TrueShade( pixie );
						if (!( pixie )) pixie = 16;
						}
					}
				if ((!( colourmaped )) && (!( pixie )))
					put_logical_pixel( (rowpointer+(pixel*pixelsize)),0,0,0);
				else	gifputpixel(rowpointer,pixel,pixie);
				pixel++;

				if (pixel == maxpixel ) {
					if ( nextrow(iptr) == -1 )
						return(0x001A);
					else	{
						pixel = 0;
						}
			                }
				firstchar = oldcode = code;
				continue;
				}

			/* --------------------------------------------------- */
			/* Check for a code not defined in the dictionary yet. */
			/* --------------------------------------------------- */
			if (code > available)  // Code too large
				return(-1);

			incode = code;

			if (code == available) {	   

				/* -------------------------------- */
				/* the first code is always < avail */
				/* -------------------------------- */
				*(stack + (stackp++)) = firstchar;
				code = oldcode;
				}

			while (code > clearcode) {
				if (code == prefix[code])
					return( -1 );
				*(stack + (stackp++)) = suffix[code];
				code = prefix[code];
				}


			/* Define a new codeword in the dictionary. */
			/* ---------------------------------------- */
			*(stack + (stackp++)) = firstchar = suffix[code];
			prefix[available] = (oldcode & 0xFFFF);
			suffix[available] = firstchar;
			available++;
			if(available >= GIF_MAX_BITS)
				return(-1);

			/* ------------------------------------------------------ */
			/* If we've used up all the codewords of a given length   */
			/* increase the length of codewords by one bit, but don't */
			/* exceed the specified maximum codeword size of 12 bits. */
			/* ------------------------------------------------------ */
			if (((available & codemask) == 0) && (available < 4096)) {
				codesize++;
				codemask += available;
				}
			oldcode = incode;
            
			/* Copy the decoded data out to the scanline buffer. */
			/* ------------------------------------------------- */
			if ( stackp != 0 ) {
				do 	{
					pixie = *(stack + (--stackp));
					if (( istransparent )
					&&  ( pixie == transparence ))
						pixie = 0;
 					else if (!( hiq )) {
						if ( colourmaped ) {
							pixie = TrueShade( pixie );
							if (!( pixie )) pixie = 16;
							}
						}
					if ((!( colourmaped )) && (!( pixie )))
						put_logical_pixel( (rowpointer+(pixel*pixelsize)),0,0,0);
					else	gifputpixel(rowpointer,pixel,pixie);
					pixel++;
					if (pixel >= maxpixel ) {
						if ( nextrow(iptr) == -1 )
							return(0x001A);
						else	{
							pixel = 0;
							}
						}
					} 
				while 	(stackp != 0);
				}

			}

		}

	return(0);
}

static unsigned short int  getbyte()
{
	char value=0;
	if ( fstream )
		if ( fread(& value,1,1,fstream) == 1 )
			bytecounter++;
	return((value & 0x00FF));
}

static unsigned short int	getword()
{
	unsigned short int value=0;
	if ( fstream ) {
		value = (getbyte() & 0x00FF);
		value = (value | ((getbyte() & 0x00FF) << 8));
		}
	return((value & 0xFFFF));
}

static long 	getlong()
{
	long 	result=0L;
	int 	value;
	value = getword();
	result = (long int ) getword();
	result <<= 16;
	result |= value;
	return( result );
}

struct standard_image * gif_loader( char * filename )
{
	struct standard_image * iptr=(struct standard_image *) 0;
	if (!( initialise_gif(filename) ))
		iptr = parse_gif(iptr);
	terminate_gif();
	return( iptr );
}

#endif	/* _screener_gif_c */





