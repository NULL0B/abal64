#ifndef	_ldlibr_c
#define	_ldlibr_c

private	LIBRARY * allocate_library()
{
	LIBRARY * lptr;
	if ((lptr = allocate( sizeof( LIBRARY ) )) != (LIBRARY*) 0) {
		lptr->next = lptr->prev = (LIBRARY*)0;
		lptr->name = (BPTR) 0;
		lptr->functions = lptr->number = lptr->options = 0;
		lptr->host = (MODULE*)0;
		}
	return( lptr );
}

private	LIBRARY * copy_library(LIBRARY * xptr)
{
	LIBRARY * lptr;
	if ((lptr = allocate_library()) != (LIBRARY*) 0) {
		if ( xptr->name )
			lptr->name = allocate_string( xptr->name );
		lptr->number = xptr->number;
		lptr->host   = xptr->host;

		}
	return( lptr );
}

private	void	drop_library ( LIBRARY * lptr )
{
	if ( lptr ) {
		if ( lptr->name )
			liberate( lptr->name );
		liberate( lptr );
		}
	return;
}

EXAWORD	resolve_internal_library( MODULE * mptr, LIBRARY * lptr, LIBRARY * nptr )
{
	REFERENCE	*	rptr;

	if ( lptr->number == nptr->number )
		return(0);

	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "relocating library %s( %u ) as %u", lptr->name, lptr->number, nptr->number);
		issue_message(4, ErrorBuffer);
	}

	for (	rptr=mptr->relocations.root;
		rptr != (REFERENCE*)0;
		rptr = rptr->next ) {
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "R.I.L: at %u,%x %u,%u", rptr->patch.sector, rptr->patch.length, rptr->type,rptr->value);
				issue_message(4, ErrorBuffer);
			}
		if ( rptr->type != (INT_LIBRARY) )
			continue;
		else if ( rptr->value != lptr->number )
			continue;
		else	{
			rptr->value = nptr->number;
			rptr->type  = EXT_LIBRARY;
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "becomes %u,%u", rptr->type, rptr->value);
				issue_message(4, ErrorBuffer);
				}
			}
		}
	return(0);
}

EXAWORD	add_library( MODULE * mptr, LIBRARY * lptr )
{
	LIBRARY	*	nptr;

	/* avoid duplicates */
	for (	nptr=mptr->libraries.root;
		nptr != (LIBRARY*)0;
		nptr = nptr->next )
		if ( compare_strings( nptr->name, lptr->name ) )
			return(resolve_internal_library( lptr->host, lptr, nptr ));

	if (!( nptr = copy_library( lptr )))
		return(linker_error(196));
	else if (!( nptr->prev = mptr->libraries.last ))
		mptr->libraries.root = nptr;
	else	mptr->libraries.last->next = nptr;
	mptr->libraries.last = nptr;
	nptr->number = mptr->nblibr++;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "add_library(%s) as %u", nptr->name, nptr->number);
		issue_message(4, ErrorBuffer);
	}
	return(resolve_internal_library(lptr->host,lptr,nptr));
}


private	void	drop_libraries ( MODULE * mptr )
{
	LIBRARY * lptr;

	while ((lptr = mptr->libraries.root) != (LIBRARY*)0) {
		mptr->libraries.root = lptr->next;
		drop_library( lptr );
		}
	return;
}

private	int load_libraries ( MODULE * mptr )
{
	EXAWORD		n;
	EXAWORD		l;
	EXAWORD		i;
	EXAWORD		v;
	EXAWORD		status;
	EXAWORD		sector;
	LIBRARY	 *	lptr;

	if (((mptr->librtable.sector = tcsector( &mptr->atheader[(TCPREFIX + (24*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
	&&  ((mptr->librtable.length = tclength( &mptr->atheader[(TCPREFIX + (25*mptr->wordsize)+2)],mptr->wordsize )) != 0 )) {
		mptr->librtable.length *= 256; /* bug !!! */
		
		if ((status = load_buffer( mptr, mptr->athandle, mptr->librtable.sector )) != 0)
			return( status );
		else if (!( mptr->nblibr = buffer_getw( mptr ))) 
			return(0);
		else if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "dlt       : sector =%u, length =%u, libraries : %u",
				mptr->librtable.sector,
				mptr->librtable.length,
				mptr->nblibr);
			issue_message(4, ErrorBuffer);
			}
		for (l=0; l < mptr->nblibr; l++ ) {
			if (!( lptr = allocate_library() ))
				return( linker_error(146) );
			else	lptr->host = mptr;
			if (!( mptr->libraries.last ))
				mptr->libraries.root = lptr;
			else	mptr->libraries.last->next = lptr;
			lptr->prev = mptr->libraries.last;
			mptr->libraries.last = lptr;
			lptr->number = l;
			if (!( lptr->name = buffer_gets( mptr )))
				return( linker_error(147) );
			lptr->functions = buffer_getw( mptr );
			n = (18 - mptr->wordsize);
			for (i=0; i < n; i++ )
				v = buffer_getb( mptr );

			}
		if ((sector = tcsector( &mptr->dbheader[(TCPREFIX + (26*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "library relocation table : %u", sector);
				issue_message(4, ErrorBuffer);
				}
			return(load_byte_relocation(mptr,INT_LIBRARY,sector));
			}
		else	return(0);
		}
	else	return(0);
}

EXAWORD	start_library_table( MODULE * mptr ) 
{
	reset_location( &mptr->librtable );
	if ( mptr->nblibr != 0 ) {
		report_library_table();
		next_free_location(&mptr->librtable);
		if( Linker.targettrace )
			issue_message(5, "Dynamic Library Table");
		buffer_start( mptr, mptr->athandle, &mptr->librtable );
		buffer_putw(mptr,mptr->nblibr);
		}
	return(mptr->nblibr);
}

EXAWORD	output_library( MODULE * rptr, LIBRARY * lptr  ) 
{
	EXAWORD	i;
	EXAWORD	n;
	report_library( lptr );
	buffer_puts(rptr,lptr->name);
	buffer_putw(rptr,lptr->functions);
	n = (18 - rptr->wordsize);
	for (i=0; i < n; i++ ) 
		buffer_putb(rptr,0);
	return(0);
}

EXAWORD	close_library_table( MODULE * mptr ) 
{
	buffer_flush( mptr );

	if ( mptr->librtable.length != 0) {
		/* length in sectors ! thanks claude and bruno ! */
		/* --------------------------------------------- */
		if ( mptr->librtable.length % 256 )
			mptr->librtable.length 	= ((mptr->librtable.length/256)+1);
		else	mptr->librtable.length 	= (mptr->librtable.length/256);
		report_close_table();
		}

	return(0);
}

#endif	/* _ldlibr_c */



