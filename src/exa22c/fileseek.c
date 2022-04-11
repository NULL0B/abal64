/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	FILESEEK.C				*/
/*		Version :	2.1d					*/
/*		Date	:	11/04/1996				*/
/*									*/
/* --------------------------------------------------------------------	*/
#include "fileseek.h"

#ifndef	_FILESEEK_C
#define	_FILESEEK_C

struct	swap_control	{
	EXABYTE	buffer[256];
	long	offset;
	EXAWORD	type;
} SwapControl;

long	swap_seek( handle , seek_offset, seek_type )
EX_FILE_HANDLE	handle;
long	seek_offset;
EXAWORD	seek_type;
{
	SwapControl.type = seek_type;
	return((SwapControl.offset = seek_offset));
}

EXAWORD	swap_read( handle, buffer , length )
EX_FILE_HANDLE	handle;
BPTR	buffer;
EXAWORD	length;
{
	long	loffset;
	EXAWORD	indent;
	EXAWORD	result;
	EXAWORD	transfer;

	/* Calculate Block start and indent values */
	/* --------------------------------------- */
	loffset  = ((SwapControl.offset / 256 ) * 256 );
	indent   = (EXAWORD)   (SwapControl.offset % 256 );
	transfer = 0;
	result	 = length;

	while ( length ) {

		/* Position to the first block */
		/* --------------------------- */
		if ( lseek( handle, loffset, SwapControl.type ) == -1L )
			return( 0xFFFF );

		/* Attempt to read the block from file */
		/* ----------------------------------- */
		if ( read(  handle,(BPTR) SwapControl.buffer, 256 ) != 256 )
			return( 0xFFFF );

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

EXAWORD	swap_write( handle, buffer , length )
EX_FILE_HANDLE	handle;
BPTR	buffer;
EXAWORD	length;
{
	long	loffset;
	EXAWORD	indent;
	EXAWORD	result;
	EXAWORD	transfer;

	/* Calculate Block start and indent values */
	/* --------------------------------------- */
	loffset  = ((SwapControl.offset / 256 ) * 256 );
	indent   = (EXAWORD)   (SwapControl.offset % 256 );
	transfer = 0;
	result	 = length;

	while ( length ) {

		/* Read not needed if the whole sector has to be written */
		if ((indent != 0) || (length < 256)) {

			/* Position to the first block */
			/* --------------------------- */
			if ( lseek( handle, loffset, SwapControl.type ) == -1L ) {
				if ( MessageReady )
					(void) BufferControl.message(20);
				return( 0xFFFF );
			}

			/* Attempt to read the block from file */
			/* ----------------------------------- */
			if ( read(  handle,(BPTR) SwapControl.buffer, 256 ) != 256 )
				(void) memset((BPTR) SwapControl.buffer, 0 , 256 );
		}

		/* Copy from users buffer */
		/* ---------------------- */
	 	(void) memcpy((BPTR) (SwapControl.buffer + indent), (BPTR) buffer,(transfer = ( ( length + indent ) > 256  ? (256 - indent) : length ) ) );

		while (1) {
			/* Position to the first block */
			/* --------------------------- */
			if ( lseek( handle, loffset, SwapControl.type ) == -1L ) {
				if ( MessageReady ) (void) BufferControl.message(21);
				return( 0xFFFF );
			}

			/* Attempt to update the file block */
			/* -------------------------------- */
			if ( write( handle,(BPTR) SwapControl.buffer, 256 ) != 256 ) {

				/* Attempt to extend the file */
				/* -------------------------- */
				if (extend(handle,1) != 0 ) {
					if ( MessageReady ) (void) BufferControl.message(22);
					return( 0xFFFF );
				}
			}
			else	break;
		}

		/* Calculate for next possible transfer */
		/* ------------------------------------ */
		length  -= transfer; 	buffer += transfer;
		loffset +=256;		indent = 0;
	}

	/* Indicate successful write operation */
	/* ----------------------------------- */
	return( result );
}

/*	Remove previous definitions for VMS	*/
/*	-----------------------------------	*/
#ifdef	VMS
#undef	read
#undef	write
#undef	lseek
#endif

#ifdef ABAL_CRITERIA
#undef lseek
#endif

/*	Redefine SEEK/READ and WRITE		*/
/*	----------------------------		*/
#define	lseek(arg1,arg2,arg3)	swap_seek(arg1,arg2,arg3)
#define	read(arg1,arg2,arg3)	swap_read(arg1,arg2,arg3)
#define	write(arg1,arg2,arg3)	swap_write(arg1,arg2,arg3)

/* System Prototypes for file access functions */
/* ------------------------------------------- */

#ifndef	ABAL_CRITERIA
long	lseek( EXAWORD, long, EXAWORD);
EXAWORD	read( EXAWORD, BPTR, EXAWORD );
EXAWORD	write( EXAWORD, BPTR, EXAWORD);
EXAWORD	open( BPTR, EXAWORD, EXAWORD );
EXAWORD	close( EXAWORD );
EXAWORD	unlink( BPTR ); 
#endif

#endif	/* _FILESEEK_C */
	/* ----------- */
