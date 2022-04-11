/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOREG.C					*/
/*		Version :	1.4a / 2.1b 				*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_REGISTER_C
#define	_REGISTER_C

#define	OPTIMISEUR

#include "aomain.h"
#include "aotcode.h"
#include "aotcngf.h"
#include "aotcesc.h"
#include "aotclen.h"
#include "aoreg.h"

EXAWORD		Redundants;
EXTERN	EXAWORD	canliste;			
SHADOWPTR	General[ _DIEZ_REGS ];

SHADOWPTR	Primary[ _DIEZ_REGS ];

SHADOWPTR	Secondary[ _DIEZ_REGS ];

SHADOWPTR	RegisterHeap;
OPERANDPTR	OperandHeap;

EXAWORD		TopRegister;
EXAWORD		BasePointer;
EXAWORD		NewLineAdresse;
EXAWORD		ForNextFlag;

EXAWORD		Redirection[ _DIEZ_REGS ];
EXAWORD		IdxRedirect[ _DIEZ_REGS ];

EXAWORD		UsedRegisters;
EXAWORD		UsedOperands;

extern	BPTR	tcCS;

/*
 *	The above three tables will contain the current condition of
 *	each of the registers in the virtual machine. They will be set
 *	to unused by a NULL REGISTER PTR at initialisation. The default
 *	structures will be allocated as required to provide register
 *	storage, however to optimise memory usage the allocated register
 *	structure will not be liberated until the call to terminate
 *	register shadowing. Each register structure allocated will be
 *	kept and reset internaly to zero at each reset shadower call.
 *
 *	They will be reset to ZERO (NUL) pointers by the initialisation
 *	function.
 *
 *	They will be liberated by the new line liberation function
 *	and consequently zeroed.
 */

/*
 *	Allocation and initialisation of a structure for a shadow
 *	register operand.
 */

void		reset_operand( loperand )
OPERANDPTR	loperand;
{
	loperand->type     = 0xFFFF;
	loperand->registre = 0;
	loperand->constant = 0;
	loperand->variable = 0;
	loperand->integer  = 0;
	loperand->next     = (OPERANDPTR) 0;
	return;

}

OPERANDPTR	allocate_for_operand()
{
	OPERANDPTR	loperand;

	if ((loperand = OperandHeap) != (OPERANDPTR) 0 )
		OperandHeap = OperandHeap->next;
	else	{
		if ((loperand = (OPERANDPTR) malloc( sizeof( struct register_operand ) )) == (OPERANDPTR) 0)
			return( loperand );
		else	{
			UsedOperands++;
#ifdef	DEBUG
			oputs((BPTR) " allocation_of_operand( ");
			HexAdresse( UsedOperands );
			oputs((BPTR) " )\n");
#endif
			}
		}
	reset_operand( loperand );

	return( loperand );

}

/*
 *	Resets the contents of a shadow register structure
 */

void	reset_register( xshadow )
SHADOWPTR	xshadow;
{
	xshadow->current_type	= 0;
	xshadow->operation_type = 0;
	xshadow->tcode_offset   = 0xFFFF;
	xshadow->register_link  = 0;
	xshadow->parent		= (SHADOWPTR) 0;
	xshadow->previous	= (SHADOWPTR) 0;
	xshadow->operand	= (OPERANDPTR) 0;
	return;
}

/*
 *	Allocates and initialises a shadow register structure
 */

SHADOWPTR	allocate_for_register()
{
	SHADOWPTR	lshadow;

	if (( lshadow = RegisterHeap ) != (SHADOWPTR) 0)
		RegisterHeap = RegisterHeap->parent;
	else	{
		if ((lshadow = (SHADOWPTR) malloc( sizeof( struct shadow_register ) )) == (SHADOWPTR) 0)
			return( lshadow );
		else	{
			UsedRegisters++;
#ifdef	DEBUG
			oputs((BPTR) " allocation_of_register( ");
			HexAdresse( UsedRegisters );
			oputs((BPTR) " )\n");
#endif
			}
		}
	reset_register( lshadow );
	return( lshadow );

}

/*
 *	-----------------------------------------
 *	I N I T I A L I S E _ S H A D O W E R ( )
 *	-----------------------------------------
 *
 *	Performs the initialisation of the register shadowing mechanism.
 *	Must be called prior to register optimisation.
 *
 */
void	establish_top_register( nreg )
EXAWORD	nreg;
{
	if ( nreg > TopRegister )
		TopRegister = nreg;
	return;
}


void	initialise_shadower()
{
	EXAWORD	i;

	for ( i =0; i < _DIEZ_REGS; i++ ) {
		General[i]   = (SHADOWPTR) 0;
		Primary[i]   = (SHADOWPTR) 0;
		Secondary[i] = (SHADOWPTR) 0;
		Redirection[i] = 0;
		IdxRedirect[i] = 0;
		}

	RegisterHeap = (SHADOWPTR) 0;
	OperandHeap  = (OPERANDPTR) 0;

	NewLineAdresse = 0xFFFF;
	BasePointer    = 0; 
	TopRegister    = 0;
	ForNextFlag    = 0;
	UsedOperands   = 0;
	UsedRegisters  = 0;
	Redundants     = 0;
	return;
}


/*
 *	Removes the operand list and resets all internal values
 *	to restore the register to an UNUSED state
 */
void	remove_register( regptr )
SHADOWPTR	regptr;
{
	regptr->parent = RegisterHeap;
	RegisterHeap   = regptr;
	return;
}


SHADOWPTR	copy_register( source )
SHADOWPTR	source;
{
	SHADOWPTR	target;

	if ((target = allocate_for_register()) != (SHADOWPTR) 0) {
		target->current_type	= source->current_type;
		target->operation_type  = source->operation_type;
		target->tcode_offset    = source->tcode_offset;
		target->register_link   = source->register_link;
		target->parent		= source->parent;
		target->previous	= source->previous;
		target->operand		= source->operand;
		}
	return( target );
}

void	duplicate_for_ldr( target, source )
SHADOWPTR	target;
EXAWORD		source;
{
	if (( General[ source ] != (SHADOWPTR) 0)
	&&  ((target->previous = copy_register( General[ source ] )) != (SHADOWPTR) 0))
		reset_register( General[ source ] );	
	return;
}

void	remove_operand( optr )
OPERANDPTR	optr;
{
	optr->next  = OperandHeap;
	OperandHeap = optr;
	return;
}

void	liberate_register( regptr )
SHADOWPTR	regptr;
{
	OPERANDPTR	loperand;

	if ( regptr->parent != (SHADOWPTR) 0) {
		liberate_register( regptr->parent );
		remove_register( regptr->parent );
		regptr->parent = (SHADOWPTR) 0;
		}

	if ( regptr->previous != (SHADOWPTR) 0) {
		liberate_register( regptr->previous );
		remove_register( regptr->previous );
		regptr->previous = (SHADOWPTR) 0;
		}

	while (( loperand = regptr->operand ) != (OPERANDPTR) 0 ) {

		regptr->operand = regptr->operand->next;
		remove_operand( loperand );

		}
	reset_register( regptr );
}

/*
 * 	Called by the NEW LINE detection mechanism to reset all
 *	register shadowing information without liberating any
 *	register structures
 *
 */

EXAWORD	reset_shadower(sptr, newline_adresse )
BPTR	sptr;
EXAWORD	newline_adresse;
{
	EXAWORD	i;

	/* Liberate all register contents */
	/* ------------------------------ */
#ifdef	DEBUG
	oputs((BPTR) " reset_shadower( ");
	HexAdresse( TopRegister );
	oputs((BPTR) " )\n");
#endif

	for ( i =0; i <= TopRegister; i++ ) {
		Redirection[i] = 0;
		IdxRedirect[i] = 0;
		if (General[i]   != (SHADOWPTR) 0)
			liberate_register(General[i]);
		if (Primary[i]   != (SHADOWPTR) 0)
			liberate_register(Primary[i]);
		if (Secondary[i] != (SHADOWPTR) 0)
			liberate_register(Secondary[i]);

		}

	BasePointer = 0; 
	TopRegister = 0;
	ForNextFlag = 0;

	/* Attempt to Perform Further Optimisation */
	/* --------------------------------------- */
	if ( NewLineAdresse != 0xFFFF ) {

		}

	/* Return Current Result Index to Caller */
	/* ------------------------------------- */
	return((NewLineAdresse = newline_adresse));
}

/*
 *	---------------------------------------
 *	T E R M I N A T E _ S H A D O W E R ( )
 *	---------------------------------------
 *
 *	Call to liberate the register shadowing mechanism
 *	at the end of the optimisation cycle 
 *
 */

void	terminate_shadower()
{
	EXAWORD		i;
	SHADOWPTR	rptr;
	OPERANDPTR	optr;


	/* Liberate all register structures */
	/* -------------------------------- */
	for ( i =0; i < _DIEZ_REGS; i++ ) {
		if (General[i]   != (SHADOWPTR) 0) {
			liberate_register(General[i]);
			remove_register( General[i] );
			}
		if (Primary[i]   != (SHADOWPTR) 0) {
			liberate_register(Primary[i]);
			remove_register( Primary[i] );
			}
		if (Secondary[i] != (SHADOWPTR) 0) {
			liberate_register(Secondary[i]);
			remove_register( Secondary[i] );
			}
		}

#ifdef	AO_STATS
	if ( Options.Stats ) {
		LineFeed(); oputs((BPTR) " Maximum number Registres   : ");
		HexAdresse( UsedRegisters );
		}
#endif

	while (( rptr = RegisterHeap ) != (SHADOWPTR) 0 ) {
		RegisterHeap = RegisterHeap->parent;
		free( rptr );
		UsedRegisters--;
		}

#ifdef	AO_STATS
	if ( Options.Stats ) {
		LineFeed(); oputs((BPTR) " Maximum number of operands : ");
		HexAdresse( UsedOperands  );
		}
#endif

	while (( optr = OperandHeap ) != (OPERANDPTR) 0 ) {
		OperandHeap = OperandHeap->next;
		free( optr );
		UsedOperands--;
		}

	/* Perform Re-Initialisation after Termination */
	/* ------------------------------------------- */
	initialise_shadower();

	return;

}


void	convert_register( tcptr )
BPTR	tcptr;
{
	EXAWORD	lregister;

	/* References to Register Zero are ignored */
	/* --------------------------------------- */
	if (( lregister = (EXAWORD) *tcptr ) != 0 ) {

		if ( Redirection[ lregister ] ) 
			lregister = (BYTE) Redirection[ lregister ];
	
		/* Check for register Used */
		/* ----------------------- */
		if ( General[ lregister ] != (SHADOWPTR) 0 )


			/* Check for a redirected register reference */
			/* ----------------------------------------- */
			while ( (General[ lregister ])->current_type & _REG_REDIRECTED )

				/* Patch new register identity */
				/* --------------------------- */
				lregister = (BYTE) (General[ lregister ])->register_link;

		}
#ifdef	DEBUG
	if ( Options.Verbose )
		if ( *tcptr != lregister ) {
			Hexadresse( lregister );
			oputs((BPTR) " <=== " );
			Hexadresse( (*tcptr) );
			LineFeed();
			}
#endif
	*tcptr = (BYTE) lregister;

	return;
}

SHADOWPTR	next_free_register( tcregister )
BPTR	tcregister;
{
	EXAWORD	xregister;

	for ( xregister = (BasePointer +1); xregister < _DIEZ_REGS; xregister++ ) {
		if ( General[ xregister ] == (SHADOWPTR) 0 ) {
			if ((General[ xregister ] = allocate_for_register()) != (SHADOWPTR) 0) {
				Redirection[ *tcregister ] = xregister;
				*tcregister = (BYTE) xregister;
				}
			establish_top_register( xregister );
			return( General[ xregister ] );
			}
		if ( (General[ xregister ])->current_type & (_REG_OCCUPIED | _REG_REDIRECTED))
			continue;

		Redirection[ *tcregister ] = xregister;
#ifdef	DEBUG
		if ( Options.Verbose )
			if ( *tcregister != xregister ) {
				HexAdresse( *tcregister );
				oputs((BPTR) " ==> ");
				HexAdresse( xregister );
				LineFeed();
				}
#endif
		*tcregister = (BYTE) xregister;
		establish_top_register( xregister );
		return( General[ xregister ] );

		}

	/* No more free registers */
	/* ---------------------- */
	return((SHADOWPTR) 0);
}

SHADOWPTR	collect_register( xregister )
BPTR	xregister;
{
	if ( BasePointer == 0 )
		BasePointer = *xregister;

	if ( General[ *xregister ] == (SHADOWPTR) 0 ) {

		establish_top_register( *xregister );

		return( (General[ *xregister ] = allocate_for_register()) );
		}

	if ( (General[ *xregister ])->current_type & (_REG_OCCUPIED | _REG_REDIRECTED))
		return( next_free_register( xregister ) );

	establish_top_register( *xregister );
	return( General[ *xregister ] );
}

SHADOWPTR	collect_vpt_register( xregister )
BPTR	xregister;
{
	EXAWORD	original;
	if ( IdxRedirect[(original = *xregister)] ) {
		*xregister = IdxRedirect[ original ];
		return( General[ *xregister ] );
		}
	else	return( collect_register( xregister ) );

}

SHADOWPTR	collect_index_register( xregister )
BPTR	xregister;
{
	EXAWORD		original;
	SHADOWPTR	registre;

	if ( BasePointer == 0 )
		BasePointer = *xregister;

	/* Check for already loaded by an Indexing Expression */
	/* -------------------------------------------------- */
	if ( IdxRedirect[(original = *xregister)] ) {
		*xregister = IdxRedirect[ original ];
		return( General[ original ] );
		}

	/* Check for Currently allocated Register */
	/* -------------------------------------- */
	if ( General[ original ] == (SHADOWPTR) 0 ) {

		IdxRedirect[ original ] = original;
		establish_top_register( *xregister );
		return( (General[ *xregister ] = allocate_for_register()) );
		}

	/* Check if register currently used */
	/* -------------------------------- */
	if ( (General[ *xregister ])->current_type & (_REG_OCCUPIED | _REG_REDIRECTED)) {
		if ((registre = next_free_register( xregister )) != (SHADOWPTR) 0)
			IdxRedirect[ original ] = *xregister;
		return( registre );
		}

	IdxRedirect[ original ] = original;
	establish_top_register( *xregister );
	return( General[ *xregister ] );
}

OPERANDPTR	create_operand( type , valeur )
EXAWORD	type;
EXAWORD	valeur;
{
	OPERANDPTR	loperand;

	if ((loperand = allocate_for_operand()) != (OPERANDPTR) 0 ) {

		switch ( type ) {

			case _REG_INTEGER  : loperand->integer  = valeur; break;
			case _REG_CONSTANT : loperand->constant = valeur; break;
			case _REG_VARIABLE : 
			case _REG_VARPTR   : loperand->variable = valeur; break;
			case _REG_REGISTER : loperand->registre = valeur; break;

			}

		loperand->type = type;

		}
	return( loperand );
}

EXAWORD	compare_operands( xop , yop )
OPERANDPTR	xop;
OPERANDPTR	yop;
{
	if ((xop ->type != yop->type ))
		return( FAUX );
	
	switch ( xop->type ) {

		case _REG_INTEGER  : 

			if ( xop->integer != yop->integer )
				return( FAUX );
			break;

		case _REG_CONSTANT :
			if ( xop->constant != yop->constant )
				return( FAUX );
			break;
		case _REG_VARIABLE :
		case _REG_VARPTR   :
			if ( xop->variable != yop->variable )
				return( FAUX );
			break;
		case _REG_REGISTER :
			if ( xop->registre != yop->registre )
				return( FAUX );
			break;

		}
	return( VRAI );

}

EXAWORD	verify_operands( xoperand , yoperand )
OPERANDPTR	xoperand;
OPERANDPTR	yoperand;
{
	while ((xoperand != (OPERANDPTR) 0 ) && (yoperand != (OPERANDPTR) 0)) {

		if ( compare_operands( xoperand , yoperand ) == FAUX )
			return( FAUX );

		xoperand = xoperand->next;
		yoperand = yoperand->next;

		}

	if (( xoperand == (OPERANDPTR) 0 ) && ( yoperand == (OPERANDPTR) 0))
		return( VRAI );
	else
		return( FAUX );
}

EXAWORD	verify_register( xregister , yregister )
SHADOWPTR	xregister;
SHADOWPTR	yregister;
{
	if ( xregister->operation_type != yregister->operation_type )
		return( FAUX );

	if ( verify_operands( xregister->operand, yregister->operand ) == FAUX )
		return( FAUX );

	return( VRAI );
}


EXAWORD	compare_registers( xreg , yreg )
EXAWORD	xreg;
EXAWORD	yreg;
{
	SHADOWPTR	xregister;
	SHADOWPTR	yregister;

 	xregister = General[ xreg ];
	yregister = General[ yreg ];
	while ( 1 ) {
		if (( xregister->current_type & _REG_MODIFIED ) != ( yregister->current_type & _REG_MODIFIED )) 
			return( FAUX );

		if ( verify_register( xregister, yregister ) == FAUX )
			return( FAUX );

		if (!( xregister->current_type & _REG_MODIFIED ))
			break;
		xregister = xregister->parent;
		yregister = yregister->parent;
		}

	if (( xregister->current_type & _REG_DIMENSIONED ) || ( yregister->current_type & _REG_DIMENSIONED )) {

		if (( xregister->current_type & _REG_DIMENSIONED ) != ( yregister->current_type & _REG_DIMENSIONED ))
			return( FAUX );
	
		if ( xregister->current_type & _REG_PRIMARY )
			if ( verify_register( Primary[xreg] , Primary[yreg] ) == FAUX )
				return( FAUX );

		if ( xregister->current_type & _REG_SECONDARY )
			if ( verify_register( Secondary[xreg] , Secondary[yreg] ) == FAUX )
				return( FAUX );

		}

	return( VRAI );

}
void	restitution( tcptr )
BPTR	tcptr;
{
#ifdef	AO_INTERNE
	if (( Options.Verbose ) && (canliste))
		(void) TcodeList( tcCS,(EXAWORD) (tcptr - tcCS) , 0x4000 );
#endif
	Redundants--;
	return;
}

void	information( tcptr )
BPTR	tcptr;
{
	if ( *tcptr != _tc_NOP ) {
#ifdef	AO_INTERNE
		if (( Options.Verbose ) && ( canliste ))
			(void) TcodeList( tcCS,(EXAWORD) (tcptr - tcCS) , 0x8000 );
#endif
		if ( Options.Pannel )
			draw_optimisations( 1 );

		Redundants++;
		}
	return;
}

void	redundancy_information()
{
	oputs((BPTR) "  Redundant Tcode Sequence Count : ");
	DecimalWord( Redundants ); LineFeed();
	return;
}

void	remove_possible_index(tcptr, registre , status )
BPTR	tcptr;
EXAWORD	registre;
WPTR	status;
{
	SHADOWPTR	xregister;
	EXAWORD		ancestor;

	/* Collect Register or ancestor */
	/* ---------------------------- */
	xregister = General[registre];
	ancestor  = 0;

	while ( xregister->current_type & _REG_MODIFIED ) {
		xregister = xregister->parent;
		ancestor++;
		}

	switch (((General[registre])->current_type & _REG_DIMENSIONED )) {

		case _REG_PRIMARY     : *status = (Primary[registre])->tcode_offset;
					information( (tcptr + (*status)) );
					break;

		case _REG_DIMENSIONED : *status = ( ((Primary[registre])->tcode_offset < (Secondary[registre])->tcode_offset ) ? (Primary[registre])->tcode_offset : (Secondary[registre])->tcode_offset );
					information( (tcptr + *status) );
					information( (tcptr + (*status) + 4 ) );
					break;

		default		      : if ( ancestor != 0 ) {
						*status = xregister->tcode_offset;
						information( (tcptr + (*status) ) );
						}
		}		

	return;
}

EXAWORD	redundancy_check( tcptr , registre, status )
BPTR		tcptr;
EXAWORD		registre;
WPTR		status;
{
	EXAWORD	i;

	/* Scan register table */
	/* ------------------- */
	for ( i = 0; i < TopRegister; i++ ) 

		/* If not this register */
		/* -------------------- */
		if ( i != registre )

			/* Test for valid used register */
			/* ---------------------------- */
			if (( General[i] != (SHADOWPTR) 0 ) && ( (General[i])->current_type & _REG_OCCUPIED )) 

				/* Test for Registers are identical */
				/* -------------------------------- */
				if ( compare_registers( i , registre ) == VRAI ) {

					/* Check for Indexing to be removed */
					/* -------------------------------- */
					remove_possible_index(tcptr, registre , status );
		
					/* Remove this registers contents */
					/* ------------------------------ */
					liberate_register( General[registre] );

					/* And perform redirection to previous register */
					/* -------------------------------------------- */
					(General[registre])->current_type  = _REG_REDIRECTED;
					(General[registre])->register_link = i;
#ifdef	DEBUG
					if ( Options.Verbose ) {
						HexAdresse( registre );
						oputs((BPTR) " **> ");
						HexAdresse( i );
						LineFeed();
						}
#endif
					return( VRAI );

					}


	return( FAUX );
}


void	remove_expression( tcptr , longueur )
BPTR	tcptr;
EXAWORD	longueur;
{
	information( tcptr );

	while ( longueur > 0 ) {
		*(tcptr++) = (BYTE) _tc_NOP;
		longueur--;
		}
	return;
}

EXAWORD	terminal_element_present( type, valeur )
EXAWORD	type;
EXAWORD	valeur;
{
	EXAWORD	r;
	EXAWORD	d;
	EXAWORD	tc;

	/* Scan Currently used registers */
	/* ----------------------------- */
	for ( r = 0; r <= TopRegister; r++ )

		/* If Register is Active */
		/* --------------------- */
		if ( General[r] != (SHADOWPTR) 0 )

			/* Register is a Terminal Element */
			/* ------------------------------ */
			if ( General[r]->current_type == _REG_OCCUPIED )

				/* Detect Expression which loaded this register */
				/* -------------------------------------------- */
				switch ( (tc = (General[r]->operation_type & 0x007F)) ) {

					case _tc_LDV :
					case _tc_VPT : 	if ( type == General[r]->operand->type ) 

								if ( valeur == General[r]->operand->variable )

									/* SUCCESS */
									/* ------- */
									return( r );

							break;

					case _tc_GIL :
					case _tc_GCL :  if ( type == General[r]->operand->type ) {

								/* Eliminate Local Variables */
								/* ------------------------- */
								if ( valeur & 0x8000 )
									break;

								/* Collect Variable Descriptor */
								/* --------------------------- */
								d = (Descriptor( valeur ) & 0x7F7F);

								/* Ensure Correct variable types */
								/* ----------------------------- */
								if ( ((d == 0) && ( tc == _tc_GCL )) 
								||   ((d == 1) && ( tc == _tc_GIL ))) {

									/* Ensure Exact Same Memory Adresse */
									/* -------------------------------- */
									if ( General[r]->operand->variable == AdresseVarb( valeur ) )

										/* SUCCESS */
										/* ------- */
										return( r );

									}
								}
							break;

					case _tc_LIL :
					case _tc_LCL :	if ( type == General[r]->operand->type ) {

								/* Eliminate Global Variables */
								/* -------------------------- */
								if (!( valeur & 0x8000 ))
									break;

								/* Collect Variable Descriptor */
								/* --------------------------- */
								d = (Descriptor( valeur ) & 0x7F7F);

								/* Ensure Correct variable types */
								/* ----------------------------- */
								if ( ((d == 0) && ( tc == _tc_LCL )) 
								||   ((d == 1) && ( tc == _tc_LIL ))) {

									/* Ensure Exact Same Memory Adresse */
									/* -------------------------------- */
									if ( General[r]->operand->variable == AdresseVarb( valeur ) )

										/* SUCCESS */
										/* ------- */
										return( r );

									}
								}
							break;
									
					case _tc_LDC : 	if ( type != General[r]->operand->type )
								break;

							if ( valeur != General[r]->operand->constant )
								break;

							/* SUCCESS */
							/* ------- */
							return( r );
			
					}

	/* Indicate Not Present */
	/* -------------------- */
	return( MOINS_UN );

}

void	compact_parameters( aptr, vptr, mode )
BPTR	aptr;
BPTR	vptr;
EXAWORD	mode;
{
	EXAWORD	v;

	while ( 1 ) {
		if ( mode ) {
			if (!( *aptr & 0x0010 ))
				break;
			if (( *aptr & 0x0006 ) == 0x0006 ) {
				*vptr = *(vptr+1);
				vptr++;
				}
			else	{
				v = tcGetw( (vptr + 1) );
				tcPutw((vptr),v);
				vptr += 2;
				}
			mode = 0;
			}
		else	{
			if (!(*aptr & 0x0001))
				break;
			aptr++;
			if (( *aptr & 0x0060 ) == 0x0060 ) {	
				*vptr = *(vptr+1);
				vptr++;
				}
			else	{
				v = tcGetw( (vptr + 1) );
				tcPutw((vptr),v);
				vptr += 2;
				}
		
			mode = 1;
			}
		}

	*vptr = _tc_NOP;
	return;

}


BPTR	register_conversion( aptr, vptr, type, mode )
BPTR	aptr;
BPTR	vptr;
EXAWORD	type;
EXAWORD	mode;
{
	EXAWORD	r;

	if ((r = terminal_element_present(type,(tcGetw(vptr)))) != MOINS_UN) {
		if ( mode )
			*aptr = ((*aptr & 0x001F) | 0x0060);
		else	*aptr = ((*aptr & 0x00F1) | 0x0006);
		*(vptr++) = r;
		compact_parameters(aptr,vptr,mode);
		}
	else	vptr += 2;
	return( vptr );
}

/*
 *	Source register linkage for functions CLF, IOF, NGF, CLP, LDF
 *	-------------------------------------------------------------
 *
 */


void	clf_sourcing( sptr )
BPTR	sptr;
{
	BPTR	aptr;
	BPTR	vptr;
	EXAWORD	x;
	EXAWORD	f;
	EXAWORD	r;
	EXAWORD	format;

	/* Attention : CLF GROUP 7 Has No Target */
	/* ------------------------------------- */
	if (( *sptr & 0x000F ) ==  0x0007 )
		f = 1;
	else	f = 0;

	/* Separate Format Codes */
	/* --------------------- */
	switch ( *sptr ) {
		case 0x005A 	: 
		case 0x006A 	: 
		case 0x007A 	: return;
		}


	/* Prepare Arg Value pointer */
	/* ------------------------- */
	aptr = (sptr + 1); vptr = aptr;

	while (( *(vptr++) & 1 ));

	do	{

		/* Determine 1st Arguament Type */
		/* ---------------------------- */
		switch (((x = *aptr) & 0x0060)) {

			case 0x0060 :	if ( f )
						convert_register( vptr );
					vptr++;
					break;

			case 0x0020 :	vptr = register_conversion( aptr, vptr, _REG_CONSTANT, 1);
					break;

			case 0x0040 :	if ( f )
						vptr = register_conversion( aptr, vptr, _REG_VARIABLE, 1);
					else	vptr += 2;
					break;

			case 0x0000 :	vptr += 2;

			}
		f++;

		/* Check for more arguaments */
		/* ------------------------- */
		if (!( x & 0x0010 ))
			break;

		/* Determine 2nd Arguament Type */
		/* ---------------------------- */
		switch ((x  & 0x0006)) {

			case 0x0006 :	if ( f )
						convert_register( vptr );
					vptr++;
					break;

			case 0x0002 :	vptr = register_conversion( aptr, vptr, _REG_CONSTANT, 0);
					break;

			case 0x0004 :	if ( f )
						vptr = register_conversion( aptr, vptr, _REG_VARIABLE, 0);
					else	vptr += 2;
					break;

			case 0x0000 :	vptr += 2;

			}

		f++; aptr++;

		}

	/* While more arguaments Exist */
	/* --------------------------- */
	while ( x & 1 );

	return;
}

void	iof_sourcing( sptr )
BPTR	sptr;
{
	BPTR	optr;
	EXAWORD	extra;

	optr = sptr;

	while ( *(optr) & 0x000F ) {

		extra = 0;

		switch (( *(optr) & 0x000F )) {

			case _io_ASK  : return;

			case _io_HOT2 :
			case _io_HOT1 : optr +=2; 

			case _io_SPX  : optr++;
					continue;

			case _io_KEY2 :
			case _io_KEY1 : extra = 2;

			default       :

			switch ( ( *(optr++) & 0x00F0 ) ) {

				case 0x0000 :
				case 0x0020 :
				case 0x0040 : 	optr += 2; break;
				case 0x0080 :	if ( ( *(optr - 1) & 0x000F ) == _io_FMT ) {
							optr += ( (*optr) + 1);
							}
						else	{
						 	while ( *(optr++) );
							}
						break;
				case 0x0060 :	convert_register( optr );
						optr++;
						break;
				}	
			
			}
		optr += extra;

		}

	return;
}

void	ngf_sourcing( sptr )
BPTR	sptr;
{
	EXAWORD	ngfcode;
	EXAWORD	mode;
	BPTR	wptr;
	BPTR	vptr;

	/* Collect NGF Function Code */
	/* ------------------------- */
	ngfcode = (EXAWORD) *(sptr++);
		
	/* Advance to Arguament Values */
	/* --------------------------- */
	wptr = sptr;
	vptr = sptr;

	while ( (*(vptr++) & 0x0001));  

	/* Check for Local Error Trapping */
	/* ------------------------------ */
	if ((((EXAWORD) *wptr ) & 0x0080) != 0x0000) {

		/* Check for Register Return */
		/* ------------------------- */
		if ((((EXAWORD) *wptr ) & 0x0060) == 0x0060) {
			convert_register( (vptr + 2) );
			vptr += 3;
			}
		else	{
			vptr += 4;
			}
		mode = 1;
		}
	else	{
		mode = 0;
		}

	/* Clear Logical File Handle */
	/* ------------------------- */
	if ( mode == 0 ) {

		/* First Nibble Analysis */
		/* --------------------- */
		if ((((EXAWORD) *wptr) & 0x0060) == 0x0060) {
			convert_register( vptr );
			vptr++;
			}
		else	{
			vptr += 2;
			}

		if ((((EXAWORD) *wptr) & 0x0010) != 0x0000) {
			mode = 1;
			}
		else	{
			mode = 2;
			}
		}
	else	{

		/* Second Nibble Analysis */
		/* ---------------------- */
		if ((((EXAWORD) *wptr) & 0x0006) == 0x0006) {
			convert_register( vptr );
			vptr++;
			}
		else	{
			vptr += 2;
			}
		if ((((EXAWORD) *wptr) & 0x0001) == 0) { 
			mode = 2;
			}
		else	{
			wptr++; 
			mode = 0;	
			}
		}

	/* Clear Function Specific Extra Byte */
	/* ---------------------------------- */
	switch ( ngfcode ) {

		case _NGF_MODIFY :
		case _NGF_INSERT :
		case _NGF_DOWN   :
		case _NGF_UP     :
		case _NGF_DELETE :
		case _NGF_SEARCH :
		case _NGF_ATB	 :
		case _NGF_ERASE  :
		case _NGF_CREATE :
		case _NGF_POSIT	 :
		case _NGF_COUNT	 : 
		case _NGF_EXEC	 :
			vptr++;
		}

	/* Clear Remaining Arguaments */
	/* -------------------------- */
	while (mode != 2) {

		if ( mode == 0 ) {

			/* First Nibble Analysis */
			/* --------------------- */
			if ((((EXAWORD) *wptr) & 0x0080) != 0x0000) {

				/* String Constant in T-Code */
				/* ------------------------- */
				while ( *vptr != (BYTE) 0 ) {
					vptr++;
					}
				vptr++;
				}
			else	{ 
				if ((((EXAWORD) *wptr) & 0x0060) == 0x0060) {

					/* Register ID in Tcode */
					/* -------------------- */
					convert_register( vptr );
					vptr++;
					}
				else	{
					vptr += 2;
					}
				}

			/* Test for Next Arguament Valid */
			/* ----------------------------- */
			if ((((EXAWORD) *wptr) & 0x0010) != 0x0000) {
				mode = 1;
				}
			else	{
				mode = 2;
				}
			}
		else	{
			/* Second Nibble Analysis */
			/* ---------------------- */
			if ((((EXAWORD) *wptr) & 0x0008) != 0x0000) {

				/* String Constant in T-Code */
				/* ------------------------- */
				while ( *vptr != (BYTE) 0 ) {
					vptr++;
					}
				vptr++;
				}
			else	{ 

				/* Register ID in Tcode */
				/* -------------------- */
				if ((((EXAWORD) *wptr) & 0x0006) == 0x0006) {
					convert_register( vptr );
					vptr++;
					}
				else	{
					vptr += 2;
					}
				}

			/* Test for Next Arguament Valid */
			/* ----------------------------- */
			if ((((EXAWORD) *wptr) & 0x0001) != 0x0000) {
				wptr++; 
				mode = 0;	
				}
			else	{
				mode = 2;
				}

			}

		}

	return;
}

void	clp_sourcing( sptr )
BPTR	sptr;
{
	BPTR	aptr;
	BPTR	vptr;
	EXAWORD	x;

	/* Advance to Arguament Values */
	/* --------------------------- */
	aptr = sptr;
	vptr = sptr;

	while ( (*(vptr++) & 0x0001));  

	do	{

		/* Determine 1st Arguament Type */
		/* ---------------------------- */
		switch (((x = *aptr) & 0x0060)) {

			case 0x0060 :	convert_register( vptr );
					vptr++;
					break;

			case 0x0020 :	vptr = register_conversion( aptr, vptr, _REG_CONSTANT, 1);
					break;

			case 0x0040 :	if (!(x & 0x0080))
						vptr = register_conversion( aptr, vptr, _REG_VARIABLE, 1);
					else	vptr += 2;
					break;

			case 0x0000 :	vptr += 2;

			}

		/* Check for more arguaments */
		/* ------------------------- */
		if (!( x & 0x0010 ))
			break;

		/* Determine 2nd Arguament Type */
		/* ---------------------------- */
		switch ((x  & 0x0006)) {

			case 0x0006 :	convert_register( vptr );
					vptr++;
					break;

			case 0x0002 :	vptr = register_conversion( aptr, vptr, _REG_CONSTANT, 0);
					break;

			case 0x0004 :	if (!(x & 0x0008))
						vptr = register_conversion( aptr, vptr, _REG_VARIABLE, 0);
					else	vptr += 2;
					break;

			case 0x0000 :	vptr += 2;

			}

		aptr++;

		}

	/* While more arguaments Exist */
	/* --------------------------- */
	while ( x & 1 );

	return;
}

/*
 *	Target register redundancy check : functions CLF, IOF, NGF, CLP, LDF
 *	--------------------------------------------------------------------
 *
 */

EXAWORD  clf_target( sptr , status )
BPTR	sptr;
EXAWORD	status;
{
	BPTR		aptr;
	BPTR		vptr;
	BPTR		tcregister;
	SHADOWPTR	lshadow;
	OPERANDPTR	loperand;
	OPERANDPTR	xoperand;
	EXAWORD		flag;
	EXAWORD		x;
	EXAWORD		l;

	/* --------------------------------------------- */
	/* Check for Functions which return NO Arguament */
	/* MASK RESTORE DATE etc			 */
	/* --------------------------------------------- */
	if ( ( *( sptr + 1 ) & 0x000F ) == 0x0007 )
		return(status);

	/* Separate Format Codes */
	/* --------------------- */
	switch ( *(sptr + 1) ) {
		case 0x005A 	: 
		case 0x006A 	: 
		case 0x007A 	: return(status);
		}

	/* If first Arguament is a Register then Check for redundancy */
	/* ---------------------------------------------------------- */
	l = 2;
	aptr = (sptr + 2); 
	vptr = aptr;

	while (( *(vptr++) & 1 ));

	x = *(aptr++); l++;

	/* Test for Register Result : May be redundant */
	/* ------------------------------------------- */
	if (( x & 0x0060 ) == 0x0060 ) {

		tcregister = vptr;

		vptr++; l++;

		if ((lshadow = collect_register( tcregister )) != (SHADOWPTR) 0) {

			lshadow->current_type |= _REG_OCCUPIED;

			lshadow->tcode_offset =  status;

			lshadow->operation_type = ( (tcGetw( (sptr) )) & 0xFF7F);

			loperand = (OPERANDPTR) 0;

			/* Repeat till end of arguaments */
			/* ----------------------------- */
			while ( x & 0x0010 ) {

				switch ( (x & 0x000E) ) {

					case 0x0000 :
						if ((xoperand = create_operand( _REG_INTEGER, (tcGetw((vptr))) )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr += 2; 
						l += 2;
						break;

					case 0x0002 :
						if ((xoperand = create_operand( _REG_CONSTANT, (tcGetw((vptr))) )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr += 2; 
						l += 2;
						break;
					case 0x0004 :
						if ((xoperand = create_operand( _REG_VARIABLE, (tcGetw((vptr))) )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr += 2; 
						l += 2;
						break;
					case 0x0006 :
						if ((xoperand = create_operand( _REG_REGISTER, *vptr )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr++; 
						l++;
						break;
					}

				if ( status == ERREUR )
					break;

				/* Position this operand in list */
				/* ----------------------------- */
				if ( loperand == (OPERANDPTR) 0 ) 
					lshadow->operand = xoperand;
				else	
					loperand->next = xoperand;

				loperand = xoperand;

				/* Check for end of Args */
				/* --------------------- */
				if ( ! ( x & 1 ) )
					break;

				/* Collect Next arg Descriptor */
				/* --------------------------- */
				x = *(aptr++); l++;

				switch ( (x & 0x00E0) ) {

					case 0x0000 :
						if ((xoperand = create_operand( _REG_INTEGER, (tcGetw((vptr))) )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr += 2; 
						l+= 2;
						break;
					case 0x0020 :
						if ((xoperand = create_operand( _REG_CONSTANT, (tcGetw((vptr))) )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr += 2; 
						l += 2;
						break;
					case 0x0040 :
						if ((xoperand = create_operand( _REG_VARIABLE, (tcGetw((vptr))) )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr += 2; 
						l += 2;
						break;
					case 0x0060 :
						if ((xoperand = create_operand( _REG_REGISTER, *vptr )) == (OPERANDPTR) 0)
							status = ERREUR;
						vptr++; 
						l++;
						break;
					}

				if ( status == ERREUR )
					break;

				/* Position this operand in list */
				/* ----------------------------- */
				if ( loperand == (OPERANDPTR) 0 ) 
					lshadow->operand = xoperand;
				else	
					loperand->next = xoperand;

				loperand = xoperand;

				}

			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR ) 

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr , *tcregister , (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( sptr , l );



			}		
		else	{
			status = ERREUR;
			}
		}

	return(status); 
}

EXAWORD  iof_target( sptr , status )
BPTR	sptr;
EXAWORD	status;
{
	return(status);
}


EXAWORD	establish_primary_index( tcregister , ri )
BPTR	tcregister;
EXAWORD	ri;
{
	OPERANDPTR	loperand;

	if ( Primary[ *tcregister ] == (SHADOWPTR) 0)
		if (( Primary[ *tcregister ] = allocate_for_register()) == (SHADOWPTR) 0)
			return(ERREUR);

	if ((loperand = allocate_for_operand()) == (OPERANDPTR) 0)
		return( ERREUR );

	(Primary[ *tcregister ])->current_type |= _REG_OCCUPIED;

	(Primary[ *tcregister ])->tcode_offset =  ri;

	switch (( (Primary[ *tcregister ])->operation_type = ( *(tcregister - 1) & 0x007F )) ) {

		case _tc_LXI  :	loperand->type 	  = _REG_INTEGER;
				loperand->integer = tcGetw( (tcregister + 1) );
				break;

		case _tc_LXC  :	loperand->type 	   = _REG_CONSTANT;
				loperand->constant = tcGetw( (tcregister + 1) );
				break;

		case _tc_LXV  :	loperand->type 	   = _REG_VARIABLE;
				loperand->variable = tcGetw( (tcregister + 1) );
				break;

		case _tc_LXR  :	loperand->type 	   = _REG_REGISTER;
				loperand->registre = *(tcregister + 1);
				break;

		}

	(Primary[ *tcregister ])->operand = loperand;
	return(ri);
}

EXAWORD	establish_secondary_index( tcregister, ri )
BPTR	tcregister;
EXAWORD	ri;
{
	OPERANDPTR	loperand;

	if ( Secondary[ *tcregister ] == (SHADOWPTR) 0)
		if (( Secondary[ *tcregister ] = allocate_for_register()) == (SHADOWPTR) 0)
			return(ERREUR);

	if ((loperand = allocate_for_operand()) == (OPERANDPTR) 0)
		return( ERREUR );

	(Secondary[ *tcregister ])->current_type |= _REG_OCCUPIED;

	(Secondary[ *tcregister ])->tcode_offset =  ri;

	switch (( (Secondary[ *tcregister ])->operation_type = ( *(tcregister - 1) & 0x007F )) ) {

		case _tc_AXI  :	loperand->type 	  = _REG_INTEGER;
				loperand->integer = tcGetw( (tcregister + 1) );
				break;

		case _tc_AXC  :	loperand->type 	   = _REG_CONSTANT;
				loperand->constant = tcGetw( (tcregister + 1) );
				break;

		case _tc_AXV  :	loperand->type 	   = _REG_VARIABLE;
				loperand->variable = tcGetw( (tcregister + 1) );
				break;

		case _tc_AXR  :	loperand->type 	   = _REG_REGISTER;
				loperand->registre = *(tcregister + 1);
				break;

		}

	(Secondary[ *tcregister ])->operand = loperand;
	return(ri);
}


EXAWORD	handle_unary_operator( sptr , si , ri )
BPTR	sptr;
EXAWORD	si;
EXAWORD	ri;
{
	EXAWORD		result;
	EXAWORD		length;
	EXAWORD		original_register;
	EXAWORD		oldregister;
	EXAWORD		flag;
	SHADOWPTR	xregister;

	/* printf("\nhandle_unary_operator(%d)\n",*(sptr + si +1)); */

	/* Watch out for Redirected target as source */
	/* ----------------------------------------- */
	if ( Redirection[((original_register = *(sptr + si + 1))) ] != 0 ) {
		/* printf("Register was %d is now %d\n",original_register,Redirection[original_register]); */
		*(sptr + si + 1) = Redirection[ *(sptr + si + 1) ];
		}

	/* Watch out for Redirected : Already an optimised expression */
	/* ---------------------------------------------------------- */
	if ((General[*(sptr + si + 1)])->current_type & _REG_REDIRECTED ) {


		oldregister = (General[*(sptr + si + 1)])->register_link;
		/* printf("Register %d has already been redirected to %d\n",*(sptr + si + 1),oldregister);  */

		/* Attempt to allocate a new target register */
		/* ----------------------------------------- */
		if ((xregister = next_free_register( (sptr + si + 1) )) == (SHADOWPTR) 0)
			return( ERREUR );		

		/* printf("Now redirected to %d\n",*(sptr + si + 1)); */

		/* Allocate for Register operand */
		/* ----------------------------- */
		if (( xregister->operand = allocate_for_operand()) == (OPERANDPTR) 0)
			return( ERREUR );

		xregister->tcode_offset = ri;

		/* ---------------------------- */
		/*  * *  TCODE EXPANSION  * *   */
		/* ---------------------------- */
		/* Generate tcode LDR #new,#old */
		/* ---------------------------- */
		*(sptr + ri) = _tc_LDR; 		ri++;
		*(sptr + ri) = (BYTE) *(sptr + si + 1); ri++;
		*(sptr + ri) = (BYTE) oldregister;	ri++;
		flag = VRAI;

		/* printf("Generating _tc_LDR %d,%d\n",*(sptr + si +1),oldregister); */

		/* Establish new register contents */
		/* ------------------------------- */
		xregister->current_type   	= _REG_OCCUPIED;
		xregister->operation_type 	= _tc_LDR;
		xregister->operand->type  	= _REG_REGISTER;
		xregister->operand->registre	= oldregister;

		/* Redirect the Redirected Register */
		/* -------------------------------- */
		/* Check for Redirection Correction Required */
		/* ----------------------------------------- */
		if (Redirection[original_register]) 

			/* Correct Redirection to This Result */
			/* ---------------------------------- */
			Redirection[original_register]  = *(sptr + si + 1);
#ifdef	PRIOR_TO_140494
		else	Redirection[oldregister] = *(sptr + si + 1);
#endif

		}
	else	{
		flag = FAUX;
		}

	/* Allocate for Register Shift Right */
	/* --------------------------------- */
	if (( xregister = allocate_for_register()) == (SHADOWPTR) 0)
		return( ERREUR );

	/* Shift right operand register and store result register */
	/* ------------------------------------------------------ */
	xregister->parent = General[ *(sptr + si + 1) ];
	General[ *(sptr + si + 1) ] = xregister;

	/* Indicated current status and operation */
	/* -------------------------------------- */
	xregister->current_type   = (_REG_OCCUPIED | _REG_MODIFIED);

	/* Check for Conversion modifier */
	/* ----------------------------- */
	if ((xregister->operation_type = *(sptr + si)) == _tc_CNV ) {

		length = 4;

		/* Attempt to allocate for CONV operand */
		/* ------------------------------------ */
		if (( xregister->operand = allocate_for_operand()) == (OPERANDPTR) 0)
			return( ERREUR );

		/* Establish Conversion Type Code */
		/* ------------------------------ */
		xregister->operand->type    = _REG_INTEGER;
		xregister->operand->integer = tcGetw( (sptr + si + 2) );

		}
	else	{
		length = 2;
		}

	xregister->tcode_offset = result = ri;

	if ( redundancy_check(sptr, *(sptr + si + 1) , (WPTR) & result ) == VRAI ) {

		/* Remove generated code if required */
		/* --------------------------------- */
		if ( flag == VRAI )
			result = ( (result < (ri - 3)) ? result : (ri - 3) );
				
		/* Remove this expression due to redundancy */
		/* ---------------------------------------- */
		remove_expression( (sptr + si) , length );

		}

	/* Return Result Pointer */
	/* --------------------- */
	return( result );
		
}

void	cancel_shadow_register( registre )
EXAWORD	registre;
{
	liberate_register( General[ registre ] );
	return;
}

EXAWORD	collect_shadow_value( registre, field )
EXAWORD	registre;
EXAWORD	field;
{
	if (( General[ registre ] != (SHADOWPTR) 0 ) && ( General[ registre ]->operand != (OPERANDPTR) 0)) {

		switch ( field ) {

			case 0x0000 : 	/* Integer Field  */
					/* -------------- */
					return(General[ registre ]->operand->integer );

			case 0x0001 : 	/* Constant Field */
					/* -------------- */
					return(General[ registre ]->operand->constant);

			case 0x0002 : 	/* Variable Field */
					/* -------------- */
					return(General[ registre ]->operand->variable);

			case 0x0003 : 	/* Register Field */
					/* -------------- */
					return(General[ registre ]->operand->registre);


			}

		}
	return( 0 );	
}

void	redirect_register( new_register, old_register )
EXAWORD	new_register;
EXAWORD	old_register;
{
	establish_top_register( new_register );
	Redirection[ new_register ] = old_register;
	return;
}

void	alter_shadow_register( new_register, old_register, field, value )
EXAWORD	new_register;
EXAWORD	old_register;
EXAWORD	field;
EXAWORD	value;
{
	if (!( ForNextFlag) ) {

		if ( new_register != old_register )
			redirect_register( new_register, old_register );

		switch ( field ) {
			case 0x0000 : 	/* Integer Field  */
					/* -------------- */
					General[ old_register ]->operand->integer = value;
					break;

			case 0x0001 : 	/* Constant Field */
					/* -------------- */
					General[ old_register ]->operand->constant = value;
					break;

			case 0x0002 : 	/* Variable Field */
					/* -------------- */
					General[ old_register ]->operand->variable = value;
					break;

			case 0x0003 : 	/* Register Field */
					/* -------------- */
					General[ old_register ]->operand->registre = value;
					break;


			}
		}	
	return;
}

EXAWORD	shadow_register_contents( registre )
EXAWORD	registre;
{
	if (General[ registre ] != (SHADOWPTR) 0 ) {
		switch ( General[registre]->operation_type ) {
			case _tc_LDI :
			case _tc_LDC :
			case _tc_LDV :
			case _tc_LDR :
			case _tc_VPT :
			case _tc_GIL :
			case _tc_GCL :
			case _tc_LIL :
			case _tc_LCL :
				if ( General[ registre ]->operand != (OPERANDPTR) 0)
					return( General[ registre ]->operand->type );
				else if ( General[ registre ]->current_type & _REG_MODIFIED )
					return( _REG_REGISTER );	
			}
		}
	return( MOINS_UN );
}

/*
 *	Returns the Effective or Useful Size of a Register Result Operand 
 *	-----------------------------------------------------------------
 *
 */

EXAWORD	RegisterSize( tcode, registre )
EXAWORD	tcode;
EXAWORD	registre;
{
	/* Not Yet Active */
	/* -------------- */
	return( MOINS_UN );

}



/*
 *	---------------------------------------------------------------
 *	R E G I S T E R _ O P T I M I S E R  (  sptr  ,   si  ,   ri  )
 *	---------------------------------------------------------------
 *
 *	Called from the main optimisation Cycle to allow visibillity
 *	of pre-optimisation tcode structures for the shadow register
 *	mechanism. 
 *	
 *	***********************************
 *	* *	A T T E N T I O N 	* *
 *	***********************************
 *	
 *	This function may and will modify the pre-optimisation tcode
 *	structures. It may also modify the post optimisation result
 *	index to remove generated but redundant code.
 *
 */  

EXAWORD	register_optimiser( sptr , si , status )
BPTR	sptr;
EXAWORD	si;
EXAWORD	status;
{
	SHADOWPTR	lshadow;
	EXAWORD		altreg;

	/* Test for New line Expression (start of block) */
	/* --------------------------------------------- */
	if     ( (((EXAWORD) *(sptr + si)) & 0x0080) ){

		/* Reset all shadow register Values */
		/* -------------------------------- */
		status = reset_shadower(sptr, status );

		}

	/* Watch out for FOR/NEXT expression under way */
	/* ------------------------------------------- */
	if ( ForNextFlag == VRAI )
		return( status );

	/* Select Tcodes of Group 3 which source from registers */
	/* ---------------------------------------------------- */
	switch ( (((EXAWORD) *(sptr + si)) & 0x007F) ){
		case _tc_JMI  :
		case _tc_GSB  :
				if (((EXAWORD) *(sptr + si)) & 0x0080)
					break;
		case _tc_PSH  :
		case _tc_POP  :
				convert_register( (sptr + si + 1) );
/*		reset_shadower( status );
Fuck		ForNextFlag = VRAI; */
				return( status );

		case _tc_ESC  : 

			/* Perform Escape Code analysis */
			/* ---------------------------- */
			switch ( (((EXAWORD) *(sptr + si + 1)) & 0x007F) ){

				case _esc_CLP :	/* CALL		*/

					clp_sourcing( (sptr + si + 2) );
					break;

				case _esc_LIB : /* ESC LIB      */
					if ( *(sptr + si + 2) == 0x0060 )
						convert_register( (sptr + si + 3) );
					break;

				case _esc_JMT : /* OF GOTO      */
				case _esc_GST : /* OF GOSUB     */
				case _esc_PSR : /* PAUSE expres */
				case _esc_SGR : /* LDGO.SEG exp */
				case _esc_RTR : /* ERROR REG	*/
				case _esc_RGT : /* GOTO REG     */
				case _esc_RGS : /* GOSUB REG    */

					convert_register( (sptr + si + 2) );
					break;


				case _esc_RTI : /* ERROR INT    */
				case _esc_RTV : /* ERROR VAR	*/
				case _esc_ETP : /* END.PROC     */
				case _esc_RTP :	/* EXIT		*/
				case _esc_RTS :	/* RET.SEG	*/
				case _esc_STP :	/* STOP		*/
				case _esc_ETS :	/* END.SEG	*/
				case _esc_SGI :	/* LDGO.SEG B	*/
				case _esc_SGV : /* LDGO.SEG X   */
				case _esc_SGW : /* LDGO.SEG W   */
				case _esc_PSI : /* PAUSE 1	*/
				case _esc_PSC :	/* PAUSE "m"	*/
				case _esc_PSV :	/* PAUSE X	*/

					break;

 				}

			break;

		case _tc_CLF  : clf_sourcing( ( sptr + si + 1 ) );
				break;
		case _tc_IOF  : iof_sourcing( ( sptr + si + 1 ) );
				break;
		case _tc_NGF  : ngf_sourcing( ( sptr + si + 1 ) );
				break;
		case _tc_LDE  :	
		case _tc_LDF  : clp_sourcing( ( sptr + si + 1 ) );
				break;

		case _tc_JEQI :
		case _tc_JNEI :
		case _tc_JGRI :
		case _tc_JLSI :
		case _tc_JGEI :
		case _tc_JLEI :

			convert_register( (sptr + si + 1) ); 
			break;

		case _tc_JEQC :
		case _tc_JNEC :
		case _tc_JGRC :
		case _tc_JLSC :
		case _tc_JGEC :
		case _tc_JLEC :
		case _tc_JINC :
		case _tc_JNIC :

			convert_register( (sptr + si + 1) ); 

			/* Check if Variable May be directed to a Register */
			/* ----------------------------------------------- */
			if ((altreg = terminal_element_present( _REG_CONSTANT, (tcGetw((sptr + si+ 2))))) != MOINS_UN ) {
 
				*(sptr + si) = (( *(sptr + si) & 0x009F) | 0x0060 );
				*(sptr + si + 2) = altreg;
				altreg = (tcGetw((sptr + si + 4)));
				tcPutw((sptr + si + 3),altreg);
				*(sptr + si + 5) = _tc_NOP;

				}
			break;

		case _tc_JEQV :
		case _tc_JNEV :
		case _tc_JGRV :
		case _tc_JLSV :
		case _tc_JGEV :
		case _tc_JLEV :
		case _tc_JINV :
		case _tc_JNIV :	

			convert_register( (sptr + si + 1) ); 

			/* Check if Variable May be directed to a Register */
			/* ----------------------------------------------- */
			if ((altreg = terminal_element_present( _REG_VARIABLE, (tcGetw((sptr + si+ 2))))) != MOINS_UN ) {
 
				*(sptr + si) = (( *(sptr + si) & 0x009F) | 0x0060 );
				*(sptr + si + 2) = altreg;
				altreg = (tcGetw((sptr + si + 4)));
				tcPutw((sptr + si + 3),altreg);
				*(sptr + si + 5) = _tc_NOP;

				}
			break;

		case _tc_JEQR :
		case _tc_JNER :
		case _tc_JGRR :
		case _tc_JLSR :
		case _tc_JGER :
		case _tc_JLER :
		case _tc_JINR :
		case _tc_JNIR : convert_register( (sptr + si + 1) ); 
		case _tc_AXR  : 
		case _tc_LXR  :	convert_register( (sptr + si + 2) ); break;

		case _tc_ADI  :
		case _tc_SBI  :
		case _tc_MLI  :
		case _tc_DVI  :
		case _tc_MDI  :
		case _tc_ANI  :
		case _tc_ORI  :
		case _tc_XRI  :
		case _tc_ADC  :
		case _tc_SBC  :
		case _tc_MLC  :
		case _tc_DVC  :
		case _tc_MDC  :
		case _tc_ANC  :
		case _tc_ORC  :
		case _tc_XRC  :
		case _tc_ADV  :
		case _tc_SBV  :
		case _tc_MLV  :
		case _tc_DVV  :
		case _tc_MDV  :
		case _tc_ANV  :
		case _tc_ORV  :
		case _tc_XRV  :	convert_register( (sptr + si + 1) ); break;
		case _tc_ADR  :
		case _tc_SBR  :
		case _tc_MLR  :
		case _tc_DVR  :
		case _tc_MDR  :
		case _tc_ANR  :
		case _tc_ORR  :
		case _tc_XOR  :	convert_register( (sptr + si + 1) );
				convert_register( (sptr + si + 2) ); break;



		case _tc_STR : convert_register( (sptr + si + 1) ); break;
		case _tc_LDR : convert_register( (sptr + si + 2) ); break;

		}

	/* Select Tcodes which require redundancy checking */
	/* ----------------------------------------------- */
	switch ( (((EXAWORD) *(sptr + si)) & 0x007F) ){

		case _tc_CLF  : status = clf_target( (sptr + si) , status );
				break;
		case _tc_IOF  : status = iof_target( (sptr + si) , status );
				break;

		/* Special functions */
		/* ----------------- */
		case _tc_POP  :
		case _tc_PSH  : break;

		/* Index Register Unary operators */
		/* ------------------------------ */
		case _tc_INX  :
		case _tc_DEX  :
		case _tc_ANX  :
		case _tc_DAX  :	break;

		/* Register modifiers */
		/* ------------------ */
		case _tc_NGR  :
		case _tc_INC  :
		case _tc_DEC  :	
		case _tc_CNV  : status = handle_unary_operator( sptr, si, status);
				break;

		/* Tcodes which target registers */
		/* ----------------------------- */
		case _tc_VPT  :
		case _tc_LDV  :

			if ((lshadow = collect_vpt_register( (sptr + si + 1) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_VARIABLE, (tcGetw((sptr + si + 2))) )) == (OPERANDPTR) 0)
					status = ERREUR;
				}
			else	{
				status = ERREUR;
				}

			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR)

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 1) , (WPTR) & status) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 4 );

			break;

		case _tc_GIL  :
		case _tc_LIL  :
		case _tc_GCL  :
		case _tc_LCL  :

			if ((lshadow = collect_register( (sptr + si + 1) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_VARPTR , (tcGetw((sptr + si + 2))))) == (OPERANDPTR) 0)
					status = ERREUR;
				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR )

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 1), (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 4 );

			break;

		case _tc_LXI  :
		case _tc_LXC  :
		case _tc_LXV  :
		case _tc_LXR  :

			if ( *(sptr + si + 1) ) {
				if ((lshadow = collect_index_register( (sptr + si + 1) )) == (SHADOWPTR) 0) {
					status = ERREUR;
					}
				else	{
					lshadow->current_type = (_REG_PRIMARY | _REG_OCCUPIED);
					status = establish_primary_index( (sptr + si + 1) , status );
					}
				}
			break;

		case _tc_AXI  :
		case _tc_AXC  :
		case _tc_AXV  :
		case _tc_AXR  :
			if ( *(sptr + si + 1) ) {
				if ((lshadow = collect_index_register( (sptr + si + 1) )) == (SHADOWPTR) 0) {
					status = ERREUR;
					}
				else	{
					lshadow->current_type |= _REG_SECONDARY;
					status = establish_secondary_index( (sptr + si + 1) , status );
					}
				}
			break;

		case _tc_LDI  :

			if ((lshadow = collect_register( (sptr + si + 1) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_INTEGER , (tcGetw((sptr + si + 2))))) == (OPERANDPTR) 0)
					status = ERREUR;
				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR )

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 1), (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 4 );

			break;

		case _tc_LDR  :

			if ((lshadow = collect_register( (sptr + si + 1) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_REGISTER , *(sptr + si + 1) ))  == (OPERANDPTR) 0)
					status = ERREUR;
				else	duplicate_for_ldr( lshadow, *(sptr + si + 2) );
				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR)

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 1), (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 3 );

			break;

		case _tc_LDC  :	

			if ((lshadow = collect_register( (sptr + si + 1) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_CONSTANT , (tcGetw((sptr + si + 2))))) == (OPERANDPTR) 0)
					status = ERREUR;
				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR)

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 1), (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 4 );

			break;

		case _tc_ADI  :
		case _tc_SBI  :
		case _tc_MLI  :
		case _tc_DVI  :
		case _tc_MDI  :
		case _tc_ANI  :
		case _tc_ORI  :
		case _tc_XRI  :

			if ((lshadow = collect_register( (sptr + si + 4) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_REGISTER , *(sptr + si + 1) ))  == (OPERANDPTR) 0)
					status = ERREUR;
				else if ((lshadow->operand->next = create_operand( _REG_INTEGER, (tcGetw((sptr + si + 2)))  ))  == (OPERANDPTR) 0)
					status = ERREUR;

				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR)

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 4), (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 5 );

			break;

		case _tc_ADC  :
		case _tc_SBC  :
		case _tc_MLC  :
		case _tc_DVC  :
		case _tc_MDC  :
		case _tc_ANC  :
		case _tc_ORC  :
		case _tc_XRC  :

			if ((lshadow = collect_register( (sptr + si + 4) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_REGISTER , *(sptr + si + 1) ))  == (OPERANDPTR) 0)
					status = ERREUR;
				else if ((lshadow->operand->next = create_operand( _REG_CONSTANT, (tcGetw((sptr + si + 2)))  ))  == (OPERANDPTR) 0)
					status = ERREUR;

				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR) {

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 4), (WPTR) & status ) == VRAI ) {

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 5 );
					}
				else	{
					/* Check if Variable May be directed to a Register */
					/* ----------------------------------------------- */
					if ((altreg = terminal_element_present( _REG_CONSTANT, (tcGetw((sptr + si+ 2))))) != MOINS_UN ) {
 
						*(sptr + si) = (( *(sptr + si) & 0x009F) | 0x0060 );
						*(sptr + si + 2) = altreg;
						*(sptr + si + 3) = *(sptr + si + 4);
						*(sptr + si + 4) = _tc_NOP;

						}
					}
				}

			break;

		case _tc_ADV  :
		case _tc_SBV  :
		case _tc_MLV  :
		case _tc_DVV  :
		case _tc_MDV  :
		case _tc_ANV  :
		case _tc_ORV  :
		case _tc_XRV  :

			if ((lshadow = collect_register( (sptr + si + 4) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_REGISTER , *(sptr + si + 1) ))  == (OPERANDPTR) 0)
					status = ERREUR;
				else if ((lshadow->operand->next = create_operand( _REG_VARIABLE, (tcGetw((sptr + si + 2)))  ))  == (OPERANDPTR) 0)
					status = ERREUR;

				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR) {

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 4), (WPTR) & status ) == VRAI ) {

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 5 );

					}
				else	{
					/* Check if Variable May be directed to a Register */
					/* ----------------------------------------------- */
					if ((altreg = terminal_element_present( _REG_VARIABLE, (tcGetw((sptr + si+ 2))))) != MOINS_UN ) {
 
						*(sptr + si) = (( *(sptr + si) & 0x009F) | 0x0060 );
						*(sptr + si + 2) = altreg;
						*(sptr + si + 3) = *(sptr + si + 4);
						*(sptr + si + 4) = _tc_NOP;

						}
					}
				}
			break;

		case _tc_ADR  :
		case _tc_SBR  :
		case _tc_MLR  :
		case _tc_DVR  :
		case _tc_MDR  :
		case _tc_ANR  :
		case _tc_ORR  :
		case _tc_XOR  :

			if ((lshadow = collect_register( (sptr + si + 3) )) != (SHADOWPTR) 0) {
				lshadow->current_type |= _REG_OCCUPIED;
				lshadow->tcode_offset =  status;
				lshadow->operation_type = ( *(sptr + si) & 0x007F );
				if ((lshadow->operand = create_operand( _REG_REGISTER , *(sptr + si + 1) ))  == (OPERANDPTR) 0)
					status = ERREUR;
				else if ((lshadow->operand->next = create_operand( _REG_REGISTER , *(sptr + si + 2) ))  == (OPERANDPTR) 0)
						status = ERREUR;

				}
			else	{
				status = ERREUR;
				}
			/* Correct context established */
			/* --------------------------- */
			if ( status != ERREUR)

				/* Test for redundant expression */
				/* ----------------------------- */
				if ( redundancy_check(sptr, *(sptr + si + 3), (WPTR) & status ) == VRAI )

					/* Remove this expression due to redundancy */
					/* ---------------------------------------- */
					remove_expression( (sptr + si) , 4 );

			break;

		}


	return ( status );

}

#endif	/* _REGISTER_C */
	/* ----------- */

