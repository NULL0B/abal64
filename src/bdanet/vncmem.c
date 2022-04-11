#ifndef	_vncmem_c
#define	_vncmem_c

void *	allocate(unsigned int nb)
{
	return( malloc( nb ) );
}
void *	liberate(void * vptr)
{
	if ( vptr ) free( vptr );
	return( (void *) 0 );
}

#endif 	// _vncmem_c


