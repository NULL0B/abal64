/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBOBS.C 				*/
/*		Date 	:	23/09/1996				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBOBS_C
#define	_EXDBOBS_C

#define	DEBUGGER

#include "exctype.h"
#include "exdebug.h"
#include "exdbctrl.h"
#include "exdbcico.h"
#include "exdbmimo.h"
#include "exdbobs.h"
#include "allocate.h"
#include "exproto1.h"
#ifdef	ABAL21
#include "exdbstre.h"
#else
#define	display_integer(v) intvisi(v)
#define display_hexint(v)  showword(v,4)
#define display_hexbyte(v)  showword(v,2)
#define	get_variable_name(i) varbname(i)
#endif

EXTERN	EXAWORD	ScreenLin;
EXTERN	EXAWORD	ScreenCol;

VOID	draw_space( width )
EXAWORD	width;
{
	for ( ; width > 0; width-- )
		x_putch(' ');
}

VOID	left_string( c, l, w, msg )
EXAWORD	c;
EXAWORD	l;
EXAWORD	w;
BPTR	msg;
{
	x_bstart();
	pos( l, c );
	while (( *msg ) && ( w != 0 )) {
		x_putch( *(msg++) );
		w--;
		}
	draw_space( w );
	x_bflush();
	return;
}	

VOID	right_string( c, l, w, msg )
EXAWORD	c;
EXAWORD	l;
EXAWORD	w;
BPTR	msg;
{
	EXAWORD	n;
	x_bstart();
	pos( l, c );
	n = exadb_strlen( msg );
	while (( n > w )
	&&     ( *msg  )) {
		msg++;
		n--;
		}
	while (( *msg ) && ( w != 0 )) {
		x_putch( *(msg++) );
		w--;
		}
	draw_space( w );
	x_bflush();
	return;
}	

EXAWORD	hidden_observation( lobs )
OBSPTR	lobs;
{
	/* Check for and inhibit inaccessible variables */
	/* -------------------------------------------- */
	if ( lobs->descriptor & ISLOCAL ) { 
		if ( sicico & ONSEM_PRC ) { 
			if ((( lobs->type & 0x0010 ) == 0 )
			||  (  procid != lobs->owner ))
				return( 1 );
			}
		else	{
			if ((( lobs->type & 0x0010 ) != 0 )
			||  ( cur_seg != lobs->owner)) 
				return( 1 );
			}
		}
	return(0);
}

VOID	display_observation_identity( lobs, showmode )
OBSPTR	lobs;
EXAWORD	showmode;
{
	BPTR	nptr;
	BPTR	get_variable_name( EXAWORD );
	BPTR	varbname( EXAWORD );
	EXAWORD	x;

	if ( showmode == 0 ) {
		if ( trad_ver > '1' ) {
			if ((nptr = get_variable_name( lobs->descriptor )) != (BPTR) 0)
				x_cprintf((BPTR) nptr );
			else	showmode = 1;
			}
		else	{
			if ((nptr = varbname(lobs->descriptor)) != (BPTR) 0) {
				for ( x=0; x < 8; x++)
					x_putch(*(nptr++));
				}
			else	showmode = 1;		
			}
		}

	if ( showmode ) {
		x_putch('[');
		display_hexint( lobs->descriptor );
		x_putch(']');
		}

	if (( lobs->type & 0x0040 ) != 0 ) { 
		x_putch('('); 
		if ( lobs->index != 0 ) 
			display_integer( lobs->index );
		else	x_putch('*');
		if (( lobs->type & 0x0020 ) != 0 ) {
			x_putch(','); 
			if ( lobs->andex != 0 ) 
				display_integer( lobs->andex );
			else	x_putch('*');
			}
		x_putch(')');
		}
	return;
}

#ifdef	ABAL21
VOID	display_observation_item(topcol,toplin,nbcol,xobs)
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
OBSPTR	xobs;
{
	EXAWORD	showmode=0;

	left_string( topcol,toplin,nbcol,(BPTR) " ");

	if ( xobs == (OBSPTR) 0 )
		return;

	if ( hidden_observation( xobs ) )
		showmode = 1;
	else	showmode = 0;

	pos(toplin,topcol);
	display_observation_identity( xobs, showmode );

	return;
}

VOID	display_observation_page(topcol,toplin,nbcol,nblin, xobs)
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
EXAWORD	nblin;
OBSPTR	xobs;
{
	EXAWORD	nombre;
	for ( nombre= 0; nombre < nblin; nombre++ ) {
		if ( xobs == (OBSPTR) 0 )
			break;
		display_observation_item(topcol,(toplin+nombre),nbcol,xobs);
		xobs = xobs->next;
		}
	for ( ; nombre < nblin; nombre++ )
		left_string( topcol,(toplin+nombre), nbcol, (BPTR) " ");
		
	return;
}
#endif

VOID	remove_observation_item( lobs )
OBSPTR	lobs;
{
	if ( lobs != (OBSPTR) 0 ) {
		if (lobs->next != (OBSPTR) 0)
			lobs->next->previous = lobs->previous;
		if ( lobs->previous != (OBSPTR) 0)
			lobs->previous->next = lobs->next;
		else	ObsBase = lobs->next;
		liberate( lobs );
		}
	return;
}

EXAWORD	avoid_observations( limit )
EXAWORD	limit;
{
	if ( ObservationCount )
		return(limit - (ObservationCount-1));
	else	return( limit );
}

#ifdef	ABAL21

VOID	observation_zoom( lobs )
OBSPTR	lobs;
{
	BPTR	nptr;
	BPTR	get_variable_name( EXAWORD );
	BPTR	varbname( EXAWORD );
	EXAWORD	x;
	if ( trad_ver > '1' )
		nptr = get_variable_name( lobs->descriptor );
	else	nptr = varbname(lobs->descriptor);
	display_variable_declaration((BPTR) nptr, lobs->descriptor);
	draw_empty_box(1,19,ScreenCol,3);
	return;
}

VOID	observation_list()
{
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
	EXAWORD	nbcol=48;
	EXAWORD	nblin=13;
	EXAWORD	c;
	EXAWORD	item=0;
	OBSPTR	lobs=(OBSPTR) 0;
	OBSPTR	xobs=(OBSPTR) 0;

	if ( ObsBase == (OBSPTR) 0 )
		return;

	nblin = avoid_observations( 13 );

	if ((!(nblin & 1)) && ( nblin != 0 ))
		nblin--; 	
	
	mouse_title_box( topcol, toplin, nbcol, nblin, (BPTR) TalkPtr[52] );
	display_observation_page( (topcol+1), (toplin+1), nbcol, nblin, ObsBase   );

	xobs = lobs = ObsBase; 

	while ( 1 ) {
		symbolic_atribut(2);
		display_observation_item((topcol+1),(toplin+1+item),nbcol,xobs);
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		display_observation_item((topcol+1),(toplin+1+item),nbcol,xobs);
		switch ( c ) {
			case CTRL_E :
				if ((xobs != (OBSPTR) 0)
				&&  (xobs->next != (OBSPTR) 0)) {
					xobs = xobs->next;
					if ( item < (nblin-1) )
						item++;
					else	{
						lobs = lobs->next;
						break;
						}
					}
				continue;

			case CTRL_K :
				if ((xobs != (OBSPTR) 0)
				&&  (xobs->previous != (OBSPTR) 0)) {
					xobs = xobs->previous;
					if ( item > 0 )
						item--;
					else	{
						lobs = lobs->previous;
						break;
						}
					}
				continue;

			case CTRL_C :
				for ( c = 0; c < (nblin/2); c++ ) {
					if ((lobs != (OBSPTR) 0)
					&&  (lobs->next != (OBSPTR) 0)) {
						lobs = lobs->next;
						xobs = xobs->next;
						}
					else	break;
					}
				break;

			case CTRL_R :
				for ( c = 0; c < (nblin/2); c++ ) {
					if ((lobs != (OBSPTR) 0)
					&&  (lobs->previous != (OBSPTR) 0)) {
						lobs = lobs->previous;
						xobs = xobs->previous;
						}
					else	break;
					}
				break;

			case CTRL_D :
				if ( DbMouse.position == 0 )
					continue;
				item++;
				if ( DbMouse.position < item ) {
					for (; DbMouse.position < item; item-- ) {
						if ((xobs != (OBSPTR) 0)
						&&  (xobs->previous != (OBSPTR) 0))
							xobs = xobs->previous;
						else	break;
						}
					}
				else	{
					for (; item < DbMouse.position; item++ ) {
						if ((xobs != (OBSPTR) 0)
						&&  (xobs->next != (OBSPTR) 0))
							xobs = xobs->next;
						else	break;
						}
					}
				item--;
				if ( current_mouse_click() != 2 )
					continue;

			case CTRL_M :
				symbolic_atribut(2);
				display_observation_item((topcol+1),(toplin+1+item),nbcol,xobs);
				symbolic_atribut(0);
				observation_zoom( xobs );
				mouse_title_box( topcol, toplin, nbcol, nblin, (BPTR) TalkPtr[52] );
				break;

			case CTRL_Y :
				remove_observation_item( xobs );
			case CTRL_L :
				item = 0;
				xobs = lobs = ObsBase;
				break;

			case 0x001B :
				pop_mouse();
				return;
			}
		display_observation_page( (topcol+1), (toplin+1), nbcol, nblin, lobs  );
		}
	return;
}
#endif

VOID	liberate_observations()
{
	OBSPTR	lobs;

	while ((lobs = ObsBase) != (OBSPTR) 0 ) {
		ObsBase = ObsBase->next;
		liberate( lobs );
		}
	return;
}

VOID	initialise_observations( )
{
	ObsBase = (OBSPTR) 0;
	ObservationCount = 0;
	return;
}

EXAWORD	is_known_observation( vid )
EXAWORD	vid;
{
	OBSPTR	lobs;
	lobs = ObsBase;
	while ( lobs != (OBSPTR) 0 ) {
		if ( lobs->descriptor == vid )
			return(1);
		lobs = lobs->next;
		}
	return(0);	
}


VOID	observation_management( cmdptr )
BPTR	cmdptr;
{
	EXABYTE	c;
	EXAWORD	x,y,v,w;
	EXABYTE	lbuf[16];
	EXAWORD	vid,vind,vand;
	BPTR	wptr;
	EXAWORD	wlen;
	BPTR	xptr;
	EXAWORD	xlen;
	EXAWORD	global_flag;
	OBSPTR	lobs=(OBSPTR) 0;

	c = toupper(*cmdptr); cmdptr++;
	if ( c == 'L' ) {
		observation_list();
		return;
		}
	else if ((c == 'A') || ( c == 'I' )) {
		/* Avoid White Space */
		/* ----------------- */
		cmdptr = CmdShift(cmdptr);
		if ( *cmdptr == IO_NUL ) 
			return;
#ifdef	ABAL21
		if ( *cmdptr == '$' ) {
			global_flag = 1;
			cmdptr++;
			}
		else
#endif
			global_flag = 0;
				
		/* Seek End of Identifier */
		/* ---------------------- */
		wptr = cmdptr; wlen = 0;
		while (( *wptr != '(' ) && ( *wptr != IO_NUL)) {
			wptr++; wlen++; 
			}

		/* Check for ETOILE total liberation of Observations */
		/* ------------------------------------------------- */
		if ((exadb_strlen((BPTR) cmdptr) == 1) && (*cmdptr == '*')) {
			if ( c == 'I' )
				liberate_observations();
			return;
			}

		/* End of Identifier : Check for Dimensions */
		/* ---------------------------------------- */
		if ( *wptr == IO_NUL ) { 
			/* Simple Variable */
			/* --------------- */
			vind = 1; vand = 1; 
			}
		else 	{
			/* Complex Variable */
			/* ---------------- */
			*(wptr++) = (EXABYTE) 0; 	/* Terminate for Name Seeker */
			xptr = wptr; xlen = 0;

			/* Seek dimension Separator or Terminator */
			/* -------------------------------------- */
			while (( *xptr != ',' ) && ( *xptr != IO_NUL) && ( *xptr != ')')) { 
				xptr++; xlen++; 
				}
			/* Convert and Collect 1st Dimension Value */
			/* --------------------------------------- */
			if ( *wptr == '*' ) 
				vind = 0;
			else 	{ 
				vind = atoi(wptr,xlen);  	
				}

			/* Seek for 2nd Dimension OR default == 1 */
			/* -------------------------------------- */
			if (( *xptr == IO_NUL ) || ( *xptr == ')' )) 
				vand = 1; 
			else 	{	
				/* Collect 2nd Dimension Value */
				/* --------------------------- */
				xptr++;
				xlen = strlen(xptr);
				if ( *xptr == '*' ) 
					vand = 0;
				else	{ 
					vand = atoi(xptr,xlen);
					}
				}
			}

		/* Separate Ajout / Suprime */
		/* ------------------------ */
		if ( c == 'A' ) {

			/* Avoid Error 102 due to Variable(*,*) */
			/* ------------------------------------ */
			if ( vind == 0 )
				vind = 1;
			if ( vand == 0 )
				vand = 1;

			/* Control Variable Identitifier Validity */
			/* -------------------------------------- */
			if (( vid = nametest( cmdptr, global_flag )) != 0 ) {

				if ((lobs = (OBSPTR) allocate( sizeof( struct exadb_observe ) )) == (OBSPTR) 0 ) {
#ifdef	ABAL21
					standard_errors( 27 );
#endif
					return;
					}

				lobs->descriptor = vid;
				lobs->index 	 = vind;
				lobs->andex 	 = vand;
				lobs->type 	 = dbvartyp(vid);

				/* Check for a Local Variable */
				/* -------------------------- */
				if ( vid & ISLOCAL ) {	/* If VARLOC */

					/* If Currently inside a Procedure */
					/* ------------------------------- */
					if ( sicico & ONSEM_PRC ) {

						/* Store Procedure identifier */
						/* -------------------------- */
						lobs->owner =  procid;
						lobs->type |= 0x0010;
						}
					else	{
						/* Store Segment Identity */
						/* ---------------------- */ 
						lobs->owner	= cur_seg;
						lobs->type	&= 0xFFEF;
						}
					}
				else	/* Global Variable */
					/* --------------- */
					lobs->owner = 0; 

				/* Advance Observation Counter */
				/* --------------------------- */ 
				if (( lobs->next = ObsBase ) != (OBSPTR) 0)
					lobs->next->previous = lobs;
				lobs->previous = (OBSPTR) 0;
				ObsBase = lobs;

				/* Indicate Success */
				/* ---------------- */
				Verbose((BPTR)TalkPtr[69]);
				/* "Ajout realise" */
				/* --------------- */
				}
			else 	Verbose((BPTR)TalkPtr[59]);
				/* "Variable inconnue" */
				/* ------------------- */

			return;
			}
		/* Otherwise Suprssion */
		/* ------------------- */
		else	{
			if (( vid = nametest( cmdptr, global_flag )) != 0 ) {
				lobs = ObsBase;
				while ( lobs != (OBSPTR) 0 ) {
					if ( hidden_observation( lobs ) ) {
						lobs = lobs->next;
						continue;
						}
					if (( lobs->descriptor == vid )
					&&  (( lobs->index == vind ) || ( vind == 0 ))
					&&  (( lobs->andex == vand ) || ( vand == 0 ))) {
						remove_observation_item( lobs );
						lobs = ObsBase;
						continue;
						}
					}
				Verbose((BPTR)TalkPtr[70]);
				/* "Supression realise" */
				/* -------------------- */
				}
			else 	Verbose((BPTR)TalkPtr[59]);
				/* "Variable inconnue" */
				/* ------------------- */
			}
		}
	return;
}

OBSPTR	next_visible_observation( lobs )
OBSPTR	lobs;
{
	while ((lobs != (OBSPTR) 0)
	&&     (hidden_observation( lobs )))
		lobs = lobs->next;
	return( lobs );
}

OBSPTR	previous_visible_observation( lobs )
OBSPTR	lobs;
{
	while ((lobs != (OBSPTR) 0)
	&&     (hidden_observation( lobs )))
		lobs = lobs->previous;
	return( lobs );
}

void	show_observation_item( topcol, toplin, nbcol, lobs )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
OBSPTR	lobs;
{
	EXAWORD	nombre;

	left_string( topcol, toplin, nbcol,(BPTR) " ");

	if ( lobs == (OBSPTR) 0 )
		return;

	/* Display Variable and Indices */
	/* ---------------------------- */
	pos( toplin, topcol );
	display_observation_identity( lobs, 0 );
	pos( toplin, topcol+24);

	freg [COPYREG] = lobs->descriptor; 
	ireg [COPYREG] = lobs->index;
	areg [COPYREG] = lobs->andex; 
	xreg [COPYREG] = 0x0002;
	if ( argset(4,COPYREG,2) != SOFTERROR ) {	
	   if(workptr2 != (BPTR)0)
	   {
		for ( nombre = 0; (nombre < 16) && (worklen2 > 0); nombre++, worklen2-- ) {
			x_putch(' ');		

			/* Control adresse for systeme validity */
			/* ------------------------------------ */
			if ( VerifPtr( workptr2 ) == 0 ) {
				display_hexbyte(((EXAWORD) *(workptr2)));
				workptr2++;
				}
			else	{
				db_xputch(' ');
				db_xputch(' ');
				}

			}
	   }
	}
#ifdef	ABAL21
	else	standard_errors( err_val );
#endif
	return;
}

#ifdef	ABAL21
VOID	flush_observations(vh)
EXAWORD	vh;
{
	BPTR	nptr;
	OBSPTR	lobs=ObsBase;
	BPTR	get_variable_name( EXAWORD );
	while ( lobs != (OBSPTR) 0) {
		if ((nptr = get_variable_name( lobs->descriptor )) != (BPTR) 0) {
			stream_putb(vh,'O');
			stream_putb(vh,'A');
			stream_puts(vh,(BPTR) nptr );
			if (( lobs->type & 0x0040 ) != 0 ) { 
				stream_putb(vh,'('); 
				if ( lobs->index != 0 ) 
					stream_puti(vh, lobs->index );
				else	stream_putb(vh,'*');
				if (( lobs->type & 0x0020 ) != 0 ) {
					stream_putb(vh,','); 
					if ( lobs->andex != 0 ) 
						stream_puti(vh, lobs->andex );
					else	stream_putb(vh,'*');
					}
				stream_putb(vh,')');
				}
			stream_putlf(vh);
			}
		lobs = lobs->next;
		}
	return;
}

void	show_observation_page( topcol, toplin, nbcol, nblin, lobs )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
EXAWORD	nblin;
OBSPTR	lobs;
{
	EXAWORD	nombre;
	for ( nombre=0; nombre < nblin; nombre++ ) {
		if (( lobs = next_visible_observation( lobs )) == (OBSPTR) 0)
			break;
		show_observation_item( topcol,(toplin+nombre), nbcol, lobs );
		lobs = lobs->next;
		}
	for ( ; nombre < nblin; nombre++ )
		left_string(topcol,(toplin+nombre),nbcol,(BPTR) " ");
	return;
} 		
#endif

#ifdef	ABAL21
EXAWORD	Observe( mode )
EXAWORD	mode;
{
	EXAWORD	topcol=1;
	EXAWORD	toplin=0;
	EXAWORD	nbcol=80;
	EXAWORD	nblin=0;
	EXAWORD	item=0;
	OBSPTR	lobs=(OBSPTR) 0;
	OBSPTR	xobs=(OBSPTR) 0;
	OBSPTR	tobs=(OBSPTR) 0;
	EXAWORD	c;
	nbcol = ScreenCol;
	if ((lobs = ObsBase) == (OBSPTR) 0 )
		return((ObservationCount=0));

	/* Count the Observation Variables to Be Displayed */
	/* ----------------------------------------------- */
	while ((lobs != (OBSPTR) 0) && ( nblin < 5 )) {
		if (!( hidden_observation( lobs ) ))
			nblin++;
		lobs = lobs->next;
		}

	/* Immediate return if no Observations Active */
	/* ------------------------------------------ */
	if ((ObservationCount = nblin) == 0 ) 
		return((ObservationCount=0));

	/* Calc starting line (between correspondances and function keys ) */
	/* --------------------------------------------------------------- */
	toplin = ((ScreenLin-2) - (ObservationCount - 1));

	/* display page */
	/* ------------ */
	show_observation_page( topcol, toplin, nbcol, nblin, ObsBase ); 

	if ( mode == 0 )
		return( ObservationCount );

	/* Establish mouse control and allow user operation */
	/* ------------------------------------------------ */
	set_mouse_control( topcol, toplin-1, nbcol, nblin );

	xobs = ((lobs = next_visible_observation( ObsBase )));

	while ( 1 ) {
		symbolic_atribut(2);
		show_observation_item( topcol, (toplin+item), nbcol, xobs );
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		show_observation_item( topcol, (toplin+item), nbcol, xobs );
		switch ( c ) {
			case CTRL_E :
					if ((  xobs != (OBSPTR) 0)
					&&  (  xobs->next != (OBSPTR) 0)
					&&  (( tobs = next_visible_observation( xobs->next )) != (OBSPTR) 0)) {
						xobs = tobs;
						if ( item < (nblin-1) )
							item++;
						else	{
							lobs = next_visible_observation( lobs->next );
							break;
							}
						}
					continue;

			case CTRL_K :
					if ((  xobs != (OBSPTR) 0)
					&&  (  xobs->previous != (OBSPTR) 0)
					&&  (( tobs = previous_visible_observation( xobs->previous )) != (OBSPTR) 0)) {
						xobs = tobs;
						if ( item > 0 )
							item--;
						else	{
							lobs = previous_visible_observation( lobs->previous );
							break;
							}
						}
					continue;
			case CTRL_C :
				for ( c = 0; c < (nblin/2); c++ ) {
					if ((xobs != (OBSPTR) 0)
					&&  (xobs->next != (OBSPTR) 0)
					&&  ((tobs = next_visible_observation( xobs->next )) != (OBSPTR) 0)) {
						xobs = tobs;
						lobs = next_visible_observation( lobs->next );
						}
					else	break;
					}
				break;
			case CTRL_R :
				for ( c = 0; c < (nblin/2); c++ ) {
					if ((lobs != (OBSPTR) 0)
					&&  (lobs->previous != (OBSPTR) 0)
					&&  ((tobs = previous_visible_observation( lobs->previous )) != (OBSPTR) 0)) {
						lobs = tobs;
						xobs = previous_visible_observation( xobs->previous );
						}
					else	break;
					}
				break;

			case CTRL_D :
				if ( DbMouse.position == 0 )
					continue;
				item++;
				if ( DbMouse.position < item ) {
					for ( ; DbMouse.position < item; item-- ) {
						if ((xobs != (OBSPTR) 0)
						&&  (xobs->previous != (OBSPTR) 0)
						&&  ((tobs = previous_visible_observation( xobs->previous )) != (OBSPTR) 0))
							xobs = tobs;
						else	break;
						}
					}
				else	{
					for ( ; item < DbMouse.position; item++ ) {
						if ((xobs != (OBSPTR) 0)
						&&  (xobs->next != (OBSPTR) 0)
						&&  ((tobs = next_visible_observation( xobs->next )) != (OBSPTR) 0))
							xobs = tobs;
						else	break;
						}
					}
				item--;
				if ( current_mouse_click() != 2 )
					continue;

			case CTRL_M :
				symbolic_atribut(2);
				show_observation_item( topcol, (toplin+item), nbcol, xobs );
				symbolic_atribut(0);
				observation_zoom( xobs );
				break;

			case CTRL_Y :
				remove_observation_item( xobs );
				ObservationCount = 0;
				if ( ObsBase == (OBSPTR) 0) {
					pop_mouse();
					return( ObservationCount );
				}
				else {
					/* Count the Observation Variables to Be Displayed */
					lobs = ObsBase;
					while ((lobs != (OBSPTR) 0) && ( ObservationCount < 5 )) {
						if (!( hidden_observation( lobs ) ))
							ObservationCount++;
						lobs = lobs->next;
					}
				}

			case CTRL_L :
				xobs = ((lobs = next_visible_observation( ObsBase )));
				item = 0;
				break;

			case 0x001B :
				pop_mouse();
				return(ObservationCount);

			}
		show_observation_page( topcol, toplin, nbcol, nblin, lobs ); 
		}
	return(ObservationCount);

}
#endif

#endif	/* _EXDBOBS_C */
	/* ---------- */
