#ifndef	_ldbuffer_c
#define	_ldbuffer_c


private	EXAWORD	read_buffer( struct module * mptr )
{
	if (!( mptr->bhandle )) 
		return(51);	
	else if (!( read_tcode( mptr->bhandle, mptr->bsector, mptr->buffer, 256 ) )) {
		mptr->bhandle = (FILE*) 0;
		return(53);
		}
	else	{
		mptr->bindex  = 0;
		mptr->bsector++;
		return(0);
		}
}

private	EXAWORD	load_buffer( struct module * mptr, FILE * handle, EXAWORD sector )
{
	mptr->bhandle = handle;
	mptr->bsector = sector;
	mptr->bindex  = 0;
	return( read_buffer( mptr ) );
}

EXAWORD	buffer_getb( struct module * mptr ) 
{
	if (!( mptr->bhandle ))
		return(0);
	else if (( mptr->bindex >= 256 ) 
	     &&  ( read_buffer( mptr ) ))
		return( 0 );
	else	return( (mptr->buffer[ mptr->bindex++ ] & 0x00FF));
}

BPTR	buffer_gets( struct module * mptr ) 
{
	WORD	i;
	
	for (i=0; i < 1023; i++ )
		if (!( workbuffer[i] = buffer_getb( mptr ) ))
			break;
	workbuffer[i] = 0;
	return( allocate_string( workbuffer ) );	
}

EXAWORD	buffer_getw( struct module * mptr ) 
{
	EXAWORD	r=0;
	r =   buffer_getb(mptr);
	r |= (buffer_getb(mptr) << 8);
	if ( mptr->wordsize > 2 ) {
		r |= (buffer_getb(mptr) << 16);
		r |= (buffer_getb(mptr) << 24);
		}
	return( r );
}

#endif	/* _ldbuffer_c */

