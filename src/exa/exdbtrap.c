/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBTRAP.C				*/
/*		Date 	:	10/08/1993				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#define	DEBUGGER
#ifndef	_EXDBTRAP_C
#define _EXDBTRAP_C

#include "exctype.h"
#include "exdebug.h"
#include "exdbtrap.h"
#include "exdbctrl.h"
#include "exdbcico.h"
#include "exdbmimo.h"
#include "allocate.h"
#ifdef	ABAL21
#include "exdbstre.h"
#endif
#include "exproto1.h"

BPTR		program_owner( VOID );
EXAWORD		get_procedure_number( BPTR );
BPTR		get_procedure_name( EXAWORD );

EXAWORD	verify_trap_owner( xtrap )
TRAPTR	xtrap;
{
	if ( wildcomp( xtrap->trap_owner, program_owner() ) == 0 )
		return( 1 );
	else	return( 0 );
}

BPTR	TcodeLocation( ltrap )
TRAPTR	ltrap;
{
	BPTR	ProcedureCodePointer( EXAWORD, EXAWORD );

	/* Avoid these problems after program failure */
	/* ------------------------------------------ */
	if (!( TcodeSegment )) { return( TcodeSegment ); }

	/* Check for Procedure type Trap */
	/* ----------------------------- */
	if (( ltrap->trap_state & DBTRAP_PROC ) == DBTRAP_PROC)

		/* Calculate Procedure Code Pointer */
		/* -------------------------------- */
		return( ProcedureCodePointer( ltrap->trap_block, ltrap->trap_offset ) );

	else	{
		/* If Not Current Segment Then Error */
		/* --------------------------------- */
		if ( ltrap->trap_block != cur_seg ) 
			return((BPTR) 0);
		

		/* Check for Inside procedure or inside segment */
		/* -------------------------------------------- */
		if (sicico & ONSEM_PRC)

			/* Return calculated Tcode pointer Execution of PROC */
			/* ------------------------------------------------- */
			return((BPTR) (CurrentSegmentPointer( cur_seg ) + ltrap->trap_offset));

		else	/* Return Calculated Tcode Pointer Execution of SEGM */
			/* ------------------------------------------------- */
			return((BPTR) (TcodeSegment + ltrap->trap_offset));

		}

}

EXAWORD	XchgTcode4Nop( ltrap )
TRAPTR	ltrap;
{
	BPTR	wptr;

	/* Calculate real physical location */
	/* -------------------------------- */
	if ((wptr = TcodeLocation( ltrap )) != (BPTR) 0) { 

		/* Check for SYSTEM LEGAL ADRESSE */
		/* ------------------------------ */
		if ( VerifPtr( wptr ) != 0 )

			/* Avoid EXCEPTION or CORE DUMP */
			/* ---------------------------- */
			return( MOINS_UN );

		/* Ensure Trap on New Line Tcode Else Error */
		/* ---------------------------------------- */
		if (( ((EXAWORD) *wptr) & 0x0080 ) == 0 )
			return( MOINS_UN);

		/* #BG: Affect after test and not before */
		/* Collect Tcode and place a NOP */
		/* ----------------------------- */
		ltrap->trap_code = (EXAWORD) *wptr; 
		*wptr = (EXABYTE) _tc_NOP;

		}

	return(0);
}


VOID	XchgNop4Tcode( ltrap )
TRAPTR 	ltrap;
{
	BPTR	wptr;

	/* Calculate real physical location */
	/* -------------------------------- */
	if ((wptr = TcodeLocation( ltrap )) != (BPTR) 0) { 
	
		/* Check for SYSTEM LEGAL ADRESSE */
		/* ------------------------------ */
		if ( VerifPtr( wptr ) != 0 )

			/* Avoid EXCEPTION or CORE DUMP */
			/* ---------------------------- */
			return;

		/* Replace Tcode */
		/* ------------- */
		/*
 		FCH+BGI 24092004 Blindage avant remplacement du NOP
		Quand ce cas arrive (et il arrive!), sans ce test on casse le Tcode.
		*/
		if (*wptr == _tc_NOP)
			*wptr = (EXABYTE) ltrap->trap_code;

		}

	return;
}

/*
 *	S E G M E N T   T R A P   W O R K
 *	---------------------------------
 * 
 *	Performs trap implantation for LDGO.SEG and RET.SEG
 *	---------------------------------------------------
 *	(when called from MOTOR.OBJ)
 */

VOID	SegmentTrapWork(mode)
EXAWORD	mode;			/* MODE 0 : REMOVES TRAPS FROM A SEGMENT */
				/* MODE 1 : PLACES  TRAPS IN   A SEGMENT */

{
	TRAPTR	ltrap;

	/* Collect Trap List Pointer */
	/* ------------------------- */
	if ((ltrap = TrapBase) != (TRAPTR) 0) {
	
		do	{

			/* Check for Segment type Trap */
			/* --------------------------- */
			if ((( ltrap->trap_state & DBTRAP_PROC ) != DBTRAP_PROC)

			/* Check for Correct Segment */
			/* ------------------------- */
			&& ( ltrap->trap_block == cur_seg )) {

				/* Select with respect to Trap Mode */
				/* -------------------------------- */
				if ( mode == 0 ) { 
					XchgNop4Tcode( ltrap ); 
					ltrap->trap_state &= ~DBTRAP_LOAD;
					}
				else	{ 
					XchgTcode4Nop( ltrap );
					ltrap->trap_state |= DBTRAP_LOAD;
					}
				}

			}
		/* Get next context pointer */
		/* ------------------------ */
		while((ltrap = ltrap->next) != (TRAPTR) 0);
		}
	return;
}


/*
 *	P R O C E D U R E   T R A P   W O R K
 *	-------------------------------------
 *	Removes or adds traps to procedure code which has just been loaded
 *	or which is about to be liberated due to END.PROC
 *	
 *	This is called from EXPROC in EXCODE.OBJ via a FUNCTION POINTER !
 *
 *	MODE 1 : Places traps, MODE 0 : Removes traps
 */

EXAWORD	ProcedureTrapWork( mode , procid )
EXAWORD	mode;
EXAWORD	procid;
{
	TRAPTR	ltrap;

	/* Collect Trap List Pointer */
	/* ------------------------- */
	if ((ltrap = TrapBase) != (TRAPTR) 0) {
	
		/* Scan until end of list */
		/* ---------------------- */
		do	{

			/* Check for Segment type Trap */
			/* --------------------------- */
			if ((( ltrap->trap_state & DBTRAP_PROC ) == DBTRAP_PROC)

			/* Ensure correct Program / Overlay */
			/* -------------------------------- */
			&& ( verify_trap_owner( ltrap ) )

			/* Check for Correct Procedure */
			/* --------------------------- */
			&& ( ltrap->trap_block == procid )) {

				/* This trap Needs to be added      */
				/* -------------------------------- */ 
				/* Select with respect to Trap Mode */
				/* -------------------------------- */
				if ( mode == 0 ) { 
					XchgNop4Tcode( ltrap ); 
					ltrap->trap_state &= ~DBTRAP_LOAD;
					}
				else	{ 
					XchgTcode4Nop( ltrap );
					ltrap->trap_state |= DBTRAP_LOAD;
					}

				}

			}
		while ((ltrap = ltrap->next) != (TRAPTR) 0);
		}
	return( 1 );
}


/*
 *	L I S T T R A P ()
 *	------------------
 *	Affichage du liste des pieges courantes
 *
 */


/*
 *	Returns a Trap Context Pointer if the requested trap exists
 *	else returns a NULL trap context pointer
 */

TRAPTR	TrapExist(blokid,offid,segproc)
EXAWORD	blokid;
EXAWORD	offid;
EXAWORD	segproc;
{
	TRAPTR 	ltrap;

	/* Collect Trap list base pointer */
	/* ------------------------------ */
	ltrap = TrapBase;
	segproc = (segproc) ? DBTRAP_PROC : 0;

	/* While not end of List */
	/* --------------------- */
	while ( ltrap != (TRAPTR) 0 ) {

		/* Test for Same Type */
		/* ------------------ */
		if ((( ltrap->trap_state & DBTRAP_PROC ) == segproc )

		/* Ensure correct Program / Overlay */
		/* -------------------------------- */
		&&   (verify_trap_owner( ltrap ) )

		/* Test for Same Block */
		/* ------------------- */
		&&   (ltrap->trap_block == blokid)

		/* Test for Same Offset */
		/* -------------------- */
		&&   ( ltrap->trap_offset == offid ) )

			/* Gotcha : Trap Exists */
			/* -------------------- */
			break;

		/* Collect next context pointer */
		/* ---------------------------- */
		ltrap = ltrap->next;
		}

	/* Return Result Pointer */
	/* --------------------- */
	return( ltrap );
}

#ifdef	MODEL_DBGT

/*
 *	Returns the Real Tcode Which has been replaced by a NOP
 *	for IDB code listing function
 *
 */

EXAWORD	real_tcode( xb )
EXAWORD	xb;
{
	TRAPTR	ltrap;
	EXAWORD	xa;
	EXAWORD	xc;

	if (sicico & ONSEM_PRC)	{
		xa = procid;  
		xc = DBTRAP_PROC;
		}
	else	{
		xa = cur_seg;
		xc = 0;
		}

	if ((ltrap = TrapExist(xa,xb,xc)) != (TRAPTR) 0)
		return( ltrap->trap_code );
	else	return( MOINS_UN ); 	

}

#endif

#ifdef INUTILE
EXAWORD	TrapNumber(blokid,offid,segproc)
EXAWORD	blokid;
EXAWORD	offid;
EXAWORD	segproc;
{
	TRAPTR 	ltrap;
	EXAWORD	x;

	/* Collect Trap list base pointer */
	/* ------------------------------ */
	ltrap = TrapBase; x = 0;

	/* While not end of List */
	/* --------------------- */
	while ( ltrap != (TRAPTR) 0 ) {

		/* Test for Same Type */
		/* ------------------ */
		if ( (( ltrap->trap_state & segproc ) == segproc )

		/* Ensure correct Program / Overlay */
		/* -------------------------------- */
		&&   (verify_trap_owner( ltrap ) )

		/* Test for Same Block */
		/* ------------------- */
		&&   (ltrap->trap_block == blokid)

		/* Test for Same Offset */
		/* -------------------- */
		&& ( ltrap->trap_offset == offid ) )

			/* Gotcha : Trap Exists */
			/* -------------------- */
			break;

		/* Collect next context pointer */
		/* ---------------------------- */
		ltrap = ltrap->next; 
		x++;
		}

	/* Return Result Pointer */
	/* --------------------- */
	return( x );

}
#endif


/*
 *	P O S E P I E G E ( Xa , Xb, Xc )
 *	---------------------------------
 *	Addition of a break point to the break point table
 *
 */

EXAWORD	checkpiege( xa,xb,xc )
EXAWORD	xa,xb,xc;
{
	TRAPTR	ltrap;

	/* Locate Trap in table and if Exists Modify Type */
	/* ---------------------------------------------- */ 
	if ((ltrap = TrapExist(xa,xb,xc)) != (TRAPTR) 0)
		return( ( ltrap->trap_state & DBTRAP_MODE ? 1 : 2 ) );
	else 	return( 0 );
}

VOID	liberate_trap( ltrap )
TRAPTR	ltrap;
{
	if ( ltrap != (TRAPTR) 0) {
		if ( ltrap->trap_owner != (BPTR) 0 )
			liberate( ltrap->trap_owner );
		liberate( ltrap );
		}
	return;
}

VOID	dismantle_trap( ltrap )
TRAPTR	ltrap;
{

	/* Remove this trap from double linked list */
	/* ---------------------------------------- */
	if ( ltrap->previous != (TRAPTR) 0) 
		ltrap->previous->next = ltrap->next;
	else	TrapBase = ltrap->next;
	if ( ltrap->next != (TRAPTR) 0)
		ltrap->next->previous = ltrap->previous;

	/* Watch out for Code Block Present */
	/* -------------------------------- */
	if ((ltrap->trap_state & DBTRAP_LOAD) != 0)

		/* Replace Tcode in Code Block */
		/* --------------------------- */
		XchgNop4Tcode( ltrap );

	liberate_trap( ltrap );
	return;

}

VOID	wipepiege( xa,xb,xc,xn )
EXAWORD	xa,xb,xc;
BPTR	xn;
{
	TRAPTR	ltrap;

	/* Locate Trap in table and if Exists Modify Type */
	/* ---------------------------------------------- */ 
	if ((ltrap = TrapExist(xa,xb,xc)) != (TRAPTR) 0) {
		dismantle_trap( ltrap );
		TrapChanges++;
		}

	return;
}

TRAPTR	posepiege( xa,xb,xc,AB_mode, xn )
EXAWORD	xa,xb,xc,AB_mode;
BPTR xn;
{
	TRAPTR	ltrap=(TRAPTR)0;
	EXAWORD	lx;
	EXAWORD	special=0;

	TrapChanges++;

	/* Resolve implicite if not Explicite Program Name */
	/* ----------------------------------------------- */
	if (!( xn )) { xn = program_owner(); } else { special=1; }

	/* Locate Trap in table and if Exists Modify Type */
	/* ---------------------------------------------- */ 
	if ((ltrap = TrapExist(xa,xb,xc,xn)) != (TRAPTR) 0)

		/* Convert to specified type */
		/* ------------------------- */
		ltrap->trap_state &= (~DBTRAP_MODE | AB_mode);

	else	{
		/* Attempt to allocate a new trap Context */
		/* -------------------------------------- */
		if ((ltrap = (TRAPTR) allocate( sizeof( struct exadb_trap ))) != (TRAPTR) 0) {
			
			/* Establish Trap informations */
			/* --------------------------- */
			if ((ltrap->next = TrapBase) != (TRAPTR) 0)
				ltrap->next->previous = ltrap;

			ltrap->previous = (TRAPTR) 0;
			TrapBase           = ltrap;
			ltrap->trap_block  = xa;
			ltrap->trap_offset = xb;

			/* allocate break point trap owner field */
			/* ------------------------------------- */
			if (!( xn ))
				ltrap->trap_owner = (BPTR) 0;
			else if (( ltrap->trap_owner = (BPTR) allocate( (strlen( xn ) + 1) )) != (BPTR) 0) {
				strcpy(ltrap->trap_owner,xn);
				}

			ltrap->file_number = ltrap->file_line=0;			

			/* This is required for initial configuration load breakpoints */
			/* ----------------------------------------------------------- */
			if ( special ) {
				resolve_trap_file_position( ltrap, xa, xb, xc );
				}
			
			/* Detect Segment / Procedure */
			/* -------------------------- */
			if ( xc == 1 ) 

				/* Procedure and Resident */
				/* ---------------------- */
				lx = (AB_mode | (DBTRAP_LOAD | DBTRAP_PROC));

			else	{
				/* Check if segment is loaded */
				/* -------------------------- */
				if ( xa == cur_seg ) 
					lx = (AB_mode | DBTRAP_LOAD);

				else	
					/* Else Simply Store Type */
					/* ---------------------- */
					lx = AB_mode;

				}

			/* Store to Context and test for Residence */
			/* --------------------------------------- */
			if ((((ltrap->trap_state = lx)) & DBTRAP_LOAD) != 0) {

				/* Perform Exchange : Tcode/NOP */
				/* ---------------------------- */
				if ( XchgTcode4Nop( ltrap ) == MOINS_UN) {

					/* Traps must be placed on New Lines */
					/* --------------------------------- */
					Verbose((BPTR)TalkPtr[62]);

					/* Remove this Trap */
					/* ---------------- */
					if ((TrapBase = TrapBase->next) != (TRAPTR) 0)
						TrapBase->previous = (TRAPTR) 0;
					liberate_trap( ltrap );
					ltrap = (TRAPTR) 0;
					}
				}

			}
		else	/* Signal memory full condition */
			/* ---------------------------- */
			Debordement();

		}

		/* ----------------------------- */
		/* Message no longer needed # 62 */
		/* ----------------------------- */
		/* "Table des pieges complete"   */
		/* ----------------------------- */
		/* Verbose((BPTR)TalkPtr[62]); */
		/* ----------------------------- */

	return(ltrap);
}

#ifdef	ABAL21

void	showtrap( topcol, toplin, nbc, trapid, ltrap )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbc;
EXAWORD	trapid;
TRAPTR	ltrap;
{
	EXAWORD	nb;
	EXAWORD	l;
	EXAWORD	nombre=0;
	BPTR	mptr;

	/* Display Trap Identification Number */
	/* ---------------------------------- */
	pos(toplin,topcol);
	if ( ltrap == (TRAPTR) 0 )
		left_string( topcol, toplin, nbc, (BPTR) ">" );
	else	{
		x_putch(' ');
		l = display_integer( trapid );
		for ( ; l < 5; l++ )
			x_putch(' ');
		x_putch(' '); 
		nombre = 8;

		(void) fn_parser(ltrap->trap_owner, (BPTR) askbuf, 8);
		left_string( topcol+7, toplin, 8, (BPTR) askbuf );
		x_putch(' ');
		nombre+= 9;

		/* Indicate Segment or Procedure */
		/* ----------------------------- */
		if ((ltrap->trap_state & DBTRAP_PROC) == 0) {
			x_cprintf((BPTR)"SEGM "); 
			x_putch(' '); 
			l = display_integer(ltrap->trap_block);
			nombre += (l + 5);
			}
		else	{ 
			x_cprintf((BPTR)"PROC "); 
			nombre += 5;
#ifdef	ABAL21
			if ( trad_ver > '1' ) {
				x_cprintf( (BPTR) ((mptr = get_procedure_name((ltrap->trap_block * (8*WORDSIZE) )))));
				nombre += exadb_strlen((BPTR) mptr );
				} 
			else	{
#endif
				AffProcName( (ltrap->trap_block * (8*WORDSIZE) ));
				nombre += 8;
#ifdef	ABAL21
				}
#endif
			}

		/* Display Offset into Code Block */
		/* ------------------------------ */
		x_putch(':'); 
		display_hexint( ltrap->trap_offset );
		nombre += 5;

		/* Indicate Permenace or OneShot */
		/* ----------------------------- */
		if ((ltrap->trap_state & DBTRAP_MODE) == DBTRAP_MODE) { 
			x_putch(' ');
			x_cprintf((BPTR) (mptr = (BPTR)TalkPtr[53]));
			l = exadb_strlen( mptr );
			x_putch(' ');
			nombre += (2 + l);
			}
		for ( ; nombre < nbc; nombre++) 
			x_putch(' ');			
		}

	return;
}

VOID	flush_traps(vh)
EXAWORD	vh;
{
	TRAPTR	ltrap=TrapBase;
	BPTR	get_procedure_name( EXAWORD );

	while ( ltrap != (TRAPTR) 0 ) {
		if ( verify_trap_owner( ltrap ) ) {
			if ((ltrap->trap_state & DBTRAP_MODE) == DBTRAP_MODE)
				stream_putb(vh,'A');
			else	stream_putb(vh,'B');
			if ((ltrap->trap_state & DBTRAP_PROC) == 0) {
				stream_putb(vh,'S');
				stream_puti(vh, ltrap->trap_block );
				}
			else	{
				stream_putb(vh,'P');
				stream_puts(vh,(BPTR) get_procedure_name((ltrap->trap_block * (8*WORDSIZE))));
				}
			stream_putb(vh,':');
			stream_puth(vh, ltrap->trap_offset );
			stream_putlf(vh);
			}
		ltrap = ltrap->next;
		}
	return;
}

EXAWORD	droptrap( TRAPTR xtrap)
{
	
	/* If Block Exists */
	/* --------------- */
	if ( xtrap != (TRAPTR) 0 ){

		if ( xtrap->previous != (TRAPTR) 0)
			xtrap->previous->next = xtrap->next;

		else if ((TrapBase = xtrap->next) != (TRAPTR) 0)
			TrapBase->previous = (TRAPTR) 0;

		if ( xtrap->next != (TRAPTR) 0)
			xtrap->next->previous = xtrap->previous;

		/* Watch out for Code Block Present */
		/* -------------------------------- */
		if ((xtrap->trap_state & DBTRAP_LOAD) != 0)
			/* Replace Tcode in Code Block */
			/* --------------------------- */
			XchgNop4Tcode( xtrap );

		/* Liberate the Trap Context */
		/* ------------------------- */
		liberate_trap( xtrap );
		}

	return(0);
}

EXAWORD	deposepiege( xa,xb,xc,AB_mode,xn )
EXAWORD	xa,xb,xc,AB_mode;
BPTR	xn;
{
	TRAPTR	ltrap=(TRAPTR)0;
	EXAWORD	lx;

	TrapChanges++;

	/* Resolve implicite if not Explicite Program Name */
	/* ----------------------------------------------- */
	if (!( xn )) { xn = program_owner(); }

	/* Locate Trap in table and if Exists Modify Type */
	/* ---------------------------------------------- */ 
	if ((ltrap = TrapExist(xa,xb,xc,xn)) != (TRAPTR) 0) {
		droptrap( ltrap );
		return(1);
		}		
	else	return(0);
}

	

void	showtraps( topcol, toplin, nbc, nbl, trapid, ltrap )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbc;
EXAWORD	nbl;
EXAWORD	trapid;
TRAPTR	ltrap;
{
	EXAWORD	nbt;

	for ( nbt = 0; nbt < nbl; nbt++ ) {
		if ( ltrap == (TRAPTR) 0)
			break;
		showtrap( topcol, (toplin+nbt), nbc, (trapid+nbt), ltrap );
		ltrap = ltrap->next;
		}
	for ( ; nbt < nbl; nbt++ )
		showtrap( topcol, (toplin+nbt), nbc, (trapid+nbt), ltrap );
		 
	return;
}

VOID	trap_correspondance( ltrap )
TRAPTR	ltrap;
{
	/* Source Correspondance Information */
	/* --------------------------------- */
	if ((ltrap->trap_state & DBTRAP_PROC) == DBTRAP_PROC)
		(void) tcode_correspondance( 1, (ltrap->trap_block * (8*WORDSIZE)),ltrap->trap_offset, 3 );
	else	(void) tcode_correspondance( 0, ltrap->trap_block,       ltrap->trap_offset, 3 );
	return;

}

BPTR	breakpointlist()
{
	TRAPTR	ltrap=(TRAPTR) 0;
	EXAWORD	width;
	EXAWORD	item;
	EXAWORD	c;
	BPTR	nptr;
	BPTR	wptr;
	BPTR	rptr;

	for (	width=0,
		ltrap = TrapBase;
		ltrap != (TRAPTR) 0;
		ltrap = ltrap->next ) {
		width += 20;
		if ((ltrap->trap_state & DBTRAP_PROC) == 0)
			width += 5;
		else if (!( nptr = get_procedure_name((ltrap->trap_block * (8*WORDSIZE) ))))
			width += (2*WORDSIZE);
		else if ( *nptr != '{' )
			width += strlen( nptr );
		else	width += (2*WORDSIZE);
		width += strlen( ltrap->trap_owner );
		width += 16;

		}
	if ((!( width ))
	||  (!( rptr = allocate( width + 10 ) )))
		return((BPTR) 0);

	wptr = rptr; *wptr = 0;

	for (	item=0,
		ltrap = TrapBase;
		ltrap != (TRAPTR) 0;
		ltrap = ltrap->next ) {
		if (item++) strcpy(wptr++,"|");
		if ((ltrap->trap_state & DBTRAP_MODE) == DBTRAP_MODE)
			c = 'A';
		else	c = 'B';
		if ((ltrap->trap_state & DBTRAP_PROC) == 0)
			sprintf(wptr,"%u: %c SEGM %u:%x %s",item,c,ltrap->trap_block,ltrap->trap_offset,ltrap->trap_owner);
		else if (!( nptr = get_procedure_name((ltrap->trap_block * (8*WORDSIZE) ))))
			sprintf(wptr,"%u: %c PROC %x:%x %s",item,c,ltrap->trap_block,ltrap->trap_offset,ltrap->trap_owner);
		else if ( *nptr == '{' )
			sprintf(wptr,"%u: %c PROC %x:%x %s",item,c,ltrap->trap_block,ltrap->trap_offset,ltrap->trap_owner);
		else	sprintf(wptr,"%u: %c PROC %s:%x %s",item,c,nptr,ltrap->trap_offset,ltrap->trap_owner);
		wptr += strlen( wptr );
		}

	return( rptr );
}

VOID	listpieges()
{
	TRAPTR	ltrap=(TRAPTR) 0;
	TRAPTR	xtrap=(TRAPTR) 0;
	EXAWORD	maxlines=13;
	EXAWORD	nbl=1;
	EXAWORD	nbc=64;
	EXAWORD	item=0;
	EXAWORD	entry=0;
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
	EXAWORD	c;

	/* Do nothing if no traps declared */
	/* ------------------------------- */
	if ((ltrap = TrapBase) == (TRAPTR) 0) 
		return;

	xtrap = ltrap;

	maxlines = avoid_observations( 13 );
	if (!(maxlines & 1))
		maxlines--;

	/* Count Traps */
	/* ----------- */
	for ( nbl = 1; nbl < maxlines; nbl++)
		if ((ltrap = ltrap->next ) == (TRAPTR) 0)
			break;

	mouse_title_box( topcol, toplin,nbc,nbl, (BPTR) TalkPtr[51] );
	showtraps( (topcol+1), (toplin+1), nbc, nbl, entry, (ltrap=xtrap) );

	/* Repeat until Not End of Liste */
	/* ----------------------------- */
	while ( 1 ) {
		TrapChanges = 0;
		symbolic_atribut(2);
		showtrap( (topcol+1), (toplin+item+1), nbc, (entry+item), xtrap );
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		showtrap( (topcol+1), (toplin+item+1), nbc, (entry+item), xtrap );
		switch ( c ) {

			case CTRL_U :
			case CTRL_N :
				continue;

			case CTRL_D :
				if ( DbMouse.position == 0 )
					continue;
				item++;
				if ( DbMouse.position < item ) {
					for ( ;DbMouse.position < item; item--  ) {
						if (( xtrap != (TRAPTR) 0 )
						&&  ( xtrap->previous != (TRAPTR) 0 ))
							xtrap = xtrap->previous;
						else	{
							item--; continue;
							}
						}
					}
				else	{
					for ( ;item < DbMouse.position; item++  ) {
						if (( xtrap != (TRAPTR) 0 )
						&&  ( xtrap->next != (TRAPTR) 0 ))
							xtrap = xtrap->next;
						else	{
							item--; continue;
							}
						}
					}
				item--;
				if ( current_mouse_click() != 2 )
					continue;

			case CTRL_M :
				if ( verify_trap_owner( xtrap ) ) {
					pop_mouse();
					trap_correspondance( xtrap );
					mouse_title_box(topcol,toplin,nbc,nbl, (BPTR) TalkPtr[51] );
					if ( TrapChanges == 0)
						break;
					}
				else	break;

			case CTRL_L :

				ltrap = TrapBase;
				xtrap = TrapBase;
				entry = item = 0;
				break;

			case 0x001B :
				pop_mouse();
				return;

			case CTRL_E :
				if (( xtrap != (TRAPTR) 0 )
				&&  ( xtrap->next != (TRAPTR) 0 )) {
					xtrap = xtrap->next;
					if ( item < (nbl-1) )
						item++;
					else if ((ltrap != (TRAPTR) 0)
					     &&	 ( ltrap->next != (TRAPTR) 0)) {
						entry++;
						ltrap = ltrap->next;
						break;
						}
					}
				continue;
				
			case CTRL_K :
				if (( xtrap != (TRAPTR) 0)
				&&  ( xtrap->previous != (TRAPTR) 0 )) {
					xtrap = xtrap->previous;
					if ( item > 0 )
						item--;
					else if ( entry > 0 ) {
						entry--;
						ltrap = ltrap->previous;
						break;
						}
					}
				continue;

			case CTRL_C :
				for ( c= 0; c < (nbl/2); c++ ) {
					if ((xtrap != (TRAPTR) 0)
					&&  (xtrap->next != (TRAPTR) 0)) {
						xtrap = xtrap->next;
						ltrap = ltrap->next;
						}
					else	break;
					}
				break;

			case CTRL_R :
				for ( c= 0; c < (nbl/2); c++ ) {
					if ((ltrap != (TRAPTR) 0)
					&&  (ltrap->previous != (TRAPTR) 0)) {
						xtrap = xtrap->previous;
						ltrap = ltrap->previous;
						}
					else	break;
					}
				break;

			}
		showtraps( (topcol+1), (toplin+1), nbc, nbl, entry, ltrap );

		}

}
#endif


/*
 *	R A Z T R A P ( trpid )
 *	-----------------------
 *	Removes a trap entry from the trap table ( or all if trpid = -1 )
 *
 */

VOID	raztrap(trpid)
EXAWORD	trpid;
{
	TRAPTR	ltrap;
	TRAPTR  xtrap;
	EXAWORD	x;

	/* Intercept request for Trap Flush */
	/* -------------------------------- */
	if (trpid == MOINS_UN) {

		/* Repeat until table Removed */
		/* -------------------------- */
		while ( TrapBase != (TRAPTR) 0 ) 
			raztrap( 0 );

		}
	else	{

		/* Remove individual TRAP */
		/* ---------------------- */
		if ( TrapBase == (TRAPTR) 0 ) 
			return;

		/* Request to remove list Base */
		/* --------------------------- */
		if ( trpid == 0 ) {
			xtrap = TrapBase;
#ifndef	VERSION666
			if ((TrapBase = TrapBase->next) != (TRAPTR) 0)
				TrapBase->previous = (TRAPTR) 0;
#endif
			}
		else	{

			xtrap = TrapBase; x = 0;
			do 	{
				xtrap = xtrap->next; 
				x++;
				}
			while (( x < trpid ) && ( xtrap != (TRAPTR) 0));

#ifndef	VERSION666
			/* Trap not found return no error */
			/* ------------------------------ */
			if ( xtrap != (TRAPTR) 0 ) {

				if ( xtrap->previous != (TRAPTR) 0)
					xtrap->previous->next = xtrap->next;
				if ( xtrap->next != (TRAPTR) 0)
					xtrap->next->previous = xtrap->previous;

				}
#endif

			}

#ifndef	VERSION666
		/* If Block Exists */
		/* --------------- */
		if ( xtrap != (TRAPTR) 0 ){

			/* Watch out for Code Block Present */
			/* -------------------------------- */
			if ((xtrap->trap_state & DBTRAP_LOAD) != 0)

				/* Replace Tcode in Code Block */
				/* --------------------------- */
				XchgNop4Tcode( xtrap );

			/* Liberate the Trap Context */
			/* ------------------------- */
			liberate_trap( xtrap );
			}
#else
		droptrap( xtrap );
#endif
		}

	/* Return With out Error */
	/* --------------------- */
	return;

}

EXAWORD	HexaTcodeId( wptr )
BPTR	wptr;
{	
	EXAWORD	vid;
	EXAWORD	i;
	for ( i= 1, vid = 0; i < 5; i++ ) {
		if (( *(wptr + i) >= '0' ) && ( *(wptr + i) <= '9'))
			vid = ((vid << 4) | ( *(wptr + i) - '0'  ));
		else if (( *(wptr + i) >= 'A' ) && ( *(wptr + i) <= 'F'))
			vid = ((vid << 4) | ( (*(wptr + i) - 'A' ) + 10  ));
		else  if (( *(wptr + i) >= 'a' ) && ( *(wptr + i) <= 'f'))
			vid = ((vid << 4) | ( (*(wptr + i) - 'a' ) + 10  ));
		else	break;
		}
	return( vid );
}

/*
 *	T R A P E R ()
 *	--------------
 *	Sets a breakpoint adresse
 *
 */

VOID traper(absel,cmdptr)
EXAWORD	absel;
BPTR	cmdptr;
{
	EXABYTE	c;
	EXAWORD s;
	EXAWORD	mode;
	BPTR	wptr;
	BPTR	fnptr=(BPTR) 0;
	EXAWORD	cnvlen;
	EXAWORD	csval;
	EXAWORD ipval;

	/* Remove white space */
	/* ------------------ */
	cmdptr = CmdShift( cmdptr );

	/* Collect Next Byte */
	/* ----------------- */
	c = toupper(*cmdptr); 

	/* Watch out for End of String */
	/* --------------------------- */
	if ( c == 0 ) 
		return;
	else	cmdptr++;

	/* Remove White Space */
	/* ------------------ */
	cmdptr = CmdShift( cmdptr );

	/* Analyse collected Character */
	/* --------------------------- */
	switch ( c ) {
#ifdef	DEBUG_XLDF
		case 'U' :
			/* Establish Dynamic Library Trap Break */
			/* ------------------------------------ */
#ifdef	MODEL_DBGT
			if ( absel == MOINS_UN )
				return;
#endif
			ldf_trapwork(cmdptr,absel);
			return;
#endif
			/* Establish a Watch break point */
			/* ----------------------------- */
		case 'V' :
#ifdef	MODEL_DBGT
			if ( absel == MOINS_UN )
				return;
#endif
			varmod(cmdptr,( absel == 1 ? 0x000C : 0x0008 ));
			return;

		case '?' :
		case 'L' :

			/* Display the List of Break Points */
			/* -------------------------------- */
#ifdef	MODEL_DBGT
			if ( absel != MOINS_UN )
#endif
				listpieges(); 		
			return;

		case 'I' :

#ifdef	MODEL_DBGT
			if ( absel != MOINS_UN )
				return;
#endif

			/* Enter Break Point Supression Loop */
			/* --------------------------------- */
			while ( *cmdptr != 0 ) {

				switch ( *cmdptr ) {

					case ',' :  
					case ' ' :
					case '\t': cmdptr++; 
					case 0   : continue;
					case '*' : ipval = MOINS_UN; 
						   cmdptr++;
						   break;
					default  : 

						/* Scan Till end or Next */
						/* --------------------- */
						s = 0; 
						while (( *(cmdptr+s) != ',' ) && ( *(cmdptr+s) != 0 ) && ( *(cmdptr+s) != ' ' )) 
							s++;
						ipval = atoi(cmdptr,s); 
						cmdptr += s;

					}

				/* Remove the Specified Trap(s) */
				/* ---------------------------- */
				raztrap(ipval); 

				/* if GLOBAL SUPRESSION EXIT */
				/* ------------------------- */
				if ( ipval == MOINS_UN ) { break; }

				}
	
			return;

		case 'P' :	mode = 1; break;
		case 'S' :	mode = 0; break;

		default	 :	return;

		}

	/* Remove White Space */
	/* ------------------ */
	cmdptr = CmdShift( cmdptr );

	/* Check for and handle Wild Request */
	/* --------------------------------- */ 
	if ( *cmdptr == '*' ) {
		if ( mode )
			trap_all_procedures(mode,absel);
		else	trap_all_segments(mode,absel);
		return;
		}

	/* Collect a break Adresse (PROCEDURE or SEGMENT) */
	/* ---------------------------------------------- */
	wptr = cmdptr; cnvlen = 0;

	/* Scan to COLON or END OF STRING */
	/* ------------------------------ */
	while (( *wptr != ':' ) && ( *wptr != (EXABYTE) 0 )) {
		wptr++; cnvlen++;
		}

	/* If COLON detected collect SEG or PROC ID */
	/* ---------------------------------------- */
	if ( *wptr == ':' ) {

		if ( mode == 0 ) { 

			/* Convert and collect SEGMENT NUMBER */
			/* ---------------------------------- */
			csval = atoi(cmdptr,cnvlen); 
			}
		else	{
			/* Collect PROCEDURE NUMBER */
			/* ------------------------ */
			*(cmdptr + cnvlen) = (EXABYTE) 0;
			if ( *cmdptr == '/' ) {
				csval = HexaTcodeId( cmdptr );
				/* convert procedure offset to procedure ID for storage */
				/* ---------------------------------------------------- */
				if ( WORDSIZE > 2 )
					csval /= 32;
				else	csval /= 16;
				}
			else	{
#ifdef	ABAL21
				if ( trad_ver > '1' )
					csval = get_procedure_number( (BPTR) cmdptr );
					if (csval != MOINS_UN)
						csval /= (8*WORDSIZE);
				else
#endif
					csval = ProcNumb( cmdptr );

				}
			if ( csval == MOINS_UN ) {

				/*  "Procedure Name Not Found" */
				/* --------------------------- */
				Verbose((BPTR)TalkPtr[63]);
				return;
				}
			}
		cmdptr = wptr + 1;
		}
	else 	{
		/* Use Current Code Block as SEG or PROC ID */
		/* ---------------------------------------- */
		if ( mode == 1 ) csval = procid;
		if ( mode == 0 ) csval = cur_seg;
		}

	/* Convert to Offset or Use Current as Default */
	/* ------------------------------------------- */
	for (cnvlen=0; *(cmdptr+cnvlen) != 0; cnvlen++)
		if ( *(cmdptr+cnvlen) == ' ' )
			break;

	if ( cnvlen > 0 ) 		{ ipval = hextoi(cmdptr,cnvlen);}
	else				{ ipval = (EXAWORD) CurrentTcodeOffset(0); } 


#ifdef	VERSION666
	/* -------------------------------------- */
	/* Detect explicite program name for trap */
	/* -------------------------------------- */
	cmdptr += cnvlen;
	while ( *cmdptr == ' ' ) cmdptr++;
	if ( *(cmdptr++) == '(' ) {
		fnptr = cmdptr;
		while (( *cmdptr != 0 ) && ( *cmdptr != ')' ))
			cmdptr++;
		*cmdptr = 0;
		}
#endif	

#ifdef	MODEL_DBGT
	if ( absel == MOINS_UN ) {

		/* Update Tcode assembler window */
		/* ----------------------------- */

		if (( mode == 0 ) && ( csval != cur_seg ))
			return;

		if ( mode == 0 )
			wptr = TcodeSegment;
		else	wptr = (*(TcodeProcTable + csval)).code_segment;

		if (!( wptr )) { return; }

#ifdef	MERDE_DB
		ExamineTcode((ScreenLin - ListLigne - 1),1 ,(ListLigne + 1),(WindCord[14][1] - 1),wptr ,ipval);
#endif
		return;

		}
#endif
	/* Establish the Trap */
	/* ------------------ */
	posepiege(csval,ipval,mode,absel,fnptr);
	return;

}

/*
 *	T R A P S E A R C H ( )
 *	-----------------------
 *	Returns the tcode exchanged for NOP at current trap break point
 *	Returns MOINS_UN in case of trap not found
 *	
 */
EXAWORD	TrapSearch(mode)
EXAWORD	mode;
{
	EXAWORD	xa,xb,xc;
	TRAPTR	ltrap;

	/* Establish Code Block Identity */
	/* ----------------------------- */
	if (sicico & ONSEM_PRC) { xa = procid;  xc = DBTRAP_PROC; }
	else			{ xa = cur_seg; xc = 0; 	  }

	/* Establish Offset */
	/* ---------------- */
	xb = (EXAWORD) CurrentTcodeOffset(0);

	/* Locate Trap Context in Trap List */
	/* -------------------------------- */
	if ((ltrap = TrapExist(xa,xb,xc)) == (TRAPTR) 0) {

		/* Error No Trap Context */
		/* --------------------- */
		return(MOINS_UN);
		}
	else	{
		/* REMOVE TRAP IF TYPE 'B'	  */
		/* -----------------------        */
		if ( mode == 1 ) {

			if ((ltrap->trap_state & DBTRAP_MODE ) == 0) {

				/* Perform Tcode Replacement */
				/* ------------------------- */
				XchgNop4Tcode( ltrap );

				/* Remove Linkage from List    */
				/* ------------------------    */
				if (ltrap->previous != (TRAPTR) 0)
					ltrap->previous->next = ltrap->next;
				else	TrapBase = ltrap->next;
				if ( ltrap->next != (TRAPTR) 0)
					ltrap->next->previous = ltrap->previous;
				liberate_trap( ltrap );				

				/* Adjust Tcode Pointer */
				/* -------------------- */
				fdex--;
				
				/* And force to re-execute */
				/* ----------------------- */
				return( MOINS_UN );

				}
			}

		/* Return New Line Stripped TCODE */
		/* ------------------------------ */
		return( (ltrap->trap_code & 0x007F) );
		}

}

VOID	initialise_trap_manager()
{
	TrapBase  = (TRAPTR) 0;
	TrapChanges        = 0;
	return;
} 

VOID	terminate_trap_manager()
{
	if ( TrapBase != (TRAPTR) 0) {
		/* Repeat until table Removed */
		/* -------------------------- */
		while ( TrapBase != (TRAPTR) 0 ) 
			raztrap( 0 );
		}
	return;
}

VOID	liberate_overlay_traps()
{
	TRAPTR	ltrap;
	TRAPTR	xtrap;
	if ((ltrap = TrapBase) != (TRAPTR) 0) {
		do	{
			xtrap = ltrap->next;
			if ( verify_trap_owner( ltrap ) )
				dismantle_trap( ltrap );
			}
		while ((ltrap = xtrap) != (TRAPTR) 0);
		}
	return;
}

VOID	save_break_points( BPTR nomfic )
{
	BPTR	nptr;
	BYTE	c;
	FILE * h;
	TRAPTR	ltrap;
	TRAPTR	xtrap;
	if (!( nomfic ))
		return;
	if (!( h = fopen( nomfic, "w" ) ))
		return;
	for (	ltrap = TrapBase;
		ltrap != (TRAPTR) 0;
		ltrap = ltrap->next ) {
		if ((ltrap->trap_state & DBTRAP_MODE) == DBTRAP_MODE)
			c = 'A';
		else	c = 'B';
		if ((ltrap->trap_state & DBTRAP_PROC) == 0)
			fprintf(h,"%cS %u:%x (%s) \r\n",c,ltrap->trap_block,ltrap->trap_offset,ltrap->trap_owner);
		else if (!( nptr = get_procedure_name((ltrap->trap_block * (8*WORDSIZE) ))))
			fprintf(h,"%cP %x:%x (%s)\r\n",c,ltrap->trap_block,ltrap->trap_offset,ltrap->trap_owner);
		else if ( *nptr == '{' )
			fprintf(h,"%cP %x:%x (%s) \r\n",c,ltrap->trap_block,ltrap->trap_offset,ltrap->trap_owner);
		else	fprintf(h,"%cP %s:%x (%s) \r\n",c,nptr,ltrap->trap_offset,ltrap->trap_owner);
		}
	fclose(h);
	return;
}

#endif	/* _EXDBTRAP_C */
	/* ----------- */

