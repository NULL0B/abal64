/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	UTMAIN.C			*/
/*		Version		:	2.1d				*/
/*		Date		:	16/03/1995			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_UTMAIN_C
#define	_UTMAIN_C

#include "stdtypes.h"
#include "version.h"
#define	ALSMID "utmain"
#include "allocate.h"
#include "utdef.h"
#include "amake.h"

/*	Private Local Module Identity Constants */
/*	--------------------------------------- */

#define	MODULE_PROVISOIRE   "\r\n   Provisoire du 03/12/2003 "
#define	MODULE_IDENTITY     "amake"

/*
 *	External Data References
 *	------------------------
 */

EXTERN 	BPTR	 Argstack[ARGMAX];	/* Arguament Stack 	*/
EXTERN 	int	 ArgDex;		/* Arguament Count	*/
EXTERN	RULETREE Sufstack;		/* Suffixes  Structure  */
EXTERN	RULETREE Regstack;		/* Dependace Structure	*/
EXTERN	CONSTREE Konstack;		/* Constants Structure	*/
EXTERN	BPTR	 workbuf;		/* Substitue Buffer	*/

/*
 *	Data Item Declarations
 *	----------------------
 */

int	UserMode;			/* Command line options */
int	Debug;				/* Debug Mode 		*/
int	ErrResult;			/* Result of AMAKE	*/
int	getchwatch;			/* Echo Getch to StdOut */
BYTE  	MakeFlags[256];			/* $MAKE Variable Ptr	*/
BPTR	program_id;

/*
 *	Prototype declarations
 *	----------------------
 */

#ifdef	UNIX
VOID	xliberate_cons();
VOID	list_cons();
VOID	xliberate_rule();
VOID	list_rule();
#else

VOID	xliberate_cons(CONSTREE);
VOID	xliberate_rule(RULETREE);
VOID	list_cons(CONSTREE);
VOID	list_rule(RULETREE);

#endif

/*
 *	GESMES Compatible messages and functions
 *	----------------------------------------
 */ 

#include "utgesmes.c"


/*
 *	Function declarations	
 *	---------------------
 */
VOID	mf_eder( err_value )
int	err_value;
{
#ifdef	ABAL21
	if ( UserMode & _RETURN_TO_USER)
		ErrResult = err_value;
#endif
	return;
}

VOID	utline()
{
	mf_message((BPTR)"\r\n");
	return;
}


int	is_option_indicator( c )
int	c;
{
	if ( c == OPTION_FLAG_1 ) return(1);
#ifndef	UNIX
	if ( c == OPTION_FLAG_2 ) return(1);
#endif
#ifdef	VMS
	if ( c == OPTION_FLAG_2 ) return(1);
#endif
	return(0);
}

VOID	module_identification()
{
	WORD	x;

	if ( (UserMode & _SILENCE ) == 0 ) {

		mf_message((BPTR) "   "              );
		mf_message((BPTR) TalkPtr[1]         );
		mf_message((BPTR) MODULE_VERSION     );
		mf_message((BPTR) MODULE_PROVISOIRE  );
		mf_message((BPTR) MODULE_ENVIRONMENT );	
		mf_message((BPTR) MODULE_COPYRIGHT   );
		utline();
		for ( x = 13; x < 27; x++ ) {
			utline();
			mf_message((BPTR) TalkPtr[ x ] );
			}
		utline();

#ifdef	intERNAL_DEBUG
#ifndef	ABAL_DC
#ifdef	DOS
		mf_message((BPTR)"   MSDOS Version ");
		llmf_co( lldos_major() ); llmf_co('.');
		llmf_co( lldos_minor1());
		llmf_co( lldos_minor2()); llmf_co(' ');
		utline();
#endif
#endif
#endif

		}
	return;
}


/*
 *	Entry Point from Caller to AMAKE
 *	--------------------------------
 *	
 *	Command line Syntax :
 *
 *	AMAKE [options for amake] [make file name] [options for makefile]
 *
 */

main(argc,argv)
int	  argc;
BYTE	* argv[];
{
	int	   	nlog;
	BPTR 		mfnom;
	BPTR		amptr;
	int		c;
	char		cc;
	int		ac;

	start_xallocate();

#ifdef	UNIX
	start_allocation_trace();
#endif
	getchwatch = 0;

#ifdef	VMS
	ErrResult = 1;
#else
	ErrResult = 0;
#endif

	/* Initialise Messages */
	/* ------------------- */
	TalkWork();

#ifdef	PRL
	utline();
	program_id = (BPTR) MODULE_IDENTITY;
#else
	program_id = (BPTR) argv[0];
#endif

	/* Default Make Options : DEFAULT_SUFFIXES */
	/* --------------------------------------- */
	UserMode = _DEFAULT_SUFFIX; Debug = 0;

	/* Initialise the macro manager */
	/* ---------------------------- */
	Initialise_Macros( 0 );

	/* Establish Makefile Name and Arguaments */
	/* -------------------------------------- */
	Argstack[0] = (BPTR) 0;

	/* Create $MAKE Variable */
	/* --------------------- */
#ifndef	PRL
	strcpy((BPTR) MakeFlags , (BPTR) (argv[0]) );
#else
	strcpy((BPTR) MakeFlags , (BPTR) MODULE_IDENTITY );
#endif
	c = 1;
	while ( c < argc ) {
		if ( is_option_indicator( *(argv[c]) ) == 0 ) { break; }
		ArgDex = strlen((BPTR) MakeFlags);
		MakeFlags[ArgDex] = ' ';
		strcpy((BPTR) & MakeFlags[(ArgDex+1)] , (BPTR) argv[c] );
		c++;
		}

	/* Argc Number of arguaments */
	/* ------------------------- */
	c = 0; ArgDex = 0;
	while (((++c) < argc) && (ArgDex < ARGMAX)) {

		/* If FileName not specified and Arg Indicator */
		/* ------------------------------------------- */
		if (( ArgDex == 0 ) && (is_option_indicator( *(argv[c]) ) == 1  )) {

			amptr = (BPTR) argv[c]; amptr++;
	
			/* Repeat till end of Arg String */
			/* ----------------------------- */
			while ( *amptr != (BYTE) 0 ) {

				/* Analysis of command line option */
				/* ------------------------------- */
				switch ((ac = *(amptr++))) {

					/* Start makefile ARG collection */
					/* ----------------------------- */
					case 'a' :
					case 'A' : 
						Argstack[0] = (BPTR) 0;
						ArgDex++; 
						continue;

					default  :
						interprete_option_character(ac);
						continue;
		
					}
				} 
			continue;
			}
		Argstack[ArgDex++] = (BPTR) argv[c]; 
		}

	/* Initialise file management */
	/* -------------------------- */
	(VOID) InitFiles();

	/* Establish Makefile name */
	/* ----------------------- */
	if (( Argstack[0] != (BPTR) 0 ) && ( ArgDex > 0 )) {

		/* Establish Explicite makefile name */
		/* --------------------------------- */
		mfnom = Argstack[0];

		}
	else	{

		/* Attempt to locate Default makefile name */
		/* --------------------------------------- */
		mfnom = (BPTR) "makefile";
		if ( Existance((BPTR) mfnom , 0 , 0 ) != 0 ) {
#ifdef UNIX
			/* Default makefile names for UNIX */
			/* ------------------------------- */
			mfnom = (BPTR) "Makefile";
			if ( Existance((BPTR) mfnom , 0 , 0 ) != 0 ) {
				mfnom = (BPTR) "s.makefile";
				if ( Existance((BPTR) mfnom , 0 , 0 ) != 0 ) {
					mfnom = (BPTR) "s.Makefile";
					if ( Existance((BPTR) mfnom , 0 , 0 ) != 0 ) {
						module_identification();
						(VOID) FreeFiles();
						return(flush_xallocate(ErrResult));
						}
					}
				}
#else
			/* Default file not Found no error */
			/* ------------------------------- */
			module_identification();
			(VOID) FreeFiles();
			return(flush_xallocate(ErrResult));
#endif
			}
		}


	/* Attempt to Locate and open File */
	/* ------------------------------- */
	if ( (nlog = mf_open((BPTR) mfnom )) != -1 ) {

		/* Attempt to Allocate the Substitution Work Buffer */
		/* ------------------------------------------------ */
		if ((workbuf = (BPTR) allocate((DIMAX+1))) != (BPTR) 0) {

			/* Perform MakeFile Analysis */
			/* ------------------------- */
			if ( mf_parser((BPTR) MakeFlags) == 0 ) {

				/* Test for Not PreProc and Not Verify */
				/* ----------------------------------- */
				if ((UserMode & (_PREPROCESS | _VERIFICATION)) == 0) {

					/* Perform MakeFile Actions */
					/* ------------------------ */
					if ( mf_Maker() != 0 ) 
						mf_eder( errno ); 
						
					}
				else	{

					if ((UserMode & _PREPROCESS) != 0 ) {
						(VOID) list_cons(Konstack);
						(VOID) list_rule(Regstack);
						(VOID) list_rule(Sufstack);
						}
					}
				}
			else	{
				/* Display Parser Error */
				/* -------------------- */
				mf_eder( errno );
				ou_eder( ); 
				}

			/* Liberate Constants if Any exist */
			/* ------------------------------- */
			Liberate_Macros( Konstack );

			/* Liberate Rule Structures if Any */
			/* ------------------------------- */
			xliberate_rule(Regstack);

			/* Liberate Work Buffer */
			/* -------------------- */
			liberate((BPTR) workbuf );
			}

		/* Close the MakeFile */
		/* ------------------ */
		mf_close( nlog );
		}
	else	{
		module_identification();
		mf_eder( errno );
		}

	/* Return to Caller */
	/* ---------------- */
	(VOID) FreeFiles();
	return(flush_xallocate(ErrResult));

}

#endif	/* _UTMAIN_C */
	/* --------- */
