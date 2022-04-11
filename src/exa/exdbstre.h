/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSTRE.H 				*/
/*		Date 	:	29/07/1993				*/
/*		Version :	2.1a                     		*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBSTRE_H
#define	_EXDBSTRE_H

#define	_TCODE_STREAM	0
#define	_DEBUG_STREAM	1
#define	_WORK_STREAM	2
#define	_TRACE_STREAM	3
#define	_TEMP_STREAM	4

#define	MAXDBSTREAMS	5

#include "exhandle.h"

#define	_EXTENDED_SECTOR_V1	1
#define	DEBUGSTREAM struct symbolic_stream

struct	symbolic_stream	{
	EX_FILE_HANDLE	handle;
	EXAWORD		secteur;
	EXABYTE		buffer[256];
	EXAWORD		limit;
	EXAWORD		identity;
	EXALONG		line;
	EXAWORD		offset;
	EXAWORD		mode;
	};

extern	EXAWORD	simcbd;

/*	Stream Input  operations	*/
/*	------------------------	*/
#ifndef RT_AIX
EXAWORD	stream_open( EXAWORD, BPTR,WORD );
EXAWORD	stream_close( EXAWORD );
EXAWORD	stream_read( EXAWORD, EXAWORD, BPTR, EXAWORD );
EXAWORD	stream_seek( EXAWORD, EXAWORD, EXAWORD );
EXAWORD	backward_stream_line( EXAWORD, EXALONG );
EXAWORD	forward_stream_line( EXAWORD, EXALONG );
EXAWORD	stream_line( EXAWORD, EXALONG );
EXAWORD	stream_position( EXAWORD, BPTR, EXALONG, EXAWORD, EXAWORD );
EXAWORD	stream_getb( EXAWORD );
EXAWORD	stream_getc( EXAWORD );
EXAWORD	stream_getw( EXAWORD );
EXAWORD	stream_file_change( EXAWORD, EXAWORD );
EXAWORD	stream_gets( EXAWORD, BPTR, EXAWORD );

EXALONG	stream_getl( EXAWORD );
EXALONG	stream_tell( EXAWORD );
EXALONG	stream_line_tell( EXAWORD );

/*	Stream Output operations	*/
/*	------------------------	*/
EXAWORD	stream_create(EXAWORD, BPTR );

VOID	stream_putc(EXAWORD, EXAWORD );
VOID	stream_putb(EXAWORD, EXAWORD );
VOID	stream_puti(EXAWORD, EXAWORD );
VOID	stream_puth(EXAWORD, EXAWORD );
VOID	stream_puts(EXAWORD, BPTR );
VOID	stream_flush(EXAWORD );
VOID	stream_putlf( EXAWORD );


/*	Binary Stream output		*/
/*	--------------------		*/
EXAWORD	stream_seek_for_write( EXAWORD, EXAWORD, EXAWORD );
VOID	stream_putw(EXAWORD, EXAWORD );
VOID	stream_putl(EXAWORD, EXALONG );
VOID	stream_padd(EXAWORD, EXAWORD );	
VOID	stream_putzs( EXAWORD, BPTR );

#else		/* RT_AIX */

EXAWORD	stream_open();
EXAWORD	stream_close();
EXAWORD	stream_read();
EXAWORD	stream_seek();
EXAWORD	backward_stream_line();
EXAWORD	forward_stream_line();
EXAWORD	stream_line();
EXAWORD	stream_position();
EXAWORD	stream_getb();
EXAWORD	stream_getc();
EXAWORD	stream_getw();
EXAWORD	stream_file_change();
EXAWORD	stream_gets();

EXALONG	stream_getl();
EXALONG	stream_tell();
EXALONG	stream_line_tell();

/*	Stream Output operations	*/
/*	------------------------	*/
EXAWORD	stream_create();

VOID	stream_putc();
VOID	stream_putb();
VOID	stream_puti();
VOID	stream_puth();
VOID	stream_puts();
VOID	stream_flush();
VOID	stream_putlf();


/*	Binary Stream output		*/
/*	--------------------		*/
EXAWORD	stream_seek_for_write();
VOID	stream_putw();
VOID	stream_putl();
VOID	stream_padd();
VOID	stream_putzs();

#endif		/* RT_AIX */

#endif	/* _EXDBSTRE_H */
	/* ----------- */


