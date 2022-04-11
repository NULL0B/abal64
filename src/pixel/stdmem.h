//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_stdmem_h
#define _stdmem_h

#include "stdtypes.h"

#ifdef	UNIX
#include "allocate.h"
#else
EXTERN	void * allocate( unsigned int  );
EXTERN	void * liberate( void * );
#endif

#endif	// _stdmem_h



