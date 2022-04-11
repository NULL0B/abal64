/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXLDF.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 
/*
 * Mises a jour :
 * ------------
 * 20/11/1990 :	The options flag for InitRunTime has
 *              been reset to ZERO to indicate neither
 *              public nor exportable libraries since
 *              the #USER syntax does not currently
 *              offer a means to indicate these options
 *              This will be activated later (V1.5)
 *              to allow fine control of library use
 *
 * 17/12/1990 : The ASFUN library signature 2 indicates
 *              redirection is to be performed ASFUN1.2
 *              whilst signature 3 indicates an old
 *              ASFUN 1.1a / 1.1b library which does 
 *              require redirection by the executer
 *
 * 25/01/1991 : The ASFUN library signature 3 indicates
 *              that the ASFUN library 1.1b requires
 *              CICO redirection but that the extended
 *              EXADB window functions are not to be
 *              activated since they are not available.
 *
 * 21/11/1991 : Correction to ensure no exception and
 *              no core dump when chaining from a
 *              program with no user libraries to a
 *              program with user libraries in function
 *              "MergeFuse" which now calls "InitFuse"
 *              when the chained from program has no
 *              User Libraries.
 *
 * 07/10/1994 : Correction to ensure liberation of
 *              Libraries loaded by a program which
 *              chained to a program with no libraies
 *              which consequently stopped!
 *              (Ecco/Houless V1.2c Provisoire)
 *
 * 21/11/1994 : MergeFuse (cf)
 *
 * 02/02/2001 : MergeFuse has had its library init
 *              code removed since this causes problems
 *              with staff screener Z library which
 *              redirects CICO to the graphics driver
 *              and then this function loads the ASFUN
 *              module which was just hanging around
 *              to watch, load == redirect == boom!
 *
 * 05/02/2001 : New function in CLF7 has been added
 *              to allow (enfin) the filename of the 
 *              dynamic library to be set by the abal
 *              program ! pheeww .....
 *              This has required a new function here
 *              to implement the real dirty work!
 *
 * 27/12/01 (#IJM) Bug EXA-165: Regression since 2.1g. Correction to allow the chain/merge or programs with differing
 *                 libraries to co-operate with screener graphical library which may or may not exist.
 *	------------ 2.2b -------------------------------------------------
 * 13/08/03 : (#BG) Révision complète pour gestion des BSA/BDA compatible avec les Overlays (contextes).
 *	04/08/05 : (#BG) Modification de la gestion des BSA/BDA lors d'un CHAIN:
 *	                 si la BSA/BDA est déja en cours d'utilisation, alors son contexte d'exécution est conservé
 *	                 conformément au mode de fonctionnement Abal2.
 *	                 (les fonctions de terminaison et d'initialisation ne sont pas ré-appelées).
 *	                 Fonctionnement des BSA comme les BDA.
 *	                 Ne pas définir BEFORE040805 pour cette nouvelle gestion.
 *
 */


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

#ifdef	ABALX11
extern	int	exa_is_X11;
#endif

BPTR kode_lode( EXAWORD , EXAWORD );

#ifdef	DEBUG_XLDF
EXAWORD	LdfTrapCount;
EXAWORD	LdfTrapLib[10];

VOID	DebugCallRunTime( nbl, nbf, nba )
EXAWORD	nbl;
EXAWORD	nbf;
EXAWORD	nba;
{
	EXAWORD	i;
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
EXAWORD	absel;
{
	EXAWORD	n=0;
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


EXAWORD fuargset(type)
EXAWORD type;			/* 	Arguament Evaluation Set to prepare */
				/*	NB	0 => argsetw		    */
				/* 	Type de data desiree	*/
{
	EXAWORD	desc,reg;

reg = 0;
switch ( amode ) {
	case 1 :	desc = (adesc & 0x0060) >> 5;
			if (( adesc & 0x0010 ) != 0 ) { amode = 2; }
			else { amode = 0; }
			break;
	case 2 :
			desc = ( adesc & 0x0006) >> 1;
			if (( adesc & 1 ) != 0 ) { adesc = (EXAWORD) *(adex++);
						   amode = 1;
						}
			else { amode = 0; }
			break;
	default : amode = 0;
	case 0  : err_val = ABAL_TCODCODE; return(SOFTERROR);
	}

if (( desc == 3 ) && ( type == 0 )) { desc = 4; reg = (EXAWORD) *(fdex++); }
switch ( type ) {
	case 0	:	return(argsetw(desc,reg));
	case 1  :	return(argset1(desc,reg));
	case 2  :	return(argset2(desc,reg));
	case 3  :	return(argset3(desc,reg));
	default : 	err_val = ABAL_TCODFILE; return(SOFTERROR);
	}

}


VOID	release_dynamic_library( struct fusework PTR	fptr, EXAWORD	libctrl )
{
	/* If this Entry is valid */
	/* ---------------------- */
	if ((*(fptr + libctrl)).fuselock != MOINS_UN )
		return;
	else if ((*(fptr + libctrl)).fusentry != MOINS_UN ) {


		/* If Library performed CICO redirection */
		/* ------------------------------------- */
		switch ( (*(fptr + libctrl)).fusetype ) {

			case _BDA_ASFUN12 :

#ifdef	DEBUGGER
				/* Remove ASFUN Debug Window */
				/* ------------------------- */
				if ( exa_is_X11 < 2 ) {
					asfun_wsup();
					}
#endif	
			case _BDA_REDIRECT:
			case _BDA_ZABAL	  :
			case _BDA_ASFUN11 :

				/* Perform Request to de-re-direct */
				/* ------------------------------- */
				if ( RunTimeUsers( (*(fptr+libctrl)).fusesyst ) == 1 ) {
					(VOID) x_redir(0,3,(BPTR) (*(fptr + libctrl)).fusedesc,sizeof(LDF_BDA));
#ifdef	DEBUGGER
					AsfunLibId = MOINS_UN;
#endif	/* DEBUGGER */
					}

			}

		/* Allow the library to liberate it's self */
		/* --------------------------------------- */
		(VOID) FinRunTime( (*(fptr+libctrl)).fusesyst );

		(*(fptr + libctrl)).fusentry = MOINS_UN;

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
 *		- 3  during attachement / detachment operation
 *
 *	N.B.	This function ignores all errors !
 *
 */

EXAWORD	LibFuse(fptr,libctrl)
struct fusework PTR	fptr;
EXAWORD			libctrl;	/* Number of usable entries */
{
	EXAWORD	x,y;

	/* If User Function Table pointer is valid */
	/* --------------------------------------- */
	if ( fptr != (struct fusework PTR) 0 ) {

		/* Liberate all entries in the table */
		/* --------------------------------- */
		while ( libctrl > 0 ) {

			/* Adjust Towards Zero */
			/* ------------------- */
			libctrl--;

			release_dynamic_library(fptr, libctrl );

			/* If Library Context is valid */
			/* --------------------------- */
			if ( (*(fptr+libctrl)).fusedesc != (LDF_BDA PTR) 0) {

				/* Liberate library Context storage zone */
				/* ------------------------------------- */
				liberate( (*(fptr+libctrl)).fusedesc );

				}

			/* If library name is valid */
			/* ------------------------ */
			if ( (*(fptr+libctrl)).fusename != (BPTR) 0) {

				/* Liberate library name storage zone */
				/* ---------------------------------- */
				liberate( (*(fptr+libctrl)).fusename );

				}
			/* If Library name is valid */
			/* ------------------------ */
			if ( (*(fptr+libctrl)).fuseprog != (BPTR) 0) {

				/* Liberate library prog storage zone */
				/* ---------------------------------- */
				liberate( (*(fptr+libctrl)).fuseprog );

				}
			}

		/* Liberate and devalidate User Function Table Pointer */
		/* --------------------------------------------------- */
		liberate (fptr); 
		fptr = (struct fusework PTR) 0;
		}
	return( 0 );

}

#ifdef	DEBUGGER

EXAWORD	Init_exadb_4_afun( x, autoflag )
EXAWORD	x;
EXAWORD	autoflag;

#ifdef WEXADBDLL
{
return 0;
}
#else
{
#ifdef UNIX
	if ( exa_is_X11 < 2 ) {
#endif

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

#ifdef UNIX
		}
#endif

	/* Return Library ID */
	/* ----------------- */
	return( x );

}
#endif

	/* -------- */
#endif	/* DEBUGGER */
	/* -------- */


EXAWORD	get_dll_filename( x, filename, namelen )
EXAWORD	x;
BPTR	filename;
EXAWORD	namelen;
{
	EXAWORD	i;
	BPTR	tptr;
	/* Ensure valid library number */
	/* --------------------------- */
	if ( x >= FuseCount ) {

		/* Invalid library number */
		/* ---------------------- */
		err_val = ABAL_FUSEFAIL;
		return( SOFTERROR );
		}

	else if (!(tptr = (*(FuseBase + x)).fuseprog)) {
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


EXAWORD	get_dll_number( filename, namelen )
BPTR	filename;
EXAWORD	namelen;
{
	EXAWORD	x;
	BPTR	nptr;
	EXAWORD	i;

	if (!( FuseCount )) { err_val = 135; return( SOFTERROR ); }

	for ( x = 0; x < FuseCount; x++ ) {

		if (!( nptr = (*(FuseBase + x)).fusename ))
			continue;

		for ( i=0; i < namelen; i++ ) {
			if (( *(filename+i) == ' ' )
			||  ( *(nptr+i) == 0 ))
				break;
			else if ( *(nptr+i) != *(filename+i) )
				break;
			else	continue;
			}
		if (( *(filename+i) == ' ' )
		||  ( *(nptr+i) == 0 )) {
			err_val = 0;
			return( x );
			}
		}
		
	err_val = 135;
	return( SOFTERROR );
}

EXAWORD	set_dll_filename( x, filename, namelen )
EXAWORD	x;
BPTR	filename;
EXAWORD	namelen;
{
	BPTR	tptr=(BPTR) 0;
	EXAWORD	i;

	/* Ensure valid library number */
	/* --------------------------- */
	if ( x > FuseCount ) {

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
	  	release_dynamic_library(FuseBase, x );
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
		if ( (*(FuseBase + x)).fuseprog != (BPTR) 0 )
			liberate( (*(FuseBase + x)).fuseprog );
		(*(FuseBase + x)).fuseprog = tptr;
		return( GOODRESULT );
		}

}

EXAWORD	resolve_dynamic_library(fptr, x, automode, overload )
struct	fusework PTR fptr;
EXAWORD	x;
EXAWORD	automode;
EXAWORD	overload;
{
	(*(fptr + x)).fuselock  = MOINS_UN;
	(*(fptr + x)).fusesyst  = MOINS_UN;
	(*(fptr + x)).fusentry = MOINS_UN;
	(*(fptr + x)).fusetype = CheckRunTime(
			(EXAWORD) (overload == MOINS_UN ? x : overload),
			(BPTR) (*(fptr + x)).fusename,
			 0 ,
			&(*(fptr + x)).fusesyst,
			(BPTR) (*(fptr + x)).fuseprog,
			(LDF_BDA PTR) (*(fptr + x)).fusedesc,
			sizeof(LDF_BDA));
	return(1);
}

EXAWORD	load_dynamic_library(fptr, x, automode, overload )
struct	fusework PTR fptr;
EXAWORD	x;
EXAWORD	automode;
EXAWORD	overload;
{
#ifdef	DEBUGGER
	EXAWORD	debug_flag;
#endif

	/* ----------------------------------------- */
	/* Attempt to Initialise User Library        */
	/* ----------------------------------------- */
	/* Option Flag : 0 : (not PUBLIC not EXPORT) */
	/* ----------------------------------------- */
#ifdef	DEBUGGER
	debug_flag = 0;
#endif
	(*(fptr + x)).fuselock = MOINS_UN;
	switch (((*(fptr + x)).fusetype = InitRunTime(
			(EXAWORD) (overload == MOINS_UN ? x : overload),
			(BPTR) (*(fptr + x)).fusename,
			 0 ,
			&(*(fptr + x)).fusesyst,
			(BPTR) (*(fptr + x)).fuseprog,
			(LDF_BDA PTR) (*(fptr + x)).fusedesc,
			sizeof(LDF_BDA)))) {

		case _BDA_ERROR : 
			/* Entry Not Correct due to Init Error */
			/* ----------------------------------- */
			(*(fptr + x)).fusentry = MOINS_UN;
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
			if ( x_redir(1,3,(BPTR) (*(fptr + x)).fusedesc,sizeof(LDF_BDA)) != 0 ) {
				errno = 44;
				return( SOFTERROR );
				}
#ifdef	DEBUGGER
			if ( debug_flag == 0 )

				/* Initialise ExaDb for ASFUN usage */
				/* -------------------------------- */
				if ( Init_exadb_4_afun((*(fptr + x)).fusesyst+1, automode ) == MOINS_UN )
					return( SOFTERROR );

	/* ------------ */
#endif	/* DEBUGGER	*/
	/* ------------ */
		case _BDA_ORDINARY :

			/* Standard Library of functions */
			/* ----------------------------- */
			(*(fptr + x)).fusentry = (overload == MOINS_UN ? x : overload);

		}

	return(1);
}

/*
 *	A T T A C H _ T C O D E _ L I B R A R I E  
 *	-----------------------------------------
 *
 */
EXAWORD	attach_dynamic_library(
		struct	fusework PTR fptr,
		EXAWORD	x,
		EXAWORD	automode,
		EXAWORD	overload 
		)
{
	return( MOINS_UN );
}

/*
 *	A T T A C H _ T C O D E _ L I B R A R I E S 
 *	-------------------------------------------
 *
 */
VPTR	attach_tcode_libraries( BPTR wptr )
{
	struct fusework PTR fptr;
	EXAWORD		fcontrol;
	EXAWORD		wdex;	/* Offset into Table 		*/
	BPTR		tptr;	/* Temporary Name Pointer	*/
	LDF_BDA PTR 	xptr;	/* Structure to contain BDA id	*/
	EXAWORD		x,l;	/* General purpose variables	*/
	EXAWORD		loadstatus; /* Initial Load or Differ	*/
				/* ---------------------------- */

	/* Collect Function Count */
	/* ---------------------- */
	fcontrol = Tcodeword (( (BPTR) wptr ) );

	/* Allocate Function Table */
	/* ----------------------- */
	if ((fptr = (struct fusework PTR) allocate( (sizeof(struct fusework) * fcontrol ))) == (struct fusework PTR) 0) {
		errno = 27; return((VPTR) 0);
		}

	/* Initialise Table des fonctions Utilisateur */
	/* ------------------------------------------ */
	for ( x = 0, wdex = WORDSIZE; x < fcontrol; x++ ) {

		/* Collect and control Length of User Library Name */
		/* ----------------------------------------------- */
		if ((l = (strlen( (BPTR) (wptr + wdex) ) + 1)) > 1) {

			/* Collect load status flag */
			/* ------------------------ */
			loadstatus = *(wptr + wdex + l + 1);

			/* Attempt to Allocate the Name Storage Pointer */
			/* -------------------------------------------- */
			if ((tptr = (BPTR) allocate( l )) == (BPTR) 0 ) {

				/* Abandon due to Error */
				/* -------------------- */
				fcontrol = LibFuse(fptr, x ); 
				errno = 27;   return((VPTR) 0);
				}

			/* Store the Name to Table Zone */
			/* ---------------------------- */
			(VOID) memcpy( (BPTR) tptr , (BPTR) (wptr+wdex) , (USINT) l );
			(*(fptr + x)).fusename = tptr;
			(*(fptr + x)).fuseprog = (BPTR) 0;
			(*(fptr + x)).fuseload = MOINS_UN;

			/* Attempt to Allocate BDA Description Pointer */
			/* ------------------------------------------- */
			if (( xptr = (LDF_BDA PTR) allocate(sizeof(LDF_BDA))) == (LDF_BDA PTR) 0) {
				fcontrol = LibFuse(fptr,x); 
				liberate(tptr); 
				errno = 27; return((VPTR) 0);
				}

			/* This could do with a wipe ! */
			/* -------------------------  */
			memset( xptr, 0, sizeof( LDF_BDA ));

			(*(fptr +x)).fusedesc = xptr;

			if (((*(fptr + x)).fuselock = 
				attach_dynamic_library( fptr, x, 0, (*(fptr + x)).fuseload))
					== MOINS_UN ) {

				if ( loadstatus ) {
					if ( load_dynamic_library( fptr,x, 0,
						(*(fptr + x)).fuseload
						/* Was MOINS_UN */ ) == SOFTERROR ) {

						/* Abandon due to Error */
						/* -------------------- */
						fcontrol = LibFuse(fptr, x ); 
						errno = 44;  
						return((VPTR) 0);

						}
					}
				else	(*(fptr + x)).fusentry = MOINS_UN;
				}
			}

		else	{

			/* De-validate this Table entry */
			/* ---------------------------- */
			(*(fptr + x)).fuseload = MOINS_UN;
			(*(fptr + x)).fusentry = MOINS_UN;
			(*(fptr + x)).fusename = (BPTR) 0;
			(*(fptr + x)).fuseprog = (BPTR) 0;
			(*(fptr + x)).fusedesc = (LDF_BDA PTR) 0;

			}

		/* Advance the Pointer index and Collect Function Count */
		/* ---------------------------------------------------- */
		wdex += l;	

		(*(fptr + x)).fusefunc = Tcodeword( (wptr + wdex) );

		wdex += FUSE_RESERVE;

		}

	return( fptr );
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

VPTR	load_tcode_libraries( wptr, callstatus )
BPTR	wptr;
EXAWORD	callstatus;
{
	EXAWORD		wdex;	/* Offset into Table 		*/
	BPTR		tptr;	/* Temporary Name Pointer	*/
	LDF_BDA PTR 	xptr;	/* Structure to contain BDA id	*/
	EXAWORD		x,l;	/* General purpose variables	*/
	EXAWORD		loadstatus; /* Initial Load or Differ	*/
	struct fusework	PTR 	lfusebase;
	EXAWORD			lfusectrl;

	/* Collect Function Count */
	/* ---------------------- */
	lfusectrl = Tcodeword (( (BPTR) wptr ) );

	/* Allocate Function Table */
	/* ----------------------- */
	if ((lfusebase = (struct fusework PTR) allocate( (sizeof(struct fusework) * lfusectrl ))) == (struct fusework PTR) 0) {
		errno = 27; return((VPTR) 0);
		}

	/* Initialise Table des fonctions Utilisateur */
	/* ------------------------------------------ */
	for ( x = 0, wdex = WORDSIZE; x < lfusectrl; x++ ) {

		/* Collect and control Length of User Library Name */
		/* ----------------------------------------------- */
		if ((l = (strlen( (BPTR) (wptr + wdex) ) + 1)) > 1) {

			/* Collect load status flag */
			/* ------------------------ */
			loadstatus = *(wptr + wdex + l + 1);

			/* Attempt to Allocate the Name Storage Pointer */
			/* -------------------------------------------- */
			if ((tptr = (BPTR) allocate( l )) == (BPTR) 0 ) {

				/* Abandon due to Error */
				/* -------------------- */
				lfusectrl = LibFuse(lfusebase, x ); 
				errno = 27;   return((VPTR) 0);
				}

			/* Store the Name to Table Zone */
			/* ---------------------------- */
			(VOID) memcpy( (BPTR) tptr , (BPTR) (wptr+wdex) , (USINT) l );
			(*(lfusebase + x)).fusename = tptr;
			(*(lfusebase + x)).fuseprog = (BPTR) 0;

/* #IJM 27/12/01 Begin */
			(*(lfusebase + x)).fuselock = MOINS_UN;
			(*(lfusebase + x)).fuseload = MOINS_UN;
/* #IJM 27/12/01 End */

			/* Attempt to Allocate BDA Description Pointer */
			/* ------------------------------------------- */
			if (( xptr = (LDF_BDA PTR) allocate(sizeof(LDF_BDA))) == (LDF_BDA PTR) 0) {
				lfusectrl = LibFuse(lfusebase,x); 
				liberate(tptr); 
				errno = 27; return((VPTR) 0);
				}

			/* This could do with a wipe ! */
			/* -------------------------  */
			memset( xptr, 0, sizeof( LDF_BDA ));

			(*(lfusebase +x)).fusedesc = xptr;

			if ( loadstatus ) {

				if ( load_dynamic_library( lfusebase,x, 0,
					(*(lfusebase + x)).fuseload
					/* Was MOINS_UN */ ) == SOFTERROR ) {

					/* Abandon due to Error */
					/* -------------------- */
					lfusectrl = LibFuse(lfusebase, x ); 
					errno = 44;  
					return((VPTR) 0);
					}
				}
			else if ( callstatus ) {
				if ( resolve_dynamic_library( lfusebase,x, 0,
					(*(lfusebase + x)).fuseload
					/* Was MOINS_UN */ ) == SOFTERROR ) {

					/* Abandon due to Error */
					/* -------------------- */
					lfusectrl = LibFuse(lfusebase, x ); 
					errno = 44;  
					return((VPTR) 0);
					}
				}
			else	(*(lfusebase + x)).fusentry = MOINS_UN;
			}

		else	{

			/* De-validate this Table entry */
			/* ---------------------------- */
/* #IJM 27/12/01 Begin */
			(*(lfusebase + x)).fuseload = MOINS_UN;
/* #IJM 27/12/01 End */
			(*(lfusebase + x)).fusentry = MOINS_UN;
			(*(lfusebase + x)).fusename = (BPTR) 0;
			(*(lfusebase + x)).fuseprog = (BPTR) 0;
			(*(lfusebase + x)).fusedesc = (LDF_BDA PTR) 0;

			}

		/* Advance the Pointer index and Collect Function Count */
		/* ---------------------------------------------------- */
		wdex += l;	

		(*(lfusebase + x)).fusefunc = Tcodeword( (wptr + wdex) );

		wdex += FUSE_RESERVE;

		}

	return( lfusebase );
}

/*	I N I T F U S E ( )
 *	------------------- 
 *	Initialisation of User function Control Structure
 *
 */

EXAWORD	InitFuse()
{
	BPTR		wptr;	/* Pointeur sur Table du T-Code */

#ifdef	DEBUGGER
	AsfunLibId = MOINS_UN;
#ifdef	DEBUG_XLDF
	LdfTrapCount = 0;
#endif
	if ( exa_is_X11 < 2 ) {
		Asfunused();
		}
#endif
	/* Attempt to Load User Function Table */
	/* ----------------------------------- */
	if ((wptr = (BPTR) kode_lode(adr_usr,(lng_usr * TCODEBLOCK))) == (BPTR) 0) {
		errno = 27;
		return( MOINS_UN );
		}

	/* Collect Function Count */
	/* ---------------------- */
	FuseCount = Tcodeword (( (BPTR) wptr ) );
	FuseBase = load_tcode_libraries( wptr, 0 );

	/* Liberate T-Code Buffer Now */
	/* -------------------------- */
	liberate( wptr );

	if (FuseBase == (struct fusework PTR) 0) 
		return( SOFTERROR  );
	else	return( GOODRESULT );
}

EXAWORD	FuseChck( tptr , bptr )
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
 *	It has been rebuilt around the new low level handle
 *	management mechanisms allowing libraries to be loaded
 *	and shared by overlays. (Abal 3.1/32)
 */

EXAWORD	MergeFuse( )
{
	BPTR	wptr;	/* Pointeur sur Table du T-Code */
	EXAWORD	wdex;	/* Offset into Table 		*/
	BPTR	tptr;	/* Temporary Name Pointer	*/
	EXAWORD	x,l,z;
	struct fusework	PTR 	lfusebase;
	EXAWORD			lfusectrl;
	EXAWORD	fusedex;

#ifdef	DEBUGGER

	EXAWORD	debug_flag;	/* Debug switch for ASFUN	*/	
	
	/* Must test for normal PROGRAM CHAIN or EXADB 'G' Function */
	/* -------------------------------------------------------- */	
	if ( ExadbGoFunction != 0 ) {

		/* Reset GO FUNCTION FLAG */
		/* ---------------------- */
		ExadbGoFunction = 0;

		/* Liberate all Dynamic Libraries */
		/* ------------------------------ */
		FuseCount = LibFuse(FuseBase, FuseCount );

		/* Re-Install Dynamic libraries and Return */
		/* --------------------------------------- */
		return ( InitFuse() );

		}

	/* -------- */
#endif	/* DEBUGGER */
	/* -------- */

	/* Ensure program has user libraries to merge */
	/* ------------------------------------------ */
	if (FuseBase == (struct fusework PTR) 0)
		return( InitFuse() );

	/* PERFORM PROGRAM CHAIN : MERGE RUN_TIME */
	/* -------------------------------------- */

	/* Attempt to load user library table */
	/* ---------------------------------- */
	if ((wptr = (BPTR) kode_lode(adr_usr,(lng_usr * TCODEBLOCK))) == (BPTR) 0) {
		FuseCount = LibFuse( FuseBase,FuseCount );
		errno = 27;
		return( MOINS_UN );
		}

	/* Collect library count, load libraries, liberate buffer */
	/* ------------------------------------------------------ */
	lfusectrl = Tcodeword (( (BPTR) wptr ) );
	lfusebase = load_tcode_libraries( wptr, 1 );
	liberate( wptr );

	/* Ensure new table has been Loaded */
	/* -------------------------------- */	
	if (!( lfusebase )) {
		FuseCount = LibFuse( FuseBase,FuseCount );
		errno = 27;
		return( MOINS_UN );
		}

	/* Release old table, and Install new table before Exit */
	/* ---------------------------------------------------- */
	FuseCount = LibFuse( FuseBase,FuseCount );
	FuseCount = lfusectrl; FuseBase = lfusebase;

	return( 0 );

}


/*
 *	D O F U S E ( )
 *	---------------
 *	Control Transfer to a User Function
 *
 */


EXAWORD	BdaNullPointer=0;
EXAWORD	get_bda_null_pointer() { return( BdaNullPointer ); }
VOID	set_bda_null_pointer(EXAWORD v) { BdaNullPointer = v; }

EXAWORD	DoFuse( mode_flag )
EXAWORD	mode_flag;
{
	EXAWORD	NbFuse;
	EXAWORD	NbFunc;
	EXAWORD	NbArgs;
	EXAWORD	eflag,etrap;
	EXAWORD	ret_cod;
	EXAWORD	Val_Flag;
	EXAWORD	lerr_val;
	EXAWORD	libctrl;
	BPTR	callfdex;

	EXAWORD LenDex;
	LenDex = 0;
	NbFunc = MOINS_UN;

	callfdex = fdex;

	/* Check if Standard LDF Tcode */
	/* --------------------------- */
	if (!(mode_flag))  {

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
		}

	/* Establish Arg Frame Pointer */
	/* --------------------------- */
	adex = fdex; NbArgs = 0;
	while ( (*(fdex++) & 1) != 0 );
	adesc = *(adex++);
	amode = 1;

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
		else 	etrap = (EXAWORD) *(fdex++); 
		eflag = adesc; 
		amode =2;
		}
	else 	eflag = 0;

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
#ifdef	ABAL4
					case REMOTE_POINTER	:
#endif
#ifdef	ABAL64
					case OFFSET_POINTER	:
#endif
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
		if ((NbFuse = (*(FuseBase + ((EXAWORD) workval1))).fusentry) == MOINS_UN) {

			/* Attempt automatic loading */
			/* ------------------------- */
			if ( load_dynamic_library( FuseBase,workval1, 1,
				(*(FuseBase + ((EXAWORD) workval1))).fuseload
				/* Was MOINS_UN */ ) == SOFTERROR ) {
				err_val = ABAL_FUSEFAIL;
				return(SOFTERROR);
				}
			NbFuse = (*(FuseBase + workval1)).fusentry;
			}
		}


	if (NbFuse == MOINS_UN) {
		err_val = ABAL_FUSEFAIL;
		return(SOFTERROR);
		}
	if ( NbFunc == MOINS_UN ) {

		/* Collect Function Selector ID Number */
		/* ----------------------------------- */
		if ( fuargset(1) == SOFTERROR ) 
			return(SOFTERROR);

		NbFunc = (EXAWORD) workval1;	

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
	while ( 1 ) {

		if ( fuargset(Val_Flag) == SOFTERROR ) {
			if (!( BdaNullPointer ))
				break;
			else if ( err_val != 118 )
				break;
			else	{
				worklen1= worktyp1 = workval1 = err_val = 0;
				workptr1=(BPTR) 0;
				}
			}

		/* Both UNIX and VMS require the length of the Arguament */
		/* ----------------------------------------------------- */
		*(TcodeWordStack + (ip_next + LenDex) ) = worklen1;
		LenDex++;

		/* Check for Value to be Passed */
		/* ---------------------------- */
		if ( Val_Flag == 1 )  {

			switch (( worktyp1 & VARB_ISOL)) {
				case	VARB_INT64	:	
					balput64( workval1 , (TcodeByteStack + worktop) );
					workptr1 = (TcodeByteStack + worktop);
					worktop += WORDSIZE;
					break;
				case	VARB_INT32	:	
					balputl( workval1 , (TcodeByteStack + worktop) );
					workptr1 = (TcodeByteStack + worktop);
					worktop += WORDSIZE;
					break;
				case	VARB_FOUR	:
				case	VARB_INT8	:
				case	VARB_INT16	:
					balputw( workval1 , (TcodeByteStack + worktop) );

					/* Create a pointer to it */
					/* ---------------------- */
					workptr1 = (TcodeByteStack + worktop);

					/* Point to low byte of INT8 */
					/* ------------------------- */
					if ((worktyp1 & VARB_STR) == 0 ) 
						workptr1++;
					worktop += WORDSIZE;
					break;
				}
			}
		else
			/* Set Pointer Status */
			/* ------------------ */
			worktyp1 |= 0x0080;

		/* Limit Data Type Bits */
		/* -------------------- */
		worktyp1 &= (VARB_ISOL | 0x80);

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
	if (( err_val != ABAL_TCODCODE ) && ( err_val != 0)) {
		if (!( BdaNullPointer ))
			return( SOFTERROR );
		else if ( err_val != 118 )
			return(SOFTERROR);
		else	err_val = 0;
		}

	/* Call the library function */	
	/* ------------------------- */
#ifdef	DEBUG_XLDF
	DebugCallRunTime( NbFuse, NbFunc, NbArgs );
#endif

	err_val = 0;

	IpcRaise((_SEMAPHORE_DLL+NbFuse));

	NbFuse = (*(FuseBase + NbFuse)).fusesyst;

	ret_cod = CallRunTime( NbFuse , NbFunc , NbArgs ,(BPTR) askbuf ,(BPTR) (TcodePtrStack + (mindex * sizeof(BPTR))) ,(WPTR) (TcodeWordStack + ip_next));

	IpcDrop((_SEMAPHORE_DLL+NbFuse));
	lerr_val = err_val;

#ifdef	PROLOGUE
	if ( stack_inspecter() != 0 ) {
		err_val = 668;
		return( SOFTERROR );
		}
#endif	/* PROLOGUE */

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
		/* -------------------------------------------------------- */
		/* If Event Wake up adresse flag has been set by ASFUN & Co */
		/* Then we must have an EXTERNAL event handler active which */
		/* Allows recovery of the real event from whoever to MIMO   */
		/* -------------------------------------------------------- */
		return( verify_wakeup_status( GOODRESULT ) );
		}
	else	return(SOFTERROR);

}

/*
 *	This function is not called during the CHAIN/STOP but
 *	during the STOP STOP or due to untrapped error.
 *
 */

VOID	liberate_dynamic_libraries()
{
	if (( adr_usr != 0 ) && ( FuseCount != MOINS_UN )) {
	     FuseCount = LibFuse(FuseBase,FuseCount);
		}

	FuseBase = (struct fusework PTR) 0;
	FuseCount = MOINS_UN;
	return;
}

#include "excallb.c"


#endif	/* _EXLDF_C */
	/* -------- */

