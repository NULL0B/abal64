#ifndef	_TRAPLIO_C
#define	_TRAPLIO_C


#define ENCODE 	1
#define	DECODE	0

static	WORD	translate_target_end()
{
	WORD	status;
	if (!( get_token() ))
		return( syntax_error( 1001 ) );
	else if ( uppercase_compare( TokenBuffer, "END" ) ) {
		if ((status = translate_end()) != 0)
			return( status );
#ifdef	ABAL33A
		else	return( instance_library_extension() );
#else
		else	return(status);
#endif
		}
	else	return( syntax_error( 10001 ) );
	
}

WORD	await_target_end()
{
	push_operation_pointer();
	set_operation_pointer(translate_target_end);
	return( 0 );
}

static	WORD	apl_seek( sector, offset )
WORD	sector;
WORD	offset;
{
#ifdef	_TRACE_TRAPLIO
	sysprintf("apl_seek(%u,%u)\n",sector,offset);
#endif
	if (( AplHandle->handle == MOINS_UN )
	&&  ((AplHandle->handle = use_library_path /* was open */ ( AplHandle->name, O_RDONLY | O_BINARY )) == MOINS_UN))
		return( internal_error( 7002 ) );
	else if ( AplHandle->sector != sector ) {
		lseek( AplHandle->handle, (LONG) LongMul( 256L, sector), 0 );
		if ( read( AplHandle->handle, AplHandle->buffer, 256 ) != 256 )
			return( 48 );
		if ( sector == 0 ) {
			if ( *(AplHandle->buffer) >= '3' )
				AplHandle->WordSize = 4;
			else	AplHandle->WordSize = 2; 
			(void) abal_crypt( 1958,(BPTR) (AplHandle->buffer + 18), (2+(21*AplHandle->WordSize)), DECODE );
			}
		else if ( AplHandle->CryptCode  != MOINS_UN ) {
			(void) abal_crypt( AplHandle->CryptCode,AplHandle->buffer,256, DECODE );
			}
		
		}
	AplHandle->sector = sector;
	AplHandle->offset = offset;
	return( 0 );
}

static	APLSYMBPTR	apl_input_symbols()
{
	if ( AplHandle != (APLPTR) 0 )
		return( AplHandle->Symbolic );
	else	return( (APLSYMBPTR) 0 );
}

static	WORD	set_input_symbol( aptr )
APLSYMBPTR	aptr;
{
	if ( AplHandle != (APLPTR) 0 ) {
		aptr->next = AplHandle->Symbolic;
		AplHandle->Symbolic = aptr;
		}
	return( 0 );
}

static	WORD	set_output_symbol( aptr )
APLSYMBPTR	aptr;
{
	if ((aptr->next = AplSymbol) !=(APLSYMBPTR) 0)
		aptr->logical = (aptr->next->logical + 1);
	else	aptr->logical = 1;
	AplSymbol = aptr;
	return( 0 );
}


static	WORD	set_input_encryption( valeur )
WORD	valeur;
{
	if ( AplHandle != (APLPTR) 0 )
		AplHandle->CryptCode = valeur;
	return( 0 );
}

static	WORD	set_input_options( valeur )
WORD	valeur;
{
	if ( AplHandle != (APLPTR) 0 )
		AplHandle->Options = valeur;
	return( 0 );
}


static	VOID	reset_apl_input( iptr )
APLPTR		iptr;
{
	iptr->handle = MOINS_UN;
	iptr->sector = MOINS_UN;
	iptr->offset = MOINS_UN;
	return;
}

static	WORD	apl_open( filename )
BPTR	filename;
{
	APLPTR	iptr;
	WORD	l;

	if ((iptr = (APLPTR) allocate( sizeof( struct apl_input ) )) == (APLPTR) 0)
		return( allocation_failure() );
	else	{
		iptr->name   = (BPTR) 0;
		iptr->next   = (APLPTR) 0;
		iptr->CryptCode = MOINS_UN;
		iptr->Options   = 0;
		iptr->Symbolic  = (APLSYMBPTR) 0;
		reset_apl_input( iptr );
		};
	
	if ((l = fn_parser( filename, iptr->buffer, 0x0010 )) == 0) {
		if ((l = fn_parser( filename, iptr->buffer, 0x000F )) == 0)
			return( syntax_error( 7004 ) );
		strcat( iptr->buffer,".apl");
		}
	else	strcpy(iptr->buffer, filename );

	if ((l = evaluate_filename( iptr->buffer )) != 0)
		return( syntax_error( 7005 ) );
	else if ((iptr->name = allocate_for_string( iptr->buffer )) == (BPTR) 0)
		return( allocation_failure() );
	else	{
		iptr->next = AplHandle;
		AplHandle  = iptr;
		return( apl_seek( 0, 0 ) );
		}
}

static	VOID	apl_close()
{
	if ( AplHandle->handle != MOINS_UN )
		close( AplHandle->handle );
	reset_apl_input( AplHandle );
	return;
}

static	WORD	apl_drop_symbols( sptr )
APLSYMBPTR	sptr;
{
	APLSYMBPTR	wptr;
	while ((wptr = sptr) != (APLSYMBPTR) 0) {
		sptr = sptr->next;
		liberate( wptr );
		}
	return( 0 );
}

static	VOID	apl_drop()
{
	APLPTR	iptr;
	if (AplHandle != (APLPTR) 0) {
		apl_close();
		iptr = AplHandle->next;
		if ( AplHandle->name != (BPTR) 0 )
			liberate( AplHandle->name );
		apl_drop_symbols( AplHandle->Symbolic );
		liberate( AplHandle );
		AplHandle = iptr;
		}
	return;
}

static	WORD	apl_get_byte()
{
	WORD	status;
	if ((AplHandle->offset >= 256)
	&&  ((status = apl_seek( AplHandle->sector+1,0 )) != 0))
		return( MOINS_UN );
	else 	return( *( AplHandle->buffer + AplHandle->offset++ ) );	
}

static	WORD	apl_get_word()
{
	WORD	c;
	c = apl_get_byte();
	c |= ( apl_get_byte() << 8 );
	if ( AplHandle->WordSize > 2 ) {
		c |= ( apl_get_byte() << 16 );
		c |= ( apl_get_byte() << 24 );
		}
	return( c );
}

static	LONG	apl_get_long()
{
	return(((LONG) apl_get_word()));
}


static	WORD	apl_get_string()
{
	WORD	l=0;
	WORD	c;
	TokenHash = 0;
	while ((c = apl_get_byte()) != 0) {
		TokenBuffer[l++] = c;
		TokenHash += c;
		}
	TokenBuffer[l] = 0;
	return( l );
}

static	WORD	apl_put_byte(c)
WORD	c;
{
	tcputbyte( c );
	return( 0 );
}

static	WORD	apl_put_word( i )
WORD	i;
{
	tcode_integer( i );
	return( 0 );
}

static	WORD	apl_put_long( l )
LONG	l;
{
	tcode_integer((WORD) l);
	return( 0 );
}

static	WORD	apl_put_string(s)
BPTR	s;
{
	tcode_string( s );
	return( 0 );
}

static	WORD	apl_option_symbolic()
{
	if ( AplHandle != (APLPTR) 0 )
		return( (AplHandle->Options & 1) );
	else	return( 0 );
}

BPTR	library_file_name()
{
	if ( AplHandle != (APLPTR) 0 )
		return(AplHandle->name);
	else	return( (BPTR) 0 );
}


#endif	/* _TRAPLIO_C */
	/* ---------- */


