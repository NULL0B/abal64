#ifndef	_unxvalloc_c
#define	_unxvalloc_c

#define	ALSMID "visual"
#include "allocate.h"

#ifndef	allocate
#ifdef	UNIX
#define	mallocate(a) malloc(a)
#define mliberate(a) free(a)
#endif

void  * mallocate( int  );
void       mliberate( void  * );

#ifndef	UNIX
/* Maybe for TwinServer */
void  * malloc( int nb )
{
	return( mallocate( nb) );
}
void	free( void * vptr )
{
	if ( vptr )
		mliberate( vptr );
}
#endif

void  * allocate( int nb )
{
/*	void	 * vptr;*/
	return( mallocate(nb) );
/*
	if (!( vptr = mallocate( nb ) ))
		allocation_failure( nb );
	return( vptr);
*/
}

void  * liberate( void  * vptr )
{
	if ( vptr ) {
		mliberate( vptr );
		}
	return((void  *) 0);
}

#endif	/* ! allocate */

char *	drop_string( char * sptr )
{
	if ( sptr )
		liberate( sptr );
	return( (char *) 0 );
}

char *	allocate_string( char * sptr )
{
	char * bptr;
	if ((bptr = (char *) allocate( strlen( sptr ) + 1 )) != (char *) 0) 
		strcpy( bptr, sptr );
	return(bptr);
}

static	char * machinename=(char *) 0;

char *	set_machine_name( char * sptr )
{
	int	i;
	int	j;
	char *	mptr;

	if ( *sptr != 0x005C )
		return( sptr );
	else if ( *(sptr+1) != 0x005C )
		return( sptr );

	else	{
		for (i=2; *(sptr+i) != 0; i++ ) 
			if ( *(sptr+i) == 0x005C )
				break;
		if ( *(sptr+i) != 0x005C )
			return( sptr );

		i++;

		if (!( mptr = allocate( (i+1) )))
			return(sptr);
			
		for (j=0; j < i; j++ )
			*(mptr+j) = *(sptr+j);

		*(mptr+j) = 0;

		if ( machinename != (char *) 0 ) 
			machinename = liberate( machinename );

		machinename = mptr;

		return( (sptr+i) );

		}

}

char *	allocate_filename( char * sptr )
{
	char * bptr;

	if (!( machinename ))
		bptr = allocate_string( sptr );

	else if ((   *sptr   == 0x005C )
	     &&  ( *(sptr+1) == 0x005C )) {
		sptr = set_machine_name( sptr );
		bptr = allocate_filename( sptr );
		}

	else if ((bptr = (char *) allocate( (strlen( sptr ) + 1 +strlen(machinename) ) )) != (char *) 0) 
		sprintf(bptr,"%s%s",machinename,sptr);

	return(bptr);
}

#endif	/* _unxvalloc_c */

