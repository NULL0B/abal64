#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#ifndef	_allocate_c
#define	_allocate_c

#define	VOID void
#define	VPTR void *

#include <malloc.h>

#define	_EXA_TRACE_ALLOC

static	int	Tracing=0;
static	char	TraceBuffer[256];
static	long	acounter=0L;
static	long	lcounter=0L;

static	int	alloc_padding=0;

int	set_allocate_padding( int v )
{
	int	r=alloc_padding;
	alloc_padding = v;
	return(r);
}

void	TraceFlush()
{
	FILE * h;
	switch ( Tracing ) {
		case	2 : 
			if (( h = fopen("/tmp/allocate.trc","a")) != (FILE *) 0) {
				fprintf(h,"%s\r\n",TraceBuffer);
				fclose(h);
				return;
				}
		case	1 : printf("%s\r\n",TraceBuffer); 
		default	  : return;
		}
}
	

void	close_allocation_trace()
{
	Tracing=0;
	return;
}

void	start_allocation_trace()
{
	char *	eptr;
	if ((eptr = getenv("TRALSM")) != (char *) 0 ) {
		system( "rm /tmp/allocate.trc" );
		Tracing=( *eptr - '0' );
		}
	else	Tracing=0;
	return;
}

VPTR	abalallocate( int nb,char * mptr )
{
	VPTR	vptr;
	if ((vptr = malloc( (nb+alloc_padding) )) != (VPTR) 0)
		memset(vptr,0,nb);
#ifdef	_EXA_TRACE_ALLOC
	if ( Tracing ) {
		acounter++;
		sprintf(TraceBuffer,"allocate %lu x%lx %u(x%x) %s ",acounter,vptr,nb,nb,mptr);
		TraceFlush();
		}
#endif
	return( vptr);
}

VPTR	aballiberate( VPTR vptr, char * mptr)
{
#ifdef	_EXA_TRACE_ALLOC
	if ( Tracing ) {
		if (!( vptr )) {
			sprintf(TraceBuffer,"NULL liberate %lu x%lx %s NULL",lcounter,vptr,mptr);
			}
		lcounter++;
		sprintf(TraceBuffer,"liberate %lu x%lx %s",lcounter,vptr,mptr);
		TraceFlush();
		}
#endif
	if ( vptr ) {
		free( vptr );
		}
	return((VPTR) 0);
}

#endif	/* _allocate_c */

