#include <stdio.h>
#include <malloc.h>
void * abalallocate(int v)
{
	return( malloc(v) );
}
void *	aballiberate( void * v)
{
	free(v);
	return((void *) 0);
}

void	start_allocation_trace()
{
	return;
}


