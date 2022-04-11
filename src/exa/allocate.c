#include <stdio.h>
#include <memory.h>

void	*	allocate( int n )
{
	return((void *) malloc(n) );
}

void	*	liberate( void * v)
{
	if( v )
		free( v );
	return((void *) 0);
}

