#ifndef	_zbmp_c
#define _zbmp_c

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

#define	BMP_SIGNATURE "BM"

#ifndef DoTrace
#define DoTrace(a)
#endif

int	vga_approximation(int  r, int  g, int  b );
static	int	PixelSize=0;

char *	put_true_colour_pixel( char * mptr, int r, int g, int b ) 
{ 
	return( (mptr+put_logical_pixel(mptr,r,g,b)) ); 
}

int     not_true_colour() 
{
	if ( get_pixel_format() )
		return(1); 
	else	return(0);
}

static		FILE 	*	handle=(FILE*)0;
			int	inhibit_transparence=1;
			int	force_host_style=0;
static			int	pixelid;
static			int	pixelbyte;
static		long	int	bytecounter;
static		long 	int 	FileSize;
static		short 	int 	Resolution1;
static		short 	int 	Resolution2;
static		long 	int 	PixelOffset;
static		long 	int	HeaderSize;
static		long 	int	Columns;
static	 	long 	int	Rows;
static		short	int	Planes;
static		short 	int	BitsPerPixel;
static		long 	int	Compression;
static		long 	int	CompSize;
static		long 	int 	Xscale;
static		long 	int 	Yscale;
static		long 	int 	ColourCount;
static		long 	int 	ImportantColourCount;
static		short	int	PixelsPerByte;
static		char		Palette[256][4];
static		char		Colours[256];
static		long	int	ByteControl;
static			int	garbage;

static	char getbyte()
{
	char value=0;
	if ( handle )
		if ( fread(& value, 1,1,handle) == 1 )
			bytecounter++;
	return(value);
}

static	short int	getword()
{
	short int value=0;
	if ( handle ) {
		value = (getbyte() & 0x00FF);
		value = (value | ((getbyte() & 0x00FF) << 8));
		}
	return(value);
}

static	long int	getlong()
{
	long int	result=0L;
	short int 	value;
	value = getword();
	result = (long int ) getword();
	result <<= 16;
	result |= value;
	return( result );
}

static	int	getpixel()
{
	int	result;
	if ( pixelid > PixelsPerByte ) {
		pixelbyte = getbyte();
		pixelid = 1;
		}
	switch ( PixelsPerByte ) {
		case	1 :
			result = pixelbyte;
			break;
		case	2 :
			switch ( pixelid ) {
				case	1 :
					result = ((pixelbyte & 0x00F0) >> 4);
					break;
				case	2 :
					result = (pixelbyte & 0x000F);
					break;
				}
			break;
		case	4 :
			switch ( pixelid ) {
				case	1 :
					result = ((pixelbyte & 0x00C0) >> 6);
					break;
				case	2 :
					result = ((pixelbyte & 0x0030) >> 4);
					break;
				case	3 :
					result = ((pixelbyte & 0x000C) >> 2);
					break;
				case	4 :
					result = (pixelbyte & 0x0003);
					break;
				}
			break;

		}
	pixelid++;
	return((Colours[(result & 0x00FF)] & 0x00FF));
}

int	initialise_bmp( char * filename )
{
	char signature[2];
	int	length=0;
	int	xxx=0;
	bytecounter = 0L;

	if ((handle = fopen( filename, "rb")) == (FILE*) 0)
		return(40);

	if (( fread( signature, 2, 1, handle ) == 1 )
	&&  ( signature[0] == 'B' )
	&&  ( signature[1] == 'M' )) {
		bytecounter = 2L;
		FileSize		= getlong();
		DoTrace( printf("Filesize=%lu\n",FileSize));
	 	Resolution1		= getword();
		DoTrace( printf("Res1    =%u\n",Resolution1));
 		Resolution2		= getword();
		DoTrace( printf("Res2    =%u\n",Resolution2));
 		PixelOffset		= getlong();
		DoTrace( printf("PixOffs =%lu\n",PixelOffset));
 		HeaderSize		= getlong();
		DoTrace( printf("HeadSize=%lu\n",HeaderSize));
 		Columns			= getlong();
		DoTrace( printf("Columns =%lu\n",Columns));
 		Rows			= getlong();
		DoTrace( printf("Rows    =%lu\n",Rows) );
 		Planes			= getword();
		DoTrace( printf("Planes  =%u\n",Planes) );
 		BitsPerPixel		= getword();
		DoTrace( printf("Bits/Pix=%u\n",BitsPerPixel) );
 		Compression		= getlong();
		DoTrace( printf("Compress=%lu\n",Compression) );

		/* Bug fix 1 : some files do not provide this value */
		/* ------------------------------------------------ */
 		if (!(CompSize = getlong()))
			CompSize = (FileSize - PixelOffset);

		DoTrace( printf("CompSize=%lu\n",CompSize) );
 		Xscale			= getlong();
		DoTrace( printf("Xscale  =%lu\n",Xscale) );
 		Yscale			= getlong();
		DoTrace( printf("Yscale  =%lu\n",Yscale) );
 		ColourCount		= getlong();
		DoTrace( printf("Colours =%lu\n",ColourCount) );
 		ImportantColourCount	= getlong();
		DoTrace( printf("ImportantColours=%lu\n",ImportantColourCount) );

		switch ( BitsPerPixel ) {
			case	8	: PixelsPerByte = 1; break;
			case	4	: PixelsPerByte = 2; break;
			case	2	: PixelsPerByte = 4; break;
			case	1	: PixelsPerByte = 8; break;
			default		: PixelsPerByte = 0; 
				if ( not_true_colour() ) {
					fclose( handle );
					handle = (FILE*)0;
					return(56);
					}
				else	break;
			}

		DoTrace( printf("PixelsPerByte=%u\n",PixelsPerByte));

		garbage = 0;

		/* Bug fix 2 : some files give incorrect image width */
		/* ------------------------------------------------- */
		if ( PixelsPerByte == 1 ) {
/*
 *	Bug fix : 10/01/2002 : 	IJM correction for 256 colour images
 *				when column count is not a multiple of 4
 *
 *			if ( CompSize > (Rows * Columns) )
 *				Columns = (CompSize/Rows);
 */
			garbage=0;
			}

		else if ( PixelsPerByte != 0 )	{
			ByteControl = (Columns/PixelsPerByte);
			if ((Columns%PixelsPerByte)!=0)
				 ByteControl++;
			while ( ((ByteControl+garbage) * Rows) < CompSize )
				garbage++;
			}
		else	garbage = 0;

		if ( PixelsPerByte != 0 ) {

			if (!(ImportantColourCount )) {
				/* Bug Fix 3 : some files forget to indicate the size */
				/* of the colour palette */
				if (!(ColourCount ))
					ImportantColourCount = (((short int) (PixelOffset - bytecounter)) / 4);
				else	ImportantColourCount = ColourCount;
				}
			}

		if ((length = (ImportantColourCount * 4)) != 0) {
			DoTrace( printf("L=%u\n",length) );
			if ( fread((char *) & Palette , length, 1, handle ) == 1 ) {
				bytecounter += length;
				if (!( inhibit_transparence )) {
					if (( Palette[16][0] == 1)
					&&  ( Palette[16][1] == 1)
					&&  ( Palette[16][2] == 1)
					&&  ( (Palette[24][0]  & 0x00FF) == 0x00FE)
					&&  ( (Palette[24][1]  & 0x00FF) == 0x00FE)
					&&  ( (Palette[24][2]  & 0x00FF) == 0x00FE))
						force_host_style = 1;
					else	force_host_style = 0;
					}
				else	force_host_style = 0;
				for ( xxx = 0; xxx < 32; xxx++ )
					if (!(Colours[xxx] = xxx))
						if ( inhibit_transparence )
							Colours[xxx] = 32;
						
				xxx = 0;
				for (xxx=0; xxx < ImportantColourCount; xxx++ ) {
					if (( force_host_style != 0 ) && ( xxx < 0x0020 ))
						continue;
					if (!( Colours[xxx] = vga_approximation( (Palette[xxx][2]&0x00FF),(Palette[xxx][1]&0x00FF),(Palette[xxx][0]&0x00FF) ) ))
						if ( inhibit_transparence )
							Colours[xxx] = 16;
					DoTrace( printf("C[%u] <= %u <= P[%u][2]=%u,P[%u][1]=%u,P[%u][0]=%u \n",xxx,(Colours[xxx]&0x00FF),xxx,(Palette[xxx][2]&0x00FF),xxx,(Palette[xxx][1]&0x00FF),xxx,(Palette[xxx][0]& 0x00FF) ) );
					}
				}
			}
		return(0);
		}
	else	{
		fclose( handle );
		handle = (FILE*)0;
		return(55);
		}
}

struct standard_image * parse_bmp(struct standard_image * iptr)
{
	int	i;
	int	r=0;
	int	c=0;
	char *	rptr;
	int	rvalue;
	int	gvalue;
	int	bvalue;
	int	colourmaped;
	int	pixelsize=0;
	int	dpi=0;

	if (!( iptr )) {
		if (!( iptr= allocate( sizeof (struct standard_image ) ) )) 
			return(iptr);
		else	iptr->users=1;
		}
	else	iptr->users++;

	if ( handle ) {

		if (!( colourmaped = get_pixel_format() )) {
			if ((iptr->palette = allocate( 1024 )) != (char *) 0) {
				for (i=0; i < 256; i++ ) {
					*(iptr->palette+(i*4))   = Palette[i][2];
					*(iptr->palette+(i*4)+1) = Palette[i][1];
					*(iptr->palette+(i*4)+2) = Palette[i][0];
					}
				}
			}
		pixelsize   = get_pixel_size();

		dpi = gethqfont(); sethqfont(75);
		iptr->storage = allocate_graphic_storage(
				 0,0, 
				(iptr->columns = Columns),
				(iptr->rows = Rows));
		sethqfont(dpi);
		if ( iptr->storage ) {
			
			if ( PixelsPerByte )
				iptr->storage->descriptor[6] = 1;
			else	iptr->format = pixelsize;

			if ( bytecounter != PixelOffset ) {
				DoTrace( printf("bytecounter(%lu) != PixelOffset(%lu)\n",bytecounter,PixelOffset));
				}

			for (r=Rows; r != 0; ) {
				r--;

				if ((rptr = connect_pixel_row( iptr->storage, r)) != (char *) 0) {

					if (!( PixelsPerByte )) {
						/* Special Case True Colour BMP */
						for (c=0; c < Columns; c++ ) {
							bvalue = getbyte();
							gvalue = getbyte();
							rvalue = getbyte();
							rptr = put_true_colour_pixel( rptr, rvalue, gvalue, bvalue );
							}
						for (i=(Columns*3); i%4 != 0; i++ ) {
/*						for (i=Columns; i%4 != 0; i++ ) {	*/
/*							bvalue = getbyte();		*/
/*							gvalue = getbyte();		*/
							rvalue = getbyte();
							}
						}
					else if ( PixelsPerByte != 1 ) {

						pixelid=PixelsPerByte+1;

						for (c=0; c < Columns; c++ )
							*( rptr + c) = getpixel();	

						/* Remove garbage bytes */
						for ( c=0; c < garbage; c++ )
							(void) getbyte();

						}
					/* Optimisation for speed */
					/* when 1 pixel per byte  */
					else if ( fread(rptr,(int)Columns,1,handle) == 1) {
/*
 *	Bug fix : 10/01/2002 : 	IJM correction for 256 colour images
 *				when column count is not a multiple of 4
 */
						for (i=Columns; i%4 != 0; i++ )
							fread(&c,1,1,handle);
 /* End of correction */
						bytecounter += Columns;
						for (c=0; c < Columns; c++ )
							*(rptr + c) = Colours[( *(rptr+c) & 0x00FF)];
						}
					}
				}
			}
		}
	return( iptr );
}

void	terminate_bmp()
{
	if ( handle ) {
		fclose(handle);
		handle=(FILE*)0;
		}
	return;
}

struct standard_image * bmp_loader( char * filename )
{
	struct standard_image * iptr=(struct standard_image *) 0;
	if (!( initialise_bmp(filename) ))
		iptr = parse_bmp(iptr);
	terminate_bmp();
	return( iptr );
}

int	set_transparence(int v)
{
	int	i=inhibit_transparence;
	if ( v ) {
		force_host_style = 1;
		inhibit_transparence=0;
		}
	else	{
		force_host_style = 0;
		inhibit_transparence=1;
		}
	return(( i ? 0 : 1));
}

#endif	// _zbmp_c




