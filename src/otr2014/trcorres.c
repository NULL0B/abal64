#ifndef	_TRCORRES_C
#define	_TRCORRES_C

#include "trcorres.h"

static	TCLINKPTR	LinksFree=(TCLINKPTR) 0;
static	TCLINKPTR	LinksUsed=(TCLINKPTR) 0;
static	WORD		LastOutputBytes=MOINS_UN;
static	WORD		Correspondances=0;
static struct tcode_source_link Correspondance;

VOID	drop_correspondances()
{
	TCLINKPTR	lptr;
	trace("drop_correspondances()\n");
	while ((lptr = LinksUsed) != (TCLINKPTR) 0) {
		LinksUsed = lptr->next;
		lptr->next = LinksFree;
		LinksFree  = lptr;
		}
	return;
}

TCLINKPTR	allocate_tcode_link()
{
	TCLINKPTR	lptr;
	if ((lptr = (TCLINKPTR) allocate( sizeof( struct tcode_source_link ) )) != (TCLINKPTR) 0) {
		lptr->file = 0;
		lptr->line = 0;
		lptr->level = 0;
		lptr->next = (TCLINKPTR) 0;
		}
	return( lptr );
}

WORD	set_correspondance()
{
	trace("set_correspondances()\n");
	if ( Context->Correspondance ) {
		Correspondance.file = current_file_number();
		Correspondance.line = current_file_line();
		Correspondance.level= current_file_level();
		Correspondances = VRAI;
		}
	return(0);
}

static TCLINKPTR	allocate_correspondance()
{
	TCLINKPTR lptr;
	if ((lptr = LinksFree) != (TCLINKPTR) 0)
		LinksFree = lptr->next;
	else if ((lptr = allocate_tcode_link()) == (TCLINKPTR) 0)
		return( lptr );
	
	lptr->next = (TCLINKPTR) 0;
	return( lptr );
}

static VOID	store_correspondance( lptr )
TCLINKPTR	lptr;
{
	TCLINKPTR	xptr;

	if ((xptr = LinksUsed) == (TCLINKPTR) 0)
		LinksUsed = lptr;
	else 	{
		while ( xptr->next != (TCLINKPTR) 0)
			xptr = xptr->next;
		if (( lptr->file  != xptr->file )
		||  ( lptr->line  != xptr->line )
		||  ( lptr->level != xptr->level))
			xptr->next = lptr;
		else	{
			lptr->next = LinksFree;
			LinksFree  = lptr;
			}
		}
	return;
}


static	WORD	build_correspondance( nfic, lfic, level )
WORD	nfic;
WORD	lfic;
WORD	level;
{
	TCLINKPTR	lptr;

	if ((lptr = allocate_correspondance()) == (TCLINKPTR) 0)
		return( allocation_failure() );

	lptr->file = nfic;
	lptr->line = lfic;
	lptr->level = level;
	store_correspondance( lptr );
	return(0);
}

WORD	add_correspondance()
{

	trace("add_correspondance()\n");

	if ( Correspondances ) {
		Correspondances = FAUX;
		if ( Correspondance.level != current_file_level() )
			build_correspondance( Correspondance.file, Correspondance.line, Correspondance.level );
		}
	build_correspondance( current_file_number(), current_file_line(), current_file_level());
	return(0);

}

VOID	pending_correspondances()
{
	TCLINKPTR	lptr;
	trace("pending_correspondances()\n");
	if ( LastOutputBytes == TcodeTarget->OutputBytes )
		return;
	while ((lptr = LinksUsed) != (TCLINKPTR) 0) {
		LinksUsed = lptr->next;
		lptr->next = LinksFree;
		LinksFree  = lptr;
		if (!( OtrOption.Generate ))
			generate_debug_trace( lptr->file, lptr->line, lptr->level, TcodeTarget->OutputBytes );
		tcode_integer( lptr->file );
		tcode_integer( lptr->line );
		tcode_integer( lptr->level); 
		tcode_integer( (LastOutputBytes = TcodeTarget->OutputBytes) );
		}
	return;
}

VOID	release_correspondances()
{
	TCLINKPTR	lptr;
	trace("release_correspondances()\n");
	while ((lptr = LinksUsed) != (TCLINKPTR) 0) {
		LinksUsed = lptr->next;
		liberate( lptr );
		}
	while ((lptr = LinksFree) != (TCLINKPTR) 0) {
		LinksFree = lptr->next;
		liberate( lptr );
		}
	return;
}

VOID	symbolic_correspondance()
{
	trace("symbolic_correspondance()\n");
	if (( OtrOption.Symbolic & 1 )
	&&  (DebugTarget != (OUTPUTPTR) 0)) {
		Target = DebugTarget;
		if (Context->DebugNature == 0) {
			/* standard offset correspondance */
			/* ------------------------------ */
			if ( LastOutputBytes != TcodeTarget->OutputBytes ) {
				tcode_integer( current_file_number() );
				tcode_integer( current_file_indent() );
				tcode_integer( current_file_segment());
				tcode_integer( (LastOutputBytes = TcodeTarget->OutputBytes) );
				}
			}
		else	{
			/* enhanced lines/levels correspondance */
			/* ------------------------------------ */
			add_correspondance();
			pending_correspondances();
			}
		Target = TcodeTarget;
		}
	return;
}

#endif	/* _TRCORRES_C */
	/* ----------- */


