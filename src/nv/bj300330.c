#ifndef	_BJ300330_C
#define	_BJ300330_C

#include "lodriver.h"

#include "bj300330.h"

#define	_BUBBLE_MASK   0x0080
#define	_BUBBLE_SHIFT  1

#define	putlo(v) *(result+(rlen++))=v
#define	escapeT( v ) rlen = packethead(result,rlen,v,'T')

int	escapeTbugfix=0;
int	MarginBytes=0;		/* number of pixels reserved for the left margin */
int	RasterBytes=0;		/* number of bytes  required for row conversion  */
int	RasterLength=0;		/* number of pixels available in mode		 */
int	DotsPerInch=0;
int	PrinterReady=0;
int	RasterReady=0;
int	RowLength=0;

int	BufferBytes=0;		/* Total size of allocated buffers		  */
int	BubbleMode='L';		/* ESC mode to be used		*/
int	BubbleFlag=0;		/* extension when ESC [ g	*/

int	PixelMask=0x0080;	/* Bit mixing mask		*/
int	PixelBytes=1;		/* Number of bytes in structure	*/
int	PixelSlice=0;		/* Current Slice		*/

char *	RasterByte=(char *) 0;
char *	RasterWork=(char *) 0;

int	RasterMask=0;
int	BitsPerPixel=0;

char *	PaletteBuffer=(char *) 0;
char	Number[32];

int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

int	average( int v )
{
	int	max=0;
	int	r=0;
	char *  pptr;
	if (( v >= 0 ) && ( v <= 255)) {
		pptr = (PaletteBuffer + (v*4));
		if ((r = (*(pptr + 3) & 0x00FF)) != 0)
			return(r);
		else 	{
			if ((r = (*pptr & 0x00FF)) > max )
				max = r;
			if ((r = (*(pptr+1) & 0x00FF)) > max )
				max = r;
			if ((r = (*(pptr+2) & 0x00FF)) > max)
				max = r;
			return((*(pptr+3) = max));
			}
		}
	else	return( 0 );
}

int	packetlength( char * bptr, int blen)
{
	int	i=0;
	int	j=0;
	for (i=0,j=0; i < blen; i++ )
		if ( *(bptr + i ) != 0)
			j = i;
	return(j);
}

int	packethead(char * result,int rlen, int nb, int code )
{
	putlo( 27 ); putlo( code );
	putlo( nb & 0x00FF );
	putlo( (nb >> 8) & 0x00FF );
	return(rlen);
}

int	flush_buffer( char * result, int rlen )
{
	int	i;
	int	nb;
	int	mlen=((RasterBytes+MarginBytes)*PixelBytes);

	if ((mlen = packetlength(RasterByte,mlen)) != 0) {

		if ( BubbleMode != '[' ) {
			escapeT((mlen+4));
			rlen = packethead( result, rlen, mlen, BubbleMode );
			}
		else	{
			escapeT((mlen+6));
			putlo(27); 
			putlo('['); 
			putlo('g');
			putlo( ((mlen+1) & 0x00FF) );
			putlo( (((mlen+1) >> 8) & 0x00FF) );
			putlo( BubbleFlag );
			}

		for ( i=0; i < mlen; i++ ) {
			putlo( *(RasterByte + i) );
			*(RasterByte + i) = 0;
			}
		}

	putlo(13); putlo(10);

	PixelMask = RasterMask = _BUBBLE_MASK;
	PixelSlice = 0;
	return( rlen );

}

int	length( char * sptr )
{
	int	l;
	for ( l=0; *(sptr+l) != 0; l++ );
	return( l );
}

int	DriverInitialise(char * palette, int dpi, int grnbcol, int grnblin, int options)
{
	int	PaperPixels;
	int	MarginPixels;
	int	RasterPixels;
	int	RasterBytes;

	RasterReady = PrinterReady = 0;

	escapeTbugfix = (options & 0x1000);

	PaletteBuffer = palette;

	// Test Driver Jet Dots / Inch 
	// ---------------------------
	switch (( DotsPerInch = dpi)) {

		case	  75 	: 
			DotsPerInch = 60;
		case	  60	:
			BubbleMode = 'K'; 
			BubbleFlag =  0;
			PixelBytes = 1;
			if ((RasterLength = 480) >= grnbcol)
				break;

		case	 100	: 
			DotsPerInch= 120;
		case	 120	:
			BubbleMode = 'L';
			BubbleFlag =  0;
			PixelBytes =  1;
			if ((RasterLength = 960) >= grnbcol)
				break;

		case	 150	: 
			DotsPerInch = 180;
		case	 180	: 
			BubbleMode = '[';
			BubbleFlag = 11;
			PixelBytes =  3;
			if ((RasterLength = 1440) >= grnbcol )
				break;

		case	 300	:
			DotsPerInch = 240;
		case	 240	:

			BubbleMode = 'Z';
			BubbleFlag =  0;
			PixelBytes =  1;
			if ((RasterLength = 1920) >= grnbcol )
				break;


		case	 600	:
		case	1200	:
			DotsPerInch = 360;

		case	 360	: 
			BubbleMode = '[';
			BubbleFlag = 16;
			RasterLength = 2880;
			PixelBytes = 6;
			break;

		case	   0	: // Driver Output Inhibited
		default		:
			PixelBytes = RasterLength = BubbleFlag =  BubbleMode = 0;
			break;
		}

	if (!( PixelBytes ))
		return( PixelBytes );

	if ( PaperPixels > RasterPixels ) {
		switch ( options & 3 ) {
			case	1 :
				MarginPixels = MarginBytes = 0;
				break;

			case	2 :
				if ((MarginPixels = (PaperPixels - RasterPixels)) > 0)
					MarginBytes  = (MarginPixels / 8);
				else	MarginBytes  = 0;
				break;

			case	0 :
			case	3 :
			if ((MarginPixels = ((PaperPixels - RasterPixels) / 2)) > 0)
				MarginBytes  = (MarginPixels / 8);
			else	MarginBytes  = 0;
			}
		}
	else	MarginBytes = 0;

	RowLength = ((RasterBytes + MarginBytes) * PixelBytes);

	// Return the Maximum Size required for a row of converted data
	// ------------------------------------------------------------

	return((BufferBytes = ((RasterBytes + (MarginBytes*2)) * PixelBytes)) + 128);


}


int	DriverConnect( char * bptr, char * wptr, char * result )
{
	int	rlen=0;
	int	i=0;

	RasterByte = bptr;
	RasterWork = wptr;

	// Wipe Entire buffer
	for (i=0; i < BufferBytes; i++ ) {
		*(RasterByte + i) = 0;
		*(RasterWork + i) = 0;
		}

	// Reset Bubble Jet
	// ----------------


	if ( BubbleMode != '[' ) {

		escapeT( 2 ); 	putlo( 27 ); putlo('@');
		// Set Line Spacing if only using 40 jets
		// --------------------------------------
		escapeT( 3 ); 	putlo( 27 ); putlo('3'); putlo(24);

		}

	PrinterReady=1;
	PixelMask = RasterMask = _BUBBLE_MASK;
	RasterReady=PixelSlice = 0;
	return( rlen );
}

int	DriverStartRaster(char * result) 
{
	int	i;
	if (!( RasterReady )) {
		// Wipe Entire buffer
		for (i=0; i < BufferBytes; i++ ) {
			*(RasterByte + i) = 0;
			*(RasterWork + i) = 0;
			}
		PixelMask = RasterMask  = _BUBBLE_MASK;
		RasterReady = 1;
		PixelSlice  = 0;
		}
	return(0); 
}

int	DriverEndRaster(char * result)   
{ 
	int	rlen=0;
	if ( RasterReady ) {
		if (( RasterMask != _BUBBLE_MASK ) 
		||  ( PixelSlice ))
			rlen = flush_buffer(result,rlen);
		RasterReady = 0;
		}
	return(rlen);
}


int	DriverLiberate(char * result)
{
	int	rlen=0;

	if ( RasterReady )
		rlen = DriverEndRaster( result );

	// Reset DriverJet Printer

	escapeT( 2 ); 
		putlo( 27 ); 
		putlo('@');

	RasterWork = (char *) 0;
	RasterByte = (char *) 0;

	return(rlen);
}

int	DriverPrintRow(char * result, char * rowbuffer)
{
	int	a;
	int	i;
	int	p;
	int	rlen=0;

	if (!( RasterReady ))
		rlen = DriverStartRaster( result );

	
	for (i=0; i < RasterBytes; i++ ) {

		a = average(( *(rowbuffer + i) & 0x00FF));

		a = ((a ^ 0x00FF) & 0x00FF);

		if ( a & PixelMask ) {
			*(RasterByte + (((MarginBytes + i) * PixelBytes) + PixelSlice)) |= RasterMask;
			}

		}

	/* Shift to next row bit position */

	RasterMask >>= 1;

	if (!( RasterMask )) {

		/* End of this byte */
		/* move on to next  */
		PixelSlice++;

		if ( PixelSlice < PixelBytes ) {
			/* more bytes required per slice */
			RasterMask = _BUBBLE_MASK;
			return(0);
			}
		else	{
			/* all bytes have been done */
			return( flush_buffer( result, rlen ) );
			}
		}
	else	return( 0 );

}



int	DriverColours()	{	return(0); 	}

#include "lodriver.c"

	/* ----------- */
#endif	/* _DRIVERABAL_C */
	/* ----------- */






