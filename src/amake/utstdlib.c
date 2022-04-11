
WORD	Mstrlen( sptr )
BPTR	sptr;
{
	WORD	length=0;
	while ( *(sptr++) )
		length++;
	return( length );
}
		
BPTR	Mmemcpy( rptr, sptr, l )
BPTR	rptr;
BPTR	sptr;
WORD	l;
{
	BPTR	tptr;
	tptr = rptr;
	for ( ; l != 0; l-- )
		*(tptr++) = *(sptr++);
	return( rptr );
}

BPTR	Mstrcpy( rptr, sptr )
BPTR	rptr;
BPTR	sptr;
{
	BPTR	tptr;
	tptr = rptr;
	while ( *sptr )
		*(tptr++) = *(sptr++);
	*tptr = 0;
	return( tptr );
}

BPTR	Mstrcat( rptr, sptr )
BPTR	rptr;
BPTR	sptr;
{
	BPTR	tptr;
	tptr = rptr;
	while ( *rptr )
		rptr++;
	(void) Mstrcpy( rptr, sptr );
	return( tptr );
}




