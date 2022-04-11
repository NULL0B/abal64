/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOVARB.C				*/
/*		Version :	1.4a / 2.1b				*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOVARB_C
#define	_AOVARB_C

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

EXTERN	EXAWORD	SymbolStatus;

/*
 *	C O N V E R T _ V A R I A B L E _ I D E N T I F I E R ( old, new, off ) 
 *	-----------------------------------------------------------------------
 *
 */

EXAWORD	convert_variable_identifier( oldDT , newDT , variable )
BPTR	oldDT;
BPTR	newDT;
EXAWORD	variable;
{
	EXAWORD	vdesc;
	EXAWORD	longeur=0;
	EXAWORD	indent;
	EXAWORD	nombre;
	EXAWORD	where=0;
	EXAWORD	bdesc=0;
	EXAWORD	field_flag=0;
	EXAWORD	offset;

	offset = (variable & TOGLOBAL);

	if (( newDT == (BPTR) 0 ) || ( Options.Tables == FAUX ))
		return( offset );

	/* Collect variable Identifier */
	/* --------------------------- */
	vdesc = tcGetw( (oldDT + offset) );

	/* Variable identifier already converted */
	/* ------------------------------------- */
	if (( vdesc & CONVERTED_ENTRY ) == 0 ) {
		
		/* Check for Extended Special Types */
		/* -------------------------------- */ 
		if ( vdesc & 0xFF00 ) {

			/* Check for dynamic allocation type */
			/* --------------------------------- */
			if ( vdesc & 0x8000 ) {

				/* Check for MEMBER of pointed memory */
				/* ---------------------------------- */
				if ( vdesc & 0x2000 ) {

					/* Length : DESC + RDESC + OFFSET */
					/* ------------------------------ */
					longeur += (3*WORDSIZE);

					/* Collect Pointer descriptor */
					/* -------------------------- */
					bdesc = tcGetw( (oldDT + offset + WORDSIZE ));

					}

				/* Not a MEMBER of pointer memory */
				/* ------------------------------ */
				else	longeur += (2*WORDSIZE);
				}

			/* Must be FIELD=E or FIELD=<handle> */
			/* --------------------------------- */
			else	longeur += (3*WORDSIZE);
			}

		/* Must be FIELD=M (Local or Global) */
		/* --------------------------------- */
		else	longeur += (2*WORDSIZE);

		/* Adjust for String variable length word */
		/* -------------------------------------- */
		if (( vdesc & 3 ) > 1) 
			longeur += (WORDSIZE);

		/* Adjust for First Dimension */
		/* -------------------------- */
		if ( vdesc & FIRST_DIMENSION )
			longeur += WORDSIZE;

		/* Adjust for Second Dimension */
		/* --------------------------- */
		if ( vdesc & SECOND_DIMENSION )
			longeur += WORDSIZE;

		/* Collect new table control info */
		/* ------------------------------ */
		nombre = tcGetw( (newDT)     );
		indent = tcGetw( (newDT + (2 * WORDSIZE)) );

		/* The MEMBER variables will patch new POINTER desc here */
		/* ----------------------------------------------------- */
		where  = (indent + WORDSIZE);

		/* Copy to new variable table */
		/* -------------------------- */
		memcpy( (BPTR) (newDT + indent) , (BPTR) (oldDT + offset), longeur );

		/* ------------------------- */
		/* Update Old Variable Table */
		/* ------------------------- */
		/* Raise Converted Variable  */
		/* Store resoloution adresse */
		/* ------------------------- */
		vdesc |= CONVERTED_ENTRY;
		tcPutw( (oldDT + offset) , vdesc );
		tcPutw( (oldDT + offset + WORDSIZE),indent );

		/* Update new table information */
		/* ---------------------------- */
		nombre++;
		tcPutw( (newDT)     , nombre );

		indent += longeur;
		tcPutw( (newDT + (2*WORDSIZE)) , indent ); 

		}

	/* Collect and return new variable identifier */
	/* ------------------------------------------ */
	offset = tcGetw( (oldDT + offset + WORDSIZE ) );

	
	/* MEMBERS must also convert their pointer : NOW */
	/* --------------------------------------------- */
	if ( bdesc ) {
		field_flag = ( bdesc & ISLOCAL);
		bdesc = convert_variable_identifier( oldDT, newDT, bdesc);
		bdesc |= field_flag;

		/* And back patch the new variable ID */
		/* ---------------------------------- */
		tcPutw((newDT+where), bdesc );

		} 

	if ( SymbolStatus )
		relocate_symbolic_variable( variable, offset );

	return( offset );	

}

EXAWORD	rellocate_variable( sptr , si )
BPTR	sptr;
EXAWORD	si;
{
	EXAWORD	before;
	EXAWORD	after;

	/* Collect variable identifier */
	/* --------------------------- */
	before = tcGetw( (sptr + si) );

	/* Test for a local variable */
	/* ------------------------- */
	if ( before & IS_LOCALE ) 
		after = (convert_variable_identifier(tcLDT, newLDT, before)  | IS_LOCALE );
	else
		after = convert_variable_identifier(tcGDT, newGDT, before );

	tcPutw( (sptr + si) , after );

	if ( before != after )
		return(VRAI);
	else
		return(FAUX);


}




/*	Returns the Variable Descriptor Word from Variable ID	*/
/*	-----------------------------------------------------	*/

EXAWORD	Descriptor( variable )
EXAWORD	variable;
{
	/* Separate Local From Global */
	/* -------------------------- */
	if (( variable & IS_LOCALE ) != 0 ) {

		/* Return Local Variable Descriptor */
		/* -------------------------------- */
		 return( ((tcGetw((tcLDT + (variable & TO_GLOBAL)))) | IS_LOCALE ) );
		}
	else	{

		/* Return Global Variable Descriptor */
		/* --------------------------------- */
		 return( (tcGetw((tcGDT + variable ))) );

		}

}

EXAWORD	VariableSize( variable )
EXAWORD	variable;
{
	BPTR	lbase;
	EXAWORD	vtype;

	/* Separate Local From Global */
	/* -------------------------- */
	if (( variable & IS_LOCALE ) != 0 ) {
		lbase = tcLDT;
		variable &= TO_GLOBAL;
		}
	else	{
		lbase = tcGDT;
		}

	/* Collect Variable Type */
	/* --------------------- */
	vtype = tcGetw( (lbase + variable ) );

	/* Watch out for 32 bit Adressing */
	/* ------------------------------ */
	if (( vtype & 0xFF00 ) != 0 ) { 
		if (!( vtype & 0x8000 ))
			variable += WORDSIZE;
		else if ( vtype & 0x2000 )
			variable += WORDSIZE;
		}

	/* Test for Bcd or String Variables */
	/* -------------------------------- */
	if (( vtype & 0x0003 ) >  1 ) {

		/* Return Length from Descriptor */
		/* ----------------------------- */
		return( (tcGetw(( lbase + variable + 4 ) )) );
		}
	else	{

		/* Return Calculated Length */
		/* ------------------------ */
		return( ((vtype & 0x0003) + 1) );
		}

}

/*	Returns the physical memory adresse of Variable		*/
/*	-----------------------------------------------		*/

EXAWORD	AdresseVarb( variable )
EXAWORD	variable;
{
	EXAWORD	vdesc;
	EXAWORD	indent;
	EXAWORD	offset=2;

	/* Separate Local From Global */
	/* -------------------------- */
	if (( variable & IS_LOCALE ) != 0 ) {

		/* Collect current type status */
		/* --------------------------- */
		vdesc = tcGetw( (tcLDT + (variable & TO_GLOBAL)) );

		if ((vdesc & 0x8000)
		&&  (vdesc & 0x2000))
			offset += WORDSIZE;

		/* Check for already converted */
		/* --------------------------- */
		if ( vdesc & CONVERTED_ENTRY ) {
 
			indent = tcGetw( (tcLDT + (variable & TO_GLOBAL) + offset) );

			/* Return converted table variable offset */
			/* -------------------------------------- */
			return( ((tcGetw((newLDT + (indent & TO_GLOBAL) + offset)))) );
			}
		else	{
			/* Otherwise return original variable offset */
			/* ----------------------------------------- */
			 return( ((tcGetw((tcLDT + (variable & TO_GLOBAL) + 2)))) );
			}
		}
	else	{

		/* Collect current type status */
		/* --------------------------- */
		vdesc = tcGetw( (tcGDT + variable) );

		if ((vdesc & 0x8000)
		&&  (vdesc & 0x2000))
			offset += WORDSIZE;

		/* Check for already converted */
		/* --------------------------- */
		if ( vdesc & CONVERTED_ENTRY ) {

			indent = tcGetw( (tcGDT + variable + offset) );

			/* Return converted table variable offset */
			/* -------------------------------------- */
			return( ((tcGetw((newGDT + indent + 2)))) );
			}
		else	{
			/* Otherwise return original variable offset */
			/* ----------------------------------------- */
			 return( ((tcGetw((tcGDT + variable + offset)))) );
			}

		}

}

void	StoreTcodeWord( tptr , valeur )
BPTR	tptr;
EXAWORD	valeur;
{
	tcPutw( tptr , valeur );
	return;
}

/*	--------------------------------------------------------------  */
/*	Re-writes the compressed data table to disk and rellocates the	*/
/*	variable name references if required 				*/
/*	--------------------------------------------------------------  */
EXAWORD	data_table_compression( newdt, olddt, oldnt )
BPTR	newdt;
BPTR	olddt;
BPTR	oldnt;
{
	EXAWORD	x;
	EXAWORD	new_length;

	/* Collect final length of Data table */
	/* ---------------------------------- */
	new_length = tcGetw( (newdt + (2 * WORDSIZE)) );

	/* Establish original Data allocation length */
	/* ----------------------------------------- */
	x = tcGetw( (olddt + (2 * WORDSIZE)) );

	StoreTcodeWord( (newdt + (2 * WORDSIZE)) , x );

	/* Copy new table to Old Table */
	/* --------------------------- */
	if ( new_length > 0 )
		memcpy((BPTR)  olddt , (BPTR) newdt , new_length );

	/* Return new table length */
	/* ----------------------- */
	return( new_length );
}

EXAWORD	local_variable_args( ldt )
BPTR	ldt;
{
	EXAWORD	nbvarb;
	EXAWORD	argcount;
	EXAWORD	i;
	EXAWORD	x;

	if ((nbvarb = (tcGetw((ldt)))) == 0)
		return( 0 );

	for ( i = (3*WORDSIZE), argcount = 0; nbvarb != 0; nbvarb-- ) {
			
		x = tcGetw( (ldt + i) );

		/* Exit on first variable Non-ARG */
		/* ------------------------------ */
		if (( x & 0x0008 ) == 0)
			break;

		argcount++;

		if ( x & 0xFF00 ) {
			if ( x & 0x8000 ) {
				if ( x & 0x2000 )
					i += (3*WORDSIZE);
				else	i += (2*WORDSIZE);
				}
			else	i += (3*WORDSIZE);
			}
		else	i += (2*WORDSIZE);

		if (( x & 0x003 ) > 1 )
			i += WORDSIZE;
		if ( x & 0x0040 )
			i += WORDSIZE;
		if ( x & 0x0020 )
			i += WORDSIZE;
		}

	return( argcount );
}

void	rellocate_local_variables( ldt, nb, adj,padj )
BPTR	ldt;
EXAWORD	nb;
EXAWORD	adj;
EXAWORD	padj;
{
	EXAWORD	i;
	EXAWORD	x;
	EXAWORD	v;

	for ( i = 0; nb != 0; nb-- ) {

		do	{
			x = tcGetw((ldt + i));
			i += WORDSIZE;
			}
		while ( x & 0x0010 );

		if ((!(x & 0x7F00)) 
		||  (( x & 0xB000) == 0x9000))  {
			v = tcGetw((ldt + i));
			v += adj;
			tcPutw((ldt+i),v);
			}
		else	i += WORDSIZE;

		/* Check for Pointer Redefinition Member */
		/* ------------------------------------- */
		if (( x & 0xA000) == 0xA000 ) {
			v = tcGetw((ldt + i));
			v += padj;
			tcPutw((ldt+i),v);
			}

		i += WORDSIZE;
		 
		if (( x & 0x003 ) > 1 )
			i += WORDSIZE;
		if ( x & 0x0040 )
			i += WORDSIZE;
		if ( x & 0x0020 )
			i += WORDSIZE;
		}
	return;

}

void	TableInit( oldDT , newDT, glflag )
BPTR	oldDT;
BPTR	newDT;
EXAWORD	glflag;
{
	EXAWORD	x;
	EXAWORD	i;
	EXAWORD	r;
	EXAWORD	varb_count;

	if (( oldDT != (BPTR) 0 ) && ( newDT != (BPTR) 0 )) {

		/* Zero elements in this table */
		/* --------------------------- */
		tcPutw( (newDT) , 0 );

		/* Adresse of variable name table */
		/* ------------------------------ */ 
		x = tcGetw( (oldDT + WORDSIZE) );

		tcPutw( (newDT + WORDSIZE), x);

		/* offset into new table of Next Descriptor */
		/* ---------------------------------------- */
		tcPutw( (newDT + (2*WORDSIZE)) , (3*WORDSIZE) );

		varb_count = tcGetw( (oldDT) );
	
		/* Scan over possible procedure / Program Arg Variables */
		/* ---------------------------------------------------- */
		for ( i = (3*WORDSIZE); varb_count != 0; varb_count-- ) {
			
			x = tcGetw( (oldDT + i) );

			/* Exit on first variable Non-ARG */
			/* ------------------------------ */
			if (( x & 0x0008 ) == 0)
				break;

			(void) convert_variable_identifier( oldDT, newDT, (i | glflag) );

			if ( x & 0xFF00 ) {
				if ( x & 0x8000 ) {
					if ( x & 0x2000 )
						i += (3*WORDSIZE);	
					else	i += (2*WORDSIZE);
					}
				else	i += (3*WORDSIZE);
				}
			else	i += (2*WORDSIZE);

			if (( x & 0x003 ) > 1 )
				i += WORDSIZE;
			if ( x & 0x0040 )
				i += WORDSIZE;
			if ( x & 0x0020 )
				i += WORDSIZE;
			}
		
		}
}


#endif	/* _AOVARB_C */
	/* --------- */

