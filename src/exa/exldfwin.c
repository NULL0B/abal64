/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLDF.C   				*/
/*		Version :	1.4e / 2.2a    				*/
/*		Date 	:	21/06/2002				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	20/11/1990	:	The options flag for InitRunTime has 	*/
/*			:	been reset to ZERO to indicate neither	*/
/*			:	public nor exportable libraries since	*/
/*			:	the #USER syntax does not currently	*/
/*			:	offer a means to indicate these options	*/
/*			:	This will be activated later (V1.5)	*/
/*			:	to allow fine control of library use	*/
/*									*/
/*	17/12/1990	:	The ASFUN library signature 2 indicates	*/
/*			:	redirection is to be performed ASFUN1.2	*/
/*			:	whilst signature 3 indicates an old	*/
/*			:	ASFUN 1.1a / 1.1b library which does 	*/
/*			:	require redirection by the executer	*/
/*									*/
/*	25/01/1991	:	The ASFUN library signature 3 indicates	*/
/*			:	that the ASFUN library 1.1b requires	*/
/*			:	CICO redirection but that the extended	*/
/*			:	EXADB window functions are not to be	*/
/*			:	activated since they are not available.	*/
/*									*/
/*	21/11/1991	:	Correction to ensure no exception and	*/
/*			:	no core dump when chaining from a	*/
/*			:	program with no user libraries to a	*/
/*			:	program with user libraries in function	*/
/*			:	"MergeFuse" which now calls "InitFuse"	*/
/*			:	when the chained from program has no	*/
/*			:	User Libraries.				*/
/*									*/
/*	07/10/1994	:	Correction to ensure liberation of	*/
/*			:	Libraries loaded by a program which	*/
/*			:	chained to a program with no libraies	*/
/*			:	which consequently stopped !		*/
/*			:	(Ecco/Houless V1.2c Provisoire) IJM	*/
/*									*/
/*	21/11/1994	:	MergeFuse (cf)				*/
/*									*/
/*	02/02/2001	:	MergeFuse has had its library init	*/
/*				code removed since this causes problems	*/
/*				with staff screener Z library which	*/
/*				redirects CICO to the graphics driver	*/
/*				and then this function loads the ASFUN	*/
/*				module which was just hanging around	*/
/*				to watch, load == redirect == boom !	*/
/*									*/
/*									*/
/*	05/02/2001	:	New function in CLF7 has been added	*/
/*				to allow (enfin) the filename of the 	*/
/*				dynamic library to be set by the abal	*/
/*				program ! pheeww .....			*/
/*				This has required a new function here	*/
/*				to implement the real dirty work !	*/
/*									*/
/* 27/12/01 (#IJM) Bug EXA-165: Regression since 2.1g. Correction to allow the chain/merge or programs with differing */
/* libraries to co-operate with screener graphical library which may or may not exist. */
/*----------------------------------------------------------------------*/

#ifndef	_EXLDF_C
#define	_EXLDF_C

/*----------------------------------------------------------------------*/
/* #define	TcodeFileHandle nlog					*/
/* -------	--------------------					*/
/* May be Activated to allow usage of this module in 1.2 version	*/
/*----------------------------------------------------------------------*/

#include	"exldf.h"
#include 	"exptr.h"

#ifdef DEBUGGER
#include "exproto1.h"
#endif

#ifdef	DEBUG_XLDF
WORD	LdfTrapCount;
WORD	LdfTrapLib[10];

VOID	DebugCallRunTime( nbl, nbf, nba )
WORD	nbl;
WORD	nbf;
WORD	nba;
{
	WORD	i;
	if ((i = LdfTrapCount)) {
		while ( i ) {
			i--;
			if ( nbl == LdfTrapLib[i] ) {
				InspectLdfCall(nbl, nbf, nba );
				break;
				}
			}
		}
	return;
}

VOID	ldf_trapwork( cmdptr, absel )
BPTR	cmdptr;
WORD	absel;
{
	WORD	n=0;
	while ((*cmdptr) && (*cmdptr == ' '))
		cmdptr++;
	if ( *cmdptr == 0 )
		return;
	if ( (*cmdptr == 'I') || (*cmdptr == 'i')) {
		LdfTrapCount = 0;
		return;
		}
	while (( *cmdptr ) && ( *cmdptr != ' ' ))
		n = ((n * 10) + ( *(cmdptr++) - '0' ));

	LdfTrapLib[LdfTrapCount++] = n;
	return;		
}

#endif

/*
 *	Gestion des Arguments des Fonctions de Definition Locales
 *	----------------------------------------------------------
 *	F U _ Argset ( Numero de Set )
 *	------------------------------
 *
 */


WORD fuargset(type)
WORD	type;			/* 	Arguament Evaluation Set to prepare */
				/*	NB	0 => argsetw		    */
				/* 	Type de data desiree	*/
{
	WORD	desc,reg;
	BPTR	tptr;

reg = 0;
switch ( amode ) {
	case 1 :	desc = (adesc & 0x0060) >> 5;
			if (( adesc & 0x0010 ) != 0 ) { amode = 2; }
			else { amode = 0; }
			break;
	case 2 :
			desc = ( adesc & 0x0006) >> 1;
			if (( adesc & 1 ) != 0 ) { adesc = (WORD) *(adex++);
						   amode = 1;
						}
			else { amode = 0; }
			break;
	default : amode = 0;
	case 0  : err_val = ABAL_TCODCODE; return(SOFTERROR);
	}

if (( desc == 3 ) && ( type == 0 )) { desc = 4; reg = (WORD) *(fdex++); }
switch ( type ) {
	case 0	:	return(argsetw(desc,reg));
	case 1  :	return(argset1(desc,reg));
	case 2  :	return(argset2(desc,reg));
	case 3  :	return(argset3(desc,reg));
	default : 	err_val = ABAL_TCODFILE; return(SOFTERROR);
	}

}


VOID	release_dynamic_library( libctrl )
WORD	libctrl;
{
	/* If this Entry is valid */
	/* ---------------------- */
	if ((*(FuseBase + libctrl)).fusentry != MOINS_UN ) {

		/* If Library performed CICO redirection */
		/* ------------------------------------- */
		switch ( (*(FuseBase + libctrl)).fusetype ) {

			case _BDA_ASFUN12 :

#ifdef	ABAL14
#ifdef	DEBUGGER
				/* Remove ASFUN Debug Window */
				/* ------------------------- */
				asfun_wsup();
#endif
#endif	
			case _BDA_ZABAL	  :
			case _BDA_ASFUN11 :
			case _BDA_REDIRECT:

				/* Perform Request to de-re-direct */
				/* ------------------------------- */
				(VOID) x_redir(0,3,(BPTR) (*(FuseBase + libctrl)).fusedesc,sizeof(LDF_BDA));
#ifdef	ABAL14
#ifdef	DEBUGGER
				AsfunLibId = MOINS_UN;
#endif	/* ABAL14   */
#endif	/* DEBUGGER */

			}

		/* Allow the library to liberate it's self */
		/* --------------------------------------- */
		(VOID) FinRunTime( (*(FuseBase+libctrl)).fusentry );

		(*(FuseBase + libctrl)).fusentry = MOINS_UN;

		}

	return;

}

/*
 *	L I B F U S E (libctrl)
 *	-----------------------
 *	Liberation of User function Control Structure.
 *	Called  
 *		- 1   on execution of a STOP which does not perform a chain
 *		    operation thus requiring total liberation of all active 
 *		    dynamic libraries, 
 *		- 2   due to errors during the merge of old and new function
 *		    tables required by a STOP/CHAIN combination.
 *
 *	N.B.	This function ignores all errors !
 *
 */

VOID	LibFuse(FuseBase,libctrl)
struct fusework PTR	FuseBase;
WORD			libctrl;	/* Number of usable entries */
{
#ifdef	ABALPS
	WORD	x,y;

	/* If User Function Table pointer is valid */
	/* --------------------------------------- */
	if ( FuseBase != (struct fusework PTR) 0 ) {

		/* Liberate all entries in the table */
		/* --------------------------------- */
		while ( libctrl > 0 ) {

			/* Adjust Towards Zero */
			/* ------------------- */
			libctrl--;

			release_dynamic_library( libctrl );

			/* If Library Context is valid */
			/* --------------------------- */
			if ( (*(FuseBase+libctrl)).fusedesc != (LDF_BDA PTR) 0) {

				/* Liberate library Context storage zone */
				/* ------------------------------------- */
				liberate( (*(FuseBase+libctrl)).fusedesc );

				}

			/* If Library name is valid */
			/* ------------------------ */
			if ( (*(FuseBase+libctrl)).fusename != (BPTR) 0) {

				/* Liberate library name storage zone */
				/* ---------------------------------- */
				liberate( (*(FuseBase+libctrl)).fusename );

				}

			}

		/* Liberate and devalidate User Function Table Pointer */
		/* --------------------------------------------------- */
		liberate (FuseBase); 
		FuseBase = (struct fusework PTR) 0;
		}
#endif
	FuseCount = 0;
	return;

}

#ifdef	ABAL14
#ifdef	DEBUGGER

WORD	Init_exadb_4_afun( x, autoflag )
WORD	x;
WORD	autoflag;
{

	/* Establish Library ID for EXADB   */
	/* -------------------------------- */
	AsfunLibId  = x;

	/* Create Control Window for EXADB  */
	/* -------------------------------- */
	if ((errno = asfun_wcreat(autoflag)) != 0) {

		/* Release libraries and Return */
		/* ---------------------------- */
		return((AsfunLibId = MOINS_UN));
		} 

	/* Return Library ID */
	/* ----------------- */
	return( x );

}

	/* -------- */
#endif	/* DEBUGGER */
#endif	/* ABAL14   */
	/* -------- */


WORD	get_dll_filename( x, filename, namelen )
WORD	x;
BPTR	filename;
WORD	namelen;
{
	WORD	i;
	BPTR	tptr;
	/* Ensure valid library number */
	/* --------------------------- */
	if ( x >= FuseCount ) {

		/* Invalid library number */
		/* ---------------------- */
		err_val = ABAL_FUSEFAIL;
		return( SOFTERROR );

		}
	else if (!(tptr = (*(FuseBase + x)).fusename)) {
		/* Invalid library number */
		/* ---------------------- */
		err_val = ABAL_FUSEFAIL;
		return( SOFTERROR );

		}
	else	{
		for (i=0; i < namelen; i++ )
			if (!( *(filename + i) = *(tptr +i) ))
				break;
		if ( i < namelen ) {
			for (i=0; i < namelen; i++ )
				*(filename+i) = ' ';
			return( GOODRESULT );
			}
		else	{
			err_val = 63;
			return( SOFTERROR );
			}

		}

}


WORD	set_dll_filename( x, filename, namelen )
WORD	x;
BPTR	filename;
WORD	namelen;
{
	BPTR	tptr=(BPTR) 0;
	WORD	i;

	/* Ensure valid library number */
	/* --------------------------- */
	if ( x >= FuseCount ) {

		/* Invalid library number */
		/* ---------------------- */
		err_val = ABAL_FUSEFAIL;
		return( SOFTERROR );

		}

	/* Check if it has already been loaded */
	/* ----------------------------------- */
	else if ( (*(FuseBase + x)).fusentry != MOINS_UN ) {

    		/* we had better release it now without error  */
		/* ------------------------------------------- */
  		release_dynamic_library( x );
		}

	/* Attempt to Allocate the Name Storage Pointer */
	/* -------------------------------------------- */
	if ((tptr = (BPTR) allocate( namelen+1 )) == (BPTR) 0 ) {

		err_val = 27;
		return( SOFTERROR );

		}

	else	{
		/* Copy the string value checking for space */
		/* ---------------------------------------- */
		for (i=0; i < namelen; i++ )
			if ((*(tptr +i) = *(filename+i)) == ' ')
				break;
		*(tptr+i) = 0;
		liberate( (*(FuseBase + x)).fusename );
		(*(FuseBase + x)).fusename = tptr;
		return( GOODRESULT );
		}

}


WORD	load_dynamic_library(FuseBase, x, automode, overload )
struct	fusework PTR FuseBase;
WORD	x;
WORD	automode;
WORD	overload;
{
#ifdef	DEBUGGER
	WORD	debug_flag;
#endif

	/* ----------------------------------------- */
	/* Attempt to Initialise User Library        */
	/* ----------------------------------------- */
	/* Option Flag : 0 : (not PUBLIC not EXPORT) */
	/* ----------------------------------------- */
#ifdef	DEBUGGER
	debug_flag = 0;
#endif
	switch (((*(FuseBase + x)).fusetype = InitRunTime(
			(WORD) (overload == MOINS_UN ? x : overload),
			(BPTR) (*(FuseBase + x)).fusename,
			 0 ,
			(LDF_BDA PTR) (*(FuseBase + x)).fusedesc,
			sizeof(LDF_BDA)))) {

		case _BDA_ERROR : 
			/* Entry Not Correct due to Init Error */
			/* ----------------------------------- */
			(*(FuseBase + x)).fusentry = MOINS_UN;
			break;

		case _BDA_ZABAL	  :
		case _BDA_ASFUN11 :
		case _BDA_REDIRECT:
#ifdef	DEBUGGER
			debug_flag = 1;
#endif
		case _BDA_ASFUN12 : 
			/* CICO requiring Redirection */
			/* -------------------------- */
			/* Perform Request to de-re-direct */
			/* ------------------------------- */
			if ( x_redir(1,3,(BPTR) (*(FuseBase + x)).fusedesc,sizeof(LDF_BDA)) != 0 ) {
				errno = 44;
				return( SOFTERROR );
				}
#ifdef	DEBUGGER
#ifdef	ABAL14
			if ( debug_flag == 0 )

				/* Initialise ExaDb for ASFUN usage */
				/* -------------------------------- */
				if ( Init_exadb_4_afun( x, automode ) == MOINS_UN )
					return( SOFTERROR );

	/* ------------ */
#endif	/* ABAL14     	*/
#endif	/* DEBUGGER	*/
	/* ------------ */
		case _BDA_ORDINARY :

			/* Standard Library of functions */
			/* ----------------------------- */
			(*(FuseBase + x)).fusentry = (overload == MOINS_UN ? x : overload);

		}

	return(1);
}

/*
 *	L O A D _ T C O D E _ L I B R A R I E S
 *	---------------------------------------
 *	Called from 	:
 *
 *		EXLDF.InitFuse in order to load dynamic library
 *		table for tcode programs.
 *
 *		EXATTACH. in order to load dynamic library tables
 *		for Overlay Programs.
 *
 *	If succesful it returns the initialised library control table.
 *
 */

VPTR	load_tcode_libraries( wptr )
BPTR	wptr;
{
	struct fusework PTR FuseBase;

	WORD		wdex;	/* Offset into Table 		*/
	BPTR		tptr;	/* Temporary Name Pointer	*/
	LDF_BDA PTR 	xptr;	/* Structure to contain BDA id	*/
	WORD		x,l;	/* General purpose variables	*/
	WORD		loadstatus; /* Initial Load or Differ	*/
				/* ---------------------------- */

	/* Collect Function Count */
	/* ---------------------- */
	FuseCount = Tcodeword (( (BPTR) wptr ) );

	/* Allocate Function Table */
	/* ----------------------- */
	if ((FuseBase = (struct fusework PTR) allocate( (sizeof(struct fusework) * FuseCount ))) == (struct fusework PTR) 0) {
		errno = 27; return((VPTR) 0);
		}

	/* Initialise Table des fonctions Utilisateur */
	/* ------------------------------------------ */
	for ( x = 0, wdex = 2; x < FuseCount; x++ ) {

		/* Collect and control Length of User Library Name */
		/* ----------------------------------------------- */
		if ((l = (strlen( (BPTR) (wptr + wdex) ) + 1)) > 1) {

#ifdef	ABAL21
			/* Collect load status flag */
			/* ------------------------ */
			loadstatus = *(wptr + wdex + l + 1);
#endif
			/* Attempt to Allocate the Name Storage Pointer */
			/* -------------------------------------------- */
			if ((tptr = (BPTR) allocate( l )) == (BPTR) 0 ) {

				/* Abandon due to Error */
				/* -------------------- */
				LibFuse(FuseBase, x ); 
				errno = 27;   return((VPTR) 0);
				}

			/* Store the Name to Table Zone */
			/* ---------------------------- */
			(VOID) memcpy( (BPTR) tptr , (BPTR) (wptr+wdex) , (USINT) l );
			(*(FuseBase + x)).fusename = tptr;
/* #IJM 27/12/01 Begin */
			(*(FuseBase + x)).fuseload = MOINS_UN;
/* #IJM 27/12/01 End */

			/* Attempt to Allocate BDA Description Pointer */
			/* ------------------------------------------- */
			if (( xptr = (LDF_BDA PTR) allocate(sizeof(LDF_BDA))) == (LDF_BDA PTR) 0) {
				LibFuse(FuseBase,x); 
				liberate(tptr); 
				errno = 27; return((VPTR) 0);
				}

			(*(FuseBase +x)).fusedesc = xptr;

#ifdef	ABAL21
			if ( loadstatus ) {
#endif
				if ( load_dynamic_library( FuseBase,x, 0,
					(*(FuseBase + x)).fuseload
					/* Was MOINS_UN */ ) == SOFTERROR ) {

					/* Abandon due to Error */
					/* -------------------- */
					LibFuse(FuseBase, x ); 
					errno = 44;  
					return((VPTR) 0);

					}
#ifdef	ABAL21
				}
			else	(*(FuseBase + x)).fusentry = MOINS_UN;
#endif
			}

		else	{

			/* De-validate this Table entry */
			/* ---------------------------- */
/* #IJM 27/12/01 Begin */
			(*(FuseBase + x)).fuseload = MOINS_UN;
/* #IJM 27/12/01 End */
			(*(FuseBase + x)).fusentry = MOINS_UN;
			(*(FuseBase + x)).fusename = (BPTR) 0;
			(*(FuseBase + x)).fusedesc = (LDF_BDA PTR) 0;

			}

		/* Advance the Pointer index and Collect Function Count */
		/* ---------------------------------------------------- */
		wdex += l;	

		(*(FuseBase + x)).fusefunc = Tcodeword( (wptr + wdex) );

		wdex += FUSE_RESERVE;

		}


	return( FuseBase );

}

/*	I N I T F U S E ( )
 *	------------------- 
 *	Initialisation of User function Control Structure
 *
 */

WORD	InitFuse()
{
#ifdef ABALPS

	BPTR		wptr;	/* Pointeur sur Table du T-Code */

#ifdef	DEBUGGER
#ifdef	ABAL14
	AsfunLibId = MOINS_UN;
#ifdef	DEBUG_XLDF
	LdfTrapCount = 0;
#endif
	Asfunused();
#endif
#endif
	/* Attempt to Load User Function Table */
	/* ----------------------------------- */
	if ((wptr = (BPTR) kode_lode(adr_usr,(lng_usr * TCODEBLOCK))) == (BPTR) 0) {
		errno = 27;
		return( MOINS_UN );
		}

	FuseBase = load_tcode_libraries( wptr );

	/* Liberate T-Code Buffer Now */
	/* -------------------------- */
	liberate( wptr );

	if (FuseBase == (struct fusework PTR) 0) 
		return( SOFTERROR  );
	else	return( GOODRESULT );
#else
	err_val = 56;
	return( SOFTERROR );	
#endif
}

WORD	FuseChck( tptr , bptr )
BPTR	tptr;
BPTR	bptr;
{
	while (( *tptr ) && ( *bptr )) {
		if ( *tptr != *bptr ) 
			return(MOINS_UN);
		tptr++; bptr++;
		}
	if ((!( *tptr )) && (!( *bptr )))
		return(0);
	else	return(MOINS_UN);

}

/*	M E R G E F U S E ( )
 *	---------------------
 *	This function performs user library merging for the
 *	CHAIN operation of ABAL
 *	
 *	Exemple :	
 *		Program1	UDF 0	= BIBGR - X	=>	0
 *				UDF 1   = BIBWW - X	=>	1
 *
 *		Program2	UDF 0	= BIBMM - X	=>	0
 *				UDF 1	= BIBGR - X	=>	1
 *
 *	After the Chain BIBWW will be liberated, BIBMM will be
 *	initialised , and BIBGR will be merge relocated
 *	::::						=>	1
 *							=>	0
 *
 */

WORD	MergeFuse( )
{
#ifdef ABALPS
	BPTR	wptr;	/* Pointeur sur Table du T-Code */
	WORD	wdex;	/* Offset into Table 		*/
	BPTR	tptr;	/* Temporary Name Pointer	*/
	WORD	x,l,z;
	struct fusework	PTR 	lfusebase;
	WORD		lfusectrl;
	WORD	fusedex;
#ifdef	DEBUGGER
	WORD	debug_flag;	/* Debug switch for ASFUN	*/	
#endif

#ifdef	ABAL14
#ifdef	DEBUGGER
	
	/* Must test for normal PROGRAM CHAIN or EXADB 'G' Function */
	/* -------------------------------------------------------- */	
	if ( ExadbGoFunction != 0 ) {

		/* Reset GO FUNCTION FLAG */
		/* ---------------------- */
		ExadbGoFunction = 0;

		/* Liberate all Dynamic Libraries */
		/* ------------------------------ */
		LibFuse(FuseBase, FuseCount );

		/* Re-Install Dynamic libraries and Return */
		/* --------------------------------------- */
		return ( InitFuse() );

		}

#endif
#endif

	/* Ensure Program has User Libraries to Merge */
	/* ------------------------------------------ */
	if (FuseBase == (struct fusework PTR) 0)
		return( InitFuse() );

	/* -------------------------------------- */
	/* PERFORM PROGRAM CHAIN : MERGE RUN_TIME */
	/* -------------------------------------- */

	/* Allocate Temporary storage buffer */
	/* --------------------------------- */
	if ((wptr = (BPTR) allocate((lng_usr * TCODEBLOCK))) == (BPTR) 0 ) {
		LibFuse( FuseBase,FuseCount );
		errno = 27; return(MOINS_UN);
		}

	/* Read in the function Table Sectors */
	/* ---------------------------------- */
	if ( SectRead(TcodeFileHandle,(BPTR) wptr , (lng_usr * TCODEBLOCK) , adr_usr ) == MOINS_UN ) {
		LibFuse( FuseBase,FuseCount );
		liberate( wptr ); 
		return( MOINS_UN );
		}

	/* Collect Function Count */
	/* ---------------------- */
	lfusectrl = Tcodeword (( (BPTR) wptr ) );

	/* Allocate Function Table */
	/* ----------------------- */
	if ((lfusebase = (struct fusework PTR) allocate( (sizeof(struct fusework) * lfusectrl ))) == (struct fusework PTR) 0) {
		LibFuse(FuseBase, FuseCount );
		liberate( wptr );
		errno = 27; 
		return(MOINS_UN);
		}

	/* Initialise Table des fonctions Utilisateur */
	/* ------------------------------------------ */
	for ( x = 0, wdex = 2; x < lfusectrl; x++ ) {

		/* Collect and control Length of User Library Name */
		/* ----------------------------------------------- */
		if ((l = (strlen( (BPTR) (wptr + wdex) ) + 1)) > 1 ) {

			/* Allocate the Name Storage Pointer */
			/* --------------------------------- */
			if ((tptr = (BPTR) allocate( l )) == (BPTR) 0 ) {
				LibFuse( FuseBase,FuseCount );
				FuseBase = lfusebase;
				LibFuse(FuseBase, x );
				liberate( wptr );
				errno = 27;
				return(MOINS_UN);
				}

			/* Store the Name to Table Zone */
			/* ---------------------------- */
			(VOID) memcpy( (BPTR) tptr , (BPTR) (wptr+wdex) , (USINT) l );

			/* Check for Function already loaded */
			/* --------------------------------- */ 
			for ( z = 0; z < FuseCount; z++ )
				if (( (*(FuseBase+z)).fusename != (BPTR) 0)
				&&  ( FuseChck( tptr , (*(FuseBase+z)).fusename ) == 0 ))
					break;

			/* If Function already Loaded */
			/* -------------------------- */
			if ( z < FuseCount ) {

				liberate( tptr );

				/* Recopie the entry ID */
				/* -------------------- */
/* #IJM 27/12/01 Begin */
				(*(lfusebase + x)).fuseload = (*(FuseBase + z)).fuseload;
/* #IJM 27/12/01 End */
				(*(lfusebase + x )).fusename = (*(FuseBase + z)).fusename;
				(*(lfusebase + x )).fusentry = (*(FuseBase + z)).fusentry;
				(*(lfusebase + x )).fusedesc = (*(FuseBase + z)).fusedesc;
				(*(lfusebase + x )).fusetype = (*(FuseBase + z)).fusetype;

				/* Signal False to Avoid DSAC and Reset */
				/* ------------------------------------ */
				(*(FuseBase + z)).fusename = (BPTR) 0;
				(*(FuseBase + z)).fusentry = MOINS_UN;
				(*(FuseBase + z)).fusedesc = (LDF_BDA PTR) 0;
				(*(FuseBase + z)).fusetype = 0;
				}
			else	{



				(*(lfusebase + x)).fusename = tptr;
				(*(lfusebase + x )).fusentry = MOINS_UN;
				(*(lfusebase + x )).fusetype = 0;

				/* Indicate Init Needed */
				/* -------------------- */
				if (((*(lfusebase+x)).fusedesc = (LDF_BDA PTR) allocate(sizeof(LDF_BDA))) == (LDF_BDA PTR) 0) {
					LibFuse( FuseBase,FuseCount );
					FuseBase = lfusebase;
					LibFuse( FuseBase,x );
					liberate( wptr );
					errno = 27;
					return(MOINS_UN);
					}

				}
			}
		else	{



			(*(lfusebase + x)).fusentry = MOINS_UN;
			(*(lfusebase + x)).fusename = (BPTR) 0;
			(*(lfusebase + x)).fusedesc = (LDF_BDA PTR) 0;
			(*(lfusebase + x)).fusetype = 0;
			}
		wdex += l;
		(*(lfusebase + x)).fusefunc = Tcodeword((wptr + wdex));
		wdex += FUSE_RESERVE;
		}
	
	/* Liberate Old Function Table */
	/* --------------------------- */
	for ( x=0; x < FuseCount; x++ ) {

		/* If Function Needs liberation */
		/* ---------------------------- */	
		if ((*(FuseBase + x)).fusentry != MOINS_UN ) {

			/* If Library performed CICO redirection */
			/* ------------------------------------- */
			switch ( (*(FuseBase + x)).fusetype ) {

			case _BDA_ASFUN12 :
#ifdef	ABAL14
#ifdef	DEBUGGER
				/* Remove ASFUN Debug Window */
				/* ------------------------- */
				asfun_wsup();
#endif
#endif	
			case _BDA_ZABAL   :	
			case _BDA_ASFUN11 :
			case _BDA_REDIRECT:

				/* Perform Request to de-re-direct */
				/* ------------------------------- */
				(VOID) x_redir(0,3,(*(FuseBase + x)).fusedesc,sizeof(LDF_BDA));

				/* Remove EXADB window LINK */
				/* ------------------------ */
#ifdef	ABAL14
#ifdef	DEBUGGER
				AsfunLibId = MOINS_UN;
#endif	/* ABAL14   */
#endif	/* DEBUGGER */

				}

			/* Allow the library to liberate it's self */
			/* --------------------------------------- */
			(VOID) FinRunTime( (*(FuseBase+x)).fusentry );
			}

		/* Liberate the Structure if Valid */
		/* ------------------------------- */
		if ( (*(FuseBase+x)).fusedesc != (LDF_BDA PTR) 0) {
			liberate( (*(FuseBase+x)).fusedesc );
			}

		/* If Function Has a Name */
		/* ---------------------- */
		if ( (*(FuseBase+x)).fusename != (BPTR) 0) {
			liberate( (*(FuseBase+x)).fusename );
			}

		}

	/* Liberate File Work Zone and old Table */
	/* ------------------------------------- */
	liberate(FuseBase); liberate( wptr );

	/* Establish Function Controllers */
	/* ------------------------------ */
	FuseBase = lfusebase;
	FuseCount = lfusectrl;

/* This definition had been added to allow Staff Screener Dynamic Library to be Differed loading when chain merge underway */
/* In fact we were a bit heavy handed so the loop through the library table has been re-activated but the actual loading   */
/* itself is now shunted out to be performed when required, ie at the first function call. In order to correct the bug     */
/* encountered when a program(asfun,other) chains to a program(asfun,bimath,other) and back to a program(asfun,other)      */
/* the redirected overload that would have been performed by the previous version(prior to staffscreener) of this function */
/* is now stored into the LDF table to be used when the library is loaded upon first function call (wow ! no shit! )	   */

/* #ifdef IJM050201 */

	/* Ensure all Libraries are initialised */
	/* ------------------------------------ */	
	for ( x=0, lfusectrl = 0; x < FuseCount; x++ ) {

		/* MOINS_UN means needs Init */
		/* ------------------------- */
		if (( (*(FuseBase + x)).fusentry == MOINS_UN )
			/* If Filename is valid */
			/* -------------------- */
		&&  ( (*(FuseBase + x)).fusename != (BPTR) 0 )) {

			/* Search for a liberate Library Code */
			/* ------------------------------ */
			for ( z= 0; z < FuseCount; z++ ) {

				/* If Entry already allocated */
				/* -------------------------- */
				if (( (*(FuseBase + z)).fusentry == lfusectrl )
				||  ( (*(FuseBase + z)).fuseload == lfusectrl )) {
					z = 0; 
					lfusectrl++;
					}
				}			

#ifdef	before_27122001_ijm
			/* Attempt to load dynamic library */
			/* ------------------------------- */
			if ( load_dynamic_library( FuseBase,x, 0, lfusectrl++ ) == SOFTERROR ) {

				/* Abandon due to Error */
				/* -------------------- */
				LibFuse(FuseBase, x ); 
				liberate( wptr );
				errno = 44;  
				return(MOINS_UN);

				}
#else
/* #IJM 27/12/01 Begin */
			/* This must be stored for use by the differed loading mechanism */
			/* ------------------------------------------------------------- */
			(*(FuseBase + x)).fuseload = lfusectrl++;
/* #IJM 27/12/01 End */
#endif

			}
		}
/* #endif */

#endif
	return(0);

}


/*
 *	D O F U S E ( )
 *	---------------
 *	Control Transfer to a User Function
 *
 */
#ifdef	ABAL21
WORD	DoFuse( mode_flag )
WORD	mode_flag;
#else
WORD	DoFuse()
#endif
{
#ifdef	ABALPS
	WORD	NbFuse;
	WORD	NbFunc;
	WORD	NbArgs;
	WORD	eflag,etrap;
	WORD	ret_cod;
	WORD	Val_Flag;
	WORD	lerr_val;
	WORD	libctrl;
#ifdef	ABAL21	
	BPTR	callfdex;
#endif

	WORD LenDex;
	LenDex = 0;
	NbFunc = MOINS_UN;

#ifdef	ABAL21

	callfdex = fdex;

	/* Check if Standard LDF Tcode */
	/* --------------------------- */
	if (!(mode_flag)) 
#endif
		/* Collect Static Library Number (LDF) */
		/* ----------------------------------- */
		if ((NbFuse = (*(FuseBase + (libctrl = *(fdex++)))).fusentry) == MOINS_UN) {

			/* Attempt automatic loading */
			/* ------------------------- */
			if ( load_dynamic_library( FuseBase,libctrl, 1,
				(*(FuseBase + libctrl)).fuseload
				/* Was  MOINS_UN */ ) == SOFTERROR ) {
				err_val = ABAL_FUSEFAIL;
				return(SOFTERROR);
				}
			if ((NbFuse = (*(FuseBase + libctrl)).fusentry) == MOINS_UN) {
				err_val = ABAL_FUSEFAIL;
				return(SOFTERROR);
				}

			}

	/* Establish Arg Frame Pointer */
	/* --------------------------- */
	adex = fdex; NbArgs = 0;
	while ( (*(fdex++) & 1) != 0 );
	adesc = *(adex++); amode = 1;

	/* Test for Return Value Required */
	/* ------------------------------ */	
	if ( adesc & 0x0080 ) {	
		/* Check for VARIABLE */
		/* ------------------ */
		if ( (adesc & 0x0060) != 0x0060 ) { 
			etrap = Tcodeword( fdex);
			fdex += WORDSIZE;
			}
		/* Else REGISTER */
		/* ------------- */
		else 	etrap = (WORD) *(fdex++); 
		eflag = adesc; 
		amode =2;
		}
	else 	eflag = 0;

#ifdef	ABAL21

	/* Check for Tcode LDFE extended user function call */
	/* ------------------------------------------------ */
	if ( mode_flag ) { 

		/* Collect Library Selector ID Number */
		/* ---------------------------------- */
		if ( fuargset(1) == SOFTERROR )
			return( SOFTERROR );

		switch ((worktyp1 & 0x0003)) {
			case 0 :
			case 1 : break;
			case 2 : err_val = 56; return( SOFTERROR );
			case 3 : 
				switch ( *(workptr1) ) {
					case PROGRAM_POINTER	:
					case PROCEDURE_POINTER	: 
						return( indirect_procedure_call( callfdex ) );
					case SEGMENT_POINTER	: 
						return( indirect_segment_call( callfdex ) );
					case USER_POINTER	: 
						workval1  = balgetw((workptr1 + 3));
						NbFunc    = balgetw((workptr1 + 1));
						break;
					default     		: 
						err_val = 56; 
						return( SOFTERROR );

					}
			}

		/* Collect Library Number */
		/* ---------------------- */
		if ((NbFuse = (*(FuseBase + ((WORD) workval1))).fusentry) == MOINS_UN) {

			/* Attempt automatic loading */
			/* ------------------------- */
			if ( load_dynamic_library( FuseBase,workval1, 1,
				(*(FuseBase + ((WORD) workval1))).fuseload
				/* Was MOINS_UN */ ) == SOFTERROR ) {
				err_val = ABAL_FUSEFAIL;
				return(SOFTERROR);
				}
			NbFuse = (*(FuseBase + workval1)).fusentry;
			}
		}

#endif
	if (NbFuse == MOINS_UN) {
		err_val = ABAL_FUSEFAIL;
		return(SOFTERROR);
		}
	if ( NbFunc == MOINS_UN ) {

		/* Collect Function Selector ID Number */
		/* ----------------------------------- */
		if ( fuargset(1) == SOFTERROR ) 
			return(SOFTERROR);

		NbFunc = (WORD) workval1;	

		}

	switch ( amode ) {
		case 1 : if (( adesc & 0x80 ) != 0 )
				Val_Flag = 0;
			 else 	Val_Flag = 1;
			 break;
		case 2 : if (( adesc & 0x08 ) != 0 )
				Val_Flag = 0;
			 else 	Val_Flag = 1;
			 break;
		default: Val_Flag = 1;
		}


	/* Collect the Arguaments */
	/* ---------------------- */
	while ( fuargset(Val_Flag) != SOFTERROR ) {

		/* Both UNIX and VMS require the length of the Arguament */
		/* ----------------------------------------------------- */
		*(TcodeWordStack + (ip_next + LenDex) ) = worklen1;
		LenDex++;

		/* Check for Value to be Passed */
		/* ---------------------------- */
		if ( Val_Flag == 1 )  {

			if ( worktyp1 < 2 ) {
				/* Store a BAL type word in the work zone */
				/* -------------------------------------- */
				balputw( workval1 , (TcodeByteStack + worktop) );

				/* Create a pointer to it */
				/* ---------------------- */
				workptr1 = (TcodeByteStack + worktop);
				if ( worktyp1 == 0 ) 
					workptr1++;
				worktop += WORDSIZE;
				
				}
			}
		else
			/* Set Pointer Status */
			/* ------------------ */
			worktyp1 |= 0x0080;

		/* Limit Data Type Bits */
		/* -------------------- */
		worktyp1 &= 0x0083;

		/* Stack up the pointer */
		/* -------------------- */
		*((BPTR PTR) (TcodePtrStack + ((mindex + NbArgs) * sizeof(BPTR))) ) = (BPTR) workptr1;

		/* Stack up the Data Type */
		/* ---------------------- */
		askbuf [ NbArgs ] = (BYTE) worktyp1;

		/* Incrment Arg Counter */
		/* -------------------- */
		NbArgs++;

		/* Establish Next Pointer or Value Flag */
		/* ------------------------------------ */
		switch ( amode ) {
			case 1 : if (( adesc & 0x80 ) != 0 ) 
					Val_Flag = 0;
				 else 	Val_Flag = 1;
				 break;
			case 2 : if (( adesc & 0x08 ) != 0 ) 
					Val_Flag = 0; 
				 else 	Val_Flag = 1; 
				 break;
			default: Val_Flag = 1;
			}
		}

	/* Test for Arguament Evaluation Error */
	/* ----------------------------------- */
	if (( err_val != ABAL_TCODCODE ) && ( err_val != 0))
		return(SOFTERROR);

	/* Call the library function */	
	/* ------------------------- */
#ifdef	DEBUG_XLDF
	DebugCallRunTime( NbFuse, NbFunc, NbArgs );
#endif

	err_val = 0;
#ifdef	ABAL21
// #FC+IJM+BG 19042001
// IpcRaise(_SEMAPHORE_DLL); 
// Ceci a besoin d'être plus spécifique
// plutôt que de locker l'accès à toutes les Bdas, on ne lock que celui en cours.
	IpcRaise((_SEMAPHORE_DLL+NbFuse));
#endif
	ret_cod = CallRunTime( NbFuse , NbFunc , NbArgs ,(BPTR) askbuf ,(BPTR) (TcodePtrStack + (mindex * sizeof(BPTR))) ,(WPTR) (TcodeWordStack + ip_next));
#ifdef	ABAL21
// #FC+IJM+BG 19042001
// IpcDrop(_SEMAPHORE_DLL);
	IpcDrop((_SEMAPHORE_DLL+NbFuse));
#endif
	lerr_val = err_val;

#ifdef	PROLOGUE
	if ( stack_inspecter() != 0 ) {
		err_val = 668;
		return( SOFTERROR );
		}
#endif

	/* Check for Non-Void Function */
	/* --------------------------- */
	if ((eflag & 0x0080) != 0) {	

		/* Check for Register Return Value */
		/* ------------------------------- */
		if ( (eflag & 0x0060) == 0x0060 ) {
			freg [ etrap ] = ret_cod;
			xreg [ etrap ] = 0;
			}
		else	{
			/* Else Variable direct return Value */
			/* --------------------------------- */
			freg [diezreg + 2] = ret_cod;
			xreg [diezreg + 2] = 0;
			err_val   = 0;
			vputs((diezreg + 2),etrap);
			}
		}		
	/* Always return a Good Result (why not) */
	/* ------------------------------------- */
	if ((err_val = lerr_val) == 0) {
#ifdef	ABAL21
	/* -------------------------------------------------------- */
	/* If Event Wake up adresse flag has been set by ASFUN & Co */
	/* Then we must have an EXTERNAL event handler active which */
	/* Allows recovery of the real event from whoever to MIMO   */
	/* -------------------------------------------------------- */
		return( verify_wakeup_status( GOODRESULT ) );
#else
		return(GOODRESULT);
#endif
		}
	else	return(SOFTERROR);

#else
	err_val = 58; return(SOFTERROR);
#endif
}

/*
 *	This function is not called during the CHAIN/STOP but
 *	during the STOP STOP or due to untrapped error.
 *
 */

VOID	liberate_dynamic_libraries()
{
	if (( adr_usr != 0 ) || ( FuseCount != MOINS_UN )) {
	     LibFuse(FuseBase,FuseCount);
		FuseBase = (struct fusework PTR) 0;
		FuseCount = MOINS_UN;
		}
	return;
}

#endif	/* _EXLDF_C */
	/* -------- */

