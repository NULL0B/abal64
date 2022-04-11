/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1997 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRACEMAN.H				*/
/*		Version :	1.1a					*/
/*		Date	:	13/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#define YT131097

#ifndef	_TRACEMAN_H
#define	_TRACEMAN_H

#define	TRACEPTR struct trace_control FPTR

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
	BYTE FPTR	filename;	/* Filename to which it applies	*/
	WORD		colonne;	/* Column of line		*/

	LONG		ligne;		/* Line with error		*/
	BYTE FPTR	message;	/* Message provided		*/

	/* Don't fuck with these bits please */
	/* --------------------------------- */
	LONG		original;	/* Initial file value		*/
	WORD		type;		/* Type of item Error / Warning	*/
	TRACEPTR	previous;	/* Pointer to previous item	*/
	TRACEPTR	next;		/* Pointer to next item		*/

	};

#define Mstrcpy(d,s) strcpy(d,s)
#define Mstrlen(s) strlen(s)
#include "allocate.h"

#ifdef	_TRACEMAN_C

	TRACEPTR	TraceRoot;
	TRACEPTR	TraceItem;

#define	FILEPTR	FILE XPTR

/*   -----------------------------------------------------------------  */
/*   E R R O R   T R A C I N G   F U N C T I O N   P R O T O T Y P E S	*/
/*   -----------------------------------------------------------------  */

WORD		initialise_trace_controller( BYTE FPTR );
VOID		terminate_trace_controller();
TRACEPTR	position_to_first( WORD );
TRACEPTR	position_to_next( WORD );
TRACEPTR	position_to_previous( WORD );
TRACEPTR	position_to_current();

VOID		adjust_trace_information( SWORD , LONG );
VOID		revalidate_trace_information( WORD );
VOID		commit_trace_adjustment();
VOID		forget_trace_adjustment();

WORD		add_trace_item( BYTE FPTR, LONG, WORD, BYTE FPTR );
WORD		Mstrcmp( BYTE FPTR, BYTE FPTR);

static BYTE XPTR Xfgets(BYTE XPTR , WORD , FILE XPTR );
static VOID Xscanf(BYTE XPTR ,  BYTE XPTR, WORD XPTR , WORD XPTR, WORD XPTR );

static VOID XscanfForLong(BYTE XPTR ,  BYTE XPTR, LONG XPTR , WORD XPTR, WORD XPTR );


#ifdef test_alloc
int nb_alloc;
void far * Xallocate( int );
void Xliberate( void far * );
#define	zalloc( a ) Xallocate( a )
#define zfree( a )  Xliberate( a )
#else
#define	zalloc( a ) allocate( a )
#define zfree( a )  liberate( (BYTE FPTR)a )
#endif


#define zstrcmp( a, b ) Mstrcmp( a, b )

#else
	/* Fonctions Extern */

extern WORD		initialise_trace_controller( BYTE FPTR );
extern VOID		terminate_trace_controller();
extern TRACEPTR		position_to_first( WORD );
extern TRACEPTR		position_to_next( WORD );
extern TRACEPTR		position_to_previous( WORD );
extern TRACEPTR		position_to_current();


extern VOID		adjust_trace_information( SWORD , LONG );

extern VOID		revalidate_trace_information( WORD );
extern VOID		commit_trace_adjustment();
extern VOID		forget_trace_adjustment();
extern WORD		add_trace_item();
extern WORD		Mstrcmp();
#endif /* _TRACEMAN_C */
#endif /* _TRACEMAN_H */

	/* ----------- */





