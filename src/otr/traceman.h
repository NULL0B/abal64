/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRACEMAN.H				*/
/*		Version :	1.1a					*/
/*		Date	:	13/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRACEMAN_H
#define	_TRACEMAN_H

#define	TRACEPTR struct trace_control XPTR	

#define	ERRORTYPE	0x0001
#define	WARNINGTYPE	0x0002
#define	USERTYPE	0x0004
#define	ANYTYPE		0x0007
#define	INVALID_ITEM	0x8000
#define	VRAI	1
#define	FAUX	0

/*	TRACE ITEM CONTROL STRUCTURE DEFINITION		*/
/*	---------------------------------------		*/

struct	trace_control	{

	/* These are PUBLIC elements */
	/* ------------------------- */
	BPTR		filename;	/* Filename to which it applies	*/
	WORD		colonne;	/* Column of line		*/
	WORD		ligne;		/* Line with error		*/
	BPTR		message;	/* Message provided		*/

	/* Don't fuck with these bits please */
	/* --------------------------------- */
	WORD		original;	/* Initial file value		*/
	WORD		type;		/* Type of item Error / Warning	*/
	TRACEPTR	previous;	/* Pointer to previous item	*/
	TRACEPTR	next;		/* Pointer to next item		*/

	};

#ifdef	_TRACEMAN_C

	TRACEPTR	TraceRoot;
	TRACEPTR	TraceItem;

#define	FILEPTR	FILE XPTR

#endif

/*   -----------------------------------------------------------------  */
/*   E R R O R   T R A C I N G   F U N C T I O N   P R O T O T Y P E S	*/
/*   -----------------------------------------------------------------  */

WORD		initialise_trace_controller( BPTR );
VOID		terminate_trace_controller();
TRACEPTR	position_to_first( WORD );
TRACEPTR	position_to_next( WORD );
TRACEPTR	position_to_previous( WORD );
TRACEPTR	position_to_current();
VOID		adjust_trace_information( WORD , WORD );
VOID		revalidate_trace_information( WORD );
VOID		commit_trace_adjustment();
VOID		forget_trace_adjustment();


#define	zalloc( a ) malloc( a )
#define zfree( a )  free( a )
#define zstrcmp( a, b ) strcmp( a, b )

#endif	/* _TRACEMAN_H */
	/* ----------- */

