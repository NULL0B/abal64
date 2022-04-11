#ifndef	_JPEG_C
#define	_JPEG_C

#include <stdio.h>
#include <stdlib.h>
#include "jpegtype.h"
#include "jpegdef.h"
#include "jinclude.h"
#include "jpeglib.h"
#include "xp_core.h"
#include "jpegfunc.h"

#ifdef UNIX
static	char	SystemFileName[256];

PUBLIC	char	*	sysfilename( char * nptr )
{
	int	i;
	for ( i=0; *(nptr+i) != 0; i++ ) 
#ifndef	UNIX
		if ((SystemFileName[i] = *(nptr+i)) == '/')
			SystemFileName[i] = '\\';
#else
		if ((SystemFileName[i] = *(nptr+i)) == '\\')
			SystemFileName[i] = '/';
#endif
	SystemFileName[i++] = 0;
	return( SystemFileName );
}

int vgapalette( char * pptr, int i, int j )
{
	return(0);
}


#endif

int	catch_exception()
{
	return(0);
}
int	throw_exception(int v)
{
	exit(v);
}



#include "vga.c"
#include "jpegid.c"
#include "jpegfunc.c"

#endif	/* _JPEG_C */ 
	/* ------- */






