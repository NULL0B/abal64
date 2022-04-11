#ifndef	_ldproc_c
#define	_ldproc_c

XPROCEDURE	*	allocate_external_procedure()
{
	XPROCEDURE	*	pptr;
	if (!( pptr = allocate( sizeof( XPROCEDURE ) )))
		return( pptr );
	else	{
		pptr->next = pptr->prev = (XPROCEDURE*) 0;
		pptr->modname 	=
		pptr->name 	= 
		pptr->signature = (BPTR) 0;
		pptr->module 	= pptr->state = 
		pptr->returntype= pptr->parameters = 0;
		pptr->relocate	= (RELOCATION*)0;
		pptr->client	=
		pptr->host      = (MODULE*)0;
		pptr->procedure = (PROCEDURE*)0;
		return( pptr );
		}
}

XPROCEDURE	*	liberate_external_procedure( XPROCEDURE * pptr )
{
	if ( pptr ) {
		if ( pptr->name )
			liberate( pptr->name );
		if ( pptr->signature )
			liberate( pptr->signature );
		if ( pptr->relocate )
			drop_relocation( pptr->relocate );
		liberate( pptr );
		}
	return((XPROCEDURE*) 0);
}

PROCEDURE	*	liberate_procedure( PROCEDURE * pptr )
{
	if ( pptr ) {
		if ( pptr->name )
			liberate( pptr->name );
		if ( pptr->signature )
			liberate( pptr->signature );
		if ( pptr->linkown ) {
			if ( pptr->linkage )
				drop_references( pptr->linkage );
			}
		liberate( pptr );
		}
	return((PROCEDURE*) 0);
}

PROCEDURE	*	allocate_procedure()
{
	PROCEDURE	*	pptr;
	if (!( pptr = allocate( sizeof( PROCEDURE ) )))
		return( pptr );
	else	{
		pptr->next = pptr->prev = (PROCEDURE*) 0;
		pptr->name = pptr->signature = (BPTR) 0;
		pptr->identity = pptr->options = 0;
		pptr->returntype = pptr->parameters = 0;
		reset_location( &pptr->tcode );
		reset_location( &pptr->stats );
		reset_location( &pptr->lvt   );
		reset_location( &pptr->lct   );
		reset_location( &pptr->crossref );
		pptr->linkown =0;
		pptr->linkage = (REFERENCE*) 0;
		reset_location( &pptr->correspondance );
		pptr->original  = 
		pptr->host      = (MODULE*)0;
		return( pptr );
		}
}

PROCEDURE	*	copy_procedure( PROCEDURE * xptr )
{
	PROCEDURE	*	pptr;
	if (!( pptr = allocate_procedure() ))
		return( pptr );
	else	{
		pptr->next = pptr->prev = (PROCEDURE*) 0;

		if ( xptr->name )
			pptr->name = allocate_string( xptr->name );

		if ( xptr->signature ) 
			if ((pptr->signature = allocate((pptr->parameters = xptr->parameters))) != (BPTR) 0)
				memcpy(pptr->signature,xptr->signature,pptr->parameters);

		pptr->identity 	= xptr->identity;
		pptr->options 	= xptr->options;
		pptr->returntype= xptr->returntype;
		copy_location( &pptr->tcode	, &xptr->tcode    );
		copy_location( &pptr->lvt  	, &xptr->lvt      );
		copy_location( &pptr->lct  	, &xptr->lct   	  );
		copy_location( &pptr->crossref  , &xptr->crossref );
		pptr->linkage = xptr->linkage;
		copy_location( &pptr->correspondance ,&xptr->correspondance );
		pptr->host = xptr->host;
		pptr->original = xptr->original;
		return( pptr );
		}
}

XPROCEDURE	*	copy_external_procedure( XPROCEDURE * xptr )
{
	XPROCEDURE	*	pptr;
	if (!( pptr = allocate_external_procedure() ))
		return( pptr );
	else	{
		pptr->next = pptr->prev = (XPROCEDURE*) 0;

		if ( xptr->name )
			pptr->name = allocate_string( xptr->name );

		if ( xptr->modname )
			pptr->modname = allocate_string( xptr->modname );

		if ( xptr->signature ) 
			if ((pptr->signature = allocate((pptr->parameters = xptr->parameters))) != (BPTR) 0)
				memcpy(pptr->signature,xptr->signature,pptr->parameters);

		pptr->module 	= xptr->module;
		pptr->state 	= xptr->state;
		pptr->returntype= xptr->returntype;
		pptr->host = xptr->host;
		pptr->client  = xptr->client;
		pptr->relocate	= copy_relocation_list( xptr->relocate );
		pptr->procedure = xptr->procedure;
		return( pptr );
		}
}

private	void	drop_external_procedures ( MODULE * mptr )
{
	XPROCEDURE	*	pptr;

	while ((pptr = mptr->xprocedures.root) != (XPROCEDURE *) 0) {
		mptr->xprocedures.root = pptr->next;
		liberate_external_procedure( pptr );
		}
	return;
}

private	void	drop_procedures ( MODULE * mptr )
{
	PROCEDURE	*	pptr;

	while ((pptr = mptr->procedures.root) != (PROCEDURE *) 0) {
		mptr->procedures.root = pptr->next;
		liberate_procedure( pptr );
		}

	if ( mptr->gpt )
		liberate( mptr->gpt );
	return;
}

private	int load_procedure( MODULE * mptr, PROCEDURE * pptr )
{
	BPTR	tptr;
	WORD	i;

	/* collect name and identity */
	/* ------------------------- */
	if (!( pptr->name = buffer_gets( mptr ) ))
		return( 27 );
	else	{
		pptr->identity = buffer_getw( mptr );
		tptr = (mptr->gpt + pptr->identity);
		}

	/* now locate procedure table information */
	/* -------------------------------------- */
	pptr->tcode.sector = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->tcode.length = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->lvt.sector = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->lvt.length = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->lct.sector = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->lct.length = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->options = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;
	pptr->options = tcgetword(tptr,mptr->wordsize);
	tptr += mptr->wordsize;

	/* collect the remaining symbolic information */
	/* ------------------------------------------ */
	pptr->crossref.sector = buffer_getw( mptr );
	pptr->correspondance.sector = buffer_getw( mptr );
	pptr->correspondance.length = buffer_getw( mptr );

	i = buffer_getw( mptr );

	pptr->parameters = (i & 0x00FFF);
	pptr->returntype = ((i >> 8) & 0xFF);

	/* collect parameter count and types */
	/* --------------------------------- */
	if (pptr->parameters != 0 ) {
		if (!( pptr->signature = allocate( pptr->parameters )))
			return(27);
		for ( i=0; i < pptr->parameters; i++ )
			*(pptr->signature + i) = buffer_getb( mptr );
		}

	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "proc %s(/%x) : tc(%u,%u) lv(%u,%u) lc(%u,%u) o (%u) xr(%u), cr(%u,%u)",
			pptr->name,pptr->identity,
			pptr->tcode.sector,pptr->tcode.length,
			pptr->lvt.sector,pptr->lvt.length,
			pptr->lct.sector,pptr->lct.length,
			pptr->options,
			pptr->crossref.sector,
			pptr->correspondance.sector,pptr->correspondance.length
			);
		issue_message(4, ErrorBuffer);
		}
	return(0);
}

private	int load_procedures( MODULE * mptr )
{
	WORD	status;
	WORD	p;
	WORD	nbp;
	PROCEDURE * pptr=(PROCEDURE*)0;
	if (((mptr->proctable.sector = tcsector( &mptr->atheader[(TCPREFIX + (9*mptr->wordsize)+2)],mptr->wordsize )) != 0 )
	&&  ((mptr->proctable.length = tclength( &mptr->atheader[(TCPREFIX + (10*mptr->wordsize)+2)],mptr->wordsize )) != 0 )) {
		mptr->nbproc = (mptr->proctable.length / (8*mptr->wordsize));
		mptr->PdtLimit = mptr->proctable.length;
		mptr->PdtAdjust= 0;
		if ( Linker.sourcetrace ) {
			sprintf(ErrorBuffer, "gpt       : sector =%u, length =%u, procedures : %u",mptr->proctable.sector,mptr->proctable.length,mptr->nbproc);
			issue_message(4, ErrorBuffer);
		}
		if (!(mptr->gpt = load_tcode( mptr->athandle, mptr->proctable.sector, mptr->proctable.length )))
			return(report_error(198,mptr->rootname));
		if ((mptr->procnames.sector = tcsector( &mptr->dbheader[(TCPREFIX + (11*mptr->wordsize)+2)],mptr->wordsize )) != 0) {
			if ((status = load_buffer( mptr, mptr->dbhandle, mptr->procnames.sector )) != 0)
				return( status );
			else if (!( nbp = buffer_getw( mptr ))) 
				return(0);
			for (p=0; p < nbp; p++ ) {
				if (!(pptr = allocate_procedure())) 
					return( report_error(135,mptr->rootname) );
				else	{
					pptr->host = mptr;
					}
				if (!( mptr->procedures.last ))
					mptr->procedures.root = pptr;
				else	mptr->procedures.last->next = pptr;
				pptr->prev = mptr->procedures.last;
				mptr->procedures.last = pptr;
				if ((status = load_procedure( mptr, pptr )) != 0)
					return( report_error(136,mptr->rootname) );
				}
			for ( 	pptr=mptr->procedures.root;
				pptr != (PROCEDURE *) 0;
				pptr = pptr->next ) {
				if ( pptr->crossref.sector != 0 ) {
					if (!(pptr->linkage = load_references( mptr, &pptr->crossref )))
						continue;
					else	pptr->linkown=1;
					}
				}
			}
		}
	return(0);
}

private	int	compare_procedures(
	BYTE xrt, BPTR xn, BYTE xnb, BPTR xs,
	BYTE prt, BPTR pn, BYTE pnb, BPTR ps )
{
	int	i;
	if ( xrt != prt )			return(1);
	if ( xnb != pnb )			return(2);
	if (!( compare_strings( xn, pn ) ))	return(3);
	for (i=0; i < xnb; i++ )
		if ( *(xs+i) != *(ps+i) )
			return(4);
	return(0);
}


private	void	show_return_type( int t )
{

	switch ( (t & 0x00F0) >> 4 ) {
		case	0 : printf(" : # "); break;
		case	1 : printf(" : %% "); break;
		case	2 : printf(" : * "); break;
		case	3 : printf(" : $ "); break;
		case	5 : printf(" : : "); break;
		}
	return;
}

private	void	show_parameter_type( int t )
{
	if ( t & 0x0008 )
		printf("PTR");
	switch (( t  & 0x0007 )) {
		case	0 : printf(" #"); break;
		case	1 : printf(" %%"); break;
		case	2 : printf(" *"); break;
		case	3 : printf(" $"); break;
		case	5 : printf(" :"); break;
		}
	if ( t & 0x0040 ) {
		printf("(");
		if ( t & 0x0020 )
			printf(",");
		printf(")");
		}
	return;
}


public	void	show_procedure_signature( PROCEDURE * pptr, char * message )
{
	int	i;
	int	t;
	if ( message )
		printf("%s PROC %s(",message,pptr->name);
	else	printf("PROC %s(",pptr->name);
	for (i=0; i < pptr->parameters; i++ ) {
		if (i) printf(",");
		show_parameter_type(*(pptr->signature+i) & 0x00FF);
		}
	printf(")");
	show_return_type(pptr->returntype);
	printf("\n");
	return;
}

public	void	show_external_procedure_signature( XPROCEDURE * pptr )
{
	int	i;
	printf("EXTERN PROC %s(",pptr->name);
	for (i=0; i < pptr->parameters; i++ ) {
		if (i) printf(",");
		show_parameter_type(*(pptr->signature+i) & 0x00FF);
		}

	printf(")");
	show_return_type(pptr->returntype);
	printf("\n");
	return;
}

private	int resolve_external_procedure( MODULE * mptr, XPROCEDURE * xptr, int failure )
{
	int		retval;
	PROCEDURE *	pptr;
	for (	pptr = mptr->procedures.root;
		pptr != (PROCEDURE *) 0;
		pptr = pptr->next ) {
		if (!(retval = compare_procedures(
			xptr->returntype, xptr->name, 
			xptr->parameters, xptr->signature,
			pptr->returntype, pptr->name, 
			pptr->parameters, pptr->signature ))) {
			xptr->host = mptr;
			xptr->procedure = pptr;
			if ( Linker.sourcetrace )
				solution( pptr->name, mptr );
			return(1);
			}
		else if (!( failure ))
			continue;
		else if ( retval != 4 )
			continue;
		else	{
			/* unmatched parameter types */
			/* ------------------------- */
			if ( Linker.verbose  ) {
				show_external_procedure_signature( xptr );
				show_procedure_signature( pptr, mptr->rootname );
				}
			report_error( 213, pptr->name );
			return(0);
			}
		}
	return(0);
}

private	int extern_procedure_in( BPTR nptr, XPROCEDURE * xptr )
{
	MODULE	*	mptr;
	if (!( mptr = locate_module( nptr ))) {
/* #BG 03/08/04
 		return( report_error(137, nptr) );
*/
		report_error(137, nptr);
		return 0;
	}
	else	return( resolve_external_procedure( mptr, xptr, 1 ) );
}

/*
 *	R E L O C A T E _ E X T E R N A L _ P R O C E D U R E ( xptr )
 *	--------------------------------------------------------------
 *	This function is called by the program building
 *	external reference resolution loop, after the addition of the
 *	parent MODULE as a COMPONENT to its client PROGRAM.
 *
 *	This function is responsible for the transmission of relocation
 *	information to the CLIENT MODULE for use during its tcode transmission
 *	routines to its CLIENT PROGRAM.
 *
 */

public 	int relocate_external_procedure( XPROCEDURE * xptr )
{
	MODULE	*	hptr;
	MODULE	*	cptr;
	PROCEDURE *	pptr;

	if ((!(hptr = xptr->host      ))
	||  (!(cptr = xptr->client    ))
	||  (!(pptr = xptr->procedure ))) 
		return( report_error(138,xptr->name));
	else	return( build_external_relocation(
				cptr,
				EXT_PROCEDURE,
				(pptr->identity+hptr->PdtAdjust),
				0,
				xptr->relocate,0
				) 
			);
}

/*
 *	R E S O L V E _ P R O C E D U R E ( xptr )
 *	------------------------------------------
 *	This function is called by the program building
 *	external reference resolution loop to find a PROCEDURE
 *	in a MODULE which resolves the EXTERNAL PROCEDURE
 *	passed as a parameter.
 *	
 *	The resolution of the external procedure limits itself
 *	to finding a or the module which satisfies the symbolic and
 *	signatural requirements.
 *	
 */

public 	int resolve_procedure( 	XPROCEDURE * xptr )
{
	MODULE	*	mptr;

	if ( Linker.sourcetrace ) {
		if (!( mptr = xptr->client ))
			sprintf(ErrorBuffer, "resolve_procedure(%s) from something", xptr->name);
		else
			sprintf(ErrorBuffer, "resolve_procedure(%s) from %s", xptr->name, mptr->rootname);
		issue_message(4, ErrorBuffer);
		}

	/* handle case of an explicite EXTERN PROC IN <modulename> */
	/* ------------------------------------------------------- */
	if ( xptr->modname )
		return( extern_procedure_in( xptr->modname, xptr  ));


	/* Resolve for case of EXTERN PROC [ IN ANY ] */
	/* ------------------------------------------ */
	for (	mptr=Linker.modules.root;
		mptr != (MODULE *) 0;
		mptr = mptr->next ) {
		if ( resolve_external_procedure( mptr, xptr,1 ) )
			return( 1 );
		}

	if ( resolve_external_procedure( Linker.program, xptr,0 ) )
		return( 1 );
	else	return(0);
}



private	int load_external_procedures( MODULE * mptr )
{
	WORD	i;
	WORD	status;
	EXAWORD	p;
	EXAWORD	nbp;
	EXAWORD	sector;
	XPROCEDURE * pptr=(XPROCEDURE*)0;
	if ((sector = tcsector( &mptr->dbheader[(TCPREFIX + (14*mptr->wordsize)+2)],mptr->wordsize )) != 0 ) {
		if ((status = load_buffer( mptr, mptr->dbhandle, sector )) != 0)
			return( status );
		else if (!( nbp = buffer_getw( mptr ))) 
			return(0);
		for (p=0; p < nbp; p++ ) {
			if (!(pptr = allocate_external_procedure())) 
				return( report_error(139,mptr->rootname) );
			else	pptr->client = mptr;

			if (!( pptr->prev = mptr->xprocedures.last ))
				mptr->xprocedures.root = pptr;
			else	mptr->xprocedures.last->next = pptr;
			mptr->xprocedures.last = pptr;
			if ((pptr->module = buffer_getw( mptr )) != mptr->minusone) {
				if (!( pptr->modname = resolve_module_name( mptr, pptr->module ) ))
					return( report_error(140,mptr->rootname));
				}
			else	pptr->modname = (BPTR) 0;
			pptr->name   = buffer_gets( mptr );

			i = buffer_getw( mptr );

			pptr->parameters = (i & 0x00FF);
			pptr->returntype = ((i >> 8) & 0xFF);

			/* collect parameter count and types */
			/* --------------------------------- */
			if (pptr->parameters != 0 ) {
				if (!( pptr->signature = allocate( pptr->parameters )))
					return(report_error(141,pptr->name));
				for ( i=0; i < pptr->parameters; i++ )
					*(pptr->signature + i) = buffer_getb( mptr );
				}


			pptr->relocate = collect_relocation( mptr,0 );

			if ( Linker.sourcetrace ) {
				sprintf(ErrorBuffer, "extern proc %s in module %u", pptr->name,pptr->module );
				issue_message(4, ErrorBuffer);
				}	
			}

		}
	return(0);
}

EXAWORD	add_procedure( MODULE * mptr, PROCEDURE * pptr )
{
	PROCEDURE	*	nptr;
	if (!( nptr = copy_procedure( pptr )))
		return(report_error(199,pptr->name));
	else if (!( nptr->prev = mptr->procedures.last ))
		mptr->procedures.root = nptr;
	else	mptr->procedures.last->next = nptr;
	mptr->procedures.last = nptr;
	mptr->PdtLimit += (8*mptr->wordsize);
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "add_procedure(%s)", nptr->name);
		issue_message(4, ErrorBuffer);
		}
	return(0);
}

EXAWORD	add_external_procedure( MODULE * mptr, XPROCEDURE * pptr )
{
	XPROCEDURE	*	nptr;
	if (!( nptr = copy_external_procedure( pptr )))
		return(report_error(200,pptr->name));
	else if (!( nptr->prev = mptr->xprocedures.last ))
		mptr->xprocedures.root = nptr;
	else	mptr->xprocedures.last->next = nptr;
	mptr->xprocedures.last = nptr;
	if ( Linker.sourcetrace ) {
		sprintf(ErrorBuffer, "add_external_procedure(%s)", nptr->name);
		issue_message(4, ErrorBuffer);
		}
	return(0);
}

EXAWORD	start_procedure_table( MODULE * mptr ) 
{
	reset_location( &mptr->proctable );
	return(0);
}

EXAWORD	output_procedure( MODULE * rptr, PROCEDURE * pptr  ) 
{
	MODULE		* mptr;
	EXAWORD		status;

	if (!( mptr = pptr->host ))
		return( report_error(142,pptr->name));
	/* the same file so no copy */
	else if ( mptr->unique == rptr->unique )
		return(0);
	else if (( status = copy_tcode( rptr, mptr, &pptr->tcode,1,(LOCATION*)0 )) != 0)
		return( report_error(143, pptr->name ));

	if ( pptr->lvt.length > rptr->maxldt ) {
		rptr->maxldt = pptr->lvt.length;
		rptr->maxlds = pptr->lvt.length;
		}

	if (( status = copy_local_variables( rptr, mptr, &pptr->lvt, &pptr->stats )) != 0)
		return( report_error( 144, pptr->name ));
	else if (( status = copy_local_constants( rptr, mptr, &pptr->lct )) != 0)
		return( report_error( 145, pptr->name ));
	else	{
		pptr->original = pptr->host;
		pptr->host = rptr;
		return(0);
		}
}

EXAWORD	close_procedure_table( MODULE * mptr ) 
{
	PROCEDURE * pptr;
	EXAWORD		identity=0;
	unsigned long	table_check=0L;
	next_free_location(&mptr->proctable);
	if( Linker.targettrace )
		issue_message(5, "Procedure Table");
	report_procedure_table();
	buffer_start( mptr, mptr->athandle, &mptr->proctable );
	for (	pptr=mptr->procedures.root;
		pptr != (PROCEDURE*) 0;
		pptr = pptr->next ) {
		report_procedure(pptr);
		buffer_putlocation(mptr,&pptr->tcode);
		buffer_putlocation(mptr,&pptr->lvt);
		buffer_putlocation(mptr,&pptr->lct);
		buffer_putw(mptr,0);
		buffer_putw(mptr,pptr->options);
		pptr->host = (MODULE *) 0;
		identity += (mptr->wordsize * 8);
		if ( mptr->wordsize > 2 )
			continue;
		else	{
			table_check += (mptr->wordsize*8);
			if ( table_check & OVERFLOW16 )
				return( report_error( 211, pptr->name ) );	
			}
		}
	buffer_flush( mptr );
	close_procedure_report();
	return(0);
}

EXAWORD	flush_procedure_names_table( MODULE * mptr ) 
{
	PROCEDURE * pptr;
	EXAWORD	i;

	if (!( Linker.debug ))
		return(0);

	/* Copy Procedure Correspondances */
	/* ------------------------------ */
	for (	pptr=mptr->procedures.root;
		pptr != (PROCEDURE*) 0;
		pptr = pptr->next ) {
		copy_correspondance( mptr, pptr->original, &pptr->correspondance );
		}
	/* Build New Procedure Names Table */
	/* ------------------------------- */
	reset_location( &mptr->procnames );
	next_debug_location(&mptr->procnames);
	if( Linker.targettrace )
		issue_message(5, "Procedure Names Table");
	buffer_start( mptr, mptr->dbhandle, &mptr->procnames );
	mptr->nbproc = (mptr->proctable.length / (8*mptr->wordsize));
	buffer_putw(mptr,mptr->nbproc);
	for (	pptr=mptr->procedures.root;
		pptr != (PROCEDURE*) 0;
		pptr = pptr->next ) {
		buffer_puts(mptr,pptr->name);
		buffer_putw(mptr,pptr->identity+pptr->original->PdtAdjust);
		buffer_putw(mptr,0 );	/* cross ref sector */
		buffer_putw(mptr,pptr->correspondance.sector);
		buffer_putw(mptr,pptr->correspondance.length);
		i = (pptr->parameters | ( pptr->returntype << 8));
		buffer_putw(mptr, i );
		if ( pptr->parameters )
			buffer_put(mptr,pptr->signature,pptr->parameters);
		}
	buffer_putw(mptr,0);
	buffer_putw(mptr,0);
	buffer_putw(mptr,mptr->minusone);
	debug_flush( mptr );
	return(0);
}

#endif	/* _ldproc_c */

