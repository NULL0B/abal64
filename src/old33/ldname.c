#ifndef	_ldnames_c
#define	_ldnames_c

NAMES *	allocate_name()
{
	NAMES *	nptr;
	if ((nptr = allocate( sizeof( NAMES ) )) != (NAMES*)0) {
		nptr->next = nptr->prev = (NAMES*)0;
		nptr->name = (BPTR) 0;
		nptr->alternative =
		nptr->number = 0;
		}
	return( nptr );
}

NAMES *	copy_name( NAMES * xptr )
{
	NAMES *	nptr;
	if ((nptr = allocate_name()) != (NAMES*)0) {
		if ( xptr->name )
			nptr->name = allocate_string( xptr->name );
		nptr->alternative = xptr->alternative;
		nptr->number = xptr->number;
		}
	return( nptr );
}

VOID	liberate_name( NAMES * nptr)
{
	if ( nptr ) {
		if ( nptr->name )
			liberate( nptr->name );
		liberate( nptr );
		}
	return;
}

EXAWORD	add_filename( MODULE * mptr, NAMES * optr )
{
	NAMES * nptr;
	if (!( mptr )) return(0);
	if (!( optr )) return(0);
	if (!( optr->name )) return(0);
 
	for (	nptr=mptr->filename.root;
		nptr != (NAMES *) 0;
		nptr = nptr->next ) {
		if (!( nptr->name )) continue; 
		if ( compare_strings( nptr->name, optr->name ) ) {
			optr->alternative = nptr->number;
			return(0);
			}
		}
	if (!( nptr = copy_name( optr )))
		return( report_error( 197, optr->name ));

	else if (!( nptr->prev = mptr->filename.last )) {
		nptr->number = nptr->alternative = 1;
		mptr->filename.root = nptr;
		}
	else	{
		nptr->alternative = 
		nptr->number = (mptr->filename.last->number+1);
		mptr->filename.last->next = nptr;
		}
	mptr->filename.last = nptr;
	optr->alternative = nptr->number;
	return( 0 );
}

VOID	drop_names( MODULE * mptr )
{
	NAMES * nptr;
	while ((nptr = mptr->names.root) != (NAMES*)0) {
		mptr->names.root = nptr->next;
		liberate_name( nptr );
		}
	return;
}

VOID	drop_filenames( MODULE * mptr )
{
	NAMES * nptr;
	while ((nptr = mptr->filename.root) != (NAMES*)0) {
		mptr->filename.root = nptr->next;
		liberate_name( nptr );
		}
	return;
}

EXAWORD	load_names( MODULE * mptr )
{
	WORD	status;
	WORD	n;
	NAMES * nptr=(NAMES*)0;

	if ((mptr->modnames.sector = tcsector( &mptr->dbheader[(TCPREFIX + (36*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
		if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "mnt : sector =%u", mptr->modnames.sector);
			issue_message(4, ErrorBuffer);
			}
		if ((status = load_buffer( mptr, mptr->dbhandle, mptr->modnames.sector )) != 0)
			return( status );
		while ((n = buffer_getw(mptr)) != mptr->minusone) {
			if (!(nptr = allocate_name())) 
				return( report_error(158,mptr->rootname) );
			if (!( mptr->names.last ))
				mptr->names.root = nptr;
			else	mptr->names.last->next = nptr;
			nptr->prev = mptr->names.last;
			mptr->names.last = nptr;
			nptr->number = n;
			if (!( nptr->name = buffer_gets( mptr )))
				return( report_error(159,mptr->rootname) );
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "module name %u : %s", nptr->number, nptr->name);
				issue_message(4, ErrorBuffer);
				}
			}
		}
	return(0);
}

NAMES * resolve_filename( MODULE * mptr, EXAWORD number )
{
	NAMES	*	nptr;
	for (	nptr=mptr->filename.root;
		nptr != (NAMES *) 0;
		nptr = nptr->next ) 
		if ( nptr->number == number )
			break;
	return( nptr );
}

EXAWORD	resolve_filenumber( MODULE * mptr, EXAWORD number )
{
	NAMES * nptr;
	if (!( nptr = resolve_filename( mptr, number ) ))
		return(0);
	else	return(nptr->alternative);
}

EXAWORD	load_filenames( MODULE * mptr )
{
	WORD	status;
	WORD	n;
	NAMES * nptr=(NAMES*)0;

	if ((mptr->filenames.sector = tcsector( &mptr->dbheader[(TCPREFIX + (40*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
		if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "mnt : sector =%u", mptr->filenames.sector);
			issue_message(4, ErrorBuffer);
			}
		if ((status = load_buffer( mptr, mptr->dbhandle, mptr->filenames.sector )) != 0)
			return( status );
		while ((n = buffer_getw(mptr)) != mptr->minusone) {
			if (!(nptr = allocate_name())) 
				return( report_error(160,mptr->rootname) );
			if (!( nptr->prev = mptr->filename.last ))
				mptr->filename.root = nptr;
			else	mptr->filename.last->next = nptr;
			mptr->filename.last = nptr;
			nptr->number = n;
			if (!( nptr->name = buffer_gets( mptr )))
				return( report_error(161,mptr->rootname) );
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "file name %u : %s", nptr->number, nptr->name);
				issue_message(4, ErrorBuffer);
				}
			}
		}
	return(0);
}


private	BPTR	resolve_module_name( MODULE * mptr, EXAWORD number )
{
	NAMES *	nptr;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "resolve_module_name(%u)", number);
		issue_message(4, ErrorBuffer);
		}
	for (	nptr=mptr->names.root; nptr != (NAMES *) 0; nptr = nptr->next ) {
		if ( nptr->number == number )
			return( nptr->name );
		}
	return((BPTR) 0);
}

private	int	compare_names( BPTR nptr,MODULE * mptr )
{
	int	i;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "compare_module_name(%s)", nptr);
		issue_message(4, ErrorBuffer);
		}
	for ( i=0; i < 15; i++ ) {
		if (!( *(nptr+i) ))
			break;
		else if ( mptr->progname[i] != *(nptr+i))
			return(0);
		}
	if ( *(nptr+i) != 0 )
		return(0);
	for ( ; i < 15; i++ )
		if ( mptr->progname[i] != ' ' )
			return(0);
	return(1);
}

public	MODULE * locate_module( BPTR nptr )
{
	MODULE * mptr;

	for ( 	mptr=Linker.modules.root;
		mptr != (MODULE*) 0;
		mptr = mptr->next ) {
		if ( compare_names( nptr, mptr ) )
			break;			
		}
	return( mptr );
}

EXAWORD	flush_filenames( MODULE * rptr )
{
	NAMES	*	nptr;
	if (!( Linker.debug ))
		return(0);
	else if (!( rptr->filename.root ))
		return( 0 );

	reset_location( &rptr->filenames );
	next_debug_location( &rptr->filenames );
	if( Linker.targettrace )
		issue_message(5, "File Names Table");
	buffer_start( rptr, rptr->dbhandle, &rptr->filenames );
	for (	nptr=rptr->filename.root;
		nptr != (NAMES *) 0;
		nptr = nptr->next ) {
			if ( Linker.targettrace ) {
				sprintf(ErrorBuffer, "filename : %u) %s", nptr->number, nptr->name);
				issue_message(5, ErrorBuffer);
				}
		buffer_putw( rptr, nptr->number );
		buffer_puts( rptr, nptr->name );
		}
	buffer_putw( rptr, rptr->minusone );
	debug_flush( rptr );
	return(0); 

}



#endif	/* _ldnames_c */


