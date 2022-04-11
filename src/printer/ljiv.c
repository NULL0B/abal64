#ifndef	_LJIV_C
#define	_LJIV_C

#include "lodriver.h"

#include "ljiv.h"

#define	putlo(v) *(result+(rlen++))=v
#define	escapeT( v ) rlen = packethead(result,rlen,v)


int	escapeTbugfix=0;
int	LeftMarginBytes=0;
int	TopMargin=0;
int	PrinterReady=0;
int	RasterReady=0;
int	RowLength=0;
int	RowCount=0;
char *	RasterByte=(char *) 0;
char *	RasterWork=(char *) 0;
int	PixelMask=0;
int	BitsPerPixel=0;
char *	PaletteBuffer=(char *) 0;
char	Number[32];

int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

int	luminence( char * bptr, int offset );

int	packethead(char * result,int rlen, int nb )
{
	putlo( 27 ); putlo( 'T' );
	putlo( nb & 0x00FF );
	putlo( (nb >> 8) & 0x00FF );
	return(rlen);
}

int	length( char * sptr )
{
	int	l;
	for ( l=0; *(sptr+l) != 0; l++ );
	return( l );
}

int	DriverInitialise(char * palette, int dpi, int grnbcol, int grnbrow, int options)
{
	int	LeftMarginPixels;
	int	RasterPixels;
	int	RasterBytes;
	int	i;

	set_colour_options( options );

	RasterReady = PrinterReady = 0;

	escapeTbugfix = (options & 0x1000);

	PaletteBuffer = palette;

	set_paper_dimensions(dpi, ((options & _PAPER_TYPE) >> _PAPER_SHIFT));

	RowCount = grnbrow; RowLength = grnbcol;

	if ( PaperWidth  > RowLength ) {
		if ( PaperHeight > RowCount  ) {
			if ((PaperWidth/RowLength) < (PaperHeight/RowCount))
				BitsPerPixel = 	(PaperWidth/RowLength);
			else	BitsPerPixel = 	(PaperHeight/RowCount);
			}
		else	{
			RowCount = PaperHeight;
			BitsPerPixel = 1;
			}
		}
	else	{
		RowLength = PaperWidth;
		BitsPerPixel = 1;
		}

	if (BitsPerPixel >= 8 ) {
		BitsPerPixel = 8;
		PixelMask    = 0x00FF;
		}
	else if ( BitsPerPixel >= 4 ) {
		BitsPerPixel = 4;
		PixelMask    = 0x00F0;
		}
	else if ( BitsPerPixel >= 2 ) {
 			BitsPerPixel = 2;
		PixelMask    = 0x00C0;
		}
	else	{
		BitsPerPixel = 1;
		PixelMask    = 0x0080;
		}

	RasterPixels = (RowLength * BitsPerPixel);
	RasterBytes  = ((RasterPixels / 8) + (RasterPixels % 8 ? 1 : 0));

	if ( PaperWidth > RasterPixels ) {
		switch ( options & 3 ) {
			case	1 :
				LeftMarginPixels = LeftMarginBytes = 0;
				break;

			case	2 :
				if ((LeftMarginPixels = (PaperWidth - RasterPixels)) > 0)
					LeftMarginBytes  = (LeftMarginPixels / 8);
				else	LeftMarginBytes  = 0;
				break;

			case	0 :
			case	3 :
				if ((LeftMarginPixels = ((PaperWidth - RasterPixels) / 2)) > 0)
					LeftMarginBytes  = (LeftMarginPixels / 8);
				else	LeftMarginBytes  = 0;
			}
		}

	else	LeftMarginBytes = 0;
		

	return( ((RasterBytes + LeftMarginBytes + 128) * BitsPerPixel) );

}


int	DriverConnect( char * bptr, char * wptr, char * result )
{
	int	rlen=0;
	int	i=0;

	RasterByte = bptr;
	RasterWork = wptr;

	// Reset Left Margin Space to WHITE
	// --------------------------------
	if ( LeftMarginBytes )
		for ( i=0; i < LeftMarginBytes; i++ )
			*(RasterByte + i) = 0;


	// Reset DriverJet Printer
	// ----------------------
	escapeT( 2 ); putlo( 27 ); putlo('E');

	PrinterReady=1;

	return( rlen );
}

int	DriverStartRaster(char * result)
{
	int	rlen=0;
	int	i;

	char 	number[16];

	if (!( RasterReady )) {

		// Establish DriverJet Dots per Inch
		// --------------------------------
		sprintf(number,"%u",DotsPerInch);

		escapeT( (4 + length( number )) );
			putlo( 27 ); 
			putlo('*');
			putlo('t');
			for ( i=0; number[i] != 0; i++ )
				putlo(number[i]);
			putlo('R');

		// Ensure start at Left margin
		// ---------------------------
		escapeT(9);

	 	putlo( 27 ); putlo('*'); putlo('r'); putlo('0'); 

		putlo('a');

		// Ensure Printing in Logical X direction
		// --------------------------------------
	 	putlo('0'); 	putlo('f');

		// Ensure Opaque
		// -------------
		putlo('1'); putlo('N');
		
		RasterReady = 1;
		}
	return(rlen);
}


int	DriverEndRaster(char * result)
{
	int	rlen=0;
	if ( RasterReady ) {
		// End Graphics
		escapeT( 4 ); 
		putlo( 27 ); 	putlo('*'); 
		putlo('r'); 	putlo('C');
		putlo(0x000C);
		RasterReady=0;
		}
	return(rlen);
}

int	DriverLiberate(char * result)
{
	int	rlen=0;

	if ( RasterReady )
		rlen = DriverEndRaster(result);

	// Reset DriverJet Printer

	escapeT( 2 ); 
		putlo( 27 ); 
		putlo('E');

	RasterWork = (char *) 0;
	RasterByte = (char *) 0;
	return(rlen);
}

int	optimiser(int notwhite,char * result,int rlen)
{
	int	bpp=BitsPerPixel;
	int	o=0;
	int	i=0;
	int	n=0;
	int	a=0;
	int	c=0;
	int	l=0;
	int	d=0;
	int	x=0;
	int	f=0;

	char *  rptr=RasterByte;
	char *  wptr=RasterWork;
	char *	nptr=Number;

	while ( i < notwhite ) {

		// Detect string of identical bytes
		// --------------------------------
		for (c=*(rptr+i),n=0,a=(i+1); a < notwhite; a++ ) {
			if ( *(rptr + a) != c )
				break;
			else	n++;
			}
		if ( n ) {
			n++;
			// N identical bytes found
			// -----------------------
			while ( n >= 128 ) {
				*(wptr +o) = ((128 - 1) * -1); o++; n-=128;
				}

			if ( n ) {
				*(wptr+o) = ((n - 1) * -1); o++;		
				}
			
			}
		else	{
			// --------------------------------
			// No match found
			// --------------------------------
			// Detect string of different bytes
			// --------------------------------
			for (n=0,a=(i+1); a < notwhite; a++ ) {
				if ( *(rptr + a) != *(rptr + i) ) {
					i++;
					n++;
					}
				else	break;
				}		

			if ( a == notwhite )
				n++;
			else	a = i;

			while ( n >= 128 ) {
				*(wptr +o) = 127; o++; n-=128;
				}

			if ( n ) {
				*(wptr+o) = (n-1); o++;		
				}
			}
		i = a;
		}

	// Totalise all bytes to be sent
	// -----------------------------
	for (n=0,a=0; a < o; a++ ) {
		if ( *(wptr+a) >= 0 )
			n += (*(wptr+a) + 2);
		else	n += 2;
		}
	
	if (!(f = n))
		n++;

	sprintf(nptr,"%u",n);
	l = length( nptr );

	for (a=0; a < bpp; a++ ) {

		if ( f ) 
			escapeT(6+l+n);
		else	escapeT(4+l+n);

		putlo(27); putlo('*'); putlo('b');

		if ( f ) {
			putlo('2');putlo('m');
			}

		for ( i=0; *(nptr+i) != 0; i++ )
			putlo(*(nptr+i));
		putlo('W');

		if (!( f ))
			putlo(f);

		else for (d=0,i=0; i < o; i++ ) {
			putlo((c = *(wptr+i)));
			if ( c >= 0 ) {
				c++;
				for ( x=0;x < c; x++ ) {
					putlo( *(rptr + d));
					d++;
					}
				}
			else	{
				putlo( *(rptr + d) );
				d += ((c * -1) + 1);
				}
			}
		}

	return(rlen);
}

int	DriverPrintRow(char * result, char * rowbuffer)
{
	int	rlen=0;
	int	t;
	int	a;
	int	b;
	int	c;
	int	i;
	int	v;
	int	p;
	int	n;
	int	rl=RowLength;
	char *	rb=RasterByte;
	int	pm=PixelMask;
	int	bpp=BitsPerPixel;
	int	notwhite=0;
	char *	nptr=Number;

	if (!( PrinterReady ))
		return(0);
	else if (!( RasterReady ))
		rlen = DriverStartRaster(result);

	// Preparation of Raster Row
	// -------------------------
	for (notwhite=0,v=0,i=pm,b=LeftMarginBytes,c=0; c < rl; c++ ) {

		// Average and Invert Luminosity (0 -> 255 getting darker)
		// -------------------------------------------------------
		
		a = luminence( rowbuffer, c );

		a = ((a ^ 0x00FF) & 0x00FF);

		switch ( bpp ) {
			case	8	:
				v = a; 
				break;
			case	4	:
				if ( i == pm )
					a &= pm;
				else	a = ((a & pm) >> 4);
				v |= a;
				break;
			case	2	:
				switch ( a & pm ) {
					case	0x00C0	:
						v |= i; break;
					case	0x0080	:
						v |= (i & 0x5555); break;
					case	0x0040	:
						v |= (i & 0xAAAA); break;
					}
				break;

			case	1	:
				if ( a & pm )
					v |= i;
				break;
			}
		i >>= bpp; 

		if (!( i )) {
			i = pm;
			if (( escapeTbugfix )
			&&  ( v == 0x001A   )) 
				v = 0x002A;
			if (( *(rb + (b++)) = v ) != 0)
				notwhite = b;
			v=0;
			}
		}

	if ( i != pm ) {
		if (( escapeTbugfix )
		&&  ( v == 0x001A   )) 
			v = 0x002A;
		if (( *(rb + (b++)) = v ) != 0)
			notwhite = b;
		}

	return( optimiser( notwhite, result,rlen ) );
	
}

int	DriverColours()	{	return(0); 	}

#include "lodriver.c"

	/* ----------- */
#endif	/* _DRIVERABAL_C */
	/* ----------- */




