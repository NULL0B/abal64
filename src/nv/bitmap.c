#ifndef	_BMP_C
#define	_BMP_C

PRIVATE	WORD	check_bmp( iptr )
BMPFILEPTR	iptr;
{
	BPTR	tptr=(BPTR) ( & iptr->Head.Signature);
	BPTR	sptr=(BPTR) BMP_SIGNATURE;
	while ( *sptr ) {
		if ( *(tptr++) != *(sptr++) )
			break;
		}
	switch ( iptr->Info.BitsPerPixel ) {
		case	8	: iptr->PixelsPerByte = 1; break;
		case	4	: iptr->PixelsPerByte = 2; break;
		case	2	: iptr->PixelsPerByte = 4; break;
		case	1	: iptr->PixelsPerByte = 8; break;
		}
	return( (WORD) *sptr );
}

PRIVATE	BMPFILEPTR	allocate_for_bmp()
{
	BMPFILEPTR	iptr=(BMPFILEPTR) 0;
	if ((iptr = (BMPFILEPTR) malloc( sizeof (BMPFILE) )) != (BMPFILEPTR) 0) {
		iptr->File = (FILEPTR) 0;
		memset((BPTR) & iptr->Head, 0,sizeof( BMPHEAD ) );
		memset((BPTR) & iptr->Info, 0,sizeof( BMPINFO ) );
		memcpy((BPTR) & iptr->Palette, (BPTR) VgaPalette,(4*256));
		memset((BPTR) & iptr->Colours, 0,256 );
		}
	return( iptr );
}

PRIVATE	BMPFILEPTR	liberate_for_bmp( iptr )
BMPFILEPTR	iptr;
{
	if ( iptr != (BMPFILEPTR) 0) {
		if ( iptr->File != (FILEPTR) 0 )
			iptr->File = CloseFile( iptr->File );
		free( iptr );
		iptr = (BMPFILEPTR) 0;
		}	
	return( iptr );
}

PUBLIC	WORD	is_bmp( nptr )
BPTR		nptr;
{
	BPTR	sptr=(BPTR) BMP_EXTENSION;
	while ( *nptr )
		if ( *(nptr++) != *(sptr++) )
			return(0);
	return( BMP_FILE_TYPE );
}


PRIVATE	VOID		build_image( bmp )
	BMPFILEPTR 	bmp;
{
	LONG		offset;
	LONG		filesize;

	filesize = bmp->Info.CompSize;
	offset   = bmp->Head.PixelOffset;

	printf("build_image : %lu @ %lu \n",filesize,offset);

	if ( FileSeekZero( bmp->File ) == 0 )

		while ( filesize )
		
			FilePutByte( bmp->File, offset++, (WORD) (filesize--) );

	return;

}

PUBLIC	VOID		build_bmp( bmp, columns, rows, colours )
	BMPFILEPTR 	bmp;
	WORD		columns;
	WORD		rows;
	WORD		colours;
{
	WORD		pixels=0;
	WORD	hlen;
	BYTE	TempHead[256];
	memset((BPTR) TempHead, 0x00F0, 256 );
	memcpy((BPTR) & bmp->Head.Signature,BMP_SIGNATURE,strlen(BMP_SIGNATURE));
 	bmp->Head.FileSize		= 0;
 	bmp->Head.Resolution1		= 0;
 	bmp->Head.Resolution2		= 0;
 	bmp->Info.HeaderSize		= 40;
 	bmp->Info.Columns		= columns;
 	bmp->Info.Rows			= rows;
 	bmp->Info.Planes		= 1;

	if ( colours <= 2 ) {
		bmp->Info.BitsPerPixel 	       	= 1;
 		bmp->Info.ImportantColourCount 	= 2;
		pixels = bmp->PixelsPerByte	= 8;
		}
	else if ( colours <= 4 ) {
		bmp->Info.BitsPerPixel 	       	= 2;
 		bmp->Info.ImportantColourCount 	= 4;
		pixels = bmp->PixelsPerByte	= 4;
		}
	else if ( colours <= 16 ) {
		bmp->Info.BitsPerPixel 	       	=  4;
 		bmp->Info.ImportantColourCount 	= 16;
		pixels = bmp->PixelsPerByte	=  2;
		}
	else 	{
		bmp->Info.BitsPerPixel 	       	=  8;
 		bmp->Info.ImportantColourCount 	= colours;
		pixels = bmp->PixelsPerByte	=  1;
		}

 	bmp->Info.Compression		= 0;
 	bmp->Info.CompSize		= ((columns * rows) / pixels);
 	bmp->Info.Xscale		= 0;
 	bmp->Info.Yscale		= 0;
 	bmp->Info.ColourCount		= 0;
 	bmp->Head.PixelOffset		= (sizeof(BMPINFO) + sizeof(BMPHEAD) + (bmp->Info.ImportantColourCount * 4));
	bmp->Head.FileSize              = (bmp->Head.PixelOffset + bmp->Info.CompSize);

	if ((hlen = WriteFile( bmp->File, 0L,(BPTR) & TempHead, 256 )) == 256 )
		if ((hlen = WriteFile( bmp->File, 0L,(BPTR) & bmp->Head, sizeof( BMPHEAD))) == sizeof( BMPHEAD))
			if ((hlen = WriteFile( bmp->File,(LONG) hlen,(BPTR) & bmp->Info, sizeof( BMPINFO))) == sizeof(BMPINFO))
				if ((hlen = WriteFile( bmp->File,(LONG) (hlen + sizeof(BMPHEAD)),(BPTR) VgaPalette , (bmp->Info.ImportantColourCount * 4))) == (bmp->Info.ImportantColourCount * 4))
					build_image( bmp );
	return;
}

PUBLIC	VOID		put_bmp_colour( iptr, item, entry )
	BMPFILEPTR	iptr;
	WORD		item;
	WORD		entry;
{
	WORD	x=0;
	for ( x = 0; x < 4; x++ )
		iptr->Palette[item][x] = VgaPalette[entry][x];
	return;
}

PUBLIC	WORD		get_bmp_colour( iptr, item )
	BMPFILEPTR	iptr;
	WORD		item;
{
	if ( item != FILE_ERROR )
		return( iptr->Colours[ item ] );
	else	return( item );
}

PUBLIC	VOID		flush_bmp_colour( iptr )
	BMPFILEPTR	iptr;
{
	WORD	hlen;
	(VOID) WriteFile( iptr->File,(LONG) (sizeof(BMPINFO) + sizeof(BMPHEAD)),(BPTR) & iptr->Palette , (iptr->Info.ImportantColourCount * 4));
	return;
}


PRIVATE	WORD		load_palette( iptr )
	BMPFILEPTR 	iptr;
{
	LONG	offset;
	WORD	length;
	WORD	xxx;
	if ( iptr == (BMPFILEPTR) 0) 
		return( 27 );
	else 	{
	 	offset = ((LONG) (sizeof(BMPINFO) +sizeof(BMPHEAD)));
		if (!(iptr->Info.ImportantColourCount )) {
			if (!(iptr->Info.ColourCount ))
				iptr->Info.ImportantColourCount = (((WORD) (iptr->Head.PixelOffset - offset)) / 4);
			else	iptr->Info.ImportantColourCount = iptr->Info.ColourCount;
			}
		length = (iptr->Info.ImportantColourCount * 4);
		if ((xxx = ReadFile(iptr->File,offset,(BPTR) & iptr->Palette , length )) != length )
			return( 48 );
		else	{
			xxx = 16;
			for ( xxx = 0; xxx < 16; xxx++ )
				iptr->Colours[xxx] = xxx;
			while ( xxx < iptr->Info.ImportantColourCount ) {
				iptr->Colours[xxx] = vga_approximation( iptr->Palette[0],iptr->Palette[1],iptr->Palette[2] );
				xxx++;
				}
			return( 0 );
			}
		}	
}

PUBLIC	VOID	display_bmp_header( iptr )
BMPFILEPTR	iptr;
{
	WORD	i;
	printf("\nBMP File %s Head & Info {\n",iptr->File->Name);
 	printf("\tFileSize    %lu\n",iptr->Head.FileSize);
 	printf("\tResolution1 %u \n",iptr->Head.Resolution1);
 	printf("\tResolution2 %u \n",iptr->Head.Resolution2);
 	printf("\tPixelOffset %lu\n",iptr->Head.PixelOffset);
 	printf("\tHeaderSize  %lu\n",iptr->Info.HeaderSize);
 	printf("\tColumns     %lu\n",iptr->Info.Columns);
 	printf("\tRows        %lu\n",iptr->Info.Rows);
 	printf("\tPlanes      %u \n",iptr->Info.Planes);
 	printf("\tBits/Pixel  %u \n",iptr->Info.BitsPerPixel);
 	printf("\tCompression %lu\n",iptr->Info.Compression);
 	printf("\tCompSize    %lu\n",iptr->Info.CompSize);
 	printf("\tXscale      %lu\n",iptr->Info.Xscale);
 	printf("\tYscale      %lu\n",iptr->Info.Yscale);
 	printf("\tColourCount %lu\n",iptr->Info.ColourCount);
 	printf("\tImportant   %lu\n",iptr->Info.ImportantColourCount);
 	printf("\tPalette     {\n");

	for ( i = 0; i < iptr->Info.ImportantColourCount; i++ )
		printf("\t\t %u, %u, %u, %u, \n",iptr->Palette[i][0],iptr->Palette[i][1],iptr->Palette[i][2],iptr->Palette[i][3]);

	printf("\t\t}\n");
	printf("\t}\n");
	return;
}

PUBLIC 	BMPFILEPTR open_bmp( filename )
BPTR filename;
{
	WORD	hlen=0;
	BMPFILEPTR iptr=(BMPFILEPTR) 0;
	if ((iptr = allocate_for_bmp()) != (BMPFILEPTR) 0) {
		if ((iptr->File = OpenFile( filename,BMP_EXTENSION )) == (FILEPTR) 0)
			iptr = liberate_for_bmp( iptr );
		else if ((hlen = ReadFile(iptr->File,0L,(BPTR) & iptr->Head, sizeof( BMPHEAD))) != sizeof (BMPHEAD))
			iptr = liberate_for_bmp( iptr );
		else if ((hlen = ReadFile(iptr->File,(LONG) hlen,(BPTR) & iptr->Info, sizeof( BMPINFO))) != sizeof (BMPINFO))
			iptr = liberate_for_bmp( iptr );
		else if ( check_bmp( iptr ) )
			iptr = liberate_for_bmp( iptr );
		else if ( load_palette( iptr ) )
			iptr = liberate_for_bmp( iptr );

		}
	if ( verbose )
		if ( iptr != (BMPFILEPTR) 0 )
			display_bmp_header( iptr );
	return( iptr );
}

PUBLIC	BMPFILEPTR create_bmp( filename )
BPTR 		filename;
{
	BMPFILEPTR iptr=(BMPFILEPTR) 0;
	if ((iptr = allocate_for_bmp()) != (BMPFILEPTR) 0)
		if ((iptr->File = CreateFile( filename, BMP_EXTENSION )) == (FILEPTR) 0)
			iptr = liberate_for_bmp( iptr );

	if ( verbose )
		if ( iptr != (BMPFILEPTR) 0 )
			display_bmp_header( iptr );
	return( iptr );
}

PUBLIC	INT 	close_bmp( iptr, status )
BMPFILEPTR iptr;
INT	status;
{
	if ( iptr != (BMPFILEPTR) 0 )
		iptr = liberate_for_bmp( iptr );
	return( status );
}

WORD	get_bmp( iptr, column, row )
BMPFILEPTR	iptr;
WORD		column;
WORD		row;
{
	LONG	offset;
	WORD	pixel;
	offset = ((((((LONG) row) * ((LONG) iptr->Info.Columns)) + column) / iptr->PixelsPerByte) + iptr->Head.PixelOffset );
	if ((pixel = FileGetByte(iptr->File,offset)) != FILE_ERROR) {
		if ( iptr->PixelsPerByte == 2 ) {
		        if ( column & 1 )
		                pixel &= 0x000F;
		        else	pixel >>= 4;
			}
		pixel &= 0x00FF;
/*		printf("GetBmp(%u,%u @ %lu) [ %u =?= ",column,row,offset,pixel); */
		}
	return( pixel );
}

WORD	put_bmp( iptr, column, row, pixel )
BMPFILEPTR	iptr;
WORD		column;
WORD		row;
WORD		pixel;
{
	LONG	offset;
	WORD	newpixel;
	if ( pixel != FILE_ERROR ) {
		offset = ((((((LONG) row) * ((LONG) iptr->Info.Columns)) + column) / iptr->PixelsPerByte) + iptr->Head.PixelOffset );
		if ( iptr->PixelsPerByte == 2 ) {
			if ( column & 1 )
				return( FilePutLoByte(iptr->File,offset,pixel)); 
			else	return( FilePutHiByte(iptr->File,offset,pixel));
			}
		else	return( FilePutByte(iptr->File,offset,pixel) );
		}
	return(pixel);
}



#endif 	/* _BMP_C */
	/* ------ */


