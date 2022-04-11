/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	OPTIMISE.C				*/
/*		Version :	2.1b					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_OPTIMISE_C
#define	_OPTIMISE_C

#define	OPTIMISEUR

				/* ------------------------------------ */
#include "aomain.h"		/* Type Definitions and constants	*/
#include "aotcode.h"		/* Inclusion of TCode definitions	*/
#include "aotcngf.h"		/* NGF T-Code Definitions		*/
#include "aostat.h"		/* Statistics management		*/
#include "aomacro.h"		/* Macros used for source Clarity	*/
#include "aoproto.h"		/* Prototypes for all Object Modules	*/
#include "aoglobal.h"		/* Data Items with Global Scope		*/
#include "aoreg.h"		/* Register Contents Coding		*/
#include "aogesmes.c"		/* Messages in GESMES Format		*/
				/* ------------------------------------ */
extern	EXAWORD	ForNextFlag;	/* Attention : Messy Code 'For Next'	*/
				/* ------------------------------------ */
extern	EXAWORD	keep_procedures;/* Cancels procedures removal due to    */
				/* Indirect procedure calling		*/
				/* Required for the optimisation of 	*/
				/* ABAL++ PROGRAM OVERLAY OBJECTS	*/
				/* IJM 8/11/1993			*/
				/* ------------------------------------ */

/*	Converts Integer Loads to GIL GCL LIL LCL	*/
/*	-----------------------------------------	*/

EXAWORD	IntegerLoad( sptr )
BPTR	sptr;
{
	EXAWORD	x;

	/* Collect Variable Descriptor and Select */
	/* -------------------------------------- */
	switch ((Descriptor((tcGetw((sptr + 2)))) & INTEGER_TYPE )) {

		/* Optimise both Local and Global % and # */
		/* -------------------------------------- */
		case 0x0088 :
		case 0x0080 : *sptr = (BYTE) (_tc_LCL | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0089 :
		case 0x0081 : *sptr = (BYTE) (_tc_LIL | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0008 :
		case 0x0000 : *sptr = (BYTE) (_tc_GCL | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0009 :
		case 0x0001 : *sptr = (BYTE) (_tc_GIL | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;

		/* No Optimisation if not # or % simple */
		/* ------------------------------------ */
		default	    : return(FAUX);
		}


	/* Collect and Establish Variable Offset */
	/* ------------------------------------- */
	x = AdresseVarb((tcGetw((sptr + 2))));
	tcPutw((sptr +2), x);
	return(VRAI);
}

/*	Converts Integer store to GIS GCS LIS LCS	*/
/*	-----------------------------------------	*/

void	IntegerSave( sptr )
BPTR	sptr;
{
	EXAWORD	x;

	/* Collect Variable Descriptor and Select */
	/* -------------------------------------- */
	switch ((Descriptor((tcGetw((sptr + 3)))) & INTEGER_TYPE)) {

		/* Optimise both Local and Global % and # */
		/* -------------------------------------- */
		case 0x0088 :
		case 0x0080 : *sptr = (BYTE) (_tc_LCS | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0089 :
		case 0x0081 : *sptr = (BYTE) (_tc_LIS | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0008 :
		case 0x0000 : *sptr = (BYTE) (_tc_GCS | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0009 :
		case 0x0001 : *sptr = (BYTE) (_tc_GIS | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;

		/* No Optimisation if not # or % simple */
		/* ------------------------------------ */
		default	    : return;
		}

	/* Collect and Establish Variable Offset */
	/* ------------------------------------- */
	x = AdresseVarb((tcGetw((sptr + 2))));
	tcPutw((sptr +2),x);
	return;
}

/*
 *	A B A L   1.5 a  : Optimised tcodes tcGWS and tcLWS
 *	---------------------------------------------------
 *
 */

EXAWORD	optimise_gws_lws( sptr )
BPTR	sptr;
{
	EXAWORD	x;
	switch ((Descriptor((tcGetw((sptr + 3)))) & INTEGER_TYPE )) {

		case 0x0089 :
		case 0x0081 : *sptr = (BYTE) (_tc_LWS | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		case 0x0009 :
		case 0x0001 : *sptr = (BYTE) (_tc_GWS | (((EXAWORD) *sptr ) & TCODE_NEWLINE)); break;
		default	    : return( FAUX );
		}

	/* Collect and Establish Variable Offset */
	/* ------------------------------------- */
	x = AdresseVarb((tcGetw((sptr + 3))));
	tcPutw((sptr +3),x);

	return( VRAI );
}


void	OptimiserError( EscMode , sptr , si )
EXAWORD	EscMode;
BPTR	sptr;
EXAWORD	si;
{
	if ( MasterPhase == 1 ) {
		oputs((BPTR) " Segment ");
		HexWord( SegId );
		}
	else	{
		oputs((BPTR) " Procedure ");
		HexWord( (PrcId >> 4) );
		}
	oputs((BPTR)" adresse ");
	HexAdresse( si );
	oputs((BPTR) TalkPtr[10] );

#ifdef	AO_LISTFILE

	if ( EscMode != 0 ) {
		Mnemonic( 0 ); 
		EscMnemonic( (((EXAWORD) *(sptr + si)) & REMOVE_NEWLINE) ); 
		}
	else	{
		Mnemonic( (((EXAWORD) *(sptr + si)) & REMOVE_NEWLINE) ); 
		}

#endif	/* AO_LISTFILE */
	/* ----------- */

	LineFeed();
	return;
}



void	debug_trace( si )
EXAWORD	si;

{

	oputs((BPTR) " [");
	HexAdresse( si );
	oputs((BPTR) " : ");
	HexAdresse( (tcGetw( ( tc_PDT + 2) )) );
	oputs((BPTR) "] ");
	return;
}

void	procedure_usage( pptr )
BPTR	pptr;
{
	EXAWORD	procid;
	EXAWORD	valeur;

	procid = tcGetw(((BPTR) pptr ));
	valeur = tcGetw(((BPTR) (tc_PDT + procid + 14)) );
	valeur |= PROCEDURE_USED;
	tcPutw(((BPTR) (tc_PDT + procid + 14)) , valeur );
	return;
}


EXAWORD	integer_compare( cmpcode )
EXAWORD	cmpcode;
{
	switch ( cmpcode ) {
		case _tc_JINC : return( _tc_JEQI );
		case _tc_JNIC : return( _tc_JNEI );
		default       : return( (cmpcode & 0x001F) );
		}
}


BYTE	vconstant[12];

EXAWORD	constant_calculator( opcode, wptr1, wlen1, yoperand )
EXAWORD	opcode;
BPTR	wptr1;
EXAWORD	wlen1;
BPTR	yoperand;
{
	BPTR	wptr2;
	EXAWORD	wlen2;
	
	wptr2 = (tcGKT + (tcGetw((yoperand))) + 1);
	wlen2 = *(wptr2++);

	/* Perform BCD Calculation */
	/* ----------------------- */
	bcdcalc( opcode, wptr1, wlen1, wptr2, wlen2,(BPTR) vconstant, 12);

	return( 1 );

}

EXAWORD	constant_calculation(opcode, xconst, yconst )
EXAWORD	opcode;
EXAWORD	xconst;
EXAWORD	yconst;
{
	BPTR	wptr1;
	EXAWORD	wlen1;
	BPTR	wptr2;
	EXAWORD	wlen2;
	wptr1 = (tcGKT + xconst + 1);
	wlen1 = *(wptr1++);
	wptr2 = (tcGKT + yconst + 1);
	wlen2 = *(wptr2++);

	/* Perform BCD Calculation */
	/* ----------------------- */
	bcdcalc( opcode, wptr1, wlen1, wptr2, wlen2,(BPTR) vconstant, 12);

	return( 1 );
}

EXAWORD	optimise_constant_div_mul( sptr , si , offset )
BPTR	sptr;			/* Tcode Code Segment Base 	*/
EXAWORD	si;			/* Current Base Offset		*/
EXAWORD	offset;			/* Next Tcode Sequence Adjuster	*/
{
	EXAWORD	result;
	EXAWORD	tc;
	EXAWORD	final_register;
	EXAWORD	bcdlen;
	BPTR	bcdptr;
	BPTR	registre;

	registre = (sptr + si + offset - 1);

	bcdptr = (tcGKT + (tcGetw((sptr + si + 2))) + 1);
	bcdlen = *(bcdptr++);

	for ( final_register = 0; ; ) {

		/* Detect possible Constant Operations */
		/* ----------------------------------- */
		switch ( (tc = *(sptr + si + offset )) ) {

			/* Tcodes which permit this optimisation */
			/* ------------------------------------- */
			case _tc_MLC :
			case _tc_DVC :

				/* Perform Calculation to Create New Constant */
				/* ------------------------------------------ */
				if ((result = constant_calculator( (tc & 0x0007),bcdptr, bcdlen, (sptr + si + offset + 2) )) == 0) {

					if ( final_register != 0 ) {

						/* Add Constant to Constant Table */
						/* ------------------------------ */
						if ((result = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN)

							/* Patch New Constant Identifier */
							/* ----------------------------- */
							tcPutw((sptr + si + 2),result);

						}

					return( final_register );

					}

				/* Patch original Register Number */
				/* ------------------------------ */
				final_register = *(sptr + si + offset + 4);

				bcdptr = (BPTR) vconstant;
				bcdlen = 12;

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 5 );

				/* Step over to next Tcode Sequence */
				/* -------------------------------- */
				offset += 5;

				/* Attempt next possible Operation */
				/* ------------------------------- */
				continue;

			default	     : 

				/* Return Current Operation Status */
				/* ------------------------------- */

				if ( final_register != 0 ) {

					/* Add Constant to Constant Table */
					/* ------------------------------ */
					if ((result = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN)

						/* Patch New Constant Identifier */
						/* ----------------------------- */
						tcPutw((sptr + si + 2),result);

					cancel_shadow_register( *registre );
					*registre = final_register;

					}

				return( final_register );

			}
		}	

}

EXAWORD	optimise_constant_add_sub( sptr , si , offset )
BPTR	sptr;			/* Tcode Code Segment Base 	*/
EXAWORD	si;			/* Current Base Offset		*/
EXAWORD	offset;			/* Next Tcode Sequence Adjuster	*/
{
	EXAWORD	result;
	EXAWORD	tc;
	EXAWORD	final_register;
	EXAWORD	bcdlen;
	BPTR	bcdptr;
	BPTR	registre;

	registre = (sptr + si + offset - 1);
	
	bcdptr = (tcGKT + (tcGetw((sptr + si + 2))) + 1);
	bcdlen = *(bcdptr++);

	for ( final_register = 0; ; ) {

		/* Detect possible Constant Operations */
		/* ----------------------------------- */
		switch ( (tc = *(sptr + si + offset )) ) {

			/* Tcodes which permit this optimisation */
			/* ------------------------------------- */
			case _tc_ADC :
			case _tc_SBC :

				/* Perform Calculation to Create New Constant */
				/* ------------------------------------------ */
				if ((result = constant_calculator( (tc & 0x0007),bcdptr, bcdlen, (sptr + si + offset + 2) )) == 0) {

					if ( final_register != 0 ) {

						/* Add Constant to Constant Table */
						/* ------------------------------ */
						if ((result = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN)

							/* Patch New Constant Identifier */
							/* ----------------------------- */
							tcPutw((sptr + si + 2),result);

						}

					return( final_register );

					}

				/* Patch original Register Number */
				/* ------------------------------ */
				final_register = *(sptr + si + offset + 4);

				bcdptr = (BPTR) vconstant;
				bcdlen = 12;

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 5 );

				/* Step over to next Tcode Sequence */
				/* -------------------------------- */
				offset += 5;

				/* Attempt next possible Operation */
				/* ------------------------------- */
				continue;

			default	     : 

				/* Return Current Operation Status */
				/* ------------------------------- */

				if ( final_register ) {

					/* Add Constant to Constant Table */
					/* ------------------------------ */
					if ((result = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN)

						/* Patch New Constant Identifier */
						/* ----------------------------- */
						tcPutw((sptr + si + 2),result);


					cancel_shadow_register( *registre );
					*registre = final_register;

					}

				return( final_register );

			}
		}	

}


EXAWORD	optimise_constant_arithmetic( sptr , si , offset )
BPTR	sptr;			/* Tcode Code Segment Base 	*/
EXAWORD	si;			/* Current Base Offset		*/
EXAWORD	offset;			/* Next Tcode Sequence Adjuster	*/
{
	EXAWORD	result;
	EXAWORD	tc;
	EXAWORD	final_register;
	EXAWORD	bcdlen;
	BPTR	bcdptr;
	EXAWORD	r;

	r = *(sptr + si + 1);

	bcdptr = (tcGKT + (tcGetw((sptr + si + 2))) + 1);
	bcdlen = *(bcdptr++);

	for ( final_register = 0; ; ) {

		/* Detect possible Constant Operations */
		/* ----------------------------------- */
		switch ( (tc = *(sptr + si + offset )) ) {

			/* Tcodes which permit this optimisation */
			/* ------------------------------------- */
			case _tc_ADC :
			case _tc_SBC :
			case _tc_MLC :
			case _tc_DVC :
			case _tc_MDC :

				/* Perform Calculation to Create New Constant */
				/* ------------------------------------------ */
				if ((result = constant_calculator( (tc & 0x0007),bcdptr, bcdlen, (sptr + si + offset + 2) )) == 0) {

					if ( final_register != 0 ) {

						/* Add Constant to Constant Table */
						/* ------------------------------ */
						if ((result = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN )

							/* Patch New Constant Identifier */
							/* ----------------------------- */
							tcPutw((sptr + si + 2),result);

						}

					return( final_register );

					}

				/* Patch original Register Number */
				/* ------------------------------ */
				final_register = *(sptr + si + offset + 4);

				bcdptr = (BPTR) vconstant;
				bcdlen = 12;

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 5 );

				/* Step over to next Tcode Sequence */
				/* -------------------------------- */
				offset += 5;

				/* Attempt next possible Operation */
				/* ------------------------------- */
				continue;

			/* Since BCD always passes by tables Optimise STORE */
			/* ------------------------------------------------ */
			case _tc_STR :
				*(sptr + si) = (_tc_STC | (*(sptr + si) & TCODE_NEWLINE) );

				if ( final_register != 0 ) 

					/* Add Constant to Constant Table */
					/* ------------------------------ */
					result = create_new_constant(0,12,(BPTR) vconstant );

				else	result = tcGetw((sptr + si + 2));

				if ( result != MOINS_UN ) {
					tcPutw((sptr + si + 1),result);
					result = tcGetw((sptr + si + offset + 2));
					tcPutw((sptr + si + 3),result);
					if ( Options.Tables )
						(void) rellocate_variable( sptr , (si + 3) );	

					information((sptr + si + offset ));
					memset((sptr + si + offset),_tc_NOP, 4);
					return((r | 0x8000));

					}


			default	     : 

				/* Return Current Operation Status */
				/* ------------------------------- */

				if ( final_register != 0 ) {

					/* Add Constant to Constant Table */
					/* ------------------------------ */
					if ((result = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN)

						/* Patch New Constant Identifier */
						/* ----------------------------- */
						tcPutw((sptr + si + 2),result);

					}

				return( final_register );

			}
		}	

}

EXAWORD	integer_sumator( xtc, opcode, xop, yop )
EXAWORD	xtc;
EXAWORD	opcode;
EXAWORD	xop;
EXAWORD	yop;
{
	switch ( xtc ) {
		case _tc_ADI :
			switch ( opcode ) {
				case 0 : return((xop + yop));
				case 1 : return((xop - yop));
				}
			break;
		case _tc_SBI :
			switch ( opcode ) {
				case 0 : return((xop - yop));
				case 1 : return((xop + yop));
				}

		}
	return( 0 );
}

EXAWORD	integer_calculator( opcode, xoperand, yoperand )
EXAWORD	opcode;
EXAWORD	xoperand;
EXAWORD	yoperand;
{

	switch ( opcode ) {
		case 0	:	return((xoperand + yoperand));
		case 1	:	return((xoperand - yoperand));
		case 2	:	return((xoperand * yoperand));
		case 3	:	return((xoperand / yoperand));
		case 4	:	return((xoperand % yoperand));
		case 5	:	return((xoperand & yoperand));
		case 6	:	return((xoperand | yoperand));
		case 7	:	return((xoperand ^ yoperand));
		default :	return( 0 );
		}

}

EXAWORD	optimise_div_mul( sptr, si , offset )
BPTR	sptr;			/* Tcode Code Segment Base 	*/
EXAWORD	si;			/* Current Base Offset		*/
EXAWORD	offset;			/* Next Tcode Sequence Adjuster	*/
{
	EXAWORD	result;
	EXAWORD	tc;
	EXAWORD	final_register;
	BPTR	registre;

 
	registre = (sptr + si + offset - 1);

	for ( final_register = 0; ; ) {

		/* Detect possible Constant Operations */
		/* ----------------------------------- */
		switch ( (tc = *(sptr + si + offset )) ) {

			/* Tcodes which permit this optimisation */
			/* ------------------------------------- */
			case _tc_MLI :
			case _tc_DVI :

				/* Optimise the arithmetic to LDI #R, ( I1 op I2 ) */
				/* ----------------------------------------------- */
				result = integer_calculator((tc & 0x0007), (tcGetw((sptr + si + 2))), (tcGetw((sptr + si + offset + 2))));

				/* Store result and Establish Real Register */
				/* ---------------------------------------- */
				tcPutw((sptr + si + 2),result);

				/* Collect current Result Register */
				/* ------------------------------- */
				final_register = *(sptr + si + offset + 4);

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 5 );

				/* Step over to next Tcode Sequence */
				/* -------------------------------- */
				offset += 5;

				/* Attempt further optimisation */
				/* ---------------------------- */
				continue;

			default	     : 

				/* Return Current Operation Status */
				/* ------------------------------- */
				if ( final_register ) {
					cancel_shadow_register( *registre );
					*registre = final_register;
					}

				return( final_register );

			}
		}	

}

EXAWORD	optimise_add_sub( sptr, si , offset )
BPTR	sptr;			/* Tcode Code Segment Base 	*/
EXAWORD	si;			/* Current Base Offset		*/
EXAWORD	offset;			/* Next Tcode Sequence Adjuster	*/
{
	EXAWORD	result;
	EXAWORD	tc;
	EXAWORD	xtc;
	EXAWORD	final_register;
	EXAWORD	status;
	BPTR	registre;

	xtc      = (EXAWORD) (*(sptr + si) & REMOVE_NEWLINE);

	registre = (sptr + si + offset - 1); status = 0;

	for ( final_register = 0; ; ) {

		/* Detect possible Constant Operations */
		/* ----------------------------------- */
		switch ( (tc = *(sptr + si + offset )) ) {

			/* Tcodes which permit this optimisation */
			/* ------------------------------------- */
			case _tc_ADI :
			case _tc_SBI :

				/* Optimise the arithmetic to LDI #R, ( I1 op I2 ) */
				/* ----------------------------------------------- */
				result = integer_sumator(xtc,(tc & 0x0007), (tcGetw((sptr + si + 2))), (tcGetw((sptr + si + offset + 2))));

				/* Store result and Establish Real Register */
				/* ---------------------------------------- */
				tcPutw((sptr + si + 2),result); status++; 

				/* Collect current Result Register */
				/* ------------------------------- */
				final_register = *(sptr + si + offset + 4);

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 5 );

				/* Step over to next Tcode Sequence */
				/* -------------------------------- */
				offset += 5;

				/* Attempt further optimisation */
				/* ---------------------------- */
				continue;

			case _tc_INC : 

				switch ( xtc ) {
					case _tc_ADI :
						result = ((tcGetw((sptr + si + 2))) + 1);
						break;

					case _tc_SBI :
						result = ((tcGetw((sptr + si + 2))) - 1);
					}
				tcPutw((sptr + si + 2),result); status++;

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 2 );
				
				offset += 2;

				continue;

			case _tc_DEC :

				switch ( xtc ) {
					case _tc_ADI :
						result = ((tcGetw((sptr + si + 2))) - 1);
						break;

					case _tc_SBI :
						result = ((tcGetw((sptr + si + 2))) + 1);
					}

				tcPutw((sptr + si + 2),result); status++;

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 2 );
				offset += 2;

				continue;

			default	     : 

				/* Return Current Operation Status */
				/* ------------------------------- */
				if (( final_register ) || ( status )) {
					cancel_shadow_register( *registre );
					if ( final_register)
						*registre = final_register;
					}
				return( status );

			}
		}	

}

EXAWORD	optimise_integer_arithmetic( sptr , si , offset )
BPTR	sptr;			/* Tcode Code Segment Base 	*/
EXAWORD	si;			/* Current Base Offset		*/
EXAWORD	offset;			/* Next Tcode Sequence Adjuster	*/
{
	EXAWORD	result;
	EXAWORD	tc;
	EXAWORD	final_register;
	EXAWORD	registre;
	
	registre = *(sptr + si + 1);

	for ( final_register = 0; ; ) {

		/* Detect possible Constant Operations */
		/* ----------------------------------- */
		switch ( (tc = *(sptr + si + offset )) ) {

			/* Tcodes which permit this optimisation */
			/* ------------------------------------- */
			case _tc_ADI :
			case _tc_SBI :
			case _tc_MLI :
			case _tc_DVI :
			case _tc_MDI :
			case _tc_ANI :
			case _tc_ORI :
			case _tc_XRI :

				/* Optimise the arithmetic to LDI #R, ( I1 op I2 ) */
				/* ----------------------------------------------- */
				result = integer_calculator((tc & 0x0007), (tcGetw((sptr + si + 2))), (tcGetw((sptr + si + offset + 2))));

				/* Store result and Establish Real Register */
				/* ---------------------------------------- */
				tcPutw((sptr + si + 2),result);

				/* Collect current Result Register */
				/* ------------------------------- */
				final_register = *(sptr + si + offset + 4);

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 5 );

				/* Step over to next Tcode Sequence */
				/* -------------------------------- */
				offset += 5;

				alter_shadow_register(final_register , registre, 0, result );

				/* Attempt further optimisation */
				/* ---------------------------- */
				continue;

			case _tc_INC : 

				result = ((tcGetw((sptr + si + 2))) + 1);
				tcPutw((sptr + si + 2),result);

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 2 );
				
				offset += 2;

				alter_shadow_register(registre , registre, 0, result );
				continue;

			case _tc_DEC :

				result = ((tcGetw((sptr + si + 2))) - 1);
				tcPutw((sptr + si + 2),result);

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 2 );
				offset += 2;

				alter_shadow_register(registre , registre, 0, result );
				continue;

			case _tc_NGR :

				result = ((tcGetw((sptr + si + 2))));
				result = !result;
				tcPutw((sptr + si + 2),result);

				/* Erase Redundant Calculation Sequence */
				/* ------------------------------------ */
				information((sptr + si + offset ));
				memset((sptr + si + offset), _tc_NOP, 2 );
				offset += 2;

				alter_shadow_register(registre , registre, 0, result );
				continue;

			default	     : 

				/* Return Current Operation Status */
				/* ------------------------------- */
				return( final_register );

			}
		}	

}

void	generate_tcode_STI( sptr, si, variable, value, padding)
BPTR	sptr;
EXAWORD	si;
EXAWORD	variable;
EXAWORD	value;
EXAWORD	padding;
{

	/* Generate Substitute Code     */
	/* ---------------------------- */
	/* CLF LEN ResVar, varid (7)  	*/
	/*        becomes	    	*/
	/* STI Varlen , ResVar NOP NOP  */
	/* ----------------------------	*/
	information((sptr + si));
	*(sptr + si) = (BYTE)(_tc_STI | (((EXAWORD) *(sptr + si)) & TCODE_NEWLINE));
	tcPutw( (sptr + si + 1) , value );
	tcPutw( (sptr + si + 3) , variable );
	while ( padding ) {
		*(sptr + si + 5) = (BYTE) _tc_NOP;
		si++;
		padding--;
		}
	return;
}

void	generate_tcode_STC( sptr, si, variable, cvalue, padding )
BPTR	sptr;
EXAWORD	si;
EXAWORD	variable;
EXAWORD	cvalue;
EXAWORD	padding;
{

	/* Generate Substitute Code     */
	/* ---------------------------- */
	information((sptr + si));
	*(sptr + si) = (BYTE)(_tc_STC | (((EXAWORD) *(sptr + si)) & TCODE_NEWLINE));
	tcPutw( (sptr + si + 1) , cvalue );
	tcPutw( (sptr + si + 3) , variable );
	while ( padding ) {
		*(sptr + si + 5) = (BYTE) _tc_NOP;
		si++;
		padding--;
		}
	return;
}

void	generate_tcode_LDI( sptr, si, registre, value, padding, ecart )
BPTR	sptr;
EXAWORD	si;
EXAWORD	registre;
EXAWORD	value;
EXAWORD	padding;
EXAWORD	ecart;
{
				
	/* Generate Substitute Code 	*/
	/* ----------------------------	*/

	/* Check if Operation will be followed by Store */
	/* -------------------------------------------- */
	if ( *(sptr + si + ecart + padding) != _tc_STR ) {

		/* No Store so Perform Operation */
		/* ----------------------------- */
		information((sptr + si));
		*(sptr + si) 	 = (BYTE)(_tc_LDI | (((EXAWORD) *(sptr + si)) & TCODE_NEWLINE));
		*(sptr + si + 1) = (BYTE) registre;	
		tcPutw((sptr + si + 2) , value );	

		}
	else	{
		generate_tcode_STI( sptr, si, (tcGetw((sptr + si  + ecart + padding + 2))), value, (padding + 4));
		padding = 0;
		}
		
	while ( padding ) {
		*(sptr + si + 4) = (BYTE) _tc_NOP;
		padding--;
		si++;
		}
	return;
}

void	generate_tcode_LDC( sptr, si, registre, value, padding, ecart )
BPTR	sptr;
EXAWORD	si;
EXAWORD	registre;
EXAWORD	value;
EXAWORD	padding;
{
				
	/* Generate Substitute Code 	*/
	/* ----------------------------	*/
	/* Check if Operation will be followed by Store */
	/* -------------------------------------------- */
	if ( *(sptr + si + padding + ecart) != _tc_STR ) {

		/* No Store so Perform Operation */
		/* ----------------------------- */
		information((sptr + si));
		*(sptr + si) 	 = (BYTE)(_tc_LDC | (((EXAWORD) *(sptr + si)) & TCODE_NEWLINE));
		*(sptr + si + 1) = (BYTE) registre;	
		tcPutw((sptr + si + 2) , value );	
		}
	else	{
		generate_tcode_STC( sptr, si, (tcGetw((sptr + si  + padding + ecart + 2))), value, (padding + 3));
		padding = 0;
		}

	while ( padding ) {
		*(sptr + si + 4) = (BYTE) _tc_NOP;
		padding--;
		si++;
		}
	return;
}

EXAWORD	zero_second_operand( sptr,si ,registre )
BPTR	sptr;
EXAWORD	si;
{
	/* Detect Operation Type */
	/* --------------------- */
	switch ( (*(sptr + si) & 0x0007) ) {
 
		case 0 :
		case 1 :
		case 6 :
		case 7 : /* SUB,ADD,OR,XOR : Changes Nothing */
			 /* -------------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 redirect_register( *(sptr + si + 3), *(sptr + si + 1) );
			 information((sptr + si));
			 memset((BPTR) (sptr + si), _tc_NOP, 4);
			 return( VRAI );

		case 3 :
		case 4 : if ( Options.Warnings ) {
				LineFeed();
				oputs((BPTR) " * * * Potential Divide/Modulo by ZERO error * * * ");
				LineFeed(); 
				}
			 return( FAUX );

		case 2 :
		case 5 : /* MUL,AND : Gives Zero Result */
			 /* --------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 generate_tcode_LDI(sptr,si,*(sptr + si + 3),0,0,4);
			 return( VRAI );
		}

	return( FAUX );

}

EXAWORD	zero_first_operand( sptr, si )
BPTR	sptr;
EXAWORD	si;
{
	/* Detect Operation Type */
	/* --------------------- */
	switch ( (*(sptr + si) & 0x0007) ) {
 
		case 0 :
		case 1 :
		case 6 :
		case 7 : /* SUB,ADD,OR,XOR : Changes Nothing */
			 /* -------------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 redirect_register( *(sptr + si + 3), *(sptr + si + 2) );
			 information((sptr + si));
			 memset((BPTR) (sptr + si), _tc_NOP, 4);
			 return( VRAI );

		case 2 :
		case 3 :
		case 4 :
		case 5 : /* MUL,AND : Gives Zero Result */
			 /* --------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 generate_tcode_LDI(sptr,si,*(sptr + si + 3),0,0,4);
			 return( VRAI );
		}

	return( FAUX );

}

EXAWORD	zero_second_constant( sptr,si ,registre )
BPTR	sptr;
EXAWORD	si;
{
	/* Detect Operation Type */
	/* --------------------- */
	switch ( (*(sptr + si) & 0x0007) ) {
 
		case 0 :
		case 1 :
		case 6 :
		case 7 : /* SUB,ADD,OR,XOR : Changes Nothing */
			 /* -------------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 redirect_register( *(sptr + si + 3), *(sptr + si + 1) );
			 information((sptr + si));
			 memset((BPTR) (sptr + si), _tc_NOP, 4);
			 return( VRAI );

		case 3 :
		case 4 : if ( Options.Warnings ) {
				LineFeed();
				oputs((BPTR) " * * * Potential Divide/Modulo by ZERO error * * * ");
				LineFeed(); 
				}
			 return( FAUX );

		case 2 :
		case 5 : /* MUL,AND : Gives Zero Result */
			 /* --------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 generate_tcode_LDC(sptr,si,*(sptr + si + 3),0,0,4);
			 return( VRAI );
		}

	return( FAUX );

}

EXAWORD	zero_first_constant( sptr, si )
BPTR	sptr;
EXAWORD	si;
{
	/* Detect Operation Type */
	/* --------------------- */
	switch ( (*(sptr + si) & 0x0007) ) {
 
		case 0 :
		case 1 :
		case 6 :
		case 7 : /* SUB,ADD,OR,XOR : Changes Nothing */
			 /* -------------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 redirect_register( *(sptr + si + 3), *(sptr + si + 2) );
			 information((sptr + si));
			 memset((BPTR) (sptr + si), _tc_NOP, 4);
			 return( VRAI );

		case 2 :
		case 3 :
		case 4 :
		case 5 : /* MUL,AND : Gives Zero Result */
			 /* --------------------------- */
			 cancel_shadow_register( *(sptr + si + 3) );
			 generate_tcode_LDC(sptr,si,*(sptr + si + 3),0,0,4);
			 return( VRAI );
		}

	return( FAUX );

}

EXAWORD	optimise_register_arithmetic( sptr, si )
BPTR	sptr;
EXAWORD	si;
{
	EXAWORD	xop;
	EXAWORD	yop;

	/* Check for Integer 1st Operand */
	/* ----------------------------- */
	switch ((xop = shadow_register_contents( *(sptr + si + 1)) ) ) {

		case _REG_INTEGER :	/* Integer Contents */
					/* ---------------- */

				/* Determine Possible Consequent Actions */
				/* ------------------------------------- */
				switch ((xop = shadow_register_contents( *(sptr + si + 2) ))) {

					case _REG_INTEGER :

						/* Optimisation is Possible : Check for ZERO RVALUE */
						/* ------------------------------------------------ */
						if ((yop = collect_shadow_value(*(sptr + si + 2),0)) == 0)
							return(zero_second_operand( sptr, si ));
						if ((xop = collect_shadow_value(*(sptr + si + 1),0)) == 0)
							return(zero_first_operand( sptr, si ));
						xop = integer_calculator((*(sptr +si) & 0x0007),xop,yop);
						cancel_shadow_register(*(sptr + si + 3));
						generate_tcode_LDI(sptr,si,*(sptr + si + 3),xop,0,4);
						return( VRAI );

					case _REG_CONSTANT :
					case _REG_VARPTR   :
					case _REG_VARIABLE :
					case _REG_REGISTER :

						if ((xop = collect_shadow_value(*(sptr + si + 1),0)) == 0)
							return(zero_first_operand( sptr, si ));
					}

				/* No Optimisation Performed */
				/* ------------------------- */
				return( FAUX );

		case _REG_CONSTANT :	/* Constant Value   */
					/* ---------------- */

				/* Determine Possible Consequent Actions */
				/* ------------------------------------- */
				switch ((xop = shadow_register_contents( *(sptr + si + 2) ))) {

					case _REG_CONSTANT :

						/* Optimisation is Possible : Check for ZERO RVALUE */
						/* ------------------------------------------------ */
						if ((yop = is_null_constant(collect_shadow_value(*(sptr + si + 2),1))) == MOINS_UN)
							return(zero_second_constant( sptr, si ));
						if ((xop = is_null_constant(collect_shadow_value(*(sptr + si + 1),1))) == MOINS_UN)
							return(zero_first_constant( sptr, si ));
						if (( xop != MOINS_UN ) && ( yop != MOINS_UN )) {
							if (constant_calculation((*(sptr +si) & 0x0007),xop,yop) != 0) {
								cancel_shadow_register(*(sptr + si + 3));
								if ((xop = create_new_constant(0,12,(BPTR) vconstant )) != MOINS_UN) {
									generate_tcode_LDC(sptr,si,*(sptr + si + 3),xop,0,4);
									return( VRAI );
									}
								}
							}
						return( FAUX );

					case _REG_INTEGER  :
					case _REG_VARPTR   :
					case _REG_VARIABLE :
					case _REG_REGISTER :

						if ((xop = is_null_constant(collect_shadow_value(*(sptr + si + 1),1))) == 0)
							return(zero_first_operand( sptr, si ));
					}

				/* No Optimisation Performed */
				/* ------------------------- */
				return( FAUX );

		case _REG_VARPTR   :
		case _REG_VARIABLE :	/* REGISTER Contains a VARIABLE */
					/* ---------------------------- */

				switch ( shadow_register_contents( *(sptr + si + 2) ) ) {

					case _REG_INTEGER :

						/* Optimisation is Possible : Check for ZERO RVALUE */
						/* ------------------------------------------------ */
						if ((yop = collect_shadow_value(*(sptr + si + 2),0)) == 0)
							return( zero_second_operand(sptr,si));


					}

				return( FAUX );

		case _REG_REGISTER :	/* Register is an Operation Result */
					/* ------------------------------- */

			switch ((xop = shadow_register_contents( *(sptr + si + 2))) ) {

				case _REG_INTEGER :

					/* Optimisation is Possible : Check for ZERO RVALUE */
					/* ------------------------------------------------ */
					if ((yop = collect_shadow_value(*(sptr + si + 2),0)) == 0)
						return(zero_second_operand(sptr,si));


				}

			return( FAUX );

		}

	return( 0 );

}


/*
 *	T-Code Post Optimiser Functional Cycle
 *	--------------------------------------
 *
 */

EXAWORD	Optimiser( sptr , slen )
BPTR	sptr;
EXAWORD	slen;
{
	EXAWORD	IsFmt;
	EXAWORD	Shadow;
	EXAWORD	ReadZero;
	EXAWORD	Compteur;
	EXAWORD	EscMode;
	EXAWORD	AskMode;
	BPTR	wptr;
	EXAWORD	x,y,z,m;
	EXAWORD	mx,my,mz;
	EXAWORD	ngfcode;
	EXAWORD	mode;
	BPTR	rptr;
	EXAWORD	extra;
	EXAWORD	si,ri;
	EXAWORD	LdiPatch;
	EXAWORD	shadow_result;
	EXAWORD	first_arg;
	EXAWORD	temp_status;
	EXAWORD	tclength;

	/* Watch out for Program Structure Analysis */
	/* ---------------------------------------- */
	if (( Options.Analyse ) && (!(Options.Inline )))
		return( Analyser(sptr, 0,slen ) );

	ReadZero = VRAI; Shadow = Options.Registers;

	if ( Options.Optimise ) {

		/* Initialise Label Manager */
		/* ------------------------ */
		if ( InitLabel( MasterPhase, SegId, PrcId ) != 0 ) 
			return(0);

		ReadZero = FAUX;

		}

#ifdef	AO_LISTFILE

	/* Check for T-Code listing active */
	/* ------------------------------- */
	if (( Options.Liste )  || ( Options.Stats & STAT_CODE )) {
		if ( MasterPhase == 1 )
			SegmentStart( SegId , Options.Compile );
		else	ProcedureStart( PrcId , Options.Compile );
		}

#endif

	if ( Options.Pannel ) {
		if ( MasterPhase == 1 )
			draw_segment( SegId );
		else	draw_procedure( PrcId );
		}

#ifdef	AO_COMPILER

	/* If Compilation active */
	/* --------------------- */
	if ( Options.Compile ) {
		if ( MasterPhase == 1 )
			StartSegment( SegId );
		else	StartProcedure( PrcId );
		}
#endif
	RegisterReset();

	/* Initialise Source and Result Indexs */
	/* ----------------------------------- */
	si = 0; ri = 0;

	/* Check for DATA and Ignore */
	/* ------------------------- */
	if ((x = tcGetw((sptr + slen - WORDSIZE))) != MOINS_UN) {
		extra = (slen - x);
		slen = x;
		}
	else	{
		extra = 0;
		}

	/* Initialise Variables */
	/* -------------------- */
	Compteur = 0; EscMode = 0; x = 0; 
	rptr = sptr; si = 0; ri = 0;

	/* While Not End of Code Segment */
	/* ----------------------------- */
	while ( slen > 0 ) {


		/* Check for End of Code Segment */
		/* ----------------------------- */
		if ( ((EXAWORD) *(sptr + si) ) == 0x00FF ) {

			break;
			}

		if ( Options.Optimise ) {

			/* Add This Adresse to List */
			/* ------------------------ */
			if ( AddLabel( si , ri ) != 0 ) {

				/* Dismantle tree and Return */
				/* ------------------------- */
				FreeLabel(0);	return(0);

				}

			}

		if ( Options.CheckFmt ) {

			/* Check for T-Code Format Strings */
			/* ------------------------------- */
			if (((EXAWORD) *(sptr + si + 1)) != 0x00FE)
				IsFmt = 0;
			else	{
				/* Collect Preceeding Octet 		*/
				/* Presumed to be Format string  Length */
				/* ------------------------------------ */
				x = (((EXAWORD) *(sptr + si)));

				/* Test for not exceeding Current Segment */
				/* -------------------------------------- */
				if ( x >= slen )
					IsFmt = 0;
				else if (((EXAWORD) *(sptr + si + x)) != 0x00FF) 
					IsFmt = 0;
				else if ((*(sptr + si + x + 1) & 0x0080))
					IsFmt = 1;
				else if (*(sptr + si + x + 2) == 0x00FE)
					IsFmt = 1;

				if ( IsFmt ) {
#ifdef	AO_LISTFILE
					/* Allow diss-assembler to see code */
					/* -------------------------------- */
					if ( Options.Liste )
						LabelFormat( sptr , si , Options.Compile );
#endif
					x++;
					tcMove( x );
					continue;
					}
				}
			}


#ifdef	AO_LISTFILE

		/* Check for Liste mode Active */
		/* --------------------------- */
		if (( Options.Liste ) || ( Options.Stats & STAT_CODE )) {

			/* If not an ESC secondary Code */
			/* ---------------------------- */
			if ( EscMode == FAUX ) {

				if (!(Options.Liste))
					temp_status = StreamStatus( 0 );

				/* Dissasemble fully */
				/* ----------------- */
				tclength = TcodeList( sptr , si , Options.Compile );

				if (!(Options.Liste))
					(void) StreamStatus( temp_status );

				si += tclength;
				slen -= tclength;
				continue; 

				}

			}

#endif	/* AO_LISTFILE */
	/* ----------- */

		/* Check for Register optimisations */
		/* -------------------------------- */
		if (( Options.Registers == VRAI ) && (EscMode == FAUX)) {


			if ( Shadow ) {

				/* Allow Register shadowing to see T-Code */
				/* -------------------------------------- */
				if ((ri = register_optimiser(sptr , si, ri)) == 0xFFFF) {

					/* Probably an allocation failure */
					/* ------------------------------ */
					oputs((BPTR) TalkPtr[11] );

					/* Signal Optimisation Error Point */
					/* ------------------------------- */
					OptimiserError( EscMode , sptr , si );
					FreeLabel(0);
					return(0);
				
					}
				}
			Shadow = Options.Registers;
			}


#ifdef	AO_COMPILER

		/* Check for Compile mode active */
		/* ----------------------------- */
		if (( Options.Compile ) && (EscMode == FAUX)) 

			/* Allow compiler to see code */
			/* -------------------------- */
			Compiler( sptr , si );

#endif

/* Select T-Code (New Line Striped) */
/* -------------------------------- */
switch ((((EXAWORD) *(sptr + si)) & REMOVE_NEWLINE)) {

	case _tc_IOF :

		/* Perform IO CYCLE Analysis */
		/* ------------------------- */
		tcMove( 1 );
		AskMode = FAUX;

		while (( *(sptr + si) != (BYTE) 0 ) && (AskMode == FAUX)) {

			switch ((((EXAWORD) *(sptr + si)) & 0x000F)) {

				case _io_SPX  :	
					tcBreak( 1 );

				case _io_ESC  : 
					switch (((EXAWORD) *(sptr + si))) {
						case 0x0010 : 	tcBreak( 1 );
						case 0x0020 :	if ( Options.Optimise ) {
								 	ConvertLabel((sptr + si + 1),(rptr + ri + 1));
									}
								tcBreak( (1+WORDSIZE) );
						case 0x0040 :	tcBreak( 1 );
						default	    :	FreeLabel(0);
								return(0);
						}

				case _io_HOT1 :
				case _io_HOT2 :	if ( Options.Optimise ) {
							ConvertLabel((sptr + si + 1),(rptr + ri + 1));
							}
						tcBreak( (1+WORDSIZE) );	

				case _io_KEY1 :
				case _io_KEY2 :	if ( IOF_REGISTER ) {
							if ( Options.Optimise ) {
								ConvertLabel((sptr + si + 2),(rptr + ri + 2));
								}
							tcBreak( (2+WORDSIZE) );	
							}
						else	{
							if ( IOF_CONSTANT ) {
								if ( Options.Optimise ) {
									ConvertConst(sptr,(si+1));
									Compteur++;
									}
								}
							else	{
								if (Options.Tables)
									if ( IOF_VARIABLE )
										Compteur += rellocate_variable( sptr , (si + 1) );

								}
							if ( Options.Optimise ) {
								ConvertLabel((sptr + si + 1+WORDSIZE),(rptr + ri + 1+WORDSIZE));
								}
							tcBreak( (1+WORDSIZE+WORDSIZE) );	
	 						}

				case _io_ASK  : AskMode = VRAI;
						if ( IOF_REGISTER ) {
							tcBreak( 2 );	
							}
						else	{
							/* Must be a variable !!! */
							/* ---------------------- */
							if (Options.Tables)
								Compteur += rellocate_variable( sptr , (si + 1) );
							tcBreak( 1+WORDSIZE );
	 						}

				case _io_ATBV :
				case _io_BACK :
				case _io_FORG :
				case _io_DEV  :
				case _io_TABC :
				case _io_TABV :
				case _io_TABL :	if ( IOF_REGISTER ) {
							tcBreak( 2 );
							}
						else	{
							if ( IOF_CONSTANT ) {
								if ( Options.Optimise ) {
									ConvertConst(sptr,(si+1));
									Compteur++;
									}
								}
							else	{
								if ( IOF_VARIABLE ) 
									if (Options.Tables)
										Compteur += rellocate_variable( sptr , (si + 1) );
								}
							tcBreak( 1+WORDSIZE );
	 						}

				case _io_PRN  : if ( IOF_REGISTER ) {
							tcBreak( 2 );
							}
						else	{
							if ( IOF_NORMAL ) {
								if ( IOF_CONSTANT ) {
									if ( Options.Optimise ) {
										ConvertConst(sptr,(si+1));
										Compteur++;
										}
									}
								else	{
									if ( IOF_VARIABLE ) 
										if (Options.Tables)
											Compteur += rellocate_variable( sptr , (si + 1) );
									}
								tcBreak( 1+WORDSIZE );
								}
							else	{
								if ((x = convert_to_constant( sptr , (si+1) , rptr , (ri+1) )) != 0 ) {
									si += (x+1);
									slen -= (x+1);
									*(rptr + ri) = (BYTE) (_io_PRN | 0x0020);
									ri += (1+WORDSIZE);
									Compteur++;
									}
								else	{
									/* Handle String in T-Code */
									/* ----------------------- */
									while ( *(sptr + si) != (BYTE) 0 ) { tcMove(1); }
									tcMove(1);
									}
								}
	 						}
						continue;


				case _io_FMT  :

					/* Check for Label Implimented Format */
					/* ---------------------------------- */
					if ( (((EXAWORD) *(sptr + si)) & 0x00F0 ) == 0x0000 ) {

						if ( Options.Optimise ) {

							/* Perform Label Adresse Conversion */
							/* -------------------------------- */
							ConvertLabel((sptr + si + 1),(rptr + ri + 1));
							}

						/* Break to Move */
						/* ------------- */
						tcBreak( (1+WORDSIZE) );
						}
					else	{

						/* Check for T-Code Format */
						/* ----------------------- */
						if (((((EXAWORD) *(sptr + si) ) & 0x00E0 ) >> 5 ) > 3 ) { 
							tcMove(1);
							x = (EXAWORD) *(sptr + si); 
							tcMove(1);
							tcBreak( x );
							}
						else	{
							/* Check for Register */
							/* ------------------ */
							if ( IOF_REGISTER ) {
								tcBreak( 2 );
								}
							else	{
								if ( IOF_CONSTANT ) {
									if ( Options.Optimise ) {
										ConvertConst(sptr,(si+1));
										Compteur++;
										}
									}
								else	{
									/* Must be Variable */
									/* ---------------- */
									if (Options.Tables)
										Compteur += rellocate_variable( sptr , (si + 1) );

									}
								tcBreak( (1+WORDSIZE) );
								}
							}
						}
				}
			tcMove( m );
			}
		if ( AskMode == FAUX ) {
			tcBreak( 1 );
			}
		else	{
			AskMode = FAUX;
			}
		continue;
	
	case _tc_CNV : 	tcBreak((2+WORDSIZE));

	case _tc_OPV :	if ( Options.Optimise ) {
				if ( Options.Tables ) {
					x = (tcGetw( (sptr + si + 1) ));
					if ( x != 0 ) 
						Compteur += rellocate_variable( sptr , (si + 1) );

					}
			 	ConvertLabel((sptr + si + 1+WORDSIZE),(rptr + ri + 1+WORDSIZE));
				}
			tcBreak( 1+(2*WORDSIZE) );

	case _tc_CLF : 

	if (( Options.Optimise )
	&&  ( Options.Constants)) {

		/* Detect Group B CLF functions (Returning Integers) */
		/* ------------------------------------------------- */
		switch ((x = *(sptr + si + 1) )) {

			case _clf_LENDOLLAR :
			case _clf_LEN       :

				if ( CLF_X_REGISTER(2) )
					z = 1;
				else	z = WORDSIZE;

				/* Determine Source Operand Nature */
				/* ------------------------------- */
				if ( CLF_Y_CONSTANT(2) ) {
					if ( x == _clf_LEN )	
						y = ConstantSize((tcGetw((sptr + si + 3 + z))));
					else	y = ConstantUsefulSize((tcGetw((sptr + si + 3 + z))));
					}
				else	{
					if ( CLF_Y_VARIABLE(2) ) {
						if ( x == _clf_LEN )
							y = VariableSize((tcGetw((sptr + si + 3 + z))));
						else	break;
						}
					else	{
						if ( CLF_Y_REGISTER(2) )
							if ((y = RegisterSize(x,*(sptr + si + 3 + z))) == MOINS_UN )
								break;

						}
					}

				/* Check for Register Result */
				/* ------------------------- */
				if ( CLF_X_REGISTER(2) ) {

					/* Get Register ID */
					/* --------------- */
					x = (EXAWORD) *(sptr + si + 3);
	
					if ( Options.Registers )
						cancel_shadow_register( x );
	
					generate_tcode_LDI( sptr, si, x ,y, 2, 4 );
	
					}
				else	{
					/* Get Result Variable ID */
					/* ---------------------- */
					Compteur += rellocate_variable( sptr , (si + 3));
					x = tcGetw((sptr + si + 3));
					generate_tcode_STI( sptr, si, x, y, 2 );
					tcMove( 1 + (2*WORDSIZE) );
					}

				Compteur++;
				continue;

			}

		}

	/* Watch out for FM functions */
	/* -------------------------- */
	switch ( *(sptr + si + 1) ) {

		case 0x005A :	/* VAR = FM((VAR)) */
				/* --------------- */
				Compteur += rellocate_variable( sptr , (si + 2));
				Compteur += rellocate_variable( sptr , (si + 2 + WORDSIZE));
				tcMove( (2+(2*WORDSIZE)) ); continue;

		case 0x006A :	/* VAR = FM((REG)) */
				/* --------------- */
				Compteur += rellocate_variable( sptr , (si + 2));
				tcMove( (3+WORDSIZE) ); continue;

		case 0x007A :	/* VAR = FM((TCD)) */
				/* --------------- */
				Compteur += rellocate_variable( sptr , (si + 2));
				x = (EXAWORD) *(sptr + si + 4);
				x += 5;
				tcMove( x );
				continue;

		}

	case _tc_LDF :

		/* Not Function LEN */
		/* ---------------- */
		tcMove( 2 );
 
		wptr = (rptr + ri );

		/* Advance to Arguament Values */
		/* --------------------------- */
		while ( ( ((EXAWORD) *(sptr + si)) & 0x0001) != 0) { tcMove(1); }
		tcMove(1);

		/* Avoid Arguament Values */
		/* ---------------------- */
		while (1) {
			x = *(wptr++);
			if (( x & 0x0060 ) == 0x0060) {
				tcMove(1);
				}
			else	{
				if (( x & 0x0060 ) == 0x0020) {
					if (( Options.Optimise )
					&& ( Options.Constants)) {
						ConvertConst(sptr,si);
						Compteur++;
						}
					}
				else	{
					if (( x & 0x0060 ) == 0x0040)
						if ( Options.Tables )
							Compteur += rellocate_variable( sptr , si );
						
					}
				tcMove(2);
				}
			if (( x & 0x0010 ) == 0 ) { break; }	
			if (( x & 0x0006 ) == 0x0006) {
				tcMove(1);
				}
			else	{
				if (( x & 0x0006 ) == 0x0002) {
					if (( Options.Optimise )
					&&  ( Options.Constants)) {
						ConvertConst(sptr,si);
						Compteur++;
						}
					}
				else	{
					if (( x & 0x0006 ) == 0x0004)
						if ( Options.Tables )
							Compteur += rellocate_variable( sptr , si );
						
					}
				tcMove(2);
				}
			if (( x & 1 ) == 0 ) { break; }	
			}
		continue;
			

		/*	1 Byte T-Code Structures 	*/
		/*	------------------------	*/

	case _tc_ESC : EscMode = VRAI; tcBreak( 1 );

	case _tc_SGN :

		if ( EscMode == FAUX ) {
			tcBreak( 1 );
			}
		else	{
			/* ESC SGV */
			/* ------- */
			EscMode = FAUX;
			Compteur += rellocate_variable( sptr , (si + 1) );
			tcBreak( 3 );
			}

	case _tc_RAZ :
	case _tc_NEW :	tcBreak( 1 );

	/*	All NOP TCodes are Extracted 	*/
	/* 	----------------------------	*/
	case _tc_NOP :	if ( Options.Optimise ) {
				information((sptr + si));
				Compteur++; 
				si++; slen--; 
				continue;
				}

			tcBreak ( 1 );
				
	case _tc_OEP :
		if ( EscMode != FAUX ) {
			/* _tc_ESC _tc_SGI or _tc_SGR */
			/* -------------------------- */
			EscMode = FAUX;
			tcBreak( 2 );
			}
		tcBreak ( 1 );


	case _tc_ERA :	/* Dissable Error Trap	*/
		if ( EscMode != FAUX ) {
			/* _tc_ESC _tc_RGT #REG       */
			/* -------------------------- */
			EscMode = FAUX;
			tcBreak( 2 );
			}

	case _tc_RES :	/* Resume after Error	*/
	case _tc_RET :	/* Return after Gosub	*/


		tcBreak ( 1 );

		/* 	2 Byte T-Code Structures	*/
		/*	------------------------	*/

	case _tc_DTR :
			ReadZero = VRAI;
	case _tc_INC :
	case _tc_DEC :
	case _tc_INX :
	case _tc_DEX :
	case _tc_DAX : 
	case _tc_PSH :
	case _tc_POP :
		tcBreak( 2 );

	case _tc_NGR :
		if ( EscMode )
			EscMode = FAUX;
		tcBreak( 2 );

	case _tc_ANX :

		if ( EscMode ) {
			/* ESC KILL */

			EscMode = FAUX;
			switch ((((EXAWORD) *(sptr + si+1)) & 0x0060)) {
				case 0x0060 : x = 1; break;
				case 0x0040 : 
					x = 2;
					if ( Options.Tables )
						Compteur += rellocate_variable( sptr , (si + 2) );	
					break;
				case 0x0020 : 
					x = 2;
					if ( Options.Optimise ) {
						ConvertConst(sptr,(si+2));
						Compteur++;
						}
					break;
				case 0x0000 : x = 2;
				}
			tcBreak( (2 +x) );

			}
		else	{
			tcBreak( 2 );
			}

		/*	3 Byte T-Code Structures	*/
		/* 	------------------------	*/

	case _tc_JMI :	/* Jump to Immedaite Adresse		*/

		if ( Options.Optimise ) {

			/* Perform Label Linkage */
			/* --------------------- */
			while (JumpLinkage(sptr,si,rptr,ri,1) != 0) { Compteur++; }

			/* Watch out for NOP's */
			/* ------------------- */
			if ( *(sptr + si) == _tc_NOP ) { 
				Compteur++;
				continue;
				}
	
			/* Check for and Strip NewLine flag */
			/* --------------------------------- */
			if ((((EXAWORD) *(sptr + si)) & TCODE_NEWLINE) != 0) {

				/* Ensure not Jump Here : Used for Timer Work */
				/* ------------------------------------------ */
				if ( ri != (tcGetw((sptr + si + 1)))) {
					*(sptr + si) = (BYTE) _tc_JMI;
					Compteur++;
					}
				}

			}

		/* Transfer to Result Zone */
		/* ----------------------- */
		tcBreak( 3 );

	case _tc_GSB :	/* Gosub local to Segment or Procedure	*/ 

		/*
		 *	if ((((EXAWORD) *(sptr + si)) & TCODE_NEWLINE) != 0) {
		 *		*(sptr + si) = (BYTE) _tc_GSB;
		 *		Compteur++;
		 *		}
		 */

		if ( Options.Optimise ) {
			ConvertLabel((sptr + si + 1),(rptr + ri + 1));
			}

		tcBreak( 3 );

	case _tc_REQ :	/* Ressume at Etiquette			*/

		/*	if ((((EXAWORD) *(sptr + si)) & TCODE_NEWLINE) != 0) {
		 *		*(sptr + si) = (BYTE) _tc_REQ;
		 *		Compteur++;
		 *		}
		 */

		if ( Options.Optimise ) {
			ConvertLabel((sptr + si + 1),(rptr + ri + 1));
			}
		tcBreak( 3 );
 
	case _tc_LDR :	/* Load Register from Register		*/
	case _tc_AXR :	/* Load Additional index from Register 	*/
	case _tc_LXR :	/* Load Primary index from Register	*/

		tcBreak( 3 );

	case _tc_DTV :	/* Load Variable from Segment Data zone	*/
		if ( EscMode == VRAI ) {
			EscMode = FAUX;
			/* ESC ETS : END.SEG */
			/* ----------------- */
			tcBreak( 1 );
			}
		ReadZero = VRAI;

	case _tc_NGV :	/* Negate Variable			*/

		if ( Options.Tables )
			Compteur += rellocate_variable( sptr , (si + 1) );

		tcBreak( 3 );

	case _tc_JMV :	/* Jump to Adresse in Variable		*/
			/* Or Jump Register indexed Table	*/

		if (EscMode == FAUX) {
			if ( Options.Tables )
				Compteur += rellocate_variable( sptr , (si + 1) );	
			tcBreak( 3 );
			}
		else	{
			/* _tc_ESC _tc_JMT */
			/* --------------- */
			EscMode = FAUX;
			tcMove( 2 );
			x = (tcGetw( (sptr + si )));

			if ( Options.Optimise ) {
				for (y = 0; y < x; y++ ) {
					ConvertLabel((sptr + si + 2 + (y * 2)),(rptr + ri + 2 + (y * 2)));
					}
				}

			x = ((x + 1) * 2);
			tcBreak( x );
			}

	case _tc_JMR :	/* Jump to Adresse in Register		*/
			/* or Gosub Register indexed Table	*/

		if (EscMode == FAUX) {
			tcBreak( 2 );			
			}
		else	{
			/* _tc_ESC _tc_GST */
			/* --------------- */
			EscMode = FAUX;
			tcMove(2);
			x = (tcGetw( (sptr + si) ));

			if ( Options.Optimise ) {
				for (y = 0; y < x; y++ ) {
					ConvertLabel((sptr + si + 2 + (y * 2)),(rptr + ri + 2 + (y * 2)));
					}
				}

			x = ((x + 1) * 2);
			tcBreak( x );
			}

		/*	4 Byte T-Code Structures	*/
		/* 	------------------------	*/
	case _tc_GIS :	/* Integer store to GDS Offset		*/ 
	case _tc_GIL :	/* Integer load from GDS offset		*/
	case _tc_LIS :	/* Integer store to LDS Offset		*/
	case _tc_LIL :	/* Integer load from LDS offset		*/

		/* Check for Escape Mode for These 4 */
		/* --------------------------------- */
		if ( EscMode == FAUX ) {
			tcBreak( 4 );
			}
		else	{
			/* ESC PAUSE */
			/* --------- */
			EscMode = FAUX;

			/* Check for PAUSE REGISTER */
			/* ------------------------ */
			if ((((EXAWORD) *(sptr + si)) & 0x0060) == 0x0060) {
				tcBreak( 2 );
				}
			else	{
				if ((((EXAWORD) *(sptr + si)) & 0x0060) == 0x0020) {
					if ( Options.Optimise ) {
						ConvertConst(sptr,(si+1));
						Compteur++;
						}
					}
				else	{
					if ((((EXAWORD) *(sptr + si)) & 0x0060) == 0x0040) 
						if ( Options.Tables )
							Compteur += rellocate_variable( sptr ,(si + 1));
					}
				tcBreak( 3 );
				}
			}

	/* --------------------------------------------------	*/
	/* _tc_LDC 	:	 Load Register with Constant 	*/
	/* ------------------------------------------------- 	*/
	/* This Tcode may be followed by Constant Calculations	*/
	/* when the constant type is a BCD constant. These BCD  */
	/* BCD calculations are costly to execution time and    */
	/* must be removed wherever possible			*/
	/* --------------------------------------------------	*/
	case _tc_LDC :	if (( Options.Optimise ) 
			&&  ( Options.Constants))	{

				/* Check for BCD type Constant */
				/* --------------------------- */
				if ( *( tcGKT + (tcGetw((sptr + si + 2))) ) == 0 ) {

					/* Allow possible Constant Folding */
					/* ------------------------------- */
					if ((x = optimise_constant_arithmetic( sptr , si, 4 )) != 0) {

						if (!( x  & ISLOCAL) ) {
							if (( Options.Registers ) && (!(ForNextFlag)))  
								alter_shadow_register( x , *(sptr + si + 1), 1, (tcGetw((sptr + si + 2))) );
							else	*(sptr + si + 1) = x;
							ConvertConst(sptr,(si+2));
							Compteur++;
							tcBreak( 4 );
							}
						else	{
							cancel_shadow_register((x & TOGLOBAL));
							ConvertConst(sptr,(si+1));
							Compteur++;
							tcBreak( 5 );
							}
						}
					}
				/* Perform Constant Identifier Conversion */
				/* -------------------------------------- */
				ConvertConst(sptr,(si+2));
				Compteur++;
				}

			tcBreak( 4 );

	case _tc_LDI :
		if ( EscMode ) {
			/* ESC SPAWN */

			EscMode = FAUX;
			switch ((((EXAWORD) *(sptr + si+1)) & 0x0060)) {
				case 0x0060 : x = 1; break;
				case 0x0040 : 
					x = 2;
					if ( Options.Tables )
						Compteur += rellocate_variable( sptr , (si + 4) );	
					break;
				case 0x0020 : 
					x = 2;
					if ( Options.Optimise ) {
						ConvertConst(sptr,(si+4));
						Compteur++;
						}
					break;
				case 0x0000 : x = 2;
				}
			if ( Options.Optimise ) {
				ConvertLabel((sptr + si + 2),(rptr + ri + 2));
				}
			tcBreak( (4 +x) );

			}
		else	{
			if ( Options.Optimise ) {
				if ((x = optimise_integer_arithmetic( sptr , si , 4 )) != 0) {
					if (( Options.Registers ) && (!(ForNextFlag))) 
						x++;
				/*	alter_shadow_register( x , *(sptr + si + 1), 0, (tcGetw((sptr + si + 2))) ); */
					else	*(sptr + si + 1) = x;
					}
				}

			tcBreak( 4 );
			}

	case _tc_LXC :
	case _tc_AXC :	if ( Options.Optimise ) {
				ConvertConst(sptr,(si+2));
				Compteur++;
				}
			tcBreak(4);

	case _tc_ADR :
	case _tc_SBR :
	case _tc_MLR :
	case _tc_DVR :
	case _tc_MDR :
	case _tc_ANR :
	case _tc_ORR :
	case _tc_XOR :	if (( Options.Optimise ) && ( Options.Registers )) 
				if (optimise_register_arithmetic( sptr, si ))
					continue;


	case _tc_LXI :
	case _tc_AXI :

		tcBreak( 4 );

	case _tc_VPT :

		if ( EscMode == VRAI ) {

			EscMode = FAUX;
		
			/* ESC ETP : END.PROC */
			/* ------------------ */
			tcBreak( 1 );
			}

		if ( Options.Optimise ) {

			/* Check for LDV used on BCD or String */
			/* ----------------------------------- */
			if (((x = (Descriptor((tcGetw((sptr + si + 2 ))))))  & 0x7F63) == 3 ) {

				/* Test Comparison Follows */
				/* ----------------------- */
				if ( ((( *(sptr + si + 4) ) & tc_CMP_JMP ) == tc_CMP_JMP ) 
					|| ( *(sptr + si + 4) == _tc_CLF )) {

					/* Test for 1 Byte String */
					/* ---------------------- */
					if ( VariableSize((tcGetw((sptr + si + 2 )) )) == 1 ){

						if (( x = convert_compare_jumps(sptr,(si + 4),*(sptr + si + 1),0)) != 0 ) {

							/* Check for Current Optimisation State allows code expansion */
							/* ---------------------------------------------------------- */
							if (( ri + 5 ) <= si ) {

								/* Adjust Optimisation Counter */
								/* --------------------------- */
								Compteur += x;

								/* Convert to : GCL : J??I : */
								/* ------------------------- */
								x = AdresseVarb((tcGetw((sptr + si + 2))));

								/* Convert LDV / VPT en GCL/LCL */
								/* ---------------------------- */
								if ( (tcGetw((sptr + si + 2))) & IS_LOCALE ) 
									*(rptr + ri) = (_tc_LCL | ( *(sptr + si) & TCODE_NEWLINE ));
								else	*(rptr + ri) = (_tc_GCL | ( *(sptr + si) & TCODE_NEWLINE )); 

								/* Store Destination Register identity */
								/* ----------------------------------- */
								*(rptr + ri + 1) = *(sptr + si + 1);

								/* Store memory offset */
								/* ------------------- */
								tcPutw((rptr + ri + 2),x);

								/* Convert Signed DIEZE to Unsigned DIEZE AND R,/00FF,R */
								/* ---------------------------------------------------- */
								*(rptr + ri + 4) = _tc_ANI; 
								*(rptr + ri + 5) = *(sptr + si + 1);
								tcPutw((rptr + ri + 6),0x00FF);
								*(rptr + ri + 8) = *(sptr + si + 1);

								/* Adjust Source and destination controllers */
								/* ----------------------------------------- */
								si += 4; slen -= 4; ri += 9;

								/* Remove Tcode Pattern Recovery Information */
								/* ----------------------------------------- */
								perform_recovery((BPTR) 0 );

								/* And Continue */
								/* ------------ */
								continue;
								}
							}
						perform_recovery((BPTR) sptr );
						}
					}
				}
			}

		/* Check for and Perform Possible Variable Rellocation */
		/* --------------------------------------------------- */
		if ( Options.Tables )
			Compteur += rellocate_variable( sptr , (si + 2) );	

		/* Transfer VPT expression to Result Zone */
		/* -------------------------------------- */
		tcBreak( 4 );

	case _tc_LXV :
	case _tc_AXV :
	case _tc_STR :
		if ( Options.Tables )
			Compteur += rellocate_variable( sptr , (si + 2) );	
		tcBreak( 4 );

		/* Optimisation possible : LDV => VPT */
		/* ---------------------------------- */

	case _tc_LDV :

		if ( Options.Optimise ) {

			/* Check for LDV used on BCD or String */
			/* ----------------------------------- */
			if (((x = (Descriptor((tcGetw((sptr + si + 2 ))))))  & 0x0003) > 1 ) {


				/* Transform LDV en VPT */
				/* -------------------- */
				*(sptr + si) = (BYTE) (_tc_VPT | (((EXAWORD) *(sptr + si)) & TCODE_NEWLINE));
				Compteur++;

				/* Note Variable Relocation Performed by VPT */
				/* ----------------------------------------- */
				Shadow = FAUX;
				continue;

				}
			else	{
				/* Check for GCL LCL GIL LIL possible */
				/* ---------------------------------- */
				if ( IntegerLoad( (BPTR) (sptr + si) ) == VRAI) {
					Compteur++;
					}
				else	{
					if ( Options.Tables )
						Compteur += rellocate_variable( sptr , (si + 2) );
					}
				}
			}

		tcBreak( 4 );

		/*	5 Byte T-Code Structures	*/
		/* 	------------------------	*/

	case _tc_JEQR :
	case _tc_JNER :
	case _tc_JLSR :
	case _tc_JGRR :
	case _tc_JLER :
	case _tc_JGER :
	case _tc_JINR :
	case _tc_JNIR :
			if ( Options.Optimise ) {

				/* Avoid T-Code Overspill */
				/* ---------------------- */
				if ( slen > 7 ) {	
					SelectCase( sptr , si , 3 );
					}

				/* Perform Jump Linkage */
				/* -------------------- */
				while (JumpLinkage(sptr,si,rptr,ri,3) != 0) { Compteur++; }

				}

			/* Copy the Result */
			/* --------------- */
			tcBreak( 5 );

	/* ERROR HANDLERS */
	/* -------------- */
	case _tc_OER :

		if ( Options.Optimise ) {
			ConvertLabel((sptr + si + 2),(rptr + ri + 2));
			}
		tcBreak( 4 );


	case _tc_OEO :

		if ( EscMode != FAUX ) {
			/* _tc_ESC _tc_SGI or _tc_SGR */
			/* -------------------------- */
			EscMode = FAUX;
			tcBreak( 2 );
			}

	case _tc_OLE :
	case _tc_OEV :

		if ( Options.Optimise ) {
			if ( Options.Tables )
				Compteur += rellocate_variable( sptr , (si + 1) );
			ConvertLabel((sptr + si + 3),(rptr + ri + 3));
			}
		tcBreak( 5 );

	case _tc_ADC :

		if ( EscMode == VRAI ) {
			
			EscMode = FAUX;

			/* ESC RTI */
			/* ------- */
			tcBreak( 3 );

			}

	case _tc_SBC :	if (( Options.Optimise )
			&&  ( Options.Constants)) {

				/* Check for BCD type Constant */
				/* --------------------------- */
				if ( *( tcGKT + (tcGetw((sptr + si + 2))) ) == 0 )

					/* Allow possible Constant Folding */
					/* ------------------------------- */
					if ( optimise_constant_add_sub( sptr , si, 5 ) != 0)
						continue;

				/* Perform Constant Identifier Conversion */
				/* -------------------------------------- */
				ConvertConst(sptr,(si+2));
				Compteur++;
				}

			tcBreak( 5 );

	case _tc_MLC :	if (( Options.Optimise )
			&&  ( Options.Constants)) {

				/* Check for BCD type Constant */
				/* --------------------------- */
				if ( *( tcGKT + (tcGetw((sptr + si + 2))) ) == 0 )

					/* Allow possible Constant Folding */
					/* ------------------------------- */
					if ( optimise_constant_div_mul( sptr , si, 5 ) != 0)
						continue;


				/* Perform Constant Identifier Conversion */
				/* -------------------------------------- */
				ConvertConst(sptr,(si+2));
				Compteur++;
				}

			tcBreak( 5 );


	case _tc_ORC :	if ( EscMode == VRAI ) {
			
				EscMode = FAUX;

				/* ESC RTR */
				/* ------- */
				tcBreak( 2 );

				}

	case _tc_MDC :	if ( EscMode == VRAI ) {
			
				EscMode = FAUX;

				if (( Options.Optimise ) 
				&&  ( Options.Tables ))
					Compteur += rellocate_variable( sptr , (si + 1) );

				/* ESC RTV */
				/* ------- */
				tcBreak( 3 );

			}

	case _tc_DVC :
	case _tc_ANC :
	case _tc_XRC :	if (( Options.Optimise )
			&&  ( Options.Constants)) {
				ConvertConst(sptr,(si+2));
				Compteur++;
				}
			tcBreak( 5 );

	case _tc_ADI :
	case _tc_SBI :

		 if ( Options.Optimise )
			if ( optimise_add_sub(sptr, si, 5) != 0 ) 
				continue;

		tcBreak( 5 );

	case _tc_MLI :

		 if ( Options.Optimise ) 
			if ( optimise_div_mul(sptr, si, 5) != 0 ) 
				continue;

		tcBreak( 5 );

	case _tc_DVI :
	case _tc_MDI :
	case _tc_ANI :
	case _tc_ORI :
 	case _tc_XRI :
			tcBreak( 5 );
	case _tc_ADV :
	case _tc_SBV :
	case _tc_MLV :
	case _tc_DVV :
	case _tc_MDV :
	case _tc_ANV :
	case _tc_ORV :
	case _tc_XRV :
			if ( Options.Tables )
				Compteur += rellocate_variable( sptr , (si + 2) );
			tcBreak( 5 );

	case _tc_STV :	if ( Options.Tables ) {
				Compteur += rellocate_variable( sptr , (si + 1) );
				Compteur += rellocate_variable( sptr , (si + 3) );
				}
			tcBreak( 5 );
	case _tc_GWS :
	case _tc_LWS :	tcBreak( 5 );

	case _tc_STI :	if ( optimise_gws_lws( (sptr+ si) ) == 0 )
				if ( Options.Tables )
					Compteur += rellocate_variable( sptr , (si + 3) );

			tcBreak( 5 );

	case _tc_STC :	if ( Options.Optimise ) {
				ConvertConst(sptr,(si+1));
				Compteur++;
				}
			if ( Options.Tables ) {
				Compteur += rellocate_variable( sptr , (si + 3) );
				}
			tcBreak( 5 );
#ifdef	OLD_TCODE
	case _tc_CVR :
			if ( EscMode == VRAI ) {

				EscMode = FAUX;
				/* ESC SGW HB LB */
				/* ------------- */
				tcBreak( 3 );
				}
#endif
	case _tc_TIM :

		/* Determine TIMER Function */ 
		/* ------------------------ */
		switch (((EXAWORD) *(sptr + si + 1)) & 0x000F ) {
			case 1 :
			case 2 : if ((((EXAWORD) *(sptr + si + 1) ) & 0x0060) == 0x0060) {
					/* Register Contains Delay */
					/* ----------------------- */
					if ( Options.Optimise ) {
						ConvertLabel((sptr + si + 3),(rptr + ri + 3));
						}
					tcMove(5);
					continue;
					}
				 else	{
					if ((((EXAWORD) *(sptr + si + 1) ) & 0x0060) == 0x0040) {
						if ( Options.Tables )
							Compteur += rellocate_variable( sptr , (si + 2) );
						}
					else	{
						if ((((EXAWORD) *(sptr + si + 1) ) & 0x0060) == 0x0020) {
							Compteur += ConvertConst( sptr , (si + 2) );
							}
						}					
	
					/* Variable Contains Delay */
					/* ----------------------- */
					if ( Options.Optimise ) {
						ConvertLabel((sptr + si + 4),(rptr + ri + 4));
						}
					tcMove(6);
					continue;
					}
			case 0 : tcMove(2);
			}
		continue;

	case _tc_WHN :

		switch ( *(sptr + si +1) ) {
			case _ec_DCL   : if ( Options.Optimise ) {
						ConvertLabel((sptr + si + 2),(rptr + ri + 2));
						}
					 tcMove(4);
					 continue;
			case _ec_STOP  :
			case _ec_RAZ   :
			case _ec_START :
			case _ec_FAUX  :
			case _ec_HALT  : tcMove(2);
			default	       :
				if ( *(sptr + si +1) & _ec_EXTERN ) {
					switch ( ( *(sptr + si +1) & 0x003F) ) {
						case _ec_GOTO  :
						case _ec_GOSUB : 
							if ( Options.Optimise ) {
								ConvertLabel((sptr + si + 2),(rptr + ri + 2));
								}
						case _ec_CALLI :
						case _ec_CALLV :
							tcMove(4); continue;
						case _ec_RAZ   : 
							tcMove(2); continue;
						}		
					}
			}
		continue;

		/*	6 Byte T-Code Structures	*/
		/* 	------------------------	*/

	case _tc_JEQC :
	case _tc_JNEC :
	case _tc_JLSC :
	case _tc_JGRC :
	case _tc_JLEC :
	case _tc_JGEC :
	case _tc_JINC :
	case _tc_JNIC : if (( Options.Optimise )
			&&  ( Options.Constants)) {
				ConvertConst(sptr,(si+2));
				Compteur++;
				}
			goto common_compare;

	case _tc_JEQV :
	case _tc_JNEV :
	case _tc_JLSV :
	case _tc_JGRV :
	case _tc_JLEV :
	case _tc_JGEV :
	case _tc_JINV :
	case _tc_JNIV :
			if ( Options.Tables )
				Compteur += rellocate_variable( sptr , (si + 2) );
			goto common_compare;

	case _tc_JEQI :
	case _tc_JNEI :
	case _tc_JLSI :
	case _tc_JGRI :
	case _tc_JLEI :
	case _tc_JGEI :


common_compare:		 if ( Options.Optimise ) {

				/* Avoid T-Code Overspill */
				/* ---------------------- */
				if ( slen > 7 ) {	

					/* Test for a Select Case Optimisation */
					/* ----------------------------------- */
					SelectCase( sptr , si , 4 );
					}

				/* Perform Jump Linkage */
				/* -------------------- */
				while (JumpLinkage(sptr,si,rptr,ri,4) != 0 ) { Compteur++; }

				}

			/* Copy the Result */
			/* --------------- */
			tcBreak( 6 );

		/* 	Redefined ESC / NORMAL TABLES	*/
		/*	-----------------------------	*/

	case _tc_GCS :	/* RTP */ 
	case _tc_GCL :	/* RTS */
	case _tc_LCS :	/* STP */

				if ( EscMode == FAUX ) {
					tcBreak( 4 );
					}
				else	{
					EscMode = FAUX;

					if ( Options.Optimise ) {

						if (( *(sptr + si) == _tc_RTS )
						&&  ( (*(sptr + si + 1) & 0x007F) == _tc_ESC )
						&&  ( *(sptr + si + 2) == _tc_STP )) {
							/* The non new line Stop will not be reached */
							/* ----------------------------------------- */
							*(sptr + si + 1) = _tc_NOP;
							*(sptr + si + 2) = _tc_NOP;
							}
						else	{
							/* Check for Optimisation of EXIT, EXIT etc */
							/* ---------------------------------------- */
							if ((( *(sptr + si + 1) & REMOVE_NEWLINE ) == _tc_ESC ) && ( *(sptr + si + 2) == *( sptr + si))) {
								ri--; 
								si--; slen++;
								information((sptr + si));
								*(sptr + si) = _tc_NOP;
								*(sptr + si + 1) = _tc_NOP;
								continue;
								}
							}
						}

					tcMove(1);
					}
				continue;

	case _tc_LDE :
		if ( EscMode == VRAI ) {
			/* ESC LDE ie ESC SGW */
			/* ------------------ */
			EscMode = FAUX;
			tcBreak( 3 );
			}
		/* True LDE */
		EscMode = VRAI;

	case _tc_LCL :

		if ( EscMode == FAUX ) {
			tcBreak( 4 );
			}
		else	{
			/* _tc_ESC _tc_CLP */
			/* --------------- */
			EscMode = FAUX;
			tcMove(1);
			wptr = (rptr + ri);

			/* Advance to Arguament Values */
			/* --------------------------- */
			while ( ( ((EXAWORD) *(sptr + si)) & 0x0001) != 0) { 
				tcMove(1);
				}

			tcMove(1);

			/* Avoid Arguament Values */
			/* ---------------------- */
			first_arg = 1;
			while (1) {
				x = *(wptr++);

				if ( first_arg ) {
					if (( x & 0x0060 ) == 0 )
						procedure_usage( ( sptr + si ) ); 
					else	keep_procedures = VRAI;
					first_arg = 0;
					}

				if (( x & 0x0060 ) == 0x0060) {
					tcMove(1);
					}
				else	{
					if (( x & 0x0060 ) == 0x0020) {
					 	if ( Options.Optimise ) {
							ConvertConst(sptr,si);
							Compteur++;
							}
						}
					else	{
						if (( x & 0x0060 ) == 0x0040)
							if ( Options.Tables )
								Compteur += rellocate_variable( sptr , si );
						}
					tcMove(2);
					}
				if (( x & 0x0010 ) == 0 ) { break; }	
				if (( x & 0x0006 ) == 0x0006) {
					tcMove(1);
					}
				else	{
					if (( x & 0x0006 ) == 0x0002) {
					 	if ( Options.Optimise ) {
							ConvertConst(sptr,si);
							Compteur++;
							}
						}
					else	{
						if (( x & 0x0006 ) == 0x0004)
							if ( Options.Tables )
								Compteur += rellocate_variable( sptr , si );
						}
					tcMove(2);
					}
				if (( x & 1 ) == 0 ) { break; }	
				}

			}
		continue;

	case _tc_NGF :	/* File access functions NGF SF etc	*/

		/* Copy _tc_NGF to Result */
		/* ---------------------- */
		tcMove(1);

		/* Collect NGF Function Code */
		/* ------------------------- */
		ngfcode = (EXAWORD) *(sptr + si); 
		
		/* and copy to Result */
		/* ------------------ */
		tcMove(1);

		/* Advance to Arguament Values */
		/* --------------------------- */

		wptr = (rptr + ri);

		while ( ( ((EXAWORD) *(sptr + si )) & 0x0001) != 0) { 
			tcMove(1);
			}
		tcMove(1);

		/* Check for Local Error Trapping */
		/* ------------------------------ */
		if ((((EXAWORD) *wptr ) & 0x0080) != 0x0000) {

		 	if ( Options.Optimise ) {
				/* Perform Label Conversion */
				/* ------------------------ */
				ConvertLabel((sptr + si),(rptr + ri));
				}

			/* Check for Register Return */
			/* ------------------------- */
			if ((((EXAWORD) *wptr ) & 0x0060) == 0x0060) {
				tcMove(3);
				}
			else	{
				if ((((EXAWORD) *wptr ) & 0x0060 ) == 0x0040)
					if ( Options.Tables )
						Compteur += rellocate_variable( sptr , (si + 2) );
				tcMove(4);
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
				tcMove(1);
				}
			else	{
				if ((((EXAWORD) *wptr ) & 0x0060) == 0x0020) {
				 	if ( Options.Optimise ) {
						ConvertConst(sptr,si);
						Compteur++;
						}
					}
				else	{
					if ((((EXAWORD) *wptr ) & 0x0060) == 0x0040)
						if ( Options.Tables )
							Compteur += rellocate_variable( sptr , si );
					}
				tcMove(2);
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
				tcMove(1);
				}
			else	{
				if ((((EXAWORD) *wptr ) & 0x0006) == 0x0002) {
				 	if ( Options.Optimise ) {
						ConvertConst(sptr,si);
						Compteur++;
						}
					}
				else	{
					if ((((EXAWORD) *wptr ) & 0x0006) == 0x0004)
						if ( Options.Tables )
							Compteur += rellocate_variable( sptr , si );
					}
				tcMove(2);
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

				tcMove(1);
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
					while ( *(sptr + si) != (BYTE) 0 ) {
						tcMove(1);
						}
					tcMove(1);
					}
				else	{ 
					if ((((EXAWORD) *wptr) & 0x0060) == 0x0060) {

						/* Register ID in Tcode */
						/* -------------------- */
						tcMove(1);
						}
					else	{
						if ((((EXAWORD) *wptr ) & 0x0060) == 0x0020) {
						 	if ( Options.Optimise ) {
								ConvertConst(sptr,si);
								Compteur++;
								}
							}
						else	{
							if ((((EXAWORD) *wptr ) & 0x0060) == 0x0040)
								if ( Options.Tables )
									Compteur += rellocate_variable( sptr , si );
							}
						/* Variable or Constant */
						/* -------------------- */
						tcMove(2);
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
					while ( *(sptr + si) != (BYTE) 0 ) {
						tcMove(1);
						}
					tcMove(1);
					}
				else	{ 

					/* Register ID in Tcode */
					/* -------------------- */
					if ((((EXAWORD) *wptr) & 0x0006) == 0x0006) {
						tcMove(1);
						}
					else	{
						if ((((EXAWORD) *wptr ) & 0x0006) == 0x0002) {
						 	if ( Options.Optimise ) {
								ConvertConst(sptr,si);
								Compteur++;
								}
							}
						else	{
							if ((((EXAWORD) *wptr ) & 0x0006) == 0x0004)
								if ( Options.Tables )
									Compteur += rellocate_variable( sptr , si );
							}

						/* Variable or Constant ID */
						/* ----------------------- */
						tcMove(2);
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
		continue;

	/*	UnKnown T-Code Structures	*/
	/* 	-------------------------	*/
	default	     :	LineFeed();
			OptimiserError( EscMode , sptr , si );
			FreeLabel(0);
			return(0);

		}
	/* Break Point from Main Switch */
	/* ---------------------------- */
	tcMove( m );

	}

	if ( Options.Registers == VRAI )

		/* Clear out register shadowing */
		/* ---------------------------- */
		reset_shadower(sptr, 0xFFFF );

	/* Calculate Size Change */
	/* --------------------- */ 
	y = (si - ri);

	/* Transfer OutStanding Data */
	/* ------------------------- */
	if ( extra != 0 ) {
		if ( ReadZero ) {

#ifdef	AO_LISTFILE
			if ( Options.Liste )
				data_list_file( sptr , si, extra, Options.Compile );
#endif

			x = ri;
			tcMove( extra );
			tcPutw( (rptr + ri - 2)  , x );
			}
		else	{
			Compteur += extra;
			y += (extra - 2);

			/* Place DATA NOT PRESENT Flag */
			/* --------------------------- */
			tcPutw((rptr + ri),0xFFFF);
			ri += 2;
			}				
		}
	else	{
		/* Place DATA NOT PRESENT Flag */
		/* --------------------------- */
		tcPutw((rptr + ri),0xFFFF);
		ri += 2;
		}

	/* Padd for Size Change */
	/* -------------------- */
	while ( y > 0 ) {
		y--;
		*(rptr + ri + y) = (BYTE) 0x00FF;
		}

	if ( Options.Optimise ) {
		/* Patch outstanding Labels  */
		/* ------------------------  */
		Resolver();
		}

#ifdef	AO_LISTFILE

	/* If T-Code Listing active */
	/* ------------------------ */
	if (( Options.Liste )  || ( Options.Stats & STAT_CODE )) {
		if ( MasterPhase == 1 )
			SegmentEnd( SegId , Options.Compile );
		else	ProcedureEnd( PrcId , Options.Compile );
		}

#endif
	if ( Options.Pannel )
		draw_optimisations( Compteur );

#ifdef	AO_COMPILER

	/* If Compilation active */
	/* --------------------- */
	if ( Options.Compile ) {
		if ( MasterPhase == 1 ) 
			EndSegment( SegId );
		else	EndProcedure( PrcId );
		}

#endif

	if ( Options.Optimise ) {

		/* End of optimisation Cycle */
		/* ------------------------- */
		FreeLabel(1);

		}

	BlockLen = ri;
	RegisterRelease();
	return(Compteur);

}

#endif	/* _OPTIMISE_C */
	/* ----------- */

