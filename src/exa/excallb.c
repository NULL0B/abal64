#ifndef	_excallback_c
#define	_excallback_c

#include "excallb.h"

extern	BPTR	ExportTable;
static	BYTE	CbCs[1024];

EXAWORD	use_export_table( BPTR xptr )
{
	if (!( xptr ))
		return( GOODRESULT );
	else	return( GOODRESULT );
}

EXAWORD	bind_export_procedure( BPTR procname, struct callback_context * dptr )
{
	BPTR	wptr;
	EXAWORD	nbx;
	EXAWORD	i;
	EXAWORD	x;
	EXAWORD	o;

	/* Ensure correct descriptor and Reset */
	/* ----------------------------------- */
	if (!( dptr ))
		return( 118 );
	else	{
		dptr->procedure  = -1; 
		dptr->pthread	 = (void *) 0;
		dptr->parameters = 0;
		dptr->first = dptr->last  = (struct callback_parameter *) 0;
		}

	/* Ensure correct procedure name and export Table */
	/* ---------------------------------------------- */
	if (!( procname ))
		return( 118 );
	else if (!( wptr = ExportTable ))
		return( 78 );
	else if (!( nbx = Tcodeword( wptr )))
		return( 78 );

	/* Step over export count and option word */
	/* -------------------------------------- */
	wptr += WORDSIZE; o = Tcodeword( wptr ); wptr += WORDSIZE;

	/* Locate and Bind to Exported Procedure */
	/* ------------------------------------- */
	for (i=0; i < nbx; i++ ) {
		for ( x=0; *(wptr+x) != 0; x++ ) {
			if (!( *(procname+x) ))
				break;
			else if ( *(procname+x) != *(wptr+x) )
				break;
			}
		if ( *(procname+x) != *(wptr+x) ) {
			while ( *(wptr+x) ) x++;
			wptr += (x+1);
			wptr += WORDSIZE;
			}
		else	{
			/* bind to the procedure */
			/* --------------------- */
			wptr += (x+1);
			x = Tcodeword( wptr );
			dptr->procedure = x;
			return( 0 );
			}
		}
	return( 78 );
}

EXAWORD	resolve_callback_procedure( char * procname )
{
	struct	callback_context	Context;
	if (!( bind_export_procedure( procname, & Context ) ))
		return( Context.procedure );
	else	return( MOINS_UN );
}


static	void	integer_register( int r, int v )
{
	freg[r] = v;
	xreg[r] = IMMEDIAT;
	ireg[r] = 0;
	areg[r] = 0;
	return;
}

static	void	temporary_register( int r, int t, int l , char * mptr )
{
	freg[r] = worktop;
	xreg[r] = TEMPDESC;
	ireg[r] = 0;
	areg[r] = 0;
	TcodePmot((TcodeByteStack + worktop),(t)); worktop += WORDSIZE;
	TcodePmot((TcodeByteStack + worktop),(l)); worktop += WORDSIZE;
	memcpy((BPTR) (TcodeByteStack + worktop) ,(BPTR) mptr, (USINT) l);
	worktop += (l+(WORDSIZE*2));
	return;
}

EXAWORD	invoke_export_procedure( struct callback_context * dptr )
{
	struct callback_parameter * pptr;
	EXAWORD	csip=0;
	EXAWORD	optarg=0;
	EXAWORD	args=0;
	EXAWORD	registers=0;
	EXAWORD	status;
	void * 	allocate_thread(WORD);

	/* Ensure valid Callback Invocation Descriptor */
	/* ------------------------------------------- */
	if (!( dptr ))
		return( 118 );
	else if ( dptr->procedure == -1 )
		return( 131 );
	else if ( dptr->parameters ) {
		if (!( dptr->pthread = allocate_thread(1)))
			return( 27 );
		else	push_all_registers( dptr->pthread );
		}
	else	dptr->pthread = (void *) 0;

	/* Load all parameters in Registers */
	/* -------------------------------- */
	for ( 	pptr = dptr->first;
		pptr != (struct callback_parameter *) 0;
		pptr = pptr->next ) {
		switch ( pptr->type ) {
			case	1	:
				integer_register( ++registers, pptr->ivalue );
				break;
			case	3	:
			case	2	:
				temporary_register( ++registers,pptr->type, pptr->length, pptr->svalue );
				break;
			}
		}

	/* Generate Pseudo Code Call */
	/* ------------------------- */
	CbCs[csip++] = _tc_ESC;
	CbCs[csip++] = _tc_CLP;
	for ( args=0; args < registers; args++ ) {
		if (!( args & 1 )) {
			optarg |= 0x16;
			}
		else	{
			optarg |= 1;
			CbCs[csip++] = optarg;
			optarg=0x060;
			}	
		}
	CbCs[csip++] = optarg;
	TcodePmot(&CbCs[csip],dptr->procedure);
	csip += WORDSIZE;

	for ( args=0; args < registers; args++ ) {
		CbCs[csip++] = (BYTE) (args+1);
		}

	/* Reset Temporary Memory */
	/* ---------------------- */
	CbCs[csip++] = _tc_RAZ;

	/* Leave Nexted Execution Cycle */
	/* ---------------------------- */
	CbCs[csip++] = _tc_ESC;
	CbCs[csip++] = _tc_ESC;

	/* Just Fucking Do It */
	/* ------------------ */
	status = execute_pseudo_code(CbCs);

	/* Then Clean up the Mess */
	/* ---------------------- */
	while ((pptr = dptr->first) != (struct callback_parameter *) 0) {
		dptr->first = pptr->next;
		liberate( pptr );
		}
	dptr->parameters = 0;		

	/* Restore Previous Execution Context */
	/* ---------------------------------- */
	if ( dptr->pthread ) {
		pop_all_registers( dptr->pthread );
		restore_stacks   ( dptr->pthread );
		dptr->pthread = liberate_thread( dptr->pthread );
		}

	/* And Return the Result */
	/* --------------------- */
	return( status );
}

EXAWORD	add_export_parameter( EXAWORD ptype, EXAWORD pvalue, BPTR pbuffer, struct callback_context * dptr  )
{
	struct callback_parameter * pptr;

	/* Ensure valid bound descriptor */
	/* ----------------------------- */
	if (!( dptr ))
		return( 118 );
	else if ( dptr->procedure == -1 )
		return( 131 );

	/* Ensure correct parameter type */
	/* ----------------------------- */
	switch ( ptype ) {
		case	1 : /* integer */
		case	2 : /* bcd     */
		case	3 : /* string  */
			break;
		default	  :
			return( 56 );
		}

	/* allocate and store parameter information */
	/* ---------------------------------------- */
	if (!( pptr = allocate( sizeof( struct callback_parameter ) ) ))
		return( 27 );
	else	{
		dptr->parameters++;
		if (!(dptr->last ))
			dptr->first = pptr;
		else	dptr->last->next = pptr;
		dptr->last = pptr;
		if ((pptr->type = ptype) > 1) {
			pptr->length = pvalue;
			pptr->svalue = pbuffer;
			pptr->ivalue = 0;
			}
		else	{
			pptr->ivalue = pvalue;
			pptr->length = 0;
			pptr->svalue = (char *) 0;
			}
		pptr->next = (struct callback_parameter *) 0;
		return( 0 );
		}
}

int	local_x_callback(int f,struct exa_callback * xptr)
{
	switch ( f ) {
		case	EXA_CALLBACK_RESOLVE	: 
			return( bind_export_procedure( xptr->buffer, &xptr->descriptor ) );
		case	EXA_CALLBACK_INVOKE 	:
			return( invoke_export_procedure( &xptr->descriptor ) );
		case	EXA_CALLBACK_INTEGER	:
			return( add_export_parameter(1,xptr->value, xptr->buffer, &xptr->descriptor ));
		case	EXA_CALLBACK_NUMERIC	:
			return( add_export_parameter(2,xptr->value, xptr->buffer, &xptr->descriptor ));
		case	EXA_CALLBACK_STRING	:
			return( add_export_parameter(3,xptr->value, xptr->buffer, &xptr->descriptor ));
		default				: 
			return(56);
		}
}

#endif  /* _excallback_c */
	/* ------------- */
 
