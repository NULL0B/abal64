#ifndef	_ldlibmod_c
#define	_ldlibmod_c



#ifdef ABAL33A

EXAWORD	load_implicite_modules( MODULE * mptr )
{
	/* Load library modules */
	/* With modules < 3.3a, FFFFFFFF is read */
	if ((mptr->libmodtable.sector = tcsector( &mptr->atheader[(TCPREFIX + (56*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
		if ((mptr->libmodtable.length = tclength( &mptr->atheader[(TCPREFIX + (57*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "lmt       : sector =%u, length =%u",mptr->libmodtable.sector,mptr->libmodtable.length);
				issue_message(4, ErrorBuffer);
			}
			if ((mptr->lmt = load_tcode( mptr->athandle, mptr->libmodtable.sector, mptr->libmodtable.length )) != (BPTR) 0)
				return(0);
			else
				return(report_error(214, mptr->rootname ) );
		}
	}

	return(0);
}

private	int add_library_modules( MODULE * mptr )
{
	EXAWORD	number;
	EXAWORD	count;
	NAMES		*nptr;
	BPTR		bptr = mptr->lmt;
	int		status = 0;

	if (bptr != (BPTR) 0) {
		for (count = 0; count < mptr->libmodtable.length / mptr->wordsize; count++) {
			number = tcgetword( bptr, mptr->wordsize );
			bptr += mptr->wordsize;

			/* Get associated filename */
			for (	nptr = mptr->names.root; nptr != (NAMES *) 0; nptr = nptr->next ) {
				if ( nptr->number == number )
					break;
				}
			
			if (status = add_module( nptr->name ) != 0)
				break;
		}
	}

	return status;
}

private	int add_implicite_modules( void )
{
	MODULE	* mptr;
	int		status = 0;

/* Add implicite modules for all input modules

	for (	mptr = Linker.modules.root;
		mptr != (MODULE *) 0;
		mptr = mptr->next ) {
		if ((status = add_library_modules(mptr)) != 0)
			break;
	}
*/
	/* Add implicite modules only if one input module */
	mptr = Linker.modules.root;

	if (mptr->next == (MODULE*) 0)
		status = add_library_modules(mptr);

	return status;
}

private	void	drop_library_modules ( MODULE * mptr )
{
	if (mptr->lmt != (BPTR)0)
		liberate( mptr->lmt );
}

#endif

#endif	/* _ldlibmod_c */



