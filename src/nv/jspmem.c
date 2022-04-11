void * malloc( int );
void   free( void * );

void *	liberate( void * vptr )
{
	free( vptr );
	return( (void *) 0 );
}

void *	allocate( int bnb )
{
	return( malloc( bnb ) );
}


