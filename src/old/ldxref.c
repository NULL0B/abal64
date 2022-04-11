#ifndef	_ldxref_c
#define	_ldxref_c

/*	------------------------------------	*/
/*			O L D			*/
/*	------------------------------------	*/
/*	Linker Externam Reference Management  	*/
/*	------------------------------------	*/
/*		Iain James Marshall		*/
/*	------------------------------------	*/

int	patchcounter=0;

/*	------------------	*/
/*	allocate_reference	*/
/*	------------------	*/
REFERENCE *	allocate_reference()
{
	REFERENCE * rptr;
	if (!( rptr = allocate( sizeof( REFERENCE ) ) ))
		return( rptr );
	else	
	{
		rptr->next = rptr->prev = (REFERENCE*) 0;
		rptr->type = NUL_REFERENCE;
		rptr->value= 0;
		rptr->number=++patchcounter;
		reset_location( &rptr->patch );
		return( rptr );
	}
}

/*	------------------	*/
/*	liberate_reference	*/
/*	------------------	*/
VOID	liberate_reference( REFERENCE * rptr )
{
	if ( rptr )
		liberate( rptr );
}

/*	-----------------	*/
/*	 drop_references	*/
/*	-----------------	*/
VOID	drop_references( REFERENCE * rptr )
{
	REFERENCE * wptr;
	while ((wptr = rptr) != (REFERENCE *) 0) 
	{
		rptr = wptr->next;
		liberate_reference( wptr );
	}
	return;
}

/*	------------------------	*/
/*	relocation_variable_name	*/
/*	------------------------	*/
private	void relocation_variable_name( BPTR buffer, MODULE * mptr, WORD variable )
{
	VARIABLE * vptr;

               
	for (   vptr = mptr->variables.root;
		vptr != (VARIABLE*) 0;
		vptr = vptr->next )
		if ( vptr->identity == variable )
			break;

	if ( vptr )
	{
		strcat( buffer, " : ");
		strcat( buffer, vptr->name );
	}
	return;
}

/*	------------	*/
/*	add_internal	*/
/*	------------	*/
private	void	add_internal( MODULE * mptr, REFERENCE * rptr )
{
	if (!( rptr->prev = mptr->relocations.last ))
		mptr->relocations.root = rptr;
	else	mptr->relocations.last->next = rptr;
	rptr->parent = mptr;
	mptr->relocations.last = rptr;
	return;
}

/*	------------------------	*/
/*	symbolic_relocation_type	*/
/*	------------------------	*/
private char *	symbolic_relocation_type(int type)
{
	switch ( type & NUL_REFERENCE )
	{
	case	NUL_REFERENCE 	: return("NULLREF");
	case	EXT_REFERENCE 	: return("EXTREF");
	case	REF_PROCEDURE 	: return("PRCREF");
	case	REF_SEGMENT 	: return("SEGREF");
	case	REF_CONSTANT 	: return("CONREF");
	case	REF_VARIABLE 	: return("VARREF");
	case	REF_LIBRARY  	: return("LIBREF");
	case	GDS_OFFSET 	: return("GDSREF");
	case	XDS_OFFSET 	: return("XDSREF");
	default			: return("WHTREF");
	}
}

/*	--------------------	*/
/*	load_word_relocation	*/
/*	--------------------	*/
private	int load_word_relocation( MODULE * mptr, EXAWORD type, EXAWORD sector )
{
	EXAWORD		rid;
	EXAWORD		sid;
	REFERENCE *	rptr;
	EXAWORD	status;

	if ( Linker.sourcetrace ) 
	{
		sprintf(ErrorBuffer, "relocation table : sector =%llu", sector);
		issue_message(4, ErrorBuffer);
	}

	if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
		return( status );

	while ((rid = buffer_getw( mptr )) != mptr->minusone) 
	{
		while ((sid = buffer_getw(mptr)) != mptr->minusone) 
		{
			if (!( sid )) 
			{
				/* sector zero : end of list */
				break;
			}
			else if (!( rptr = allocate_reference() ))
				return( report_error(163,mptr->rootname));
			else 	
			{
				add_internal( mptr, rptr );
				rptr->value = rid;
				rptr->type  = type;
				rptr->patch.sector = sid;
				if (((rptr->patch.length = buffer_getw(mptr)) & 0xFE00) != 0)   
				{
					if ( type == INT_VARIABLE ) 
					{
						rptr->type = GDS_OFFSET;
						rptr->patch.length &= 0x01FF;
					}
					else if ( type == EXT_VARIABLE ) 
					{
						rptr->type = XDS_OFFSET;
						rptr->patch.length &= 0x01FF;
					}
					else 	return( report_error( 203, mptr->rootname ) );
				}
				if ( Linker.sourcetrace ) 
				{
					/* ----------------------------------- */
					/* generate the relocation information */
					/* ----------------------------------- */
					sprintf(ErrorBuffer, "word relocation record (%llu) : type=%u(%s), sector=%llu, offset=%llx, value=%llx",
						rptr->number,
						rptr->type, symbolic_relocation_type(rptr->type),
						rptr->patch.sector,
						rptr->patch.length,
						rptr->value );
					/* ----------------------------------------- */
					/* add variable identity if it is a variable */
					/* ----------------------------------------- */
					if ( rptr->type == REF_VARIABLE )
					{
						relocation_variable_name(ErrorBuffer, mptr, rptr->value);
					}
					issue_message(4, ErrorBuffer);
				}
			}
		}
	}
	return(0);
}

/*	--------------------	*/
/*	load_byte_relocation	*/
/*	--------------------	*/
private	int load_byte_relocation( MODULE * mptr, EXAWORD type, EXAWORD sector )
{
	EXAWORD		rid;
	EXAWORD		sid;
	REFERENCE *	rptr;
	EXAWORD	status;

	if ( Linker.sourcetrace ) 
	{
		sprintf(ErrorBuffer, "byte type relocation table : sector =%llu",sector);
		issue_message(4, ErrorBuffer);
	}

	if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
		return( status );

	while ((rid = buffer_getb( mptr )) != 0x00FF) 
	{
		if ((sid = buffer_getw(mptr)) == mptr->minusone)
			break;
		else if (!( rptr = allocate_reference() )) 
			return( report_error(163,mptr->rootname));
		else 	
		{
			add_internal( mptr, rptr );
			rptr->value = rid;
			rptr->type  = type;
			rptr->patch.sector = sid;
			rptr->patch.length = buffer_getw(mptr);
			if ( Linker.sourcetrace ) 
			{
				sprintf(ErrorBuffer, "byte relocation record[%llu] : type=%u(%s), sector=%llu, offset=%llx, value=%llu",
					rptr->number,
					rptr->type,symbolic_relocation_type(rptr->type),
					rptr->patch.sector,
					rptr->patch.length,
					rptr->value );
				issue_message(4, ErrorBuffer);
			}
		}
	}
	return(0);
}

/*	-----------------	*/
/*	 load_references	*/
/*	-----------------	*/
REFERENCE *	load_references( MODULE * mptr, LOCATION * sptr )
{
	REFERENCE * root=(REFERENCE*) 0;
	REFERENCE * last=(REFERENCE*) 0;
	REFERENCE * rptr=(REFERENCE*) 0;
	WORD		status;
	BYTE	    ltype;
	if ( sptr->sector != 0 ) 
	{
		if ((status = load_buffer( mptr, mptr->dbhandle, sptr->sector )) != 0) 
		{
			(void)report_error(164,mptr->rootname);
			return( root );
		}
		while ((ltype = buffer_getb( mptr )) != NUL_REFERENCE) 
		{
			if (!( rptr = allocate_reference())) 
			{
				(void)report_error(163,mptr->rootname);
				return( root );
			}
			switch ( ltype ) 
			{
			case	INT_PROCEDURE	:
			case	INT_SEGMENT	:
				add_internal( mptr, rptr );
				break;
			default			:
				if (!(rptr->prev = last)) 
				{
					if ( Linker.verbose & 32 )
						issue_message(0, "{");
					root = rptr;
				}
				else	last->next = rptr;
				last = rptr;
			}
			rptr->type  = ltype;
			rptr->value = buffer_getw( mptr );
			rptr->patch.sector = buffer_getw( mptr );
			rptr->patch.length = buffer_getw( mptr );
			if ( Linker.verbose & 32 ) 
			{
				switch ( rptr->type ) 
				{
				case	INT_PROCEDURE 	:
					sprintf(ErrorBuffer, "record(%llu) iprc v(%llx) p(%llu,%llx)",
						rptr->number,
						rptr->value,
						rptr->patch.sector,
						rptr->patch.length);
					issue_message(0, ErrorBuffer);
					break;
				case	EXT_PROCEDURE 	:
					sprintf(ErrorBuffer, "record(%llu) xprc v(%llx) p(%llu,%llx)",
						rptr->number,
						rptr->value,
						rptr->patch.sector,
						rptr->patch.length);
					issue_message(0, ErrorBuffer);
					break;
				case	INT_SEGMENT 	:
					sprintf(ErrorBuffer, "record(%llu) iseg v(%llx) p(%llu,%llx)",
						rptr->number,
						rptr->value,
						rptr->patch.sector,
						rptr->patch.length);
					issue_message(0, ErrorBuffer);
					break;
				case	EXT_SEGMENT 	:
					sprintf(ErrorBuffer, "record(%llu) xseg v(%llx) p(%llu,%llx)",
						rptr->number,
						rptr->value,
						rptr->patch.sector,
						rptr->patch.length);
					issue_message(0, ErrorBuffer);
					break;
				default			:
					sprintf(ErrorBuffer," XRF: 0x%x(%u) unkown external type \n", rptr->type,rptr->type);
					issue_message(0, ErrorBuffer);
					(void)report_error(55,mptr->rootname);
					return(root);
				}	
			}
		}	
		if ( Linker.verbose & 32 ) 
		{
			if ( root )
				issue_message(0, "}");
		}
	}
	return( root );
}

/*	-------------------------	*/
/*	build_external_relocation	*/
/*	-------------------------	*/
public	int	build_external_relocation(
		MODULE *	mptr,
		EXAWORD		type,
		EXAWORD		value,
		EXAWORD		alternative,
		RELOCATION * 	root,
		EXAWORD		report )
{
	RELOCATION	* sptr;
	REFERENCE 	* rptr;
	for (	sptr=root;
		sptr != (RELOCATION*) 0;
		sptr = sptr->next ) 
	{
		if (!( rptr = allocate_reference() ))
			return(report_error(163,mptr->rootname));
		else	
		{
			add_internal( mptr, rptr );
			if ( report ) 
			{
				sprintf(ErrorBuffer, "record(%llu) BXReloc(t=%llu,v=%llx,s=%llu,o=%llu)",
					rptr->number,type,value,sptr->detail.sector,sptr->detail.length);
				issue_message(0, ErrorBuffer);
			}
			rptr->type = type;
			rptr->value = value;
			rptr->patch.sector = sptr->detail.sector;
			if (((rptr->patch.length = sptr->detail.length) & 0xFF00) == 0xFF00) 
			{
				if ( type == EXT_VARIABLE ) 
				{
					rptr->type = XDS_OFFSET;
					rptr->patch.length &= 0x00FF;
					rptr->value = alternative;
				}
				else if ( type == INT_VARIABLE ) 
				{
					rptr->type = GDS_OFFSET;
					rptr->patch.length &= 0x00FF;
				}
			}
		}

	}
	return( 0 );
}

#endif	/* _ldxref_c */


