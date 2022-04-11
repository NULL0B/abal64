#ifdef	OLD_PRINT_SCREEN

void	html_gui::PrintScreen()
{
	char	number[16];
	int	c;
	int	r;
	int	PaperPixels;
	int	MarginPixels;
	int	MarginBytes;
	int	RasterPixels;
	int	RasterBytes;
	int	BitsPerPixel=1;
	int	PixelMask;
	char *	RasterByte=(char *) 0;
	int	a;
	int	b;
	int	i;
	int	v;
	int	p;
	int	gratcol;
	int	gratlin;
	int	grtocol;
	int	grtolin;
	int	grnbcol;
	int	resgrlo;
	int	imask;
	int	n;
	int	lmp=0;
	int	lmb=0;
	int	maxpix=0;
	char *	mptr;
	char *	RowBuffer=(char *) 0;

	// Test Laser Jet Dots / Inch 
	// ---------------------------
	switch ( GuiLaser ) {
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
			if ( GuiLaser < 100 )
				GuiLaser = 75;
			else if ( GuiLaser < 150 )
				GuiLaser = 100;
			else if ( GuiLaser < 300 )
				GuiLaser = 150;
			else if ( GuiLaser < 600 )
				GuiLaser = 300;
			else if ( GuiLaser < 1200 )
				GuiLaser = 600;
			else	GuiLaser = 1200;
			break;
		}

	if ( GuiMargin ) {
		gratcol = ((window_column+(left_margin-1)) * GuiFontWidth);
		grnbcol = grtocol = (columns * GuiFontWidth);	
		}
	else	{
		gratcol = 0;
		grnbcol = grtocol = ((columns+(window_column*2)) * GuiFontWidth);	
		}

	gratlin = (window_line  * GuiFontHeight);
	grtolin = gratlin + (lines * GuiFontHeight);

	switch ( GuiLaser ) {
		case	  75 : PaperPixels =   584; break;
		case	 100 : PaperPixels =   778; break;
		case	 150 : PaperPixels =  1168; break;
		case	 300 : PaperPixels =  2336; break;
		case	 600 : PaperPixels =  4672; break;
		case	1200 : PaperPixels =  9344; break;
		}

	if ( PaperPixels >= grnbcol ) {

		if ((BitsPerPixel = (PaperPixels/grnbcol)) >= 8 ) {
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
		grnbcol      = PaperPixels; 
		BitsPerPixel = 1;
		PixelMask    = 0x0080;
		}

	RasterPixels = (grnbcol * BitsPerPixel);
	RasterBytes =  ((RasterPixels / 8) + (RasterPixels % 8 ? 1 : 0));

	if (( PaperPixels > RasterPixels )
	&&  ((MarginPixels = ((PaperPixels - RasterPixels) / 2)) > 0))
		MarginBytes  = (MarginPixels / 8);
	else	MarginBytes = 0;
		
	if (!(RowBuffer = html_string::allocate( GuiPixelWidth )))
		return;

	// Allocate Raster Line Preparation Buffer
	// ---------------------------------------
	else if (!( RasterByte = html_string::allocate( (RasterBytes + MarginBytes + 2 ) ))) {
		html_string::liberate( RowBuffer );
		return;
		}

	// Reset Left Margin Space to WHITE
	// --------------------------------
	if ( MarginBytes )
		for ( i=0; i < MarginBytes; i++ )
			*(RasterByte + i) = 0;


	if (!( systemloopen() ))
		return;

	// Reset LaserJet Printer
	// ----------------------
	escapeT( 2 ); systemlo( 27 ); systemlo('E');

	// Establish LaserJet Dots per Inch
	// --------------------------------
	sprintf(number,"%u",GuiLaser);
	escapeT( (4 + html_string::length( number )) );
		systemlo( 27 ); 
		systemlo('*');
		systemlo('t');
		for ( i=0; number[i] != 0; i++ )
			systemlo(number[i]);
		systemlo('R');

	// Ensure start at Left margin
	// ---------------------------
	escapeT( 5 ); systemlo( 27 ); systemlo('*'); systemlo('r'); systemlo('0'); systemlo('A');

	// Ensure Printing in Logical X direction
	// --------------------------------------
	escapeT( 5 ); 	systemlo( 27 ); systemlo('*'); systemlo('r'); systemlo('0'); systemlo('F');

	// Ensure Opaque
	// -------------
	escapeT( 5 ); 
		systemlo( 27 ); 
		systemlo('*');
		systemlo('r');
		systemlo('1');
		systemlo('N');

	grtocol += gratcol;

	// For All Graphic Rows
	// --------------------
	for (	r=gratlin; r < grtolin; r++ ) {

		getzone(gratcol,r,grnbcol,1,(RowBuffer+gratcol));

		// Preparation of Raster Row
		// -------------------------
		for (v=0,i=PixelMask,b=MarginBytes,c=gratcol; c < grtocol; c++ ) {

			// Average and Invert Luminosity (0 -> 255 getting darker)
			// -------------------------------------------------------
			a = ((html_vga::average( *(RowBuffer + c) ) ^ 0x00FF) & 0x00FF);

			switch ( BitsPerPixel ) {
				case	8	: v = a; break;

				case	4	:
					if ( i == PixelMask )
						a &= PixelMask;
					else	a = ((a & PixelMask) >> 4);
					v |= a;
					break;

				
				case	2	:
					switch ( a & PixelMask ) {
						case	0x00C0	:
							v |= i; break;
						case	0x0080	:
							v |= (i & 0x5555); break;
						case	0x0040	:
							v |= (i & 0xAAAA); break;
						}
					break;

				case	1	:

					if ( a & PixelMask )
						v |= i;
					break;
				}


			i >>= BitsPerPixel; // Bits Per Pixel

			if (!( i )) {
				i = PixelMask;
				*(RasterByte + (b++)) = v;
				v=0;
				}
			}

		if ( i != PixelMask )
			*(RasterByte + (b++)) = v;

		// Send Rows of Raster Data
		// ------------------------
		sprintf(number,"%u",b);
		v = html_string::length( number );

		for (n=0; n < BitsPerPixel; n++ ) {

			escapeT(4+v+b);
				systemlo(27);
				systemlo('*');
				systemlo('b');
				for ( i=0; number[i] != 0; i++ )
					systemlo(number[i]);
				systemlo('W');
				for (i=0; i < b; i++ )
					systemlo(*(RasterByte+i));

			}

		}

	// End Graphics
	escapeT( 4 ); 
		systemlo( 27 ); 
		systemlo('*');
		systemlo('r');
		systemlo('C');


	// Clear Page
	systemlo(0x000C);

	// Reset LaserJet Printer
	escapeT( 2 ); 
		systemlo( 27 ); 
		systemlo('E');


	if ( RasterByte )
		html_string::liberate( RasterByte );

	if ( RowBuffer );
		html_string::liberate( RowBuffer );

	systemloclose();

	return;

	
}

#else	// NEW_PRINT_SCREEN

