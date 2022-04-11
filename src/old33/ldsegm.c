#ifndef	_ldsegm_c
#define	_ldsegm_c

XSEGMENT	*	allocate_external_segment()
{
	XSEGMENT	*	sptr;
	if (!( sptr = allocate( sizeof( XSEGMENT ) )))
		return( sptr );
	else	{
		sptr->next = sptr->prev = (XSEGMENT*) 0;
		sptr->modname 	=
		sptr->name 	= (BPTR) 0;	
		sptr->module 	= sptr->state = 0;
		sptr->number    = 0;
		sptr->relocate	= (RELOCATION*)0;
		sptr->client	= 
		sptr->host	= (MODULE*)0;
		sptr->segment	= (SEGMENT*) 0;
		return( sptr );
		}
}

XSEGMENT	*	copy_external_segment(XSEGMENT * xptr)
{
	XSEGMENT	*	sptr;
	if (!( sptr = allocate_external_segment()))
		return( sptr );
	else	{
		sptr->next = sptr->prev = (XSEGMENT*) 0;
		if ( xptr->name )
			sptr->name = allocate_string( xptr->name );
		sptr->module   = xptr->module;
		sptr->number   = xptr->number;
		sptr->state    = xptr->state;
		sptr->host     = xptr->host;
		sptr->client  = xptr->client;
		sptr->segment  = xptr->segment;
		sptr->relocate = copy_relocation_list( xptr->relocate );
		return( sptr );
		}
}

XSEGMENT	*	liberate_external_segment( XSEGMENT * sptr )
{
	if ( sptr ) {
		if ( sptr->name )
			liberate( sptr->name );
		if ( sptr->relocate )
			drop_relocation( sptr->relocate );

		liberate( sptr );
		}
	return((XSEGMENT*) 0);
}

SEGMENT	*	allocate_segment()
{
	SEGMENT	*	sptr;
	if (!( sptr = allocate( sizeof( SEGMENT ) )))
		return( sptr );
	else	{
		sptr->next = sptr->prev = (SEGMENT*) 0;
		sptr->name = (BPTR) 0;
		sptr->identity = sptr->options = 0;
		reset_location( &sptr->tcode );
		reset_location( &sptr->stats );
		reset_location( &sptr->lvt   );
		reset_location( &sptr->lct   );
		reset_location( &sptr->crossref );
		sptr->linkown =0;
		sptr->linkage = (REFERENCE*) 0;
		reset_location( &sptr->correspondance );
		sptr->original =	
		sptr->host = (MODULE*)0;
		return( sptr );
		}
}

SEGMENT	*	copy_segment(SEGMENT * xptr)
{
	SEGMENT	*	sptr;
	if (!( sptr = allocate_segment()))
		return( sptr );
	else	{
		sptr->next = sptr->prev = (SEGMENT*) 0;
		if ( xptr->name )
			sptr->name = allocate_string( xptr->name );
		sptr->identity = xptr->identity;
		sptr->options  = xptr->options;
		sptr->offset   = xptr->offset;
		copy_location( &sptr->tcode, 	&xptr->tcode );
		copy_location( &sptr->lvt,	&xptr->lvt   );
		copy_location( &sptr->lct,	&xptr->lct   );
		copy_location( &sptr->crossref,	&xptr->crossref);
		sptr->linkage = xptr->linkage;
		copy_location( &sptr->correspondance,&xptr->correspondance );
		sptr->original = xptr->original;
		sptr->host = xptr->host;
		return( sptr );
		}
}

SEGMENT	*	liberate_segment( SEGMENT * sptr )
{
	if ( sptr ) {
		if ( sptr->name )
			liberate( sptr->name );
		if ( sptr->linkown ) {
			if ( sptr->linkage )
				drop_references( sptr->linkage );
			}
		liberate( sptr );
		}
	return((SEGMENT*) 0);
}

private	void	drop_external_segments ( MODULE * mptr )
{
	XSEGMENT	*	sptr;

	while ((sptr = mptr->xsegments.root) != (XSEGMENT *) 0) {
		mptr->xsegments.root = sptr->next;
		liberate_external_segment( sptr );
		}
	return;
}

private	void	drop_segments ( MODULE * mptr )
{
	SEGMENT	*	sptr;

	while ((sptr = mptr->segments.root) != (SEGMENT *) 0) {
		mptr->segments.root = sptr->next;
		liberate_segment( sptr );
		}

	if ( mptr->gst )
		liberate( mptr->gst );
	return;
}

private	int load_segment( MODULE * mptr, SEGMENT * sptr )
{
	BPTR	tptr;

	/* collect name and identity */
	/* ------------------------- */
	if (!( sptr->name = buffer_gets( mptr ) ))
		return( 27 );
	else	{
		sptr->identity = buffer_getw( mptr );
		sptr->offset = buffer_getw( mptr );
		tptr = (mptr->gst + sptr->offset);
		}

	/* now locate segment table information */
	/* -------------------------------------- */
	tptr += mptr->wordsize;
	sptr->tcode.sector = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	sptr->tcode.length = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	sptr->lvt.sector = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	sptr->lvt.length = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;

	sptr->options = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;

	sptr->lct.sector = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	sptr->lct.length = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;

	/* collect the remaining symbolic information */
	/* ------------------------------------------ */
	sptr->crossref.sector = buffer_getw( mptr );
	sptr->correspondance.sector = buffer_getw( mptr );
	sptr->correspondance.length = buffer_getw( mptr );

	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "segm %s(/%x) : tc(%u,%u) lv(%u,%u) lc(%u,%u) o (%u) xr(%u), cr(%u,%u)",
			sptr->name,sptr->identity,
			sptr->tcode.sector,sptr->tcode.length,
			sptr->lvt.sector,sptr->lvt.length,
			sptr->lct.sector,sptr->lct.length,
			sptr->options,
			sptr->crossref.sector,
			sptr->correspondance.sector,sptr->correspondance.length
			);
		issue_message(4, ErrorBuffer);
		}
	return(0);
}

private	int resolve_external_segment( MODULE * mptr, XSEGMENT * xptr )
{
	SEGMENT *	sptr;

	for (	sptr = mptr->segments.root;
		sptr != (SEGMENT *) 0;
		sptr = sptr->next ) {
		if (compare_strings( xptr->name, sptr->name )) {
			xptr->host 	= mptr;
			xptr->segment   = sptr;
			if ( xptr->number != Linker.minusone )
				sptr->identity = xptr->number;
			if ( Linker.sourcetrace )
				solution( sptr->name, mptr );
			return(1);
			}
		}
	return(0);
}

private	int extern_segment_in( BPTR nptr, XSEGMENT * xptr )
{
	MODULE	*	mptr;
	if (!( mptr = locate_module( nptr )))
		return( report_error(123,nptr) );
	else	return( resolve_external_segment( mptr, xptr ) );
}

public 	int relocate_external_segment( XSEGMENT * xptr )
{
	MODULE	*	hptr;
	MODULE	*	cptr;
	SEGMENT *	sptr;

	if ((!(hptr = xptr->host      ))
	||  (!(cptr = xptr->client    ))
	||  (!(sptr = xptr->segment   ))) 
		return( report_error(124,xptr->name));
	else	return( build_external_relocation(
				cptr,
				EXT_SEGMENT,
				( xptr->number != cptr->minusone ?
				  xptr->number : (xptr->number = sptr->identity)),
				0,
				xptr->relocate ,0
				) 
			);

	return(0);

}

public 	int resolve_segment( XSEGMENT * xptr )
{
	MODULE	*	mptr;

	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "resolve_segment(%s)", xptr->name);
		issue_message(4, ErrorBuffer);
		}

	if ( xptr->modname )
		return( extern_segment_in( xptr->modname, xptr  ));

	else if ( resolve_external_segment( Linker.program, xptr  ) )
		return(1);

	for (	mptr=Linker.modules.root;
		mptr != (MODULE *) 0;
		mptr = mptr->next ) {
		if ( resolve_external_segment( mptr, xptr ) )
			return(1);
		}

	return(0);
}

private	int load_segments( MODULE * mptr )
{
	EXAWORD	status;
	EXAWORD	s;
	EXAWORD	nbs;
	SEGMENT * sptr=(SEGMENT*)0;

	if (((mptr->segmtable.sector = tcsector( &mptr->atheader[(TCPREFIX + (7*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
	&&  ((mptr->segmtable.length = tclength( &mptr->atheader[(TCPREFIX + (8*mptr->wordsize)+2)],mptr->wordsize )) != 0 )) {
		mptr->nbsegm = (mptr->segmtable.length / (12*mptr->wordsize));
		mptr->SdtLimit = mptr->segmtable.length;
		mptr->SdtAdjust= 0;
		if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "gst       : sector =%u, length =%u, segments : %u",mptr->segmtable.sector,mptr->segmtable.length,mptr->nbsegm);
			issue_message(4, ErrorBuffer);
			}
		if (!(mptr->gst = load_tcode( mptr->athandle, mptr->segmtable.sector, mptr->segmtable.length )))
			return(report_error( 125, mptr->rootname) );
		if ((mptr->segmnames.sector = tcsector( &mptr->dbheader[(TCPREFIX + (33*mptr->wordsize)+2)],mptr->wordsize )) != 0) {
			if ((status = load_buffer( mptr, mptr->dbhandle, mptr->segmnames.sector )) != 0)
				return( report_error( 126,mptr->rootname) );
			else if (!( nbs = buffer_getw( mptr ))) 
				return(0);
			for (s=0; s < nbs; s++ ) {
				if (!(sptr = allocate_segment()))
					return( report_error( 127,mptr->rootname) );
				else	{
					sptr->host = mptr;
					}
				if (!( mptr->segments.last ))
					mptr->segments.root = sptr;
				else	mptr->segments.last->next = sptr;
				sptr->prev = mptr->segments.last;
				mptr->segments.last = sptr;
				if ((status = load_segment( mptr, sptr )) != 0)
					return( report_error( 128,mptr->rootname) );
				}
			for ( 	sptr=mptr->segments.root;
				sptr != (SEGMENT *) 0;
				sptr = sptr->next ) {
				if ( sptr->crossref.sector != 0 ) {
					if (!(sptr->linkage = load_references( mptr, &sptr->crossref )))
						continue;
					else	sptr->linkown=1;
					}
				}
			}
		}
	return(0);
}

private	int load_external_segments( MODULE * mptr )
{
	WORD	status;
	EXAWORD	s;
	EXAWORD	nbs;
	EXAWORD	sector;
	XSEGMENT * sptr=(XSEGMENT*)0;

	if ((sector = tcsector( &mptr->dbheader[(TCPREFIX + (34*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
		if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
			return( status );
		else if (!( nbs = buffer_getw( mptr ))) 
			return(0);
		for (s=0; s < nbs; s++ ) {
			if (!(sptr = allocate_external_segment())) 
				return( report_error(129,mptr->rootname) );
			else	sptr->client = mptr;
			if (!( sptr->prev = mptr->xsegments.last ))
				mptr->xsegments.root = sptr;
			else	mptr->xsegments.last->next = sptr;
			mptr->xsegments.last = sptr;
			if ((sptr->module = buffer_getw( mptr )) != mptr->minusone) {
				if (!( sptr->modname = resolve_module_name( mptr, sptr->module ) ))
					return( report_error(130,mptr->rootname));
				}
			else	sptr->modname = (BPTR) 0;
			sptr->name   = buffer_gets( mptr );
			sptr->number = buffer_getw( mptr );

			sptr->relocate = collect_relocation( mptr,0 );

			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "extern segm %s as %u in module %u", sptr->name, sptr->number, sptr->module );
				issue_message(4, ErrorBuffer);
				}	
			}

		}
	return(0);
}

/*
 *	This method os called to calculate the initial segment
 *	number of a program to be used when rellocating module
 *	segments. Programs may contain named segments numbered
 *	from the external range.
 *
 */

EXAWORD	calculate_max_segment( MODULE * pptr ) 
{
	SEGMENT *	sptr;
	EXAWORD		maxsegment;

	if (!( pptr->segments.root ))
		return( 205 );
	else	maxsegment = 0;

	for (	sptr=pptr->segments.root;
		sptr != (SEGMENT*)0;
		sptr = sptr->next ) {
		if( sptr->identity > maxsegment )
			maxsegment = sptr->identity;
		}
	if ( maxsegment >= pptr->NewSegment )
		pptr->NewSegment = (maxsegment+1);
	return( 0 );
}



EXAWORD	resolve_internal_segment( MODULE * mptr, SEGMENT * sptr )
{
	REFERENCE	*	rptr;

	for (	rptr=mptr->relocations.root;
		rptr != (REFERENCE*)0;
		rptr = rptr->next ) {
		if ( rptr->type != INT_SEGMENT )
			continue;
		else if ( rptr->value != sptr->offset )
			continue;
		else	{
			rptr->value = sptr->identity;
			rptr->type  = EXT_SEGMENT;
			}
		}
	return(0);
}

EXAWORD	add_segment( MODULE * mptr, SEGMENT * sptr )
{
	SEGMENT	*	nptr;
	if (!( nptr = copy_segment( sptr )))
		return(report_error(201,sptr->name));
	else if (!( nptr->prev = mptr->segments.last ))
		mptr->segments.root = nptr;
	else	mptr->segments.last->next = nptr;
	mptr->segments.last = nptr;
	mptr->SdtLimit += (12*mptr->wordsize);
	if ( nptr->identity == mptr->minusone )
		nptr->identity = mptr->NewSegment++;
	sptr->identity = nptr->identity;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "add_segment(%u)",nptr->identity);
		issue_message(4, ErrorBuffer);
		}
	if (!( sptr->host ))
		return( 0 );
	else	return(resolve_internal_segment(sptr->host,sptr));
}

EXAWORD	add_external_segment( MODULE * mptr, XSEGMENT * sptr )
{
	XSEGMENT	*	nptr;
	if (!( nptr = copy_external_segment( sptr )))
		return(report_error(202,sptr->name));
	else if (!( nptr->prev = mptr->xsegments.last ))
		mptr->xsegments.root = nptr;
	else	mptr->xsegments.last->next = nptr;
	mptr->xsegments.last = nptr;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "add_external_segment(%u)", nptr->number);
		issue_message(4, ErrorBuffer);
		}
	return(0);
}

EXAWORD	start_segment_table( MODULE * mptr ) 
{
	reset_location( &mptr->segmtable );
	return(0);
}

EXAWORD	output_segment( MODULE * rptr, SEGMENT * sptr  ) 
{
	MODULE		* mptr;
	EXAWORD	status;

	if (!( mptr = sptr->host ))
		return( report_error(131,sptr->name));
	/* the same file so no copy */
	else if ( mptr->unique == rptr->unique )
		return(0);
	else if (( status = copy_tcode( rptr, mptr, &sptr->tcode,1,(LOCATION*)0 )) != 0)
		return( report_error(132, sptr->name ) );

	/* update the local variable table details */
	/* IJM : 25/11/2003 */
	if ( sptr->lvt.length > rptr->maxldt ) {
		rptr->maxldt = sptr->lvt.length;
		rptr->maxlds = sptr->lvt.length;
		}

	if (( status = copy_local_variables( rptr, mptr, &sptr->lvt, &sptr->stats )) != 0)
		return( report_error(133, sptr->name ));
	else if (( status = copy_local_constants( rptr, mptr, &sptr->lct )) != 0)
		return( report_error( 134, sptr->name ));
	else	{
		sptr->original = sptr->host;
		sptr->host = rptr;
		return(0);
		}
}

EXAWORD	close_segment_table( MODULE * mptr ) 
{
	SEGMENT * sptr;
	EXAWORD	offset=0;
	unsigned long table_check=0L;
	if (!( mptr->segments.root ))
		return(0);
	report_segment_table();
	next_free_location(&mptr->segmtable);
	if( Linker.targettrace )
		issue_message(5, "Segment Table");
	buffer_start( mptr, mptr->athandle, &mptr->segmtable );
	for (	sptr=mptr->segments.root;
		sptr != (SEGMENT*) 0;
		sptr = sptr->next ) {
		report_segment(sptr,offset);
		sptr->offset = offset;
		buffer_putw(mptr,sptr->identity);
		buffer_putlocation(mptr,&sptr->tcode);
		buffer_putlocation(mptr,&sptr->lvt);
		buffer_putw(mptr,sptr->options);
		buffer_putlocation(mptr,&sptr->lct);
		buffer_putw(mptr,0);
		buffer_putw(mptr,0);
		buffer_putw(mptr,0);
		buffer_putw(mptr,0);
		offset += (12*mptr->wordsize);
		if ( mptr->wordsize > 2 )
			continue;
		else	{
			table_check += (12*mptr->wordsize);
			if ( table_check & OVERFLOW16 )
				return( report_error( 212, sptr->name ) );
			}
		}
	buffer_putw(mptr,mptr->minusone);
	buffer_flush( mptr );
	close_segment_report();
	return(0);
}

EXAWORD	flush_segment_names_table( MODULE * mptr ) 
{
	SEGMENT * sptr;

	if (!( Linker.debug ))
		return(0);

	/* Copy Segment Correspondances */
	/* ---------------------------- */
	for (	sptr=mptr->segments.root;
		sptr != (SEGMENT*) 0;
		sptr = sptr->next ) 
		copy_correspondance( mptr, sptr->original, &sptr->correspondance );

	/* Build New Procedure Names Table */
	/* ------------------------------- */
	reset_location( &mptr->segmnames );
	next_debug_location(&mptr->segmnames);
	if( Linker.targettrace )
		issue_message(5, "Segment Names Table");
	buffer_start( mptr, mptr->dbhandle, &mptr->segmnames );
	mptr->nbsegm = (mptr->segmtable.length / (12*mptr->wordsize));
	buffer_putw(mptr,mptr->nbsegm);
	for (	sptr=mptr->segments.root;
		sptr != (SEGMENT*) 0;
		sptr = sptr->next ) {
		if (!( sptr->name ))
			buffer_putb(mptr,0);
		else	buffer_puts(mptr,sptr->name);
		buffer_putw(mptr,sptr->identity);
		buffer_putw(mptr,sptr->offset);
		buffer_putw(mptr,0 );	/* cross ref sector */
		buffer_putw(mptr,sptr->correspondance.sector);
		buffer_putw(mptr,sptr->correspondance.length);
		}
	buffer_putw(mptr,0);
	buffer_putw(mptr,0);
	buffer_putw(mptr,mptr->minusone);
	debug_flush( mptr );
	return(0);
}

#endif	/* _ldsegm_c */


