#ifndef	_ldtcode_c
#define	_ldtcode_c

VOID	tcode_version_three( MODULE * mptr )
{
	mptr->wordsize = 4;
	mptr->minusone = 0xFFFFFFFFL;
	return;
}

VOID	tcode_version_two  ( MODULE * mptr )
{
	mptr->wordsize = 2;
	mptr->minusone = 0x0000FFFFL;
	return;
}


EXAWORD	write_tcode( FILE * h, EXAWORD s, BPTR buffer, EXAWORD length )
{
	int	i;
	char	tmp[10];
	fseek( h, (s * 256L), SEEK_SET );
	if ( fwrite( buffer, length, 1 , h ) == 1 ) {
		if ( Linker.targettrace ) {
			sprintf(ErrorBuffer, "\nwrite_tcode : s=%u, l=%u ", s, length);
			issue_message(5, ErrorBuffer);
			*ErrorBuffer = '\0';
			for (i=0; i < length; i++ ) {
				sprintf(tmp, "%02.1x ", *(buffer+i));
				strcat(ErrorBuffer, tmp);
				if (i && !( i % 16 )) {
					issue_message(0, ErrorBuffer);
					*ErrorBuffer = '\0';
					}
				}
			}
		return( 0 );
		}
	else	return( 46 );
}


private	BPTR	read_tcode( FILE * handle, EXAWORD sector, BPTR buffer, EXAWORD length )
{
	fseek( handle, sector*256L, SEEK_SET );
	if ( fread( buffer, length, 1, handle ) == 1 )
		return( buffer );
	else	return((BPTR) 0);
}

BPTR	tcputword( BPTR bptr, EXAWORD v, int ws )
{
	int	i;
	for ( i=0; i < ws; i++ ) {
		*(bptr++) = (v & 0x00FF);
		v >>= 8;
		}
	return( bptr );
}

BPTR	tcputlong( BPTR bptr, EXAWORD v )
{
	return( tcputword( bptr, v, sizeof( long )) );
}

EXAWORD	tcgetword( BPTR bptr, int ws )
{
	EXAWORD	r;
	r = *(bptr++);
	r |= ( (*(bptr++) & 0x00FF) << 8);
	if ( ws > 2 ) {
		r |= ( (*(bptr++) & 0x00FF) << 16);
		r |= ( (*(bptr++) & 0X00FF) << 24);
		}
	return( r );
}

WORD	handle_overspill( 	MODULE * mptr, 	REFERENCE * rptr, 
				BPTR buffer,	EXAWORD buflen  	)
{
	EXAWORD	v;
	/* watch out for overflow */
	Linker.overspill++;
	memset( mptr->spillzone,0,mptr->wordsize);
		if (( Linker.targettrace ) ||  ( Linker.verbose & 4 )) {
		sprintf(ErrorBuffer, "OverSpill( sector=%u, offset=%d )", rptr->patch.sector, rptr->patch.length);
			issue_message(5, ErrorBuffer);
			}
	/* detect erroneous values */
	if ( rptr->patch.length > 256 ) {
		return( 55 );		
		}
	memcpy( mptr->spillzone,(buffer+rptr->patch.length),(buflen - rptr->patch.length));
	switch (rptr->type) {
		case	EXT_PROCEDURE	:
		case	EXT_SEGMENT	:
		case	EXT_CONSTANT	:
		case	EXT_VARIABLE	:
		case	XDS_OFFSET  	:
		case	INT_SEGMENT	:
			tcputword( mptr->spillzone,rptr->value,mptr->wordsize );
			break;

		case	INT_PROCEDURE	:
			v = tcgetword( mptr->spillzone,mptr->wordsize );
			v += mptr->PdtAdjust; 
			tcputword( mptr->spillzone,v,mptr->wordsize );
			break;
		case	INT_CONSTANT	:
			v = tcgetword( mptr->spillzone,mptr->wordsize );
			v += mptr->GctAdjust; 
			tcputword( mptr->spillzone,v,mptr->wordsize );
			break;
		case	INT_VARIABLE	:
			v = tcgetword( mptr->spillzone,mptr->wordsize );
			v += mptr->GdtAdjust; 
			tcputword( mptr->spillzone,v,mptr->wordsize );
			break;
		case	GDS_OFFSET  	:
			v = tcgetword( mptr->spillzone,mptr->wordsize );
			v += mptr->GdsAdjust; 
			tcputword( mptr->spillzone,v,mptr->wordsize );
			break;
		}
	memcpy( (buffer+rptr->patch.length),mptr->spillzone,(buflen-rptr->patch.length));
	return(0);
}

VOID	handle_underspill( 	MODULE * mptr, 	REFERENCE * rptr, 
				BPTR buffer,	EXAWORD buflen  	)
{
	EXAWORD	v;

	switch (rptr->type) {
		case	INT_PROCEDURE	:
		case	INT_CONSTANT	:
		case	GDS_OFFSET	:
		case	INT_VARIABLE	:
			v = tcgetword( mptr->spillzone,mptr->wordsize );
			memset( mptr->spillzone, 0, mptr->wordsize );
			memcpy((mptr->spillzone+(buflen-rptr->patch.length)),buffer,((rptr->patch.length+mptr->wordsize)-buflen));
			v += tcgetword( mptr->spillzone,mptr->wordsize );
			tcputword( mptr->spillzone, v, mptr->wordsize );
		}
	memcpy(buffer,(mptr->spillzone+(256-rptr->patch.length)),((rptr->patch.length+mptr->wordsize)-256));
	mptr->overspill = (REFERENCE *) 0;
	return;
}

WORD	relocate_tcode( MODULE * mptr, EXAWORD sector, BPTR buffer, EXAWORD buflen )
{
	REFERENCE	*	rptr;
	EXAWORD			v, v2;
	EXAWORD			status=0;

	for (	rptr=mptr->relocations.root;
		rptr != (REFERENCE*)0;
		rptr = rptr->next ) {
	
		if ( rptr->patch.sector != sector )
			continue;

		if (( Linker.targettrace ) ||  ( Linker.verbose & 4 )) {
			sprintf(ErrorBuffer, "record(%u) patch sector %u,%x t=%u, v=%x",
				rptr->number,
				rptr->patch.sector,rptr->patch.length,
				rptr->type,rptr->value);
			issue_message(5, ErrorBuffer);
			}

		if ( rptr->type == EXT_LIBRARY ) {
			*(buffer + rptr->patch.length) = rptr->value;
			}
		else if ( rptr->type == INT_LIBRARY ) {
			*(buffer + rptr->patch.length) = rptr->value;
			}
		else	{
			if (( rptr->patch.length + mptr->wordsize ) > buflen ) {
				if ((status = handle_overspill( mptr,(mptr->overspill=rptr), buffer, buflen )) != 0)
					return(status);
				}

			else	{			
				v = tcgetword((buffer+rptr->patch.length),mptr->wordsize);

				switch ( rptr->type ) {
					case	EXT_PROCEDURE	:
					case	EXT_SEGMENT	:
					case	EXT_CONSTANT	:
					case	EXT_VARIABLE	:
					case	XDS_OFFSET	:
					case	INT_SEGMENT	:
						v = rptr->value;
						break;

					case	INT_PROCEDURE	:
						v += mptr->PdtAdjust;
						break;
					case	INT_CONSTANT	:
						if ( Linker.targettrace ) {
							v2 = v+mptr->GctAdjust; 
							sprintf(ErrorBuffer, "internal constant from %s(%u+%u)=%u", mptr->rootname, v, mptr->GctAdjust,v2);
							issue_message(5, ErrorBuffer);
							}
						v += mptr->GctAdjust; 
						break;
					case	GDS_OFFSET	:
						if ( Linker.targettrace ) {
							v2 = v+mptr->GdsAdjust;
							sprintf(ErrorBuffer, "optimised variable offset %s(%u+%u)=%u", mptr->rootname, v, mptr->GdtAdjust, v2);
							issue_message(5, ErrorBuffer);
							}
						v += mptr->GdsAdjust; 
						break;

					case	INT_VARIABLE	:
						if ( Linker.targettrace ) {
							v2 = v+mptr->GdtAdjust; 
							sprintf(ErrorBuffer, "internal variable from %s(%u+%u)=%u", mptr->rootname, v, mptr->GdtAdjust, v2);
							issue_message(5, ErrorBuffer);
							}
						v += mptr->GdtAdjust; 
						break;
					}
				tcputword( (buffer+rptr->patch.length),v,mptr->wordsize);
				}
			}
		}
	return(0);
		
}

EXAWORD	copy_local_names( 	MODULE * toptr, MODULE * fromptr, 
				LOCATION * tptr, LOCATION * sptr )
{
	EXAWORD	status;

	if ( Linker.targettrace )
		issue_message(5, "Local Names Table");

	if ((status = load_buffer( fromptr, fromptr->dbhandle, sptr->sector )) != 0)
		return( report_error( 165, fromptr->rootname ) );
	else if ((status = buffer_start( toptr, toptr->dbhandle, tptr )) != 0)
		return( report_error( 166,toptr->rootname ) );

	while ( buffer_getq(fromptr) != 0 ) {
		buffer_putq(toptr);
		buffer_putw(toptr, buffer_getw(fromptr) );
		}
	buffer_putw( toptr, 0 );
	debug_flush( toptr );
	return(0);
}

EXAWORD	copy_tcode( MODULE * toptr, MODULE * fromptr, LOCATION * lptr, int iscode, LOCATION * stats )
{
	BPTR			bptr;
	LOCATION		target;
	LOCATION		source;
	LOCATION		snames;
	LOCATION		tnames;
	EXAWORD			status;
	EXAWORD			started=0;

	if ( stats ) {
		stats->sector = stats->length = 0;
		}

	/* illegal sector or no length : do nothing */
	/* ---------------------------------------- */
	if ((!( lptr->sector ))
	||  (!( lptr->length ))) 
		return(0);

	if ((!( fromptr->athandle ))
	&&  ((status = open_tcode_source( fromptr )) != 0)) 
		return( status );

	next_free_location(&target);

	reset_location(&snames);
	reset_location(&tnames);
	reset_location(&source);

	fromptr->overspill= (REFERENCE*)0;

	while ( target.length < lptr->length ) {

		if ((bptr =  read_tcode( 
				fromptr->athandle, lptr->sector+source.sector,
				fromptr->buffer, 256 )) == (BPTR) 0) {
			status = 53;
			break;
			}

		switch ( iscode ) {
			case	1 :	/* instructions need relocation */
				if ( fromptr->overspill )
					handle_underspill(fromptr,fromptr->overspill,fromptr->buffer,256);
				if ((status = relocate_tcode( fromptr,lptr->sector+source.sector,fromptr->buffer,256)) != 0)
					return(status );
				else	break;
			case	2 :	/* local variables and names */
				if (!( started )) {
					if ( stats ) {
						stats->sector =tcgetword(fromptr->buffer,fromptr->wordsize);
						stats->length =tcgetword((fromptr->buffer+(fromptr->wordsize*2)),fromptr->wordsize);
						}
					if (((snames.sector = tcgetword((fromptr->buffer+fromptr->wordsize),fromptr->wordsize)) != 0)
					&&  ((snames.length = tcgetword(fromptr->buffer,fromptr->wordsize)) != 0)) {
						next_debug_location(&tnames);
						tcputword( fromptr->buffer+fromptr->wordsize,tnames.sector,fromptr->wordsize);
						}
					}
			}

		if ((status = write_tcode(		
				toptr->athandle, target.sector+source.sector,
				bptr, 256 )) != 0) {
			break;
			}
		target.length += 256;
		if ( target.length > lptr->length )
			target.length= lptr->length;
		source.sector++;
		started=1;
		}

	if ( status != 0 ) {
		return( status );
		}
	else	{
		copy_location( lptr, &target );
		consume_location( &source );
		if ( iscode == 2 ) {
			if (( snames.sector != 0 )
			&&  ( tnames.sector != 0 ))  {
				if ((!( fromptr->dbhandle ))
				&&  ((status = open_debug_source( fromptr )) != 0)) 
					return( status );
				status = copy_local_names( toptr, fromptr, &tnames, &snames); 
				}
			}
		return( status );
		}
}


EXAWORD	copy_correspondance( MODULE * mptr, MODULE * hptr, LOCATION * lptr )
{
	EXAWORD	status;
	EXAWORD	v;
	EXAWORD i;
	EXAWORD	snumber;
	EXAWORD	tnumber;
	LOCATION target;
	NAMES		*	nptr=(NAMES*)0;
	if (!( Linker.debug ))
		return(0);
	if (!( hptr ))
		return(0);
	if (!( lptr->sector ))
		return(0);
	else if (!( lptr->length ))
		return(0);
	else	{
		if ( Linker.targettrace )
			issue_message(5, "Correspondance Table");

		if (!( hptr->dbhandle ))
			if ((status = open_debug_source( hptr )) != 0)
				return( status );
		snumber = tnumber = mptr->minusone;
		reset_location( &target);
		next_debug_location( &target);

		if ( Linker.targettrace ) {
			sprintf(ErrorBuffer, "copying corrspondances from %s(%u,%u)",
				hptr->rootname,lptr->sector,lptr->length,
				mptr->rootname);
			issue_message(5, ErrorBuffer);
			}
		if ((status = load_buffer( hptr, hptr->dbhandle, lptr->sector )) != 0)
			return( report_error( 167, hptr->rootname) );
		else if ((status = buffer_start( mptr, mptr->dbhandle, &target )) != 0)
			return( report_error( 168,mptr->rootname) );

		lptr->sector = target.sector;

		while ((v = buffer_getw(hptr)) != hptr->minusone) {
			if ((!( nptr ))
			|| ( v != nptr->number )) {
				nptr = resolve_filename(hptr, v );
				if ( Linker.targettrace ) {
					if ( nptr ) {
						sprintf(ErrorBuffer, "correspondance file %s was %u is %u", nptr->name, nptr->number, nptr->alternative);
						issue_message(5, ErrorBuffer);
						}
					}
				}
			if (!( nptr ))
				tnumber = v;
			else	tnumber = nptr->alternative;

			buffer_putw(mptr,tnumber);
			for ( i = 0; i < 3; i++ )
				buffer_putw( mptr,(v = buffer_getw( hptr )));
			}		
		buffer_putw(mptr,mptr->minusone);
		debug_flush( mptr );
		lptr->length = target.length;
		if ( Linker.targettrace ) {
			sprintf(ErrorBuffer, "to %s(%u,%u)", mptr->rootname, lptr->sector, lptr->length);
			issue_message(5, ErrorBuffer);
			}
		return(0);
		}		
}

EXAWORD	tcsector( BPTR bptr, int ws )
{
	EXAWORD	r;
	r = tcgetword(bptr, ws );
	if ( ws == 2 ) {
		if ( r  == 0xFFFF)
			return(0);
		else	return(r);
		}
	else if ( r == 0xFFFFFFFF )
		return(0);
	else	return(r);			
}

EXAWORD	tclength( BPTR bptr, int ws )
{
	EXAWORD	r;
	r = tcgetword(bptr, ws );
	if ( ws == 2 ) {
		if ( r  == 0xFFFF)
			return(0);
		else	return(r);
		}
	else if ( r == 0xFFFFFFFF )
		return(0);
	else	return(r);			
}

private	BPTR	load_tcode( FILE * handle, EXAWORD sector, EXAWORD length )
{
	BPTR	buffer;
	if (!( length ))
		return((BPTR) 0);
	else if (!( buffer = allocate( length )))
		return( buffer );
	else if (!( read_tcode( handle, sector, buffer, length ) )) {
		liberate( buffer );
		return((BPTR) 0);
		}
	else	return( buffer );
}

#endif	/* _ldtcode_c */

