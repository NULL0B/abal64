/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOJUMP.C  				*/
/*		Version :	2.1b					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOJUMP_C
#define	_AOJUMP_C

#define	OPTIMISEUR

				/* ------------------------------------ */
#include "aomain.h"		/* Type Definitions and constants	*/
#include "aotcode.h"		/* Inclusion of TCode definitions	*/
#include "aotcngf.h"		/* NGF T-Code Definitions		*/
#include "aostat.h"		/* Statistics management		*/
#include "aomacro.h"		/* Macros used for source Clarity	*/
#include "aoproto.h"		/* Prototypes for all Object Modules	*/
#include "aoglobal.h"		/* Data Items with Global Scope		*/
#include "aogesmes.c"		/* Messages in GESMES Format		*/
				/* ------------------------------------ */


/*	Select Case JEQ JMP Optimiser		*/
/*	-----------------------------		*/

void	SelectCase( sptr , si , indent )
BPTR	sptr;
EXAWORD	si;
EXAWORD	indent;
{
	EXAWORD	x;

	/* Check for JMP after J??? */
	/* ------------------------ */
	if ( *(sptr + si + indent + 2) != _tc_JMI ) {

		/* No So Return Now */
		/* ---------------- */
		return;
		}

	/* Watch out For : For Bcd = 1 to Limit Step Pas */
	/* which generates a similar code sequence but   */
	/* Cannot be optimised in the same way		 */
	/* --------------------------------------------- */
	x = tcGetw( (sptr + si + indent ) );

	/* Check for Not Adresse after JMI &Label */
	/* -------------------------------------- */
	if ( x != (si + indent + 5)) {

		/* Not a Select case */
		/* ----------------- */
		return;
		}

	/* Determine Inverted Compare Operation */
	/* ------------------------------------ */
	switch ((((EXAWORD) *(sptr + si )) & 0x000F ) ) {
		case 0x0008 : x = 0x0009; break;
		case 0x0009 : x = 0x0008; break;
		case 0x000A : x = 0x000D; break;
		case 0x000B : x = 0x000C; break;
		case 0x000C : x = 0x000B; break;
		case 0x000D : x = 0x000A; break;
		case 0x000E : x = 0x000F; break;
		case 0x000F : x = 0x000E; break;
		default	    : return;
		}

	/* Modify Compare Mnemonic */
	/* ----------------------- */
	*(sptr + si ) = (BYTE) ((((EXAWORD) *(sptr + si )) & 0x00F0) | x );

	/* Get Jump to Label */
	/* ----------------- */
	x = tcGetw( (sptr  + si + indent + 3) );

	/* Patch for Reversed Jump */
	/* ----------------------- */
	tcPutw( (sptr  + si + indent) , x );

	information((sptr + si + indent + 2));

	/* OverWrite redundant Jump */
	/* ------------------------ */
	for ( x = 2; x < 5; x++ ) {
		*(sptr  + si + indent + x ) = (BYTE) _tc_NOP;
		}

	/* Signal Operation performed */
	/* -------------------------- */
	return;

}


/*	Optimises consequtive Direct Jump instructions		*/
/*	----------------------------------------------		*/

EXAWORD	JmiCheck( adresse )
EXAWORD	adresse;
{
	EXAWORD	ladresse;
	EXAWORD	x;

	/* Check for Direct Jump Found */
	/* --------------------------- */
	if ((((EXAWORD) *(tcCS + adresse)) & REMOVE_NEWLINE ) != _tc_JMI ) {
		/* No so Return Current Adresse */
		/* ---------------------------- */
		return( adresse );
		}

	/* Locate JUMP TO Adresse */
	/* ---------------------- */
	x = tcGetw( (tcCS + adresse + 1) );

	/* Recursivly check the new adresse */
	/* -------------------------------- */
	if ((ladresse = JmiCheck( x )) != x ) {

		/* Update new adresse if different */
		/* ------------------------------- */
		tcPutw( (tcCS + adresse + 1) , ladresse );
		OptCount++;
		}

	/* Return the Current Linked Jump Adresse */	
	/* -------------------------------------- */
	return(ladresse);

}


EXAWORD	JumpLinkage( sptr , si , rptr , ri , indent )
BPTR	sptr;
EXAWORD	si;
BPTR	rptr;
EXAWORD	ri;
EXAWORD	indent;
{
	EXAWORD	x;
	EXAWORD	y;

	/* Get the Label From Tcode (Watch out for Do :: Loop ) */
	/* ---------------------------------------------------- */
	if ((x = tcGetw( (sptr + si + indent))) != si ) { 

		/* Check for JMI Mode */
		/* ------------------ */
		if ( indent == 1 ) {

			/* Watch Out For Jump Next */
			/* ----------------------- */
			if ( x == (si + 3)) {

				information((sptr + si));

				/* Overwrite with NOP's */
				/* -------------------- */
				for ( x = 0; x < 3; x++ ) {
					*(sptr + si + x) = _tc_NOP;
					}
					return(0);
				}
			}

		/* Check for Label already Known */
		/* ----------------------------- */
		if (( y = LabelKnown( x ) ) != MOINS_UN ) {

			/* The Label Exists so Back Ref */
			/* ---------------------------- */

			/* Check for and Link JMI's */
			/* ------------------------ */
			if ((((EXAWORD) *(rptr + y)) & REMOVE_NEWLINE) == _tc_JMI) {
	
				/* JMI Found */
				/* --------- */
				x = tcGetw( (rptr + y + 1) );
	
				/* Patch New Label Now */
				/* ------------------- */
				tcPutw( (sptr + si + indent) , x);
	
				/* Check for awaiting BackPatch */
				/* ---------------------------- */
				if (IsBackPatch((rptr + y + 1)) != MOINS_UN ) {
	
					/* Declare a BackPatch Here as well */
					/* -------------------------------- */
					ConvertLabel((sptr + si + indent),(rptr + ri + indent));
					}
				}
			else	{
				/* Not a JMI so patch Good Adresse */
				/* ------------------------------- */
				tcPutw( (sptr + si + indent) , y);

				}
			}
		else	{
			/* Label Unknown Forward Ref	*/
			/* -------------------------	*/
			/* Check for and Link JMI's */
			/* ------------------------ */
			if ((((EXAWORD) *(sptr + x)) & REMOVE_NEWLINE) == _tc_JMI) {

				/* Get The Label */
				/* ------------- */
				y = tcGetw( (sptr + x + 1) );

				/* Patch This Label */
				/* ---------------- */
				tcPutw( (sptr + si + indent) , y);

				/* Go Around again (avoid Recursivity) */
				/* ----------------------------------- */
				return(1);
				}

			/* Convert it Since it's UnKnown */
			/* ----------------------------- */
			ConvertLabel((sptr + si + indent),(rptr + ri + indent));
	
			}

		}
	else	{
		/* Found a Do :: Loop */
		/* ------------------ */
		tcPutw( (sptr + si + indent) , ri );
		}
	return(0);

}

EXAWORD	convert_compare_jumps(sptr, si,registre, nombre )
BPTR	sptr;
EXAWORD	si;
EXAWORD	registre;
EXAWORD	nombre;
{
	EXAWORD	x;
	EXAWORD	cid;
	EXAWORD	nsi;
	EXAWORD	l;

	while ( 1 ) {

		/* New line at adresse means end of chain */
		/* -------------------------------------- */
		if ( *(sptr + si) & TCODE_NEWLINE ) {
			if ((si = pop_branche_offset()) != MOINS_UN) {
				si += 6;
				continue;
				}
			else	return( nombre );
			}

		/* Avoid NOP's */
		/* ----------- */
		if ( *(sptr + si) == _tc_NOP ) {
			si++;
			continue;
			}
	
		/* Check for Possible Optimisation */
		/* ------------------------------- */
		if (( ((*(sptr + si)) & (tc_CMP_JMP | TCODE_NEWLINE)) == tc_CMP_JMP )
			
			&& (( *(sptr + si) & 0x0078) != _tc_JEQR )) {

			/* Ensure identical Registers */
			/* -------------------------- */
			if ( *(sptr +si + 1) != registre ) {
				if ((si = pop_branche_offset()) != MOINS_UN ) {
					si += 6;
					continue;
					} 
				else	return( nombre );
				}

			nombre++;

			/* Collect Constant Identifier */
			/* --------------------------- */
			cid = (tcGetw((sptr + si + 2)));

			/* Ensure Correct String Constant 1 byte Long */
			/* ------------------------------------------ */
			if ( *( tcGKT + cid ) != 1 ) {
			
				/* Indicate Failure */
				/* ---------------- */
				return( 0 );
				}

			/* Attempt to store this tcode pattern */
			/* ----------------------------------- */
			if ( !(allocate_for_recovery( sptr, si, 6 )) )
				return( 0 );

			/* Convert J??C reg,C => J??I r,I */
			/* ------------------------------ */
			*(sptr + si) = integer_compare(( *(sptr + si)));


			/* Collect First byte and use as 8 bit Integer Value */
			/* ------------------------------------------------- */
			x = *( tcGKT + (cid+1) );
			tcPutw((sptr + si + 2),x);

			/* Attempt further optimisations */
			/* ----------------------------- */
			if ( *(sptr + si + 6) == _tc_JMI )
				nsi = (tcGetw((sptr + si + 7)));
			else	nsi = (tcGetw((sptr + si + 4)));

			/* Attempt further optimisations */
			/* ----------------------------- */
			if (!(push_branche_offset( si ))) 
				return( 0 );

			si = nsi;
			continue;

			}
		else	{

			/* Check for Possible CHR$( integer ) */
			/* ---------------------------------- */
			if (( *(sptr + si) == _tc_CLF ) 

				&& ( *(sptr + si + 1) == _clf_CHR )) {


				/* REGISTER = CHR$( INTEGER ) */
				/* -------------------------- */
				if ( *(sptr + si + 2) == 0x0070 ) {

					/* Check for Possible Optimisation */
					/* ------------------------------- */
					if ( ((*(sptr + si + 6)) & (tc_CMP_JMP | TCODE_NEWLINE)) == tc_CMP_JMP ) {

						nombre++;
						information((sptr + si));
						if ( *(sptr + si + 11) == _tc_JMI )
							l = 14;
						else	l = 11;

						/* Attempt to Store current tcode pattern */
						/* -------------------------------------- */
						if (!(allocate_for_recovery(sptr,si,l)))
							return(0);

						/* Collect Integer Value from CHR$ */
						/* ------------------------------- */
						x = tcGetw((sptr + si + 4));

						/* Generate J??I R,I,&E */
						/* -------------------- */
						*(sptr + si) = integer_compare( (*(sptr + si + 6) & 0x003F) );
						*(sptr + si + 1) = *(sptr + si + 7);
						tcPutw((sptr + si + 2),x);
						nsi = tcGetw((sptr + si + 9));
						if ( l == 14 )
							x = (nsi - 5);
						else 	x = nsi;

						tcPutw((sptr + si + 4),x);

						/* Watch out for Subsequent JMI */
						/* ---------------------------- */
						if ( l == 14 )
							memcpy((sptr + si + 6), (sptr + si + 11) , 3 ); 

						/* RAZ Unused Zone with NOP */
						/* ------------------------ */
						memset((BPTR) (sptr + si + (l == 14 ? 9 :6)), _tc_NOP, 5 );
	
						/* Attempt further optimisations */
						/* ----------------------------- */
						if ( l == 14 )
							nsi = (tcGetw((sptr + si + 7)));

						/* Attempt To store Branche Adresse */
						/* -------------------------------- */
						if (!(push_branche_offset( si ))) 
							return( 0 );

						/* Next Possible Member */
						/* -------------------- */
						si = nsi;
						continue;

						}
					}
				}
			}
		
		/* Check for Terminal GOTO statement */
		/* --------------------------------- */
		if ( *(sptr + si) == _tc_JMI ) {

			if ((si = pop_branche_offset()) != MOINS_UN ) {
				si += 6;
				continue;
				}
			else	return( nombre );

			}

		/* Indicate Failure */
		/* ---------------- */
		return( 0 );

		}
  
}

#endif	/* _AOJUMP_C   */
	/* ----------- */

