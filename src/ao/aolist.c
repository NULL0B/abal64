/* -------------------------------------------------------------------- */
/*									*/
/*		Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		-------------------------------------			*/
/*									*/
/*	Project :	Optimiser/Compiler/Dissassembler		*/
/*	---------	--------------------------------		*/
/*									*/
/*	Module	:	AOLIST.C					*/
/*	Version :	2.1b						*/
/*	Date	:	11/05/1994					*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_LISTFILE_C
#define	_LISTFILE_C

#define	LISTFILE
				/* ------------------------------------ */
#include "aomain.h"		/* General definitions			*/
#include "aolist.h"		/* File access definitions		*/
				/* ------------------------------------ */
#ifndef	BLOCK
#define	BLOCK	256
#endif

/*	Variable declarations		*/
/*	---------------------		*/
EXAWORD	OutPutStatus;

struct	outstream {
	BPTR	stream_name;
	EXAWORD	stream_handle;
	EXAWORD	stream_block;
	EXAWORD	stream_byte;
	BYTE	stream_buffer[BLOCK];
	} OutStream;

/*	External Function Prototypes	*/
/*	----------------------------	*/
#ifndef	UNIX
extern	EXAWORD	Access( BPTR , EXAWORD , EXAWORD );
#else
extern	EXAWORD	Access();
void	HexWord();
#endif

/*	Initialisation of Stream output Controller	*/
/*	------------------------------------------	*/
void	OutPutInit()
{
	/* Indicate no current Output */
	/* -------------------------- */	
	OutStream.stream_name   = (BPTR) 0;
	OutStream.stream_handle = 0;
	OutStream.stream_block  = 0;
	OutStream.stream_byte   = 0;
	OutPutStatus = CONSOLE_OUTPUT;
	return;
}

/*	Output of stream buffer		*/
/*	-----------------------		*/
void	StreamFlush()
{
	(void) write( OutStream.stream_handle , (BPTR) OutStream.stream_buffer , OutStream.stream_byte );
	OutStream.stream_block++;
	OutStream.stream_byte = 0;
	return;
}

#ifdef	AO_LISTFILE

/*	List stream output file Close function		*/
/*	--------------------------------------		*/
void	OutPutClose()
{
	/* Check for Close not already done */
	/* -------------------------------- */
	if ( OutPutStatus == FILE_OUTPUT ) {

		/* Check for buffer flush needed */
		/* ----------------------------- */
		if ( OutStream.stream_byte > 0 ) {
#ifdef	PRL
			/* Perform Buffer flush with Ctrl Z */
			/* -------------------------------- */
			while ( OutStream.stream_byte < BLOCK ) {
				OutStream.stream_buffer [ (OutStream.stream_byte++) ] = (BYTE) CTRLZ;
				}
#endif
			/* Flush the Buffer to the File */
			/* ---------------------------- */
			StreamFlush();

			}

		/* Close the file now */
		/* ------------------ */
		close ( OutStream.stream_handle );
	
		/* Liberate the file name Buffer */
		/* ----------------------------- */
		free ( OutStream.stream_name ); 

		/* Re-Initialise for possible next user */
		/* ------------------------------------ */
		OutPutInit();

		}
	return;
}

/*	Creation of a list stream output file		*/
/*	-------------------------------------		*/
void	OutPutCreate( filename )
BPTR	filename;
{
	/* Close the current if it Exists */
	/* ------------------------------ */
	if ( OutPutStatus == FILE_OUTPUT ) {
		OutPutClose();
		}

	/* Attempt buffer allocation */
	/* ------------------------- */
	if ((OutStream.stream_name = (BPTR) malloc ( (strlen((BPTR) filename ) + 1) )) != (BPTR) 0) {

		/* Store filename in Buffer */
		/* ------------------------ */
		memcpy( (BPTR) OutStream.stream_name , (BPTR) filename , (strlen((BPTR) filename ) + 1));

		/* Attempt to establish Exclusive Access rights */
		/* -------------------------------------------- */
		if ( Access (OutStream.stream_name,0,1) == 0 ) {

			/* Remove existing file */
			/* -------------------- */
			unlink ( OutStream.stream_name );

			}

		/* Attempt to create the file */
		/* -------------------------- */
		if ((OutStream.stream_handle = creat ( OutStream.stream_name , CREATRW )) != -1 ) {

			close( OutStream.stream_handle );
			OutStream.stream_handle = open ( OutStream.stream_name , OPENRW );

			/* Indicate Valid Stream Context */
			/* ----------------------------- */
			OutPutStatus = FILE_OUTPUT;

			/* SUCCESS file open */
			/* ----------------- */
			return;

			}

		/* Liberate the buffer */
		/* ------------------- */
		free ( OutStream.stream_name );

		/* Indicate In-Valid Stream Context */
		/* -------------------------------- */
		OutPutStatus = CONSOLE_OUTPUT;
		}

	return;
}

#endif	/* AO_LISTFILE */
	/* ----------- */

void	StreamByte( s )
EXAWORD	s;
{
	if ( OutPutStatus == FILE_OUTPUT ) {

		/* Check for Flush Needed */
		/* ---------------------- */
		if ( OutStream.stream_byte >= BLOCK ) {
			StreamFlush();
			}

		/* Place character on output stream */
		/* -------------------------------- */
		OutStream.stream_buffer[ (OutStream.stream_byte++) ] = (BYTE) s;
		}
	else if ( OutPutStatus == CONSOLE_OUTPUT )
			printf("%c",s);

	return;

}

void	StreamString( sptr )
BPTR	sptr;
{
	/* Send all characters up to Terminator */
	/* ------------------------------------ */
	while ( *sptr != (BYTE) 0 ) {
		StreamByte((EXAWORD) *(sptr++) );
		}
	return;
}

void	StreamLine()
{
#ifndef	UNIX
#ifndef	VMS
	StreamByte( '\r' );
#endif
#endif
	StreamByte( '\n' );
	return;
}

EXAWORD	StreamStatus( type )
EXAWORD	type;
{
	EXAWORD	x;
	x = OutPutStatus;
	OutPutStatus = type;
	return( x );
}

/*
 *	D e c i m a l W o r d ( word_value )
 *	------------------------------------
 *
 *	Displays a decimal word with format : ($)
 *
 */

void	DecimalWord( x )
EXAWORD	x;
{
	EXAWORD	n;
	EXAWORD	f;
	BYTE	buffer[64];
	if ( x == 0 ) { 
		StreamByte('0'); 
		}
	else	{
#ifdef	VERSION666
#ifdef ABAL64
		sprintf(buffer,"%llu",x);
#else
		sprintf(buffer,"%lu",x);
#endif
		StreamString(buffer);
#else
		for (f = 0, n = 10000; n > 0; n /= 10 ) {
			if ((( x / n ) > 0 ) || ( f != 0)) {
				StreamByte((( x / n) | 0x0030));
				f = 1;
				}
			x %= n;
			}
#endif
		}
	return;
}

/*
 *	H e x a O c t e t ( word_value )
 *	--------------------------------
 *	
 *	Display a hex byte with format : (HZ2)
 *
 */

void	HexaOctet( hexval )
EXAWORD	hexval;
{
	if (( hexval & 0x00F0 ) > 0x0090 ) {
		StreamByte( ((((hexval >> 4) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 4) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x000F ) > 0x0009 ) {
		StreamByte( (((hexval & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval & 0x000F) ) + 0x0030)    );
		}
	return;
}

/*
 *	H e x L o n g ( long_value )
 *	----------------------------
 *
 * Displays a Hexa Long Word With Format (HZ8,X)
 *
 */

void	HexLong( v )
long	v;
{
	union redef_long {
		long	v_long;
		EXAWORD	v_short[2];
		} llvalue;

	llvalue.v_long = v;
	HexWord( llvalue.v_short[1] ); HexWord( llvalue.v_short[0] );	
	StreamByte(' ');
	return;
}

#ifdef	VERSION666
/*
 *	H e x W o r d ( word_value )
 *	----------------------------
 *
 *	Displays a Hexa Word With Format (HZ?),((WORDSIZE))
 *
 */
void	HexOut( hexval )
EXAWORD	hexval;
{
	if (( hexval & 0xF000 ) > 0x9000 ) {
		StreamByte( ((((hexval >> 12) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 12) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x0F00 ) > 0x0900 ) {
		StreamByte( ((((hexval >> 8) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 8) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x00F0 ) > 0x0090 ) {
		StreamByte( ((((hexval >> 4) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 4) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x000F ) > 0x0009 ) {
		StreamByte( (((hexval & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval & 0x000F) ) + 0x0030)    );
		}
}
#endif
void	HexWord( hexval )
EXAWORD	hexval;
{
#ifdef	VERSION666
	EXAWORD	mexval;
	if ( WORDSIZE > 4 )
	{
		mexval = (hexval >> 48);
		HexOut( mexval );		
		mexval = (hexval >> 32);
		HexOut( mexval );		
	}
	if ( WORDSIZE > 2 ) 
	{
		mexval = (hexval >> 16);
		HexOut( mexval );		
	}
	HexOut( hexval );
#else
	if (( hexval & 0xF000 ) > 0x9000 ) {
		StreamByte( ((((hexval >> 12) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 12) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x0F00 ) > 0x0900 ) {
		StreamByte( ((((hexval >> 8) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 8) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x00F0 ) > 0x0090 ) {
		StreamByte( ((((hexval >> 4) & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval >> 4) & 0x000F) + 0x0030)    );
		}
	if (( hexval & 0x000F ) > 0x0009 ) {
		StreamByte( (((hexval & 0x000F) - 10) + 0x0041)    );
		}
	else	{
		StreamByte( (((hexval & 0x000F) ) + 0x0030)    );
		}
#endif
	return;
}


/*
 *	H e x A d r e s s e ( wod_value )
 *	---------------------------------
 *
 *	Displays a Hex word with Format : ("(",HZ4,")",X)
 *
 */

void	HexAdresse( hexval )
EXAWORD	hexval;
{
	StreamByte('('); HexWord( hexval ); StreamByte(')'); StreamByte(' ');
	return;
}

void	procedure_verbose( procid )
EXAWORD	procid;
{
	StreamString("Procedure : ");
	HexWord( procid );
	StreamLine();
}

void	segment_verbose( segmid )
EXAWORD	segmid;
{
	StreamString("Segment   : ");
	DecimalWord( segmid );
	StreamLine();
}

	

#endif	/* _LISTFILE_C */
	/* ----------- */

