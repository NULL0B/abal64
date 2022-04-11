/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	FILESEEK.C				*/
/*		Version :	1.1a					*/
/*		Date	:	04/07/1991				*/
/*									*/
/* --------------------------------------------------------------------	*/
#include "fileseek.h"

#ifndef	_FILESEEK_C
#define	_FILESEEK_C

struct	swap_control	{
	BYTE	buffer[256];
	long	offset;
	WORD	type;
	} SwapControl;

long	swap_seek( handle , seek_offset, seek_type )
WORD	handle;
long	seek_offset;
WORD	seek_type;
{
	SwapControl.type = seek_type;
	return((SwapControl.offset = seek_offset));
}

WORD	swap_read( handle, buffer , length )
WORD	handle;
BPTR	buffer;
WORD	length;
{
	long	loffset;
	WORD	indent;
	WORD	result;
	WORD	transfer;

	/* Calculate Block start and indent values */
	/* --------------------------------------- */
	loffset 	= ((SwapControl.offset / 256 ) * 256 );
	indent  	= (WORD)   (SwapControl.offset % 256 );
	transfer	= 0;
	result		= length;

	while ( length ) {

		/* Position to the first block */
		/* --------------------------- */
		if ( lseek( handle, loffset, SwapControl.type ) == -1L )
			return( -1 );

		/* Attempt to read the block from file */
		/* ----------------------------------- */
		if ( read(  handle,(BPTR) SwapControl.buffer, 256 ) != 256 )
			return( -1 );

		/* Copy to users buffer */
		/* -------------------- */
	 	(void) memcpy((BPTR) buffer,(BPTR) (SwapControl.buffer + indent),(transfer = ( ( length + indent ) > 256  ? (256 - indent) : length) ) );

		/* Calculate for next possible transfer */
		/* ------------------------------------ */
		length  -= transfer; 	buffer += transfer; 
		loffset +=256;		indent = 0;

		}

	/* Indicate successful read operation */
	/* ---------------------------------- */
	return( result );
	
}

WORD	swap_write( handle, buffer , length )
WORD	handle;
BPTR	buffer;
WORD	length;
{
	long	loffset;
	WORD	indent;
	WORD	result;
	WORD	transfer;

	/* Calculate Block start and indent values */
	/* --------------------------------------- */
	loffset 	= ((SwapControl.offset / 256 ) * 256 );
	indent  	= (WORD)   (SwapControl.offset % 256 );
	transfer	= 0;
	result		= length;

	while ( length ) {

		/* Position to the first block */
		/* --------------------------- */
		if ( lseek( handle, loffset, SwapControl.type ) == -1L ) {
			if ( MessageReady )
				(void) BufferControl.message(20);
			return( -1 );
			}

		/* Attempt to read the block from file */
		/* ----------------------------------- */
		if ( read(  handle,(BPTR) SwapControl.buffer, 256 ) != 256 )
			(void) memset((BPTR) SwapControl.buffer, 0 , 256 );

		/* Copy from users buffer */
		/* ---------------------- */
	 	(void) memcpy((BPTR) (SwapControl.buffer + indent), (BPTR) buffer,(transfer = ( ( length + indent ) > 256  ? (256 - indent) : length ) ) );  

		/* Position to the first block */
		/* --------------------------- */
		if ( lseek( handle, loffset, SwapControl.type ) == -1L ) {
			if ( MessageReady )
				(void) BufferControl.message(21);
			return( -1 );
			}
		/* Attempt to update the file block */
		/* -------------------------------- */
		if ( write( handle,(BPTR) SwapControl.buffer, 256 ) != 256 ) {
			if ( MessageReady )
				(void) BufferControl.message(22);
			return( -1 );
			}
		/* Calculate for next possible transfer */
		/* ------------------------------------ */
		length  -= transfer; 	buffer += transfer; 
		loffset +=256;		indent = 0;

		}

	/* Indicate successful read operation */
	/* ---------------------------------- */
	return( result );


}
/*	Remove previous definitions for VMS	*/
/*	-----------------------------------	*/
#ifdef	VMS
#undef	read
#undef	write
#undef	lseek
#endif

/*	Redefine SEEK/READ and WRITE		*/
/*	----------------------------		*/
#define	lseek(arg1,arg2,arg3)	swap_seek(arg1,arg2,arg3)
#define	read(arg1,arg2,arg3)	swap_read(arg1,arg2,arg3)
#define	write(arg1,arg2,arg3)	swap_write(arg1,arg2,arg3)

/* System Prototypes for file access functions */
/* ------------------------------------------- */

#ifndef	ABAL_CRITERIA
#ifndef	WIN32
long	lseek( WORD, long, WORD);
WORD	read( WORD, BPTR, WORD );
WORD	write( WORD, BPTR, WORD);
WORD	open( BPTR, WORD, WORD );
WORD	close( WORD );
WORD	unlink( BPTR ); 
#endif
#endif

#endif	/* _FILESEEK_C */
	/* ----------- */
