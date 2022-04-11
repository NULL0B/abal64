/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBAFUN.C  				*/
/*		Version :	1.4c / 2.1d				*/
/*		Date 	:	25/03/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
/* This module Contains the Interfacing functions for ASFUN usage	*/
/*----------------------------------------------------------------------*/

#ifndef	_EXDBAFUN_C
#define	_EXDBAFUN_C

#define	DEBUGGER

#include "exdebug.h"
#include "bda.h"

#include "exdbffff.h"
#define	ASFUN_WINIT	0
#define	ASFUN_WCREAT	1
#define ASFUN_WSUP	2
#define	ASFUN_WWRITE	3
#define	ASFUN_WSELECT	4
#define	ASFUN_WINV	5
#define	ASFUN_WVIS	6
#define	ASFUN_WIMPL	10
#define ASFUN_WGETIMPL  50

#define	INVALID_WINDOW_HANDLE	MOINS_UN
#define NULL_IMPLICITE	        0
#define	MONITOR_IMPLICITE	0
#define PROGRAM_IMPLICITE	1
#define	MONITOR_VISIBLE  	0
#define PROGRAM_VISIBLE  	1


				/* ------------------------------------ */
EXAWORD	BibDynUsed;		/*					*/
EXAWORD	VisibleWindowUser;	/* Current Window condition for DB	*/
EXAWORD	AsfunLibId;		/* Activated library identity		*/
EXAWORD	MonitorWindowHandle;	/* Created Special Exadb Type Window	*/
EXAWORD	ProgramImpliciteHandle;	/* Current Program Implicite window	*/
EXAWORD	ImpliciteUser;		/* Indicates who has and must keep impl	*/
EXABYTE	AsfunBuffer[61];	/* Window Creation Description		*/
BPTR	AsfunPstack[10];	/* Pointer stack for Dynamic lib call	*/
EXAWORD	AsfunWstack[10];	/* Length stack for Dynamic lib call	*/
EXABYTE	AsfunBstack[10];	/* Byte stack for Dynamic lib call	*/
				/* ------------------------------------ */

EXTERN	EXAWORD	ScreenCol;
EXTERN	EXAWORD	ScreenLin;
EXTERN	EXAWORD	monitor_execution_mode;

#ifndef UNIX
VOID	asfun_program_implicite(VOID);
VOID	asfun_program_visible(VOID);
#else
VOID	asfun_program_implicite();
VOID	asfun_program_visible();
#endif

#ifdef	WIN32
void	ExadbSelecteFenetre(void);
void	ExadbDeselecteFenetre(void);
#endif

EXAWORD	AsFun_Active()
{
#ifdef	WIN1632
	return(0);
#else
	return(AsfunLibId);
#endif
}

/*	Function performing dynamic library linkage call	*/
/*	------------------------------------------------	*/
/*	Used for Size optimisation of EXADB			*/
/*								*/

EXAWORD	asfun_connect(AsfunFunc,AsfunNbArgs)
EXAWORD	AsfunFunc;
EXAWORD	AsfunNbArgs;
{
	/* Perform call only if ASFUN has been detected */
	/* -------------------------------------------- */
	if ( AsfunLibId != MOINS_UN ) {
#ifdef	UNIX
		return(CallRunTime((AsfunLibId-1),AsfunFunc,AsfunNbArgs,(BPTR) AsfunBstack,(BPTR) AsfunPstack,(BPTR) AsfunWstack));
#else
		return(CallRunTime(AsfunLibId,AsfunFunc,AsfunNbArgs,(BPTR) AsfunBstack,(BPTR) AsfunPstack,(BPTR) AsfunWstack));
#endif
		}
	else	{
		return(MOINS_UN);
		}
}


VOID	set_monitior_window_handle()
{
	/* Prepare Arguament Passing tables */
	/* ------------ -------------------- */
	AsfunPstack[0]  = (WPTR) &MonitorWindowHandle;
	AsfunWstack[0]  = 2;
	AsfunBstack[0]  = 0x01;
	return;
}

/*	Prepares a pointer to the 'PROGRAM IMPLICITE WINDOW' handle
 *	ready to receive the value returned by asfun for WGETIMPL()
 */

VOID	set_program_window_handle()
{
	/* Prepare Arguament Passing tables */
	/* ------------ -------------------- */
	AsfunPstack[0]  = (WPTR) &ProgramImpliciteHandle;
	AsfunWstack[0]  = 2;
	AsfunBstack[0]  = 0x81;
	return;
}


/*
 *	A S F U N _ W S U P ( )
 *	-----------------------
 *	Destruction of the EXADB control window by the ASFUN dynamic
 *	window library
 */

VOID	asfun_wsup( )
{
	if ( MonitorWindowHandle != MOINS_UN ) {

		/* x_cprintf((BPTR) " asfun_wsup(TOP) "); x_getch(); */

		/* Establish Window identification Handle */
		/* -------------------------------------- */
		set_monitior_window_handle();

		/* Perform Window Supression */
		/* ------------------------- */
		(VOID) asfun_connect(ASFUN_WSUP,1);

		/* Return to Caller */
		/* ---------------- */
		MonitorWindowHandle = MOINS_UN;

		}

	return;

}

/*
 *	A S F U N _ W C R E A T ( )
 *	---------------------------
 *	Creation of the EXADB control window by the ASFUN dynamic
 *	window library
 *
 */

EXTERN	EXAWORD fsame;

EXAWORD	asfun_wcreat( autoflag )
EXAWORD	autoflag;
{
	EXAWORD	wcerr;

	/* Indicates debugger window must be refreshed */
	fsame = EXDB_FFFF;

	/* Prepare Arguament Passing tables */
	/* ------------ -------------------- */
	MonitorWindowHandle = MOINS_UN;
	AsfunPstack[0]  = (WPTR) &MonitorWindowHandle; 
	AsfunWstack[0]  = 2;
	AsfunBstack[0]  = 0x81;
	AsfunPstack[1]  = (BPTR) AsfunBuffer;	 	
	AsfunWstack[1]  = 61;
	AsfunBstack[1]  = 0x83;

	/* Create window description Zone */
	/* ------------------------------ */
	AsfunBuffer[0]  = 0; AsfunBuffer[1] = 0;
	AsfunBuffer[2]  = 0; AsfunBuffer[3] = 1;
	AsfunBuffer[4]  = 0; AsfunBuffer[5] = 1;
	AsfunBuffer[6]  = 0; AsfunBuffer[7] = ScreenLin;
	AsfunBuffer[8]  = 0; AsfunBuffer[9] = ScreenCol; 
				/* ------------ */
	AsfunBuffer[10] = 0;	/* Normal ATB 	*/
	AsfunBuffer[11] = 11;	/* Yellow	*/
	AsfunBuffer[12] = 4;	/* on Blue	*/
				/* ------------ */
	/* Fenetre de type EXADB Control */
	/* ----------------------------- */
	AsfunBuffer[13] = 0x80; AsfunBuffer[14] = 2;

	/* Length of Title to be displayed */
	/* ------------------------------- */
	AsfunBuffer[15] = 0; AsfunBuffer[16] = 0;

	/* Set TITRE$ and CADUSR$ to SPACE */
	/* ------------------------------- */
	memset((BPTR) &AsfunBuffer[17] , ' ' , 40 );

	AsfunBuffer[57] = 0; AsfunBuffer[58] = 0;
	AsfunBuffer[59] = 0; AsfunBuffer[60] = 0;

	/* Indicate DEBUG implicite */
	/* ------------------------ */
	ImpliciteUser           = MONITOR_IMPLICITE;
	ProgramImpliciteHandle  = NULL_IMPLICITE;
	VisibleWindowUser       = MONITOR_VISIBLE;
 	
	/* Perform Library Call */
	/* -------------------- */
	if ((wcerr = asfun_connect(ASFUN_WCREAT,2)) != 0 ) 
		return( wcerr );

	/* Check for AUTO INIT via CALL RUNTIME and DOFUSE */
	/* ----------------------------------------------- */
	if ( autoflag ) {

		/* This may be a STEP or an EXEC 	      */	
		/* if EXEC then we must ensure PROGRAM active */
		/* ------------------------------------------ */
		if ( monitor_execution_mode )
			asfun_program_visible();

		/* In both cases the implicite must be set to PROGRAM */
		/* -------------------------------------------------- */
		asfun_program_implicite();

		}

	/* Indicate success ie ERROR = 0 */
	/* ----------------------------- */
	return( 0 );

}

/*
 *	A S F U N _ P R O G R A M _ I M P L I C I T E
 *	---------------------------------------------
 *	Establishs the Application Program Implicite Window Handle
 *
 */

VOID	asfun_program_implicite()
{
	EXAWORD	v;
	if (((v = AsFun_Active()) != MOINS_UN )
	&&  ( ImpliciteUser != PROGRAM_IMPLICITE )) {

#ifdef	WIN1632
		ExadbDeselecteFenetre();
#else
		/* Establish Program Implicite Window */
		/* ---------------------------------- */	
		AsfunPstack[0]  = (WPTR) &ProgramImpliciteHandle;
		AsfunWstack[0]  = 2;
		AsfunBstack[0]  = 0x01;
		(VOID) asfun_connect(ASFUN_WIMPL,1);
#endif
		/* Indicate PROGRAM implicite */
		/* -------------------------- */
		ImpliciteUser = PROGRAM_IMPLICITE;

		}
	return;
}

/*
 *	A S F U N _ M O N I T O R _ I M P L I C I T E
 *	---------------------------------------------
 *
 *	First 
 *		Collects the Application Program Implicite Window Handle
 *	Then
 *		Establishs the Debug Monitor Implicite Window Handle
 *
 */

VOID	asfun_monitor_implicite()
{
	EXAWORD	v;
	if ((v = AsFun_Active()) == MOINS_UN ) {
		return;
		}
	if ( ImpliciteUser != MONITOR_IMPLICITE ) {

#ifdef	WIN1632
		ExadbSelecteFenetre();
#else
		/* Establish pointer to Program Implicite Handle */
		/* --------------------------------------------- */
		set_program_window_handle();

		/* Collect current implicite window identity */
		/* ----------------------------------------- */
		(VOID) asfun_connect(ASFUN_WGETIMPL,1);

		set_monitior_window_handle();
		(VOID) asfun_connect(ASFUN_WIMPL,1);
#endif
		/* Indicate DEBUG implicite */
		/* ------------------------ */
		ImpliciteUser = MONITOR_IMPLICITE;

		}

	return;

}

/*
 *	A S F U N _ P R O G R A M _ V I S I B L E
 *	-----------------------------------------
 *	Renders the Application Program Window Context visible
 *
 */

VOID	asfun_program_visible()
{
	if (( VisibleWindowUser != PROGRAM_VISIBLE )
	&&  ( MonitorWindowHandle != INVALID_WINDOW_HANDLE )) {

		/* Establish Program Window active */
		/* ------------------------------- */
		set_monitior_window_handle();

		/* Make the Moniteur window INVISIBLE */
		/* ---------------------------------- */
		(VOID) asfun_connect(ASFUN_WINV,1);

		VisibleWindowUser = PROGRAM_VISIBLE;

		}

	return;
}

/*
 *	A S F U N _ M O N I T O R _ V I S I B L E
 *	-----------------------------------------
 *	Renders the Debug Monitor Window Context visible
 *
 */

VOID	asfun_monitor_visible()
{
	if (( VisibleWindowUser   != MONITOR_VISIBLE )
	&&  ( MonitorWindowHandle != INVALID_WINDOW_HANDLE )) {

		/* Collect Moniteur Window Handle */
		/* ------------------------------ */
		set_monitior_window_handle();

		/* Make the Moniteur Window VISIBLE */
		/* -------------------------------- */
		(VOID) asfun_connect(ASFUN_WVIS,1);

		VisibleWindowUser = MONITOR_VISIBLE;

		}

	return;
}

#ifndef	ABAL21
VOID	AsFun_DbShow()
{

#ifdef	ASFUN_MERDE

	/* Ensure program has the implicite */
	/* -------------------------------- */
	if (( ImpliciteUser       == PROGRAM_IMPLICITE )
	&&  ( MonitorWindowHandle != INVALID_WINDOW_HANDLE )) {

		/* Establish pointer to Program Implicite Handle */
		/* --------------------------------------------- */
		set_program_window_handle();

		/* Collect current implicite window identity */
		/* ----------------------------------------- */
		(VOID) asfun_connect(ASFUN_WGETIMPL,1);

		}
#endif

	if (( VisibleWindowUser   != MONITOR_VISIBLE ) 
	&&  ( MonitorWindowHandle != INVALID_WINDOW_HANDLE )) {

		/* Collect Moniteur window Handle */
		/* ------------------------------ */
		set_monitior_window_handle();

		/* Make Moniteur window VISIBLE */
		/* ---------------------------- */
		(VOID) asfun_connect(ASFUN_WVIS,1);

		VisibleWindowUser = MONITOR_VISIBLE;

		}

	return;
}
#endif

/*
 *	A S F U N _ S W A P S T A T E ( )
 *	---------------------------------
 *	This function hides or makes visible the debug information window.
 *	It is called from the function S W A P _ W I N D O W in source
 *	EXDBCICO.C.
 *
 */

VOID	AsFun_SwapState()
{

	/* If DB WINDOW is VISIBLE then HIDE it else SHOW it	*/
	/* ---------------------------------------------------- */
	if ( VisibleWindowUser == MONITOR_VISIBLE ) 
		asfun_program_visible();
	else	asfun_monitor_visible();
	return;

}

VOID	AsFun_SwapView()
{
	/* If DB WINDOW is VISIBLE then HIDE it else VIEW it	*/
	/* ---------------------------------------------------- */
	if ( VisibleWindowUser == MONITOR_VISIBLE ) 	
		asfun_program_visible();
	else	asfun_monitor_visible();
	return;

}


/*
 *	A S F U N I N I T I A L I S E
 *	-----------------------------
 *	Called from debug startup to ensure correct window value
 *	
 */

VOID	AsFunInitialise()
{
	if (BibDynUsed == 0) { 
		MonitorWindowHandle = INVALID_WINDOW_HANDLE; 
		AsfunLibId  = MOINS_UN;
		BibDynUsed  = 1;
		}
	return;
}


VOID	Asfunused()
{
	BibDynUsed = 1;
	return;
}

#endif	/* _EXDBAFUN_C */
	/* ----------- */

