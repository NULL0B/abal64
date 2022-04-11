#ifndef	_FILES_C
#define	_FILES_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "files.h"

#ifdef	PROLOGUE

PRIVATE	INT	FileIndent=0;
PRIVATE	BYTE	FileBuffer[256];

PRIVATE	INT	WriteIndent=0;
PRIVATE	BYTE	WriteBuffer[256];

PUBLIC	INT	FileOpen( nptr, option )
	BPTR  	nptr;
	INT     option;
{
	INT	handle;
	if ((handle = open( nptr, option )) >= 0 )
		FileIndent = 256;		
	return( handle );
}

PUBLIC	INT	FileCreate( nptr )
	BPTR  	nptr;
{
	INT	handle;
	BPTR	pptr;
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '/' )
			*pptr = '\\';
		}
	if (*nptr == '\\') nptr++;
	unlink( nptr );
	if ((handle = creat(nptr, 0666)) >= 0 ) {
		close( handle );
		handle = -1;
		if ((handle = open( nptr, (O_RDWR | O_BINARY) )) >= 0 )
			WriteIndent = 0;
		}
	return( handle );
}

PUBLIC	INT    	FileRead( handle, buffer, length )
	INT	handle;
	BPTR  	buffer;
	INT     length;
{
	INT	status;
	INT	xfer=0;
	while ( xfer < length ) {
		if ( FileIndent >= 256 ) {
			if ( read( handle, FileBuffer, 256 ) != 256 )
				break;
			else	FileIndent = 0;
			}
		*(buffer++) = FileBuffer[FileIndent++];
		xfer ++;
		}
	return( xfer );
}

PUBLIC	INT    	FileWrite( handle, buffer, length )
	INT	handle;
	BPTR  	buffer;
	INT     length;
{
	INT	transfer=0;
	INT	transfered=0;

	if ( handle < 0 )
		return( length );
	while (length > 0) {

		if (WriteIndent >= 256) {
			WriteIndent = 0;
			if ( write( handle, WriteBuffer, 256 ) != 256 )
				break;
			else	memset(WriteBuffer,0x001A,256);
			}

		if ((transfer = (256 - WriteIndent)) > length )
			transfer = length;

		memcpy((WriteBuffer + WriteIndent),buffer,transfer);
		length -= transfer;
		buffer += transfer;
		WriteIndent += transfer;
		transfered += transfer;
		}
	return( transfered );
}


PUBLIC	INT	FileClose( handle )
	INT	handle;
{
	close( handle );
	return(0);
}

PUBLIC	INT	FileFlush( handle )
	INT	handle;
{
	if ( handle > 0 ) {
		if ( WriteIndent < 256) 
			memset((WriteBuffer+WriteIndent),0x001A,(256 - WriteIndent));
		(VOID) write( handle, WriteBuffer, 256 );
		(VOID) FileClose(handle);
		}
	WriteIndent = 0;
	return( 0 );
}

PUBLIC	INT	FilePurge( handle )
	INT	handle;
{
	if ( handle > 0 ) {
		if ( WriteIndent > 0 ) {
			(VOID) write( handle, WriteBuffer, 256 );
			}
		(VOID) FileClose(handle);
		}
	WriteIndent = 0;
	return( 0 );
}

	/* -------- */
#endif	/* PROLOGUE */
	/* -------- */

PUBLIC	INT	FileGetLine( handle, bptr, blen )
	INT	handle;
	BPTR 	bptr;
	INT	blen;
{
	INT	i=0;
	BYTE	c;
	while ( i < blen ) {
		if ( FileRead(handle, (BPTR) & c, 1) != 1 )
			break;
		else 	{
			switch ( c ) {
				case	'\r'	: continue;
				case	'\n'	: if (!( i )) 
							continue;
				case	0	:
				case	0x001A	: break;
				case	'\t'	: c = ' ';
				default		: *(bptr + i) = c;
						  i++;
						  continue;
				}
			break;
			}
		}
	*(bptr + i) = 0;
	return(i);
}


#endif	/* _FILES_C */
	/* -------- */

