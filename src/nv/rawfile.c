//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_rawfile_c
#define _rawfile_c

#include "rawfile.h"

int	creat( char *n, int o)		{ return( _creat( n, o ) ); 	}
int	open( char *n, int o)		{ return( _open( n, o ) ); 	}
int	read( int h, char *b, int l )	{ return( _read( h, b, l ) ); 	}
int	write( int h, char *b, int l )	{ return( _write( h, b, l ) ); 	}
long	lseek( int h, long p , long o )	{ return( _lseek( h, p, o ) ); 	}
int	close( int h )			{ return( _close( h ) ); 	}
int 	unlink( char * n) 		{ return( _unlink(n) ); 	}

#endif	// _rawfile_c






