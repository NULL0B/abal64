#ifndef	_ALLOCATE_C
#define	_ALLOCATE_C

extern	VOID FPTR malloc( int  );
extern	VOID free( VOID FPTR );

VOID FPTR allocate( int  bytes )
{
	return( malloc( bytes ) );
}

VOID FPTR liberate( VOID FPTR vptr )
{
	if ( vptr )
		free( vptr );
	return((VOID FPTR)0);
}


#endif	/* _ALLOCATE_C */
	/* ----------- */
