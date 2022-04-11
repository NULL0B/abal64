#ifndef	_ldvarb_c
#define	_ldvarb_c

/*	------------------------------------	*/
/*			O L D			*/
/*	------------------------------------	*/
/*	Management of Global Variable Tables	*/
/*	------------------------------------	*/
/*		Iain James Marshall		*/
/*	------------------------------------	*/

/*	----------	*/
/*	drop_label	*/
/*	----------	*/
VOID	drop_label( DATALABEL * lptr ) 
{
	if ( lptr ) 
	{
		if ( lptr->name )
			liberate( lptr->name );
		liberate( lptr );
	}
	return;
}

/*	-----------	*/
/*	drop_labels	*/
/*	-----------	*/
VOID	drop_labels( MODULE * mptr )
{
	DATALABEL * lptr;
	while ((lptr = mptr->labels.root) != (DATALABEL*)0) 
	{
		mptr->labels.root = lptr->next;
		drop_label( lptr );
	}
	
	mptr->labels.root=
	mptr->labels.last=(DATALABEL*)0;
	return;
}

/*	--------------	*/
/*	allocate_label	*/
/*	--------------	*/
DATALABEL	*	allocate_label()
{
	DATALABEL *	lptr;
	if (!( lptr = allocate( sizeof( DATALABEL ) )))
		return( lptr );
	else	
	{
		lptr->prev = lptr->next = (DATALABEL*)0;
		lptr->name = (BPTR) 0;
		lptr->extra = lptr->value = lptr->type = 0;
		return( lptr );
	}
}

/*	-----------------	*/
/*	allocate_variable	*/
/*	-----------------	*/
VARIABLE	*	allocate_variable()
{
	VARIABLE	*	vptr;
	if (!( vptr = allocate( sizeof( VARIABLE ) )))
		return( vptr );
	else	
	{
		vptr->next = vptr->prev = (VARIABLE*) 0;
		vptr->name = (BPTR) 0;
		vptr->identity = 0;
		vptr->offset = 0;
		vptr->copy = 0;
		vptr->type = vptr->length = vptr->first = vptr->second = 0;
		vptr->relocate	= (RELOCATION*)0;
		vptr->host 	= (MODULE *) 0;
		return( vptr );
	}
}

/*	-------------	*/
/*	copy_variable	*/
/*	-------------	*/
VARIABLE	*	copy_variable( VARIABLE * xptr )
{
	VARIABLE * vptr;
	if ((vptr = allocate_variable()) != (VARIABLE*) 0) 
	{
		vptr->next = vptr->prev = (VARIABLE*) 0;
		vptr->name = xptr->name;
		vptr->copy = 1; /* avoids liberate */
		vptr->identity	= xptr->identity;
		vptr->type 	= xptr->type;
		vptr->length 	= xptr->length;
		vptr->offset 	= xptr->offset;
		vptr->first 	= xptr->first;
		vptr->second	= xptr->second;
		vptr->relocate	= xptr->relocate;
		vptr->host	= xptr->host;
	}
	return( vptr );
}

/*	-----------------	*/
/*	liberate_variable	*/
/*	-----------------	*/
VARIABLE	*	liberate_variable( VARIABLE * vptr )
{
	if ( vptr ) 
	{
		if (!( vptr->copy )) 
		{
			if ( vptr->name )
				liberate( vptr->name );
			if ( vptr->relocate )
				drop_relocation( vptr->relocate );
		}
		liberate( vptr );
	}
	return((VARIABLE*) 0);
}

/*	--------------	*/
/*	drop_variables	*/
/*	--------------	*/
private	void	drop_variables ( MODULE * mptr )
{
	VARIABLE	*	vptr;

	while ((vptr = mptr->variables.root) != (VARIABLE *) 0) 
	{
		mptr->variables.root = vptr->next;
		liberate_variable( vptr );
	}

	if ( mptr->gvt )
		liberate( mptr->gvt );
	return;
}

/*	-------------------------	*/
/*	 drop_external_variables	*/
/*	-------------------------	*/
private	void	drop_external_variables ( MODULE * mptr )
{
	VARIABLE	*	vptr;

	while ((vptr = mptr->xvariables.root) != (VARIABLE *) 0) 
	{
		mptr->xvariables.root = vptr->next;
		liberate_variable( vptr );
	}

	if ( mptr->xvt )
		liberate( mptr->xvt );
	return;
}

/*	---------------------	*/
/*	collect_variable_type	*/
/*	---------------------	*/
private	void	collect_variable_type( VARIABLE * vptr, BPTR dptr, EXAWORD ws )
{
	vptr->type = tcgetword(dptr,ws); dptr += ws; 
	/* step over offset / host */
	switch ((vptr->type & SPECIALE)) 
	{
	case	ISDYNAMIC | ISPOINTER 		 :
	case	ISNORMAL	      		 :
		vptr->offset = tcgetword(dptr,ws);
		dptr+=ws;
		break;
	case	ISDYNAMIC | ISMEMBER  		 :
	case	ISDYNAMIC | ISMEMBER | ISPOINTER :
	case	ISETENDU			 :
	default					 :	
		dptr+=(ws*2);
	}
	/* collect length */
	switch ((vptr->type & VARBTYPE)) 
	{
	case	ABAL_INT8 	:	vptr->length = 1; break;
	case	ABAL_INT16	:	vptr->length = 2; break;
	case	ABAL_INT32	:	vptr->length = 4; break;
	case	ABAL_INT64	:	vptr->length = 8; break;
	case	ABAL_BCD  	:
	case	ABAL_STRING	:	vptr->length = tcgetword(dptr,ws);
					dptr += ws;
	}
	vptr->first = vptr->second = 1;
	if ( vptr->type & PRIMARY ) 
	{
		vptr->first = tcgetword(dptr,ws);
		dptr += ws;
		if ( vptr->type & SECONDARY )
			vptr->first = tcgetword(dptr,ws);
	}
	return;
}

/*	----------------	*/
/*	load_data_labels	*/
/*	----------------	*/
private	int load_data_labels ( MODULE * mptr, EXAWORD sector )
{
	EXAWORD		status;
	EXAWORD		number;
	EXAWORD		l;
	DATALABEL * 	lptr;
	if ((!( sector ))
	||  (!( mptr   )))
		return(0);
	if ( Linker.sourcetrace ) 
	{
		sprintf(ErrorBuffer, "glt : sector %llu", sector);
		issue_message(4, ErrorBuffer);
	}
	if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
		return( report_error(171, mptr->rootname ) );
	else if (!( number = buffer_getw( mptr ) ))
		return(0);
	if ( Linker.sourcetrace ) 
	{
		sprintf(ErrorBuffer, "label count %llu", number);
		issue_message(4, ErrorBuffer);
	}

	for ( l=0; l < number; l++ ) 
	{
		if (!( lptr = allocate_label() ))
			return( report_error( 172,mptr->rootname) );
		else if (!( mptr->labels.last ))
			mptr->labels.root = lptr;
		else	mptr->labels.last->next = lptr;
		lptr->prev = mptr->labels.last;
		mptr->labels.last = lptr;
		if (!( lptr->name = buffer_gets( mptr )))
			return( report_error( 173, mptr->rootname) );
		lptr->type = buffer_getb( mptr );
		lptr->value= buffer_getw( mptr );
		lptr->extra= buffer_getw( mptr );
		if ( Linker.sourcetrace ) 
		{
			sprintf(ErrorBuffer, "label %llu) %s=%llu at %llx:%llx",l,lptr->name,lptr->type,lptr->extra,lptr->value);
			issue_message(4, ErrorBuffer);
		}
	}
	return( 0 );
}

/*	---------------------	*/
/*	generate_variable_dcl	*/
/*	---------------------	*/
private	void generate_variable_dcl( BPTR buffer, BPTR prefix, VARIABLE * vptr )
{
	BPTR	kw;
	BPTR	kt;
	BYTE	extra[1024];
	// handle keyword
	if (vptr->type & ISPOINTER )
		kw = "ptr";
	else	kw = "dcl";
	// handle type
	switch ( (vptr->type & VARBTYPE) )
	{
	case	ABAL_INT8	: kt = "#"; break;
	case	ABAL_INT16	: kt = "%"; break;
	case	ABAL_INT32	: kt = ":"; break;
	case	ABAL_INT64	: kt = "&"; break;
	case	ABAL_STRING	: kt = "$"; break;
	case	ABAL_BCD	: 
	default			: kt = ""; break;
	}
	// generate basic variable
	sprintf(buffer, "%s%s %s%s",prefix,kw,vptr->name,kt);
	// handle length
	switch ( (vptr->type & VARBTYPE) )
	{
	case	ABAL_STRING	: 
	case	ABAL_BCD	: 
		sprintf(extra,"=%llu",vptr->length);
		strcat(buffer,extra);
	}
	// handle dimensions
	if (vptr->type & PRIMARY )
	{
		if (vptr->type & SECONDARY )
			sprintf(extra,"(%llu,%llu)",vptr->first,vptr->second);
		else	sprintf(extra,"(%llu)",vptr->first);
		strcat(buffer,extra);
	}
	sprintf(extra,"\t[%llx]",vptr->identity);
	strcat(buffer,extra);
	return;
}
	
/*	--------------	*/
/*	load_variables	*/
/*	--------------	*/
private	int load_variables ( MODULE * mptr )
{
	int	v;
	VARIABLE * vptr =(VARIABLE*)0;
	EXAWORD	sector;
	EXAWORD	status;

	if (((mptr->varbtable.sector = tcsector( &mptr->atheader[(TCPREFIX + (3*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
	&&  ((mptr->varbtable.length = tclength( &mptr->atheader[(TCPREFIX + (4*mptr->wordsize)+2)],mptr->wordsize )) != 0 )) 
	{
		if ((mptr->gvt = load_tcode( mptr->athandle, mptr->varbtable.sector, mptr->varbtable.length )) != (BPTR) 0) 
		{
			mptr->nbvarb     	= tclength( mptr->gvt ,mptr->wordsize );
			mptr->GdsLimit        	= tclength( (mptr->gvt + (mptr->wordsize*2)), mptr->wordsize);
			mptr->GdtLimit		= mptr->varbtable.length;
			if ( Linker.sourcetrace ) 
			{
				sprintf(ErrorBuffer, "gvt       : sector =%llu, length =%llu, variables : %llu, memory : %llu",
					mptr->varbtable.sector, mptr->varbtable.length, mptr->nbvarb, mptr->GdsLimit);
				issue_message(4, ErrorBuffer);
			}
			if (!(mptr->varbnames.sector	= tcsector( (mptr->gvt + (mptr->wordsize*1)), mptr->wordsize)))
				return(0);
			else if ((status = load_buffer( mptr, mptr->dbhandle, mptr->varbnames.sector )) != 0)
				return( report_error( 174, mptr->rootname ) );
			for ( v=0; v < mptr->nbvarb; v++ ) 
			{
				if (!( vptr = allocate_variable() ))
					return( report_error( 175, mptr->rootname) );
				else	vptr->host = mptr;
				if (!( vptr->prev = mptr->variables.last ))
					mptr->variables.root = vptr;
				else	mptr->variables.last->next = vptr;
				mptr->variables.last = vptr;
				if (!( vptr->name = buffer_gets( mptr )))
					return( report_error( 176, mptr->rootname) );
				else	vptr->identity = buffer_getw( mptr );
				collect_variable_type( vptr, (mptr->gvt + vptr->identity), mptr->wordsize );
				if ( Linker.sourcetrace ) 
				{
					generate_variable_dcl( ErrorBuffer, "", vptr );
					issue_message(4, ErrorBuffer);
				}
			}
			if ((sector = tcsector( &mptr->dbheader[(TCPREFIX + (41*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
				if (( status = load_data_labels(mptr,sector)) != 0)
					return( status );
			if ((sector = tcsector( &mptr->dbheader[(TCPREFIX + (15*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
				return(load_word_relocation(mptr,INT_VARIABLE,sector));
			else	return(0);
	
		}
		else	return( report_error( 190, mptr->rootname ) );
	}
	return(0);
}

/*	-------------------------	*/
/*	 load_external_variables	*/
/*	-------------------------	*/
private	int load_external_variables( MODULE * mptr )
{
	int	v;
	VARIABLE * vptr =(VARIABLE*)0;
	EXAWORD	status;
	if (((mptr->xvarbtable.sector = tcsector( &mptr->dbheader[(TCPREFIX + (42*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
	&&  ((mptr->xvarbtable.length = tclength( &mptr->dbheader[(TCPREFIX + (43*mptr->wordsize)+2)],mptr->wordsize )) != 0 )) 
	{
		if ((mptr->xvt = load_tcode( mptr->dbhandle, mptr->xvarbtable.sector, mptr->xvarbtable.length )) != (BPTR) 0) 
		{
			mptr->xnbvarb     	= tclength( mptr->xvt ,mptr->wordsize );
			mptr->xvarbnames.sector = tcsector( (mptr->xvt+mptr->wordsize) ,mptr->wordsize );
			if ( Linker.sourcetrace ) 
			{
				sprintf(ErrorBuffer, "xvt       : sector =%llu, length =%llu, variables : %llu",
					mptr->xvarbtable.sector,mptr->xvarbtable.length,mptr->xnbvarb);
				issue_message(4, ErrorBuffer);
			}
			if (!(mptr->xvarbnames.sector ))
				return(0);
			else if ((status = load_buffer( mptr, mptr->dbhandle, mptr->xvarbnames.sector )) != 0)
				return( report_error( 177, mptr->rootname ) );
			for ( v=0; v < mptr->xnbvarb; v++ ) 
			{
				if (!( vptr = allocate_variable() ))
					return( report_error( 178, mptr->rootname) );
				else if (!( mptr->xvariables.last ))
					mptr->xvariables.root = vptr;
				else	mptr->xvariables.last->next = vptr;
				vptr->prev = mptr->xvariables.last;
				mptr->xvariables.last = vptr;
				if (!( vptr->name = buffer_gets( mptr )))
					return( report_error( 179, mptr->rootname) );
				else	vptr->identity = buffer_getw( mptr );
				collect_variable_type( vptr, (mptr->xvt + vptr->identity), mptr->wordsize );
				if ( Linker.sourcetrace ) 
				{
					generate_variable_dcl( ErrorBuffer, "extern ", vptr );
					issue_message(4, ErrorBuffer);
				}
			}
		}
		else	return(report_error(191,mptr->rootname));
	}
	return(0);
}

/*	--------------	*/
/*	allocate_field	*/
/*	--------------	*/
private	FIELD *	allocate_field()
{
	FIELD	*	fptr;
	if ((fptr = allocate( sizeof( FIELD ))) != (FIELD *) 0) 
	{
		fptr->next = fptr->prev = (FIELD*)0;
		fptr->modname = (BPTR) 0;
		fptr->name = (BPTR) 0;
		fptr->state = 0;
		fptr->module = fptr->entry = fptr->loword= fptr->hiword =0;
		reset_location( &fptr->xvt );
		fptr->members.root = fptr->members.last = (VARIABLE*)0;
		fptr->host    =
		fptr->client  = (MODULE*)0;
		fptr->solution.root = fptr->solution.last = (SOLUTION*)0;
	}
	return( fptr );
}

/*	----------	*/
/*	copy_field	*/
/*	----------	*/
private	FIELD *	copy_field(FIELD * xptr)
{
	FIELD	*	fptr;
	if ((fptr = allocate_field()) != (FIELD *) 0) 
	{
		fptr->next = fptr->prev = (FIELD*)0;
		if ( xptr->name )
			fptr->name = allocate_string( xptr->name );
		fptr->module 	= xptr->module;
		fptr->host = xptr->host;
		fptr->client  = xptr->client;
		fptr->entry = xptr->entry;
		fptr->loword = xptr->loword;
		fptr->hiword = xptr->hiword;
		if ( xptr->modname )
			fptr->modname = allocate_string( xptr->modname );
		copy_location( &fptr->xvt, &xptr->xvt );
		fptr->members.root = xptr->members.root;
		fptr->members.last = xptr->members.last;
		fptr->solution.root = fptr->solution.last = (SOLUTION*)0;
	}
	return( fptr );
}

/*	-------------	*/
/*	drop_solution	*/
/*	-------------	*/
private	VOID	drop_solution(FIELD *fptr)
{
	SOLUTION * sptr =(SOLUTION*)0;
	if ( fptr ) 
	{
		while ((sptr = fptr->solution.root) != (SOLUTION *) 0) 
		{
			fptr->solution.root = sptr->next;
			liberate( sptr );
		}
	}
}

/*	--------------	*/
/*	liberate_field	*/
/*	--------------	*/
private	FIELD *	liberate_field(FIELD *fptr)
{
	VARIABLE * vptr =(VARIABLE*)0;
	if ( fptr ) 
	{
		if ( fptr->name )
			liberate( fptr->name );
		if (!( fptr->state )) 
		{
			while ((vptr = fptr->members.root) != (VARIABLE *) 0) 
			{
				fptr->members.root = vptr->next;
				liberate_variable( vptr );
			}
		}
		drop_solution( fptr );
		liberate( fptr );
	}
	return((FIELD*)0);
}

/*	-----------------	*/
/*	 locate_variable	*/
/*	-----------------	*/
private	VARIABLE * locate_variable( MODULE * mptr, VARIABLE * wptr )
{
	VARIABLE	*	vptr;
	if (!( mptr ))
		return((VARIABLE*)0);
	if (!( wptr ))	
		return((VARIABLE*)0);
	if (!( wptr->name ))
		return((VARIABLE*)0);
	for (	vptr=mptr->variables.root;
		vptr != (VARIABLE *) 0;
		vptr = vptr->next ) 
	{
		if (( vptr->type & ~ISARG)   != (wptr->type & ~ISARG)) 
		{
			if (( vptr->type & STRICT_TYPE ) != ( wptr->type & STRICT_TYPE ))
				continue;	
		}
		if ( vptr->length != wptr->length  )
			continue;	
		if ( vptr->first  != wptr->first   )
			continue;	
		if ( vptr->second != wptr->second )
			continue;	
		if(!( compare_strings( vptr->name, wptr->name )))
			continue;		
		else	return( vptr );
	}
	return((VARIABLE*)0);
}

/*	--------------------	*/
/*	drop_external_fields	*/
/*	--------------------	*/
private	void drop_external_fields( MODULE * mptr )
{
	FIELD * fptr =(FIELD*)0;
	while ((fptr = mptr->fields.root) != (FIELD*) 0) 
	{
		mptr->fields.root = fptr->next;
		liberate_field( fptr );
	}
	return;
}

/*	------------	*/
/*	add_solution	*/
/*	------------	*/
private	int add_solution(FIELD * fptr, VARIABLE * vptr, MODULE * mptr)
{
	SOLUTION	*	sptr;
	if (!( sptr = allocate( sizeof( SOLUTION ) )))
		return(report_error(192,vptr->name));
	else	sptr->next = sptr->prev = (SOLUTION*)0;
	if (!(sptr->prev = fptr->solution.last))
		fptr->solution.root = sptr;
	else	fptr->solution.last->next = sptr;
	fptr->solution.last = sptr;
	sptr->variable = vptr;
	sptr->module   = mptr;
	return(0);
}

/*	--------------------------------------------------------	*/
/*	R E S O L V E _ E X T E R N A L _ M E M B E R S ( fptr )	*/
/*	--------------------------------------------------------	*/
/*	This function will attempt to resolve individual members	*/
/*	in any module combination. Failure will occur if a member	*/
/*	cannot be found.						*/
/*	--------------------------------------------------------	*/
private	int resolve_external_members( FIELD * fptr )
{
	MODULE	  *	mptr;
	VARIABLE  *	vptr;
	VARIABLE  *	wptr;
	EXAWORD		status;

	for (	vptr = fptr->members.root;
		vptr != (VARIABLE *) 0;
		vptr = vptr->next ) 
	{

		if (!( vptr->relocate )) 
		{
			if ( Linker.warning ) 
			{
				sprintf(ErrorBuffer, "unused extern dcl %s", vptr->name);
				issue_warning(9, ErrorBuffer, 1);
			}
			continue;
		}

		if ( Linker.sourcetrace ) 
		{
			sprintf(ErrorBuffer, "locate : %s of %s in %s",vptr->name,fptr->client->rootname,Linker.program->rootname);
			issue_message(4, ErrorBuffer);
		}

		if (!(wptr = locate_variable( (mptr = Linker.program) , vptr ))) 
		{
			for (	mptr=Linker.modules.root;
				mptr != (MODULE *) 0;
				mptr = mptr->next ) 
			{
				if ( Linker.sourcetrace ) 
				{
					sprintf(ErrorBuffer, "locate : %s of %s in %s",vptr->name,fptr->client->rootname,mptr->rootname);
					issue_message(4, ErrorBuffer);
				}
				if (!(wptr = locate_variable( mptr , vptr )))
					continue;
				else	break;
			}
		}
		if (!( wptr )) 
		{
			drop_solution( fptr );
			report_error( 180,vptr->name );
			return(0);	
		}
		else if ((status = add_solution( fptr, wptr, mptr )) != 0) 
		{
			drop_solution( fptr );
			report_error( 180,vptr->name );
			return(0);	
		}			
	}
	fptr->host = Linker.program;
	return(1);
}

/*	----------------------	*/
/*	resolve_external_field	*/
/*	----------------------	*/
private	int resolve_external_field( MODULE * mptr, FIELD * fptr )
{
	VARIABLE  *	vptr;
	VARIABLE  *	wptr;
	EXAWORD		status;

	for (	vptr = fptr->members.root;
		vptr != (VARIABLE *) 0;
		vptr = vptr->next ) 
	{
		if (!( vptr->relocate ))
			continue;
		if ( Linker.sourcetrace ) 
		{
			sprintf(ErrorBuffer, "locate : %s in %s",vptr->name,mptr->rootname);
			issue_message(4, ErrorBuffer);
		}
		if (!(wptr = locate_variable( mptr, vptr ))) 
		{
			if ( Linker.sourcetrace ) 
				issue_message(4, "Not found");
			drop_solution(fptr);
			return(0);
		}
		else if ((status = add_solution( fptr, wptr, mptr )) != 0) 
		{
			drop_solution( fptr );
			report_error( 180,vptr->name );
			return(0);	
		}			
	}
	fptr->host = mptr;
	return(1);
}

/*	-----------------	*/
/*	 extern_field_in	*/
/*	-----------------	*/
private	int extern_field_in( BPTR nptr, FIELD *fptr )
{
	MODULE	*	mptr;
	if (!( mptr = locate_module( nptr )))
		return( report_error(181,nptr) );
	else	return( resolve_external_field( mptr, fptr ) );
}

/*	---------------------	*/
/*	relocate_extern_field	*/
/*	---------------------	*/
public	int	relocate_extern_field( FIELD * fptr )
{
	MODULE		*	optr;
	MODULE		*	hptr;
	MODULE		*	cptr;
	SOLUTION 	*	sptr;
	EXAWORD			status;
	VARIABLE	*	vptr;
	VARIABLE	*	wptr;

	if ((!(hptr = fptr->host      ))
	||  (!(cptr = fptr->client    )))
		return( report_error(182,fptr->name));
	else	
	{
		if ( Linker.verbose & 2 ) 
		{
			sprintf(ErrorBuffer, "relocate_extern_field of client %s in host %s", cptr->rootname,hptr->rootname);
			issue_message(0, ErrorBuffer);
			if (!( fptr->members.root ))
				issue_message(0, "no members  root");
			if (!( fptr->solution.root ))
				issue_message(0, "no solution  root");
		}
		for ( 	sptr = fptr->solution.root,
			wptr = fptr->members.root;
			sptr != (SOLUTION*) 0;
			sptr = sptr->next, wptr = wptr->next )
		{ 
			hptr = sptr->module;
			if (!( wptr )) 
				return(report_error(183,hptr->rootname));
			
			if (!( wptr->relocate )) 
			{
				if ( Linker.verbose & 2 ) 
				{
					sprintf(ErrorBuffer, "elimination of %s", wptr->name);
					issue_message(0, ErrorBuffer);
				}
				continue;
			}
			if (!( vptr = sptr->variable))
				return(report_error(184,wptr->name));
			else if (!( optr = vptr->host )) 
				return(report_error(1184,wptr->name));

			if ( Linker.verbose & 2 ) 
			{
				sprintf(ErrorBuffer, "reloc member : %s::%s (%llx + %llx) = %llx",
					optr->rootname,
					vptr->name,vptr->identity,optr->GdtAdjust,
					(vptr->identity+optr->GdtAdjust));
				issue_message(0, ErrorBuffer);
			}

			if ((status = build_external_relocation( 
				cptr,
				EXT_VARIABLE,
				(vptr->identity+optr->GdtAdjust),
				(vptr->offset  +optr->GdsAdjust),
				wptr->relocate,
				(Linker.verbose & 2) )) != 0) 
			{
				return(report_error(status,wptr->name));
			}
		}
		return(0);
	}
}

/*	-------------	*/
/*	resolve_field	*/
/*	-------------	*/
public	int	resolve_field( FIELD * fptr )
{
	MODULE	*	mptr;

	if ( Linker.sourcetrace ) 
	{
		if ( fptr->name ) 
		{
			sprintf(ErrorBuffer, "resolve_field(%s)", fptr->name);
			issue_message(4, ErrorBuffer);
		}
		else	issue_message(4, "resolve_field()");
	}

	/* handle case of an explicite EXTERN FIELD IN <modulename> */
	/* -------------------------------------------------------- */
	if ( fptr->modname )
		return( extern_field_in( fptr->modname, fptr  ));

	/* If the field has no name then the members may be in any amount */
	/* of different combined modules				  */
	/* -------------------------------------------------------------- */
	else if (!( fptr->name )) 
		return( resolve_external_members( fptr ) );
	else if (!( strlen( fptr->name ) ))
		return( resolve_external_members( fptr ) );

	/* Otherwise the field must be in one module */
	/* ----------------------------------------- */
	else if ( resolve_external_field( Linker.program, fptr ) )
		return( 1 );

	/* Resolve for case of EXTERN FIELD [ IN ANY ] */
	/* ------------------------------------------- */
	for (	mptr=Linker.modules.root;
		mptr != (MODULE *) 0;
		mptr = mptr->next ) 
		if ( resolve_external_field( mptr, fptr ) )
			return( 1 );

	return(0);
}

/*	-----------	*/
/*	use_modules	*/
/*	-----------	*/
public	int	use_modules( MODULE * rptr, FIELD * fptr )
{
	SOLUTION  *	sptr;
	int	status;
	if ( fptr->modname )
		return( use_module( rptr, fptr->host ) );

	else if (( fptr->name != (BPTR) 0 ) 
	     &&  ( strlen( fptr->name ) != 0 ))
		return( use_module( rptr, fptr->host ) );

	for ( 	sptr = fptr->solution.root;
		sptr != (SOLUTION *) 0;
		sptr = sptr->next ) 
	{
		if (!( sptr->module )) 
		{
			if (!( sptr->variable ))
				continue;
			else	return( report_error(206, sptr->variable->name ));
		}
		else if ((status = use_module( rptr, sptr->module )) != 0)
			return(status);
	}
	return(0);

}

/*	--------------------	*/
/*	load_external_fields	*/
/*	--------------------	*/
private	int load_external_fields( MODULE * mptr )
{
	EXAWORD	v;
	EXAWORD	nbv;
	EXAWORD	f;
	FIELD * fptr =(FIELD*)0;
	VARIABLE * vptr =(VARIABLE*)0;
	EXAWORD	status;
	if ((mptr->fieldtable.sector = tcsector( &mptr->dbheader[(TCPREFIX + (35*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) 
	{
		if ((status = load_buffer( mptr, mptr->dbhandle, mptr->fieldtable.sector )) != 0)
			return( report_error( 185, mptr->rootname ) );
		if (!( mptr->nbfields = buffer_getw( mptr ) ))
			return( 0 );
		if ( Linker.verbose & 8 ) 
		{
			sprintf(ErrorBuffer, "extern fields of %s : %llu", mptr->rootname, mptr->nbfields);
			issue_message(0, ErrorBuffer);
		}
		for ( f=0; f < mptr->nbfields; f++) 
		{
			if (!( fptr = allocate_field() ))
				return( report_error( 186, mptr->rootname) );
			else	fptr->client = mptr;
			if (!( mptr->fields.last ))
				mptr->fields.root  = fptr;
			else	mptr->fields.last->next = fptr;
			fptr->prev = mptr->fields.last;
			mptr->fields.last = fptr;
			if ((fptr->module = buffer_getw( mptr )) != mptr->minusone) 
			{
				if (!( fptr->modname = resolve_module_name( mptr, fptr->module ) ))
					return( report_error(187,mptr->rootname));
			}
			else	fptr->modname = (BPTR) 0;
			fptr->name   = buffer_gets( mptr );
			fptr->nature = buffer_getb( mptr );
			if ( fptr->nature & 0x0010 )
				fptr->entry = buffer_getw( mptr );
			else	fptr->entry = 0;
			fptr->loword = buffer_getw( mptr );
			fptr->hiword = buffer_getw( mptr );
			fptr->xvt.sector = buffer_getw( mptr );
			if ( Linker.verbose & 8 ) 
			{
				sprintf(ErrorBuffer, "extern field,%s(%llx) in %llu at %llx,%llx sector %llu",
					fptr->name,fptr->entry,fptr->module,
					fptr->hiword,fptr->loword, fptr->xvt.sector );
				issue_message(0, ErrorBuffer);
			}
		}
		if ( Linker.verbose & 8 ) 
		{
			sprintf(ErrorBuffer, "extern members of %s", mptr->rootname);
			issue_message(0, ErrorBuffer);
		}
		/* --------------------------------- */
		/* collect the members of the fields */
		/* --------------------------------- */
		for (	fptr=mptr->fields.root; 
			fptr != (FIELD*)0; 
			fptr = fptr->next ) 
		{
			if (!( fptr->xvt.sector ))
				continue;
			else if ((status = load_buffer( mptr, mptr->dbhandle, fptr->xvt.sector )) != 0)
				return( report_error( 188, mptr->rootname) );
			else if (!( nbv = buffer_getw( mptr )))
				continue;
			for ( v=0; v < nbv; v++ ) 
			{
				if (!( vptr = allocate_variable()))
					return( report_error( 189, mptr->rootname));
				else if (!( vptr->prev = fptr->members.last ))
					fptr->members.root = vptr;
				else	fptr->members.last->next = vptr;
				fptr->members.last = vptr;
				vptr->name     = buffer_gets( mptr );
				if ((vptr->identity = buffer_getw( mptr )) > mptr->xvarbtable.length)
					return( report_error( 207, vptr->name ) );
				if ( Linker.verbose & 8 ) 
				{
					sprintf(ErrorBuffer, "extern member: %s(%llx)", vptr->name,vptr->identity);
					issue_message(0, ErrorBuffer);
				}
				vptr->relocate = collect_relocation( mptr,8 );
				collect_variable_type( vptr, (mptr->xvt + vptr->identity), mptr->wordsize );
				if ( Linker.verbose & 8 ) 
				{
					sprintf(ErrorBuffer, "type : 0x%llx=%llu(%llu,%llu)", vptr->type, vptr->length, vptr->first, vptr->second);
					issue_message(0, ErrorBuffer);
				}
			}
		}	
	}
	return(0);
}

/*	------------	*/
/*	add_variable	*/
/*	------------	*/
EXAWORD	add_variable( MODULE * mptr, VARIABLE * vptr )
{
	VARIABLE	*	nptr;
	if (!( nptr = copy_variable( vptr )))
		return(report_error(193,vptr->name));
	else if (!( nptr->prev = mptr->variables.last ))
		mptr->variables.root = nptr;
	else	mptr->variables.last->next = nptr;
	mptr->variables.last = nptr;
	if ( Linker.sourcetrace ) 
	{
		sprintf(ErrorBuffer, "add_variable(%s)", nptr->name);
		issue_message(4, ErrorBuffer);
	}
	return(0);
}

/*	------------------	*/
/*	add_external_field	*/
/*	------------------	*/
EXAWORD	add_external_field( MODULE * mptr, FIELD * fptr )
{
	FIELD	*	nptr;
	if (!( nptr = copy_field( fptr )))
		return(report_error(194,fptr->name));
	else if (!( nptr->prev = mptr->fields.last ))
		mptr->fields.root = nptr;
	else	mptr->fields.last->next = nptr;
	mptr->fields.last = nptr;
	if ( Linker.sourcetrace ) 
	{
		sprintf(ErrorBuffer, "add_external_field(%s)", nptr->name);
		issue_message(4, ErrorBuffer);
	}
	return(0);
}

/*	--------------------	*/
/*	start_variable_table	*/
/*	--------------------	*/
EXAWORD	start_variable_table( MODULE * mptr ) 
{
	if( Linker.targettrace ) {
		sprintf(ErrorBuffer, "Variable Table");
		issue_message(5, "Variable Table");
	}
	reset_location(&mptr->varbtable);
	next_free_location(&mptr->varbtable);
	buffer_start( mptr, mptr->athandle, &mptr->varbtable );
	return(0);
}

/*	----------------	*/
/*	output_variables	*/
/*	----------------	*/
EXAWORD	output_variables( MODULE * rptr, MODULE * sptr )
{
	BPTR		dptr;
	EXAWORD		i;
	EXAWORD		t;
	EXAWORD		lo;
	EXAWORD		hi;
	EXAWORD		l;
	EXAWORD		p;
	EXAWORD		s;
	unsigned long	adresse=0L;
	unsigned long	limit_check=0L;
	unsigned long	bigadresse=0L;	
	if (!( dptr = sptr->gvt )) 
		return(0);

	if (!( sptr->GdtAdjust = rptr->GdtLimit ))  
	{
		sptr->EtdAdjust = 0;
		sptr->GdsAdjust = 0;
		if ( Linker.targettrace ) 
		{
			sprintf(ErrorBuffer, "Data Table : nb=%llu, ns=%xllu, mem=%llu", rptr->GlobalVariables, 0, rptr->GlobalAllocation );
			issue_message(5, ErrorBuffer);
		}
		buffer_putw(rptr,rptr->GlobalVariables);
		buffer_putw(rptr,rptr->varbnames.sector);
		buffer_putw(rptr,rptr->GlobalAllocation);
		rptr->GdtLimit = sptr->GdtLimit;
		rptr->GdsLimit = sptr->GdsLimit;
	}
	else 	
	{
		sptr->GdtAdjust -= (3*sptr->wordsize);
		sptr->GdsAdjust = rptr->GdsLimit;
		sptr->EtdAdjust = rptr->EtdLimit;
		if ( sptr->GdtLimit ) 
		{
			if ( rptr->wordsize <= 2 ) 
			{
				limit_check = rptr->GdtLimit;
				limit_check += (sptr->GdtLimit-(3*sptr->wordsize));
				if ( limit_check & OVERFLOW16 )
					return( report_error(209,sptr->rootname) );
				limit_check = rptr->GdsLimit;
				limit_check += sptr->GdsLimit;
				if ( limit_check & OVERFLOW16 )
					return( report_error(210,sptr->rootname) );
			}
			rptr->GdtLimit += (sptr->GdtLimit-(3*sptr->wordsize));
			rptr->GdsLimit += sptr->GdsLimit;
		}
		rptr->nbvarb += sptr->nbvarb;
	}
	dptr += (sptr->wordsize * 3);

	for ( i=0; i < sptr->nbvarb; i++ ) 
	{
		/* -------------------------- */
		/* collect variable type word */
		/* avoiding ATR hole bug bit  */
		/* -------------------------- */
		do	
		{
			t = tcgetword(dptr,sptr->wordsize);
			dptr += sptr->wordsize;
			buffer_putw(rptr,t);
		}
		while ( t & ATR_HOLE );

		lo = hi = 0;
		switch (( t & SPECIALE)) 
		{
		case	ISETENDU	:
			/* --------------------------------- */
			/* EXTENDED variables will not exist */
			/* in 32bit and 64bit ABAL programs. */
			/* They will have been conversted to */
			/* standard FIELD=M type variables.  */
			/* --------------------------------- */
			lo = tcgetword(dptr,sptr->wordsize); 
			dptr += sptr->wordsize;
			lo += sptr->EtdAdjust;
			hi = tcgetword(dptr,sptr->wordsize);
			dptr += sptr->wordsize;
			if ( sptr->wordsize > 2 )
				adresse = lo;
			else	adresse = ((hi << 16) | lo);
			adresse += sptr->EtdAdjust;
			if ( sptr->wordsize > 2 ) 
			{
				lo = adresse;
				hi = 0;
			}
			else	
			{
				lo = (adresse & 0x00FFFF);
				hi = (adresse >> 16);
			}
			buffer_putw(rptr,lo);
			buffer_putw(rptr,hi);
			break;

		case	ISDYNAMIC | ISMEMBER  		 :
		case	ISDYNAMIC | ISMEMBER | ISPOINTER :
			hi = tcgetword(dptr,sptr->wordsize);
			dptr += sptr->wordsize;
			hi += sptr->GdtAdjust;
			buffer_putw(rptr,hi);
			lo = tcgetword(dptr,sptr->wordsize); 
			dptr += sptr->wordsize;
			buffer_putw(rptr,lo);
			break;

		case	ISDYNAMIC | ISPOINTER 		 :
		case	ISNORMAL	      		 :
			lo = tcgetword(dptr,sptr->wordsize); 
			dptr += sptr->wordsize;
			lo += sptr->GdsAdjust;
			buffer_putw(rptr,lo);
			break;
		default					:
			/* gota be virtual memory file */
			lo = tcgetword(dptr,sptr->wordsize); 
			dptr += sptr->wordsize;
			buffer_putw(rptr,lo);
			hi = tcgetword(dptr,sptr->wordsize);
			dptr += sptr->wordsize;
			buffer_putw(rptr,hi);
			break;
		}

		/* -------------------------- */
		/* handle the variable length */
		/* -------------------------- */
		switch ( (t & VARBTYPE) )
		{
		case	ABAL_BCD		:
		case	ABAL_STRING	:
			l = tcgetword(dptr,sptr->wordsize);
			dptr += sptr->wordsize;
			buffer_putw(rptr,l);
			break;
		case	ABAL_INT64	:
			l = 8;
			break;
		case	ABAL_INT32	:
			l = 4;
			break;
		case	ABAL_INT16	:
			l = 2;
			break;
		case	ABAL_INT8	:
			l = 1;
			break;
		}

		p = s = 1;

		if (( t & PRIMARY )) 
		{
			p = tcgetword(dptr,sptr->wordsize);
			dptr += sptr->wordsize;
			buffer_putw(rptr,p);
			if (( t & SECONDARY )) 
			{
				s = tcgetword(dptr,sptr->wordsize);
				dptr += sptr->wordsize;
				buffer_putw(rptr,s);
			}			
		}
		if (( t & SPECIALE) == 	ISETENDU ) 
		{
			if ((bigadresse = (adresse + ((p*l)*s))) > rptr->EtdLimit)
				rptr->EtdLimit = bigadresse;
		}
	}
	sptr->EtdLimit = (rptr->EtdLimit - sptr->EtdAdjust);
	return(0);
}

/*	--------------------	*/
/*	close_variable_table	*/
/*	--------------------	*/
EXAWORD	close_variable_table( MODULE * mptr ) 
{
	buffer_flush( mptr );
	return(0);
}

/*	--------------------	*/
/*	copy_local_variables	*/
/*	--------------------	*/
WORD	copy_local_variables(
	MODULE * rptr,
	MODULE * sptr,
	LOCATION * lptr,
	LOCATION * xptr )
{
	return( copy_tcode( rptr, sptr, lptr, 2, xptr ) );
}

/*	--------------------------	*/
/*	start_variable_names_table	*/
/*	--------------------------	*/
EXAWORD	start_variable_names_table( MODULE * pptr ) 
{
	reset_location( &pptr->varbnames );
	if (!( Linker.debug ))
		return(0);
	next_debug_location(&pptr->varbnames);
	return(0);
}

/*	--------------------------	*/
/*	flush_variable_names_table	*/
/*	--------------------------	*/
EXAWORD	flush_variable_names_table( MODULE * pptr ) 
{
	COMPONENT 	* cptr;
	MODULE		* mptr;	
	VARIABLE 	* vptr;

	if (!( Linker.debug ))
		return(0);

	if( Linker.targettrace )
		issue_message(5, "Variable Names Table");

	buffer_start( pptr, pptr->dbhandle, &pptr->varbnames );

	for (	cptr = pptr->components.root;
		cptr != (COMPONENT*)0;
		cptr = cptr->next )  
	{
		if (!( mptr = cptr->module ))
			continue;

		for (	vptr = mptr->variables.root;
			vptr != (VARIABLE*) 0;
			vptr = vptr->next ) 
		{
			buffer_puts(pptr,vptr->name);
			buffer_putw(pptr,vptr->identity+mptr->GdtAdjust);
		}
	}
	buffer_putw(pptr,pptr->minusone);

	debug_flush( pptr );
	return(0);
}

/*	-------------------------	*/
/*	flush_variable_host_table	*/
/*	-------------------------	*/
EXAWORD	flush_variable_host_table( MODULE * pptr ) 
{
	COMPONENT 	* cptr;
	MODULE		* mptr;	
	VARIABLE 	* vptr;
	EXAWORD		module_id;

	if (!( Linker.debug ))
		return(0);

	reset_location( &pptr->varbhosttable );
	next_debug_location(&pptr->varbhosttable);
	if( Linker.targettrace )
		issue_message(5, "Variable Host Table");

	buffer_start( pptr, pptr->dbhandle, &pptr->varbhosttable );

	/* Version index */
	buffer_putw(pptr, 1);

	/* For each module */
	for (	cptr = pptr->components.root;	/* BGI: Why use pptr->components.root instead of pptr->module? */
		cptr != (COMPONENT*)0;
		cptr = cptr->next )  
	{
		if (!( mptr = cptr->module ))
			continue;

		module_id = get_module_id(pptr, mptr);

		/* For each variable */
		for (	vptr = mptr->variables.root;
			vptr != (VARIABLE*) 0;
			vptr = vptr->next ) 
		{
			module_id = get_module_id(pptr, vptr->host); /* BGI: Why use vptr->host instead of mptr? */
			buffer_putw(pptr, module_id);
		}
	}

	debug_flush( pptr );

	return(0);
}

#endif	/* _ldvarb_c */

