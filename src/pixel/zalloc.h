#ifndef	_zalloc_h
#define	_zalloc_h

#if defined(UNIX)
#include "stdtypes.h"
#endif

#define  ALSMID "zzzz"
#include "allocate.h"

char * allocate_string( char * );
BPTR allocate_filename( BPTR );
BPTR drop_string(BPTR);

#endif	/* _zalloc_h */

