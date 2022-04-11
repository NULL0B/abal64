#ifndef	_TRTEXT_C
#define	_TRTEXT_C

TCTEXTPTR	liberate_text_value( tptr )
TCTEXTPTR	tptr;
{
	if ( tptr != (TCTEXTPTR) 0 ) {
		if ( tptr->users )
			tptr->users--;
		else	{
			if ( tptr->buffer != (VALUEPTR) 0 )
				tptr->buffer = liberate_value( tptr->buffer );
			liberate( tptr );
			}
		}
	return( (TCTEXTPTR) 0 );
}


TCTEXTPTR	allocate_text_value()
{
	TCTEXTPTR	tptr;
	trace("allocate_text_value(");
	if ((tptr = (TCTEXTPTR) allocate( sizeof( struct tcode_text_value ) )) != (TCTEXTPTR) 0) {
		tptr->users = 0;
		if ((tptr->buffer = allocate_for_value()) == (VALUEPTR) 0)
			return( liberate_text_value( tptr ) );
		}
	return( tptr );
}

TCTEXTPTR	copy_text_value( tptr )
TCTEXTPTR	tptr;
{
	if ( tptr != (TCTEXTPTR) 0)
		tptr->users++;
	return( tptr );
}

#endif	/* _TRTEXT_C */
	/* --------- */



