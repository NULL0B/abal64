/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXDWTCH.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

#ifndef	_EXDBWTCH_C
#define	_EXDBWTCH_C
	
#define	DEBUGGER

#include "exdebug.h"
#include "exdbwtch.h"
#include "exdbctrl.h"
#include "exdbcico.h"
#include "exdbmimo.h"
#include "allocate.h"
#ifdef	ABAL21
#include "exdbstre.h"
#endif
#include "exproto1.h"
/*
 *	M E M O R Y    Z O N E    W A T C H I N G
 *	-----------------------------------------
 *	These functions have been added to Version 1.4 to allow
 *	the detection of code portions which modifed variables.
 *	Execution will halt after having executed code which results
 *	in the modification of a memory location being watched.
 *	
 */

/*
 *	W A T C H F L A G S
 *	-------------------
 *	Ensure DEBUG STEP/BREAK flags reflect the watch status
 *
 */

VOID	WatchFlags()
{
	if ( WatchBase == (WATCHPTR) 0 ) {
		db_step_ctrl &= 0xFFFB;
		}
	return;
}


/*
 *	W A T C H M E S S A G E ( mptr )
 *	--------------------------------
 *	Displays the message pointed to by mptr after activating the
 *	debug display window
 *
 */

VOID	WatchMessage( mptr )
BPTR	mptr;
{
	return;
	MoniteurWindow();
	asfun_monitor_implicite();
	Verbose((BPTR) mptr );
	return;
}


/* 
 *	W A T C H F R E E ( wptr )
 *	--------------------------
 *	Liberation of a watch structure
 *
 */

VOID	WatchFree( lwptr )
WATCHPTR	lwptr;
{
	/* If Valid Watch Structure */
	/* ------------------------ */
	if ( lwptr != (WATCHPTR) 0 ) {

		/* Liberate Name Syntax storage zone */
		/* --------------------------------- */
		if ( lwptr->name != (BPTR) 0)
			liberate(lwptr->name);

		/* Liberate value storage zone */
		/* --------------------------- */
		if ( lwptr->value != (BPTR) 0)
			liberate(lwptr->value);

		/* Remove from double linked list */
		/* ------------------------------ */
		if ( lwptr->previous == (WATCHPTR) 0)
			WatchBase = lwptr->next;
		else	lwptr->previous->next = lwptr->next;
		if ( lwptr->next != (WATCHPTR) 0)
			lwptr->next->previous = lwptr->previous;

		/* Liberate structure */
		/* ------------------ */
		liberate (lwptr);
		}

	return;
}
/*
 *	Constructs complete variable name from watch structure elements
 *	---------------------------------------------------------------
 *
 */
EXABYTE	lvarbname[32];

BPTR	WatchVariableName( lwatch )
WATCHPTR	lwatch;
{
	EXAWORD	x,i;
	BPTR	dptr;

	lvarbname[0] = 0;

	/* Construct new name if dimensioned */
	/* --------------------------------- */
	if ((x = lwatch->descriptor) & ISLOCAL)
		dptr = (LocalDataTable + (x & TOGLOBAL));
	else 	dptr = (GlobalDataTable + x);

	/* Collect Variable Descriptor */
	/* --------------------------- */
	x = Tcodeword( dptr );

	/* Check for First Dimension */
	/* ------------------------- */	
	if ( x & 0x0040 ) {

		/* Copy variable name */
		/* ------------------ */
		i = 0;
		do	{
			lvarbname[i] = *(lwatch->name + i);
			i++;
			}
		while ((*(lwatch->name + i) != 0 ) && (*(lwatch->name + i) != ' ' ));

		/* Establish First dimension */
		/* ------------------------- */
		lvarbname[i++] = '(';

		itoa( lwatch->index, (BPTR) & lvarbname[i] , 6 );

		while ((lvarbname[i] != 0) && (lvarbname[i] != ' ')) i++;

		/* Check for Second dimension */
		/* -------------------------- */
		if ( x & 0x0020 ) {

			/* Establish Second dimension */
			/* -------------------------- */
			lvarbname[i++] = ',';

			itoa( lwatch->andex, (BPTR) & lvarbname[i] , 6 );
			while ((lvarbname[i] != 0) && (lvarbname[i] != ' ')) i++;

			}

		/* Terminate the string */
		/* -------------------- */
		lvarbname[i++] = ')'; lvarbname[i++] = 0;
		dptr = (BPTR) lvarbname;
		}
	else	dptr = lwatch->name;

	/* Return final pointer to name */
	/* ---------------------------- */
	return((BPTR) dptr );

}

/*
 *	W A T C H E V E N T C O U N T ( variable , mode )
 *	-------------------------------------------------
 *	mode == 1 : Count them all		(WatchEventList PreCalcule)
 *	mode == 0 : Return if match		(WatchMake Existance check)
 *
 */

EXAWORD	WatchEventCount( cptr , mode )
BPTR	cptr;
EXAWORD	mode;
{
	WATCHPTR	lwatch;
	EXAWORD		trapdex;
	EXABYTE		lvarb[32];
	EXAWORD		i;
	BPTR		xptr;

	/* Copy test value to local storage */
	/* -------------------------------- */
	for (i = 0; *(cptr + i); i++) lvarb[i] = *(cptr + i);
	lvarb[i] = 0; 

	/* Point to new version */
	/* -------------------- */
	xptr = cptr;
	cptr = (BPTR) lvarb;
	

	trapdex = 0;	lwatch = WatchBase;

	while ( lwatch != (WATCHPTR) 0) {

		/* Test for member of specified group */
		/* ---------------------------------- */
		if ( CompWild( WatchVariableName(lwatch) , cptr ) == 0 ) {
			if ( mode == WATCH_COUNT ) {
				trapdex++;
				}
			else	{
				trapdex = 1;
				break;
				}
			}

		lwatch = lwatch->next;
		}

	/* Copy back to original memory */
	/* ---------------------------- */
	/* Copy test value to local storage */
	/* -------------------------------- */
	for (i = 0; lvarb[i]; i++) *(xptr + i) = lvarb[i];

	*(xptr + i) = 0; 

	/* Return number found */
	/* ------------------- */
	return(trapdex);

}

/* 
 *	W A T C H M A K E ( variable_name )
 *	-----------------------------------
 *	Creates a watch structure for the variable named
 *
 */

EXAWORD	WatchMake( variable_name , mode, index , andex , vdesc )
BPTR	variable_name;
EXAWORD	mode;
EXAWORD	index;
EXAWORD	andex;
EXAWORD	vdesc;
{
	WATCHPTR	lwatch;
	EXAWORD		x;
	EXAWORD		v;
	BPTR		wptr;
	BPTR		nptr;

	/* Atttempt to allocate structure storage zone */
	/* ------------------------------------------- */
	if ((lwatch = (WATCHPTR) allocate (sizeof (struct watchform))) != (WATCHPTR) 0) {

		/* Initialise structure */
		/* -------------------- */
		lwatch->name   = (BPTR) 0;
		lwatch->value  = (BPTR) 0;
		lwatch->where  = (BPTR) 0;
		lwatch->length = 0;
		lwatch->type   = 0;
		lwatch->next   = (WATCHPTR) 0;
		lwatch->previous = (WATCHPTR) 0;

		/* Ensure Variable not nul string */
		/* ------------------------------ */
		if ((x = strlen((BPTR) variable_name )) != 0 ) {

			/* Allocate Storage space for Name Syntax */
			/* -------------------------------------- */
			if ((lwatch->name = allocate( (x + 1) )) != (BPTR) 0) {

				/* Transfer to Storage */
				/* ------------------- */
				(VOID) memcpy((BPTR) lwatch->name , (BPTR) variable_name, (USINT) (x + 1));

				/* Attempt to allocate zone for current value */
				/* ------------------------------------------ */
				if ((lwatch->value = (BPTR) allocate ( worklen1 )) != (BPTR) 0) {

					/* Save variable control values */
					/* ---------------------------- */
					lwatch->where  = workptr1;
					lwatch->length = worklen1;
					lwatch->type   = mode;
					lwatch->next   = WatchBase;
					lwatch->previous = (WATCHPTR) 0;
					lwatch->index       = index;
					lwatch->andex       = andex;
					lwatch->descriptor  = vdesc;
					nptr = WatchVariableName(lwatch);

					/* Eliminate duplicate variables */   
					/* ----------------------------- */
					if ( WatchEventCount( nptr , WATCH_EXIST ) != 0 ) {

						/* Liberate allocated structure */
						/* ---------------------------- */
						WatchFree ((BPTR) lwatch );  

						/* Return Structure Error */
						/* ---------------------- */
						return (MOINS_UN);

						}

					WatchBase = lwatch;
					if ( lwatch->next != (WATCHPTR) 0)
						lwatch->next->previous = lwatch;

					/* Separate Watch Change or Value */
					/* ------------------------------ */
					if (( mode & 32 ) == 0) {

						/* Copy current value to storage zone */
						/* ---------------------------------- */
						(VOID) memcpy((BPTR) lwatch->value,(BPTR) workptr1, (USINT) worklen1);

						}
					else	{
						/* Store TEST VALUE to Buffer */
						/* -------------------------- */
						wptr = lwatch->value;
						switch ( worktyp1 ) {
							case 4 :
							case 0 : *wptr = (EXABYTE) exatoi((BPTR) WatchVbuf,WatchVlen); break;
							case 1 : v = (EXAWORD)  exatoi((BPTR) WatchVbuf,WatchVlen);
								 balputw(v,wptr);
								 break;
							case 2 : (VOID) atobcd((BPTR) WatchVbuf,(BPTR)lwatch->value,WatchVlen,worklen1);
								 break;
							case 3 : memset((BPTR)lwatch->value,' ',(USINT) worklen1);
								 memcpy((BPTR)lwatch->value,(BPTR)WatchVbuf,(worklen1 > WatchVlen ? WatchVlen : worklen1));
								 break;
							}
						lwatch->type |= (WatchVcode << 8);
						}

					/* Perform Message Display */
					/* ----------------------- */
					WatchMessage((BPTR) TalkPtr[69] ); 

				 	/* Ajout realise */
					/* -------------- */
					db_step_ctrl |= 4;

					/* Indicate Success */
					/* ---------------- */
					return( 0 );

					}

				}

			}

		/* Liberate allocated structure */
		/* ---------------------------- */
		WatchFree ((BPTR) lwatch );  

		}

	/* Return Structure Error */
	/* ---------------------- */
	return (MOINS_UN);

}



/*
 *	Displays the Value of the watch zone
 *	------------------------------------
 *
 */
VOID	WatchShowValue(lwatch)
WATCHPTR	lwatch;
{
#ifdef	VERSION666
	if (!( DebugWatchShow(lwatch->name,lwatch->value,lwatch->where) )) {
#endif
		/* Indicate Watch Event Has Occured */
		/* -------------------------------- */
							/* ------------------- */
		WatchMessage((BPTR) TalkPtr[66] ); 	/* "WATCH EVENT BREAK" */
							/* ------------------- */

		/* Perform Display Operation */
		/* ------------------------- */
		varmod((BPTR) WatchVariableName( lwatch ) , 0 );


#ifdef	VERSION666
		}
#endif
	/* Return to caller */
	/* ---------------- */
	return;
}

short int   WllComp(xptr,yptr,l)
BPTR	xptr;
BPTR	yptr;
EXAWORD	l;
{
	BINAIRE	x;
	while ( l > 0 ) {
		if ((x = (*(xptr++) - *(yptr++))) != 0) {
			return( x );
			}
		l--;
		}
	return(0);
}

EXAWORD	WatchCompare( xptr , yptr , l , mode )
BPTR	xptr;
BPTR	yptr;
EXAWORD	l;
EXAWORD	mode;
{
	BINAIRE	x;

	/* Perform Low Level Compare Operation */
	/* ----------------------------------- */
	x = WllComp(xptr,yptr,l);
	if ( x == 0 ) {
		switch (( mode & 0x0F00)) {
			case 0x0600 : /* >= */
			case 0x0400 : /* <= */
			case 0x0100 : /* == */

					return(0);
	
			}
		}
	else if ( x > 0 ) {
		switch (( mode & 0x0F00 )) {
			case 0x0500 : /* >  */
			case 0x0600 : /* >= */
			case 0x0200 : /* <> */
					return(0);
			}
		}
	else	{
		switch (( mode & 0x0F00 )) {
			case 0x0300 : /* <  */
			case 0x0400 : /* <= */
			case 0x0200 : /* <> */
					return(0);
			}
		}
	return(1);
}

VOID	RemoveWatchElement( lwatch )
WATCHPTR	lwatch;
{

	/* Liberate this watch element */
	/* --------------------------- */
	WatchFree( lwatch );
	WatchFlags();

	/* Return to Caller */
	/* ---------------- */
	return;

}

VOID	WatchAction( lwatch )
WATCHPTR	lwatch;
{
	/* Indicate Watch Event Encountered */
	/* -------------------------------- */
	WatchShowValue(lwatch);
					
	/* Check for Permanant or Volotile */
	/* ------------------------------- */
	if ( lwatch->type & 0x0004 ) {

		if ((lwatch->type & 32) == 0 )

			/* Permanant Watch Trap So Update it */
			/* --------------------------------- */
			(VOID) memcpy((BPTR) lwatch->value, (BPTR) lwatch->where,(USINT) lwatch->length );

		}
	else	
		/* --------------------------------- */
		/* Volotile Watch Trap so Remove it  */
		/* --------------------------------- */
		/* Check for Forward Linkage pointer */
		/* --------------------------------- */
		RemoveWatchElement( lwatch );

	
	/* Signal : Watch Zone Change */
	/* -------------------------- */
	return;

}

/*
 *	W A T C H M A N ( )
 *	-------------------
 *	Verification of Variable Watch Events
 *	Returns Zero if no memory zone being watched has been modified
 *	Else Indicates a watched zone has been modified
 *
 */

EXAWORD	WatchMan(imode)
EXAWORD	imode;
{
	WATCHPTR	lwatch;
	WATCHPTR	xwatch;
	BPTR		xptr;
	BPTR		yptr;
	EXAWORD		x;
	EXAWORD		l;
	EXAWORD		flag;

	/* Avoid Empty watch lists */
	/* ----------------------- */
	if ((lwatch = WatchBase) != (WATCHPTR) 0) {
	
		/* While not end of Watch list */
		/* --------------------------- */
		while ( lwatch != (WATCHPTR) 0) {

			/* Initialise for zone compare */
			/* --------------------------- */
			l    =  lwatch->length;
			yptr =  lwatch->where;
			xwatch = lwatch->next;

			/* Ensure that the pointer is still valid */
			/* -------------------------------------- */
			if ( VerifPtr( yptr ) != 0 ) {

				/* Remove invalid Watch element */
				/* ---------------------------- */
				RemoveWatchElement( lwatch );

				lwatch = xwatch;

				/* Continue from the Top */
				/* --------------------- */
				continue;
				}

			xptr =  lwatch->value;

			if ((lwatch->type & 32 ) == 0) {

				/* Perform the zone compare */
				/* ------------------------ */
				for (x = 0,flag =0;x < l; x++ ) {

					/* If this byte is different */
					/* ------------------------- */
					if ( *(xptr +x) != *(yptr + x) ) {

						WatchAction( lwatch );
						return(1);

						}
					}
				}
			else	{
				/* Check Test value against watched zone */
				/* ------------------------------------- */
				if ( WatchCompare(yptr,xptr,l,lwatch->type) == 0) {

					/* Perform Required Action */
					/* ----------------------- */
					WatchAction( lwatch );
					return(1);
					}

				}

			/* Collect next list element pointer */
			/* --------------------------------- */
			lwatch = lwatch->next;

			}

		}
	/* Indicate no change */
	/* ------------------ */
	return(0);
}

/*
 *	W A T C H I N I T ( )
 *	---------------------
 *	Performs initialisation of memory watch structure.
 *
 */

VOID	WatchInit()
{
	/* Initialise Watch structure Base pointer */
	/* --------------------------------------- */
	WatchBase = (WATCHPTR) 0;

	/* Ensure Flags are Coherant */
	/* ------------------------- */
	WatchFlags();


	return;
}





/*
 *	W A T C H R A Z ( )
 *	-------------------
 *	Remove the Watch management informations
 *
 */

VOID	WatchRaz()
{
	WATCHPTR	lwptr;	
	WATCHPTR	nwptr;

	/* Collect base pointer */
	/* -------------------- */
	lwptr = WatchBase;

	/* While Current is valid */
	/* ---------------------- */
	while ( lwptr != (WATCHPTR) 0 ) {

		/* Get next structure */
		/* ------------------ */
		nwptr = lwptr->next;

		/* Liberate this pointer */
		/* --------------------- */
		WatchFree( lwptr );

		/* Collect next pointer */
		/* -------------------- */
		lwptr = nwptr;

		}

	/* Ensure Clean Condition */
	/* ---------------------- */
	WatchInit();
}

#ifdef	ABAL21
/*
 *	W A T C H E V E N T L I S T ()
 *	------------------------------
 *	Displays selective list of currently active watch events
 *
 *
 */

VOID		display_watch_item( topcol, toplin, nbc, lwatch )
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbc;
WATCHPTR	lwatch;
{
	EXAWORD	nombre=0;
	EXAWORD	l;

	if ( lwatch == (WATCHPTR) 0 )
		left_string( topcol, (toplin+nombre), nbc, (BPTR) " ");
	else	{
		pos( toplin, topcol );
		x_putch(' '); nombre++;
		x_cprintf((BPTR) lwatch->name);
		nombre += exadb_strlen((BPTR) lwatch->name );
		for ( ; nombre < 25; nombre++ )
			x_putch(' ');
 
		switch ((lwatch->type & 0x0F00)) {
			case 1 : x_cprintf((BPTR) "=  "); break;
			case 2 : x_cprintf((BPTR) "<> "); break;
			case 3 : x_cprintf((BPTR) ">  "); break;
			case 4 : x_cprintf((BPTR) ">= "); break;
			case 5 : x_cprintf((BPTR) "<  "); break;
			case 6 : x_cprintf((BPTR) "<= "); break;
			default: x_cprintf((BPTR) "   "); break;
			}

		nombre += 3;

		/* Indicate Permenace or OneShot */
		/* ----------------------------- */
		if (lwatch->type & 0x0004) {
			x_cprintf((BPTR)TalkPtr[53]);
			nombre += exadb_strlen((BPTR)TalkPtr[53]);
			}

		for ( ; nombre < nbc; nombre++ )
			x_putch(' ' );

		}
	return;
}

VOID	flush_watch_events(vh)
EXAWORD	vh;
{
	WATCHPTR	lwatch=WatchBase;

	while ( lwatch != (WATCHPTR) 0 ) {
		if (lwatch->type & 0x0004)
			stream_putb(vh,'A');
		else	stream_putb(vh,'B');
		stream_putb(vh,'V');
		stream_puts(vh,(BPTR) WatchVariableName( lwatch ) );
		stream_putlf(vh);
		lwatch = lwatch->next;
		}
	return;
}

BPTR	watchpointlist() 
{
	WATCHPTR	lwatch=(WATCHPTR) 0;
	EXAWORD	width;
	EXAWORD	item;
	BPTR	wptr;
	BPTR	rptr;

	for (	width=0,
		lwatch = WatchBase;
		lwatch != (WATCHPTR) 0;
		lwatch = lwatch->next )
		width += ( strlen( lwatch->name ) + 4 );

	if ((!( width ))
	||  (!( rptr = allocate( width + 10 ) )))
		return((BPTR) 0);

	wptr = rptr; *wptr = 0;

	for (	item=0,
		lwatch = WatchBase;
		lwatch != (WATCHPTR) 0;
		lwatch = lwatch->next ) {
		if (item++) strcpy(wptr++,"|");
		strcpy(wptr,lwatch->name);
		wptr += strlen( wptr );
		}
	return( rptr );
}

VOID		display_watch_page( topcol, toplin, nbc, nbl, lwatch )
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbc;
EXAWORD		nbl;
WATCHPTR	lwatch;
{
	EXAWORD	nombre=0;
	for ( nombre=0; nombre < nbl; nombre++ ) {
		if ( lwatch == (WATCHPTR) 0)
			break;
		display_watch_item( topcol, (toplin+nombre), nbc, lwatch );
		lwatch = lwatch->next;
		}
	for ( ; nombre < nbl; nombre++ )
		left_string( topcol, (toplin+nombre), nbc, (BPTR) " ");
	return;
}

VOID	WatchEventList( cptr )
BPTR	cptr;
{
	WATCHPTR	lwatch=(WATCHPTR) 0;
	WATCHPTR	xwatch=(WATCHPTR) 0;
	EXAWORD	c;
	EXAWORD	item=0;
	EXAWORD	entry=0;
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
	EXAWORD	nbc=44;
	EXAWORD	nbl=0;
	EXAWORD	watchcount=0;
	EXAWORD	maxlines=13;

	/* Do nothing if no Watch events exist declared */
	/* -------------------------------------------- */
	if ((lwatch = WatchBase) == (WATCHPTR) 0) 
		return;
	
	/* Pre calculate number of traps which match request */
	/* ------------------------------------------------- */
	if ((watchcount = WatchEventCount((BPTR) "*", WATCH_COUNT )) == 0) 
		return;

	maxlines = avoid_observations( 13 );
	if (!( maxlines & 1))
		maxlines--;

	nbl = (watchcount > maxlines ? maxlines : watchcount );

	mouse_title_box( topcol, toplin, nbc, nbl, (BPTR) TalkPtr[65] );
	display_watch_page( (topcol+1), (toplin+1), nbc, nbl, WatchBase );

	xwatch = lwatch = WatchBase;

	while ( 1 ) {

		symbolic_atribut(2);
		display_watch_item( (topcol+1), (toplin+1+item), nbc, xwatch );
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		display_watch_item( (topcol+1), (toplin+1+item), nbc, xwatch );
		switch ( c ) {
			case	0x001B 	:
				pop_mouse();
				return;

			case	CTRL_D	:
				if ( DbMouse.position == 0 )
					continue;
				item++;
				if ( DbMouse.position < item ) {
					for (; DbMouse.position < item; item-- ) {
						if ((xwatch != (WATCHPTR) 0)
						&&  (xwatch->previous != (WATCHPTR) 0))
							xwatch = xwatch->previous;
						else	break;
						}
					}
				else	{
					for (; item < DbMouse.position; item++ ) {
						if ((xwatch != (WATCHPTR) 0)
						&&  (xwatch->next != (WATCHPTR) 0))
							xwatch = xwatch->next;
						else	break;
						}
					}
				item--;
				if ( current_mouse_click() != 2 )
					continue;

			case	CTRL_M	:
				pop_mouse();
				display_variable_declaration( xwatch->name, xwatch->descriptor );
				mouse_title_box( topcol, toplin, nbc, nbl, (BPTR) TalkPtr[65] );
				break;

			case	CTRL_Y  :
				RemoveWatchElement( xwatch );
				if ( WatchBase == (WATCHPTR) 0) {
					pop_mouse();
					return;
					}

			case	CTRL_L	:
				xwatch = lwatch = WatchBase;
				item = 0;
				break;

			case	CTRL_E	:
				if (( xwatch != (WATCHPTR) 0)
				&&  ( xwatch->next != (WATCHPTR) 0)) {
					xwatch = xwatch->next;
					if ( item < (nbl-1) )
						item++;  
					else 	{
						lwatch = lwatch->next;
						break;
						}
					}
				continue;
								
			case	CTRL_K	:
				if (( xwatch != (WATCHPTR) 0)
				&&  ( xwatch->previous != (WATCHPTR) 0)) {
					xwatch = xwatch->previous;
					if ( item > 0 )
						item--;  
					else 	{
						lwatch = lwatch->previous;
						break;
						}
					}
				continue;

			case	CTRL_C	:
				for ( entry = 0; entry < (nbl/2); entry++ ) {
					if ((xwatch != (WATCHPTR) 0)
					&&  (xwatch->next != (WATCHPTR) 0)) {
						lwatch = lwatch->next;
						xwatch = xwatch->next;
						}
					else	break;
					}
				break;

			case	CTRL_R	:
				for ( entry = 0; entry < (nbl/2); entry++ ) {
					if ((lwatch != (WATCHPTR) 0)
					&&  (lwatch->previous != (WATCHPTR) 0)) {
						lwatch = lwatch->previous;
						xwatch = xwatch->previous;
						}
					else	break;
					}
				break;

			}

		display_watch_page( (topcol+1), (toplin+1), nbc, nbl, lwatch);
		}
	return;
}
#else	/* ABAL14 */

VOID	WatchEventList( cptr )
BPTR	cptr;
{
	WATCHPTR lwatch;
	EXAWORD	trapdex;
	EXAWORD	x,lno,c,nbl,lc;
	EXAWORD	width;
	BPTR	nptr;

	/* Do nothing if no Watch events exist declared */
	/* -------------------------------------------- */
	if ((lwatch = WatchBase) == (WATCHPTR) 0) { return; }

	/* Ensure at least something to List */
	/* --------------------------------- */
	if ( strlen((BPTR) cptr) == 0) { cptr = (BPTR) "*"; }

	/* Pre calculate number of traps which match request */
	/* ------------------------------------------------- */
	if ((trapdex = WatchEventCount( cptr , WATCH_COUNT )) == 0) { return; }

	/* Adjust value and establish base pointer */
	/* --------------------------------------- */
	trapdex++; lwatch = WatchBase;

	/* Calculate Maximum Window Size */
	/* ----------------------------- */
	if (( ScreenCol - 3 ) < 52 ) 	{ c = (ScreenCol - 3);  }
	else				{ c = 52;		}
	nbl = (trapdex > 16 ? 19 : trapdex + 3);

	WdwLimit(8,nbl,c);

	/* Create Window */
	/* ------------- */
	if (PushZone(WindCord[8][0],WindCord[8][1],(trapdex > 16 ? 19 : trapdex + 3),c,0x0013,Couleurs[8][0],Couleurs[8][1]) != 0) {
		Debordement();
		return;
		}

	/* Display Description Text */
	/* ------------------------ */
	db_xcprintf((BPTR) TalkPtr[65]); 	/* "Watch Event List" */
						/* ------------------ */
	db_xcprintf((BPTR)" : "); 
	lno = 2; x = 0;
	lwatch = WatchBase;

	/* Repeat until Not End of Liste */
	/* ----------------------------- */
	while ( lwatch != (WATCHPTR) 0 ) {

		/* Test for member of specified group */
		/* ---------------------------------- */
		if ( CompWild((nptr = WatchVariableName( lwatch )) , cptr ) == 0 ) {

			/* Position to current line and display */
			/* ------------------------------------ */
			wdw_xpos(lno++,2);
			width = strlen((BPTR) nptr);
			db_xcprintf((BPTR) nptr );

			while (width < 23 ) {
				db_xputch(' ');
				width++;
				}

			switch ((lwatch->type & 0x0F00)) {
				case 1 : db_xcprintf((BPTR) "=  ");
				case 2 : db_xcprintf((BPTR) "<> ");
				case 3 : db_xcprintf((BPTR) ">  ");
				case 4 : db_xcprintf((BPTR) ">= ");
				case 5 : db_xcprintf((BPTR) "<  ");
				case 6 : db_xcprintf((BPTR) "<= ");
				default: db_xcprintf((BPTR) "   ");
				}

			width = strlen((BPTR)TalkPtr[53]);
			db_xputch(' ');

			/* Indicate Permenace or OneShot */
			/* ----------------------------- */
			if (lwatch->type & 0x0004) 
				db_xcprintf((BPTR)TalkPtr[53]);
			else	{
				while (width > 0 ) {
					db_xputch(' ');
					width--;
					}
				}
			db_xputch(' ');

			/* If Physical Page End Reached */
			/* ---------------------------- */
			if (((x + 1) % 16) == 0 ) {
				Validate(0); lno = 4;
				}

			x++;
			}

		/* Next Trap Context */
		/* ----------------- */
		lwatch = lwatch->next;

		}

	/* Perform Standard Function Exit Wait */
	/* ----------------------------------- */
	switch ( ExitMethod(1) ) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}

	/* Return without error */
	/* -------------------- */
	return;

}

#endif	/* ABAL21 or ABAL14 */

VOID	WatchEventSupr( cptr )
BPTR	cptr;
{
	WATCHPTR	wptr;
	WATCHPTR	xptr;

	/* Establish initial pointers to liste */
	/* ----------------------------------- */
	if ((wptr = WatchBase) == (WATCHPTR) 0) 
		return;

	xptr = (WATCHPTR) 0;


	while ( wptr != (WATCHPTR) 0 ) {

		/* Test for member of specified group */
		/* ---------------------------------- */
		if ( CompWild( WatchVariableName( wptr ) , cptr ) == 0 ) {
			
			/* Remove this element from inside the list */
			/* ---------------------------------------- */
			if ( xptr != (WATCHPTR) 0) {
				xptr->next = wptr->next;
				WatchFree( wptr );
				wptr = xptr->next;
				}

			/* Remove this element from head of list */
			/* ------------------------------------- */
			else	{
				WatchBase = wptr->next;
				WatchFree( wptr );
				wptr = WatchBase;
				}
			WatchMessage((BPTR) TalkPtr[70] );
			continue;

			}

		/* Save current pointer */
		/* -------------------- */
		xptr = wptr;

		/* Collect next element */
		/* -------------------- */
		wptr = wptr->next;
		}

	/* Perform Watch Status check */
	/* -------------------------- */
	WatchFlags();
	return;
}

VOID	DeleteWatchPoint( EXAWORD id )
{
	WATCHPTR	wptr;
	EXAWORD		item;
	for ( 	item=0,
		wptr = WatchBase;
		wptr != (WATCHPTR) 0;
		wptr = wptr->next ) {
		if ( item == id ) {
			WatchEventSupr( wptr->name );
			break;
			}
		else	item++;
		}
	return;
}


/*
 *	W A T C H F U N C T I O N S ( cmdptr )
 *	--------------------------------------
 *	Provides interface and parsing for all watch events functions
 *	other that the creation of watch trap events
 *
 *	Currently Supported :
 *
 *	V?, Vl , VL		:List of active watch events
 *	VI syntax
 *	Vi syntax		:Inhibition of specified  watch activity
 *
 */

VOID	WatchFunctions( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	c;

	/* Remove any white space */
	/* ---------------------- */
	cmdptr = CmdShift(cmdptr);

	c = *(cmdptr++);

	cmdptr = CmdShift(cmdptr);

	/* Select requested command function */
	/* --------------------------------- */
	switch ( c ) {

		case '?' :
		case 'l' :
		case 'L' :	WatchEventList( cmdptr ); break;

		case 'i' :
		case 'I' :	WatchEventSupr( cmdptr ); break;
		
		}

	return;
}

/*
 *	W A T C H V A L U E ( cmdptr )
 *	------------------------------
 *	Extraction of a watch conditional Value
 *	from the watch syntax command line
 *
 */

BPTR	WatchValue( cmdptr )
BPTR	cmdptr;
{
	WatchVcode = 0;

	/* Detect Compare operation required to be performed */
	/* ------------------------------------------------- */
	switch ( *cmdptr ) {
		case '=' : WatchVcode = 1; break;
		case '<' : if ( *(cmdptr + 1) == '>' ) {
				WatchVcode = 2; cmdptr++;
				}
			   else	{
				if ( *(cmdptr + 1) == '=' ) {
					WatchVcode = 4; cmdptr++;
					}
				else	{
					WatchVcode = 3;
					}
				}
			   cmdptr++; break;

		case '>' : if ( *(cmdptr + 1) == '=' ) {
				WatchVcode = 6; cmdptr++;
				}
			   else	{
				WatchVcode = 5;
				}
			   cmdptr++; break;

		default  : return( cmdptr );
		}

	/* Transfer Value to Storage Zone */
	/* ------------------------------ */
	WatchVlen = 0; cmdptr++;

	while (( *cmdptr != 0 ) && ( WatchVlen < WATCHVMAX )) {
		WatchVbuf[WatchVlen] = *(cmdptr++);
		WatchVlen++;
		}
	WatchVbuf[WatchVlen] = 0;
	
	return( cmdptr );
}

#ifdef	ABAL21
EXAWORD	check_watch( vid, vnom )
EXAWORD	vid;
BPTR	vnom;
{
	WATCHPTR	wptr;
	EXAWORD		wildcomp(BPTR,BPTR);

	/* Establish initial pointers to liste */
	/* ----------------------------------- */
	if ((wptr = WatchBase) != (WATCHPTR) 0) {
		do	{
			if (((wptr->descriptor & TOGLOBAL) == vid )
			&&  (wildcomp((BPTR) wptr->name,(BPTR) vnom) != MOINS_UN ))
				return( ( wptr->type & 0x0004 ? 1 : 2 ) );

			}
		while ((wptr = wptr->next) != (WATCHPTR) 0);

		}
	return(0);

	
}
#endif

#endif	/* _EXDBWTCH_C */
	/* ----------- */
