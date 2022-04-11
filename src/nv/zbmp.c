#ifndef	_zbmp_c
#define _zbmp_c

#include <stdio.h>
#include "zalloc.h"
#include "zimage.h"
#define	BMP_SIGNATURE "BM"

#ifndef DoTrace
#define DoTrace(a)
#endif

static		char	*	colourbmp="\1COLOURBMP";

static		FILE 	*	handle=(FILE*)0;
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
	if ( *colourbmp )
	return((Colours[(result & 0x00FF)] & 0x00FF));
	/* return(((result & 0x000F) | 0x0010)); */
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
			default		: PixelsPerByte = 0; break;
			}
		DoTrace( printf("PixelsPerByte=%u\n",PixelsPerByte));

		garbage = 0;

		/* Bug fix 2 : some files give incorrect image width */
		/* ------------------------------------------------- */
		if ( PixelsPerByte == 1 ) {
			if ( CompSize > (Rows * Columns) )
				Columns = (CompSize/Rows);
			}
		else	{
			ByteControl = (Columns/PixelsPerByte);
			if ((Columns%PixelsPerByte)!=0)
				 ByteControl++;
			while ( ((ByteControl+garbage) * Rows) < CompSize )
				garbage++;
			}

		if (!(ImportantColourCount )) {
			/* Bug Fix 3 : some files forget to indicate the size */
			/* of the colour palette */
			if (!(ColourCount ))
				ImportantColourCount = (((short int) (PixelOffset - bytecounter)) / 4);
			else	ImportantColourCount = ColourCount;
			}

		length = (ImportantColourCount * 4);
		DoTrace( printf("L=%u\n",length) );
		if ( fread((char *) & Palette , length, 1, handle ) == 1 ) {
			bytecounter += length;
			for ( xxx = 0; xxx < 16; xxx++ )
				Colours[xxx] = xxx;
			xxx = 0;
			for (xxx=0; xxx < ImportantColourCount; xxx++ ) {
				Colours[xxx] = vga_approximation( (Palette[xxx][2]&0x00FF),(Palette[xxx][1]&0x00FF),(Palette[xxx][0]&0x00FF) );
				DoTrace( printf("C[%u] <= %u <= P[%u][2]=%u,P[%u][1]=%u,P[%u][0]=%u \n",xxx,(Colours[xxx]&0x00FF),xxx,(Palette[xxx][2]&0x00FF),xxx,(Palette[xxx][1]&0x00FF),xxx,(Palette[xxx][0]& 0x00FF) ) );
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
	int	r=0;
	int	c=0;
	char *	rptr;

	if ((!( iptr ))
	&& (!( iptr= allocate( sizeof (struct standard_image ) ) )))
		return(iptr);

	iptr->users++;

	if ( handle ) {
		if ((iptr->storage = allocate_graphic_storage(
				 0,0, 
				(iptr->columns = Columns),
				(iptr->rows = Rows)))) {

			if ( bytecounter != PixelOffset ) {
				DoTrace( printf("bytecounter(%lu) != PixelOffset(%lu)\n",bytecounter,PixelOffset));
				}

			for (r=Rows; r != 0; ) {
				r--;

				if ((rptr = connect_pixel_row( iptr->storage, r)) != (char *) 0) {

					if ( PixelsPerByte != 1 ) {

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


#endif	// _zbmp_c




