//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_gui_laser_cpp
#define _gui_laser_cpp

#include <stdio.h>
#include "lo.h"
#include "glo.h"

int	underline_links=0;
int	landscape_mode=0;
int	escapeTbugfix=1;
int	optimised=1;

void	putlo( int c )
{
	listoutput->loch( (c & 0x00FF) );
	return;
}


void	startraster()
{
	int	i;
	char 	number[16];
	if (!( RasterReady )) {

		// Establish LaserJet Dots per Inch
		// --------------------------------
		sprintf(number,"%u",DotsPerInch);
		escapeT( (4 + html_string::length( number )) );
			putlo( 27 ); 
			putlo('*');
			putlo('t');
			for ( i=0; number[i] != 0; i++ )
				putlo(number[i]);
			putlo('R');

		// Ensure start at Left margin
		// ---------------------------
		if (!( optimised )) escapeT( 5 ); else escapeT(9);

	 	putlo( 27 ); putlo('*'); putlo('r'); putlo('0'); 

		if (!( optimised )) putlo('A'); else putlo('a');

		// Ensure Printing in Logical X direction
		// --------------------------------------
		if (!( optimised )) {
			escapeT( 5 ); putlo( 27 ); putlo('*'); putlo('r');
			}

	 	putlo('0'); 

		if (!( optimised )) putlo('F'); else putlo('f');

		// Ensure Opaque
		// -------------
		if (!( optimised )) {
			escapeT( 5 ); putlo( 27 ); putlo('*'); putlo('r'); 
			}

		putlo('1'); putlo('N');
		
		RasterReady = 1;
		}
	return;

}

void	endraster()
{
	if ( RasterReady ) {
	// End Graphics
		escapeT( 4 ); 
		putlo( 27 ); 	putlo('*'); 
		putlo('r'); 	putlo('C');
		RasterReady=0;
		}
	return;
}


gui_laser( printer_interface * loptr, int dpi, int grnbcol  )
{
	int	PaperPixels;
	int	MarginPixels;
	int	RasterPixels;
	int	RasterBytes;
	int	i;
	RasterReady = NumberReady = PrinterReady = 0;

	listoutput = loptr;

	// Test Laser Jet Dots / Inch 
	// ---------------------------
	switch (( DotsPerInch = dpi)) {
		case	   0	: // Laser Output Inhibited
			return;
		case	  75 	:
		case	 100	:
		case	 150	:
		case	 300	: // Max for Laser Jet Series 2
		case	 600	:
		case	1200	: // Max for Laser Jet Series 4
			break;
		default		:
			if ( DotsPerInch < 100 )
				DotsPerInch = 75;
			else if ( DotsPerInch < 150 )
				DotsPerInch = 100;
			else if ( DotsPerInch < 300 )
				DotsPerInch = 150;
			else if ( DotsPerInch < 600 )
				DotsPerInch = 300;
			else if ( DotsPerInch < 1200 )
				DotsPerInch = 600;
			else	DotsPerInch = 1200;
			break;
		}

	switch ( DotsPerInch ) {
		case	  75 : PaperPixels =   584; break;
		case	 100 : PaperPixels =   778; break;
		case	 150 : PaperPixels =  1168; break;
		case	 300 : PaperPixels =  2336; break;
		case	 600 : PaperPixels =  4672; break;
		case	1200 : PaperPixels =  9344; break;
		default	     : return;
		}

	if ( PaperPixels >= (RowLength=grnbcol) ) {

		if ((BitsPerPixel = (PaperPixels/RowLength)) >= 8 ) {
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
		}
	else	{
		RowLength      = PaperPixels; 
		BitsPerPixel = 1;
		PixelMask    = 0x0080;
		}

	RasterPixels = (RowLength * BitsPerPixel);
	RasterBytes =  ((RasterPixels / 8) + (RasterPixels % 8 ? 1 : 0));

	if (( PaperPixels > RasterPixels )
	&&  ((MarginPixels = ((PaperPixels - RasterPixels) / 2)) > 0))
		MarginBytes  = (MarginPixels / 8);
	else	MarginBytes = 0;
		
	// Allocate Raster Line Preparation Buffer
	// ---------------------------------------
	if (!( RasterByte = html_string::allocate( (RasterBytes + MarginBytes + 2 ) )))
		return;

	if ( optimised ) {
		if (!( RasterWork = html_string::allocate( (RasterBytes + MarginBytes + 2 ) ))) {
			html_string::liberate( RasterByte );
			RasterByte = (char *) 0;
	 		return;
			}
		}

	// Reset Left Margin Space to WHITE
	// --------------------------------
	if ( MarginBytes )
		for ( i=0; i < MarginBytes; i++ )
			*(RasterByte + i) = 0;


	// Reset LaserJet Printer
	// ----------------------
	escapeT( 2 ); putlo( 27 ); putlo('E');

	//	-----------------------------------------
	//	Set Landscape or Italien Mode(not really)
	//	-----------------------------------------
	//	This code has been inhibited since the
	//	landscape mode does not work in raster
	//	graphics mode !
	//	-----------------------------------------
	//	escapeT( 5 ); 
	//	putlo( 27 ); 
	//	putlo('&');putlo('l');
	//	if ( landscape_mode )
	//		putlo('1');
	//	else	putlo('0');
	//	putlo('O');
	//	----------------------------------------
	PrinterReady=1;

	return;

}


void	optimiser(int notwhite)
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

	// Normal non-optimised heavy weight
	// ---------------------------------
	sprintf(nptr,"%u",n);
	l = html_string::length( nptr );

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

	return;
}

//	-----------------------
//	PRINT ROW ( rowbuffer )
//	-----------------------
void	printrow( char * rowbuffer )
{
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
		return;
	else if (!( RasterReady ))
		startraster();

	// Preparation of Raster Row
	// -------------------------
	for (notwhite=0,v=0,i=pm,b=MarginBytes,c=0; c < rl; c++ ) {

		// Average and Invert Luminosity (0 -> 255 getting darker)
		// -------------------------------------------------------
		
		a = html_vga::average(( *(rowbuffer + c) & 0x00FF));

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

	// Check for Run Length Optimisation
	// ---------------------------------
	if ( optimised )
		optimiser( notwhite );

	else	{

		// Send Rows of Raster Data
		// ------------------------
		if (!( notwhite ))
			notwhite=1;

		// Normal non-optimised heavy weight
		// ---------------------------------
		sprintf(nptr,"%u",notwhite);
		v = html_string::length( nptr );

		while (((t = (4+v+notwhite)) & 0x00FF) == 0x001A) {
			if (!( escapeTbugfix ))
				break;
			else	{
				notwhite++;		
				sprintf(nptr,"%u",notwhite);
				v = html_string::length( nptr );
				}
			}

		for (n=0; n < bpp; n++ ) {
			escapeT(t);
			putlo(27); putlo('*'); putlo('b');
			for ( i=0; *(nptr+i) != 0; i++ )
				putlo(*(nptr+i));
			putlo('W');
			for (i=0; i < notwhite; i++ )
				putlo(*(rb+i));
			}
		}
	return;

}


~gui_laser()
{

	if ( RasterReady )
		endraster();

	// Reset LaserJet Printer
	escapeT( 2 ); 
		putlo( 27 ); 
		putlo('E');

	if ( RasterWork ) {
		html_string::liberate( RasterWork );
		RasterWork = (char *) 0;
		}

	if ( RasterByte ) {
		html_string::liberate( RasterByte );
		RasterByte = (char *) 0;
		}

	return;

}

void	escapeT( int nb )
{
	putlo( 27 ); putlo( 'T' );
	putlo( nb & 0x00FF );
	putlo( (nb >> 8) & 0x00FF );
	return;
}

#endif	// _gui_laser_cpp


