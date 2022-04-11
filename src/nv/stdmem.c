//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_stdmem_c
#define _stdmem_c

#include "stdmem.h"

void __far* __far __cdecl allocate( unsigned int n )
{
	return( _fmalloc( n ) );
}

void __far* __far __cdecl liberate( void __far * mptr )
{
	if ( mptr )
		_ffree( mptr );
	return((void __far *) 0);
}

#endif	// _stdmem_c




