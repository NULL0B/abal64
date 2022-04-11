#ifndef	_ldxref_c
#define	_ldxref_c

int	patchcounter=0;

REFERENCE *	allocate_reference()
{
	REFERENCE * rptr;
	if (!( rptr = allocate( sizeof( REFERENCE ) ) ))
		return( rptr );
	else	{
		rptr->next = rptr->prev = (REFERENCE*) 0;
		rptr->type = NUL_REFERENCE;
		rptr->value= 0;
		rptr->number=++patchcounter;
		reset_location( &rptr->patch );
		return( rptr );
		}
}

VOID	liberate_reference( REFERENCE * rptr )
{
	if ( rptr )
		liberate( rptr );
}

VOID	drop_references( REFERENCE * rptr )
{
	REFERENCE * wptr;
	while ((wptr = rptr) != (REFERENCE *) 0) {
		rptr = wptr->next;
		liberate_reference( wptr );
		}
	return;
}

private	void	add_internal( MODULE * mptr, REFERENCE * rptr )
{
	if (!( rptr->prev = mptr->relocations.last ))
		mptr->relocations.root = rptr;
	else	mptr->relocations.last->next = rptr;
	mptr->relocations.last = rptr;
	return;
}

private	int load_word_relocation( MODULE * mptr, EXAWORD type, EXAWORD sector )
{
	EXAWORD		rid;
	EXAWORD		sid;
	REFERENCE *	rptr;
	EXAWORD	status;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "relocation table : sector =%un", sector);
		issue_message(4, ErrorBuffer);
		}
	if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
		return( status );
	while ((rid = buffer_getw( mptr )) != mptr->minusone) {
		while ((sid = buffer_getw(mptr)) != mptr->minusone) {
			if (!( sid )) {
				/* sector zero : end of list */
				break;
				}
			else if (!( rptr = allocate_reference() ))
				return( report_error(163,mptr->rootname));
			else 	{
				add_internal( mptr, rptr );
				rptr->value = rid;
				rptr->type  = type;
				rptr->patch.sector = sid;
				if (((rptr->patch.length = buffer_getw(mptr)) & 0xFF00) != 0)   {
					if ( type == INT_VARIABLE ) {
						rptr->type = GDS_OFFSET;
						rptr->patch.length &= 0x00FF;
						}
					else if ( type == EXT_VARIABLE ) {
						rptr->type = XDS_OFFSET;
						rptr->patch.length &= 0x00FF;
						}

					else 	return( report_error( 203, mptr->rootname ) );
					}
				if ( Linker.sourcetrace ) {
					sprintf(ErrorBuffer, "relocation record (%u) : type=%u, sector=%u, offset=%x, value=%u",
						rptr->number,
						rptr->type,
						rptr->patch.sector,
						rptr->patch.length,
						rptr->value );
					issue_message(4, ErrorBuffer);
					}
				}
			}
		}
	return(0);
}

private	int load_byte_relocation( MODULE * mptr, EXAWORD type, EXAWORD sector )
{
	EXAWORD		rid;
	EXAWORD		sid;
	REFERENCE *	rptr;
	EXAWORD	status;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "byte type relocation table : sector =%u",sector);
		issue_message(4, ErrorBuffer);
		}
	if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
		return( status );
	while ((rid = buffer_getb( mptr )) != 0x00FF) {
		if ((sid = buffer_getw(mptr)) == mptr->minusone)
			break;
		else if (!( rptr = allocate_reference() )) 
			return( report_error(163,mptr->rootname));
		else 	{
			add_internal( mptr, rptr );
			rptr->value = rid;
			rptr->type  = type;
			rptr->patch.sector = sid;
			rptr->patch.length = buffer_getw(mptr);
			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "relocation record[%u] : type=%u, sector=%u, offset=%x, value=%u",
					rptr->number,
					rptr->type,
					rptr->patch.sector,
					rptr->patch.length,
					rptr->value );
				issue_message(4, ErrorBuffer);
				}
			}
		}
	return(0);
}

REFERENCE *	load_references( MODULE * mptr, LOCATION * sptr )
{
	REFERENCE * root=(REFERENCE*) 0;
	REFERENCE * last=(REFERENCE*) 0;
	REFERENCE * rptr=(REFERENCE*) 0;
	WORD		status;
	BYTE	    ltype;
	if ( sptr->sector != 0 ) {	

		if ((status = load_buffer( mptr, mptr->dbhandle, sptr->sector )) != 0) {
			(void)report_error(164,mptr->rootname);
			return( root );
			}
		while ((ltype = buffer_getb( mptr )) != NUL_REFERENCE) {
			if (!( rptr = allocate_reference())) {
				(void)report_error(163,mptr->rootname);
				return( root );
				}
			switch ( ltype ) {
				case	INT_PROCEDURE	:
				case	INT_SEGMENT	:
					add_internal( mptr, rptr );
					break;
				default			:
					if (!(rptr->prev = last)) {	
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
			if ( Linker.verbose & 32 ) {
				switch ( rptr->type ) {
					case	INT_PROCEDURE 	:
						sprintf(ErrorBuffer, "record(%) iprc v(%x) p(%u,%x)",
							rptr->number,
							rptr->value,
							rptr->patch.sector,
							rptr->patch.length);
						issue_message(0, ErrorBuffer);
						break;
					case	EXT_PROCEDURE 	:
						sprintf(ErrorBuffer, "record(%u) xprc v(%x) p(%u,%x)",
							rptr->number,
							rptr->value,
							rptr->patch.sector,
							rptr->patch.length);
						issue_message(0, ErrorBuffer);
						break;
					case	INT_SEGMENT 	:
						sprintf(ErrorBuffer, "record(%u) iseg v(%x) p(%u,%x)",
							rptr->number,
							rptr->value,
							rptr->patch.sector,
							rptr->patch.length);
						issue_message(0, ErrorBuffer);
						break;
					case	EXT_SEGMENT 	:
						sprintf(ErrorBuffer, "record(%u) xseg v(%x) p(%u,%x)",
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
		if ( Linker.verbose & 32 ) {
			if ( root )
				issue_message(0, "}");
			}
		}
	return( root );
}

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
		sptr = sptr->next ) {
		if (!( rptr = allocate_reference() ))
			return(report_error(163,mptr->rootname));
		else	{
			add_internal( mptr, rptr );
			if ( report ) {
				sprintf(ErrorBuffer, "record(%u) BXReloc(t=%u,v=%x,s=%u,o=%u)",
					rptr->number,type,value,sptr->detail.sector,sptr->detail.length);
				issue_message(0, ErrorBuffer);
				}
			rptr->type = type;
			rptr->value = value;
			rptr->patch.sector = sptr->detail.sector;
			if (((rptr->patch.length = sptr->detail.length) & 0xFF00) == 0xFF00) {
				if ( type == EXT_VARIABLE ) {
					rptr->type = XDS_OFFSET;
					rptr->patch.length &= 0x00FF;
					rptr->value = alternative;
					}
				else if ( type == INT_VARIABLE ) {
					rptr->type = GDS_OFFSET;
					rptr->patch.length &= 0x00FF;
					}
				}
			}

		}
	return( 0 );
}

#endif	/* _ldxref_c */


