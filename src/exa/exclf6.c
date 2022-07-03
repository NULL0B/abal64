/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXCLF6.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 
/* Mises a jour :
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
#include "exngf.h"

static EXABYTE ForcedRemove[] = "FORCEDREMOVE=0";

EXTERN EXAWORD TcodeTraceControl;

#ifdef	DEBUGGER
extern EXAWORD VerifPtr(BPTR);
#endif

EXTERN	EXAWORD			simcbd;
EXTERN	EX_FILE_HANDLE	TcodeFileHandle;
EXTERN	EXAWORD			procmaxid;
EXTERN	struct procform PTR TcodeProcTable;
EXTERN	BPTR			ExportTable;
OVLOBJPTR				ProcContext;
OVLOBJPTR				TcodeContext;
struct	overlay_object	MasterContext;
DYNOPTR					DynamixHeap;

#include "exptr.c"

/*	---------------------------------	*/
/*	  initialise_dynamic_allocation 	*/
/*	---------------------------------	*/
/*	initialise the dynamic allocation	*/
/*	management system for PTR tracking	*/
/*	---------------------------------	*/
void	initialise_dynamic_allocation()
{
#ifdef	ABAL64
	AllocateIndexedPointers();
#endif
	DynamixHeap = (DYNOPTR) 0;
	return;
}

/*	-------------------------------		*/
/*	  liberate_dynamic_allocation   	*/
/*	-------------------------------		*/
/*	liberate the dynamic allocation		*/
/*	mechanisms and release all PTR		*/
/*	variables outstanding.				*/
/*	-------------------------------		*/
void	liberate_dynamic_allocation()
{
	DYNOPTR	ldyn;

	while ((ldyn = DynamixHeap) != (DYNOPTR) 0) {
		DynamixHeap = ldyn->next;
		liberate( ldyn );
		}
	initialise_dynamic_allocation();
#ifdef	ABAL64
	ReleaseIndexedPointers();
#endif
	return;
}

/*	------------------------	*/
/*	initialise_terminal_data	*/
/*	------------------------	*/
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
		memset( rptr, 0, PTRSIZE );
	else	
	{
		switch ( (itemt & VARB_ISOL ) ) 
		{
		case VARB_INT8  :
		case VARB_INT16 :
		case VARB_INT32 :
		case VARB_INT64 :
			memset( rptr, 0, (iteml * itemp * itemd ) );
			break;

		case VARB_STR :
			memset( rptr, ' ', (iteml * itemp * itemd ) );
			break;

		case VARB_BCD :
			wptr = rptr;
			items = itemd;
			while ( itemp ) 
			{
				while ( itemd ) 
				{
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

/*	------------------------	*/
/*	initialise_object_member	*/
/*	------------------------	*/
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

	/* IJM : IMPORTANT CORRECTION 32B : 12/7/2006 */
	/* ------------------------------------------ */
	switch (( varbtype & VARB_ISOL))
	{
	case VARB_FOUR  :
	case VARB_INT8  : varblength = 1; break;
	case VARB_INT16 : varblength = ABALWORDSIZE; break;
	case VARB_INT32 : varblength = (2*ABALWORDSIZE); break;
	case VARB_INT64 : varblength = (4*ABALWORDSIZE); break;
	default		: varblength = Tcodeword((tptr)); 
			  tptr += WORDSIZE;
	}

	/* Calculate possible dimensioned Result */
	/* ------------------------------------- */
	if ( varbtype & NDX1st) 
	{
		first_dim = Tcodeword((tptr)); tptr += WORDSIZE;		
		if ( varbtype & NDX2nd ) 
		{
			second_dim = Tcodeword((tptr)); tptr += WORDSIZE;		
		}
		else	second_dim = 1;
	}
	else
	{
		first_dim = 1;
		second_dim = 1;
	}

	initialise_terminal_data( mptr, varblength, first_dim, second_dim, varbtype );

	return( tptr );

}

/*	-------------------------	*/
/*	next_variable_table_entry	*/
/*	-------------------------	*/
BPTR	next_variable_table_entry( tptr , vtype )
BPTR	tptr;
EXAWORD	vtype;
{
	if ( vtype & ISDYNAMIC ) 
	{
		if ( vtype & ISMEMBER )
			tptr += (2 * WORDSIZE);
		else	tptr += WORDSIZE;
	}
	else if ( vtype & 0x7F00 )
		tptr += (2 * WORDSIZE);
	else	tptr += WORDSIZE;

	/* IJM : IMPORTANT CORRECTION 32B : 12/7/2006 */
	/* ------------------------------------------ */
	if ((( vtype & VARB_ISOL ) > 1)
	&&  (( vtype & VARB_ISOL ) < 5))
		tptr += WORDSIZE;
	if ( vtype & NDX1st ) 
	{
		if ( vtype & NDX2nd )
			tptr += (2 * WORDSIZE);
		else	tptr += WORDSIZE;
	}
	return( tptr );
}

/*	------------------------	*/
/*	initialise_global_object	*/
/*	------------------------	*/
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

/*	-------------------------	*/
/*	  object_initialisation 	*/
/*	-------------------------	*/
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

/*	-------------------------------------------------	*/
/*	d y n a m i c _ o b j e c t _ a l l o c a t i o n	*/
/*	-------------------------------------------------	*/
/*	allocation of the dynamic object and control info	*/
/*	linked into a list and stored in the 64 storage.	*/
/*	-------------------------------------------------	*/
BPTR	dynamic_object_allocation( zone_length )
EXAWORD	zone_length;
{
	DYNOPTR	result;
	BPTR	rptr;

	/* Attempt to allocate for this object */
	/* ----------------------------------- */
	if (( result = (DYNOPTR) allocate( (zone_length + PREFIX_SIZE) )) == (DYNOPTR) 0)
		return( (BPTR) result );
	else	rptr = (BPTR) result;

	/* Integrate into dynamic object control list */
	/* ------------------------------------------ */
	result->usage = zone_length;
	result->ValidityFlag = MAGICWORD;

#ifdef	ABAL64
	if ( PTRSIZE < ABALPTRSIZE )
	{
		result->value = SetIndexedPointer((rptr + PREFIX_SIZE));
	}
#endif

	/* Add to List of Dynamic Objects */
	/* ------------------------------ */
	if ((result->next = DynamixHeap) != (DYNOPTR) 0) 
	{
		result->previous = DynamixHeap->previous;
		DynamixHeap->previous = result;
	}
	else	result->previous = (DYNOPTR) 0;

	DynamixHeap = result;

	return((BPTR) (rptr + PREFIX_SIZE ) );

}

#ifdef	ABAL64

/*	------------------	*/
/*	GetSymbolicPointer	*/
/*	------------------	*/
VPTR	GetSymbolicPointer(BPTR value)
{
	DYNOPTR	dptr;
	if (!( value ))
		return((VPTR) 0);
	else
	{
		dptr = (DYNOPTR) (value - PREFIX_SIZE);
		return( (VPTR) dptr->value );
	}
}

#else
#define	GetSymbolicPointer(value) value
#endif

/*	-------------------------	*/
/*	 allocate_dynamic_object	*/
/*	-------------------------	*/
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
	switch ( ptype & VARB_ISOL ) {
		case VARB_FOUR :
		case VARB_INT8 : 
			item_length = 1;
			break;
		case VARB_INT16 : 
			item_length = (ABALWORDSIZE); 
			break;
		case VARB_INT32 : 
			item_length = (2*ABALWORDSIZE); 
			break;
		case VARB_INT64 : 
			item_length = (4*ABALWORDSIZE); 
			break;
		default		:
			item_length = Tcodeword((pdesc));
			pdesc += WORDSIZE;
		}

	/* Calculate possible dimensioned Result */
	/* ------------------------------------- */
	if ( ptype & NDX1st ) 
	{
		first_dim = Tcodeword((pdesc));
		pdesc += WORDSIZE;		
		if ( ptype & NDX2nd ) 
		{
			second_dim = Tcodeword((pdesc)); 
			pdesc += WORDSIZE;		
		}
		else	second_dim = 1;
	}
	else	
	{
		first_dim = 1;
		second_dim = 1;
	}

	if ((rptr = dynamic_object_allocation(( item_length * first_dim * second_dim ) )) == (BPTR) 0)
		return( rptr );
		
	/* Return pointer to user text area */
	/* -------------------------------- */
	return( object_initialisation( rptr, item_length, first_dim, second_dim, ptype, ptrvid ) );


}

/*	-------------------------	*/
/*	 decrement_usage_counter	*/
/*	-------------------------	*/
VOID	decrement_usage_counter( duptr )
BPTR	duptr;
{
	DYNOPTR	ldyn;

	/* Convert to control pointer */
	/* -------------------------- */
	if ( TcodeTraceControl ) {
		fprintf(stderr,"decrement usage counter %lu \n",duptr);
		}
	
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

#ifdef	ABAL64
		/* Remove the Indexed Pointer */
		/* -------------------------- */
		if ( PTRSIZE < ABALPTRSIZE )
		{
			RazIndexedPointer( ldyn->value );
		}
#endif
		/* Finally liberate this element */
		/* ----------------------------- */
		liberate( ldyn );

#ifdef	CONTROL_POINTER_USAGE
		}
#endif
	return;

}

/*	-------------------------	*/
/*	 increment_usage_counter	*/
/*	-------------------------	*/
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

/*	-------------------------	*/
/*	 liberate_dynamic_object	*/
/*	-------------------------	*/
VOID	liberate_dynamic_object( pvptr )
BPTR	pvptr;
{
	if ( pvptr != (BPTR) 0 )
		decrement_usage_counter( pvptr );
	return;
}

/*	----------------	*/
/*	forget_reference	*/
/*	----------------	*/
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
	TcodeRazPointer( tptr );
	return;
}

/*	-----------------	*/
/*	release_reference	*/
/*	-----------------	*/
VOID	release_reference( tptr )
BPTR	tptr;
{
	if(ForcedRemove[13]=='1')
	{
		liberate_dynamic_object((TcodeGetPointer((tptr))));
		TcodeRazPointer( tptr );
	}
	else
	{
		switch ( *tptr ) 
		{
		case ALLOCATED_POINTER  :
			liberate_dynamic_object((TcodeGetPointer((tptr))));
		case REFERENCED_POINTER :
			TcodeRazPointer( tptr );
		}
	}
	return;
}

/*	---------------------------------	*/
/*	  e s t a b l i s h _ a l i a s  	*/
/*	---------------------------------	*/
/*						*/
/*	This must handle the following :	*/
/*						*/
/*	PTR V = ALIAS ( PTR V )			*/
/*						*/
/*	PTR V = ALIAS ( DCL V )			*/
/*						*/
/*	PTR V = ALIAS ( CONST )			*/
/*						*/
/*	PTR V = ALIAS ( REGISTER )		*/
/*						*/
/*	---------------------------------	*/
/*	The ABAL64 version requires very	*/
/*	careful handling of each case.		*/
/*	---------------------------------	*/
/*		IJM 04/05/2022			*/
/*	---------------------------------	*/

EXAWORD	establish_alias( tptr, adesc )
BPTR	tptr;
EXAWORD	adesc;
{
	EXAWORD	mode;
	EXAWORD	vtype;
	EXAWORD	source;
#ifdef	ABAL64
	EXAWORD	logical_address=0;
#endif
	BPTR	sptr;
	BPTR	sdesc;
	BPTR	resolve_member(EXAWORD);
	EXAWORD	aliasi;

	/* ------------------------------------------- */
	/* determine the nature of the argument source */
	/* ------------------------------------------- */
	switch ((mode = ((adesc & 0x0006) >> 1 ))) 
	{
	case 0 :/* Integer  */
		/* -------------------------------------- */
		/* ALIAS(0) will generate a NULL POINTER  */
		/* This is Like a FORGET if the target is */
		/* a pointer variable			  */
		/* -------------------------------------- */
		aliasi = Tcodeword((fdex)); 
		fdex += WORDSIZE;
		if ( aliasi != 0 ) 
		{
			err_val = 118;
			return( SOFTERROR );
		}
		else
		{
			forget_reference( tptr );
			return( GOODRESULT );
		}			

	case 1 :/* Constant */
	case 2 :/* Variable */
		source = Tcodeword((fdex)); 
		fdex += WORDSIZE;
		break;

	case 3 :/* Register */
		source = *(fdex++);
		if ( xreg[ source ] == TEMPDESC ) 
		{
			/* ----------------------------------------------------- */
			/* it would appear to be a PTR stored in the HEAP memory */
			/* as a result of an ALIAS of a REGISTER stored VALUE	 */
			/* ----------------------------------------------------- */
			sptr = (TcodeByteStack + freg[ source ] + (2*WORDSIZE));
#ifdef	ABAL64
			if ( PTRSIZE < ABALPTRSIZE )
			{
				if (((source = *sptr) > 3)
				/* --------------------------- */
				/* collect the logical address */
				/* --------------------------- */
				||  (!( logical_address = TcodeWord32((sptr+1)) ))
				/* ---------------------------- */
				/* collect the physical address */
				/* ---------------------------- */
				||  (!( sptr = TcodeGetPointer( sptr ) )) )
					source = 0;
			}
			else
#endif
			/* ---------------------------------------- */
			/* NOT ABAL64 or PTRSIZE is NATIVE PTR SIZE */
			/* ---------------------------------------- */
			if (((source = *sptr) > 3)
			||  (( sptr  = TcodeGetPointer( sptr )) == (BPTR) 0 ))
				source = 0;
			break;
		}

		else if ( xreg[ source ] == VARIABLE ) 
		{
			/* Evaluate Register Operand */
			/* ------------------------- */
			if ( argset1(4,source) == SOFTERROR )
				return( SOFTERROR );
			else	
			{
				sptr = workptr1;
				source = 3;
			}
			break;
		}

	default:/* Error ?? */
		err_val = 118;
		return( SOFTERROR );
	}

	/* ------------------ */
	/* Check for constant */
	/* ------------------ */
	if ( mode ==  1 ) 
	{
		/* -------------------------- */
		/* Calculate constant adresse */
		/* -------------------------- */
		sptr = (BPTR) (TcodeConstants + source);

		while (1) 
		{
			/* ------------------------- */ 
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

	/* -------------------- */
	/* Check for a Variable */
	/* -------------------- */
	else if ( mode == 2 ) 
	{

		/* ------------------------ */
		/* Resolve and Check Target */
		/* ------------------------ */
		if ( source & ISLOCAL ) 
		{
			sdesc = (LocalDataTable + (source & TOGLOBAL));
			sptr  = LocalDataSegment;
		}
		else
		{
			sdesc = (GlobalDataTable + source);
			sptr  = GlobalDataSegment;
		}

		/* ------------------------------------- */
		/* Check for Non Pointer Variable Source */
		/* ------------------------------------- */
		if ((!((vtype = (Tcodeword((sdesc)))) & ISDYNAMIC))
		||  (!( vtype & ISPOINTER ))) 
		{
			/* -------------------------------- */
			/* Evaluate as for normal arguments */
			/* -------------------------------- */
			if ( argset( 5, source, 1 ) == SOFTERROR )
				return( SOFTERROR );

			/* --------------------------------- */
			/* Establish Referencing information */
			/* --------------------------------- */
			mode = REFERENCED_POINTER;
			sptr = workptr1;
		}
		else	
		{

			sdesc += WORDSIZE;

			/* ----------------------------------------- */
			/* Allow evaluation of Redefinition pointers */
			/* ----------------------------------------- */
			if ( vtype & ISMEMBER ) 
			{

				/* ---------------------------------------- */
				/* Allow resoloution of this pointer member */
				/* ---------------------------------------- */
				if (( sptr = resolve_member((Tcodeword((sdesc))))) == (BPTR) 0) 
				{
					err_val = 118;
					return( SOFTERROR );
				}

				/* ------------------------------------ */
				/* Step over Member Variable Identifier */
				/* ------------------------------------ */
				sdesc += WORDSIZE;

			}

			/* ---------------------------------------- */
			/* Evaluate Storage Adresse of this pointer */
			/* ---------------------------------------- */
			sptr += Tcodeword((sdesc)); sdesc += WORDSIZE;

			/* --------------------------- */
			/* Collect actual pointer type */
			/* --------------------------- */
#ifdef	ABAL64
			if ( PTRSIZE < ABALPTRSIZE )
			{
				if (((mode = *sptr) > 3)
				/* --------------------------- */
				/* collect the logical address */
				/* --------------------------- */
				||  (!( logical_address = TcodeWord32((sptr+1)) ))
				/* ---------------------------- */
				/* Collect actual pointer value */
				/* ---------------------------- */
				|| ((sptr = TcodeGetPointer((sptr))) == (BPTR) 0))
					mode = 0;
			}
			else
#endif
			/* ----------------------------- */
			/* NOT ABAL 64 or NATIVE PTRSIZE */
			/* ----------------------------- */
			if (((mode = *sptr) > 3)
			|| ((sptr = TcodeGetPointer((sptr))) == (BPTR) 0))
				mode = 0;

		}
	}
	else	mode = source;

	/* --------------------------------------- */
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
	/* -------------------------------- */
	/* Disconect the target pointer now */
	/* -------------------------------- */
	forget_reference( tptr );

	/* ---------------------------------------- */
	/* Set up and store result pointer variable */
	/* ---------------------------------------- */
	if ( mode != 0 )
	{
#ifdef	ABAL64
		/* ----------------------------------------------------- */
		/* when the logical address is not zero its an index PTR */
		/* so it can be used "as is" with the same PTR mode flag */ 
		/* ----------------------------------------------------- */
		if ((!( logical_address )) && ( PTRSIZE < ABALPTRSIZE ))
		{
			/* ----------------------------------------------------- */
			/* when the logical address is ZERO it means it has not  */
			/* been resolved to a logical address which must be done */
			/* ----------------------------------------------------- */
			if (!( logical_address = SetIndexedPointer( sptr ) ))
			{
				err_val = 118;
				return( SOFTERROR );
			}
			else 
			{
				/* ----------------------------- */
				/* mark this as an indexed ALIAS */
				/* ----------------------------- */
				mode |= INDEXED_ALIAS;
			}
		}
		/* ------------------------------ */
		/* otherwise use the real address */
		/* ------------------------------ */
		else	logical_address = sptr;

		establish_pointer_variable( tptr, logical_address, mode );
#else
		/* ------------------------------------------------------------- */
		/* in ABAL 32 bit mode the pointer can be stored in PTR variable */
		/* ------------------------------------------------------------- */
		establish_pointer_variable( tptr, sptr, mode );
#endif
	}

	return( GOODRESULT );

}

/*	------------------	*/
/*	  register_alias	*/
/*	------------------	*/
EXAWORD	register_alias( registre, adesc )
EXAWORD	registre;
EXAWORD	adesc;
{
	BPTR	tptr;

	StackCheck( ((2*WORDSIZE)+PTRSIZE) );
	freg [ registre ] = worktop;	
	xreg [ registre ] = TEMPDESC;	
	tptr = (TcodeByteStack + worktop);	
	TcodePmot( tptr, VARB_STR);
	TcodePmot( (tptr + WORDSIZE),PTRSIZE );
	tptr += (2 * WORDSIZE);
	worktop += PTRSIZE+(2*WORDSIZE);
	*tptr = 0;
	return( establish_alias( tptr, adesc ) );
}

/*	-----------------	*/
/*	select_descriptor	*/
/*	-----------------	*/
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

/*	----------------------------------	*/
/*	  redimension_collect_descriptor	*/
/*	----------------------------------	*/
EXAWORD	redimension_collect_descriptor( dptr, type, adesc, bdesc )
BPTR	dptr;
EXAWORD	type;
EXAWORD	adesc;
EXAWORD	bdesc;
{
	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	return( GOODRESULT );

}

/*	--------------------------	*/
/*	  redimension_descriptor	*/
/*	--------------------------	*/
EXAWORD	redimension_descriptor( dptr, type, adesc, bdesc )
BPTR	dptr;
EXAWORD	type;
EXAWORD	adesc;
EXAWORD	bdesc;
{
	EXAWORD	mode;
	EXAWORD	desc;

	/* First may be length */
	if (( type & 3 ) > 1 )
	{
		ExFlgSgn = 1;
		if (argset(((adesc & 0x0006) >> 1),0,3) == SOFTERROR) 
		{
			ExFlgSgn = 0;
			return(SOFTERROR);
		}
		switch (worktyp3) 
		{
		case 4 :
		case 5 :
		case 0 :
		case 1 : break;
		case 2 : workval3 = bcdtoi(workptr3,worklen3);
			 break;
		case 3 : workval3 = atoi(workptr3,worklen3);
			 break;
		}
		ExFlgSgn = 0;
		TcodePmot( dptr, workval3 );
		dptr += WORDSIZE;
		mode = 1;
	}
	else	mode = 0;
	
	if (((desc = select_descriptor( mode++, adesc, bdesc )) & 1) == 0)
		return( GOODRESULT );

	if (!( type & NDX1st ))	 
		return( SOFTERROR );

	if (argset(((desc & 0x0006) >> 1),0,3) == SOFTERROR)
		return(SOFTERROR); 

	switch (worktyp3) 
	{
	case 4 :
	case 5 :
	case 0 :
	case 1 : break;
	case 2 : workval3 = bcdtoi(workptr3,worklen3);
		 break;
	case 3 : workval3 = atoi(workptr3,worklen3);
		 break;
	}
	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	if (((desc = select_descriptor( mode++, adesc, bdesc )) & 1) == 0)
		return( GOODRESULT );

	if (!( type & 0x0020 ))	 
		return( SOFTERROR );

	if (argset(((desc & 0x0006) >> 1),0,3) == SOFTERROR)
		return(SOFTERROR); 
	switch (worktyp3) 
	{
	case 4 :
	case 5 :
	case 0 :
	case 1 : break;
	case 2 : workval3 = bcdtoi(workptr3,worklen3); 
		 break;
	case 3 : workval3 = atoi(workptr3,worklen3);
		 break;
	}
	TcodePmot( dptr, workval3 );
	dptr += WORDSIZE;

	return( GOODRESULT );

}

#ifdef	ABAL64
/*	-------------------------------------------------	*/
/*	r e s o l v e _ p r o g r a m _ p r o c e d u r e	*/
/*	-------------------------------------------------	*/
/*	Resolves a Procedure Offset in the same Program.	*/
/*	-------------------------------------------------	*/
EXAWORD	resolve_program_procedure( BPTR memptr )
{
	EXAWORD	offset = TcodeWord32( (memptr+1) );
	BPTR	descptr = (TcodeContext->ipt + offset);
	EXAWORD thisproc = TcodeWord32((descptr+ABALPTRSIZE));
	return( thisproc );
}
#endif

#ifdef	ABAL_REMOTE
/*	------------------------	*/
/*	connect_remote_procedure	*/
/*	------------------------	*/
EXAWORD	connect_remote_procedure( attbase, argc, argdesc )
BPTR	attbase;
EXAWORD	argc;
BPTR	argdesc;
{
	OVLOBJPTR	thiscontext;
	EXAWORD		thisproc;
	EXAWORD		procid;

	if (!( attbase = (BPTR) TcodeGetPointer((attbase)) )) 
	{
		err_val = 118;
		return( MOINS_UN );
	}
	else if (!( thiscontext = (OVLOBJPTR) TcodeGetPointer((attbase)) )) 
	{
		err_val = 100;
		return( MOINS_UN );
	}
	else	attbase += PTRSIZE;
#ifdef	ABAL64
	if ( thiscontext->wordsize > 4 )
	{	thisproc = TcodeWord64((attbase));	}
	else
#endif
	if ( thiscontext->wordsize > 2 ) 
	{	thisproc = TcodeWord32((attbase));	}
	else	
	{	thisproc = TcodeWord16((attbase));	}
	
	procid = (thisproc / (8*WORDSIZE));

	return( call_remote_procedure( procid, thiscontext, argc, argdesc, &fdex ) );
}
#endif

/*	-------------------------	*/
/*	connect_program_procedure	*/
/*	-------------------------	*/
EXAWORD	connect_program_procedure( attbase )
BPTR	attbase;
{
	EXAWORD		thisproc;
#ifdef	DEBUGGER
	VOID	force_symbolic_attachment( OVLOBJPTR );
#endif
	if (!( attbase = (BPTR) TcodeGetPointer((attbase)) ))
	{
		err_val = 118;
		return( MOINS_UN );
	}
	else if (!( ProcContext = (OVLOBJPTR) TcodeGetPointer((attbase)) )) {
		err_val = 100;
		return( MOINS_UN );
		}
	else	attbase += PTRSIZE;
#ifdef	VERSION666
#ifdef	ABAL64
	if ( ProcContext->wordsize > 4 )
	{
		thisproc = TcodeWord64((attbase));
	}
	else
#endif
	if ( ProcContext->wordsize > 2 )
	{
		thisproc = TcodeWord32((attbase));
	}
	else
	{
		thisproc = TcodeWord16((attbase));
	}
#else
	thisproc = Tcodeword((attbase));
#endif
	special_procedure_push();

	TcodeContext      = ProcContext;
	FuseBase          = (struct fusework PTR)TcodeContext->libraries;
	FuseCount         = TcodeContext->nbdll;	
	TcodeProcTable    = (struct procform PTR)ProcContext->procedures;
	ExportTable	  = ProcContext->callbacks;
	if ((TcodeFileHandle   = ProcContext->handle) == EX_UNUSED_HANDLE)
	{
		ca_y_est();
		TcodeFileHandle = AssignTable[0].unlog;
	}
	procmaxid         = ProcContext->procmaxid;

#ifdef	DEBUGGER
	force_symbolic_attachment( ProcContext );
#endif

	return( thisproc );
}


#ifdef	DEBUGGER
/*	-----------------	*/
/*	get_procid_by_ptr	*/
/*	-----------------	*/
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
			attbase += PTRSIZE;
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

/*	--------------------	*/
/*	collect_indirect_gds	*/
/*	--------------------	*/
VOID	collect_indirect_gds()
{
	GlobalDataTable   = ProcContext->descriptors;
	GlobalDataSegment = ProcContext->variables;
	TcodeConstants 	  = GlobalConstants = ProcContext->constants;
	FuseBase 	  	  = (struct fusework PTR)ProcContext->libraries;
	FuseCount         = ProcContext->nbdll;	
	return;
}

/*	-------------------------	*/
/*	 release_overlay_context	*/
/*	-------------------------	*/
EXAWORD	release_overlay_context( context, oldhandle, result )
OVLOBJPTR	context;
EX_FILE_HANDLE	oldhandle;
EXAWORD		result;
{
	CloseTcodeFile( context->handle );
	if ((TcodeFileHandle = oldhandle) == EX_UNUSED_HANDLE) 
	{
		ca_y_est();
	}

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

#include "exattach.h"
#include "exattach.c"

/*	---------------------------------------------	*/
/*	A T T A C H _ I N D I R E C T _ P R O G R A M	*/
/*	---------------------------------------------	*/

EXAWORD	attach_indirect_program( result, adesc )
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
	if ( (worktyp2 & VARB_ISOL) == VARB_STR) 
	{
		StackCheck( (worklen2+1) );
		attnfic = (BPTR) (TcodeByteStack + worktop);
		for ( i = 0; worklen2 != 0; worklen2-- ) 
		{
			if ( *workptr2 <= ' ' )
				break;
			else	*(attnfic + (i++)) = *(workptr2++);
		}
		*(attnfic + (i++)) = 0;
		worktop += i;
	}
	else
	{
		/* Watch out for atr bug : BCD constant */
		/* ------------------------------------ */
		if ( (worktyp2 & VARB_ISOL) == VARB_BCD)
			workval2 = bcdtoi((BPTR) workptr2, worklen2 );

		/* Assign handle */
		/* ------------- */
		if ((attnfic = assigned_filename( workval2 )) == (BPTR) 0)
		{
			err_val = 116;
			return( SOFTERROR );
		}
	}

	if (!( TcodeOverlayName( askbuf, attnfic ) ))
	{
		err_val = 30;
		return( SOFTERROR );
	}
	else	attnfic = askbuf;

	return( overlay_object_attachment( attnfic, result ) );
}

#ifdef	VERSION_XX
/*	--------------------	*/
/*	finalise_indirection	*/
/*	--------------------	*/
VOID	finalise_indirection()
{
	if (!( ProcContext ))
		return;
	else if ((ISLOCAL = ProcContext->islocal) & ISLOCAL3)
	{
		TOGLOBAL = TOGLOBAL3;
#ifdef	VERSION666
#ifndef ABAL64
		WORDSIZE = WORD16SIZE;
#endif
#endif
	}
	else
	{
		TOGLOBAL = TOGLOBAL4;
#ifdef	VERSION666
#ifndef ABAL64
		WORDSIZE = WORD32SIZE;
#endif
#endif
	}
	return;
}

/*	-------------------	*/
/*	prepare_indirection	*/
/*	-------------------	*/
VOID	prepare_indirection()
{
	ProcContext = (OVLOBJPTR) 0;
	return;
}

#endif /* VERSION_XX */

/*	-------------------------	*/
/*	reset_indirection_control	*/
/*	-------------------------	*/
VOID	reset_indirection_control()
{
	TcodeContext = (OVLOBJPTR) 0;
	return;
}

/*	--------------------	*/
/*	trace_tcode_filename	*/
/*	--------------------	*/
BPTR	trace_tcode_filename()
{
	if (!( TcodeContext ))
		return((BPTR) 0);
	else	return( TcodeContext->filename );
}

/*	-----------------	*/
/*	SaveMasterContext	*/
/*	-----------------	*/
OVLOBJPTR	SaveMasterContext()
{
	OVLOBJPTR	optr;
	if ((optr = allocate( sizeof( OVLOBJ ) ) ) != (OVLOBJPTR) 0)
		memcpy(optr,&MasterContext,sizeof( OVLOBJ ));
	return(optr);
}

/*	--------------------	*/
/*	RestoreMasterContext	*/
/*	--------------------	*/
VOID		RestoreMasterContext(OVLOBJPTR optr)
{
	if ( optr != (OVLOBJPTR) 0)
	{
		memcpy(&MasterContext,optr,sizeof( OVLOBJ ));
		liberate( optr );
	}
	return;
}

/*	-----------------------------	*/
/*	establish_indirection_control	*/
/*	-----------------------------	*/
VOID		establish_indirection_control()
{
	if (!( TcodeContext->special )) 
	{
		if ((TcodeContext->handle = TcodeFileHandle) == EX_UNUSED_HANDLE) 
		{
			ca_y_est();
		}
		TcodeContext->filename    = AssignTable->direcp;
		TcodeContext->procmaxid   = procmaxid;
		TcodeContext->constants   = GlobalConstants; /* TcodeConstants;  */
		TcodeContext->variables   = GlobalDataSegment;
		TcodeContext->descriptors = GlobalDataTable;
		TcodeContext->procedures  = (BPTR) TcodeProcTable;
		TcodeContext->callbacks	  = (BPTR) ExportTable;
		TcodeContext->libraries   = FuseBase;
		TcodeContext->nbdll       = FuseCount;
		TcodeContext->master      = (VPTR) 0;
		TcodeContext->ipt         = (BPTR) 0;
#ifdef	VERSION_XX
		TcodeContext->islocal     = ISLOCAL;
#ifdef	VERSION666
		TcodeContext->wordsize    = WORDSIZE;
#endif
#endif
	}
	return;
}

/*	------------------------------	*/
/*	initialise_indirection_control	*/
/*	------------------------------	*/
VOID	initialise_indirection_control()
{
	TcodeContext = (OVLOBJPTR) & MasterContext;
	TcodeContext->special=0;
	establish_indirection_control();
	return;
}

/*	----------------------	*/
/*	identify_current_tcode	*/
/*	----------------------	*/
VOID	identify_current_tcode()
{
	ATTLOGPTR	attlog;
	if (( attlog = TcodeContext->master ) != (ATTLOGPTR) 0)
	{
		if ( attlog->filename != (BPTR) 0)
		{
			x_cprintf((BPTR) attlog->filename );
			x_newlyne();
		}
	}
	return;
}

/*	----------------------------	*/
/*	liberate_indirection_control	*/
/*	----------------------------	*/
VOID	liberate_indirection_control()
{
	if ((TcodeContext != (OVLOBJPTR) 0)
	&&  (TcodeContext->ipt != (BPTR) 0)) 
	{
		liberate( TcodeContext->ipt );
		TcodeContext->ipt = (BPTR) 0;
	}
	reset_indirection_control();
	return;
}

/*	------------------------	*/
/*	attach_procedure_pointer	*/
/*	------------------------	*/
EXAWORD	attach_procedure_pointer( BPTR result, EXAWORD procid )
{
	if (( TcodeContext->ipt == (BPTR) 0 )
	&&  ((TcodeContext->ipt = allocate_indirection_table( procmaxid,(BPTR) TcodeContext, WORDSIZE)) == (BPTR) 0))
	{
		err_val = 27;
		return( SOFTERROR );
	}
	else
	{
#ifdef	ABAL64
		if ( PTRSIZE < ABALPTRSIZE )
			establish_pointer_reference( result,((procid / (8*WORDSIZE)) * (WORDSIZE+ABALPTRSIZE)), PROGRAM_POINTER );
		else
#endif
			establish_pointer_variable( result,(BPTR) (TcodeContext->ipt + ((procid / (8*WORDSIZE)) * (WORDSIZE+ABALPTRSIZE))), PROGRAM_POINTER );
		return( GOODRESULT );
	}
}

/*	---------------------	*/
/*	allocated_object_size	*/
/*	---------------------	*/
EXAWORD	allocated_object_size( xptr )
BPTR	xptr;
{
	DYNOPTR	ldyn;

	/* Convert to control pointer */
	/* -------------------------- */
	ldyn = (DYNOPTR) (xptr - PREFIX_SIZE);

	return( ldyn->usage );

}

/*	------------------------	*/
/*	release_indirect_program	*/
/*	------------------------	*/
VOID	release_indirect_program( tptr )
BPTR	tptr;
{
	BPTR		pgmbase;
	BPTR		objbase;
	BPTR		prcbase;
	EXAWORD		objsize;

	/* Collect object base pointer */
	/* --------------------------- */
	if ((pgmbase = (TcodeGetPointer((tptr)))) != (BPTR) 0)
	{

		/* Collect and release OBJECT data storage area */
		/* -------------------------------------------- */
		if ((objbase = (TcodeGetPointer((pgmbase+PTRSIZE)))) != (BPTR) 0)
		{
			release_reference( (pgmbase+PTRSIZE) );
		}

		/* Collect OBJECT Method table pointer */
		/* ----------------------------------- */
		if ((objbase = (TcodeGetPointer(pgmbase))) != (BPTR) 0)
		{

			objsize = allocated_object_size( objbase );

			/* Release loaded procedures */
			/* ------------------------- */
			if ((prcbase = (TcodeGetPointer((objbase)))) != (BPTR) 0)
				/* This is the IPT */
				/* --------------- */
				release_attachment_log_entry( prcbase );

			release_reference( pgmbase );
		}

		/* Release OBJECT base */
		/* ------------------- */
		release_reference( tptr );
	}

	TcodeRazPointer( tptr );

	return;
}

/*	------------------------	*/
/*	allocate_collect_storage	*/
/*	------------------------	*/
BPTR	allocate_collect_storage( target, iwidth, rcount )
EXAWORD	target;
EXAWORD	iwidth;
EXAWORD	rcount;
{

	EXAWORD	adesc;		/* Arguament Descriptor		*/
	EXAWORD	bdesc=0;
	BPTR	xdesc;		/* Storage descriptor		*/
	BPTR	tdesc;		/* Descriptor Pointer		*/
	BPTR	tptr;		/* Memory Storage Pointer	*/
	EXAWORD	xtarget=target;	/* Copy of Variable identity	*/
	BPTR	result;		/* Allocation result pointer	*/
	EXAWORD	registre;
	BPTR	resolve_member(EXAWORD);
	EXAWORD	local_error;

	/* ----------------------------------------- */
	/* Establish storage adresse of this pointer */
	/* ----------------------------------------- */
	/* Resolve and Check Target */
	/* ------------------------ */
	if ( target & ISLOCAL )
	{
		tdesc = (LocalDataTable + (target & TOGLOBAL));
		tptr  = LocalDataSegment;
	}
	else
	{
		tdesc = (GlobalDataTable + target);
		tptr  = GlobalDataSegment;
	}

	if (!((target = (Tcodeword((tdesc)))) & ISDYNAMIC))
	{
		err_val = 118;
		return((BPTR) 0);
	}

	tdesc += WORDSIZE;

	if ( target & ISETENDU )
	{
		err_val = 56;
		return((BPTR) 0);
	}

	/* Allow evaluation of Redefinition pointers */
	/* ----------------------------------------- */
	if ( target & ISMEMBER )
	{

		/* Ensure this is a pointer type */
		/* ----------------------------- */
		if (!(target  & ISPOINTER))
		{
			err_val = 118;
			return((BPTR) 0);
		}

		/* Resolve the area pointed to by member indirection */
		/* ------------------------------------------------- */
		if (( tptr = resolve_member((Tcodeword((tdesc))))) == (BPTR) 0)
		{
			err_val = 118;
			return((BPTR) 0);
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
	xdesc = tdesc;
	TcodePmot( xdesc, iwidth );
	xdesc += WORDSIZE;

	TcodePmot( xdesc, rcount );
	xdesc += WORDSIZE;

	forget_reference( tptr );

	/* Attempt to allocate for Specified Type */
	/* -------------------------------------- */
	if (( result = allocate_dynamic_object( tdesc, target, xtarget )) == (BPTR) 0)
	{
		err_val = 27;
		return( result );
	}
	else
	{
		/* Create Referenced Object */
		/* ------------------------ */
		establish_pointer_variable( tptr, result, ALLOCATED_POINTER );

		/* Indicate success */
		/* ---------------- */
		return( result  );					
	}
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
 *		ATTACH  <pointer_variable> <string>	tcCLF  x46
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
	EXAWORD	local_error;

	/* Ensure First Arguament is correct ie a VARIABLE type POINTER */
	/* ------------------------------------------------------------ */
	if (((adesc = (EXAWORD) *(fdex++)) & 0x0060) == 0x0060)
	{
		if ( opcode != 3 )
		{
			err_val = 115;
			return( SOFTERROR );
		}
		return( register_alias( *(fdex++), adesc ) );
	}
	else
	{
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
	if ( target & ISLOCAL )
	{
		tdesc = (LocalDataTable + (target & TOGLOBAL));
		tptr  = LocalDataSegment;
	}
	else
	{
		tdesc = (GlobalDataTable + target);
		tptr  = GlobalDataSegment;
	}

	if (!((target = (Tcodeword((tdesc)))) & ISDYNAMIC))
	{
		err_val = 118;
		return( SOFTERROR );
	}

	tdesc += WORDSIZE;

	if ( target & ISETENDU )
	{
		err_val = 56;
		return( SOFTERROR );
	}

	/* Allow evaluation of Redefinition pointers */
	/* ----------------------------------------- */
	if ( target & ISMEMBER )
	{
		/* Ensure this is a pointer type */
		/* ----------------------------- */
		if (!(target  & ISPOINTER))
		{
			if ( opcode != 6 )
			{
				err_val = 118;
				return( SOFTERROR );
			}
			else	return( redimension_descriptor( (tdesc+WORDSIZE), target, adesc, bdesc ) );
		}

		/* Resolve the area pointed to by member indirection */
		/* ------------------------------------------------- */
		if (( tptr = resolve_member((Tcodeword((tdesc))))) == (BPTR) 0)
		{
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
	switch ( opcode )
	{
	case 0 	:	
		/* Ensure Pointer devalidated */
		/* -------------------------- */
		forget_reference( tptr );

		/* Attempt to allocate for Specified Type */
		/* -------------------------------------- */
		if (( result = allocate_dynamic_object( tdesc, target, xtarget )) == (BPTR) 0)
			break;

		if ( TcodeTraceControl ) { fprintf(stderr,"CREATE %lu \n",result); }

		/* Create Referenced Object */
		/* ------------------------ */
		if ( PTRSIZE < ABALPTRSIZE )
		{ establish_pointer_variable( tptr, GetSymbolicPointer(result), ALLOCATED_POINTER ); }
		else
		{ establish_pointer_variable( tptr, result, ALLOCATED_POINTER ); }

		/* Indicate success */
		/* ---------------- */
		return( GOODRESULT );					

	case 1 	:
		/* Delete Referenced Object */
		/* ------------------------ */
		release_reference( tptr );
		return( GOODRESULT );

	case 2	:	
		/* Delete Referenced Object */
		/* ------------------------ */
		forget_reference( tptr );
		return( GOODRESULT );

	case 3  :
		/* Create ALIAS/REFERENCE */
		/* ---------------------- */
		return( establish_alias( tptr, adesc ) );

	case 4  :
		/* Connect : filename	    */
		/* ------------------       */
		if ((result = dynamic_object_allocation( PTRSIZE * 2 )) == (BPTR) 0)
			return( SOFTERROR );

		/* Create Allocated  Object */
		/* ------------------------ */
		if ( PTRSIZE < ABALPTRSIZE )
		{ establish_pointer_variable( tptr, GetSymbolicPointer(result), ALLOCATED_POINTER ); }
		else
		{ establish_pointer_variable( tptr, result, ALLOCATED_POINTER ); }

		if (attach_indirect_program( result, adesc ) == SOFTERROR)
		{
			local_error = err_val;
			release_reference( tptr );
			if (( err_val = local_error) == 0 )
				err_val = 136;
			return( SOFTERROR );
		}
		else	return( GOODRESULT );
				
	case 5  :
		/* Release */
		/* ------- */
		release_indirect_program( tptr );
		return( GOODRESULT );
	

	case 6  :
		/* Alter */
		/* ----- */
		return( GOODRESULT );

	
	default :
		/* Unknown function codes   */
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

