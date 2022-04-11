#ifndef	_EXDLL_C
#define	_EXDLL_C
#include "allocate.h"
#include "exdll.h"
#include "exmacro.h"

extern	EXAWORD	procmaxid;
extern	EXAWORD	SegmentCount;

/*	----------------------------------------------------------	*/
/*	   A b a l P r o c e d u r e P a r a m e t e r T y p e 		*/
/*	----------------------------------------------------------	*/
/*	returns the type of an abal procedure parameter taken from	*/
/*	a loval variable table entry pointer. The table entry is	*/
/*	consumed and the pointer will point to the next entry in 	*/
/*	the table on succesful exit from the function.			*/
/*	----------------------------------------------------------	*/
static	EXAWORD	AbalProcedureParameterType( struct abal_program_handle * pptr, BPTR * dptr, EXAWORD item, EXAWORD total )
{
	BPTR	datatable;
	EXAWORD	vtype;
	/* -------------------------------------- */
	/* detect first call for count collection */
	/* -------------------------------------- */

	if (!( dptr ))
		return( MOINS_UN );

	else if (!( datatable = *dptr ))
		return( MOINS_UN );

	if (!( item ))
	{
		item = Tcodeword( datatable );
		datatable += ( WORDSIZE * 3 );

		/* update callers data table pointer */
		/* --------------------------------- */
		*dptr = datatable;

		/* return the actual parameter type */
		/* -------------------------------- */
		return( item );
	}
	else if (!( dptr ))
		return( MOINS_UN );
	else if ( item > total )
		return( MOINS_UN );
	else
	{
		/* detect procedure parameter by ARG */
		/* --------------------------------- */
		vtype = Tcodeword( datatable );
		datatable += WORDSIZE;
		if (!( vtype & VARB_ARG ))
			return( MOINS_UN );
			
		/* step over offset and eventual base */
		/* ---------------------------------- */
		datatable += WORDSIZE;
		if (( vtype & SPECIALE )
		&&  ( (vtype &  SPECIALE) != (ISDYNAMIC | ISPOINTER) ))
			datatable += WORDSIZE;

		/* step over eventual string length */
		/* -------------------------------- */
		switch ( vtype & VARB_ISOL ) 
		{
		case VARB_FOUR 	:
		case VARB_INT8 	: 
		case VARB_INT16 : 
		case VARB_INT32 : 
		case VARB_INT64 : 
			break;
		default		:
			datatable += WORDSIZE;
			break;
		}

		/* step over eventual index information */
		/* ------------------------------------ */
		if ( vtype & NDX1st )
		{
			datatable += WORDSIZE;
			if ( vtype & NDX2nd )
			{
				datatable += WORDSIZE;
			}
		}

		/* update callers data table pointer */
		/* --------------------------------- */
		*dptr = datatable;

		/* return the actual parameter type */
		/* -------------------------------- */
		return(( vtype & VARB_ISOL ));
	}
}

/*	----------------------------------------------------------	*/
/*	      A b a l P r o c e d u r e P a r a m e t e r 		*/
/*	----------------------------------------------------------	*/
/*	adds an abal procedure parameter value prior to a call to	*/
/*	the procedure. parameter values are stored in registers so	*/
/*	the mechanism cannot handle calles to procedures with more	*/
/*	parameters than the maximum register count.			*/
/*	----------------------------------------------------------	*/
static	int 	AbalProcedureParameter( struct abal_program_handle * pptr, int type, int value, void * vptr )
{
	BPTR	wptr;
	if ( pptr->registers >= ExRegMax )
		return(132);
	else	{
		switch ( type ) {
			case VARB_INT8	:
			case VARB_INT16:	
			case VARB_INT32:
			case VARB_INT64:
				xreg[++pptr->registers] = IMMEDIAT;
				freg[pptr->registers] = value;
				break;
			case VARB_BCD	:	
			case VARB_STR	:
				if (!( wptr = (BPTR) vptr))  { return(118); }
				StackCheck( ( value + (WORDSIZE * 2) ));
				xreg[++pptr->registers] = TEMPDESC;
				freg[pptr->registers] = worktop;
				workptr1 = (TcodeByteStack + worktop);
				worktop += (value + (WORDSIZE * 2));
				TcodePmot( workptr1 , type  ); workptr1 += WORDSIZE;
				TcodePmot( workptr1 , value ); workptr1 += WORDSIZE; 
				memcpy(workptr1,wptr,value);
				break;
			}
		}
	return(0);
}

/*	----------------------------------------------------------	*/
/*	      A b a l P r o c e d u r e R e s u l t 			*/
/*	----------------------------------------------------------	*/
/*	resolves the nature of the exit value found in register 53	*/
/*	and returns type and value, in the case of a string return	*/
/*	of type length and value.					*/
/*	----------------------------------------------------------	*/

static	char *	AbalProcedureResult( struct abal_program_handle * pptr, int * type, int * length  )
{
	*type   = VARB_INT16;
	*length = 0;
	if (!( argset(4,53,1) ))
		return((char *) 0);
	else
	{
		switch ((*type = worktyp1))
		{
		case	VARB_INT8	:
		case	VARB_INT16	:
		case	VARB_INT32	:
		case	VARB_INT64	:
			*length = workval1;
			return((char *) 0);
		case	VARB_BCD	:
		case	VARB_STR	:
			*length = worklen1;
			return( workptr1 );
		default			:
			return((char *) 0);
		}
	}
}

/*	----------------------------------------------------------	*/
/*	      R e s o l v e A b a l P r o c e d u r e			*/
/*	----------------------------------------------------------	*/
/*	converts the symbolic procedure name to its procedure id	*/
/*	this is the procedure number and not the procedure table 	*/
/*	offset value. A value of -1 means that the procedure name	*/
/*	could not been found.						*/
/*	----------------------------------------------------------	*/
static	int 	ResolveAbalProcedure( struct abal_program_handle * pptr, char * procname )
{
	int result;
	if ((result = resolve_callback_procedure( procname ) ) == -1)
		return( result );
	else 	return((result / (8 * WORDSIZE)));
}
	
/*	----------------------------------------------------------	*/
/*	      	C a l l A b a l P r o c e d u r e			*/
/*	----------------------------------------------------------	*/
/*	calls the indicated procedure number. parameters values		*/
/*	that were established by calls to the appropriate method,	*/
/*	"AbalProcedureParameter", will be passed as arguments to	*/
/*	the procedure invocation.					*/
/*	----------------------------------------------------------	*/
static	int 	CallAbalProcedure( struct abal_program_handle * pptr, int procedure )
{
	int	result;
	result = call_abal_program(procedure,pptr->registers);
	worktop = 0;
	pptr->registers = 0;
	return( result );
}

/*	----------------------------------------------------------	*/
/*	      		L d G o A b a l S e g m e n t			*/
/*	----------------------------------------------------------	*/
/*	calls the indicated segment number. 				*/
/*	----------------------------------------------------------	*/
static	int 	LdGoAbalSegment( struct abal_program_handle * pptr, int segment )
{
	return( ldgo_abal_program(segment) );
}

/*	----------------------------------------------------------	*/
/*	      		S t o p A b a l P r o g r a m			*/
/*	----------------------------------------------------------	*/
/*	executes a remote STOP instruction which dismantles the		*/
/*	entire current program context.					*/
/*	----------------------------------------------------------	*/
static	int 	StopAbalProgram( struct abal_program_handle * hptr )
{
	int	p;
	if ( hptr ) {
		close_abal_program();
		liberate( hptr );
		}
	return(0);
}

/*	----------------------------------------------------------	*/
/*	      	G e n e r a t e E x t e r n I n t e r f a c e		*/
/*	----------------------------------------------------------	*/
/*	this method is intended to generate the external interface.	*/
/*	----------------------------------------------------------	*/

static	int	GenerateExternInterface( struct abal_program_handle * hptr, char * filename, char * hostname )
{
	return(SOFTERROR);
}

/*	----------------------------------------------------------	*/
/*	      G e n e r a t e R p c X m l I n t e r f a c e		*/
/*	----------------------------------------------------------	*/
/*	this method is intended to generate the rpc xml interface.	*/
/*	----------------------------------------------------------	*/

static	int	GenerateRpcXmlInterface( struct abal_program_handle * hptr, char * filename, char * hostname  )
{
	return(SOFTERROR);
}

#include "exwsdl.c"

/*	----------------------------------------------------------	*/
/*	      G e n e r a t e P r o g r a m I n t e r f a c e		*/
/*	----------------------------------------------------------	*/
/*	generates the program interface with respect to the nature	*/
/*	or file type required. wsdl, ext, or xml rpc			*/
/*	----------------------------------------------------------	*/

static	int	GenerateProgramInterface( struct abal_program_handle * hptr, char * filename, char * filetype, char * hostname  )
{
	if (!( strcmp( filetype, "wsdl" ) ))
		return( GenerateWsdlInterface( hptr, filename,hostname ) );
	else if (!( strcmp( filetype, "ext" ) ))
		return( GenerateExternInterface( hptr, filename,hostname ) );
	else if (!( strcmp( filetype, "xml" ) ))
		return( GenerateRpcXmlInterface( hptr, filename,hostname ) );
	else	return( SOFTERROR );
}

/*	----------------------------------------------------------	*/
/*	      		L o a d A b a l P r o g r a m 			*/
/*	----------------------------------------------------------	*/
/*	loads the named program and returns a pointer to the abal	*/
/*	program handle top be used for the remote invocation of 	*/
/*	the various methods through the relays provided by the		*/
/*	program handle.							*/
/*	----------------------------------------------------------	*/
struct	abal_program_handle * LoadAbalProgram( char * n, int options )
{
	int	p;
	struct	abal_program_handle * hptr;
	if ( load_abal_program( n, options & 1 ) != 0 )
		return((struct abal_program_handle *) 0);
	else if (!( hptr = allocate( sizeof( struct abal_program_handle )  )))
		return( hptr );
	else if (!( hptr->program = allocate( strlen( n ) + 1 ) ))
	{
		liberate( hptr );
		return((struct abal_program_handle *) 0);
	}
	else
	{
		strcpy(hptr->program, n );
		hptr->stop       = StopAbalProgram;
		hptr->procedure  = CallAbalProcedure;
		hptr->parameter  = AbalProcedureParameter;
		hptr->parametertype  = AbalProcedureParameterType;
		hptr->result     = AbalProcedureResult;
		hptr->segment    = LdGoAbalSegment;
		hptr->procedures = procmaxid;
		hptr->segments   = SegmentCount;
		hptr->resolve    = ResolveAbalProcedure;
		hptr->interface  = GenerateProgramInterface;
		hptr->xmlparser  = xml_parse;
		return( hptr );
	}
}

	/* -------- */
#endif	/* _EXDLL_C */
	/* -------- */
