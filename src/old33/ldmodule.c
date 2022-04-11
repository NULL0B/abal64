#ifndef	_ldmodule_c
#define	_ldmodule_c

VOID	drop_components( MODULE * mptr )
{
	COMPONENT *	cptr;

	/* scan list to see if it is already present */
	/* ----------------------------------------- */
	while ((cptr=mptr->components.root) != (COMPONENT*)0) {
		mptr->components.root = cptr->next;
		liberate( cptr );
		}
	return;
}


private	MODULE * drop_module( MODULE * mptr )
{
	if ( mptr ) {
		drop_libraries(mptr);
		drop_constants(mptr);
		drop_labels( mptr );
		drop_variables(mptr);
		drop_external_fields (mptr);
		drop_external_variables (mptr);
		drop_procedures(mptr);
		drop_external_procedures(mptr);
		drop_segments(mptr);
		drop_external_segments(mptr);
		drop_components(mptr);
		drop_filenames(mptr);
		drop_names(mptr);
#ifdef ABAL33A
		drop_library_modules(mptr);
#endif
		close_debug( mptr );
		close_tcode( mptr );
		liberate( mptr );
		}
	return( (MODULE *) 0 );
}

MODULE *	allocate_module( BPTR nptr )
{
	MODULE	*	mptr;
	if ((mptr = (MODULE *) allocate( sizeof( MODULE ))) != (MODULE*)0) {

		mptr->xvt = mptr->gct = 
		mptr->gvt = mptr->gpt = mptr->gst = (BPTR) 0;

		if ( nptr != (BPTR) 0 )
			mptr->rootname   = allocate_string( nptr );
		else	mptr->rootname	 = allocate_string("bidon");

		mptr->unique     = Linker.counter++;

		mptr->NewSegment	= 256;
		mptr->whatisit		= 0x00FF;
		mptr->maxldt		=
		mptr->maxlds		=
		mptr->CryptCode		= 
		mptr->LdtAdjust		=
		mptr->GctLimit		=
		mptr->GctAdjust		=
		mptr->PdtLimit		=
		mptr->PdtAdjust		=
		mptr->SdtLimit		=
		mptr->SdtAdjust		=
		mptr->GdtAdjust		=
		mptr->GdsAdjust		=
		mptr->EtdAdjust		=
		mptr->GdtLimit		=
		mptr->GdsLimit		=
		mptr->EtdLimit		=
		mptr->GlobalVariables 	=
		mptr->GlobalAllocation	= 0;

		mptr->spillzone[0] = 0;
		mptr->overspill    = (REFERENCE *) 0;

		mptr->relocations.root =
		mptr->relocations.last =(REFERENCE *) 0; 

		mptr->labels.root =
		mptr->labels.last = (DATALABEL  *) 0;
		mptr->variables.root =
		mptr->variables.last = (VARIABLE  *) 0;
		mptr->xvariables.root= 
		mptr->xvariables.last= (VARIABLE  *) 0;

		mptr->filename.root =
		mptr->filename.last = (NAMES *) 0;
		mptr->names.root =
		mptr->names.last = (NAMES *) 0;

		mptr->libraries.root =
		mptr->libraries.last = (LIBRARY *) 0;

		mptr->procedures.root =
		mptr->procedures.last = (PROCEDURE *) 0;
		mptr->xprocedures.root=
		mptr->xprocedures.last= (XPROCEDURE *) 0;

		mptr->segments.root   = 
		mptr->segments.last   = (SEGMENT *) 0;
		mptr->xsegments.root  = 
		mptr->xsegments.last  = (XSEGMENT *) 0;

		mptr->components.root =
		mptr->components.last = (COMPONENT*)0;

		mptr->fields.root    =
		mptr->fields.last    = (FIELD*)0;

		mptr->nbproc = mptr->nbsegm = 
		mptr->nbvarb = mptr->nbcons = mptr->nblibr = 0;
		mptr->atname 	 = (BPTR) 0;
		mptr->athandle	 = (FILE *) 0;
		mptr->dbname 	 = (BPTR) 0;
		mptr->dbhandle	 = (FILE *) 0;
		mptr->boutput	 = (LOCATION*)0;
		mptr->next 	 = (MODULE *) 0;
		mptr->prev 	 = (MODULE *) 0;
		mptr->argvariable= 0;
		reset_location(&mptr->extended);
		reset_location(&mptr->librtable);
		reset_location(&mptr->constable);
		reset_location(&mptr->consnames);
		reset_location(&mptr->varbtable);
		reset_location(&mptr->varbnames);
		reset_location(&mptr->xvarbtable);
		reset_location(&mptr->xvarbnames);
		reset_location(&mptr->fieldtable);
		reset_location(&mptr->proctable);
		reset_location(&mptr->procnames);
		reset_location(&mptr->segmtable);
		reset_location(&mptr->segmnames);
		reset_location(&mptr->modnames);
#ifdef ABAL33A
		reset_location(&mptr->libmodtable);
#endif
		reset_location(&mptr->filenames);

		mptr->diezeheap	=0;
		mptr->diezefiles=0;
		mptr->diezemem	=0;
		mptr->diezestack=0;

		}
	return( mptr );
}

EXAWORD	add_component( MODULE * tptr, MODULE * sptr )
{
	COMPONENT *	cptr;

	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "add_component(%s)", sptr->rootname);
		issue_message(4, ErrorBuffer);
	}

	/* don't add a program to itself */
	/* ----------------------------- */
	if ( tptr->unique == sptr->unique )
		return(0);

	if ( sptr->wordsize != tptr->wordsize ) {
		return( report_error( 204, sptr->rootname ) );
		}

	/* scan list to see if it is already present */
	/* ----------------------------------------- */
	for (	cptr=tptr->components.root;
		cptr != (COMPONENT*) 0;
		cptr = cptr->next ) {
		if (!( cptr->module ))
			continue;
		else if ((cptr->module->unique == sptr->unique ))
			return(0);
		}

	/* add new component to module list */
	/* -------------------------------- */
	if (!( cptr = allocate( sizeof( COMPONENT ) )))
		return( report_error(27,sptr->rootname) );
	else	{
		sptr->PdtAdjust = tptr->PdtLimit;
		sptr->SdtAdjust = tptr->SdtLimit;
		tptr->GlobalVariables += sptr->nbvarb;
		tptr->GlobalAllocation+= sptr->GdsLimit;
		cptr->prev = cptr->next = (COMPONENT*)0;
		cptr->module = sptr;
		if (!(cptr->prev = tptr->components.last))
			tptr->components.root = cptr;
		else	tptr->components.last->next = cptr;

		tptr->components.last = cptr;

		if (!( tptr->argvariable ))
			tptr->argvariable = sptr->argvariable;
		else if ( sptr->argvariable ) 
			return( report_error(148, sptr->rootname ) );

		if ( sptr->diezemem > tptr->diezemem )
			tptr->diezemem = sptr->diezemem;
		if ( sptr->diezeheap > tptr->diezeheap )
			tptr->diezeheap = sptr->diezeheap;
		if ( sptr->diezefiles > tptr->diezefiles )
			tptr->diezefiles = sptr->diezefiles;
		if ( sptr->diezestack > tptr->diezestack )
			tptr->diezestack = sptr->diezestack;

		return(1);
		}
}

EXAWORD	use_module( MODULE * rptr, MODULE * mptr )
{
	LIBRARY   *	lptr;
	VARIABLE *	vptr;
	PROCEDURE *	pptr;
	SEGMENT   *	sptr;
	FIELD	 *	fptr;
	NAMES	*	nptr;
	XPROCEDURE *	xpptr;
	XSEGMENT   *	xsptr;
	EXAWORD	status;

	if ( Linker.sourcetrace )
		issue_message(4, "use_module()");

	switch (( status = add_component( rptr, mptr ) )) {
		case	0  : /* already present */
			return(0);
		case	1  : /* ok its added */
			break;
		default	   :
			return( report_error( 149, mptr->rootname ) );
		}

	report_use_module( mptr );

	/* transfer filenames to output */
	/* ---------------------------- */
	if ( Linker.debug ) {
		for (	nptr=mptr->filename.root;
			nptr != (NAMES*)0;
			nptr = nptr->next )
			if ((status = add_filename(rptr,nptr)) != 0)
				return( report_error( 150, nptr->name  ) );

		}

	/* transfer libraries to output */
	for (	lptr=mptr->libraries.root;
		lptr != (LIBRARY*)0;
		lptr = lptr->next )
		if ((status = add_library(rptr,lptr)) != 0)
			return( report_error( 151, lptr->name ) );

	/* transfer variables to output */
	for (	vptr=mptr->variables.root;
		vptr != (VARIABLE*)0;
		vptr = vptr->next )
		if ((status = add_variable(rptr,vptr)) != 0)
			return( report_error( 152, vptr->name ) );

	/* transfer procedures to output */
	for (	pptr=mptr->procedures.root;
		pptr != (PROCEDURE*)0;
		pptr = pptr->next )
		if ((status = add_procedure(rptr,pptr)) != 0)
			return( report_error( 153, pptr->name ) );

	/* transfer segments to output */
	for (	sptr=mptr->segments.root;
		sptr != (SEGMENT*)0;
		sptr = sptr->next )
		if ((status = add_segment(rptr,sptr)) != 0)
			return( report_error( 154, sptr->name ) );


	/* transfer external fields to output */
	for (	fptr=mptr->fields.root;
		fptr != (FIELD*)0;
		fptr = fptr->next )
		if ((status = add_external_field(rptr,fptr)) != 0)
			return( report_error( 155, fptr->name  ) );


	/* transfer external procedures to output */
	for (	xpptr=mptr->xprocedures.root;
		xpptr != (XPROCEDURE*)0;
		xpptr = xpptr->next )
		if ((status = add_external_procedure(rptr,xpptr)) != 0)
			return( report_error( 156, xpptr->name ) );

	/* transfer external segments to output */
	for (	xsptr=mptr->xsegments.root;
		xsptr != (XSEGMENT*)0;
		xsptr = xsptr->next )
		if ((status = add_external_segment(rptr,xsptr)) != 0)
			return( report_error( 157, xsptr->name ) );


	return(0);
}

#endif	/* _ldmodule_c */

