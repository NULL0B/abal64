extern	void * malloc( unsigned int nb );
extern	void   free( void * vptr );

void __far* __far __cdecl _fmalloc( unsigned int n )
{

	return( malloc( n ) );
}

void	__far __cdecl _ffree( void __far* vptr )
{
	free( vptr );
	return;
}


