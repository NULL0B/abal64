/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBTRAC.C				*/
/*		Date 	:	16/08/1993				*/
/*		Version :	2.1a 					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBTRACE_C
#define	_EXDBTRACE_C
#define DEBUGGER
#include "exctype.h"
#include "exdebug.h"
#include "exdbstre.h"
#include "exdbctrl.h"
#include "allocate.h"
#include "exdbmimo.h"
#include "exdbffff.h"

EXTERN	EXABYTE	trad_ver;
EXTERN	BPTR	TalkPtr[];		/* GesMes Messages array	*/
#ifndef UNIX
EXTERN	BPTR	CmdShift(BPTR);		/* Removal of White Space	*/
EXTERN	BPTR	interface_message( EXAWORD );
EXTERN	VOID	Verbose(BPTR);
EXTERN	VOID	trace_all_symbols(EXAWORD);
EXTERN	EXAWORD	get_procedure_number(BPTR);
EXTERN	EXAWORD	ProcNumb(BPTR);
EXTERN	VOID	left_string(EXAWORD,EXAWORD,EXAWORD,BPTR);
EXTERN	VOID    db_xputch(EXAWORD);
EXTERN	VOID    db_xcprintf(BPTR);
EXTERN	VOID	display_hexint(EXAWORD);
EXTERN	VOID	symbolic_atribut(EXAWORD);
EXTERN	EXAWORD	tcode_correspondance(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
EXTERN	BPTR	exadb_strcpy( BPTR, BPTR );
EXTERN	BPTR	exadb_strcat( BPTR, BPTR );
EXTERN	EXAWORD	display_integer(EXAWORD);
EXTERN	EXAWORD	current_mouse_click(VOID);
EXTERN	VOID	mouse_title_box(EXAWORD,EXAWORD,EXAWORD,EXAWORD,BPTR);
EXTERN	VOID	pop_mouse(VOID);
EXTERN	EXAWORD	mouse_or_keyboard( VOID );
EXTERN	VOID    db_xpos(EXAWORD,EXAWORD);
#else
EXTERN	BPTR	CmdShift();		/* Removal of White Space	*/
EXTERN	BPTR	interface_message();
EXTERN	VOID	Verbose();
EXTERN	VOID	trace_all_symbols();
EXTERN	EXAWORD	get_procedure_number();
EXTERN	EXAWORD	ProcNumb();
EXTERN	VOID	left_string();
EXTERN	VOID    db_xputch();
EXTERN	VOID    db_xcprintf();
EXTERN	VOID	symbolic_atribut();
EXTERN	EXAWORD	tcode_correspondance();
EXTERN	BPTR	exadb_strcpy();
EXTERN	BPTR	exadb_strcat();
EXTERN	EXAWORD	display_integer();
EXTERN	EXAWORD	current_mouse_click();
EXTERN	VOID	mouse_title_box();
EXTERN	VOID	pop_mouse();
EXTERN	EXAWORD	mouse_or_keyboard();
EXTERN	VOID    db_xpos();
#endif
#define	REGIONPTR	struct debug_trace_entry PTR
#define	TRACE_BUFFER_SIZE	256

struct	debug_trace_entry	{
	EXAWORD		type;
	EXAWORD		identity;
	EXAWORD		start;
	EXAWORD		finish;
	REGIONPTR	next;
	REGIONPTR	previous;
	};

struct	trace_controller {
	REGIONPTR	regions;
	EXAWORD		status;
	EXABYTE		filename[ 64 ];
	};

struct	trace_controller DbTrace;	

EXAWORD	trace_is_active()
{
	return( DbTrace.status );
}

void	initialise_file_control()
{
	DbTrace.status      = 0;
	memset((BPTR) DbTrace.filename, 0, 64 );
	return;
}

VOID	terminate_file_control()
{
	if ( strlen( DbTrace.filename ) != 0 )
		stream_flush( _TRACE_STREAM );
	initialise_file_control();

}

void	initialise_trace_control()
{
	DbTrace.regions     = (REGIONPTR) 0;
	initialise_file_control();
	return;
}

VOID	liberate_trace_control()
{
	REGIONPTR	ltrace;

	if ( strlen( DbTrace.filename ) != 0 )
		stream_flush( _TRACE_STREAM );

	while ((ltrace = DbTrace.regions) != (REGIONPTR) 0 ) {
		DbTrace.regions = DbTrace.regions->next;
		liberate( ltrace );
		}
	initialise_trace_control();
	return;
}

VOID	edit_trace_file(cmdptr)
BPTR	cmdptr;
{
	EXAWORD	l;
	VOID	standard_text_editor(BPTR);
	
	if ((l = strlen( DbTrace.filename )) != 0 ) {
		stream_flush( _TRACE_STREAM );
		initialise_file_control();
		}

	if ((l =  strlen((BPTR) (cmdptr = (BPTR) CmdShift( (BPTR) cmdptr )))) != 0 )
		standard_text_editor( (BPTR) cmdptr );
	return;
}

void	activate_trace_control( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	l;
	/* Establish trace file if name provided */
	/* ------------------------------------- */

	if ((l=  strlen((cmdptr = CmdShift( cmdptr )))) != 0 ) {
		terminate_file_control();
		if ( stream_create( _TRACE_STREAM, (BPTR) cmdptr ) == 0 ) {
			Verbose((BPTR) interface_message( 56 ) );
			return;
			}
		else	memcpy((BPTR) DbTrace.filename,(BPTR) cmdptr, (l+1));
		}


/*  	if (( DbTrace.regions != (REGIONPTR) 0 )
	&&  (strlen( (BPTR) DbTrace.filename ) != 0)) {	*/
		DbTrace.status = 1;
		Verbose((BPTR) interface_message( 57 ) );
/*		} */
	
	return;
}

VOID	remove_trace_entry( ltrace )
REGIONPTR	ltrace;
{
	if ( ltrace != (REGIONPTR) 0 ) {
		if ( ltrace->previous != (REGIONPTR) 0)
			ltrace->previous->next = ltrace->next;
		else	DbTrace.regions        = ltrace->next;
		if ( ltrace->next != (REGIONPTR) 0)
			ltrace->next->previous = ltrace->previous;
		liberate( ltrace );
		}
	return;
}

REGIONPTR	allocate_for_region(type)
EXAWORD		type;
{
	REGIONPTR	ltrace;

	/* Allocate trace control entry structure */
	/* -------------------------------------- */
	if ((ltrace = (REGIONPTR) allocate( sizeof ( struct debug_trace_entry ) )) != (REGIONPTR) 0) {

		/* Establish general region */
		/* ------------------------ */
		ltrace->start    = 0;
		ltrace->finish   = EXDB_FFFF;
		ltrace->type     = type;
		ltrace->identity = EXDB_FFFF;
		ltrace->previous = (REGIONPTR) 0;

		}
	return( ltrace );
}

VOID	add_to_region_list( ltrace )
REGIONPTR	ltrace;
{
	if ( ltrace != (REGIONPTR) 0 ) {
		if ((ltrace->next = DbTrace.regions) != (REGIONPTR) 0)
			ltrace->next->previous = ltrace;
		DbTrace.regions    = ltrace;
		Verbose((BPTR)interface_message( 58 ) );
		}
	return;
}

VOID	add_trace_region( type, identity, debut, offset )
EXAWORD	type;
EXAWORD	identity;
EXAWORD	debut;
EXAWORD	offset;
{
	REGIONPTR	ltrace;

	if ( (ltrace = allocate_for_region( type )) != (REGIONPTR) 0 ) {
		ltrace->identity = identity;
		ltrace->start    = debut;
		ltrace->finish   = offset;
		add_to_region_list( ltrace );
		}
	return;
}

EXAWORD	is_traced_region( type, identity, adresse )
EXAWORD	type;
EXAWORD	identity;
EXAWORD	adresse;
{
	REGIONPTR	ltrace;
	
	if ((ltrace = DbTrace.regions) != (REGIONPTR) 0) {
		do	{
			if (( ltrace->type == type         ) 
			&&  ( ltrace->identity == identity )
			&&  ( adresse >= ltrace->start     )
			&&  ( adresse <= ltrace->finish    )) 
				return(1);
			}
		while (( ltrace = ltrace->next ) != (REGIONPTR) 0 );
		}
	return(0);
}

VOID	add_trace_entry( cmdptr, type )
BPTR	cmdptr;
EXAWORD	type;
{
	REGIONPTR	ltrace;
	BPTR		wptr;
	BPTR		xptr;
	BPTR		yptr;

	/* Remove white space */
	/* ------------------ */
	cmdptr = CmdShift( cmdptr );

	if ( *cmdptr == 0 )
		return;

	else if ( *cmdptr == '*' ) {
		trace_all_symbols( type );
		return;
		}

	/* Allocate and initialise a region structure */
	/* ------------------------------------------ */
	if ((ltrace = allocate_for_region( type )) == (REGIONPTR) 0)
		return;

	/* Scan past code block identity */
	/* ----------------------------- */
	wptr = cmdptr; 
	while (( *cmdptr != ':' ) && ( *cmdptr != 0 )) 
		cmdptr++;
	
	/* Check for and collect explicite region */
	/* -------------------------------------- */
	if ( *cmdptr != 0) {

		/* Terminate code block identity */
		/* ----------------------------- */  
		*(cmdptr++) = 0;

		/* Scan past start offset */
		/* ---------------------- */
		xptr = cmdptr;
		while (( *cmdptr != ',' ) && ( *cmdptr != 0 )) 
			cmdptr++;
	
		/* Check for and collect explicite finish */
		/* -------------------------------------- */
		if ( *cmdptr != 0) {

			/* Terminate start offset */
			/* ---------------------- */  
			*(cmdptr++) = 0;

			/* Scan past finish offset */
			/* ----------------------- */
			yptr = cmdptr;
			while (( *cmdptr != ' ' ) && ( *cmdptr != 0 ))
				cmdptr++;
		
			/* Terminate finish offset */
			/* ----------------------- */
			if ( *cmdptr != 0 )
				*(cmdptr++) = 0;

			ltrace->finish = hextoi( (BPTR) yptr, strlen( yptr ));
 
			}

		ltrace->start = hextoi( (BPTR) xptr, strlen( xptr ));

		}

	/* Collect Segment Number or Procedure Name/Offset */
	/* ----------------------------------------------- */
	if ( type == 'S' )

		/* Convert and collect SEGMENT NUMBER */
		/* ---------------------------------- */
		ltrace->identity = atoi(wptr,strlen( wptr ));

	else	{
		/* Collect PROCEDURE NUMBER */
		/* ------------------------ */
		if ( trad_ver > '1' )
			ltrace->identity = get_procedure_number( (BPTR) wptr );
		else	ltrace->identity = ProcNumb((BPTR) wptr );
		if ( ltrace->identity == MOINS_UN ) {

			liberate( ltrace );
			/*  "Procedure Name Not Found" */
			/* --------------------------  */
			Verbose((BPTR)TalkPtr[63]);
			return;
			}
		}

	/* Add to list of trace regions */
	/* ---------------------------- */
	add_to_region_list( ltrace );

	return;

}

VOID	output_trace_information( type, identity, adresse )
EXAWORD	type;
EXAWORD	identity;
EXAWORD	adresse;
{
	BPTR	get_procedure_name( EXAWORD );
	switch ( type ) {
		case 'p' :
		case 'P' : stream_puts(_TRACE_STREAM,(BPTR) get_procedure_name(identity) );
			   break;
		case 's' :
		case 'S' : stream_puti( _TRACE_STREAM, identity ); 
			   break;
		}
	stream_putc( _TRACE_STREAM, ':' );
	stream_puth( _TRACE_STREAM, adresse );
	stream_putlf( _TRACE_STREAM );
	return;
}

VOID	trace_manager( type, identity, adresse )
EXAWORD	type;
EXAWORD	identity;
EXAWORD	adresse;
{

	/* If tracing active and valid regions list */
	/* ---------------------------------------- */
	if (( DbTrace.status ) 
	&&  ( is_traced_region( type, identity, adresse) != 0 ))
		output_trace_information( type, identity, adresse );
	return;
}


/*
 *	T R A C E _ I T E M _ L I N K A G E 
 *	-----------------------------------
 *	Called from motor execution cycle every newline for possible
 *	TRACE information generation.
 *
 *	NB : Do not modify "offset" since the assemble motor will POP
 *	     this value into its SI as the current TCODE OFFSET !!!
 *
 */

VOID	trace_item_linkage(offset)
EXAWORD	offset;
{
	/* Ensure tracing active */
	/* --------------------- */
	if (( DbTrace.status == 0 )
	||  ( DbTrace.regions == (REGIONPTR) 0 ))
		return;

	if ( sicico & ONSEM_PRC )
		trace_manager( (EXAWORD) 'P', (procid * 16), offset );
	else	trace_manager( (EXAWORD) 'S', cur_seg, offset );
	return; 

}

VOID	display_trace_item(topcol,toplin,nbcol,ltrace)
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
REGIONPTR	ltrace;
{
	BPTR	get_procedure_name( EXAWORD );

	left_string( topcol, toplin, nbcol, (BPTR) " " );

	if ( ltrace != (REGIONPTR) 0) {
		db_xpos( toplin, topcol );
		db_xputch( ltrace->type );
		db_xputch( ' ' );
		if ( ltrace->type == 'P' )
			db_xcprintf( (BPTR) get_procedure_name( ltrace->identity ) );
		else	display_integer( ltrace->identity );
		db_xputch(':');
		display_hexint( ltrace->start );
		db_xputch(',');
		display_hexint( ltrace->finish );
		}
	return;
}

VOID	display_trace_page(topcol,toplin,nbcol,nblin,ltrace)
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
EXAWORD	nblin;
REGIONPTR	ltrace;
{
	EXAWORD	entry;
	symbolic_atribut(0);
	for ( entry = 0; entry < nblin; entry++ ) {
		if ( ltrace == (REGIONPTR) 0 )
			break;
		display_trace_item(topcol,toplin+entry, nbcol, ltrace );
		ltrace = ltrace->next;
		}
	for ( ; entry < nblin; entry++ )
		left_string(topcol,(toplin+entry),nbcol,(BPTR) " ");
	return;
}

VOID	show_trace_region( ltrace )
REGIONPTR	ltrace;
{
	if ( ltrace != (REGIONPTR) 0) {
		if ( ltrace->type == 'P' )
			(void) tcode_correspondance( 1, ltrace->identity, ltrace->start, 2 );
		else	(void) tcode_correspondance( 0, ltrace->identity, ltrace->start, 2 );
		}
	return;
}

VOID	traced_regions_list()
{
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
	EXAWORD	nbcol=30;
	EXAWORD	nblin=13;
	EXAWORD	entry=0;
	REGIONPTR	ltrace;
	REGIONPTR	xtrace;
	EXAWORD	c;
	EXABYTE	regtitre[64];

	if ( DbTrace.regions == (REGIONPTR) 0 )
		return;
	exadb_strcpy((BPTR) regtitre, (BPTR) interface_message( 59 ) );
	if ((c = strlen( (BPTR) DbTrace.filename )) != 0 ) {
		exadb_strcat((BPTR) regtitre,(BPTR) ":" );
		exadb_strcat((BPTR) regtitre,(BPTR) DbTrace.filename );
		}
	mouse_title_box( topcol,toplin, nbcol, nblin, (BPTR) regtitre);
	display_trace_page((topcol+1),(toplin+1), nbcol, nblin, DbTrace.regions );
	ltrace = xtrace = DbTrace.regions;
	while ( 1 ) {
		symbolic_atribut(2);
		display_trace_item((topcol+1),(toplin+1+entry), nbcol, xtrace );
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		display_trace_item((topcol+1),(toplin+1+entry), nbcol, xtrace );
		switch ( c ) {
			case	0x001B :
				pop_mouse();
				return;

			case	CTRL_C :
				for ( c = 0; c < (nblin /2); c++ ) {
					if ((xtrace != (REGIONPTR) 0)
					&&  (xtrace->next != (REGIONPTR) 0)) {
						xtrace = xtrace->next;
 						ltrace = ltrace->next;
						}
					else	break;
					}
				break;

			case	CTRL_R :
				for ( c = 0; c < (nblin /2); c++ ) {
					if ((ltrace != (REGIONPTR) 0)
					&&  (ltrace->previous != (REGIONPTR) 0)) {
						xtrace = xtrace->previous;
 						ltrace = ltrace->previous;
						}
					else	break;
					}
				break;

			case	CTRL_E :
				if ((xtrace != (REGIONPTR) 0)
				&&  (xtrace->next != (REGIONPTR) 0)) {
					xtrace = xtrace->next;
					if ( entry < (nblin-1) )
						entry++;
					else	{
						ltrace = ltrace->next;
						break;
						}
					}
				continue; 
			case	CTRL_K :
				if ((xtrace != (REGIONPTR) 0)
				&&  (xtrace->previous != (REGIONPTR) 0)) {
					xtrace = xtrace->previous;
					if ( entry > 0 )
						entry--;
					else	{
						ltrace = ltrace->previous;
						break;
						}
					}
				continue; 
			case	CTRL_D :
				if ( DbMouse.position == 0 )
					continue;
				entry++;
				if ( DbMouse.position < entry ) {
					for ( ;DbMouse.position < entry; entry--  ) {
						if (( xtrace != (REGIONPTR) 0 )
						&&  ( xtrace->previous != (REGIONPTR) 0 ))
							xtrace = xtrace->previous;
						else	{
							entry--; continue;
							}
						}
					}
				else	{
					for ( ;entry < DbMouse.position; entry++  ) {
						if (( xtrace != (REGIONPTR) 0 )
						&&  ( xtrace->next != (REGIONPTR) 0 ))
							xtrace = xtrace->next;
						else	{
							entry--; continue;
							}
						}
					}
				entry--;

				if ( current_mouse_click() != 2 )
					continue;

			case	CTRL_M :
				pop_mouse();
				show_trace_region( xtrace );
				mouse_title_box( topcol,toplin, nbcol, nblin, (BPTR) regtitre);
				break;

			case	CTRL_Y :
				remove_trace_entry( xtrace );
				if ( DbTrace.regions == (REGIONPTR) 0 ) {
					pop_mouse();
					return;
					}

			case	CTRL_L :
				ltrace = xtrace = DbTrace.regions;
				entry = 0;
				break;
			} 		
		display_trace_page((topcol+1),(toplin+1), nbcol, nblin, ltrace );
		}
}

VOID	disable_trace_control()
{
	DbTrace.status = 0;
	return;
}

/*
 *	T R A C E _ C O N T R O L ( )
 *	-----------------------------
 *	Debug trace mode control syntax analyser and dispatcher
 *
 *	TA			activate tracing
 *	TD			disable  tracing
 *	TS			specify tracing in segment list
 *	TP			declare tracing in procedure list
 *	TI			cancel all trace regions
 *	TL			display list of traced regions
 */

void	trace_control( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	c;

	/* Remove white space */
	/* ------------------ */
	cmdptr = CmdShift( cmdptr );

	/* Collect Next Byte */
	/* ----------------- */
	c = toupper(*cmdptr); cmdptr++;

	/* Analysis of trace command */
	/* ------------------------- */
	switch ( c ) {
		case 'S' :	/* Segment Trace declaration 	*/
		case 'P' :	/* Procedure Trace declaration	*/
			add_trace_entry( cmdptr, c );
			break;
		case 'A'  :	/* Activate tracing		*/
			activate_trace_control( cmdptr );
			break;
		case 'D' :	/* Disable tracing		*/
			disable_trace_control();
			break;
		case 'I' :	/* Cancel all trace entries	*/
			terminate_file_control();
			liberate_trace_control();
			break;
		case 'E' :
			edit_trace_file((BPTR) cmdptr );
			break;
		case 'L' :
			traced_regions_list();
			break;
		}
	return;
}


VOID	flush_trace_list( vh )
EXAWORD	vh;
{
	REGIONPTR	ltrace;
	BPTR		get_procedure_name( EXAWORD );

	if ((ltrace = DbTrace.regions ) != (REGIONPTR) 0) {
		do	{
			if ( ltrace->type == 'P' ) {
				stream_putb(vh,'T');
				stream_putb(vh,'P');
				stream_puts(vh,(BPTR) get_procedure_name( ltrace->identity ));
				}
			else	{
				stream_putb(vh,'T');
				stream_putb(vh,'S');
				stream_puti(vh,ltrace->identity);
				}
			stream_putb(vh,':');
			stream_puth(vh,ltrace->start);
			stream_putb(vh,',');
			stream_puth(vh,ltrace->finish);
			stream_putlf(vh);
			}
		while ((ltrace = ltrace->next) != (REGIONPTR) 0);
		}

	/* Then Check for Declared trace filename */
	/* -------------------------------------- */
	if ( strlen( DbTrace.filename ) != 0 ) {
		stream_putb( vh, 'T' );
		stream_putb( vh, 'A' );
		stream_puts( vh,(BPTR) DbTrace.filename );
		stream_putlf(vh);
		}
	return;	

}

#endif	/* _EXDBTRACE_C */
	/* ------------ */
