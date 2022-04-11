#ifndef	_stuballoc_c
#define	_stuballoc_c

#include <stdio.h>
#include "inxsql.h"

void *	abalallocate( int n, char * mptr )
{
	void * r;
	r = malloc(n);
	return( r );
}

void *	aballiberate( void * vptr, char * mptr )
{
	if ( vptr )
		free( vptr );
	return((void *) 0);
}

char * allocate_string(char *s)
{
	char * r;
	if (!( r = allocate( strlen(s) + 1 ) ))
		return( r );
	else return( strcpy(r,s));
}



	/* -------- */
#endif	/* _stuballoc_c */
	/* -------- */

