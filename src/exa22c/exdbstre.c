/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSTRE.C 				*/
/*		Date 	:	29/07/1993				*/
/*		Version :	2.1a                     		*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBSTRE_C
#define	_EXDBSTRE_C

#ifdef	PRL3
#define	PROLOGUE
#endif

#ifdef DOS
#include "stdio.h"
#else
#include <stdio.h>
#endif
#include <errno.h>
#include "exos.h"
#include "stdtypes.h"
#include "exdbstre.h"
#include "exdbsymb.h"
#include "allocate.h"
#include "exdbstio.h"
#include "exproto1.h"

static	EXAWORD	StreamSpecial=VRAI;

static	EXABYTE	StreamSearch[64];

#ifdef	OPTIMISEUR
/*	-----------------------------------------------------------	*/
/*	The optimiser uses this source in order to access the debug	*/
/*	symbols. This source is included by the optimiser source	*/
/*	file AOSTREAM.C 						*/
/*	-----------------------------------------------------------	*/

#ifdef	DOS
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#define	OPENRW	(O_RDWR | O_BINARY)
#define	CREATRW	(S_IWRITE | S_IREAD | O_BINARY)
#endif

#ifdef	UNIX
#ifndef	VMS
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define	OPENRW	(O_RDWR | O_BINARY)
#define	CREATRW	(S_IWRITE | S_IREAD | O_BINARY)
#else	/* VMS */
#define	open(Xarg1,Xarg2)		Mopen(Xarg1,Xarg2)
#define	creat(Xarg1,Xarg2)		Mcreat(Xarg1,Xarg2)
#define	close(Xarg1)			Mclose(Xarg1)
#define	read(Xarg1,Xarg2,Xarg3)		Mread(Xarg1,Xarg2,Xarg3)
#define	write(Xarg1,Xarg2,Xarg3)	Mwrite(Xarg1,Xarg2,Xarg3)
#define	lseek(Xarg1,Xarg2,Xarg3)	Mlseek(Xarg1,Xarg2,Xarg3)
#define	unlink(Xarg1)			delete(Xarg1)
#define	OPENRW	1
#define	CREATRW 1
#endif	/* ! VMS 	*/
#endif	/* UNIX  	*/

#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifdef	PROLOGUE
#define	OPENRW	2
#define	CREATRW 2
#endif

#else	/* ! STD_C_CALLS : EXADB MEDIUM ! OPTIMISER */
	/* ---------------------------------------- */

#define	OPENRW 0
#ifdef UNIX
#define CREATRW 0666
#else
#define CREATRW 0
#endif

#ifndef UNIX
EXAWORD	open( BPTR, EXAWORD );
EXAWORD	creat( BPTR, EXAWORD );
EXAWORD	read( EXAWORD, BPTR, EXAWORD );
EXAWORD	write(EXAWORD, BPTR, EXAWORD );
EXALONG	lseek( EXAWORD, EXALONG, EXAWORD );
EXAWORD	close( EXAWORD );
#else
EXAWORD	open();
EXAWORD	creat();
EXAWORD	read();
EXAWORD	write();
EXALONG	lseek();
EXAWORD	close();
#endif

#endif

static	BPTR	StreamFileName=(BPTR) 0;

EXTERN	EXAWORD	err_val;
#ifdef UNIX
EXTERN	int	errno;
#endif

EXAWORD	StreamErrorMsg(vhandle, mptr )
EXAWORD	vhandle;
BPTR	mptr;
{
#ifndef OPTIMISEUR
	db_xpos(1, 1); db_xatb( 21 ); db_xcprintf((BPTR) mptr);
	db_xpos(2, 1); db_xatb( 21 ); 
	display_integer(DebugSymbols->Stream[vhandle].handle);
	db_xputch( ':' );
	display_integer(DebugSymbols->Stream[vhandle].identity);
	db_xputch( ':' );
	display_integer(DebugSymbols->Stream[vhandle].secteur);
	db_xputch( ':' );
	display_integer(DebugSymbols->Stream[vhandle].offset);
	db_xputch( ':' );
	display_integer((EXAWORD) DebugSymbols->Stream[vhandle].line);
	db_xputch( '[' );
	display_integer((EXAWORD) err_val );
	db_xputch( ':' );
	display_integer((EXAWORD) errno );
	db_xputch( ']' );
	db_xpos(3, 1); db_xatb( 21 ); 
	if ( StreamFileName != (BPTR) 0 )
		db_xcprintf((BPTR) StreamFileName );
	else	db_xcprintf((BPTR) "<nullfilename>");
	return( x_getch() );
#else
	return(0);
#endif
}

VOID	set_debug_search_path( lcmdptr )
BPTR	lcmdptr;
{
	while (( *lcmdptr ) && ( *lcmdptr == ' ' ))
		lcmdptr++;
	exadb_strcpy((BPTR) StreamSearch,(BPTR) lcmdptr );
	return;
}

VOID	stream_reset( vhandle )
EXAWORD	vhandle;
{
	DebugSymbols->Stream[vhandle].handle   = EX_UNUSED_HANDLE;
	DebugSymbols->Stream[vhandle].identity = MOINS_UN;
	DebugSymbols->Stream[vhandle].offset   = 0;
	DebugSymbols->Stream[vhandle].secteur  = 0;
	DebugSymbols->Stream[vhandle].limit    = 0;
	DebugSymbols->Stream[vhandle].mode     = 0;
	DebugSymbols->Stream[vhandle].line     = 1;
	return;
}


#ifdef	ABAL_CRITERIA
#include "exdbcrio.c"
#else
#include "exdbstio.c"
#endif

EXAWORD	stream_open(vhandle, nomfic )
EXAWORD	vhandle;
BPTR	nomfic;
{
	EXABYTE	buffer[256];
	EXAWORD	mode=0;
	if ( exadb_strlen( nomfic ) >= 256 )
		return( FAUX );
	exadb_strcpy((BPTR) buffer, (BPTR) nomfic);
	while ( 1 ) {
		if ( ll_stream_open( vhandle, buffer ) )
			return( VRAI );

		if (!( StreamSpecial ))
			return( FAUX );
#ifndef	OPTIMISEUR
		if (!( mode )) {
			if (( exadb_strlen( (BPTR) StreamSearch ) != 0 )
			&&  ( fn_parser((BPTR) nomfic,(BPTR) buffer,0x0007) == 0 )) {
				exadb_strcpy((BPTR) buffer,(BPTR) StreamSearch );
				exadb_strcat((BPTR) buffer,(BPTR) nomfic );
				mode = 1;			
				continue;
				}
			}
		if ( specify_filename( (BPTR) buffer, vhandle ) == FAUX )	
#endif
			return( FAUX );
#ifndef	OPTIMISEUR
		replace_filename_symbol((BPTR) nomfic,(BPTR) buffer );
#endif
		}
}


EXAWORD	stream_close( vhandle )
EXAWORD	vhandle;
{
	ll_stream_close( vhandle );
	return( VRAI );
}

VOID	initialise_streams()
{
	EXAWORD	vhandle;
	for ( vhandle = 0; vhandle < MAXDBSTREAMS; vhandle++ )
		stream_reset( vhandle );		
	return;
}

VOID	terminate_streams()
{
	EXAWORD	vhandle;
	for ( vhandle = 0; vhandle < MAXDBSTREAMS; vhandle++ )
		stream_close( vhandle );
	return;
} 
	
EXAWORD	stream_read( vhandle,secteur, buffer, longueur )
EXAWORD	vhandle;
EXAWORD	secteur;
BPTR	buffer;
EXAWORD	longueur;
{
	if ( valid_stream_handle( vhandle ) ) {
		if ( DebugSymbols->Stream[vhandle].secteur == (secteur+1) ) {
			DebugSymbols->Stream[vhandle].offset = 0;
			return( longueur );
			}
		else	return( ll_stream_read( vhandle, secteur, buffer, longueur ) );
		}
	return( 0 );
}

EXAWORD	stream_seek( vhandle, secteur, offset )
EXAWORD	vhandle;
EXAWORD	secteur;
EXAWORD	offset;
{
	EXAWORD	r;
	if ((r = stream_read( vhandle,secteur,(BPTR) DebugSymbols->Stream[vhandle].buffer, 256)) != 0) {
		DebugSymbols->Stream[vhandle].secteur = ++secteur;
		DebugSymbols->Stream[vhandle].limit   = r;
		DebugSymbols->Stream[vhandle].offset  = offset;
		}
	return( r );
}

EXAWORD	stream_seek_for_write( vhandle, secteur, offset )
EXAWORD	vhandle;
EXAWORD	secteur;
EXAWORD	offset;
{
	EXAWORD	r;
	if ((r = stream_seek( vhandle, secteur, offset )) != 0 )
		DebugSymbols->Stream[vhandle].secteur = secteur;
	return(r);		

}

EXALONG	stream_tell( vhandle )
EXAWORD	vhandle;
{
	EXALONG	where=0L;

	if ( valid_stream_handle( vhandle ) ) {
		if (DebugSymbols->Stream[vhandle].secteur > 0) {
			where = (DebugSymbols->Stream[vhandle].secteur-1);
			where *= 256;
			}
		where += DebugSymbols->Stream[vhandle].offset;
		return( where );
		}
	else	return( -1L );


}

EXALONG	stream_line_tell( vhandle )
EXAWORD	vhandle;
{
	if ( valid_stream_handle( vhandle ) )
		return( DebugSymbols->Stream[vhandle].line );
	else	return( -1L );
}

EXAWORD	stream_file_change( vhandle, idfile )
EXAWORD	vhandle;
EXAWORD	idfile;
{
	if (( valid_stream_handle( vhandle ))
	&&  ( idfile != MOINS_UN )
	&&  ( DebugSymbols->Stream[vhandle].identity == idfile))
		return( FAUX );
	else	return( VRAI );

}

EXAWORD	check_same_stream_file( vhandle, nomfic, idfile )
EXAWORD	vhandle;
BPTR	nomfic;
EXAWORD	idfile;
{
	EXAWORD	result;

	if (!(stream_file_change( vhandle, idfile )))
		return( VRAI );

	(void) stream_close( vhandle );
	if ((result = stream_open( vhandle,(StreamFileName = nomfic) )) != FAUX)
		DebugSymbols->Stream[vhandle].identity = idfile;

	return( result );
}

EXAWORD	stream_getc( vhandle )
EXAWORD	vhandle;
{
	EXAWORD	c;
	if ( valid_stream_handle( vhandle ) ) {
		if ( DebugSymbols->Stream[vhandle].offset  >= DebugSymbols->Stream[vhandle].limit ) {
			if ( stream_seek( vhandle, DebugSymbols->Stream[vhandle].secteur, 0 ) == 0 )
				return( MOINS_UN );
			}
		if (( c = DebugSymbols->Stream[vhandle].buffer[ (DebugSymbols->Stream[vhandle].offset++)]) == '\n' )
			DebugSymbols->Stream[vhandle].line++;
		return( c );
		}
	return( MOINS_UN );	
}

EXAWORD	forward_stream_line( vhandle, number )
EXAWORD	vhandle;
EXALONG	number;
{
	EXAWORD	status;
	while ( DebugSymbols->Stream[vhandle].line < number ) {
		if ((status = stream_getc( vhandle )) == MOINS_UN ) {
			StreamErrorMsg(vhandle,(BPTR) "forward_getc:failure");
			return( FAUX );
			}
		}

	if ( DebugSymbols->Stream[vhandle].line > number )
		return( backward_stream_line( vhandle, number ) );

	return( VRAI );
}

EXAWORD	backward_stream_line( vhandle, number )
EXAWORD	vhandle;
EXALONG	number;
{
	if ( stream_seek( vhandle, 0, 0 ) == 0 ) {
		StreamErrorMsg(vhandle,(BPTR) "backward_seek:failure");	
		return( FAUX );
		}
	else	{
		DebugSymbols->Stream[vhandle].line = 1;
		return( forward_stream_line( vhandle, number ) );
		}
}

EXAWORD	stream_line( vhandle, number )
EXAWORD	vhandle;
EXALONG	number;
{
	if ( DebugSymbols->Stream[vhandle].line == number )
		return( VRAI );
	else if ( DebugSymbols->Stream[vhandle].line < number )
		return( forward_stream_line( vhandle, number ) );
	else	return( backward_stream_line( vhandle, number ) );
}


EXAWORD	stream_position( vhandle, nomfic, offset, idfile, nature )
EXAWORD	vhandle;
BPTR	nomfic;
EXALONG	offset;
EXAWORD	idfile;
EXAWORD	nature;	/* 0 : Lseek positioning, 1 : Line counter */
{
	EXAWORD	nboffs;
	EXAWORD	nbsect;
	EXALONG	number=offset;

	nboffs = (EXAWORD) ( offset & 0x00FF );
	offset >>= 8;
	nbsect = (EXAWORD) ( offset & 0xFFFF);

	if ( check_same_stream_file( vhandle,(StreamFileName = nomfic), idfile ) ) {
		if (!( nature ))
			return( stream_seek( vhandle, nbsect, nboffs ) );
		else	return( stream_line( vhandle, number ) );
		}
	else	return( FAUX );

}


EXAWORD	stream_getb( vhandle )
EXAWORD	vhandle;
{
	if ( valid_stream_handle( vhandle ) ) {
		if ( DebugSymbols->Stream[vhandle].offset  >= DebugSymbols->Stream[vhandle].limit )
			if ( stream_seek( vhandle, DebugSymbols->Stream[vhandle].secteur, 0 ) == 0 )
				return( MOINS_UN );
		return( DebugSymbols->Stream[vhandle].buffer[ (DebugSymbols->Stream[vhandle].offset++)] );
		}
	return( MOINS_UN );	
}

EXAWORD	stream_getw( vhandle )
EXAWORD	vhandle;
{
	EXAWORD	r;
	if ((r = stream_getb( vhandle )) == MOINS_UN)
		return( r );
	return( (( stream_getb(vhandle) * 256 ) + r ) );
}

EXALONG	stream_getl( vhandle )
EXAWORD	vhandle;
{
	EXAWORD	l;
	EXAWORD	h;
	EXALONG	r;

	l = stream_getb( vhandle );
	l +=  (( stream_getb(vhandle) * 256 ) );
	h = stream_getb( vhandle );
	h +=  (( stream_getb(vhandle) * 256 ) );
	r = h; r <<= 16; r += l;
	return( r );
}

EXAWORD	stream_gets( vhandle, buffer, limit )
EXAWORD	vhandle;
BPTR	buffer;
EXAWORD	limit;
{
	EXAWORD	nombre;
	for ( nombre = 0; nombre < limit; nombre++ ) {
		switch ( ( *(buffer + nombre) = stream_getb( vhandle )) ) {
			case  0x00FF	: *(buffer + nombre) = 0;
			case	0  	: return( nombre );
			}
		}
	return( nombre );
}

EXAWORD	stream_create(vhandle, nomfic )
EXAWORD	vhandle;
BPTR	nomfic;
{
	EXABYTE	buffer[256];
	stream_close(vhandle);
	StreamSpecial=FAUX;
	if (stream_open(vhandle,nomfic) != 0) {
		StreamSpecial=VRAI;
		stream_close(vhandle);
#ifndef	OPTIMISEUR
		if (standard_validation((BPTR) "Overwrite existing file ?") ==0)
			return( 0 );
#endif
		ll_stream_unlink( nomfic );
		}
	StreamSpecial=VRAI;
	exadb_strcpy((BPTR) buffer, (BPTR) nomfic);
	if ( ll_stream_create( vhandle, buffer ) == FAUX )
		return( FAUX );
	else	{
		DebugSymbols->Stream[vhandle].identity = MOINS_UN;
		DebugSymbols->Stream[vhandle].secteur= 0;
		DebugSymbols->Stream[vhandle].offset = 0;
		DebugSymbols->Stream[vhandle].limit  = 256;
		return( VRAI );
		}

}

VOID	stream_write(vhandle)
EXAWORD	vhandle;
{
	ll_stream_write( vhandle );
	DebugSymbols->Stream[vhandle].secteur++;
	DebugSymbols->Stream[vhandle].offset = 0;
	DebugSymbols->Stream[vhandle].limit  = 256;
	return;
}


VOID	stream_putb(vhandle, c )
EXAWORD	vhandle;
EXAWORD	c;
{
	DebugSymbols->Stream[vhandle].buffer[ (DebugSymbols->Stream[vhandle].offset++)] = c;
	if ( DebugSymbols->Stream[vhandle].offset  >= DebugSymbols->Stream[vhandle].limit )
		stream_write(vhandle);
	return;
}

VOID	stream_putc(vhandle, c )
EXAWORD	vhandle;
EXAWORD	c;
{
	if ( valid_stream_handle( vhandle ) ) {
		DebugSymbols->Stream[vhandle].buffer[ (DebugSymbols->Stream[vhandle].offset++)] = c;
		if ( DebugSymbols->Stream[vhandle].offset  >= DebugSymbols->Stream[vhandle].limit )
			stream_write(vhandle);
		}
#ifndef OPTIMISEUR
	else	db_xputch( c );
#endif
	return;
}

VOID	stream_padd(vhandle,c)
EXAWORD	vhandle;
EXAWORD	c;
{
	while ( DebugSymbols->Stream[vhandle].offset != 0 )
		stream_putb( vhandle, c );
	return;

}


VOID	stream_flush(vhandle)
EXAWORD	vhandle;
{
#ifndef	UNIX
	do	{
		stream_putb(vhandle, 0x001A );
		}
	while ( DebugSymbols->Stream[vhandle].offset != 0 );
#endif
	if ( DebugSymbols->Stream[vhandle].offset != 0 )
		stream_write(vhandle);
	stream_close(2);
	return;
}

VOID	stream_puti(vhandle, val )
EXAWORD	vhandle;
EXAWORD 	val;
{
	EXABYTE	buffer[6];
	EXAWORD	i=5;
	if ( val == 0 )
		stream_putc(vhandle,'0');
	else	{
		for ( ; val != 0; val /= 10 ) 
			buffer[(i--)] = ((val % 10) + '0');	
		for ( ; i < 5; stream_putc(vhandle, buffer[ ++i ] ) );
		}
	return;
}

VOID	stream_puthb(vhandle, v )
EXAWORD	vhandle;
EXAWORD	v;
{
	v &= 0x000F;
	if ( v > 9 )
		stream_putc(vhandle,((v-10) + 'A'));
	else	stream_putc(vhandle,(v+'0'));
	return;
}

VOID	stream_puth(vhandle, val )
EXAWORD	vhandle;
EXAWORD 	val;
{
	stream_puthb( vhandle,  (val >> 12) );
	stream_puthb( vhandle,  (val >>  8) );
	stream_puthb( vhandle,  (val >>  4) );
	stream_puthb( vhandle,  val );
	return;
}

VOID	stream_puts(vhandle, sptr )
EXAWORD	vhandle;
BPTR 	sptr;
{
	while ( *sptr )
		stream_putc(vhandle, *(sptr++) );
	return;
}

VOID	stream_putzc( vhandle, sptr )
EXAWORD	vhandle;
BPTR	sptr;
{
	stream_puts(vhandle, (BPTR) sptr );
	stream_putc(vhandle, 0 );
	return;
}

VOID	stream_putzs( vhandle, sptr )
EXAWORD	vhandle;
BPTR	sptr;
{
	stream_puts(vhandle, (BPTR) sptr );
	stream_putb(vhandle, 0 );
	return;
}

VOID	stream_putw(vhandle, v )
EXAWORD	vhandle;
EXAWORD	v;
{
	stream_putb(vhandle, (v & 0x00FF) );
	stream_putb(vhandle,((v >> 8) & 0x00FF));   
	return;
}
VOID	stream_putl(vhandle, v )
EXAWORD	vhandle;
EXALONG	v;
{
	stream_putb( vhandle,  (v & 0x000000FF) );
	stream_putb( vhandle, ((v >>  8) & 0x000000FF));   
	stream_putb( vhandle, ((v >> 16) & 0x000000FF));   
	stream_putb( vhandle, ((v >> 24) & 0x000000FF));   
	return;
}

VOID	stream_putlf(vhandle)
EXAWORD	vhandle;
{
	stream_putc(vhandle,'\r');
	stream_putc(vhandle,'\n');
	return;
}

VOID	flush_search_path( vhandle )
EXAWORD	vhandle;
{
	stream_putb(vhandle,'Y');
	stream_puts(vhandle, (BPTR) StreamSearch );
	stream_putb(vhandle,0);
	stream_putlf(vhandle);
	return;
}

#ifdef	PROLOGUE3
#define	PROLOGUE
#endif
#ifdef	PROLOGUE2
#define	PROLOGUE
#endif

#ifdef	PROLOGUE
BPTR	ll_malloc( nb )
EXAWORD	nb;
{
	VPTR	allocate( EXAWORD );

	return( (BPTR) allocate( nb ) );
}

VOID	ll_free( nptr )
BPTR	nptr;
{
	liberate( nptr );
	return;
}
#endif

#endif	/* EXDBSTRE_C */
	/* ---------- */


