#ifndef	_zalloc_c
#define	_zalloc_c


#include "allocate.h"

#ifndef	UNIX

#ifndef	WIN32
void PTR	malloc( int  );
void		free( void PTR );
#endif

void PTR allocate( unsigned int nb )
{
	void	PTR vptr;
	vptr = malloc( nb );
	return( vptr);
}

void PTR liberate( void PTR vptr )
{
	if ( vptr ) {
		free( vptr );
		}
	return((void PTR) 0);
}

#endif

BPTR	drop_string( BPTR sptr )
{
	if ( sptr )
		sptr = liberate( sptr );
	return( sptr );
}
BPTR	allocate_string( BPTR sptr )
{
	BPTR bptr;
	if ((bptr = (BPTR) allocate( strlen( sptr ) + 1 )) != (BPTR) 0) 
		strcpy( bptr, sptr );
	return(bptr);
}

static	BPTR machinename=(BPTR) 0;

BPTR	set_machine_name( BPTR sptr )
{
	int	i;
	int	j;
	BPTR	mptr;

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

		if ( machinename != (BPTR) 0 ) 
			machinename = liberate( machinename );

		machinename = mptr;

		return( (sptr+i) );

		}

}

BPTR	allocate_filename( BPTR sptr )
{
	BPTR bptr;

	if (!( machinename ))
		bptr = allocate_string( sptr );

	else if ((   *sptr   == 0x005C )
	     &&  ( *(sptr+1) == 0x005C )) {
		sptr = set_machine_name( sptr );
		bptr = allocate_filename( sptr );
		}

	else if ((bptr = (BPTR) allocate( (strlen( sptr ) + 1 +strlen(machinename) ) )) != (BPTR) 0) 
		sprintf(bptr,"%s%s",machinename,sptr);

	return(bptr);
}

#endif	/* _zalloc_c */

