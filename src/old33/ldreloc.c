#ifndef	_ldreloc_c
#define	_ldreloc_c

private	RELOCATION	*	allocate_relocation()
{
	RELOCATION	*	rptr;
	if ((rptr = allocate( sizeof( RELOCATION ) )) != (RELOCATION*)0) {
		rptr->next = (RELOCATION*)0;
		reset_location( &rptr->detail );
		}
	return( rptr );
}

private	RELOCATION	*	copy_relocation(RELOCATION * xptr)
{
	RELOCATION	*	rptr;
	if ((rptr = allocate( sizeof( RELOCATION ) )) != (RELOCATION*)0) {
		rptr->next = (RELOCATION*)0;
		copy_location( &rptr->detail, &xptr->detail );
		}
	return( rptr );
}

private	RELOCATION	*	copy_relocation_list(RELOCATION * xptr)
{
	RELOCATION	*	root=(RELOCATION*) 0;
	RELOCATION	*	rptr;
	RELOCATION	*	last=(RELOCATION*) 0;
	while (xptr != (RELOCATION *)0) {
		if (!( rptr = copy_relocation( xptr ) )) {
			linker_error( 162 );
			break;
			}
		else if (!( root ))
			root = rptr;
		else	last->next = rptr;
		last = rptr;
		xptr = xptr->next;
		}
	return( root );
}

private	void	drop_relocation( RELOCATION * root )
{
	RELOCATION	*	rptr=(RELOCATION*)0;
	while ((rptr = root) != (RELOCATION *)0) {
		root = rptr->next;
		liberate( rptr );
		}
	return;
}

public	RELOCATION	*	collect_relocation( MODULE * mptr, int report )
{
	RELOCATION	*	root=(RELOCATION*)0;
	RELOCATION	*	last=(RELOCATION*)0;
	RELOCATION	*	rptr;
	EXAWORD	v;
	while ((v = buffer_getw( mptr )) != 0) {
		if (!(rptr = allocate_relocation() ))  {
			report_error(163,mptr->rootname);
			break;
			}
		else if (!( root ))
			root = rptr;
		else 	last->next = rptr;
		last = rptr;
		rptr->detail.sector = v;
		rptr->detail.length = buffer_getw( mptr );
		if ( Linker.verbose & report ) {
			sprintf(ErrorBuffer, "(%u:%x)", rptr->detail.sector, rptr->detail.length);
			issue_message(0, ErrorBuffer);
			}
		}
	return( root );
}

#endif	/* _ldreloc_c */

