#ifndef	_TRAPLIO_C
#define	_TRAPLIO_C

#define ENCODE 	1
#define	DECODE	0

// --------------------------------------------------
// define this constant to activate detailled tracing
// of both ouput to and input from an APL.
// --------------------------------------------------
#undef _TRACE_TRAPLIO

#ifdef	_TRACE_TRAPLIO
#define apl_trace(a) printf(a)
#else
#define apl_trace(a) 
#endif

/*	--------------------	*/
/*	translate_target_end	*/
/*	--------------------	*/
static	WORD	translate_target_end()
{
	WORD	status;
	if (!( get_token() ))
		return( syntax_error( 1001 ) );
	else if ( uppercase_compare( TokenBuffer, "END" ) ) 
	{
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

/*	----------------	*/
/*	await_target_end	*/
/*	----------------	*/
WORD	await_target_end()
{
	push_operation_pointer();
	set_operation_pointer(translate_target_end);
	return( 0 );
}

/*	--------	*/
/*	apl_seek	*/
/*	--------	*/
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
	else if ( AplHandle->sector != sector ) 
	{
		/* ------------------------------------------------ */
		/* the version 64 bit can use 512 byte blocks with  */
		/* offsets greater than 256 so this adjusts better  */
		/* ------------------------------------------------ */
		while ( offset > 256 ) { offset -= 256; sector++; }
#ifdef	_TRACE_TRAPLIO
		sysprintf("becomes apl_seek(%u,%u)\n",sector,offset);
#endif
		lseek( AplHandle->handle, (LONG) LongMul( 256L, sector), 0 );
		if ( read( AplHandle->handle, AplHandle->buffer, 256 ) != 256)
			return( 48 );
		if ( sector == 0 ) 
		{
			if ( *(AplHandle->buffer) == '4' )
				AplHandle->WordSize = 8;
			else if ( *(AplHandle->buffer) == '3' )
				AplHandle->WordSize = 4;
			else	AplHandle->WordSize = 2; 
			(void) abal_crypt( 1958,(BPTR) (AplHandle->buffer + 18), (2+(21*AplHandle->WordSize)), DECODE );
		}
		else if ( AplHandle->CryptCode  != MOINS_UN ) 
		{
			(void) abal_crypt( AplHandle->CryptCode,AplHandle->buffer,256, DECODE );
		}
		
	}
	AplHandle->sector = sector;
	AplHandle->offset = offset;
	return( 0 );
}

/*	-----------------	*/
/*	apl_input_symbols	*/
/*	-----------------	*/
static	APLSYMBPTR	apl_input_symbols()
{
	if ( AplHandle != (APLPTR) 0 )
		return( AplHandle->Symbolic );
	else	return( (APLSYMBPTR) 0 );
}

/*	----------------	*/
/*	set_input_symbol	*/
/*	----------------	*/
static	WORD	set_input_symbol( aptr )
APLSYMBPTR	aptr;
{
	if ( AplHandle != (APLPTR) 0 ) 
	{
		aptr->next = AplHandle->Symbolic;
		AplHandle->Symbolic = aptr;
	}
	return( 0 );
}

/*	-----------------	*/
/*	set_output_symbol	*/
/*	-----------------	*/
static	WORD	set_output_symbol( aptr )
APLSYMBPTR	aptr;
{
	if ((aptr->next = AplSymbol) !=(APLSYMBPTR) 0)
		aptr->logical = (aptr->next->logical + 1);
	else	aptr->logical = 1;
	AplSymbol = aptr;
	return( 0 );
}

/*	--------------------	*/
/*	set_input_encryption	*/
/*	--------------------	*/
static	WORD	set_input_encryption( valeur )
WORD	valeur;
{
	if ( AplHandle != (APLPTR) 0 )
		AplHandle->CryptCode = valeur;
	return( 0 );
}

/*	-----------------	*/
/*	set_input_options	*/
/*	-----------------	*/
static	WORD	set_input_options( valeur )
WORD	valeur;
{
	if ( AplHandle != (APLPTR) 0 )
		AplHandle->Options = valeur;
	return( 0 );
}

/*	---------------		*/
/*	reset_apl_input 	*/
/*	---------------		*/
static	VOID	reset_apl_input( iptr )
APLPTR		iptr;
{
	iptr->handle = MOINS_UN;
	iptr->sector = MOINS_UN;
	iptr->offset = MOINS_UN;
	return;
}

/*	--------	*/
/*	apl_open	*/
/*	--------	*/
static	WORD	apl_open( filename )
BPTR	filename;
{
	APLPTR	iptr;
	WORD	l;

	if ((iptr = (APLPTR) allocate( sizeof( struct apl_input ) )) == (APLPTR) 0)
		return( allocation_failure() );
	else	
	{
		iptr->name   = (BPTR) 0;
		iptr->next   = (APLPTR) 0;
		iptr->CryptCode = MOINS_UN;
		iptr->Options   = 0;
		iptr->Symbolic  = (APLSYMBPTR) 0;
		reset_apl_input( iptr );
	}

	if ((l = fn_parser( filename, iptr->buffer, 0x0010 )) == 0) 
	{

		if ((l = fn_parser( filename, iptr->buffer, 0x000F )) == 0)
			return( syntax_error( 7004 ) );
		strcat( iptr->buffer,".apl");
	}
	else	strcpy(iptr->buffer, filename );

	if ((l = evaluate_filename( iptr->buffer )) != 0)
		return( syntax_error( 7005 ) );
	else if ((iptr->name = allocate_for_string( iptr->buffer )) == (BPTR) 0)
		return( allocation_failure() );
	else	
	{
		iptr->next = AplHandle;
		AplHandle  = iptr;
		return( apl_seek( 0, 0 ) );
	}
}

/*	---------	*/
/*	apl_close	*/
/*	---------	*/
static	VOID	apl_close()
{
	if ( AplHandle->handle != MOINS_UN )
		close( AplHandle->handle );
	reset_apl_input( AplHandle );
	return;
}

/*	----------------	*/
/*	apl_drop_symbols	*/
/*	----------------	*/
static	WORD	apl_drop_symbols( sptr )
APLSYMBPTR	sptr;
{
	APLSYMBPTR	wptr;
	while ((wptr = sptr) != (APLSYMBPTR) 0) 
	{
		sptr = sptr->next;
		liberate( wptr );
	}
	return( 0 );
}

/*	--------	*/
/*	apl_drop	*/
/*	--------	*/
static	VOID	apl_drop()
{
	APLPTR	iptr;
	if (AplHandle != (APLPTR) 0) 
	{
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

/*	------------	*/
/*	apl_get_byte	*/
/*	------------	*/
static	WORD	apl_get_byte()
{
	WORD	status;
	if (AplHandle->offset >= 256 )
		if  ((status = apl_seek( AplHandle->sector+1,0 )) != 0)
			return( MOINS_UN );
	return( *( AplHandle->buffer + AplHandle->offset++ ) );	
}

/*	------------	*/
/*	apl_get_word	*/
/*	------------	*/
static	WORD	apl_get_word()
{
	WORD	c;
	c = apl_get_byte();
	c |= ( apl_get_byte() << 8 );
	if ( AplHandle->WordSize > _SIZE_INT16 ) 
	{
		c |= ( apl_get_byte() << 16 );
		c |= ( apl_get_byte() << 24 );
		if ( AplHandle->WordSize > _SIZE_INT32 ) 
		{
			c |= ( apl_get_byte() << 32 );
			c |= ( apl_get_byte() << 40 );
			c |= ( apl_get_byte() << 48 );
			c |= ( apl_get_byte() << 56 );
		}
	}
#ifdef	_TRACE_TRAPLIO
	sysprintf("apl_get_word( %u, 0x%08X )\n",c,c);
#endif
	return( c );
}

/*	------------	*/
/*	apl_get_long	*/
/*	------------	*/
static	LONG	apl_get_long()
{
	return(((LONG) apl_get_word()));
}

/*	--------------	*/
/*	apl_get_string	*/
/*	--------------	*/
static	WORD	apl_get_string()
{
	WORD	l=0;
	WORD	c;
	TokenHash = 0;
	while ((c = apl_get_byte()) != 0) 
	{
		TokenBuffer[l++] = c;
		TokenHash += c;
	}
	TokenBuffer[l] = 0;
#ifdef	_TRACE_TRAPLIO
	sysprintf("apl_get_string( %s )\n",TokenBuffer);
#endif
	return( l );
}

/*	------------	*/
/*	apl_put_byte	*/
/*	------------	*/
static	WORD	apl_put_byte(c)
WORD	c;
{
	tcputbyte( c );
	return( 0 );
}

/*	------------	*/
/*	apl_put_word	*/
/*	------------	*/
static	WORD	apl_put_word( i )
WORD	i;
{
#ifdef	_TRACE_TRAPLIO
	sysprintf("apl_put_word( %lu, 0x%08X )\n",i,i);
#endif
	tcputword( i );
	return( 0 );
}

/*	------------	*/
/*	apl_put_long	*/
/*	------------	*/
static	WORD	apl_put_long( l )
LONG	l;
{
#ifdef	_TRACE_TRAPLIO
	sysprintf("apl_put_word( %lu, 0x%08X )\n",l,l);
#endif
	tcputword((WORD) l);
	return( 0 );
}

/*	--------------	*/
/*	apl_put_string	*/
/*	--------------	*/
static	WORD	apl_put_string(s)
BPTR	s;
{
#ifdef	_TRACE_TRAPLIO
	sysprintf("apl_put_string( %s )\n",s);
#endif
	tcode_string( s );
	return( 0 );
}

/*	-------------------	*/
/*	apl_option_symbolic	*/
/*	-------------------	*/
static	WORD	apl_option_symbolic()
{
	if ( AplHandle != (APLPTR) 0 )
		return( (AplHandle->Options & 1) );
	else	return( 0 );
}

/*	-----------------	*/
/*	library_file_name	*/
/*	-----------------	*/
BPTR	library_file_name()
{
	if ( AplHandle != (APLPTR) 0 )
		return(AplHandle->name);
	else	return( (BPTR) 0 );
}

	/* ---------- */
#endif	/* _TRAPLIO_C */
	/* ---------- */
