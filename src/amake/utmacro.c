/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1993 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	UTMACRO.C			*/
/*		Version		:	1.4c / 2.1a			*/
/*		Date		:	03/02/1993			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_UTMACRO_C
#define	_UTMACRO_C

#include "stdtypes.h"
#define	ALSMID "utmacro"
#include "allocate.h"
#include "utdef.h"
#include "amake.h"


/*	Memory Allocation functions for DOS / PROLOGUE 		*/
/*	----------------------------------------------		*/

int	 MacroMode;	 	/* Options as recieved from initialise   */
CONSTREE Konstack;	 	/* Pointer to local Variable/Constants	 */
CONSTREE NextMacro;		/* Used by List Functions for NextMacro	 */
int	 ParseEnd;	 	/* Indicator of Special Macro Inhibition */
int	 ArgDex;		/* Number of Command line parameters	 */
BPTR	 Argstack[ARGMAX];	/* Pointers to Numeric Args      	 */
BPTR	 CurrentSymbol;		/* Current Macro Symbol Saught		 */
		
/*
 *	S E A R C H N A M E ( macro_name )
 *	----------------------------------
 *	Searchs for the string MACRO_NAME in the internal tables only
 *	(no environment check)
 *	and if succesful returns a pointer to the macro value
 *
 */

#ifdef	PRL

#undef	getenv

WORD	prlsys_getenv( BPTR );
WORD	setenv( BPTR, BPTR );
BPTR	getenv( BPTR );

BYTE	PrlEnvBuf[512];

BPTR	getenv( token )
BPTR	token;
{
	WORD	nl;
	WORD	result;
	BPTR	PrlEnvBuffer = (BPTR) PrlEnvBuf;

	*(PrlEnvBuffer + 0x0000) = 0x0009;	/* Lecture 		*/
	*(PrlEnvBuffer + 0x0009) = 1;		/* This station		*/
	*(PrlEnvBuffer + 0x000B) = 0;		/* Format Systeme	*/
	memcpy( (PrlEnvBuffer+0x000E), token, (nl = strlen(token)));
	*((WPTR) (PrlEnvBuffer + 0x000C)) = (nl+2);
	*((WPTR) (PrlEnvBuffer + 0x0001)) = (nl+14);
	*((WPTR) (PrlEnvBuffer + 0x0003)) = (512 - (nl + 14));
	*((BPTR XPTR) (PrlEnvBuffer + 0x0005)) = (BPTR) (PrlEnvBuffer+nl+14);
	if (( result = prlsys_getenv( PrlEnvBuffer )) != 0)
		return((BPTR) 0);
	else	{
		result = *((WPTR) (PrlEnvBuffer+14+nl));
		*(PrlEnvBuffer + 16 + nl + result) = 0;
		return((BPTR) (PrlEnvBuffer + 16 + nl) );
		}

}

WORD	setenv( token, valeur )
BPTR	token;
BPTR	valeur;
{
	WORD	vl=0;
	WORD	nl;
	WORD	result;
	BPTR	PrlEnvBuffer = (BPTR) PrlEnvBuf;

	if (valeur == (BPTR) 0)
		return( 30 );
	if ((vl = strlen( valeur )) == 0) 	
		return( 31 );

	*(PrlEnvBuffer + 0x0000) = 0x0006; /* Ecriture	 */

	*(PrlEnvBuffer + 0x0009) = 1;		/* This station		*/
	*(PrlEnvBuffer + 0x000B) = 0;		/* Format Systeme	*/
	memcpy( (PrlEnvBuffer+0x000E), token, (nl = strlen(token)));
	*((WPTR) (PrlEnvBuffer + 0x000C)) = (nl+2);

	memcpy((PrlEnvBuffer+0x0010+nl),valeur,vl);
	*((WPTR) (PrlEnvBuffer + 0x000E +nl)) = (vl+2);

	*((WPTR) (PrlEnvBuffer + 0x0001)) = 12;
	*((WPTR) (PrlEnvBuffer + 0x0003)) = vl+nl+4;
	*((BPTR XPTR) (PrlEnvBuffer + 0x0005)) = (BPTR) (PrlEnvBuffer+12);

	return( prlsys_getenv( PrlEnvBuffer ));


}



#endif

BPTR	SearchName( macro_name )
BPTR	macro_name;
{
	CONSTREE	lnode;

	lnode = Konstack;
	while ( lnode != (CONSTREE) 0) {
		if ( mfcompare((BPTR) macro_name , (BPTR) lnode->name) == 0 ) {
			return( lnode->value );
			}
		lnode = lnode->suite;
		}
	return((BPTR) 0);
}


/*
 *	R E C H E R C H E ( macro_name )
 *	--------------------------------
 *	Attempts to locate a definition for macro_name
 *	and if succesful returns the pointer to it's value
 *	otherwise returns a NUL pointer to indicate MACRO UNKNOWN
 *
 */

BYTE	NestWork[512];

static	WORD	offset_right_brace( macro_name )
BPTR	macro_name;
{
	WORD	x=0;
	while (( *(macro_name + x) != ')' ) && ( *(macro_name + x) != (BYTE) 0 ) )
		x++;
	return( x );
}

BPTR Recherche( macro_name )
BPTR macro_name;
{
	int	x;
	BPTR	rptr;
	BPTR	wptr;
	BPTR	new_name;
	BPTR	tptr;
	/* Check for Nested Macro Symbols */
	/* ------------------------------ */
	if (( *macro_name == '$' )
	&&  ( *(macro_name + 1) == '(' )) {
		if ((new_name = Recherche( (macro_name+2) )) == (BPTR) 0)
			return( new_name );
		else	{
			x = offset_right_brace( macro_name );
			/* Test for End of String Error */
			/* ---------------------------- */
			if ( *(macro_name + x) == (BYTE) 0 ) 
				return( (BPTR) 0 );
			wptr = (macro_name + x + 1);
			tptr = (BPTR) NestWork;
			while ( *wptr )
				*(tptr++) = *(wptr++);
			*tptr = 0;
			tptr = macro_name;
			wptr = (BPTR) NestWork;
			while ( *new_name )
				*(tptr++) = *(new_name++);
			while ( *wptr )
				*(tptr++) = *(wptr++);
			*(tptr++) = 0;
			}
		}
	CurrentSymbol = macro_name;

	/* Establish Locals */
	/* ---------------- */
	x = 0;	rptr = (BPTR) 0;

	/* Scan for Right Bracket */
	/* ---------------------- */
	x = offset_right_brace( macro_name );

	/* Test for End of String Error */
	/* ---------------------------- */
	if ( *(macro_name + x) == (BYTE) 0 ) 
		return( (BPTR) 0 );

	/* Establish end of String */
	/* ----------------------- */
	*(macro_name + x ) = (BYTE) 0;

	/* Attempt to locate Environment Variable */
	/* -------------------------------------- */
	if ((MacroMode & 0x0020) != 0 )
		rptr = getenv( (BPTR) macro_name );

	if ( rptr == (BPTR) 0 )

		/* Search for Variable Name in Konstant Table */
		/* ------------------------------------------ */
		rptr = SearchName( (BPTR) macro_name );


	if (( rptr == (BPTR) 0 ) && ((MacroMode & 0x0020) == 0 ))

		/* If String Not found and Environment Search not done */
		/* --------------------------------------------------- */
		rptr = getenv( (BPTR) macro_name );


	/* Replace Bracket */
	/* --------------- */
	*(macro_name + x ) = ')';

	/* Return Result Pointer */
	/* --------------------- */
	return( (BPTR) rptr );

}


/*
 *	E X P A N D _ M A C R O S ( workbuf , source )
 *	----------------------------------------------
 *	Performs macro expansion of the NUL terminated source string
 *	and transfers result to workbuf. Returns the Pointer to the
 *	Result or a NUL Pointer if it encounters a FATAL error.
 *
 */

BPTR	Expand_Macros( workbuf , fnom )
BPTR	workbuf;
BPTR	fnom;
{
	int		si,di;
	int		l;
	int		ai,bi;
	int		ModeFile;
	unsigned int	fnpval;

	BPTR	sptr;

	si = 0; di = 0; l = 0;

	/* While not end of source string or end of Target buffer */
	/* ------------------------------------------------------ */
	while (( di < DIMAX ) && ( *(fnom + si) != (BYTE) 0)) {

		/* Check for Substitution identifier */
		/* --------------------------------- */
		if ( *(fnom + si) == '$' ) {

			si++;

			/* Check for Variable Start Bracket */
			/* -------------------------------- */
			if ( *(fnom + si) != '(' ) {

				switch ( *(fnom + si) ) {

					/* ------------------------- */
					/* Use list of Dependancies  */
					/* EG : Object list for LINK */
					/* ------------------------- */
					case '?' : if (ParseEnd == 0) {
							*(workbuf +di) = '$';
							di++;
							continue;
							}
						   si++;
						   di += DependList((BPTR) (workbuf + di), 0x007F );
						   continue;
					/* ---------------------------------- */
					/* Use Entire Current Target PathName */
					/* ---------------------------------- */
					case '@' : if (ParseEnd == 0) {
							*(workbuf + di) = '$';
							di++;
							continue;
							}
						   si++;
						   di += DollarMacro(0,(BPTR) (workbuf +di) , 0x007F );
						   continue;

					/* ---------------------------- */
					/* Extract Ressource+Path+Name */
					/* --------------------------- */
					case '*' : if (ParseEnd == 0) {
							*(workbuf + di) = '$';
							di++;
							continue;
							}
						   si++;
						   di += DollarMacro(1,(BPTR) (workbuf +di) , 0x007F );
						   continue;

					/* ---------------------------- */
					/* TURBO MAKE compatible options */
					/* ----------------------------- */
					/* Pathname without filename 	 */
					/* -------------------------	 */
					/* UNIX Equivalence $(@D)	*/
					/* ---------------------------- */
					case ':' :
						   si++;
						   di += DollarMacro(0,(BPTR) (workbuf +di) , 0x0007 );
						   continue;

					/* ---------------------------- */
					/* Filename and Extension Only	 */
					/* ---------------------------	 */
					/* UNIX Equivalence $(@F)	*/
					/* ---------------------------- */
					case '.' :
						   si++;
						   di += DollarMacro(0,(BPTR) (workbuf +di) , 0x0078 );
						   continue;

					/* ---------------------------- */
					/* Filename Only		*/
					/* ----------------------------	*/
					/* UNIX Equivalence $(@B)	*/
					/* ---------------------------- */
					case '&' :
						   si++;
						   di += DollarMacro(0,(BPTR) (workbuf +di) , 0x0008 );
						   continue;

					default :

					/* Check for Numeric Command Line Arg */
					/* ---------------------------------- */
					ai = 0;
					
					if (( *(fnom+si) >= '0' ) && ( *(fnom+si) <= '9' )) {

						/* Calculation Commande Line Arg ID */
						/* -------------------------------- */
						while (( *(fnom +si) >= '0' ) && ( *(fnom +si) <= '9' )) {
							ai = ((ai * 10) + (((int) *(fnom +si)) - '0')) ;
							si++;
							}

						/* Check for Valid Arg */
						/* ------------------- */
						if ((ai > 0) && (ai < ArgDex)) {
	
							/* Calculate Length and Transfer to Destination */
							/* -------------------------------------------- */
							if ((sptr = Argstack[ai]) == (BPTR) 0) { continue; }
							l = strlen( (BPTR) sptr );
							if ( l > 0 ) {
								memcpy( (BPTR) (workbuf+di) , (BPTR) sptr , (l + 1) );
								di += l;
								}
							}
						continue;
						}
					else	{
						/* the $ symbol must be kept */
						/* ------------------------- */
						*(workbuf + di) = '$'; di++;
						continue;
						}
					}

				}

			si++;

			/* Watch Out For @ Special Macros */
			/* ------------------------------ */
			if (( *(fnom + si) == '@' ) || ( *(fnom + si) == '*') || ( *(fnom + si) == '?') ) {
				if ( *(fnom + si ) == '@' ) {
					ModeFile = 0;
					}
				else 	{
					if ( *(fnom + si) == '*' ) {
						ModeFile = 1;
						}
					else	{
						ModeFile = 2;
						}
					}
				if (ParseEnd == 0) {	
					*(workbuf + di) = '$'; di++;
					*(workbuf + di) = '('; di++;
					continue;
					}
				si++;

				switch ( *(fnom + si) ) {
					case '/' : /* Valeur Hexa Follows */
						   /* ------------------- */
						   fnpval = Hexa2Digit( (fnom + si + 1) );
						   si += 2; break;
					case 'U' :
					case 'u' :
						/* DEVICE */
						/* ------ */
						fnpval = 0x0002; break;

					case 'P' :
					case 'p' :
						/* PATH */
						/* ---- */
						fnpval = 0x0004; break;

					case 'D' :
					case 'd' : 
						/* DEVICE+PATH */
						/* ----------- */
						fnpval = 0x0007; break;
					   
					case 'F' :
					case 'f' :
						/* FILENAME + EXTENSION ETC */
						/* ------------------------ */
						fnpval = 0x0078; break; 

					case 'R' :
					case 'r' :
						/* PATH + FILENAME NO EXT   */
						/* ------------------------ */
						fnpval = 0x000F; break;

					case 'B' :
					case 'b' :
						/* FILENAME NO EXT   */
						/* ----------------- */
						fnpval = 0x0008; break;

					case 'X' :
					case 'x' :
						/* EXTENSION etc */
						/* ------------- */
						fnpval = 0x0030; break;

					default  : fnpval = 0;

					}

				si += 2;
				/* Perform file name cutting if valid cut value */
				/* -------------------------------------------- */
				if ( fnpval > 0 ) {
					if ( ModeFile == 2 ) 
						di += DependList((BPTR) (workbuf + di), fnpval );
					else
						di += DollarMacro(ModeFile,(BPTR) (workbuf +di) , fnpval );
					}
				continue;

				}

			/* Attempt to Locate Variable Name */
			/* ------------------------------- */
			if ( (sptr = Recherche( (BPTR) (fnom + si) )) == (BPTR) 0 ) {
				if ( (MacroMode & 0x0200) == 0 ) {
					return( (BPTR) 0 );
					}
				}

			/* Scan past Right Bracket */
			/* ----------------------- */
			while (( *(fnom + si) != ')' ) && ( *(fnom +si) != (BYTE) 0 )) {
				si++;
				}

			/* Check for End of String Error */
			/* ----------------------------- */
			if ( *(fnom + si) == (BYTE) 0 ) {
				if ( (MacroMode & 0x0200) == 0 ) {
					return( (BPTR) 0 );
					}
				}
			si++;

			/* Check for Legal Macro Result Value */
			/* ---------------------------------- */
			if ( sptr != (BPTR) 0 ) {

				/* Calculate Length and Transfer to Destination */
				/* -------------------------------------------- */
				l = strlen( (BPTR) sptr );
				if ( l > 0 ) {
					memcpy( (BPTR) (workbuf+di) , (BPTR) sptr , (l + 1) );
					di += l;
					}
				}

			}
		else	{
			*(workbuf + di) = *(fnom + si); si++; di++;
			}

		}
	*(workbuf+di) = (BYTE) 0;
	return( (BPTR) workbuf );

}



/*
 *	M A C R O _ I N I T ( mode )
 *	----------------------------
 *	Allows initialisation of Macro Manager
 *
 *	0x0200	:	Allow inexistant macros during Expansion
 *			default returns error due to inexistant macros
 *	0x0020	:	Causes the environnement to be searched before
 *			the list of internal macros.
 *
 */

int	Initialise_Macros( mode )
int	mode;
{
	int	x;

	MacroMode = mode; Konstack  = (CONSTREE) 0; ArgDex = 0;
	CurrentSymbol = (BPTR) 0;

	for (x=0; x < ARGMAX; x++) 
		Argstack[x] = (BPTR) 0;

	return(0);

}

/*
 *	R E M O V E _ M A C R O ( macro_name )
 *	--------------------------------------
 *	Removes the macro indicated by macro_name from the internal
 *	list of macros.
 *	This Function cannot remove visibillity of Envirronment variables
 *
 */

int	Remove_Macro( macro_name )
BPTR	macro_name;
{
	CONSTREE	lnode;
	CONSTREE	pnode;

	lnode = Konstack; pnode = (CONSTREE) 0;
	while ( lnode != (CONSTREE) 0) {
		if ( mfcompare((BPTR) macro_name , (BPTR) lnode->name) == 0 ) {
			liberate ((BPTR) lnode->value );
			liberate ((BPTR) lnode->name  );
			if ( pnode != (CONSTREE) 0 ) {
				pnode->suite = lnode->suite;
				}
			else	{
				Konstack = lnode->suite;
				}
			liberate ((BPTR) lnode ); 
			return(0);
			}
		pnode = lnode;
		lnode = lnode->suite;
		}
	return(1);

}

/*
 *	A D D _ M A C R O ( macro_name , macro_value )
 *	----------------------------------------------
 *	Adds the macro name provided to the list of internal macros
 *	and associates the value provided with this name
 *
 */

int	Add_Macro( macro_name , macro_value )
BPTR	macro_name;
BPTR	macro_value;
{
	CONSTREE	lnode;

	/* Allocate a new structure Zone */
	/* ----------------------------- */
	if ((lnode = (CONSTREE) allocate(sizeof(struct Constant))) != (CONSTREE) 0) {
		lnode->name  = macro_name;
		lnode->value = macro_value;
		lnode->suite = Konstack;
		Konstack     = lnode;
		return(0);
		}
	return(27);
}


/*
 *	A D D _ A R G _ M A C R O ( macro_value )
 *	-----------------------------------------
 *	This function allows the provided value to be declared as a command
 *	line passed arguament value to be used for the special macros
 *	$1 -> $9
 * 	during Expand_Macros()
 *
 */

int	Add_Arg_Macro( macro_value )
BPTR	macro_value;
{
	if ( ArgDex < ARGMAX ) {
		Argstack[ ArgDex ] = macro_value;
		ArgDex++;
		return(0);
		}
	return(30);
}


/*
 *	Liberation of the Constants/Variables Tree (Recursive Function)
 *	------------------------------------------ --------------------
 *
 */

VOID	Liberate_Macros(lroot)
CONSTREE	lroot;
{

	/* If this level is Valid */
	/* ---------------------- */
	if ( lroot != (CONSTREE) 0) {

		/* Go to next level */
		/* ---------------- */
		Liberate_Macros( lroot->suite );

		/* Encore une libelle a sous_ligner */
		/* -------------------------------- */

		/* Liberate this Level */
		/* ------------------- */
		liberate((BPTR) lroot->name );
		liberate((BPTR) lroot->value );
		liberate((BPTR) lroot );
		}

	/* Return to Previous Level */
	/* ------------------------ */
	return;

}

/*
 *	RESET PARSE END ()	and	SET PARSE END ()
 *	------------------		----------------
 *	Offer a mechanism to activate and dissactivate the special macros
 *	which refer to AMAKE inference rules (@,?,*,> etc)
 */
	
VOID	ResetParseEnd()
{
	ParseEnd = 0;
	return;
}

VOID	SetParseEnd()
{
	ParseEnd = 1;
	return;
}


/*
 *	FIRST MACRO ( & name , & value )   and	NEXT MACRO ( &name , &value )
 *	---------------------------------------------------------------------
 *	These functions offer a means of Listing the Internal Macros
 *	currently known and managed by the MACRO manager
 *
 */


int	Next_Macro( nameptr , valueptr )
BPTR	XPTR	nameptr;
BPTR	XPTR	valueptr;
{
	if ( NextMacro == (CONSTREE) 0 ) {
		return(48);
		}
	*nameptr  = NextMacro->name;
	*valueptr = NextMacro->value;
	NextMacro = NextMacro->suite;
	return(0);
}

int	First_Macro( nameptr , valueptr )
BPTR	XPTR	nameptr;
BPTR	XPTR	valueptr;
{
	NextMacro = Konstack;
	return( Next_Macro( nameptr , valueptr ) );
}


#endif	/* _UTMACRO_C */
	/* ---------- */
