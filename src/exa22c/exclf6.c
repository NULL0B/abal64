/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCLF6.C  				*/
/*		Date 	:	20/05/1997				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 20/05/97 : Ajout du patch FORCEDREMOVE qui si actif rend les remove
 *            actifs meme sur des references.(A.M.)
 * 20/05/97 : Ajout du champs ValidityFlag dans la structure dynamic_control
 *            pour verifier la validite du pointeur alloue 
 *            voir fichier ptr.h (A.M.)
 *
 */

#ifndef	_EXCLF6_C
#define	_EXCLF6_C

/*	----------------------------------------------------		*/
/*	D Y N A M I C    A L L O C A T I O N   C O N T R O L		*/
/*	----------------------------------------------------		*/
#include "allocate.h"
#include "exptr.h"

static EXABYTE ForcedRemove[] = "FORCEDREMOVE=0";


#ifdef	DEBUGGER
#ifndef UNIX 
extern EXAWORD VerifPtr(VPTR);
#else
extern EXAWORD VerifPtr();
#endif
#endif

#ifdef	DEBUG_ATTACH
#define	attmsg(mptr) x_cprintf((BPTR) mptr); x_cprintf((BPTR)"\r\n");
#else
#define attmsg(mptr)
#endif
 
EXTERN	EXAWORD			simcbd;
EXTERN	EX_FILE_HANDLE		TcodeFileHandle;
EXTERN	EXAWORD			procmaxid;
EXTERN	struct procform SPTR 	TcodeProcTable;

	OVLOBJPTR		ProcContext;
	OVLOBJPTR		TcodeContext;
	struct	overlay_object	MasterContext;
	DYNOPTR			DynamixHeap;


void	initialise_dynamic_allocation()
{
	DynamixHeap = (DYNOPTR) 0;
	return;
}

void	liberate_dynamic_allocation()
{
	DYNOPTR	ldyn;

	while ((ldyn = DynamixHeap) != (DYNOPTR) 0) {
		DynamixHeap = ldyn->next;
		liberate( ldyn );
		}
	initialise_dynamic_allocation();
	return;
}

VOID	initialise_terminal_data( rptr, iteml, itemp, itemd, itemt )
BPTR	rptr;
EXAWORD	iteml;
EXAWORD	itemp;
EXAWORD	itemd;
EXAWORD	itemt;
{
	BPTR	wptr;
	EXAWORD	items;

	if ( itemt & ISPOINTER )
		memset( rptr, 0, 5 );
	else	{
		switch ( (itemt & VARB_ISOL ) ) {

			case VARB_INT8  :
			case VARB_INT16 :
				memset( rptr, 0, (iteml * itemp * itemd ) );
				break;

			case VARB_STR :
				memset( rptr, ' ', (iteml * itemp * itemd ) );
				break;

			case VARB_BCD :
				wptr = rptr;
				items = itemd;
				while ( itemp ) {
					while ( itemd ) {
						*wptr = 0x00CF;
						if ( iteml > 1 )
							memset( (wptr+1), 0x00FF, (iteml-1) );
						wptr += iteml; 
						itemd--;
						}
					itemd = items;
					itemp--;
					}
				break;
			}
		}
	return;
}

BPTR	initialise_object_member( mptr, tptr, varbtype )
BPTR	mptr;
BPTR	tptr;
EXAWORD	varbtype;
{
	EXAWORD	varblength;
	EXAWORD	first_dim;
	EXAWORD	second_dim;

	tptr 	 += WORDSIZE;
	mptr	 += (Tcodeword((tptr))); 
	tptr     += WORDSIZE;
	if (( varbtype & VARB_ISOL) > 1) {
		varblength = Tcodeword((tptr)); 
		tptr += WORDSIZE;
		}
	else	varblength = ((varbtype & VARB_ISOL) + 1);   

	/* Calculate possible dimensioned Result */
	/* ------------------------------------- */
	if ( varbtype & 0x0040 ) {
		first_dim = Tcodeword((tptr)); tptr += WORDSIZE;		
		if ( varbtype & 0x0020 ) {
			second_dim = Tcodeword((tptr)); tptr += WORDSIZE;		
			}
		else	second_dim = 1;
		}
	else	{
		first_dim = 1;
		second_dim = 1;
		}

	initialise_terminal_data( mptr, varblength, first_dim, second_dim, varbtype );
	return( tptr );

}

BPTR	next_variable_table_entry( tptr , vtype )
BPTR	tptr;
EXAWORD	vtype;
{
	if ( vtype & ISDYNAMIC ) {
		if ( vtype & ISMEMBER )
			tptr += (2 * WORDSIZE);
		else	tptr += WORDSIZE;
		}

	else if ( vtype & 0x7F00 )
		tptr += (2 * WORDSIZE);
	else	tptr += WORDSIZE;

	if (( vtype & VARB_ISOL ) > 1)
		tptr += WORDSIZE;
	if ( vtype & 0x0040 ) {
		if ( vtype & 0x0020 )
			tptr += (2 * WORDSIZE);
		else	tptr += WORDSIZE;
		}
	return( tptr );
}


BPTR	initialise_global_object( rptr, ptrvid )
BPTR	rptr;
EXAWORD	ptrvid;
{
	BPTR	tptr;
	EXAWORD	nbvarb;
	EXAWORD	thisvarb;
	EXAWORD	whichptr;
	tptr = (GlobalDataTable + (3 * WORDSIZE));
	for ( nbvarb = Tcodeword((GlobalDataTable)); nbvarb != 0; nbvarb-- ) {
		do	{
			thisvarb = Tcodeword((tptr));
			tptr += WORDSIZE;
			}
		while ( thisvarb & 0x0010 );
		if ((thisvarb & ISDYNAMIC) && ( thisvarb & ISMEMBER))
			if (( whichptr = Tcodeword((tptr))) == ptrvid ) {
				tptr = initialise_object_member( rptr, tptr, thisvarb );
				continue;
				}
		tptr = next_variable_table_entry( tptr, thisvarb );
		}
	return( rptr );
}

BPTR	object_initialisation( rptr, iteml, itemp, itemd, itemt, ptrvid )
BPTR	rptr;
EXAWORD	iteml;
EXAWORD	itemp;
EXAWORD	itemd;
EXAWORD	itemt;
EXAWORD	ptrvid;
{
	initialise_terminal_data( rptr, iteml, itemp, itemd, (itemt & 0x0003) );
	if (! (ptrvid & ISLOCAL) )
		initialise_global_object( rptr, ptrvid );
	return( rptr );
}

BPTR	dynamic_object_allocation( zone_length )
EXAWORD	zone_length;
{
	DYNOPTR	result;
	BPTR	rptr;

	/* Attempt to allocate for this object */
	/* ----------------------------------- */
	if (( result = (DYNOPTR) allocate( (zone_length + PREFIX_SIZE) )) == (DYNOPTR) 0)
		return( (BPTR) result );

	rptr = (BPTR) result;

	/* Integrate into dynamic object control list */
	/* ------------------------------------------ */
	result->usage = zone_length;
	result->ValidityFlag = MAGICWORD;
	if ((result->next = DynamixHeap) != (DYNOPTR) 0) {
		result->previous = DynamixHeap->previous;
		DynamixHeap->previous = result;
		}
	else	result->previous = (DYNOPTR) 0;

	DynamixHeap = result;

	return((BPTR) (rptr + PREFIX_SIZE ) );

}

BPTR	allocate_dynamic_object( pdesc, ptype, ptrvid )
BPTR	pdesc;
EXAWORD	ptype;
EXAWORD	ptrvid;
{
	BPTR	rptr;
	EXAWORD	item_length;
	EXAWORD	first_dim;
	EXAWORD	second_dim;

	/* Establish Object Unit Length */
	/* ---------------------------- */
	if ((item_length = ((ptype & 0x0003 )+1)) > 2) {
		item_length = Tcodeword((pdesc));
		pdesc += WORDSIZE;
		}

	/* Calculate possible dimensioned Result */
	/* ------------------------------------- */
	if ( ptype & 0x0040 ) {
		first_dim = Tcodeword((pdesc));
		pdesc += WORDSIZE;		
		if ( ptype & 0x0020 ) {
			second_dim = Tcodeword((pdesc)); 
			pdesc += WORDSIZE;		
			}
		else	second_dim = 1;
		}
	else	{
		first_dim = 1;
		second_dim = 1;
		}

	if ((rptr = dynamic_object_allocation(( item_length * first_dim * second_dim ) )) == (BPTR) 0)
		return( rptr );
		
	/* Return pointer to user text area */
	/* -------------------------------- */
	return( object_initialisation( rptr, item_length, first_dim, second_dim, ptype, ptrvid ) );


}


VOID	decrement_usage_counter( duptr )
BPTR	duptr;
{
	DYNOPTR	ldyn;

	/* Convert to control pointer */
	/* -------------------------- */
	ldyn = (DYNOPTR) (duptr - PREFIX_SIZE);

#ifdef	CONTROL_POINTER_USAGE
	/* Decrement if not already null */
	/* ----------------------------- */
	if ( ldyn->usage )
		ldyn->usage--;

	/* If No more users */
	/* ---------------- */
	if (!(ldyn->usage)) {
#endif
		/* Test of validityFlag */
		/* -------------------- */
		if(ldyn->ValidityFlag != MAGICWORD)
			return;	/* Incorrect structure */

		/* Erase the ValidityFlag */
		/* ---------------------- */
		ldyn->ValidityFlag = 0;		

		/* Check for not end of list and dis-integrate */
		/* ------------------------------------------- */
		if ( ldyn->next != (DYNOPTR) 0 )
			ldyn->next->previous = ldyn->previous;

		/* Check for top of list and dis-integrate */
		/* --------------------------------------- */
		if ( ldyn->previous != (DYNOPTR) 0 )
			ldyn->previous->next = ldyn->next;
		else	DynamixHeap = ldyn->next;

		/* Finally liberate this element */
		/* ----------------------------- */
		liberate( ldyn );


#ifdef	CONTROL_POINTER_USAGE
		}
#endif
	return;

}

VOID	increment_usage_counter( duptr )
BPTR	duptr;
{
	DYNOPTR	ldyn;

	/* Convert to control pointer */
	/* -------------------------- */
	ldyn = (DYNOPTR) (duptr - PREFIX_SIZE);
	
	ldyn->usage++;

	return;

}

VOID	liberate_dynamic_object( pvptr )
BPTR	pvptr;
{
	if ( pvptr != (BPTR) 0 )
		decrement_usage_counter( pvptr );
	return;
}


VOID	forget_reference( tptr )
BPTR	tptr;
{
#ifdef	CONTROL_POINTER_USAGE
	/* Test for Active Allocated Pointer */
	/* --------------------------------- */
	if ( *tptr == ALLOCATED_POINTER )
		decrement_usage_counter((TcodeGetPointer((tptr))));
#endif	
	/* Reset the pointer storage zone */
	/* ------------------------------ */
	raz_pointer_variable( tptr );
	return;
}

VOID	release_reference( tptr )
BPTR	tptr;
{
	attmsg("release_reference()");
	if(ForcedRemove[13]=='1'){
		liberate_dynamic_object((TcodeGetPointer((tptr))));
		raz_pointer_variable( tptr );
		}
	else{
	switch ( *tptr ) {
		case ALLOCATED_POINTER  :
			attmsg("REMOVE");
			liberate_dynamic_object((TcodeGetPointer((tptr))));
		case REFERENCED_POINTER :
			attmsg("FORGET");
			raz_pointer_variable( tptr );
		}
		}
	return;
}


EXAWORD	establish_alias( tptr, adesc )
BPTR	tptr;
EXAWORD	adesc;
{
	EXAWORD	mode;
	EXAWORD	vtype;
	EXAWORD	source;
	BPTR	sptr;
	BPTR	sdesc;
	BPTR	resolve_member(EXAWORD);
	EXAWORD	aliasi;

	switch ((mode = ((adesc & 0x0006) >> 1 ))) {
		case 0 :	/* Integer  */
			/* -------------------------------------- */
			/* ALIAS(0) will generate a NULL POINTER  */
			/* This is Like a FORGET if the target is */
			/* a pointer variable			  */
			/* -------------------------------------- */
			aliasi = Tcodeword((fdex)); 
			fdex += WORDSIZE;
			if ( aliasi != 0 ) {
				err_val = 118;
				return( SOFTERROR );
				}
			else	{
				forget_reference( tptr );
				return( GOODRESULT );
				}			
		case 1 :	/* Constant */
		case 2 :	/* Variable */

			source = Tcodeword((fdex)); 
			fdex += WORDSIZE;
			break;
		case 3 :
			source = *(fdex++);
			if ( xreg[ source ] == TEMPDESC ) {
				sptr = (TcodeByteStack + freg[ source ] + 4);
				if (((source = *sptr) > 3)
				||  (( sptr  = TcodeGetPointer( sptr )) == (BPTR) 0 ))
					source = 0;
				break;
				}

			else if ( xreg[ source ] == VARIABLE ) {
				/* Evaluate Register Operand */
				/* ------------------------- */
				if ( argset1(4,source) == SOFTERROR )
					return( SOFTERROR );
				else	{
					sptr = workptr1;
					source = 3;
					}
				break;
				}

		default:	/* Error ?? */
			err_val = 118;
			return( SOFTERROR );
		}

	/* Check for constant */
	/* ------------------ */
	if ( mode ==  1 ) {
	
		/* Calculate constant adresse */
		/* -------------------------- */
		sptr = (BPTR) (TcodeConstants + source);

		while (1) {
			/* Step over length and type */
			/* ------------------------- */ 
			if ( *(sptr++) )
				break;
			else if (!( *(sptr++) & 0x0080 ))
				break;
			sptr = (GlobalConstants + (Tcodeword((sptr))));
			}

		mode = (REFERENCED_POINTER | CONSTANT_POINTER);

		}
	else if ( mode == 2 ) {

		/* Resolve and Check Target */
		/* ------------------------ */
		if ( source & ISLOCAL ) {
			sdesc = (LocalDataTable + (source & TOGLOBAL));
			sptr  = LocalDataSegment;
			}
		else	{
			sdesc = (GlobalDataTable + source);
			sptr  = GlobalDataSegment;
			}

		/* Check for Non Pointer Variable Source */
		/* ------------------------------------- */
		if ((!((vtype = (Tcodeword((sdesc)))) & ISDYNAMIC))
		||  (!( vtype & ISPOINTER ))) {

			/* Evaluate as for normal arguments */
			/* -------------------------------- */
			if ( argset( 5, source, 1 ) == SOFTERROR )
				return( SOFTERROR );

			/* Establish Referencing information */
			/* --------------------------------- */
			mode = REFERENCED_POINTER;
			sptr = workptr1;
			}
		else	{

			sdesc += WORDSIZE;

			/* Allow evaluation of Redefinition pointers */
			/* ----------------------------------------- */
			if ( vtype & ISMEMBER ) {

				/* Allow resoloution of this pointer member */
				/* ---------------------------------------- */
				if (( sptr = resolve_member((Tcodeword((sdesc))))) == (BPTR) 0) {
					err_val = 118;
					return( SOFTERROR );
					}

				/* Step over Member Variable Identifier */
				/* ------------------------------------ */
				sdesc += WORDSIZE;

				}

			/* Evaluate Storage Adresse of this pointer */
			/* ---------------------------------------- */
			sptr += Tcodeword((sdesc)); sdesc += WORDSIZE;

			/* Collect actual pointer type */
			/* --------------------------- */
			if (((mode = *sptr) > 3)
			/* Collect actual pointer value */
			/* ---------------------------- */
			|| ((sptr = TcodeGetPointer((sptr))) == (BPTR) 0))
				mode = 0;

			}
		}
	else	mode = source;

	/* Check for Compatible usage perhaps NO ! */
	/* --------------------------------------- */

#ifdef	CONTROL_POINTER_USAGE
	/* --------------------------------------------- */
	/* Check for and adjust allocation usage counter */
	/* This must preceed the following "AUTO FORGET" */
	/* to ensure that alias to identical zones keep  */
	/* the zone ALIVE !!!!				 */
	/* --------------------------------------------- */
	if ( mode == ALLOCATED_POINTER )
		increment_usage_counter( sptr );
#endif
	/* Disconect this pointer now */
	/* -------------------------- */
	forget_reference( tptr );

	/* Set up and store result pointer variable */
	/* ---------------------------------------- */
	if ( mode != 0 ) {
		establish_pointer_variable( tptr, sptr, mode );
		}

	return( GOODRESULT );

}

EXAWORD	register_alias( registre, adesc )
EXAWORD	registre;
EXAWORD	adesc;
{
	BPTR	tptr;

	StackCheck( 9 );
	freg [ registre ] = worktop;	
	xreg [ registre ] = TEMPDESC;	
	tptr = (TcodeByteStack + worktop);	
	TcodePmot( tptr, VARB_STR);
	TcodePmot( (tptr + WORDSIZE),5 );
	tptr += (2 * WORDSIZE);
	worktop += 9;
	*tptr = 0;
	return( establish_alias( tptr, adesc ) );
}


EXAWORD	select_descriptor( mode, adesc, bdesc )
EXAWORD	mode;
EXAWORD	adesc;
EXAWORD	bdesc;
{
	switch ( mode ) {
		case 0 : 
			if ( adesc & 0x0010 )
				return(( adesc & 0x000F ) | 1 );
			else	return( 0 );
		case 1 :
			if ( adesc & 0x0001 )
				return( ((bdesc & 0x00F0) >> 4) | 1 );
			else	return( 0 );
		case 2 :
			if ( bdesc & 0x0010 )
				return( ((bdesc & 0x000F)) | 1 );
			else	return( 0 );
		default :
			return( 0 );
		}
}

EXAWORD	redimension_descriptor( dptr, type, adesc, bdesc )
BPTR	dptr;
EXAWORD	type;
EXAWORD	adesc;
EXAWORD	bdesc;
{
	EXAWORD	mode;
	EXAWORD	desc;

	/* First may be length */
	if (( type & 3 ) > 1 ) {
		if (argset(((adesc & 0x0006) >> 1),0,3) == SOFTERROR)
			return(SOFTERROR); 
		TcodePmot( dptr, workval3 );
		dptr += WORDSIZE;
		mode = 1;
		}
	else	mode = 0;
	
	if (((desc = select_descriptor( mode++, adesc, bdesc )) & 1) == 0)
		return( GOODRESULT );

	if (!( type & 0x0040 ))	 
		return( SOFTERROR );

	if (argset(((desc & 0x0006) >> 1),0,3) == SOFTERROR)
		return(SOFTERROR); 
	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	if (((desc = select_descriptor( mode++, adesc, bdesc )) & 1) == 0)
		return( GOODRESULT );

	if (!( type & 0x0020 ))	 
		return( SOFTERROR );

	if (argset(((desc & 0x0006) >> 1),0,3) == SOFTERROR)
		return(SOFTERROR); 
	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	return( GOODRESULT );

}


EXAWORD	connect_program_procedure( attbase )
BPTR	attbase;
{
	EXAWORD		thisproc;
#ifdef	DEBUGGER
	VOID	force_symbolic_attachment( OVLOBJPTR );
#endif
	attbase = (BPTR) TcodeGetPointer((attbase));
	ProcContext = (OVLOBJPTR) TcodeGetPointer((attbase));
	attbase += 5;
	thisproc = Tcodeword((attbase));

	special_procedure_push();

	TcodeContext      = ProcContext;

#ifdef	DEBUGGER
	force_symbolic_attachment( ProcContext );
#endif
	TcodeProcTable    = (struct procform SPTR)ProcContext->procedures;
	TcodeFileHandle   = ProcContext->handle;
	procmaxid         = ProcContext->procmaxid;

	return( thisproc );
}


#ifdef	DEBUGGER
EXAWORD	get_procid_by_ptr( attbase )
BPTR	attbase;
{
	EXAWORD		thisproc;
	OVLOBJPTR	contextproc;
#ifdef	DEBUGGER
	VOID	force_symbolic_attachment( OVLOBJPTR );
#endif
	attbase = (OVLOBJPTR) TcodeGetPointer((attbase));
	if ( VerifPtr( attbase ) == 0 )
	{
		contextproc = (OVLOBJPTR) TcodeGetPointer((attbase));
		if( VerifPtr( contextproc ) == 0 )
		{
			attbase += 5;
			thisproc = Tcodeword((attbase));

			force_symbolic_attachment( contextproc );

		}
		else
			thisproc= MOINS_UN;	
	}
	else
		thisproc = MOINS_UN;
	return( thisproc );
}
#endif


VOID	collect_indirect_gds()
{
	GlobalDataTable   = ProcContext->descriptors;
	GlobalDataSegment = ProcContext->variables;
	GlobalConstants   = TcodeConstants = ProcContext->constants;
#ifdef	_ABAL_DLL_PRIVATE
	FuseBase 	  = (struct fusework SPTR) ProcContext->libraries;
#endif
	return;
}

EXAWORD	release_overlay_context( context, oldhandle, result )
OVLOBJPTR	context;
EX_FILE_HANDLE	oldhandle;
EXAWORD		result;
{
	CloseTcodeFile( context->handle );
	TcodeFileHandle = oldhandle;

	if ( context->constants != (BPTR) 0)
		liberate( context->constants );

	liberate_dynamic_object( context->variables );

	if ( context->descriptors != (BPTR) 0)
		liberate( context->descriptors );

	if ( context->procedures != (BPTR) 0)
		liberate( context->procedures );

	liberate( context );
	return( result ); 
}


#ifndef	OLD_ATTACH

#include "exattach.h"
#include "exattach.c"


/*
 *	A T T A T C H _ I N D I R E C T _ P R O G R A M
 *	-----------------------------------------------
 *
 */

EXAWORD	attatch_indirect_program( result, adesc )
BPTR	result;
EXAWORD	adesc;
{
	BPTR	attnfic;
	EXAWORD	i;
	BPTR	assigned_filename( EXAWORD );

	/* Evaluate handle or filename parameter */
	/* ------------------------------------- */
	if (argset(((adesc & 0x0006) >> 1),0,2) == SOFTERROR) 
		return(SOFTERROR);

	/* Strings are filenames */
	/* --------------------- */
	if ( (worktyp2 & VARB_ISOL) == VARB_STR) {
		StackCheck( (worklen2+1) );
		attnfic = (BPTR) (TcodeByteStack + worktop);
		for ( i = 0; worklen2 != 0; worklen2-- ) {
			if ( *workptr2 <= ' ' )
				break;
			else	*(attnfic + (i++)) = *(workptr2++);
			}
		*(attnfic + (i++)) = 0;
		worktop += i;
		}
	else	{
		/* Watch out for atr bug : BCD constant */
		/* ------------------------------------ */
		if ( (worktyp2 & VARB_ISOL) == VARB_BCD)
			workval2 = bcdtoi((BPTR) workptr2, worklen2 );

		/* Assign handle */
		/* ------------- */
		if ((attnfic = assigned_filename( workval2 )) == (BPTR) 0) {
			err_val = 116;
			return( SOFTERROR );
			}
		}
	return( overlay_object_attachment( attnfic, result ) );
}


#else 	/* OLD_ATTACH */

BPTR	allocate_indirection_table( proc_nombre, context )
EXAWORD	proc_nombre;
BPTR	context;
{
	BPTR	result;
	EXAWORD	thisproc;
	EXAWORD	indent;

	if ((result = allocate( (proc_nombre * 7) )) != (BPTR) 0) {
	
		for (indent=0, thisproc = 0; proc_nombre != 0; proc_nombre-- ) {
			establish_pointer_variable((BPTR) (result+indent),(BPTR) context, ALLOCATED_POINTER );
			indent += 5;
			TcodePmot( (result+indent), thisproc );
			indent += 2;
			thisproc += 16;
			}
		}

	return( result );
}

EXAWORD	attatch_indirect_program( result, adesc )
BPTR	result;
EXAWORD	adesc;
{
	EX_FILE_HANDLE	tcode_handle;
	EX_FILE_HANDLED	hold_handle;
	EXAWORD	thisproc;
	BPTR	fdex;
	EXAWORD	dcrypt;
	EXAWORD	gdt_sector;
	EXAWORD	gdt_length;
	EXAWORD	gct_sector;
	EXAWORD	gct_length;
	EXAWORD	gpt_sector;
	EXAWORD	gpt_length;
	EXAWORD	ppt_length;
	EXAWORD	proc_nombre;
	EXAWORD	indent;
	BPTR	gct;
	BPTR	gdt;
	BPTR	attnfic;
	BPTR	ipt;
	OVLOBJPTR	context;
	EXAWORD	kode_b_lode( BPTR, EXAWORD, EXAWORD );
	BPTR	assigned_filename( EXAWORD );
	BPTR 	load_tcode_procedures( EXAWORD, BPTR);

	/* Evaluate handle or filename parameter */
	/* ------------------------------------- */
	if (argset(((adesc & 0x0006) >> 1),0,2) == SOFTERROR) 
		return(SOFTERROR);

	/* Strings are filenames */
	/* --------------------- */
	if ( (worktyp2 & VARB_ISOL) == VARB_STR)
		attnfic = workptr2;
	else	{
		/* Watch out for atr bug : BCD constant */
		/* ------------------------------------ */
		if ( (worktyp2 & VARB_ISOL) == VARB_BCD)
			workval2 = bcdtoi((BPTR) workptr2, worklen2 );

		/* Assign handle */
		/* ------------- */
		if ((attnfic = assigned_filename( workval2 )) == (BPTR) 0) {
			err_val = 116;
			return( SOFTERROR );
			}
		}

	/* Attempt to attach this specified program */
	/* ---------------------------------------- */
	if ((tcode_handle = open_tcode_file((BPTR) attnfic )) == EX_UNUSED_HANDLE )
		return( SOFTERROR );

	/* Load Tcode Header */
	/* ----------------- */
	if (SectRead((EX_FILE_HANDLE) tcode_handle,(BPTR) askbuf, BLOCK, 0) == MOINS_UN) {
		CloseTcodeFile( tcode_handle );
		return( SOFTERROR ); 
		}		

	hold_handle = TcodeFileHandle;
	TcodeFileHandle = tcode_handle;

	fdex  = (BPTR) askbuf;

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	Tcodeword( (fdex + 62 ) );

	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		(VOID) exa_crypt(dcrypt,(BPTR) (fdex + 18),44,0);

	/* Allocate Global Variables */
	/* ------------------------- */
	gct_sector = Tcodeword( (fdex + 0x0016 ) );
	gct_length = Tcodeword( (fdex + 0x0018 ) );
	gdt_sector = Tcodeword( (fdex + 0x001A ) );
	gdt_length = Tcodeword( (fdex + 0x001C ) );
	gpt_sector = Tcodeword( (fdex + 0x0026 ) );
	gpt_length = Tcodeword( (fdex + 0x0028 ) );

	/* Allocate Context controller */
	/* --------------------------- */
	if (( context = (OVLOBJPTR) allocate( sizeof( struct overlay_object ))) == (OVLOBJPTR) 0) {
		CloseTcodeFile( tcode_handle );
		TcodeFileHandle = hold_handle;
		return( SOFTERROR ); 
		}
	else	{
		context->handle      = tcode_handle;
		context->procmaxid   = 0;
		context->constants   = (BPTR) 0;
		context->variables   = (BPTR) 0;
		context->descriptors = (BPTR) 0;
		context->procedures  = (BPTR) 0;
		}

	/* Load Overlay Constants */
	/* ---------------------- */
	if ((gct_sector != MOINS_UN) && (gct_sector != 0)) 
		if (((context->constants = (BPTR) allocate( gct_length )) == (BPTR) 0)
		||  (kode_b_lode(context->constants, gct_sector, gct_length) == MOINS_UN ))
			return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	if (((context->descriptors = (BPTR) allocate( gdt_length )) == (BPTR) 0)
	||  (kode_b_lode( context->descriptors, gdt_sector, gdt_length) == MOINS_UN ))
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	gdt_length = Tcodeword((context->descriptors + 4)); 

	if ((context->variables = dynamic_object_allocation( gdt_length )) == (BPTR) 0)
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	establish_pointer_variable( (result+5), context->variables, ALLOCATED_POINTER );
	
	/* Load Procedure Table */
	/* -------------------- */
	context->procmaxid = proc_nombre = ( gpt_length / 16 );
	ppt_length =  ( proc_nombre * 5 );

	/* Allocate for table of Procedure pointers */
	/* ---------------------------------------- */
	if ((gdt = dynamic_object_allocation( ppt_length )) == (BPTR) 0)
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	establish_pointer_variable( result, gdt, ALLOCATED_POINTER );

	/* Initialise loaded procedures */
	/* ---------------------------- */
	result = gdt;

	if (((gdt = (BPTR) allocate( gpt_length )) == (BPTR) 0)
	||  (kode_b_lode( gdt, gpt_sector, gpt_length) == MOINS_UN ))
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	/* Allocate Indirection Table */
	/* -------------------------- */
	if ((ipt = (BPTR) allocate_indirection_table( proc_nombre, context )) == (BPTR) 0) {
		liberate( gdt );
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );
		}

	/* Now Load Actual Procedure Table as for Normal Program */
	/* ----------------------------------------------------- */
	if ((context->procedures = (BPTR) load_tcode_procedures( proc_nombre , gdt )) == (BPTR) 0) {
		liberate( gdt );
		liberate( ipt );
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );
		}

	liberate( gdt );

	/* Now initialise Procedure Indirection Table */
	/* ------------------------------------------ */
	for (thisproc = 0 ; proc_nombre > 0; proc_nombre-- ) {
		establish_pointer_variable( result,(BPTR) ipt, PROGRAM_POINTER );
		result += 5;
		ipt    += 7;
		}

	/* Restore Tcode File Handle */
	/* ------------------------- */
	TcodeFileHandle = hold_handle;

	return( GOODRESULT );

}

#endif

#ifdef	VERSION_XX
VOID	finalise_indirection()
{
	if (!( ProcContext ))
		return;
	else if ((ISLOCAL = ProcContext->islocal) & ISLOCAL3)
		TOGLOBAL = TOGLOBAL3;
	else	TOGLOBAL = TOGLOBAL4;
	return;
}

VOID	prepare_indirection()
{
	ProcContext = (OVLOBJPTR) 0;
	return;
}

#endif

VOID	reset_indirection_control()
{
	TcodeContext = (OVLOBJPTR) 0;
	return;
}

VOID	initialise_indirection_control()
{
	TcodeContext = (OVLOBJPTR) & MasterContext;
	TcodeContext->handle      = TcodeFileHandle;
	TcodeContext->procmaxid   = procmaxid;
	TcodeContext->constants   = GlobalConstants;
	TcodeContext->variables   = GlobalDataSegment;
	TcodeContext->descriptors = GlobalDataTable;
	TcodeContext->procedures  = (BPTR) TcodeProcTable;
#ifdef	_ABAL_DLL_PRIVATE
	TcodeContext->libraries   = FuseBase;
#endif
	TcodeContext->nbdll       = 0;
	TcodeContext->master      = (VPTR) 0;
	TcodeContext->ipt         = (BPTR) 0;
#ifdef	VERSION_XX
	TcodeContext->islocal     = ISLOCAL;
#endif
	return;
}

VOID	identify_current_tcode()
{
	ATTLOGPTR	attlog;
	if (( attlog = TcodeContext->master ) != (ATTLOGPTR) 0) {
		if ( attlog->filename != (BPTR) 0) {
			x_cprintf((BPTR) attlog->filename );
			x_newlyne();
			}
		}
	return;
}

VOID	liberate_indirection_control()
{
	if ((TcodeContext != (OVLOBJPTR) 0)
	&&  (TcodeContext->ipt != (BPTR) 0)) {
		liberate( TcodeContext->ipt );
		TcodeContext->ipt = (BPTR) 0;
		}
	reset_indirection_control();
	return;
}

EXAWORD	attatch_procedure_pointer( result, procid )
BPTR	result;
EXAWORD	procid;
{
	if (( TcodeContext->ipt == (BPTR) 0 )
	&&  ((TcodeContext->ipt = allocate_indirection_table( procmaxid,(BPTR) TcodeContext )) == (BPTR) 0)) {
		err_val = 27;
		return( SOFTERROR );
		}
	else	{
establish_pointer_variable( result,(BPTR) (TcodeContext->ipt + ((procid / 16) * 7)), PROGRAM_POINTER );
		return( GOODRESULT );
		}
}
	
EXAWORD	allocated_object_size( xptr )
BPTR	xptr;
{
	DYNOPTR	ldyn;

	/* Convert to control pointer */
	/* -------------------------- */
	ldyn = (DYNOPTR) (xptr - PREFIX_SIZE);

	return( ldyn->usage );

}

VOID	release_indirect_program( tptr )
BPTR	tptr;
{
	BPTR		pgmbase;
	BPTR		objbase;
	BPTR		prcbase;
	EXAWORD		indent;
	EXAWORD		objsize;
	EXAWORD		filehandle;

	attmsg("DETACH_indirect_program()");

	/* Collect object base pointer */
	/* --------------------------- */
	if ((pgmbase = (TcodeGetPointer((tptr)))) != (BPTR) 0) {

		/* Collect and release OBJECT data storage area */
		/* -------------------------------------------- */
		if ((objbase = (TcodeGetPointer((pgmbase+5)))) != (BPTR) 0) {
			attmsg("release OBJECT DATA container");
			release_reference( (pgmbase+5) );
			}

		/* Collect OBJECT Method table pointer */
		/* ----------------------------------- */
		if ((objbase = (TcodeGetPointer(pgmbase))) != (BPTR) 0) {

			objsize = allocated_object_size( objbase );

			/* Release loaded procedures */
			/* ------------------------- */
			if ((prcbase = (TcodeGetPointer((objbase)))) != (BPTR) 0)
				/* This is the IPT */
				/* --------------- */
				release_attachment_log_entry( prcbase );

			attmsg("release OBJECT METHOD table");
			release_reference( pgmbase );
			}

		/* Release OBJECT base */
		/* ------------------- */
		attmsg("release OBJECT BASE");
		release_reference( tptr );
		}

	raz_pointer_variable( tptr );

	return;
}

/*
 *	----------------------
 *	F _ C L F 6 ( opcode )
 *	----------------------
 *
 *	Functions which Manipulate Dynamic objects : 
 *
 *		CREATE  <pointer_variable> <dimensions> tcCLF  x06
 *		REMOVE  <pointer_variable> <dimensions> tcCLF  x16
 *		FORGET  <pointer_variable>		tcCLF  x26
 *		ALIAS   <pointer_variable> <something>	tcCLF  x36
 *		ATTATCH <pointer_variable> <string>	tcCLF  x46
 *		RELEASE <pointer_variable> 		tcCLF  x56
 *		ALTER	<pointer_variable> <dimensions> tcCLF  x66
 *
 */

EXAWORD	f_clf6( opcode )
EXAWORD	opcode;
{
	EXAWORD	adesc;		/* Arguament Descriptor		*/
	EXAWORD	bdesc=0;
	BPTR	tdesc;		/* Descriptor Pointer		*/
	BPTR	tptr;		/* Memory Storage Pointer	*/
	EXAWORD	target;		/* Pointer Variable Identity	*/
	EXAWORD	xtarget;	/* Copy of Variable identity	*/
	BPTR	result;		/* Allocation result pointer	*/
	EXAWORD	registre;
	BPTR	resolve_member(EXAWORD);
	BPTR	rptr;
	EXAWORD	local_error;

	/* Ensure First Arguament is correct ie a VARIABLE type POINTER */
	/* ------------------------------------------------------------ */
	if (((adesc = (EXAWORD) *(fdex++)) & 0x0060) == 0x0060) {
		if ( opcode != 3 ) {
			err_val = 115;
			return( SOFTERROR );
			}
		return( register_alias( *(fdex++), adesc ) );
		}
	else	{
		/* Collect Target Variable Identifier */
		/* ---------------------------------- */
		if ( adesc & 1 )
			bdesc = *(fdex++);
		registre = 0;
		xtarget = target = Tcodeword( (fdex) ); 
		fdex += WORDSIZE;
		}

	/* ----------------------------------------- */
	/* Establish storage adresse of this pointer */
	/* ----------------------------------------- */
	/* Resolve and Check Target */
	/* ------------------------ */
	if ( target & ISLOCAL ) {
		tdesc = (LocalDataTable + (target & TOGLOBAL));
		tptr  = LocalDataSegment;
		}
	else	{
		tdesc = (GlobalDataTable + target);
		tptr  = GlobalDataSegment;
		}

	if (!((target = (Tcodeword((tdesc)))) & ISDYNAMIC)) {
		err_val = 118;
		return( SOFTERROR );
		}

	tdesc += WORDSIZE;

	if ( target & ISETENDU ) {
		err_val = 56;
		return( SOFTERROR );
		}

	/* Allow evaluation of Redefinition pointers */
	/* ----------------------------------------- */
	if ( target & ISMEMBER ) {

		/* Ensure this is a pointer type */
		/* ----------------------------- */
		if (!(target  & ISPOINTER)) {
			if ( opcode != 6 ) {
				err_val = 118;
				return( SOFTERROR );
				}
			else	return( redimension_descriptor( (tdesc+WORDSIZE), target, adesc, bdesc ) );

			}

		/* Resolve the area pointed to by member indirection */
		/* ------------------------------------------------- */
		if (( tptr = resolve_member((Tcodeword((tdesc))))) == (BPTR) 0) {
			err_val = 118;
			return( SOFTERROR );
			}

		/* Step over Member Variable Identifier */
		/* ------------------------------------ */
		tdesc += WORDSIZE;

		}

	/* Evaluate Storage Adresse of this pointer */
	/* ---------------------------------------- */
	tptr += Tcodeword((tdesc)); tdesc += WORDSIZE;

	/* We are now pointing to the possible Length and dimensions */
	/* --------------------------------------------------------- */
	/* Check for Redimensioning possible and required	     */
	/* --------------------------------------------------------- */
	if ((( opcode < 3 ) || ( opcode == 6 ))
	&&  ( target & 0x0062 ) 
	&&  ( adesc  & 0x0010 )
 	&&  ( redimension_descriptor( tdesc, target, adesc, bdesc ) == SOFTERROR ))
		return( SOFTERROR );

	/* Select Required operation */
	/* ------------------------- */
	switch ( opcode ) {

		case 0 	:	/* Ensure Pointer devalidated */
				/* -------------------------- */
				forget_reference( tptr );

				/* Attempt to allocate for Specified Type */
				/* -------------------------------------- */
				if (( result = allocate_dynamic_object( tdesc, target, xtarget )) == (BPTR) 0)
					break;

				/* Create Referenced Object */
				/* ------------------------ */
				establish_pointer_variable( tptr, result, ALLOCATED_POINTER );

				/* Indicate success */
				/* ---------------- */
				return( GOODRESULT );					

		case 1 	:	/* Delete Referenced Object */
				/* ------------------------ */
				release_reference( tptr );
				return( GOODRESULT );

		case 2	:	/* Delete Referenced Object */
				/* ------------------------ */
				forget_reference( tptr );
				return( GOODRESULT );

		case 3  :	/* Create ALIAS/REFERENCE */
				/* ---------------------- */

				return( establish_alias( tptr, adesc ) );


		case 4  :	/* Connect : filename	    */
				/* ------------------       */
				if ((result = dynamic_object_allocation( 10 )) == (BPTR) 0)
					return( SOFTERROR );

				/* Create Allocated  Object */
				/* ------------------------ */
				establish_pointer_variable( tptr, result, ALLOCATED_POINTER );

				if (attatch_indirect_program( result, adesc ) == SOFTERROR) {
					local_error = err_val;
					release_reference( tptr );
					if (( err_val = local_error) == 0 )
						err_val = 136;
					return( SOFTERROR );
					}
				else	return( GOODRESULT );
				
		case 5  :	/* Release */
				/* ------- */
				release_indirect_program( tptr );
				return( GOODRESULT );
	

		case 6  :	/* Alter */
				/* ----- */
				return( GOODRESULT );

	
		default :	/* Unknown function codes   */
				/* ----------------------   */
				err_val = 56;
				return( SOFTERROR );

		}

	/* Error Handling happens here */
	/* --------------------------- */
	err_val = 27; return( SOFTERROR );
	
}
 	
	/* --------- */
#endif	/* _EXCLF6_C */
	/* --------- */

