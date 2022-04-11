/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLOADGO.C				*/
/*		Version :	1.4d / 2.1d				*/
/*		Date 	:	10/04/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
/* INCLUDE file for EXNGF.C						*/
/*	5/11/93	IJM	: Save and restore MIMO context			*/
/*----------------------------------------------------------------------*/
#ifndef EXLOADGOC		/* If not already included		*/
#define EXLOADGOC		/* Avoid multiple inclusions		*/
				/* ------------------------------------ */
#include "exngf.h"

#ifndef	UNIX
#ifndef	VMS
				/* ------------------------------------ */
#define	EXACUTE			/* Causes Re-Entry into Current EXA	*/
				/* For DOS , PROLOGUE 2 and PROLOGUE 3	*/
				/* ------------------------------------ */
#endif
#endif

/*
 *	I s T c o d e N a m e ( filename )
 *	----------------------------------
 *	Uses the file name parser to test for the presence of the tcode
 *	file type extension to detect tcode file names for LOAD.GO
 *
 *	Returns : 	ZERO (0)	Failure not a tcode name
 *			TRUE (1)	Success it is a tcode name
 *
 */


EXAWORD	IsTcodeName( nptr )
BPTR	nptr;
{
	EXABYTE	buffer[FNMAX];

	/* Parse filename for Extension */
	/* ---------------------------- */
	if ( fn_parser( nptr , (BPTR) buffer , 0x0010 ) == 3 ) {

		/* Test for correct separator type */
		/* ------------------------------- */
		if (( buffer[0] == '-' ) || ( buffer[0] == '.' )) {

			/* Test for 'at' or 'AT' etc */
			/* ------------------------- */
			if (( buffer[1] == 'a' ) || ( buffer[1] == 'A' )) {

				if (( buffer[2] == 't' ) || ( buffer[2] == 'T' ))

					/* Success it is a Tcode Filename */
					/* ------------------------------ */
					return(1);
				}
			}
		}
	/* Failure Not a T-Code filename */
	/* ----------------------------- */
	return(0);
}

#ifdef	UNIX
#define	EXACUTE
EXAWORD	ExaCute( BPTR cmdline )
{
	EXAWORD	result;
	BPTR	execptr = UnixExecuteur();
	check_push_before();
	result = x_exec( execptr, cmdline );
	check_pop_after();
	return( result );
}
#endif


EXAWORD	standard_loadgo()
{
	EXAWORD	mode;
	EXAWORD	l;
	EXAWORD	flag;
	EXABYTE	d[2];
	BPTR	execptr;
	EXAWORD	chgtret;
	EXAWORD	result;
#ifdef	ABAL21
	EXABYTE	thismimo[32];
#endif

	/* Check for Automatic Executeur Call */
	/* ---------------------------------- */
	if ((mode = IsTcodeName( fidname )) != 0) {

		/* Prepare and analyse tcode filename */
		/* ---------------------------------- */
		l = TcodeFileName((BPTR) askbuf , fidname );

		if (( worklen2 > 0 ) && ( *workptr2 != 0 ) && ( *workptr2 != 0x000D )) {
		  	askbuf[l++] = (EXABYTE) CMDFIELD;
		  	while (( worklen2 > 0 ) && ( *workptr2 != 0 ) && ( *workptr2 != 0x000D )) {
				askbuf[l++] = *(workptr2++);
				worklen2--;
				}
			 }

		worklen2 = l; workptr2 = (BPTR) askbuf;


#ifdef	EXACUTE
		/* Since we are under Amenesik / Sologic or DOS we can Call OurSelves */
		/* -------------------------------------------------------- */
		*(workptr2 + worklen2) = (EXABYTE) 0x000D;
#ifdef	ABAL21
		save_mimo_context( (BPTR) thismimo );
		fin_mimo();
#endif

#ifdef	DOS_BUGS
		finterm(1);
#endif
		result = ExaCute((BPTR) workptr2);
#ifdef	DOS_BUGS
		initerm();
#endif

#ifdef	ABAL21
		init_mimo();
		restore_mimo_context((BPTR) thismimo );
#endif
		return( result );

#else	/* ! EXACUTE */
#ifdef	UNIX
		execptr = UnixExecuteur();
#else
		execptr = (BPTR) ID_EX_ABAL; 
#endif
#endif
		}
	else	execptr = fidname;

	/* Perform low level System utility Call */
	/* ------------------------------------- */
#ifdef	ABAL21
	save_mimo_context( (BPTR) thismimo );
	fin_mimo();
#endif

	chgtret = (EXAWORD) x_exec(execptr,workptr2 );

#ifdef	ABAL21
	init_mimo();
	restore_mimo_context( (BPTR) thismimo );
#endif


#ifdef	PROLOGUE
	return (( chgtret & 0x00FF));
#else
	return ( chgtret );
#endif

}

/*
 *	S F _ L O A D G O ()
 *	--------------------
 *	Called from SF_NGF performs the tcode analysis and arguament
 *	preparation for the LOAD.GO functions of ABAL.
 *
 *	Two possible cases exist :
 *	- 1	Execution of a native system command or batch
 *	- 2	Execution of a Tcode Program then Return 
 *
 *	The Second case is detected by the precence of one of the tcode 
 *	standard filename extensions :
 *		.at	.At	.AT	.aT
 *		-at	-At	-AT	-aT
 *	which activates the later case.
 *	All other syntax's are submited with an eventual arguament to
 *	the systeme command executeur (Shell etc)
 *
 */

#ifdef	UNIX
EXTERN	BPTR	Exa;	/* ARGV 0 : EXA */
static 	EXABYTE	UnixExaName[256];
EXTERN	EXAWORD	AtbContext;
EXTERN	EXAWORD	LastFore;
EXTERN	EXAWORD	LastBack;
EXTERN	int	exa_is_X11;
static BPTR	UnixExecuteur()
{
	unsigned long x_window();
	unsigned long windowid=0L;
	if ( exa_is_X11 > 1 )
		windowid = x_window();
	else	windowid = 0L;
	sprintf(UnixExaName,"%s \'-x%u:%u:%u:%u:%u:f%u:n%lu\' ", /* quote avant et apres -x */
			(BPTR) Exa,
			x_lin(1),	x_col(1),
			AtbContext,
			LastBack,	LastFore,
			get_pushpopid(),windowid 
			);

#ifndef	VERSION666
#else
#if defined(RT_AIX) || defined(LINUX)
	/* #if defined(RT_AIX) */
	sprintf(UnixExaName,"%s \'-x%u:%u:%u:%u:%u\' ",		/* quote avant et apres -x */
#else
	sprintf(UnixExaName,"%s -x%u:%u:%u:%u:%u ",
#endif
#ifdef	VERSION666
				(BPTR) Exa,
#else
			     	(BPTR) ID_EX_ABAL,
#endif
				x_lin(1),
				x_col(1),
				AtbContext,
				LastBack,
				LastFore);
#endif	/* VERSION666 */
#ifdef LINUX_DB
	fprintf(stderr,"UNIXEXANAME %s\n\r",UnixExaName);
#endif
	return((BPTR) UnixExaName );
}

#endif

EXAWORD	sf_loadgo()
{
	EXAWORD	mode;
	EXAWORD	l;
	EXAWORD	flag;
	EXABYTE	d[2];
	BPTR	execptr;
	EXAWORD	chgtret;
	EXAWORD	result;
#ifdef	ABAL21
	EXABYTE	thismimo[32];
#endif

	/* Collect arguament [R] */
	/* --------------------- */
	worklen3 = (EXAWORD) *(fdex++); mode = 0;

	/* Collect possible Arguament */
	/* -------------------------- */
	if ( fargset(2) != SOFTERROR ) { 

		/* Check for String (Refuse others) */
		/* -------------------------------- */
		if ( worktyp2 != VARB_STR ) 
			return(ABAL_TCODCODE);

		/* Limit to useable string length */
		/* ------------------------------ */
		worklen2 = lenuse((BPTR) workptr2 , worklen2 );

		}
	else 	{

		/* Pas d'arguament alors Retour Chariot */
		/* ------------------------------------ */
#ifdef PROLOGUE
		d[0] = (EXABYTE) 0x000D; 
#else
		d[0] = (EXABYTE) 0; 
#endif
		d[1] = (EXABYTE) 0;

		workptr2 = (BPTR) &d[0];  worklen2 = 1;

		}


	return( standard_loadgo() );

}

#endif	/* EXLOADGOC */
	/* --------- */

/* ----- */
/* E.O.F */
/* ----- */

