#ifndef	_ldcons_c
#define	_ldcons_c

/*	------------------------------------	*/
/*			O L D			*/
/*	------------------------------------	*/
/*	Management of Global Constant Tables	*/
/*	------------------------------------	*/
/*		Iain James Marshall		*/
/*	------------------------------------	*/

/*	--------------	*/
/*	drop_constants	*/
/*	--------------	*/
private	void	drop_constants ( MODULE * mptr )
{
	if ( mptr->gct )
		liberate( mptr->gct );
	return;
}

/*	--------------	*/
/*	load_constants	*/
/*	--------------	*/
private	int load_constants ( MODULE * mptr )
{
	EXAWORD	sector;
	if (((mptr->constable.sector = tcsector( &mptr->atheader[(TCPREFIX + (1*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
	&&  ((mptr->constable.length = tclength( &mptr->atheader[(TCPREFIX + (2*mptr->wordsize)+2)],mptr->wordsize )) != 0 )) 
	{
		if ( Linker.sourcetrace ) 
		{
			sprintf(ErrorBuffer, "gct       : sector =%llu, length =%llu",mptr->constable.sector,mptr->constable.length);
			issue_message(4, ErrorBuffer);
		}
		if ((mptr->gct = load_tcode( mptr->athandle, mptr->constable.sector, mptr->constable.length )) != (BPTR) 0) 
		{
			if ((sector = tcsector( &mptr->dbheader[(TCPREFIX + (16*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
				return(load_word_relocation(mptr,INT_CONSTANT,sector));
			else	return(0);
		}
		else	return(report_error(195,"load cons" ) );
	}
	else	return(0);
}

/*	--------------------	*/
/*	start_constant_table	*/
/*	--------------------	*/
EXAWORD	start_constant_table( MODULE * mptr ) 
{
	if( Linker.targettrace )
		issue_message(5, "Constant Table");
	reset_location(&mptr->constable);
	next_free_location(&mptr->constable);
	buffer_start( mptr, mptr->athandle, &mptr->constable );
	return(0);
}

/*	----------------	*/
/*	output_constants	*/
/*	----------------	*/
EXAWORD	output_constants( MODULE * rptr, MODULE * sptr )
{
	BPTR		dptr;
	EXAWORD		conadjust=0;
	EXAWORD		i;
	EXAWORD		l;
	unsigned long	new_table_size=0L;
	
	if (!( dptr = sptr->gct )) 
		return(0);

	sptr->GctAdjust = rptr->GctLimit;

	i=0; 

	while ( i < sptr->constable.length ) 
	{
		if ((l = *(dptr+i)) != 0 ) 
		{
			/* its a string */
			buffer_putb(rptr,l);
			buffer_put(rptr,(dptr+i+1),l);
			i += (l+1);
		}
		else if ((l = *(dptr+i+1)) != 0 ) 
		{
			/* its bcd */
			buffer_putb(rptr,0);
			buffer_putb(rptr,l);
			buffer_put(rptr,(dptr+i+2),l);
			i += (l+2);
		}
		else	break;
	}
	
	new_table_size = rptr->GctLimit;
	new_table_size += sptr->constable.length;

	if ( rptr->wordsize > 2 ) 
	{
		rptr->GctLimit += sptr->constable.length;
		return(0);
	}

	else if ( new_table_size & OVERFLOW16 )
		return( linker_error(208) );
	else	
	{
		rptr->GctLimit += sptr->constable.length;
		return(0);
	}
}

/*	--------------------	*/
/*	close_constant_table	*/
/*	--------------------	*/
EXAWORD	close_constant_table( MODULE * mptr ) 
{
	buffer_flush( mptr );
	return(0);
}

/*	------------------------	*/
/*	old_copy_local_constants	*/
/*	------------------------	*/
WORD	old_copy_local_constants(
	MODULE * rptr,
	MODULE * sptr,
	LOCATION * lptr )
{
	return( copy_tcode( rptr, sptr, lptr, 0,(LOCATION *) 0) );
}

/*	--------------------	*/
/*	copy_local_constants	*/
/*	--------------------	*/
WORD	copy_local_constants(
	MODULE * mptr,
	MODULE * hptr,
	LOCATION * lptr )
{
	EXAWORD	status;
	EXAWORD offset=0;
	EXAWORD clength;
	EXAWORD coffset;
	EXAWORD i;
	LOCATION target;

	if (!( hptr ))
		return(0);
	if (!( lptr->sector ))
		return(0);
	else if (!( lptr->length ))
		return(0);
	else	
	{
		if ( Linker.targettrace )
			issue_message(5, "Local Constant Table");

		if (!( hptr->athandle ))
			if ((status = open_tcode_source( hptr )) != 0)
				return( status );

		reset_location( &target);
		next_free_location( &target);

		if ((status = load_buffer( hptr, hptr->athandle, lptr->sector )) != 0)
			return( linker_error(169) );
		else if ((status = buffer_start( mptr, mptr->athandle, &target )) != 0)
			return( linker_error( 170) );

		lptr->sector = target.sector;
		
		while ( offset < lptr->length ) 
		{
			if ((clength = buffer_getb( hptr )) != 0) 
			{
				/* its a string */
				buffer_putb( mptr, clength );
				for ( i=0; i < clength; i++ )
					buffer_putb( mptr, buffer_getb( hptr ) );
				offset += (clength+1);
			}
			else if (!((clength = buffer_getb( hptr )) & 0x0080)) 
			{
				/* its a bcd */
				buffer_putb( mptr, 0 );
				buffer_putb( mptr, clength );
				for ( i=0; i < clength; i++ ) 
					buffer_putb( mptr, buffer_getb( hptr ) );
				offset += (clength+2);
				}
			else	
			{
				/* Global redirection requiring relocation */
				coffset = buffer_getw( hptr );
				coffset += hptr->GctAdjust;
				buffer_putb( mptr, 0 );
				buffer_putb( mptr, 0x0080 );
				buffer_putw( mptr, coffset );
				offset += (2 + hptr->wordsize);			
			}
		}		

		buffer_flush( mptr );
		lptr->length = target.length;
		return(0);
	}		
}

#endif	/* _ldcons_c */

