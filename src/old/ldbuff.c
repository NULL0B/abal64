#ifndef	_ldbuffer_c
#define	_ldbuffer_c


private	EXAWORD	write_buffer( MODULE * mptr )
{
	if (!( mptr->bhandle )) 
		return(51);	

	else if (!( write_tcode( mptr->bhandle, mptr->bsector+mptr->boutput->sector, mptr->buffer, mptr->sectorsize ) )) {
		mptr->CryptCode += mptr->bindex;
		mptr->bsector += (mptr->sectorsize/256);
		mptr->boutput->length += mptr->bindex;
		mptr->bindex  = 0;
		memset( mptr->buffer, 0x00FF, mptr->sectorsize);
		return(0);
		}
	else	{
		mptr->bhandle = (FILE*) 0;
		return(46);
		}
}

private	EXAWORD	read_buffer( MODULE * mptr )
{
	if (!( mptr->bhandle )) 
		return(51);	
	else if (!( read_tcode( mptr->bhandle, mptr->bsector, mptr->buffer,  mptr->sectorsize) )) {
		mptr->bhandle = (FILE*) 0;
		return(53);
		}
	else	{
		mptr->bindex  = 0;
		mptr->bsector += (mptr->sectorsize/256);
		return(0);
		}
}

private	EXAWORD	load_buffer( MODULE * mptr, FILE * handle, EXAWORD sector )
{
	mptr->bhandle = handle;
	mptr->bsector = sector;
	mptr->bindex  = 0;
	return( read_buffer( mptr ) );
}

EXAWORD	buffer_getb( MODULE * mptr ) 
{
	if (!( mptr->bhandle ))
		return(0);
	else if (( mptr->bindex >=  mptr->sectorsize) 
	     &&  ( read_buffer( mptr ) ))
		return( 0 );
	else	return( (mptr->buffer[ mptr->bindex++ ] & 0x00FF));
}

BPTR	buffer_gets( MODULE * mptr ) 
{
	WORD	i;
	
	for (i=0; i < 1023; i++ )
		if (!( workbuffer[i] = buffer_getb( mptr ) ))
			break;
	workbuffer[i] = 0;
	return( allocate_string( workbuffer ) );	
}

EXAWORD	buffer_getq( MODULE * mptr ) 
{
	WORD	i;
	
	for (i=0; i < 1023; i++ )
		if (!( workbuffer[i] = buffer_getb( mptr ) ))
			break;
	workbuffer[i] = 0;
	return( i );
}

EXAWORD	buffer_getw( MODULE * mptr ) 
{
	EXAWORD	r=0;
	r =   buffer_getb(mptr);
	r |= (buffer_getb(mptr) << 8);
	if ( mptr->wordsize > 2 ) 
	{
		r |= (buffer_getb(mptr) << 16);
		r |= (buffer_getb(mptr) << 24);
	}
	if ( mptr->wordsize > 4 ) 
	{
		r |= (buffer_getb(mptr) << 32);
		r |= (buffer_getb(mptr) << 40);
		r |= (buffer_getb(mptr) << 48);
		r |= (buffer_getb(mptr) << 56);
	}
	return( r );
}

VOID	buffer_putb( MODULE * mptr, BYTE c ) 
{
	if (!( mptr->bhandle ))
		return;

	mptr->buffer[ mptr->bindex++ ] = (c & 0x00FF);

	if ( mptr->bindex >=  mptr->sectorsize ) 
		write_buffer( mptr );
}

VOID	buffer_putq( MODULE * mptr ) 
{
	WORD	i;
	
	for (i=0; i < 1023; i++ ) {
		buffer_putb( mptr, workbuffer[i] );
		if (!( workbuffer[i] ))
			break;
		}
	return;
}

VOID	buffer_putw( MODULE * mptr, EXAWORD v )
{
	int	i;
	for (i=0; i < mptr->wordsize; i++ ) {
		buffer_putb(mptr,(v & 0x00FF));
		v >>= 8;
		}
	return;
}

VOID	buffer_putlocation( MODULE * mptr, LOCATION * lptr )
{
	buffer_putw( mptr, lptr->sector );
	buffer_putw( mptr, lptr->length );
	return;
}

VOID	buffer_puts( MODULE * mptr, BPTR sptr )
{
	while ( *sptr != 0 )
		buffer_putb( mptr, *(sptr++) );
	buffer_putb( mptr, 0 );
}

VOID	buffer_put( MODULE * mptr, BPTR sptr, EXAWORD slen )
{
	EXAWORD	i;
	for ( i= 0; i < slen; i++ )
		buffer_putb( mptr, *(sptr+i) );
	return;
}

EXAWORD	buffer_start( MODULE * mptr, FILE* h, LOCATION * lptr )
{
	mptr->boutput = lptr;
	memset( mptr->buffer, 0xFF,  mptr->sectorsize );
	mptr->bhandle = h;
	mptr->bindex  = 0;
	mptr->bsector = 0;
	return( 0 );
}


EXAWORD	buffer_flush( MODULE * mptr )
{
	LOCATION	bidon;
	if ( mptr->bhandle ) {
		if ( mptr->bindex ) 
			write_buffer( mptr );
		reset_location(&bidon);

		if (!( mptr->boutput->length ))
			mptr->boutput->sector = 0;

		bidon.sector = mptr->bsector;
		consume_location( &bidon );
		mptr->boutput = (LOCATION*)0;
		mptr->bindex = mptr->bsector = 0;
		mptr->bhandle= (FILE *) 0;
		}
	return( 0 );
}

EXAWORD	debug_flush( MODULE * mptr )
{
	LOCATION	bidon;
	if ( mptr->bhandle ) {
		if ( mptr->bindex ) 
			write_buffer( mptr );
		reset_location(&bidon);

		if (!( mptr->boutput->length ))
			mptr->boutput->sector = 0;

		bidon.sector = mptr->bsector;
		consume_debug_location( &bidon );
		mptr->boutput = (LOCATION*)0;
		mptr->bindex = mptr->bsector = 0;
		mptr->bhandle= (FILE *) 0;
		}
	return( 0 );
}

#endif	/* _ldbuffer_c */

