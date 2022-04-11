TCPRCPTR	allocate_for_procedure()
{
	TCPRCPTR	pptr;
	if ((pptr = (TCPRCPTR) allocate( sizeof( struct tcode_procedure ))) != (TCPRCPTR) 0) {
		pptr->identity=MOINS_UN;
		pptr->mode = MOINS_UN;
		pptr->name=(BPTR) 0;
		pptr->status=FAUX;
		pptr->function=0;
		pptr->options=0;
		pptr->extitem=0;
		pptr->module =0;
		pptr->crossref = (XREFPTR) 0;
		pptr->sector_XRF = 0;
		pptr->relocation = (RELOCPTR) 0;
		pptr->result=(TCTYPPTR) 0;
		pptr->extcall  =(TCVARPTR) 0;
		pptr->parameter=(TCVARPTR) 0;
		pptr->details=(TCBLKPTR) 0;
		pptr->next=(TCPRCPTR) 0;
		pptr->class=(VPTR) 0;
		pptr->member=(VPTR) 0;
		pptr->symbolic.sector = 0;
		pptr->symbolic.length = 0;
		}
	return( pptr );
}

VOID	liberate_rellocation_list( lptr )
RELOCPTR	lptr;
{
	RELOCPTR	rptr;
	trace("liberate_rellocation_list()\n");
	while ((rptr = lptr) != (RELOCPTR) 0) {
		lptr = rptr->next;
		liberate( rptr );
		}
	return;
}

VOID	liberate_cross_reference_list( lptr )
XREFPTR	lptr;
{
	XREFPTR	xptr;
	trace("liberate_cross_reference_list()\n");
	while ((xptr = lptr) != (XREFPTR) 0) {
		lptr = xptr->next;
		liberate( xptr );
		}
	return;
}

VOID	liberate_for_variable( vptr )
TCVARPTR	vptr;
{
	if ( vptr != (TCVARPTR) 0 ) {
		if ( vptr->type != (TCTYPPTR) 0 )
			liberate_for_type( vptr->type );
		liberate_rellocation_list( vptr->relocation );
		if ( vptr->construction != (TCTEXTPTR) 0 )
			liberate_text_value( vptr->construction );
		vptr->next = World->VariableHeap;
		World->VariableHeap = vptr;
		}
	return;
}

VOID	liberate_parameter_variable( vptr )
TCVARPTR	vptr;
{
	if ( vptr != (TCVARPTR) 0 ) {
		if ( vptr->name != (BPTR) 0 )
			liberate( vptr->name );
		if ( vptr->construction != (TCTEXTPTR) 0 )
			liberate_text_value( vptr->construction );
		liberate_for_variable( vptr );
		}
	return;
}

WORD	ensure_correct_parameter_types( ltype, rtype, mode )
TCTYPPTR	ltype;
TCTYPPTR	rtype;
WORD		mode;
{
	if ((ltype == (TCTYPPTR) 0) 
	||  (rtype == (TCTYPPTR) 0)
	||  (ltype->type   != rtype->type  )) {
		if (!( mode )) return( 4000 );
		if ( (ltype->type & 0x00FF) ==  (rtype->type & 0x00FF) ) 
			return( issue_warning(17) );
		else	return( syntax_error(4000) );
		}
	else if ((ltype->size   != rtype->size  )
	     ||  (ltype->first  != rtype->first )
	     ||  (ltype->second != rtype->second)) {
		if (!( mode )) return(0);
		return( issue_warning(17) );
		}
	else	return( 0 );
}

WORD	ensure_correct_parameter_names( optr, nptr, mode )
TCVARPTR	optr;	/* Forward Procedure Parameters 	*/
TCVARPTR	nptr;	/* Procedure Definition Parameters 	*/
WORD		mode;
{
	TCTYPPTR	tptr;
	BPTR		name;
	WORD		status;
	WORD		hash;

	while ((optr != (TCVARPTR) 0) && ( nptr != (TCVARPTR) 0)) {

		if ((status = ensure_correct_parameter_types(optr->type, nptr->type,mode)) != 0)
			return( status );

		name = nptr->name;
		hash = nptr->hash;
		tptr = nptr->type;
		nptr->name = optr->name;
		nptr->hash = optr->hash;
		nptr->type = optr->type;
		optr->name = name;
		optr->hash = hash;
		optr->type = tptr;
		optr = optr->next;
		nptr = nptr->next;

		}

	if ((optr == (TCVARPTR) 0) && ( nptr == (TCVARPTR) 0))
		return( 0 );
	else	return( 4001 );
}

VOID	liberate_for_procedure( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;

	if ( pptr != (TCPRCPTR) 0) {

		trace("liberate_for_procedure(");

		if ( pptr->name != (BPTR) 0 ) {
			trace( pptr->name );
			liberate( pptr->name );
			}
		trace(")\n");

		/* Method Function Parameters belong to the Method */
		/* ----------------------------------------------- */
		if (!( pptr->function )) {
			while ((vptr = pptr->parameter) != (TCVARPTR) 0) {
				pptr->parameter = vptr->next;
				liberate_parameter_variable( vptr );
				}
			}

		if ( pptr->result != (TCTYPPTR) 0)
			liberate_for_type( pptr->result );

		if ( pptr->details != (TCBLKPTR) 0)
			liberate( pptr->details );

		liberate_cross_reference_list( pptr->crossref );
		liberate_rellocation_list( pptr->relocation );

		liberate( pptr );

		}
	return;
}


