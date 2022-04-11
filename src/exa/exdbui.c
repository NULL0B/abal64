/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.		*/
/*									*/
/*		Module  :	EXDBUI.C 				*/
/*		Date 	:	27/11/1996				*/
/*		Version :	2.1d                     		*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBUI_C
#define	_EXDBUI_C

#include "exos.h"
#include "stdtypes.h"	
#include "exword.h"
#include "exwords.h"
#include "exdbgrsy.h"
#include "exdbstre.h"
#include "exdbsymb.h"
#include "exdbui.h"
#include "exdbtrap.h"
#include "exdbwtch.h"
#include "exdbmimo.h"
#include "exdbctrl.h"
#include "exdbobs.h"
#include "exdbfkey.h"
#include "exdbfind.h"
#include "exdbword.h"
#include "exproto1.h"

#ifdef	ABALX11
extern	int	exa_is_X11;
#endif

static EXAWORD		BlockOffset;
static EXAWORD		DebugLevel=0;
static EXAWORD		CorresFile=0;
static EXAWORD		BlockType;
static EXAWORD		BlockIdentity;
static EXABYTE		CommandBuffer[256];
#ifdef WIN1632
static CORRESPTR	ZoomLine[128];
#else
static CORRESPTR	ZoomLine[64];
#endif

EXTERN	EXABYTE	askbuf[];
EXTERN	EXAWORD	brayk;
EXTERN	EXAWORD	TabSize;
EXTERN	EXAWORD	ScreenLin;
EXTERN	EXAWORD	ScreenCol;

#ifndef UNIX
EXAWORD	display_symbols( EXAWORD, EXAWORD, SYMBOLPTR);
EXAWORD	mouse_or_keyboard( VOID );
EXAWORD	checkpiege( EXAWORD, EXAWORD, EXAWORD );
EXAWORD	varmod( BPTR, EXAWORD );
EXAWORD	is_traced_region( EXAWORD, EXAWORD, EXAWORD );
EXAWORD	zoom_symbol( SYMBOLPTR );
EXAWORD	systeme(BPTR);
VOID	show_zoom_switch(VOID);
VOID	show_break_switch(VOID);
VOID	show_hexa_switch(VOID);
VOID	show_screen_switch(VOID);
EXAWORD	inhibit_standard_errors(VOID);
#else
EXAWORD	inhibit_standard_errors();
EXAWORD	display_symbols();
EXAWORD	mouse_or_keyboard();
EXAWORD	checkpiege();
EXAWORD	varmod();
EXAWORD	is_traced_region();
EXAWORD	zoom_symbol();
EXAWORD	systeme();
VOID	show_zoom_switch();
VOID	show_break_switch();
VOID	show_hexa_switch();
VOID	show_screen_switch();
#endif

/*	---------	-------		-----------------	*/
/*	E X A D B	U S E R   	I N T E R F A C E	*/
/*	---------	-------		-----------------	*/

#define _MUI_
EXAWORD fsame = 0;
CORRESPTR kinfos = (CORRESPTR)0;

#ifdef _MUI_
#ifndef UNIX
EXAWORD display_correspondances(CORRESPTR,EXAWORD);
CORRESPTR get_next_line(CORRESPTR);
CORRESPTR get_prev_line(CORRESPTR);
VOID draw_correspondance_page(EXAWORD,EXAWORD,EXAWORD,EXAWORD,CORRESPTR);
EXAWORD correspondance_item(EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD,CORRESPTR);
EXAWORD show_correspondance(EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD,CORRESPTR);
VOID correspondance_header(EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
VOID draw_empty_box(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
#else
EXAWORD display_correspondances(CORRESPTR,EXAWORD);
CORRESPTR get_next_line();
CORRESPTR get_prev_line();
VOID draw_correspondance_page();
EXAWORD correspondance_item();
EXAWORD show_correspondance();
VOID correspondance_header();
VOID draw_empty_box();
#endif
#endif

#ifdef	MODEL_DBGT
EXAWORD	TCASMFLAG=FAUX;
#endif

VOID	symbolic_atribut( natb )
EXAWORD	natb;
{
	if ( conf(14) == 0 )
		db_xatb(natb);
	else	list_colours(natb);
	return;
}

VOID		symbol_atribut( natb, lsymb )
EXAWORD		natb;
SYMBOLPTR	lsymb;
{
	if (( lsymb == (SYMBOLPTR) 0 )
	||  ( use_window_coordinates() == 0 ))
		symbolic_atribut( natb );	
	else if ( conf(14) == 0 )
		db_xatb(natb);
	else	{
		if ( exa_is_X11 < 2 ) {
			if ( natb == 0 ) {
				db_foregr( window_fcoord( lsymb->type ) );
				db_backgr( window_bcoord( lsymb->type ) );
				}
			else	{
				db_foregr( window_bcoord( lsymb->type ) );
				db_backgr( window_fcoord( lsymb->type ) );
				}
			}
		else	{
			if ( natb == 0 ) {
				db_foregr( 4 );
				db_backgr( 7 );
				}
			else	{
				db_foregr( 1 );
				db_backgr( 7 );
				}
			}

		}
	return;
}

#ifdef	MODEL_DBGT
VOID	announce( msg )
BPTR	msg;
{
	x_cprintf((BPTR) "ANNOUNCE:" );
	x_cprintf((BPTR) msg );
	x_getch();
	x_cprintf((BPTR) "\r\n");
	return;
}
#endif

VOID	set_mouse_status( level )
EXAWORD	level;
{
	if ( level == 0)
		inhibit_mimo();
	else	activate_mimo();
	return;
}

VOID	reset_mouse_context( mode )
EXAWORD	mode;
{
	DbMouse.top_column = 0;
	DbMouse.top_line   = 0;
	DbMouse.columns    = 0;
	DbMouse.lines  	   = 0;
	DbMouse.position   = 0;
	DbMouse.clicktype  = 0;
	DbMouse.mode	   = mode;
}

EXAWORD	current_mouse_click()
{
	switch ( DbMouse.clicktype ) {
		case	0 		:	return( 0 );
		case MIMO_CLICK		:	return( 0 );
		case MIMO_DOUBLE_CLICK	:	return( 2 );
		default			:	return( 0 );
		}
}

VOID	set_mouse_control(topcol,toplin,nbcol,nblin )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
EXAWORD	nblin;
{
	EXAWORD	previous=DbMouse.mode;

	if ( mouse_index < MICE ) {

		mouse_index++;
		reset_mouse_context(2);

		if ( previous == 0 )
			set_mouse_status(2);

		DbMouse.top_column  = topcol;
		DbMouse.top_line    = toplin;
		DbMouse.columns     = nbcol;
		DbMouse.lines       = nblin;
		DbMouse.position    = 0;
		}
	return;
		
}

VOID	pop_mouse()
{
	EXAWORD	previous=DbMouse.mode;
	if ( mouse_index > 0 ) {
		mouse_index--;
		if ((previous != 0 )
		&&  (DbMouse.mode == 0)
		&&  (mouse_index  == 0))
			set_mouse_status(0);
		}
	return;
}

VOID	initialise_mouse_manager()
{
	mouse_index = 0;
	reset_mouse_context(0);
	return;
}


VOID	standard_draw_box( tc, tl, nc, nl )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	nc;
EXAWORD	nl;
{
	EXAWORD	c,l;


	pos( tl, tc );

	x_putch( GRSYM_DA ); 
	for ( c=0; c < nc; c++ ) 
		x_putch( GRSYM_C4);
	x_putch( GRSYM_BF );

	for ( l = 1; l <= nl; l++ ) {
		pos( tl+l, tc);
		x_putch( GRSYM_B3 ); 
		for ( c=0; c < nc; c++ ) 
			x_putch( 0x0020);
		x_putch( GRSYM_B3 );
		}

	pos( tl+l, tc );
	x_putch( GRSYM_C0 ); 
	for ( c=0; c < nc; c++ ) 
		x_putch( GRSYM_C4);
	x_putch( GRSYM_D9 );

	x_bflush();
	return;
}	

VOID	draw_box( tc, tl, nc, nl )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	nc;
EXAWORD	nl;
{
	x_bstart(); 
	symbolic_atribut(0);
	standard_draw_box( tc,tl, nc, nl );
	return;
}

VOID	mouse_box( tc, tl, nc, nl )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	nc;
EXAWORD	nl;
{
	draw_box( tc, tl, nc, nl );
	set_mouse_control( tc, tl, nc, nl );
	return;
}


VOID	mouse_title_box( tc, tl, nc, nl, msg )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	nc;
EXAWORD	nl;
BPTR	msg;
{
	x_bstart(); 
	standard_draw_box( tc, tl, nc, nl );
	set_mouse_control( tc, tl, nc, nl );
	pos( tl, tc+2 ); 
	x_cprintf( (BPTR) msg );
	return;
}

VOID	display_message_zone()
{
	symbolic_atribut( 1 );
	centered_string(22,4,38,(BPTR) DebugSymbols->MessageZone );
	symbolic_atribut( 0 );
	return;
}

BPTR	interface_message( EXAWORD );
BPTR	interface_msg( EXAWORD );

VOID	display_operation_msg( mptr )
BPTR	mptr;
{
	symbolic_atribut(1);
	centered_string(24,2,34,(BPTR) mptr );
	symbolic_atribut( 0 );
	return;
}

EXAWORD	LastOpMode;

VOID	display_operation_mode( opmode )
EXAWORD	opmode;
{
	if ( opmode == MOINS_UN )
		opmode = LastOpMode;
	else	LastOpMode = opmode;
	switch ( opmode ) {
		case	0 :
			display_operation_msg((BPTR) interface_message(1) );
			break;
		case	1 : 
			display_operation_msg((BPTR) interface_message(2) );
			break;
		case	2 :
			display_operation_msg((BPTR) interface_message(3) );
			break;
		case	3 :
			display_operation_msg((BPTR) interface_message(4) );
			break;
		case	4 :
			display_operation_msg((BPTR) interface_message(71) );
			break;
		case	5 :
			display_operation_msg((BPTR) "Trace is Active" );
			break;
			
		}
	return;
}

VOID	standard_message( mptr )
BPTR	mptr;
{
	EXAWORD	n;
	for ( n=0; n < 63; n++)
		if ((DebugSymbols->MessageZone[n] = *(mptr++) ) == 0)
			break;
	display_message_zone();
	return;
}

VOID	standard_error( error_msg )
BPTR	error_msg;
{
	EXAWORD	c;
#ifdef	VERSION666
	if ( inhibit_standard_errors() )
		return;
#endif
	standard_message( (BPTR) error_msg );
	while ( 1 ) {
		if (((c = mouse_or_keyboard()) == 0x001B) 
		||  ( c == CTRL_M )
		||  ( c == CTRL_D ))
			break;
		}
	return;
}

extern	BPTR fdex;
extern	BPTR TcodeSegment;

VOID	standard_errors( error_value )
EXAWORD	error_value;
{
	BPTR	mptr=(BPTR) askbuf;
	exadb_strcpy((BPTR) mptr, (BPTR) interface_message(5) );
	exadb_strcat((BPTR) mptr, (BPTR) " ( ");
	exadb_itoa((BPTR) (mptr + exadb_strlen((BPTR) askbuf)), error_value);
	exadb_strcat((BPTR) mptr, (BPTR) " , ");
	exadb_itoa((BPTR) (mptr + exadb_strlen((BPTR) askbuf)), fdex - TcodeSegment );
	exadb_strcat((BPTR) mptr, (BPTR) " )");
	standard_error((BPTR) mptr );
	return;
}


EXAWORD	standard_validation( mptr )
BPTR	mptr;
{
	EXAWORD	c;
	standard_message((BPTR) mptr );
	while(1) {
		if (((c = mouse_or_keyboard()) == 0x001B) 
		||  ( c == CTRL_M )
		||  ( c == CTRL_D ))
			break;
		}
	reset_message_zone();
	if ( c == 0x001B )
		return(0);
	else	return(1);
}

EXAWORD	standard_exit_check()
{
	if ( standard_validation((BPTR) interface_message(6)) )
		return(0);
	else	return( 1 );
}


VOID	centered_string( tc, tl, nc, msg )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	nc;
BPTR	msg;
{
	EXAWORD	prepadd,width,postpadd;

	if ((width = exadb_strlen( (BPTR) msg )) >= nc) {
		right_string( tc,tl, nc, msg );
		}
	else	{
		prepadd  = ((nc - width)/2);
		postpadd = ((nc - width) - prepadd);
		x_bstart();
		pos( tl, tc );
		draw_space( prepadd );
		while ( *msg )
			x_putch( *(msg++) );
		draw_space(postpadd);
		x_bflush();
		}
	return;
}

#ifdef	MODEL_DBGT
VOID	message_box( tc, tl, nc, nl, msg )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	nc;
EXAWORD	nl;
BPTR	msg;
{
	draw_box( tc, tl, nc, nl );
	centered_string( tc+1,tl+1,nc,msg );
	return;
}
#endif

VOID	view_help_screen(mode)
EXAWORD	mode;
{
	EXAWORD	ctrlcode;
	EXAWORD	id;
	EXAWORD	indent;
	draw_box( 2,6, 76, 13 );
	
	//#BG 31/10/19 cf exadb21x.h
	for ( ctrlcode = 0; ctrlcode < 26; ctrlcode++ ) {
		pos( 7+(ctrlcode%13),4+((ctrlcode/13)*36));
		x_cprintf((BPTR) "Ctrl ");
		x_putch((0x0041+ctrlcode));
		x_cprintf((BPTR) " : ");
		switch ( (ctrlcode+1) ) {
			case CTRL_A : indent = 9; id = 13; break;
			case CTRL_B : indent = 9; id = 14; break;
			case CTRL_C : indent = 9; id = 15; break;
			case CTRL_D : indent = 0; id =116; break;	// Blanc
			case CTRL_E : indent = 9; id = 17; break;
			case CTRL_F : indent = 9; id = 18; break;
			case CTRL_G : indent = 0; id =128; break;
			case CTRL_H : indent = 9; id = 20; break;
			case CTRL_I : indent = 0; id =135; break;
			case CTRL_J : indent = 0; id =146; break;
			case CTRL_K : indent = 9; id = 23; break;
			case CTRL_L : indent = 9; id = 25; break;
//#BG 31/10/19			case CTRL_M : indent = 0; id =116; break;	// Blanc
			case CTRL_M : indent = 9; id = 32; break;
			case CTRL_N : indent = 0; id =147; break;
			case CTRL_O : indent = 0; id =134; break;
			case CTRL_P : indent = 0; id =130; break;
			case CTRL_Q : indent = 0; id =133; break;
			case CTRL_R : indent = 9; id = 27; break;
			case CTRL_S : indent = 0; id =131; break;
			case CTRL_T : indent = 0; id =175; break;
			case CTRL_U : indent = 0; id =100; break;
			case CTRL_V : indent = 0; id =129; break;
			case CTRL_W : indent = 9; id = 29; break;
			case CTRL_X : indent = 9; id = 30; break;
			case CTRL_Y : indent =31; id = 36; break;
//#BG 31/10/19			case CTRL_Z : indent = 9; id = 32; break;
			case CTRL_Z : indent = 9; id = 29; break;
			default     : continue;
			}
		left_string(13+((ctrlcode/13)*36),7+(ctrlcode%13), 25, (BPTR) ( interface_msg(id) + indent) );
		}
	(VOID) mouse_or_keyboard();
	return;
}

#ifndef _MUI_
VOID	show_zoom_switch()
{
	EXAWORD	col63;
	col63 = ScreenCol-17;
	WindowOff();
	symbolic_atribut(2);
	switch ( DebugSymbols->zoom_status ) {
		case 0 :
		case 1 : centered_string(col63,4, 8, (BPTR) interface_message(7));
			 break;
		case 2 : centered_string(col63,4, 8, (BPTR) interface_message(8));
			 break;
#ifdef	MODEL_DBGT
		case 3 : centered_string(col63,4, 8, (BPTR) "ZOOM:TCO" );
			 break;
		case 4 : centered_string(col63,4, 8, (BPTR) "ZOOM:TCI" );
			 break;
#endif
		}
	symbolic_atribut(0);
	x_putch(' ');
	WindowOn();
	return;
}
#endif

VOID	alter_zoom_switch()
{
	DebugSymbols->zoom_status++;
#ifndef	MODEL_DBGT
	if ( DebugSymbols->zoom_status > 2 )
		DebugSymbols->zoom_status = 0;
#else
	if ( DebugSymbols->zoom_status > 4 )
		DebugSymbols->zoom_status = 0;
#endif
	show_zoom_switch();
}
EXAWORD	display_integer( wv )
EXAWORD	wv;
{
	EXABYTE	buffer[16];
	exadb_itoa( (BPTR) buffer, wv );
	x_cprintf((BPTR) buffer );
	return( exadb_strlen( (BPTR) buffer ) );
}

EXAWORD	display_menu(topcol, toplin, nombre,msg1, msg2, msg3, msg4, msg5, msg6, msg7, msg8, msg9)
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nombre;
BPTR	msg1;
BPTR	msg2;
BPTR	msg3;
BPTR	msg4;
BPTR	msg5;
BPTR	msg6;
BPTR	msg7;
BPTR	msg8;
BPTR	msg9;
{
	EXAWORD	c;
	EXAWORD	maxmen=0;
	BPTR	texte[10];
	EXAWORD	width=0;
	EXAWORD	hold_nombre;

	if (nombre >= 1)  
		texte[maxmen++] = msg1;
	if ( nombre >= 2 )
		texte[maxmen++] = msg2;
	if ( nombre >= 3 )
		texte[maxmen++] = msg3;
	if ( nombre >= 4 )
		texte[maxmen++] = msg4;
	if ( nombre >= 5 )
		texte[maxmen++] = msg5;
	if ( nombre >= 6 )
		texte[maxmen++] = msg6;
	if ( nombre >= 7 )
		texte[maxmen++] = msg7;
	if ( nombre >= 8 )
		texte[maxmen++] = msg8;
	if ( nombre >= 9 )
		texte[maxmen++] = msg9;
	texte[maxmen] = (BPTR) 0;

	for ( nombre=0; nombre < maxmen; nombre++ )
		if ((c = exadb_strlen( texte[nombre] )) > width)
			width = c;
	
	if ( topcol == 0 )
		topcol = ((80 - (width+6))/2);
	if ( toplin == 0 )
		toplin = ((24 - (maxmen+2))/2);

	mouse_box( topcol, toplin, width+6, maxmen);
	
	width += 4;
	for ( nombre = 0; nombre < maxmen; nombre++ )
		centered_string(topcol+2,toplin+nombre+1,width, texte[nombre]);
	nombre = 0;
	while ( 1 ) {
		symbolic_atribut(2);
		centered_string(topcol+2,toplin+nombre+1,width, texte[nombre]);
		symbolic_atribut(0);		
		c = mouse_or_keyboard();
		centered_string(topcol+2,toplin+nombre+1,width, texte[nombre]);
		switch ( c ) {
			case CTRL_Z :
				alter_zoom_switch();
				continue;

			case CTRL_D :
				if ( DbMouse.position == 0 )
					continue;
				nombre = (DbMouse.position-1);
			case CTRL_M : 	
				symbolic_atribut(2);
				centered_string(topcol+2,toplin+nombre+1,width, texte[nombre]);
				symbolic_atribut(0);
				pop_mouse();
				return( nombre );
			case 0x001B : 	
				pop_mouse();
				return( MOINS_UN );
			case CTRL_U	:
				continue;
			case CTRL_N :
				continue;
			case 0x0020 :
			case CTRL_E : 	nombre++;
					if ( nombre >= maxmen )
						nombre = 0;
					break;
			case CTRL_K :	if ( nombre == 0 )
						nombre = maxmen;
					nombre--;
					break;
			default	    :
					hold_nombre = nombre;
					for ( nombre = 0; nombre < maxmen; nombre++ )
	 					if ((c & 0x005F) == ( *( texte[nombre] ) & 0x005F ))
							break;
					if ( nombre < maxmen ) {
						symbolic_atribut(2);
						centered_string(topcol+2,toplin+nombre+1,width, texte[nombre]);
						symbolic_atribut(0);
						pop_mouse();
						return( nombre );
						}
					nombre = hold_nombre;
			}
		}

}

EXAWORD	is_trapped_symbol( xsymb )
SYMBOLPTR	xsymb;
{
#ifndef	STD_C_CALLS	
	if ( xsymb != (SYMBOLPTR) 0 ) {
		switch ( xsymb->type ) {
			case PNAME_SYMBOL	:
				return(checkpiege((xsymb->number / (8*WORDSIZE)) ,0, 2 ));

			case SNAME_SYMBOL	:
				return(checkpiege(xsymb->number ,0, 0 ));
	
			case VNAME_SYMBOL	:
				return(check_watch(xsymb->number,(BPTR) xsymb->name));
			}
		}
#endif
	return( 0 );

}

VOID	push_view()
{
	x_putch(0x001B);
	x_putch('>');
	x_bflush();
}

VOID	pop_view()
{
	x_putch(0x001B);
	x_putch('<');
	x_bflush();
}

VOID	standard_text_editor( txtptr )
BPTR	txtptr;
{
	EXABYTE	buffer[256];
#ifdef	DOS
#ifdef	ABAL64
	(VOID) execsys( (BPTR) exadb_strcat((BPTR) exadb_strcpy((BPTR) buffer, (BPTR) "aed64 " ),txtptr ) );
#else
	(VOID) execsys( (BPTR) exadb_strcat((BPTR) exadb_strcpy((BPTR) buffer, (BPTR) "aed " ),txtptr ) );
#endif
#else
#ifdef	ABAL64
	(VOID) systeme( (BPTR) exadb_strcat((BPTR) exadb_strcpy((BPTR) buffer, (BPTR) "aed64 " ),txtptr ) );
#else
	(VOID) systeme( (BPTR) exadb_strcat((BPTR) exadb_strcpy((BPTR) buffer, (BPTR) "aed " ),txtptr ) );
#endif
#endif
}

VOID	display_hexint( wv )
EXAWORD	wv;
{
	EXABYTE	buffer[16];
	exadb_itoh((BPTR) buffer, wv );
	x_cprintf((BPTR) buffer );
	return;
}

VOID	display_hexbyte( wv )
EXAWORD	wv;
{
	EXABYTE	buffer[16];
	exadb_itoh((BPTR) buffer, wv );
	x_putch( buffer[2] );
	x_putch( buffer[3] );
	return;
}

EXAWORD	display_variable_declaration( nomptr, identity )
BPTR	nomptr;
EXAWORD	identity;
{
	EXAWORD		offset;
	EXAWORD		secteur;
	EXAWORD		type;
	EXAWORD		base;
	SYMBOLPTR	bsymb;
	EXAWORD		result=0; 
#ifndef	STD_C_CALLS
	EXABYTE		buffer[64];
#endif
	EXAWORD		holdsect;	

	offset = (identity & TOGLOBAL);

	if (( identity == 0 ) || ( identity == EXDB_FFFF )) {
		Verbose((BPTR) interface_message(9) );
		return(0);
		}

	if (!(secteur = ( DebugSymbols->ldt_sector != 0  ? DebugSymbols->ldt_sector : TcGetWord((BPTR) & DebugSymbols->AtHeader[(3 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX] )))) {
		Verbose((BPTR) interface_message(9) );
		return(0);
		}
	else if (secteur == MOINS_UN) {
		Verbose((BPTR) interface_message(9) );
		return(0);
		}
#ifdef	VERSION666 
	else if ( stream_seek( _TCODE_STREAM, (secteur+((offset & 0x7FFFFF00) >> 8)), (offset & 0x00FF) )) {
#else
	else if ( stream_seek( _TCODE_STREAM, (secteur+((offset & 0x7F00) >> 8)), (offset & 0x00FF) )) {
#endif
		draw_box( 1, 19, (ScreenCol-2), 1 );
		type = stream_getw( _TCODE_STREAM );
		x_bstart(); 
		symbolic_atribut(1);
		pos( 20, 3 );

		/* Display Memory Base Type */
		/* ------------------------ */
		if ( identity & ISLOCAL )
			x_cprintf((BPTR) "Local ");
		else	x_cprintf((BPTR) "Global ");
		x_cprintf((BPTR) "Field=" );
		if (type & 0xFF00) {
			if ( type & 0x8000 ) {
				if (type & 0x2000) {
					base = stream_getw(_TCODE_STREAM);
					x_putch( '[' );
					if ((bsymb = locate_variable_number( base )) != (SYMBOLPTR) 0)
						x_cprintf((BPTR) bsymb->name );
#ifdef	MODEL_DBGT
					x_putch(':');
					display_hexint( base );					
#endif
					x_putch( ']' );
					}										
				else	x_putch('M');
				}
			else if (type & 0x4000)
				x_putch( 'E' );
			else display_integer( ((type & 0x3F00) >> 8) );	
			}
		else	x_putch( 'M' );

		/* Display Memory Offset from base */
		/* ------------------------------- */
		x_putch( ':' );
		display_hexint( stream_getw( _TCODE_STREAM ) );
		if ((!(type & 0x8000))
		&&  ( type & 0x7F00))
			display_hexint( stream_getw( _TCODE_STREAM ) );

		/* Display Declaration information */
		/* ------------------------------- */
		if ( type & 0x0008 )
			x_cprintf((BPTR)" Arg " );
		if ((type & 0x9000) == 0x9000)
			x_cprintf((BPTR)" Ptr ");
		else if (!( type & 0x0008 ))
			x_cprintf((BPTR)" Dcl ");
		x_cprintf((BPTR) nomptr );
#ifdef	MODEL_DBGT
		x_putch(':');
		display_hexint( base );					
#endif
		switch ((type & 0x0003)) {
			case 0 : x_putch('#'); break;
			case 1 : x_putch('%'); break;
			case 3 : x_putch('$'); 
			case 2 : x_putch('='); 
				 display_integer( stream_getw(_TCODE_STREAM) );
			}
		if (type & 0x0040) {
			x_putch( '(' );
			 display_integer( stream_getw(_TCODE_STREAM) );
			if ( type & 0x0020 ) {
				x_putch( ',' );
				 display_integer( stream_getw(_TCODE_STREAM) );
				}		
			x_putch( ')' );
			}
		symbolic_atribut(0);
		x_bflush();
	holdsect = DebugSymbols->ldt_sector;
#ifndef	STD_C_CALLS
		switch ( DebugSymbols->display_mode ) {
			case	1	:	/* PRINT:ASK */
				exadb_strcpy( (BPTR) buffer, (BPTR) " "); 
				exadb_strcat( (BPTR) buffer, (BPTR) nomptr );
				result = varmod((BPTR) buffer, 3); 
				break;
			case	0	:	/* MEMORY */
				exadb_strcpy( (BPTR) buffer, (BPTR) "H "); 
				exadb_strcat( (BPTR) buffer, (BPTR) nomptr );
				result = varmod((BPTR) buffer, 0); 
				break;
			}
		symbolic_atribut(0);
#endif
		}
	DebugSymbols->ldt_sector = holdsect;
	return(result);

}

VOID	display_local_variables( lsymb )
SYMBOLPTR	lsymb;
{
	SYMBOLPTR	LocalList=(SYMBOLPTR) 0;

	if (( lsymb != (SYMBOLPTR) 0 )
	&&  (( LocalList = load_local_variables( lsymb )) != (SYMBOLPTR) 0)) {
		(VOID) display_symbols(50,6, LocalList );
		liberate_symbol_list( LocalList );
		}
	return;
}

EXAWORD	load_correspondance_line()
{
	EXAWORD	indent=0;
	EXAWORD	tabulation=TabSize;
	EXAWORD	c=0;

	while (1) {
		if ((c = stream_getc( _WORK_STREAM )) == MOINS_UN)
			break;
		switch ( c ) {
			case 0	      :
			case CTRL_Z   :
			case CTRL_J   : break;
			case CTRL_M   : continue;
			case CTRL_I   :
				do	{
					askbuf[(indent++)] = ' ';
					}
				while ((indent % tabulation) != 0);
				continue;
			default	      :
				askbuf[(indent++)] = c;
				continue;
			}
		break;
		}
	askbuf[(indent)]=0;
	return( indent );
}

VOID	edit_correspondance_file( linfos )
CORRESPTR	linfos;
{
	SYMBOLPTR	fsymb;
	EXAWORD		line_length;
	EXAWORD		line_count;
	EXAWORD		tl=6;
	EXAWORD		tc=2;
	EXAWORD		nl=0;
	EXAWORD		c;
	while ( 1 ) {
	
		if ((linfos != (CORRESPTR) 0)
		&&  ((fsymb = locate_source_number( linfos->file_number )) != (SYMBOLPTR) 0)
		&&  ( stream_position( _WORK_STREAM, (BPTR) fsymb->name, (EXALONG) linfos->file_offset, (fsymb->number+1), linfos->nature ))) {
			while (1) {
				if ((line_length = load_correspondance_line()) <= 76)
					line_count  = 1;
				else	line_count  = ((line_length / 76) + 1);
				draw_box( tc=2, tl=6, 76, line_count );					
				tl++; tc++;
				for ( nl = 0; nl < line_length; nl++ ) {
					if (( nl % 76 ) == 0) 
						pos( (tl++), tc );
					x_putch( askbuf[nl] );					
					}

				switch ((c = mouse_or_keyboard())) {

					case 27 : return;

					case CTRL_M :
						stream_close( _WORK_STREAM );	
						standard_text_editor( fsymb->name );
						return;

					case CTRL_K :
						break;

					case CTRL_C :
						if ( linfos->next != (CORRESPTR) 0 )
							linfos = linfos->next;
						break;

					case CTRL_E :
						continue;

					case CTRL_R :
						if ( linfos->previous != (CORRESPTR) 0 )
							linfos = linfos->previous;
						break;
					}
				break;
				}
			}
		else	break;
		}
	return;
}

EXAWORD	is_trace_region( linfos )
CORRESPTR	linfos;
{
	return( is_traced_region((BlockType == 0 ? 'S': 'P'), BlockIdentity, linfos->tcode_offset ) );
}

EXAWORD	is_break_point( linfos )
CORRESPTR	linfos;
{
	EXAWORD	blockid;
#ifndef	STD_C_CALLS
	if ( BlockType == 0 )
		blockid = BlockIdentity;
	else	blockid = (BlockIdentity / (8*WORDSIZE));
	return(checkpiege( blockid,linfos->tcode_offset, (BlockType ? 0x0002 : 0) ));
#else
	return( 0 );
#endif
}

#ifndef _MUI_
static	EXAWORD	correspondance_nature( linfos, fsymb )
CORRESPTR	linfos;
SYMBOLPTR	fsymb;
{
	EXAWORD	xnc=0;
	if ( CorresFile ) {
		xnc = exadb_strlen( fsymb->name );
		x_cprintf((BPTR) fsymb->name);
		}
	x_putch('(');

	if ( CorresFile ) {
		xnc += display_integer( (EXAWORD) linfos->file_offset );
		x_putch(',');
		}
	xnc += display_integer( linfos->level );
	x_putch(')');
	if ( CorresFile )
		xnc += 3;
	else	xnc += 2;
	return( xnc );
}
#endif

static	EXAWORD	check_finished( linfos, finish )
CORRESPTR	linfos;
EXALONG		finish;
{
	if ( linfos->nature ) {
		if ( stream_line_tell( _WORK_STREAM ) >= finish )
			return( VRAI );
		else	return( FAUX );
		}
	else if ( stream_tell( _WORK_STREAM ) >= finish )
		return( VRAI );
	else	return( FAUX );

}

#ifndef _MUI_
/*	-------------------	*/
/*	correspondance_item	*/
/*	-------------------	*/
EXAWORD	correspondance_item( topcol, toplin, nbcol, nbl, lno, linfos)
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
EXAWORD		nbl;
EXAWORD		lno;
CORRESPTR	linfos;
{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	EXAWORD		c;
	EXAWORD		nbc;
	EXAWORD		xnc=0;
	EXAWORD		tabulation=TabSize;
	EXAWORD		status=1;
	EXAWORD		n;
	EXALONG		finish=-1L;

	if (( linfos != (CORRESPTR) 0)
	&&  ((fsymb = locate_source_number( linfos->file_number )) != (SYMBOLPTR) 0)
	&&  ( stream_position( _WORK_STREAM, (BPTR) fsymb->name, (EXALONG) linfos->file_offset, (fsymb->number+1), linfos->nature ))) 
	{
		ZoomLine[lno] = linfos;
		x_bstart();
		nbcol += (topcol+1);
		pos( (toplin+lno),(nbc = topcol));
		switch ((c = is_break_point( linfos ))) 
		{
			case 0 : x_putch(' '); break;
			case 1 :
			case 2 : x_putch((c+0x0040)); break;
		}
		if ((c = is_trace_region( linfos )) != 0)
			x_putch('T');
		else	x_putch(' ');

		display_hexint( linfos->tcode_offset );
		if (( linfos->next != (CORRESPTR) 0)
		&&  ( linfos->next->file_number == linfos->file_number ))
			finish = linfos->next->file_offset;
		x_putch(':'); 
		if ( linfos->nature )
			xnc = correspondance_nature( linfos,fsymb );
		else	xnc = 0;
		x_putch(' ');
		nbc += (9 + xnc );
		while ( 1 ) 
		{
			if ((c = stream_getc(_WORK_STREAM)) == EXDB_FFFF)
				c = 0x001A;
			switch (c) 
			{
				case '\r' : 
					continue;
				case '\n' : 
					if (status)
						for ( ; nbc < nbcol; nbc++ )
							x_putch( ' ' );
					status = 1;
					lno++;
					if ( check_finished( linfos, finish ) ) 
					{
						x_bflush();
						return( lno );
					}
					if ( lno < nbl ) 
					{
						pos( toplin+lno,(nbc = topcol) );
						for ( c = 0; c < 8; c++,nbc++ )
							x_putch(' ');
						nbc++;
						continue;
					}
				case 0x0000 :
				case 0x001A :
					x_bflush();
					return( lno );

 				case '\t' :
					do	
					{
						if ( nbc < nbcol ) 
						{
							x_putch(' ');
							nbc++;
						}
					}
					while ((nbc < nbcol) && ((nbc % tabulation) != 0));
					continue;
  
				case 0x000C :
				case 0x001C : 
					c = 0x0020;
				default :
					if ( DebugSymbols->zoom_status == 1 ) 
					{
						if ( nbc >= nbcol ) 
						{
							lno++;
							if ( check_finished( linfos, finish ) ) 
							{
								x_bflush();
								return( lno );
							}
							if ( lno < nbl ) 
							{
								pos( toplin+lno,(nbc = topcol) );
								for ( n = 0; n < 8; n++,nbc++ )
									x_putch(' ');
								nbc++;
							}
							else	
							{
								x_bflush();
								return( lno );
							}
						}
						x_putch( c );
						nbc++;
					}
					else	
					{
						if ((status) && ( nbc < nbcol )) 
						{
							x_putch( c );
							nbc++;
						}
						else	status = 0;
					}
				continue;
				}
			}	
		}
	return(lno);
	
}

#ifdef	MODEL_DBGT
EXTERN	BPTR	TcodeSegment;
EXAWORD		show_assembleur( mode, topcol, toplin, nbcol, nblin,lno, si )
EXAWORD		mode;
EXAWORD		toplin;
EXAWORD		topcol;
EXAWORD		nbcol;
EXAWORD		nblin;
EXAWORD		lno;
EXAWORD		si;
{
	EXAWORD	x;
	EXAWORD	holder=0x0056;
	EXAWORD	tcode=MOINS_UN;
	EXAWORD	seq_len=0;
	BPTR	sptr=TcodeSegment;

	symbolic_atribut(mode);
	InitLiner( ((toplin-(nblin/2)-1)),topcol,(toplin+(nblin/2)),nbcol+topcol);
	symbolic_atribut(mode);

	do	{

		/* Check validity of Tcode Pointer */
		/* ------------------------------- */
		if ( VerifPtr( (sptr + si) ) != 0 )
			break;

		/* Watch out for and Indicate Break Points */
		/* --------------------------------------- */
		if (((holder = *(sptr + si)) == 0x0056 )
		&&  ((tcode = real_tcode( si )) != MOINS_UN )) {
			*(sptr + si) = tcode;
			symbolic_atribut((mode=1));
			}

		seq_len = TcodeList( sptr , si , 0);

		/* Check for and Reposition Break Points */
		/* ------------------------------------- */
		if (( holder == 0x0056 ) && ( tcode != MOINS_UN ))
			*(sptr + si) = 0x0056;

		si += seq_len;


		if ( mode )
			symbolic_atribut((mode=0));
		lno++;
		if ( VerifPtr( (sptr + si) ) != 0 )
			break;

#ifdef	MERDE_ASM
		if ( *(sptr + si) & 0x0080 )
			break;
#endif
		}

	while (( seq_len != 0 )   && ( not_end_of_tc_window() ));

	if ( not_end_of_tc_window() )
		StreamPage();

	symbolic_atribut(0);
	return(lno);
}
#endif
#endif /* _MUI_*/

VOID	standard_integer( v )
EXAWORD	v;
{
	pos( 4, 32 ); display_integer( v ); x_getch();
}

#ifndef _MUI_
/*	------------------------	*/
/*	 display_correspondance 	*/
/*	------------------------	*/
VOID	display_correspondance( topcol, toplin, nbcol, nbl, linfos)
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
EXAWORD		nbl;
CORRESPTR	linfos;
{
	EXAWORD	lno=0;
	EXAWORD	c;

	for ( c = 0; c < nbl; c++ )
		ZoomLine[c] = (CORRESPTR) 0;

#ifdef	MODEL_DBGT
	if ( DebugSymbols->zoom_status == 3 ) 
	{
		if ( LastOpMode == 0 ) 
		{
			ZoomLine[0] = linfos;
			lno = show_assembleur( 2, (topcol+1), (toplin+1), nbcol, nbl, lno, linfos->tcode_offset );
			return;
		}
		else	DebugSymbols->zoom_status = 4;
	}
#endif

	symbolic_atribut(2);

	while ( linfos != (CORRESPTR) 0 ) 
	{

		if ( linfos->level > DebugLevel ) 
		{
			linfos = linfos->next;
			continue;
		}

#ifdef	MODEL_DBGT
		if ( DebugSymbols->zoom_status > 2 ) 
		{
			ZoomLine[0] = linfos;
			lno = show_assembleur( 2, (topcol+1), (toplin+1), nbcol, nbl, lno, linfos->tcode_offset );
		}
		else
#endif
		 	lno = correspondance_item((topcol),(toplin+1),nbcol,nbl,lno,linfos);
		symbolic_atribut(0);
		if (( lno == 0 ) || ( lno == nbl ))
			break;
		do	
		{
			if ((linfos = linfos->next) == (CORRESPTR) 0)
				break;
		}
		while ((linfos->file_offset == linfos->previous->file_offset)
		&&     (linfos->file_number == linfos->previous->file_number));
	}
	symbolic_atribut(0);
	if ( lno != 0 )
		for ( ; lno < nbl; lno++ )
			left_string((topcol),(toplin+1+lno),nbcol,(BPTR) " ");

	return;
}
#endif /* _MUI_ */

EXAWORD	set_break_point(type, linfos )
EXAWORD		type;
CORRESPTR	linfos;
{
	EXAWORD	blockid;

	if ( BlockType == 0 )
		blockid = BlockIdentity;
	else	blockid = (BlockIdentity / (8*WORDSIZE));

#ifndef	STD_C_CALLS
	if ( type )
		posepiege( blockid, linfos->tcode_offset, BlockType, (type & 1 ? 1 : 0),(BPTR) 0);
	else	wipepiege( blockid, linfos->tcode_offset, (BlockType ? 0x0002 : 0),(BPTR) 0);
#endif
	return( VRAI );
}


#ifndef _MUI_
EXAWORD		show_correspondance( mode, topcol, toplin, item, nbcol, nblin, linfos )
EXAWORD		mode;
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		item;
EXAWORD		nbcol;
EXAWORD		nblin;
CORRESPTR	linfos;

{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	EXAWORD		c;
	EXAWORD		nbc;
	EXAWORD		xnc=0;
	EXAWORD		lno=0;
	EXAWORD		tabulation=TabSize;

#ifdef	MODEL_DBGT
	if ( TCASMFLAG ) {
		toplin += (item-1);
		(VOID) show_assembleur( mode, topcol, toplin , nbcol,nblin,1, linfos->tcode_offset );
		return(0);
		}
#endif
	if ( DebugSymbols->zoom_status < 2) {
		if ( linfos->level > DebugLevel )
			return( 32 );
		symbolic_atribut(mode);
		display_correspondance((topcol), (toplin-1),nbcol, nblin,linfos);
		return(0);
		}

	toplin += (item-1);
	nblin = 1;

#ifdef	MODEL_DBGT
	if ( DebugSymbols->zoom_status == 3 ) {
		if ( LastOpMode == 0 ) {
			(VOID) show_assembleur( mode, topcol, toplin, nbcol, nblin,1, linfos->tcode_offset );
			return(0);
			}
		else	DebugSymbols->zoom_status = 1;
		}
#endif

	if (( linfos != (CORRESPTR) 0)
	&&  ((fsymb = locate_source_number( linfos->file_number )) != (SYMBOLPTR) 0)
	&&  ( stream_position( _WORK_STREAM, (BPTR) fsymb->name, (EXALONG) linfos->file_offset, (fsymb->number+1), linfos->nature ))) {
		x_bstart();
		pos((toplin++),topcol);
		symbolic_atribut(mode);
		switch ((c = is_break_point( linfos ))) {
			case 0 : x_putch(' '); break;
			case 1 :
			case 2 : x_putch((c+0x0040)); break;
			}
		if ((c = is_trace_region( linfos ))!= 0)
			x_putch('T');
		else	x_putch(' ');
		display_hexint( linfos->tcode_offset );
		x_putch(':');
		if ( linfos->nature )
			xnc = correspondance_nature( linfos, fsymb );
		else	xnc = 0;
		x_putch(' ' );
		nbc = (topcol = (8+xnc));
		while ( 1 ) {
			if ((c = stream_getc(_WORK_STREAM)) == EXDB_FFFF) 
				c = 0x001A;
			switch (c) {
				case 0x000D : continue;
				case 0x000A : 
					if (!(lno))
						for ( ; nbc < nbcol; nbc++ )
							x_putch( ' ' );
					lno++;
					if ( lno < nblin ) {
						symbolic_atribut(0);
						pos( (toplin++),(nbc = (topcol+8)) );
						continue;
						}
				case 0x0000 :
				case 0x001A :
					x_bflush();
					return(0);
 				case 0x0009 :
					do	{
						if ( nbc < nbcol ) {
							x_putch(' ');
							nbc++;
							}
						else	{
							lno++;
							break;
							}
						}
					while ((nbc < nbcol) && ((nbc % tabulation) != 0));
					continue;

				case 0x000C :
				case 0x001C : 
					c = 0x0020;
				default :
					if ( nbc < nbcol ) {
						x_putch( c );
						nbc++;
						}
					else	{
						lno++;
						if ( lno < nblin ) {
							symbolic_atribut(0);
							pos( (toplin++),(nbc =(topcol+8)) );
							}
						else	{
							x_bflush();
							return(0);
							}
						}
					continue;
				}
			}	
		}
	return(0);
}

	
VOID	draw_correspondance_page(topcol,toplin,nbcol,nblin,linfos )
EXAWORD		toplin;
EXAWORD		topcol;
EXAWORD		nbcol;
EXAWORD		nblin;
CORRESPTR	linfos;
{
	CORRESPTR	tinfos;
	EXAWORD		nb;
	EXAWORD		lno;
	EXAWORD		preline;

	if ( DebugSymbols->zoom_status < 2 )
		return;
#ifdef	MODEL_DBGT
	else if ( TCASMFLAG )
		return;
#endif
	preline = ((nblin/2)+1);

	/* Position to 8th item before current */
	/* ----------------------------------- */
	for ( tinfos = linfos,nb = 0;((tinfos->previous != (CORRESPTR) 0) && (nb < preline));nb++, tinfos = tinfos->previous );

	/* Display previous lines or space prefix */
	/* -------------------------------------- */
	lno = 1; 
	while ( lno < (preline+1) ) {
		if ( nb < preline ) {
			pos( (toplin+lno), (topcol+1) );	
			draw_space( nbcol );
			nb++;
			lno++;
			}
		else	{
			if ( tinfos->level <= DebugLevel ) {
				show_correspondance( 0, (topcol), (toplin+1),lno, nbcol, nblin, tinfos );
				lno++;
				}
			tinfos = tinfos->next;
			}		
		}

	while ( lno < (nblin+1) ) {
		if (( tinfos == (CORRESPTR) 0)
		|| (  tinfos->level > DebugLevel )) {				
			pos( (toplin+lno), (topcol) );	
			draw_space( nbcol );
			lno++;
			}
		else	{
			if ( tinfos->level <= DebugLevel ) {
				show_correspondance( 0, (topcol), (toplin+1),lno, nbcol, nblin, tinfos );
				lno++;
				}
			tinfos = tinfos->next;
			}		
		}
	return;
}
#endif /* _MUI_ */


VOID	procedure_parameter_type( ptype )
EXAWORD	ptype;
{
	if ( ptype & 0x0008 )
		x_putch( '&' );

	switch ( (ptype & 0x0003) ) {
		case 0 : x_putch( '#' ); break;
		case 1 : x_putch( '%' ); break;
		case 2 : x_putch( 'N' ); break;
		case 3 : x_putch( '$' ); break;
		}
	return;
}

VOID		output_procedure_signature( lsymb )
SYMBOLPTR	lsymb;
{
	EXAWORD	nbargs;
	BPTR	sptr;
	EXAWORD	retval;
	EXAWORD	type;

	if ( lsymb->name != (BPTR) 0 ) {
		x_cprintf( lsymb->name );
		x_putch( ' ' );
		}
	
	if ((sptr = lsymb->signature) == (BPTR) 0 )
		return;

	nbargs = *(sptr++); 
	nbargs += ( *(sptr++) << 8 );
	retval = *(sptr++); nbargs--;
	x_putch( '(' );
	while ( nbargs != 0 ) {
		procedure_parameter_type( *(sptr++) );

		nbargs--;
		if ( nbargs )
			x_putch( ',' );
		}

	x_putch( ')' );
	if ( retval & 0x0080 ) {
		x_putch( ' ' );
		x_putch( ':' );
		x_putch( ' ' );
		procedure_parameter_type( (retval & 0x000F) );
		}
	return;
}

VOID	code_block_identity( topcol, toplin )
EXAWORD	topcol;
EXAWORD	toplin;
{
	SYMBOLPTR	lsymb;

	x_bstart();
	pos( toplin, topcol+2 );
	symbolic_atribut(1);
	if ( BlockType ) {
		x_cprintf((BPTR) " Proc : ");
		if ((lsymb = locate_procedure_number( BlockIdentity )) != (SYMBOLPTR) 0 )
			output_procedure_signature( lsymb );
		else	x_cprintf((BPTR) get_procedure_name( BlockIdentity )); 
		}
	else	{
		x_cprintf((BPTR) " Segment : ");
		if (BlockIdentity >=0 && BlockIdentity <= 2048)
			x_cprintf((BPTR) get_segment_name(BlockIdentity));
		else
			display_integer( BlockIdentity );
		}
	x_putch(' ');
	symbolic_atribut(0);
	x_bflush();
}

#include "exdbfkey.c"	/* Function key manager */

#ifndef _MUI_
VOID	show_break_switch()
{
	WindowOff();
	symbolic_atribut(2);
	if ( brayk != 0 )
		centered_string( 3,4,  9, (BPTR) interface_message(24) );
	else	centered_string( 3,4,  9, (BPTR) interface_message(25) );
	symbolic_atribut(0);
	x_putch(' ');
	WindowOn();
	return;
}

VOID	show_hexa_switch()
{
	WindowOff();
	symbolic_atribut(2);
	switch ( DebugSymbols->display_mode ) {
		case 1 : centered_string(13,4, 6, (BPTR) interface_message(26) );
			 break;
		case 0 : centered_string(13,4, 6, (BPTR) interface_message(27) );
			 break;
		}
	symbolic_atribut(0);
	WindowOn();
	return;
}


VOID	show_screen_switch()
{
	WindowOff();
	symbolic_atribut(2);
	centered_string(ScreenCol-8,4, 7, (BPTR) interface_message(28) ); 
	symbolic_atribut(0);
	WindowOn();
	return;
}
#endif


VOID	alter_hexa_switch()
{
	if ( DebugSymbols->display_mode )
		DebugSymbols->display_mode = 0;
	else	DebugSymbols->display_mode = 1;
	show_hexa_switch();
}


VOID	alter_screen_switch()
{
	show_screen_switch();
}

VOID	alter_break_switch()
{
	if ( brayk != 0 )
		brayk = 0;
	else	brayk = 0x001B;
	show_break_switch();
}

VOID	show_debug_switchs()
{
	show_break_switch();
	show_hexa_switch();
	show_zoom_switch();
	show_screen_switch();
	return;
}

VOID	show_debug_level()
{
/*	symbolic_atribut(1);
	pos( 2, 24 );
	display_integer( DebugLevel );
	symbolic_atribut(0);
*/
	return;
}

#ifndef _MUI_
VOID	correspondance_header(topcol,toplin,nbcol,nblin,opmode)
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
EXAWORD	nblin;
EXAWORD	opmode;
{
	EXAWORD	c;
	EXAWORD	nbc;
	EXAWORD	zflag=0;
	EXAWORD	col60;
	col60 = (ScreenCol-20);
	symbolic_atribut(0);
	draw_box(1,1,(nbc=(ScreenCol-2)),3);
	pos( 1,20);  x_putch( GRSYM_C2 );
	if ( trace_is_active() )
		display_operation_mode(5);
	else	display_operation_mode(opmode);
	symbolic_atribut(2);
	centered_string( 3, 2, 16, (BPTR) interface_message(29) );
	symbolic_atribut(0); x_putch(' '); x_putch( GRSYM_B3 );
	pos( 2,col60+1 ); x_putch( GRSYM_B3 );   x_putch(' ');
	symbolic_atribut(2);
	centered_string( col60+3, 2, 16, (BPTR) interface_message(30) );
	symbolic_atribut(0);
	pos( 3, 1);  x_putch( GRSYM_C3 );
	for ( c=0; c < nbc; c++ ) 
		x_putch( GRSYM_C4);
	pos( 3,20);  x_putch( GRSYM_C5 );
	pos( 3,col60+1);  x_putch( GRSYM_C5 );

	pos( 4, 1);  x_putch( GRSYM_B3 );   x_putch(' ');
	pos( 4,19);  x_putch(' ');	  x_putch( GRSYM_B3 ); x_putch(' ');
	pos( 1,col60+1);  x_putch( GRSYM_C2 );
	pos( 4,col60);  x_putch(' ');	  x_putch( GRSYM_B3 ); x_putch(' ');
	pos( 3,ScreenCol);  x_putch( GRSYM_B4 );
	pos( 4,ScreenCol-1);  x_putch( ' ' );   	  x_putch( GRSYM_B3 );

	show_debug_switchs();
	show_debug_level();
	display_message_zone();
	reset_message_zone();

	pos( 5,20);  x_putch( GRSYM_C1 );
	pos( 5,col60+1);  x_putch( GRSYM_C1 );

	if ( zflag )
		left_string(topcol,(toplin+nblin+2),(nbcol+2),(BPTR) " ");

	code_block_identity(topcol,toplin);
	establish_function_keys(opmode);
	set_mouse_control( topcol, toplin, nbcol, nblin );
	return;
}
#endif

CORRESPTR	locate_tcode_offset( linfos, nombre )
CORRESPTR	linfos;
EXAWORD		nombre;
{
	while ( linfos != (CORRESPTR) 0) {
		if ( linfos->tcode_offset == nombre )
			break;
		else	linfos = linfos->next;
		}
	return( linfos );

}

#ifdef	MODEL_DBGT
EXAWORD	exadb_conv_htoi( hptr, l )
BPTR	hptr;
EXAWORD	l;
{
	EXAWORD	result=0;
	EXAWORD	c;
	while (( l != 0 ) && ((c = *(hptr++)) != 0)) {
		if (((c >= 'A') && (c <= 'F'))
		||  ((c >= 'a') && (c <= 'f')))
			result = ((result << 4) + (((c & 0x005F) - 'A') + 10));
		else if ((c >= '0') && (c <= '9'))
			result = ((result << 4) + (c - '0'));
		else if (( c == 'H' ) || ( c == 'h'))
			break;
		else if ( result != 0 )
			break;
		else if ((c != '/') && (c != 'x') && (c != 'X'))
			break;
		else	l--;
		}
	return( result );
}
#endif

EXAWORD	legal_symbol( c )
EXAWORD	c;
{
	EXAWORD	x;
	BPTR	sptr;

	if ((( c >= 'A' ) && ( c <= 'Z' ))
	||  (( c >= '0' ) && ( c <= '9' )))
		return( c );

 	if ((( c >= 'a' ) && ( c <= 'z' ))
	||  ( c == '\\' ))
		return( c );

	for ( sptr = (BPTR) "$_-+*/ :;.,?!()#%&=<>|[]{}"; *sptr; sptr++)
		if ( *sptr == c )
			break;
	return( *sptr );
}
		
EXAWORD	valid_token_character( c )
EXAWORD	c;
{
	if ((( c >= 'A' ) && ( c <= 'Z' ))
	||  (( c >= '0' ) && ( c <= '9' ))
 	||  (( c >= 'a' ) && ( c <= 'z' ))
	||  (  c == '_' ))  
		return(c);
	else	return(0);

}

#include "exdbhist.c"

EXAWORD	transfer_command( bptr, hptr, blen )
BPTR	bptr;
BPTR	hptr;
EXAWORD	blen;
{
	EXAWORD	i;
	for ( i = 0; i < blen; i++ )
		if ((*(bptr + i) = *(hptr + i)) == 0)
			break;
	*(bptr + i ) = 0;
	return(i);
}

VOID	display_command( topcol, toplin, bptr, blen)
EXAWORD	topcol;
EXAWORD	toplin;
BPTR	bptr;
EXAWORD	blen;
{
	EXAWORD	i;
	x_bstart();
	pos( toplin, topcol);
	for ( i = 0; i < blen; i++ ) {
		if ( *(bptr+i) )
			x_putch( *(bptr+i) );
		else	break;
		}
	for ( ; i < blen; i++ )
		x_putch( ' ' );
	x_bflush();
	return;
} 

EXAWORD	standard_ask( bptr, blen, msgptr, mode )
BPTR	bptr;
EXAWORD	blen;
BPTR	msgptr;
EXAWORD	mode;
{
	EXAWORD	insertflag=0;
	EXAWORD	l=0;
	EXAWORD	maxl=0;
	EXAWORD	c;
	EXAWORD	i;
	EXAWORD	msglen;
	EXAWORD	topcol=22;
	EXAWORD	toplin=4;
	BPTR	hptr;

#ifdef WIN1632
	/* Set caret visible */
	atb(26);
#endif

	/* Clear communication area and display Prompt Message */
	/* --------------------------------------------------- */
	standard_message( (BPTR) " " );
	display_operation_msg((BPTR) msgptr);

	/* Initialise buffer and control length */
	/* ------------------------------------ */
	if ( blen > 32 )
		blen = 32;
	if (mode == 0)
		memset( bptr, 0, blen );
	else	{
		display_command( topcol, toplin, (BPTR) bptr,(mode <= blen ? mode : blen));
		l = maxl = ( mode <= blen ? mode : blen );
		}

	x_bflush();
	while ( 1 ) {
		pos( toplin, (topcol+l));
		switch ((c = x_getch())) {
			case CTRL_O :
				insertflag = ((insertflag + 1) & 1);
 				continue;
			case 0x001B : 
				display_operation_mode(MOINS_UN);
				reset_message_zone();
				return( 0 );
			case CTRL_Z :
				alter_zoom_switch();
			case CTRL_N :
			case CTRL_U :
				continue;
				
			case CTRL_E :
				if ((hptr = next_history()) != (BPTR) 0) {
					maxl = transfer_command( bptr, hptr, blen );
					display_command( topcol, toplin, (BPTR) bptr, blen);
					l = maxl;
					}
				continue;

			case CTRL_A :
				memset( bptr, 0, blen );
				standard_message( (BPTR) " " );
				maxl = l = 0 ;
				continue;

			case CTRL_B :
				if ( l != maxl )
					l = maxl;
				else	l = 0;
				continue;

			case CTRL_K :
				if ((hptr = previous_history()) != (BPTR) 0) {
					maxl = transfer_command( bptr, hptr, blen );
					display_command( topcol, toplin, (BPTR) bptr, blen);
					l = maxl;
					}
				continue;

			case CTRL_J :
				l = maxl;
			case CTRL_D :
			case CTRL_M :
			case CTRL_L :
			case CTRL_I :
			 	*(bptr +l) = 0; 
				display_operation_mode(MOINS_UN);
				put_history( bptr );
				reset_message_zone();
				return( l );

			case CTRL_H :
				if ( l > 0 )
					l--;
				pos( toplin, (topcol+l));
				continue;

			case CTRL_F :
				if ( l < maxl )
					l++;
				pos( toplin, (topcol+l));
				continue;

			case 0x0007 :
			case 0x007F :
				if ( l < maxl ) {
					for ( i = l; i < maxl; i++ )
						*(bptr + i) = *(bptr + i + 1); 
					display_command( topcol, toplin, (BPTR) bptr, blen);
					maxl--;
					}

				continue;
					
			default	    : 
				if (( l < blen )
				&&  (((c = legal_symbol(c)) != 0)
				||    ( c == ' ' ))) {
					if ( insertflag ) {
						if (( i = maxl) != 0) {
							do	{
								i--;
								*(bptr + i + 1) = *(bptr + i);
								}
							while ( i != l );
							}
						*(bptr + (l++)) = c;
						if ( maxl < blen )
							maxl++;
						*(bptr + maxl) = 0;
						display_command( topcol, toplin, (BPTR) bptr, blen);
						}
					else	{
						pos( toplin, (topcol+l));
						*(bptr + (l++)) = c;
						x_putch(c);
						if ( l >= maxl )
							maxl = l;
						}
					}
			}
		}
}

EXAWORD	standard_command_input( nbcol , mode )
EXAWORD	nbcol;
EXAWORD	mode;
{
	EXAWORD	c;

	while ( 1 ) {

		check_for_stop_status();

		switch ((c = db_xgetch())) {
			case 0x001B : return( 0x001B );
			case CTRL_X : return( CTRL_X );
			case CTRL_O :
			case 0x0020 : return( 0x0020 );
			default :
			if ( c > 0x0020 ) {
				db_ungetch( c );
				if ( standard_ask( (BPTR) askbuf, nbcol, (BPTR) interface_message(31),0 ) != 0)
					return( 0 );
				}
			return( 13 );
			}
		}

}

EXAWORD	standard_integer_ask( mptr )
BPTR	mptr;
{
	EXAWORD	l;
	EXAWORD	n;
	EXAWORD	v;
	EXABYTE	buffer[16];
	if ((l = standard_ask( (BPTR) buffer, 15, (BPTR) mptr,0 )) != 0) {
		for ( n=0, v=0; n < l; n++ ) {
			if ((buffer[n] < '0') || (buffer[n] > '9'))
				break;
			v *= 10;
			v += (buffer[n] - '0');
			}
		return( v );
		}		
	else	return( MOINS_UN );	
}

EXAWORD	zoom_local_variables()
{
	if ( valid_local_data() ) {
		check_for_local_load();
		if ( DebugSymbols->locals != (SYMBOLPTR) 0 )
			return( display_symbols(50,6, DebugSymbols->locals ) );
		}
	return(0x001B);
}

EXAWORD	zoom_global_variables()
{
	EXAWORD	ctrl;
	EXAWORD	holdsect = DebugSymbols->ldt_sector;
	DebugSymbols->ldt_sector = 0;
	check_global_load();
	DebugSymbols->ldt_sector = 0;
	ctrl =	display_symbols(30,6, DebugSymbols->globals);
	DebugSymbols->ldt_sector = holdsect;
	return(ctrl);
}

EXAWORD	zoom_procedure_list()
{
	return( display_symbols(30,6, DebugSymbols->procedures) );
}

EXAWORD	zoom_segment_list()
{
	return( display_symbols(30,6, DebugSymbols->segments) );
}

EXAWORD	handle_click( clicktype )
EXAWORD	clicktype;
{
	EXAWORD	nbl;
	EXAWORD	nbc;
	EXAWORD	c;

	/* Ensure Mouse has been activated */
	/* ------------------------------- */
	if ( DbMouse.mode == 0 )
		return( 0 );


	/* Check for Top Box Selection */
	/* --------------------------- */
	if ((nbl = get_mimo_lin()) == 2 ) {
		if ((nbc = get_mimo_col()) == 0)
			return( 0 );
		else if (( nbc >= 3 ) && ( nbc <= 18 ))
			return( CTRL_J );
		else if (( nbc >= (ScreenCol-17) ) && ( nbc <= (ScreenCol-2) ))
			return( CTRL_N );
		else	return( 0x001B );		
		}

	/* Check for SWITCH selection */
	/* -------------------------- */
	if ( nbl == 4 ) {
		if ((nbc = get_mimo_col()) == 0)
			return( 0 );
		else if (( nbc >= 3 ) && ( nbc <= 11 )) {
			alter_break_switch();
			return( 0 );
			}
		else if (( nbc >= (ScreenCol-17) ) && ( nbc <= (ScreenCol-10) ))
			return( CTRL_Z );
		else if (( nbc >= 14) && ( nbc <= 19 )) {
			alter_hexa_switch();
			return(0);
			}
		else if (( nbc >= (ScreenCol-8) ) && ( nbc <= (ScreenCol-2) ))
			return(CTRL_W);
		else	return( 0x001B );		
		}

	/* Eliminate clicks outside declared zone : ESCAPE */
	/* ----------------------------------------------- */
	if ((nbl < DbMouse.top_line)
	||  (nbl > (DbMouse.top_line + DbMouse.lines+1))) {
		/* Check for observation window selection */
		/* -------------------------------------- */
		if (( ObservationCount != 0 ) 
		&&  ( nbl <= (ScreenLin -2))
		&&  ( nbl > ( (ScreenLin-2) - ObservationCount )))
			return( CTRL_U );
		else	{
			/* Check for function key selection */
			/* -------------------------------- */
			if ((nbl >= (ScreenLin-1) ) &&  (nbl <= (ScreenLin))) {
				if ((c = detect_function_key( nbl )) != 0)
					return( c );
				else	return( 0 );
				}
			else	return( 0x001B );
			}
		}

	/* check for outside column limits */
	/* ------------------------------- */
	if ((nbc = get_mimo_col()) == 0)
		return( 0 );
	if ((nbc < DbMouse.top_column)
	||  (nbc > (DbMouse.top_column+DbMouse.columns+1)))
		return( 0x001B );

	/* The click is in the correct zone */
	/* -------------------------------- */
	if ( nbl == DbMouse.top_line ) {
		if ( nbc == DbMouse.top_column )
			return( CTRL_L );
		else	return( CTRL_R );
		}
	else if ( nbl == (DbMouse.top_line+DbMouse.lines+1) )
		return( CTRL_C );
	else	{
		DbMouse.position  = (nbl - DbMouse.top_line);
		DbMouse.clicktype = clicktype;
		return( CTRL_D );
		}
}

EXAWORD	visual_mouse_or_keyboard=0;

VOID	use_visual_mouse()
{
	visual_mouse_or_keyboard=1;
	return;
}

EXAWORD	mouse_or_keyboard()
{
	EXAWORD	c;
	EXAWORD	nbl;
#ifdef	VERSION666
#ifndef	NOGIGO
	if ( visual_mouse_or_keyboard )
		return( visual_getch() );
#endif
#endif
	DbMouse.position = 0;

	/* Check first for posible ungot character */
	/* --------------------------------------- */
	if ((c = db_ungotch()) != 0)
		return( c );

	/* Check if mouse is active : if not use keyboard */
	/* ---------------------------------------------- */
	if (!( DbMouse.mode ))
		return((x_getch() & 0x00FF));

	/* Otherwise it may be a mouse event so perform event testing */
	/* ---------------------------------------------------------- */
	while ( 1 ) {
		if ((c = x_getch()) != 0x0100)
			return( (c & 0x00FF) );
		switch (((c = get_mimo_type())& 0x7FFF)) {
			case MIMO_NO_EVENT   	:
				continue;
			case MIMO_KEYBOARD 	:
				return((get_mimo_par() & 0x00FF));
			case MIMO_DOUBLE_CLICK	:
			case MIMO_MOUSE_UP 	:
				if (((c = handle_click((c & 0x7FFF))) != 0)
				&&  (c != CTRL_W))
					return( c );
				if (c == CTRL_W)
					toggle_visible_screen();
				continue;

			case MIMO_MOUSE_DOWN	:
				continue;
			case MIMO_MOVE  	:
				continue;
			case MIMO_WHILE_DOWN 	:
				continue;
			case MIMO_IS_DOWN 	:
				continue;
			}

		}
}

EXAWORD		check_quick_zoom(linfos,deblin)
CORRESPTR	linfos;
EXAWORD		deblin;
{ 
	EXAWORD		button=0;
	EXAWORD		nbcol=0;
	EXAWORD		nblin=0;
	EXAWORD		indent=0;
	SYMBOLPTR	fsymb;
	EXAWORD		debut=0;
	EXAWORD		fin=0;
  
	/* Check for Right hand button clicked */
	/* ----------------------------------- */
	if (((button = get_mimo_par()) != 0) 
	&&  ((nbcol  = get_mimo_col()) >= 8)
	&&  ((nblin  = get_mimo_lin()) != 0)
	&&  ((button & MIMO_RIGHT) == MIMO_RIGHT)
	&&  ( linfos != (CORRESPTR) 0)
	&&  ((fsymb = locate_source_number( linfos->file_number )) != (SYMBOLPTR) 0)
	&&  ( stream_position( _WORK_STREAM, (BPTR) fsymb->name, (EXALONG) linfos->file_offset, (fsymb->number+1), linfos->nature ))) {

		/* Collect current source line to buffer */
		/* ------------------------------------- */
		indent = load_correspondance_line();

		nblin -= deblin;
		nbcol -= 8;
		nbcol += (nblin * 70);

		/* Locate start of token */
		/* --------------------- */
		for ( ; nbcol != 0; nbcol-- )
			if (!(valid_token_character(askbuf[(nbcol-1)])))
				break;

		debut = nbcol;

		/* Locate End of Token */
		/* ------------------- */
		for ( ; nbcol < indent; nbcol++ )
			if (!(valid_token_character(askbuf[nbcol])))
				break;

		fin = nbcol;

		/* Locate Token Type */
		/* ----------------- */
		for (indent = 0 ;(indent < 16) && (debut < nbcol); debut++ )
			askbuf[(indent++)] = legal_symbol( askbuf[debut] );

		askbuf[(indent++)] = 0;
		uppercase_command((BPTR) askbuf );
		if ((fsymb = locate_any_symbol( (BPTR) askbuf )) != (SYMBOLPTR) 0) {
			zoom_symbol( fsymb );
			return( 1 );
			}			
		}
	return( 0 );
}

VOID	interprete_command( cmdptr, verbose )
BPTR	cmdptr;
EXAWORD	verbose;
{
	if ( verbose )
		standard_message((BPTR) cmdptr );
	command_interpreter( cmdptr, 0 );
	return;
}

VOID	execute_debug_script( nomfic, verbose )
BPTR	nomfic;
EXAWORD	verbose;
{
	EXAWORD	l;
	EXAWORD	c;
	
	stream_close(_TEMP_STREAM );
	if ( stream_position(_TEMP_STREAM , (BPTR) nomfic, (EXALONG) 0L, MOINS_UN, 0 ) != 0) {
		if ( verbose )
			standard_message((BPTR) interface_message(34) );
		l = 0;
		while (1) {
			if ((c = stream_getc(_TEMP_STREAM)) == EXDB_FFFF)
				c = 0x001A;
			switch (c) { 
				case 0x000D : 
					continue;
				case 0x000A : 
					if ( l == 0 )
						continue;
				case 0x0000 :
				case 0x001A :
					if ( l != 0 ) {
						CommandBuffer[(l++)] = 0;
						interprete_command((BPTR) CommandBuffer, verbose );
						}
					if ( c != 0x000A ) {
						if ( verbose )
							standard_message((BPTR) interface_message(35) );
						break;
						}
					else	{
						l = 0;
						continue;
						}
				case 0x0009 :
				case 0x000C :
				case 0x001C : 
					c = 0x0020;
				default     :
					if ( l < 255 ) {
						CommandBuffer[(l++)] = c;
						continue;
						}
					else if ( verbose )
						standard_error((BPTR) interface_message(36) );
					break;
				}
			break;				
			}
		stream_close( _TEMP_STREAM );
		} 
	else if ( verbose )
		standard_error((BPTR) interface_message(37) );

	return;
}

VOID	load_and_execute_debug_script()
{
	EXABYTE	nomfic[65];
	EXAWORD	l;
	memset((BPTR) nomfic,0,65);
	configuration_file_name((BPTR) nomfic, 65);
	if ((l = standard_ask( (BPTR) nomfic, 64, (BPTR) interface_message(33),exadb_strlen((BPTR) nomfic))) != 0)
		execute_debug_script( (BPTR) nomfic, 1 );
	return;
}

EXAWORD	specify_filename( nptr, mode )
BPTR	nptr;
EXAWORD	mode;
{
	EXAWORD	l=0;
	BPTR	mptr=(BPTR) 0;

	switch( mode ) {
		case _TEMP_STREAM  :
		case _TRACE_STREAM : return( 0 );
		case _WORK_STREAM  : 
		case _TCODE_STREAM : 
		case _DEBUG_STREAM : mptr = (BPTR) interface_message(37); break;
		}

	for ( l = 0; l < 256; l++ )
		if (( *(nptr+l) == 0 ) || ( *(nptr+l) == ' ' ))
			break;

	*(nptr+l) = 0;

	return(standard_ask( (BPTR) nptr, 70, (BPTR) mptr,l));
}

VOID	flush_window_configuration()
{
	EXAWORD	nbw;
	for ( nbw = 0; nbw < 16; nbw++ ) {
		stream_putb(_TEMP_STREAM,'W');
		stream_putb(_TEMP_STREAM,' ');
		stream_puti(_TEMP_STREAM, nbw );
		stream_putb(_TEMP_STREAM,' ');
		stream_putb(_TEMP_STREAM,'C');
		stream_putb(_TEMP_STREAM,' ');
		stream_puti(_TEMP_STREAM, window_ccoord(nbw) );
		stream_putb(_TEMP_STREAM,' ');
		stream_putb(_TEMP_STREAM,'L');
		stream_putb(_TEMP_STREAM,' ');
		stream_puti(_TEMP_STREAM, window_lcoord(nbw) );
		stream_putb(_TEMP_STREAM,' ');
		stream_putb(_TEMP_STREAM,'F');
		stream_putb(_TEMP_STREAM,' ');
		stream_puti(_TEMP_STREAM, window_fcoord(nbw) );
		stream_putb(_TEMP_STREAM,' ');
		stream_putb(_TEMP_STREAM,'B');
		stream_putb(_TEMP_STREAM,' ');
		stream_puti(_TEMP_STREAM, window_bcoord(nbw) );
		stream_putlf(_TEMP_STREAM);
		}
	return;
}

VOID	dump_debug_context()
{
	EXABYTE	nomfic[65];
	EXAWORD	l;
	EXAWORD	c;
	
	configuration_file_name((BPTR) nomfic, 65);
	if ((l = standard_ask( (BPTR) nomfic, 64, (BPTR) interface_message(38),exadb_strlen((BPTR) nomfic))) != 0) {
		if  ( stream_create(_TEMP_STREAM,(BPTR) nomfic) != 0 ) {
			standard_message((BPTR) interface_message(39) );
			flush_traps(_TEMP_STREAM);
			flush_watch_events(_TEMP_STREAM);
			flush_observations(_TEMP_STREAM);
			flush_trace_list(_TEMP_STREAM);
			if ( use_window_coordinates() )
				flush_window_configuration();
			stream_putb(_TEMP_STREAM,'K');
			stream_puti(_TEMP_STREAM, brayk );
			stream_putlf(_TEMP_STREAM);
			stream_putb(_TEMP_STREAM,'I');
			stream_puti(_TEMP_STREAM, TabSize );
			stream_putlf(_TEMP_STREAM);
			flush_search_path( _TEMP_STREAM );
			stream_flush(_TEMP_STREAM);
			reset_message_zone();
			}
		else	standard_error((BPTR) interface_message(40) );
		}
	return;
}


EXAWORD	offer_list_menu(opmode)
EXAWORD	opmode;
{
	EXAWORD	choice;

	if ((choice = 
		display_menu( 42,6, 8, 
					(BPTR) interface_message(41)	,
					(BPTR) interface_message(42)	,
					(BPTR) interface_message(43)	,
					(BPTR) interface_message(44)	,
					(BPTR) interface_message(45)	,
					(BPTR) interface_message(46)	,
					(BPTR) interface_message(47)	,
					(BPTR) interface_message(48)	,
					(BPTR) "\0"
			)) != MOINS_UN) 
		switch ( choice ) {
		case	0 : listpieges();
			    return(1); /* break; */
		case	1 : stack_trace();
			    return(1); /* break; */
		case	2 : WatchEventList((BPTR) "*");
			    break;
		case	3 : observation_list();
			    break;
		case	4 : traced_regions_list();
			    break;
		case	5 : display_assign_table(0);
			    break;
		case	6 : /* Read context  */
			    if ( opmode == 0 ) {
				    load_and_execute_debug_script();
				    return(1);
				    }
			    else    standard_message((BPTR) interface_message(49 ));
			    break;
 
		case	7 : dump_debug_context();
			    break;

		case	8 : alter_break_switch();
			    break;
		case 	9 : alter_hexa_switch();
			    break;
		}
	return(0);
}

VOID	symbols_selector( ctrl_code )
EXAWORD	ctrl_code;
{
	while ( 1 ) {
		switch ( ctrl_code ) {
			case	CTRL_P	:
				ctrl_code = zoom_procedure_list();
				continue;
			case	CTRL_S	:
				ctrl_code = zoom_segment_list();
				continue;
			case	CTRL_V	:
				ctrl_code = zoom_local_variables();
				continue;
			case	CTRL_G	:
				ctrl_code = zoom_global_variables();
				continue;
			default		:
				return;
			}
		}

}

CORRESPTR	check_correspondances()
{
	CORRESPTR	linfos=(CORRESPTR) 0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;

	switch ((BlockType = current_tcode_block_type())) {
		case 0 :	/* Segmental  code block */
			lsymb = locate_segment_number((BlockIdentity = current_tcode_identity() ));
			break;
						
		case 1 :	/* Procedural code block */
			lsymb = locate_procedure_number((BlockIdentity = current_tcode_identity() ));
			break;
	}

	if (lsymb != (SYMBOLPTR) 0)
		linfos= locate_correspondance( lsymb, (BlockOffset = current_tcode_offset()) );


/*		} */
	return( linfos );
}

VOID	trace_to_here( debut, linfos )
EXAWORD	debut;
CORRESPTR	linfos;
{
	add_trace_region( (BlockType == 0 ? 'S': 'P'), BlockIdentity, debut, linfos->tcode_offset );
	return;
}

static	CORRESPTR	zoom_correspondance_in( linfos, level )
CORRESPTR		linfos;
EXAWORD			level;
{
	while ((linfos != (CORRESPTR) 0)
	&&     (linfos->level != level))
		linfos = linfos->next;
	if ( linfos != (CORRESPTR) 0 )
		DebugLevel = level;
	return( linfos );
}

static	CORRESPTR	zoom_correspondance_out( linfos, level )
CORRESPTR		linfos;
EXAWORD			level;
{
	while ((linfos != (CORRESPTR) 0)
	&&     (linfos->level != level))
		linfos = linfos->previous;
	if ( linfos != (CORRESPTR) 0 )
		DebugLevel = level;
	return( linfos );
}

static	CORRESPTR	pseudo_step( linfos )
CORRESPTR		linfos;
{
	EXAWORD	current = linfos->level;
	EXAWORD	offset  = linfos->tcode_offset;
		
	while (( linfos = linfos->next) != (CORRESPTR) 0) {
		if ((( linfos->level <= current )
		   ||( linfos->level <= DebugLevel ))
		&&  (  linfos->tcode_offset > offset  ))
			break;
		}
	return( linfos );
}


#ifndef _MUI_
EXAWORD	display_correspondances( linfos, opmode )
CORRESPTR	linfos;
EXAWORD		opmode;
{
	EXAWORD		trace_toggle=0;
	EXAWORD		trace_start=0;
	EXAWORD		c;
	EXAWORD		lno=9;
	EXAWORD		topcol=1;
	EXAWORD		toplin=5;
	EXAWORD		nblin=16;
	EXAWORD		nbcol=80;
	SYMBOLPTR	fsymb;
	CORRESPTR	zinfos;
	CORRESPTR	tinfos;
	CORRESPTR	hinfos;
	CORRESPTR	finfos;

	if ( linfos->level > DebugLevel )
		return(' ');

	/* Adjust line count to avoid observation display */
	/* ---------------------------------------------- */
	nbcol = ScreenCol;
	nblin = avoid_observations( (ScreenLin - 8) );

	correspondance_header( topcol, toplin, nbcol, nblin, opmode );

	draw_correspondance_page(topcol,toplin, nbcol, nblin,(hinfos = tinfos = linfos) );

	lno = ((nblin/2)+2);

	/* Display current selection */
	/* ------------------------- */
	while ( 1 ) {

		if ((c = show_correspondance( 2, (topcol), (toplin+1),lno, nbcol, nblin, tinfos )) == 0)
			c = mouse_or_keyboard();

		if (DebugSymbols->zoom_status == 2)
			show_correspondance( 0, (topcol), (toplin+1),lno, nbcol, nblin, tinfos );

		switch ( c ) {
#ifdef	MODEL_DBGT	
			case ':'    :
				if ( TCASMFLAG ) {
					DebugLevel = (TCASMFLAG - 1);
					TCASMFLAG = FAUX;
					}
				else	{
					TCASMFLAG = (DebugLevel + 1);
					DebugLevel = 256;
					}
				continue;
#endif	
			case ';'    :
				if ( CorresFile )
					CorresFile = 0;
				else	CorresFile = 1;
				break;

			case '>'    : 
				DebugLevel++;
/*
				if ((zinfos = zoom_correspondance_in( tinfos, (DebugLevel+1))) != (CORRESPTR) 0)
					draw_correspondance_page(topcol,toplin, nbcol, nblin,(hinfos = tinfos = zinfos) );
 */
				show_debug_level();
				continue;


			case '<'    :
				if ( DebugLevel )
					DebugLevel--;
/*
				if (( DebugLevel )
				&&  ((zinfos = zoom_correspondance_out( tinfos, (DebugLevel-1))) != (CORRESPTR) 0))
					draw_correspondance_page(topcol,toplin, nbcol, nblin,(hinfos = tinfos = zinfos) );
 */
				show_debug_level();
				continue;

			case '-'    :	 
				if ( opmode == 0 ) {
					pop_mouse();
					previous_correspondance();
					correspondance_header( topcol, toplin, nbcol, nblin, opmode );
					}
				break;

			case '?'    :
				alter_hexa_switch();
				continue;

			case	CTRL_H :
				view_help_screen(0);
				pop_mouse();
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;
				
			case	CTRL_D :
				if ( DbMouse.position == 0 )
					continue;

				if ( DebugSymbols->zoom_status < 2 ) {
					if ((finfos = ZoomLine[(DbMouse.position-1)]) != (CORRESPTR) 0) {
						linfos = tinfos = finfos;
						lno = 1;
						}
					else	continue;
					}
				else	{
					if ( DbMouse.position < lno ) {
						for ( ; lno != DbMouse.position; lno-- ) {
							if (( tinfos != (CORRESPTR) 0 )
							&&  ( tinfos->previous != (CORRESPTR) 0))
								tinfos = tinfos->previous;
							else	continue;
							}
						}
					else	{
						for ( ; lno  != DbMouse.position; lno++ ) {
							if (( tinfos != (CORRESPTR) 0 )
							&&  ( tinfos->next != (CORRESPTR) 0))
								tinfos = tinfos->next;
							else	continue;
							}
						}
					}

				if ( check_quick_zoom( tinfos,(toplin+lno) ) ) {
					correspondance_header( topcol, toplin, nbcol, nblin, opmode );
					break;
					}

				if ( current_mouse_click() != 2 )
					continue;
	
			case	CTRL_M	:
				pop_mouse();
				edit_correspondance_file( tinfos );
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_F :
				find_correspondance(hinfos);
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_L :
				linfos = tinfos = hinfos;
				lno = ((nblin/2)+2);
				break;

			case	CTRL_Q :
				if ((opmode == 0 )
				&&  ( tinfos != (CORRESPTR) 0 )) {
 					set_break_point( 0x0002, tinfos );
					pop_mouse();
					return( 0x0018 );
					}
				else	continue;

			case	CTRL_I :
				if ( opmode == 0 ) {
					if ( linfos->nature ) {
						if ((zinfos = pseudo_step( linfos )) != (CORRESPTR) 0) {
		 					set_break_point( 0x0002, zinfos->next );
							pop_mouse();
							return( 0x0018 );
							}
						}
					else if ( hinfos->next != (CORRESPTR) 0 ) {
	 					set_break_point( 0x0002, hinfos->next );
						pop_mouse();
						return( 0x0018 );
						}
					}
				continue;

			case 	CTRL_J :
				stream_close(_WORK_STREAM);
				pop_mouse();
				symbols_browser();
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_C :
				for ( c = 0; c < 8; c++ ) {
					if (( tinfos->next == (CORRESPTR) 0)
					||  ( linfos->next == (CORRESPTR) 0))
						break;
					tinfos = tinfos->next;
					linfos = linfos->next;
					}
				if ( c != 0 )
					break;
				else	continue;

			case	CTRL_R :

				for ( c = 0; c < 8; c++ ) {
					if (( tinfos->previous == (CORRESPTR) 0)
					||  ( linfos->previous == (CORRESPTR) 0))
						break;
					tinfos = tinfos->previous;
					linfos = linfos->previous;
					}
				if ( c != 0 )
					break;
				else	continue;

			case	CTRL_Z	:
				alter_zoom_switch();
				break;
			
			case 	CTRL_G :
				pop_mouse();
				symbols_selector( CTRL_G );
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_P :
				pop_mouse();
				symbols_selector( CTRL_P );
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_S :
				pop_mouse();
				symbols_selector( CTRL_S );
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_V :
				if ( opmode == 0 ) {
					pop_mouse();
					symbols_selector( CTRL_V );
					correspondance_header( topcol, toplin, nbcol, nblin, opmode );
					break;
					}
				continue;
				
			case	CTRL_Y :
				c  = 0; 
			case	CTRL_A  :
			case	CTRL_B  :

				set_break_point( c, tinfos );
				continue;

			case CTRL_U	:
				pop_mouse();
				Observe(1);
				correspondance_header( topcol, toplin, nbcol, nblin, opmode );
				break;

			case	CTRL_N  :
				pop_mouse();
				if (( offer_list_menu(opmode) != 0 )
				&&  ((finfos = check_correspondances()) != (CORRESPTR) 0))

					tinfos = hinfos = linfos = finfos;

				/* Adjust line count to avoid observation display */
				/* ---------------------------------------------- */
				Observe(0);
				nblin = avoid_observations( (ScreenLin - 8) );

				correspondance_header( topcol, toplin, nbcol, nblin, opmode );

				lno = ((nblin/2)+2);

				break;

			case	CTRL_E	:

				if ( tinfos->next ) {
					if ((zinfos = zoom_correspondance_in(tinfos->next,DebugLevel)) == (CORRESPTR) 0)
						continue;
					else	tinfos = zinfos;
					if ( lno < nblin )
						lno++;
					else	{
						if ((zinfos = zoom_correspondance_in(linfos->next,DebugLevel)) == (CORRESPTR) 0)
							continue;
						linfos = zinfos;
						break;
						}
					}
				continue;

			case	CTRL_K	:

				if ( tinfos->previous ) {
					if ((zinfos = zoom_correspondance_out(tinfos->previous,DebugLevel)) == (CORRESPTR) 0)
						continue;
					else	tinfos = zinfos;
					if ( lno > 1 )
						lno--;
					else	{
						if ((zinfos = zoom_correspondance_out(linfos->previous,DebugLevel)) == (CORRESPTR) 0)
							continue;
						linfos = zinfos;
						break;
						}
					}
				continue;

			case	CTRL_T	:
				if ( trace_toggle ) {
					trace_to_here( trace_start, tinfos ); 
					trace_toggle = 0;
					}
				else	{
					Verbose( (BPTR) interface_message(50) );
					trace_start  = tinfos->tcode_offset;
					trace_toggle = 1;
					}
				break;

				
			case 	CTRL_O	:
				c = 0x0020;
			case	CTRL_X  :
			case	0x0020	:

			default 	:
				pop_mouse();
				return( c );

			}

		draw_correspondance_page( topcol, toplin, nbcol, nblin,linfos);

		}

}
#endif /* _MUI_ */



/*	------------------------------------------------------------	*/
/*	T C O D E _ C O R R E S P O N D A N C E ( type, id, offset )	*/
/*	------------------------------------------------------------	*/
/*									*/
/*	This is the PUBLIC function which provides source positioning	*/
/*	for the execution debug motor each time it comes to rest	*/
/*									*/
/*	The return value of VRAI ( 1 ) indicates that source infos	*/
/*	exist and have been displayed for the provided parameters.	*/
/*									*/
/*	The return value of FAUX ( 0 ) indicates that either no		*/
/*	source linkage infos exist or that they cannot be displayed	*/
/*	for various unidentified reasons.				*/ 
/*									*/
/*	------------------------------------------------------------	*/

CORRESPTR resolve_correspondance( 
		EXAWORD type_code, 
		EXAWORD identity, 
		EXAWORD	offset
		)
{
	CORRESPTR	linfos=(CORRESPTR) 0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;

	switch ((BlockType = type_code)) {
		case 0 :	/* Segmental  code block */
			lsymb = locate_segment_number((BlockIdentity = identity ));
			break;
						
		case 1 :	/* Procedural code block */
			lsymb = locate_procedure_number((BlockIdentity = identity ));
			break;
		}

	if (lsymb != (SYMBOLPTR) 0)
		if (( linfos= locate_correspondance( lsymb, (BlockOffset = offset) )) != (CORRESPTR) 0)
			return( linfos );

	return((CORRESPTR) 0);

}

EXAWORD	tcode_correspondance( type_code, identity, offset, modus )
EXAWORD	type_code;
EXAWORD	identity;
EXAWORD	offset;
EXAWORD	modus;
{
	CORRESPTR	linfos=(CORRESPTR) 0;
	EXAWORD		HoldType = BlockType;
	EXAWORD		HoldId   = BlockIdentity;
	EXAWORD		result   = FAUX;
	EXAWORD		HoldOffset = BlockOffset;

	if ( test_stop_status() )
		result = FAUX;
	else if (( linfos= resolve_correspondance(type_code,identity,offset)) != (CORRESPTR) 0)
		result = display_correspondances( linfos, modus );
	else if ( test_stop_status() )
		result = FAUX;
	else	result = ' ';
	BlockType = HoldType;
	BlockIdentity = HoldId;
	return(result);

}

/*	-----------------------------------------------------------	*/
/*	S O U R C E _ C O R R E S P O N D A N C E ( lsymb )		*/
/*	---------------------------------------------------		*/
/*									*/
/*	Provides source linkage browsing function for specified		*/
/*	symbol structure						*/
/*									*/
/*	-----------------------------------------------------------	*/
VOID		source_correspondance( lsymb )
SYMBOLPTR	lsymb;
{
	CORRESPTR	linfos;
	EXAWORD		c;
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	EXAWORD		HoldType=BlockType;
	EXAWORD		HoldIdentity=BlockIdentity;

	BlockIdentity	= lsymb->number;
	if ( lsymb->type == PNAME_SYMBOL )
		BlockType = 1;
	else	BlockType = 0;

	if (( linfos = collect_correspondances(lsymb)) != (CORRESPTR) 0) {
		display_correspondances( linfos, 1 );
		release_correspondances( linfos );
		}
	BlockType = HoldType;
	BlockIdentity = HoldIdentity;
	return;
}
	
VOID		zoom_code_block( lsymb )
SYMBOLPTR	lsymb;
{
	EXAWORD	choice;

	if  ((choice = display_menu( 22,17, 2, 
					(BPTR) interface_message(51), 
					(BPTR) interface_message(52),
					(BPTR) "\0",
					(BPTR) "\0",
					(BPTR) "\0",
					(BPTR) "\0",
					(BPTR) "\0",
					(BPTR) "\0",
					(BPTR) "\0"
			)) != MOINS_UN) 
	switch ( choice ) {
		case	0	:
			source_correspondance( lsymb );
			break;
		case	1	:
			display_local_variables( lsymb );
			break;
		}
	return;
}

VOID		display_procedure_signature( topcol, toplin, lsymb )
EXAWORD		topcol;
EXAWORD		toplin;
SYMBOLPTR	lsymb;
{
	if ( lsymb == (SYMBOLPTR) 0 )
		return;

	pos( toplin, topcol );

	output_procedure_signature( lsymb );

	return;
}


VOID	zoom_signature( lsymb )
SYMBOLPTR	lsymb;
{

	draw_box( 1, 15, (ScreenCol-2), 1 );
	x_bstart(); 
	symbolic_atribut(1);
	display_procedure_signature(3, 16, lsymb );
	symbolic_atribut(0);
	x_bflush();
	return;
}

EXAWORD	zoom_symbol( lsymb )
SYMBOLPTR	lsymb;
{
	if ( lsymb != (SYMBOLPTR) 0) {
		switch ( lsymb->type ) {
			case FNAME_SYMBOL :
				standard_text_editor( lsymb->name );
				break;
			case VNAME_SYMBOL :
				return( display_variable_declaration( lsymb->name, lsymb->number ) );

			case PNAME_SYMBOL :
				zoom_signature( lsymb );

			case SNAME_SYMBOL :
				zoom_code_block( lsymb );
				break;
			}
		}
	return(0);
}

VOID	repeat_zoom_symbol( lsymb )
SYMBOLPTR	lsymb;
{
	EXAWORD	c;
	while ( 1 ) {
		switch ((c = zoom_symbol( lsymb ))) {
			case 0x0005	:
				if ( lsymb->next != (SYMBOLPTR) 0)
					lsymb = lsymb->next;
				continue;
			case 0x000B	:
				if ( lsymb->previous != (SYMBOLPTR) 0)
					lsymb = lsymb->previous;
				continue;
			default		:
				return;
			}
		}
}
	 
SYMBOLPTR	find_symbol( tsymb, hsymb )
SYMBOLPTR	tsymb;
SYMBOLPTR	hsymb;
{
	SYMBOLPTR	lsymb=(SYMBOLPTR)0;
	EXAWORD		l=0;
	EXABYTE	buffer[65];
	if ((l = standard_ask((BPTR)buffer,64,(BPTR) interface_message(53),0 )) != 0)
		if ((lsymb = locate_symbol( tsymb, (BPTR) buffer)) == (SYMBOLPTR) 0)
			lsymb = locate_symbol( hsymb, (BPTR) buffer);
	return( lsymb );
}

VOID	trap_symbol( lsymb, type )
SYMBOLPTR	lsymb;
EXAWORD	type;
{
	EXABYTE	buffer[65];
	switch ( lsymb->type ) {
		case VNAME_SYMBOL :
			if ( type )
				exadb_strcpy((BPTR) buffer,"V");
			else	exadb_strcpy((BPTR) buffer, " I " );
			exadb_strcat((BPTR) buffer, (BPTR) lsymb->name );
			if ( type )
				traper( (type & 1), (BPTR) buffer );
			else	WatchFunctions((BPTR) buffer );
			break;

		case SNAME_SYMBOL :
			if ( type )
				posepiege( lsymb->number, 0, 0, (type & 1 ? 1 : 0),(BPTR) 0);
			else	wipepiege( lsymb->number, 0, 0,(BPTR) 0);
			break;

		case PNAME_SYMBOL :
			if ( type )
				posepiege( (lsymb->number / (8*WORDSIZE)), 0, 1, (type & 1 ? 1 : 0),(BPTR) 0);
			else	wipepiege( (lsymb->number / (8*WORDSIZE)), 0, 2,(BPTR) 0);
			break;
		}
	return;

}

EXAWORD		is_observation( lsymb )
SYMBOLPTR	lsymb;
{
	switch ( lsymb->type ) {
		case	VNAME_SYMBOL :
			if ( is_known_observation( lsymb->number ) != 0 )
				return('O');
			else	return( 0 );
		case	SNAME_SYMBOL :
			if ( is_traced_region( 'S', lsymb->number, 0 ) != 0 )
				return('T');
			else	return( 0 );
		case 	PNAME_SYMBOL :
			if ( is_traced_region( 'P', lsymb->number, 0 ) != 0 )
				return('T');
			else	return( 0 );
		}
	return( 0 );
}

void	display_symbol(topcol, toplin,nbcol, xsymb )
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
SYMBOLPTR	xsymb;
{
	EXAWORD	flag;
	EXABYTE	rptr[256];

	if ( xsymb == (SYMBOLPTR) 0 )
		centered_string( topcol, toplin, nbcol,(BPTR) interface_message(54) );
	else	{
		pos(toplin,topcol-1);
		if ((flag = is_trapped_symbol( xsymb )))
			x_putch((0x0040+flag));
		else	x_putch(' ');
		if(xsymb->type == FNAME_SYMBOL || xsymb->type == LNAME_SYMBOL)
		{
			if( fn_parser((BPTR)xsymb->name,(BPTR)rptr,7))
			{
#ifdef UNIX
			   strcpy(rptr,".../");
#endif	
#ifdef VMS
			   strcpy(rptr,"[  ]");
#endif

#ifndef UNIX
#ifndef VMS
			   strcpy(rptr,"...\\");
#endif
#endif

			   fn_parser((BPTR)xsymb->name,(BPTR)&rptr[4],24);
			   rptr[255]=0;
			}
			else
			   strcpy(rptr,(BPTR)xsymb->name);
		}
		else
			strcpy(rptr,(BPTR)xsymb->name);
		centered_string( topcol, toplin, nbcol, rptr );

		if ((flag = is_observation( xsymb )) != 0)
			x_putch(flag);
		else	x_putch(' ');
		}
	return;
}


VOID		draw_liste( topcol, toplin, ncol, nlin, xsymb )
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		ncol;
EXAWORD		nlin;
SYMBOLPTR	xsymb;
{
	EXAWORD	item=0;
	EXAWORD	flag;

	while (( item < nlin ) && ( xsymb != (SYMBOLPTR) 0)) {
		display_symbol(topcol,(toplin+item),ncol,xsymb );
		item++;
		xsymb = xsymb->next;
		}
	if (( xsymb == (SYMBOLPTR) 0 )
	&&  ( item  <  nlin ))
		centered_string( topcol,toplin+(item++),ncol, interface_message( 54 ) );


	for ( ; item < nlin; item++ )
		left_string( topcol, toplin+item, ncol, " " );

	return;
}

BPTR	liste_titre( lsymb )
SYMBOLPTR	lsymb;
{
	if ( lsymb != (SYMBOLPTR) 0 ) {
		switch ( lsymb->type ) {
			case PNAME_SYMBOL : return((BPTR) interface_message( 64 ));
			case SNAME_SYMBOL : return((BPTR) interface_message( 65 ));
			case VNAME_SYMBOL : return((BPTR) interface_message( 62 ));
			case CNAME_SYMBOL : return((BPTR) interface_message( 63 ));
			case LNAME_SYMBOL : return((BPTR) interface_message( 66 ) );
			case FNAME_SYMBOL : return((BPTR) interface_message( 60 ) );
			}
		}
	return((BPTR) "\0" );
}

EXAWORD	right_button_click()
{
	EXAWORD	button;
	EXAWORD	nbcol;

	if (((button = get_mimo_par()) != 0) 
	&&  ((nbcol  = get_mimo_col()) != 0)
	&&  ((button & MIMO_RIGHT) == MIMO_RIGHT))
		return( VRAI );
	else	return( FAUX );
}


VOID		declare_observation( lsymb, mode )
SYMBOLPTR	lsymb;
{
	if ( lsymb->type == VNAME_SYMBOL ) {
		if (!(is_observation( lsymb ))) {
			exadb_strcpy((BPTR) askbuf, (BPTR) "A");
			exadb_strcat((BPTR) askbuf, (BPTR) lsymb->name );
			observation_management((BPTR) askbuf );
			}
		}
	else if (((lsymb->type == SNAME_SYMBOL)
	     ||   (lsymb->type == PNAME_SYMBOL))
	     &&   (mode == CTRL_D)) {
		trap_symbol( lsymb, current_mouse_click() );
		}	
	return;
}

VOID	trace_symbol( lsymb )
SYMBOLPTR	lsymb;
{
	EXAWORD	mode='S';

	switch ( lsymb->type ) {
		case PNAME_SYMBOL :
			mode = 'P';
		case SNAME_SYMBOL :
			add_trace_region( mode, lsymb->number, 0, MOINS_UN );
		}
	return;
}


EXAWORD	display_symbols(topcol, toplin, lsymb )
EXAWORD	topcol;
EXAWORD	toplin;
SYMBOLPTR	lsymb;
{
	SYMBOLPTR	xsymb;
	SYMBOLPTR	hsymb;
	SYMBOLPTR	fsymb;
	EXAWORD		item=1;
	EXAWORD		c;
	EXAWORD		flag;
	BPTR		tptr;
	EXAWORD		maxsline=(conf(1)/2);
	if (( lsymb != (SYMBOLPTR) 0 ) 
	&&  ( use_window_coordinates() )) {
		topcol = window_ccoord( lsymb->type );
		toplin = window_lcoord( lsymb->type );
		}
	xsymb = lsymb;
	symbol_atribut(0,xsymb);
	mouse_title_box( (topcol-1), toplin, 32, maxsline,(BPTR)(tptr = liste_titre(lsymb)) );
	draw_liste( topcol+2, toplin+1, 28, maxsline,(hsymb = xsymb=lsymb) );
	while ( 1 ) {
		symbol_atribut(2,xsymb);
		display_symbol( topcol+2,toplin+item,28,xsymb);
		symbol_atribut(0,xsymb);
		c = mouse_or_keyboard();
		display_symbol( topcol+2,toplin+item,28,xsymb);
		switch ( c ) {
				
			case '?'    :
				alter_hexa_switch();
				continue;

			case CTRL_H :
				view_help_screen(1);
				draw_box( topcol, toplin, 18, maxsline );
				break;

			case CTRL_Z :
				alter_zoom_switch();
				continue;

			case CTRL_Y :
				c = 0;	
			case CTRL_A :
			case CTRL_B :
				trap_symbol( xsymb, c );
				continue;
			case CTRL_C :
				for ( c = 0; c < 8; c++ ) {
					if (( xsymb != (SYMBOLPTR) 0) 
					&&  ( xsymb->next != (SYMBOLPTR) 0)) {
						xsymb = xsymb->next;
						lsymb = lsymb->next;
						}
					else	break;
					}
				if ( c != 0 )
					break;
				else	continue;
	
			case	CTRL_T :
				trace_symbol( xsymb );
				continue;

			case	CTRL_R :
				for ( c = 0; c < 8; c++ ) {
					if (( lsymb != (SYMBOLPTR) 0)
					&&  ( lsymb->previous != (SYMBOLPTR) 0)) {
						xsymb = xsymb->previous;
						lsymb = lsymb->previous;
						}
					else	break;
					}
				if ( c != 0 )
					break;
				else	continue;

			case CTRL_D	: /* Sent from Mouse ??? */

				if ( DbMouse.position == 0 )
					continue;

				if ( DbMouse.position < item ) {
					for ( ; item != DbMouse.position; item-- ) {
						if (( xsymb != (SYMBOLPTR) 0 )
						&&  ( xsymb->previous != (SYMBOLPTR) 0))
							xsymb = xsymb->previous;
						else	break;
						}
					}
				else	{
					for ( ; item != DbMouse.position; item++ ) {
						if (( xsymb != (SYMBOLPTR) 0 )
						&&  ( xsymb->next != (SYMBOLPTR) 0))
							xsymb = xsymb->next;
						else	break;
						}
					}

				if ( right_button_click() ) {
					declare_observation(xsymb,c);
					continue;
					}

				if ( current_mouse_click() != 2 )
					continue;

			case CTRL_M	:
				symbol_atribut(2,xsymb);
				display_symbol( topcol+2,toplin+item,28,xsymb);
				symbolic_atribut(0);
				pop_mouse();
				zoom_symbol( xsymb );
				symbol_atribut(0,xsymb);
				mouse_title_box( topcol-1, toplin, 32, maxsline,(BPTR) tptr );
				break;

			case CTRL_O     :
				declare_observation(xsymb,c);
				continue;

			case CTRL_F	:
				if ((fsymb = find_symbol(xsymb, hsymb)) != (SYMBOLPTR) 0) {
					xsymb = lsymb = fsymb;
					item = 1;
					break;
					}
				continue;
					
			case 0x0040 : /* Cut List Here */

				liberate_symbol_list( xsymb->next );
				xsymb->next = (SYMBOLPTR) 0;

			case CTRL_L	:
				lsymb = xsymb = hsymb;
				item = 1;
				break;

			case CTRL_P	:
			case CTRL_S	:
			case CTRL_V	:
			case CTRL_G	:
			case 0x001B	:
				pop_mouse();
				return(c);
			case CTRL_U	:
				pop_mouse();
				Observe(1);
				symbol_atribut(0,xsymb);
				mouse_title_box( topcol-1, toplin, 20, maxsline,(BPTR) tptr );
				continue;

			case CTRL_N	:
				pop_mouse();
				offer_list_menu(1);
				symbol_atribut(0,xsymb);
				mouse_title_box( topcol-1, toplin, 20, maxsline,(BPTR) tptr );
				break;

			case 0x0020	:

			case CTRL_E	:
				if (( xsymb != (SYMBOLPTR) 0 )
				&&  ( xsymb->next != (SYMBOLPTR) 0)) { 
					xsymb = xsymb->next;
					if ( item < maxsline )
						item++;
					else	{
						lsymb = lsymb->next;
						break;
						}
					}
				continue;
			case CTRL_K	:
				if (( xsymb != (SYMBOLPTR) 0 )
				&&  ( xsymb->previous != (SYMBOLPTR) 0)) {
					xsymb = xsymb->previous;
					if ( item > 1 ) 
						item--;
					else	{
						lsymb = lsymb->previous;
						break;
						}
					}
				continue;
			}

		draw_liste( topcol+2, toplin+1, 28, maxsline,lsymb );

		}
		
}

VOID	clear_screen()
{
	x_putch( 0x000C );
	return;
}

VOID		choose_all_symbols(sptr,mode)
SYMBOLPTR	sptr;
EXAWORD		mode;
{
	while ( sptr != (SYMBOLPTR) 0) {
		if ( mode == 'T' )
			trace_symbol( sptr );
		else if ( mode == 'A' )
			trap_symbol( sptr, mode );
		else if ( mode == 'B' )
			trap_symbol( sptr, mode );
		sptr = sptr->next;
		}
	return;
}

VOID		trace_all_symbols( mode )
EXAWORD		mode;
{
	if (( mode == 'S' )
	||  ( mode == '*' ))
		choose_all_symbols( DebugSymbols->segments, 'T' );

	if (( mode == 'P' )
	||  ( mode == '*' ))
		choose_all_symbols( DebugSymbols->procedures, 'T' );

	return;
}


/*	------------------------------------------------------------	*/
/*	S Y M B O L S _ B R O W S E R 					*/
/*	-----------------------------					*/
/*	Provides extensive symbol browsing features via user menu	*/
/*	------------------------------------------------------------	*/
VOID	symbols_browser()
{
	EXAWORD	choice;

	while ( 1 ) {
		if  ((choice = display_menu( 2, 6, 7, 
			(BPTR) interface_message( 60 ) ,
			(BPTR) interface_message( 61 ) ,
			(BPTR) interface_message( 62 ) ,
			(BPTR) interface_message( 63 ) ,
			(BPTR) interface_message( 64 ) ,
			(BPTR) interface_message( 65 ) ,
			(BPTR) interface_message( 66 ) ,
			(BPTR) "\0",
			(BPTR) "\0"
			)) == MOINS_UN) 
			break;
		switch ( choice ) {
			case  0 	: /* Sources 	*/
				(VOID) display_symbols( 30, 6,DebugSymbols->sources);
				break;
			case  1 	: /* Listes  	*/	
				(VOID) display_symbols( 30, 6, DebugSymbols->listes);
				break;
			case  2 	: /* Variables	*/
				(VOID) zoom_global_variables();
				break;
			case  3 	: /* Constants	*/
				(VOID) display_symbols(30,6, DebugSymbols->constants);
				break;
			case  4 	: /* Procedures */
				(VOID) zoom_procedure_list();
				break;
			case  5 	: /* Segments	*/
				(VOID) zoom_segment_list();
				break;
			case  6 	: /* Libraries	*/
				(VOID) display_symbols(30,6, DebugSymbols->libraries);
				break;
			}
		}
}

#ifdef	MODEL_DBGT
EXAWORD	show_before_compare( a, b, c, d )
EXAWORD	a;
BPTR	b;
EXAWORD	c;
BPTR	d;
{

	display_integer( a );
	x_putch(':');
	x_cprintf( (BPTR) b );
	x_putch(':');
	display_integer( c );
	x_putch(':');
	x_cprintf((BPTR) d );
	x_putch('?');
	x_bflush();
	return( x_getch() );
}
#endif

#ifdef	DEBUG_XLDF
VOID	InspectLdfCall( nbl, nbf, nba )
EXAWORD	nbl;
EXAWORD	nbf;
EXAWORD	nba;
{
	left_string( 1,24,20,(BPTR) "CallRunTime(L,F,A)(");
	(VOID) display_integer( nbl );
	x_putch(',');
	(VOID) display_integer( nbf );
	x_putch(',');
	(VOID) display_integer( nba );
	x_putch(')');
	(VOID) x_getch();
	return;
}

#endif

#include "exdbfind.c"


#ifdef _MUI_
#include "exdbmui.c"
#endif

#endif	/* EXDBUI_C */
	/* -------- */
