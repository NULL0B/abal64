#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRIOF.C    				*/
/*		Version :	2.1c					*/
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRIOF_C
#define	_TRIOF_C
#define	_GEN_C_RTL

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"
#include "translat.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "triof.h"
#include "trdebug.h"
#include "trfmt.h"
#include "trfmt.c"
#include "trgenc.h"
#include "trtnode.h"

WORD	initialise_iof()
{
	IofFree = IofFoot = IofHead = (IOFPTR) 0;
	HotFree = HotFoot = HotHead = (HOTPTR) 0;
	AskEndLabel = MOINS_UN;
	return(0);
}

IOFPTR	allocate_for_iof()
{
	IOFPTR	iptr;
	if ((iptr = IofFree) != (IOFPTR) 0)
		IofFree = IofFree->next;
	else if ((iptr = (IOFPTR) allocate( sizeof(struct iof_control ))) == (IOFPTR) 0)
		return( iptr );
	iptr->operation = MOINS_UN;
	iptr->operand   = (RESULTPTR) 0;
	iptr->buffer	= (BPTR) 0;
	iptr->next      = (IOFPTR) 0;
	iptr->prev      = (IOFPTR) 0;
	return( iptr );
}

HOTPTR	allocate_for_hotkey()
{
	HOTPTR	iptr;
	if ((iptr = HotFree) != (HOTPTR) 0)
		HotFree = HotFree->next;
	else if ((iptr = (HOTPTR) allocate( sizeof(struct hot_control ))) == (HOTPTR) 0)
		return( iptr );
	iptr->nature    = MOINS_UN;
	iptr->operand   = (RESULTPTR) 0;
	iptr->label     = (BPTR) 0;
	iptr->gosub     = FAUX;
	iptr->next      = (HOTPTR) 0;
	return( iptr );
}

HOTPTR	copy_hotkey( hptr )
HOTPTR	hptr;
{
	HOTPTR	nptr;
	if ((nptr = allocate_for_hotkey()) != (HOTPTR) 0) {
		nptr->nature  = hptr->nature;
		nptr->operand = hptr->operand;
		nptr->label   = hptr->label;
		nptr->gosub   = hptr->gosub;
		}
	return( nptr );
}

VOID	release_iof( iptr )
IOFPTR	iptr;
{
	iptr->next = IofFree;
	if ( iptr->buffer != (BPTR) 0)
		liberate( iptr->buffer );
	IofFree = iptr;
	return;
}

VOID	release_hotkey( iptr )
HOTPTR	iptr;
{
	iptr->next = HotFree;
	if ( iptr->label != (BPTR) 0)
		liberate( iptr->label );
	HotFree = iptr;
	return;
}

VOID	liberate_iof()
{
	IOFPTR	iptr;
	trace("liberate_iof()\n");
	while ((iptr = IofFree) != (IOFPTR) 0) {
		IofFree = IofFree->next;
		liberate( iptr );
		}
	return;
}

VOID	liberate_hot()
{
	HOTPTR	iptr;
	trace("liberate_hot()\n");
	while ((iptr = HotFree) != (HOTPTR) 0) {
		HotFree = HotFree->next;
		liberate( iptr );
		}
	return;
}

WORD	start_iof()
{
	IOFPTR	iptr;
	HOTPTR	hptr;
	trace("start_iof()\n");
	AskEndLabel = MOINS_UN;
	while ((iptr = IofHead) != (IOFPTR) 0) {
		IofHead = IofHead->next;
		release_iof( iptr );
		}
	IofFoot = IofHead = (IOFPTR) 0;
	while ((hptr = HotHead) != (HOTPTR) 0) {
		HotHead = HotHead->next;
		release_hotkey( hptr );
		}
	HotFoot = HotHead = (HOTPTR) 0;
	return(0);
} 

VOID	terminate_iof()
{
	trace("terminate_iof(START)\n");
	if (start_iof() ==0) {
		liberate_iof();
		liberate_hot();
		}
	trace("terminate_iof(END)\n");
	return;
}


WORD	translate_pause()
{
	BPTR	rptr;
	if ((rptr = EvaluateExpression()) != (BPTR) 0)
		return( generate_pause( rptr ) );
	else	return( 1 );
}

WORD	is_iof_instruction()
{
	WORD	i;
	trace("is_iof_instruction()\n");
	for ( i = 0; i < _PRINT_KEYWORD_MAX; i++ )
		if ( is_mnemonic( print_keywords[i] ) )
			return( i );
	return( MOINS_UN );
}

WORD	store_fmt( opcode, fptr )
WORD	opcode;
BPTR	fptr;
{
	IOFPTR	iptr;
	if ((iptr = allocate_for_iof()) == (IOFPTR) 0)
		return(27);
	if ((iptr->prev = IofFoot) == (IOFPTR) 0)
		IofHead = iptr;
	else	IofFoot->next = iptr;
	IofFoot = iptr;
	iptr->operation  = opcode;
	iptr->buffer	 = fptr;
	return( 0 );
}

BPTR	allocate_for_format()
{
	BPTR	fptr;
	if ((fptr = (BPTR) allocate(256)) != (BPTR) 0) {
		memset(fptr,0x00FF,256);
		*fptr = 0;
		}
	return( fptr );
}

BPTR	convert_ascii_format( xptr )
BPTR	xptr;
{
	WORD	l=0;
	BPTR	fptr=(BPTR) 0;;
	if (((l = strlen(xptr)) != 0)
	&&  ((fptr = (BPTR) allocate_for_format()) != (BPTR) 0)
	&&  ((l = atofmt( xptr,l,(fptr+1),255)) != 0)
	&&  ( *(fptr + 1) == 0x00FE )) {
		for ( l = 1; l < 255; l++ )
			if ( *(fptr +l) == 0x00FF )
				break;
		*fptr = l;
		}
	return( fptr );
}


WORD	store_iof_fmt( fptr )
BPTR	fptr;
{
	WORD	status;
	if ( fptr == (BPTR) 0 )
		fptr = (BPTR) "E";
	if ((fptr = convert_ascii_format(fptr)) == (BPTR) 0)
		return( syntax_error(3000) );
	else if ((status = store_fmt( (_iof_FMT | 0x0080 ), fptr )) != 0)
		return( status );
	else	return( 0 );
}

WORD	store_iof( xptr, opcode )
BPTR    xptr;
WORD	opcode;
{
	IOFPTR	iptr;
	if ((iptr = allocate_for_iof()) == (IOFPTR) 0)
		return(27);
	if ((iptr->prev = IofFoot) == (IOFPTR) 0)
		IofHead = iptr;
	else	IofFoot->next = iptr;
	IofFoot = iptr;
	iptr->operation = opcode;
	iptr->operand   = xptr;
	return( 0 );
}

WORD	store_iof_prn( xptr )
VPTR	xptr;
{
	trace("store_iof_prn()\n");
	return( store_iof( xptr , _iof_PRN ) );
}

WORD	translate_prn()
{
	BPTR     	xptr;
	if ((xptr = EvaluateExpression()) == (BPTR) 0)
		return( syntax_error(3001) );
	else	return( store_iof_prn( xptr ) );
}

WORD		store_iof_atb( xptr )
VPTR     	xptr;
{
	trace("store_iof_atb()\n");
	return( store_iof( xptr, _iof_ATB ) );
}

WORD	translate_atb()
{
	BPTR	xptr;
	if (( is_left_brace()  )
	&&  ((xptr = IntegerExpression()) != (BPTR) 0)
	&&  ( is_right_brace() ))
		return( store_iof_atb( xptr ) );
	else	return( syntax_error(3002) );
}

WORD	store_iof_tabv( xptr )
VPTR     	xptr;
{
	trace("store_iof_tabv()\n");
	return( store_iof( xptr, _iof_TABV ) );
}

WORD	translate_tabv()
{
	BPTR	xptr;
	if (( is_left_brace() )
	&&  ((xptr = IntegerExpression()) != (BPTR) 0)
	&&  ( is_right_brace() ))
		return( store_iof_tabv( xptr ) );
	else	return( syntax_error(3003) );
}

WORD	store_iof_tabl( lptr )
VPTR     	lptr;
{
	trace("store_iof_tabl()\n");
	return( store_iof( lptr, _iof_TABL ) );
}

WORD	store_iof_tabc( lptr )
VPTR     	lptr;
{
	trace("store_iof_tabc()\n");
	return( store_iof( lptr, _iof_TABC ));
}

WORD	translate_iof_tab(modeabal)
WORD	modeabal;
{
	BPTR     	lptr;
	BPTR     	cptr;
	WORD		status;
	if ((cptr = IntegerExpression()) == (BPTR) 0)
		return( syntax_error(3004) );
	
	status = is_comma();
	if (!(modeabal))
		status = VRAI;
	if ( status ) {
		if (((lptr = IntegerExpression()) == (BPTR) 0)
		||  ((status = store_iof_tabl( lptr )) != 0 ))
			return( syntax_error(3005) );
		}
	if ( is_right_brace() )
		return( store_iof_tabc( cptr ));
	else	return( unmatched_braces() );
}

WORD	translate_tab()
{
	if ( is_left_brace() )
		return( translate_iof_tab(VRAI) );
	return( syntax_error(3006) );
}

WORD	store_iof_foreground( xptr )
VPTR     	xptr;
{
	return( store_iof( xptr, _iof_FORE ) );
}

WORD	store_iof_background( xptr )
VPTR     	xptr;
{
	return( store_iof( xptr, _iof_BACK ) );
}

WORD	translate_paint()
{
	BPTR     	xptr;
	WORD		status;
	if ( is_left_brace() ) {
		if (((xptr = IntegerExpression()) == (BPTR) 0)
		||  ((status = store_iof_foreground( xptr )) != 0 ))
			return( syntax_error(3007) );
		if ( is_comma() ) {
			if (((xptr = IntegerExpression()) == (BPTR) 0)
			||  ((status = store_iof_background( xptr )) != 0 ))
				return( syntax_error(3008) );
			}
		if ( is_right_brace() )
			return( 0 );
		}
	return( syntax_error(3009) );
}

WORD	flush_fmt()
{
	return(0);
}

WORD	ask_end_label()
{
	if ( AskEndLabel == MOINS_UN )
		return((AskEndLabel = new_implicite_label()));
	else	return(AskEndLabel);
}

WORD	dcl_ask_end_label()
{
	if (( AskEndLabel != MOINS_UN )
	&&  ( dcl_implicite_label( AskEndLabel ) == 0 )) {
		return( 0 );
		}
	else	return( 0 );
}

WORD	flush_hotkey( hptr )
HOTPTR	hptr;
{
	WORD	status;
	if (( hptr != (HOTPTR) 0)
	&&  ((status = generate_iof_hotkey( hptr )) != 0))
		return( status );
	else	return( 0 );
}


WORD	flush_hotkeys()
{
	HOTPTR	hptr;
	WORD	status;
	if ((hptr = HotHead) != (HOTPTR) 0) {
		do	{
			if ((status = flush_hotkey( hptr )) != 0)
				return( status );
			}
		while ((hptr = hptr->next) != (HOTPTR) 0);
		}
	return(0);
}
WORD	message( nptr )
BPTR	nptr;
{
	sysprintf(nptr);
	return(1);
}

BPTR	convert_explicite_format()
{
	WORD	l=0;
	BPTR	fptr=(BPTR) 0;;
	if (((l = get_format()) != 0)
	&&  ((fptr = (BPTR) allocate_for_format()) != (BPTR) 0)
	&&  ((l = atofmt( TokenBuffer,l,(fptr+1),255)) != 0)
	&&  ( *(fptr + 1) == 0x00FE )) {
		for ( l = 1; l < 255; l++ )
			if ( *(fptr +l) == 0x00FF )
				break;
		*fptr = l;
		}
	return( fptr );
}

/*
 *	(FORMAT)
 *	((<expr>,<expr>,<expr>))
 *
 */

WORD	translate_fmt()
{
	BPTR		rptr;
	BPTR		fptr;
	WORD		status;
	trace("translate_fmt()\n");
	if ( is_left_brace() )	{	/* Double Opening Brace */
		trace("implicite_format_expression\n");
		/* Format Expression (variable etc) */
		do	{
			if ((rptr = EvaluateExpression()) == (BPTR) 0)
				return( syntax_error(3010) );
			if ((status = store_iof( rptr, _iof_FMT )) != 0 )
				return(status);
			}
		while ( is_comma() );
		if (!(is_right_brace()))
			return( syntax_error(3011) );
		}
	else	{			/* Single Opening Brace */
		trace("explicite_format_string\n");
		/* Explicite Format String */
		/* ----------------------- */
		if ((fptr = convert_explicite_format()) == (BPTR) 0)
			return( syntax_error(3012) );
		if ((status = store_fmt( (_iof_FMT | 0x0080 ), fptr )) != 0)
			return( status );
		}

	/* Check for final closing brace */
	/* ----------------------------- */
	if ( is_right_brace() )
		return(0);
	else	return(unmatched_braces());
}

WORD	iof_special( opcode )
WORD	opcode;
{
	return( store_iof( (VPTR) 0, opcode ));
}

WORD	translate_iof_bell()
{
	return( iof_special( _iof_BELL ) );
}

WORD	translate_iof_clear()
{
	trace("translate_iof_clear()\n");
	return( iof_special( _iof_CLEAR ) );
}

WORD	iof_instructions(askmode)
WORD	askmode;
{
	WORD		instruction=0;
	WORD		status=0;
	trace("iof_instructions()\n");

	do	{
		switch ((instruction = is_iof_instruction())) {

			case _IOF_TAB		:
				if ((status = translate_tab()) != 0)
					return( status );
				else	break;
				
			case _IOF_TABV		:
				if ((status = translate_tabv()) != 0)
					return( status );
				else	break;

			case _IOF_PAINT		:
				if ((status = translate_paint()) != 0)
					return( status );
				else	break;

			case _IOF_ATB		:
				if ((status = translate_atb()) != 0)
					return( status );
				else	break;

			case _IOF_PAGE		:
			case _IOF_CLEAR		:
				if ((status = translate_iof_clear()) != 0)
					return( status ); 
				else	break;
			case _IOF_BELL		:
				if ((status = iof_special( _iof_BELL )) != 0)
					return( status );
				else	break;
			case _IOF_HOME		:
				if ((status = iof_special( _iof_HOME )) != 0)
					return( status );
				else	break;

			case MOINS_UN		:
				if ( is_equals() ) {
					if ( askmode == 1 ) {
						unget_byte();
						return( 0 );
						}
					else	return( syntax_error(3013) );
					}
				if ( is_right_brace() ) {
					if ( askmode == 2 ) {
						unget_byte();
						return(0);
						}
					else	return( syntax_error(3014) );
					}
				if ( is_left_brace() ) {
					if ((status = translate_fmt()) != 0 )
						return( syntax_error(3015) );
					}
				else if ((status = translate_prn()) != 0)
					return( syntax_error(3016) );

			}
		}
	while ( is_comma() );
	return(0);
}

WORD		flush_iof()
{
	WORD	status;
	IOFPTR	iptr;
	BPTR	fptr;
	WORD	l;
	if ((iptr = IofHead) != (IOFPTR) 0) {
		do	{
			if ( iptr->operation != MOINS_UN ) {
				if ( iptr->operation & 0x0080 ) {
					/* Explicite Format Code */
					if ((status = generate_iof_format(iptr->operation, iptr->buffer )) != 0)
						return( status );
					}
				else if ( iptr->operand != (BPTR) 0) {
					if ((status = generate_iof_instruction( iptr->operation, iptr->operand )) != 0)
						return( status );
					}
				else if ((status = generate_byte( iptr->operation )) != 0)
					return( status );
				}
			}
		while ((iptr = iptr->next) != (IOFPTR) 0);
		}
	return(0);
}

WORD	flush_device( device )
BPTR	device;
{
	return( generate_iof_instruction( _iof_DEV, device ));
}

WORD	check_hotkey_operands()
{
	return(0);
}

WORD		flush_print( device, mode )
BPTR 		device;
WORD		mode;
{
	WORD	status;
	trace("flush_print()\n");
	if (((status = generate_iof()) == 0)
	&&  ((status = flush_device(device)) == 0)
	&&  ((status = flush_fmt())    == 0)
	&&  ((status = flush_iof())    == 0))
		return( generate_fio() );
	else	return( status );
}

WORD		flush_iof_ask( device, target )
BPTR     	device;
BPTR     	target;
{
	WORD		status=30;
	if (((status = generate_iof())  == 0 )
	&&  ((status = flush_device(device)) == 0)
	&&  ((status = flush_hotkeys()) == 0 )
	&&  ((status = flush_iof())     == 0 )
	&&  ((status = generate_iof_instruction( _iof_ASK, target )) == 0))
		return( dcl_ask_end_label() );
	else	return( syntax_error(3017) );
}

BPTR		AskExpression();

WORD		flush_ask( device )
BPTR     	device;
{
	BPTR     	target;
	WORD		status=30;
	if (( is_equals() )
	&&  ((target = AskExpression()) != (BPTR) 0))
		return( flush_iof_ask( device, target ) );
	else	return(syntax_error(3018));
}

WORD	translate_format_labels()
{
	while ( is_comma() ) {
		return( not_yet_available() );
		}
	return( 0 ); 
}

WORD	translate_print()
{
	BPTR     	device;
	WORD		status=0;
	if (( is_equals() )
	&&  ((status = start_iof()) == 0)
	&&  ((device = EvaluateExpression()) != (BPTR) 0)
	&&  ((status = translate_format_labels()) == 0 )
	&&  ( is_colon()  )
	&&  ((status = iof_instructions(0)) == 0 ))
		return( flush_print( device, VRAI ) );
	else	return( syntax_error(3019) );	
}

WORD	translate_clf_print(device)
BPTR    device;
{
	WORD		status=0;
	if (( is_left_brace() )
	&&  ((status = start_iof()) == 0)
	&&  ((status = iof_instructions(2)) == 0 )
	&&  ( is_right_brace() ))
		return( flush_print( device ) );
	else	return( syntax_error(3020) );	
}



WORD	store_hotkey( hptr )
HOTPTR	hptr;
{
	if ( HotFoot == (HOTPTR) 0 )
		HotHead = hptr;
	else	HotFoot->next = hptr;
	HotFoot = hptr;
	return( 0 );
}

WORD	translate_hotkey_adresse( hptr )
HOTPTR	hptr;
{
	trace("translate_hotkey_adresse()\n");
	if ((hptr->gosub = is_left_brace()))
		generate_iof_doloop();
	if (!( get_token() ))
		return( syntax_error(3021) );
	if ((hptr->label = (BPTR) allocate( strlen( TokenBuffer )+1 )) == (BPTR) 0)
		return( allocation_failure() );
	else	strcpy(hptr->label,TokenBuffer);
	if (( hptr->gosub ) &&  (!( is_right_brace())))
		return( syntax_error(3022) );
	else	return( 0 );

}


WORD	translate_implicite_hotkey( identity )
WORD	identity;
{
	WORD		status;
	HOTPTR		hptr;
	if (( is_equals() )
	&&  ((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
	&&  ((status = translate_hotkey_adresse(hptr)) == 0  )) {
		hptr->nature = identity;
		return( store_hotkey( hptr ) );
		}
	else	return( status );
}

WORD	store_implicite_hotkeys( kptr, label )
BPTR	kptr;
BPTR	label;
{
	WORD		status;
	WORD		keycode;
	HOTPTR		hptr;
	trace("store_implicite_hotkeys()\n");
	while ((keycode = *(kptr++)) != 0 ) {
		if  (((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
		&&   ((hptr->label = (BPTR) allocate_for_string( label )) != (BPTR) 0)) {
			hptr->gosub = FAUX;
			switch ( keycode ) {
				case 'I' :
					trace("Escape\n");
					hptr->nature = _hot_I;
					break;
				case 'U' :
					hptr->nature = _hot_U;
					break;
				case 'D' :
					hptr->nature = _hot_D;
					break;
				case 'L' :
					hptr->nature = _hot_L;
					break;
				default	:
					return( syntax_error(3023) );
				}
			if ((status = store_hotkey( hptr )) != 0)
				return( status );
			}
		else	return( allocation_failure() );
		}
	return( 0 );
}


WORD	translate_explicite_hotkey()
{
	WORD		status=30;
	HOTPTR		hptr;
	trace("translate_explicite_hotkey()\n");
	if (((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
	&&  ((hptr->operand = EvaluateExpression()) != (BPTR) 0)
	&&  ( is_equals() )
	&&  ((status = translate_hotkey_adresse(hptr)) == 0 ))
		return( store_hotkey( hptr ) );
	else	return( status );
}


WORD	translate_hotkeys()
{
	WORD	c=32;
	WORD	status;
	trace("translate_hotkeys()\n");
	while ( is_comma() ) {
		if ( is_mnemonic("I") )
			c = 1;
		else if ( is_mnemonic("U") )
			c = 2;
		else if ( is_mnemonic("D") )
			c = 3;
		else if ( is_mnemonic("L") )
			c = 4;
		else if ( is_mnemonic("X") )
			c = 5;
		else if ( is_mnemonic("E") )
			c = 6;
		else if ( is_mnemonic("T") )
			c = 7;
		else	c = get_byte();
/*		sysprintf(" C = %c \n",c);	*/
		if (c != 0 ) {
			switch (c) {

				case 1   :	/* ESCAPE 	*/
					if ((status = translate_implicite_hotkey(_hot_I)) != 0 )
						return( status );
					else	break;

				case 2 :	/* UP		*/
					if ((status = translate_implicite_hotkey(_hot_U)) != 0 )
						return( status );
					else	break;

				case 3 :	/* DOWN		*/
					if ((status = translate_implicite_hotkey(_hot_D)) != 0 )
						return( status );
					else	break;

				case 4 :	/* LEFT		*/
					if ((status = translate_implicite_hotkey(_hot_L)) != 0 )
						return( status );
					else	break;

				case 5 :	/* EVENT	*/
					if ((status = translate_implicite_hotkey(_hot_X)) != 0 )
						return( status );
					else	break;

				case 6 :	/* ERROR	*/
					if ((status = translate_implicite_hotkey(_hot_E)) != 0 )
						return( status );
					else	break;

				case 7 :	/* TIMER	*/
					if ((status = translate_implicite_hotkey(_hot_T)) != 0 )
						return( status );
					else	break;

				default	 :	/* All others */
					unget_byte();
					if ((status = translate_explicite_hotkey()) != 0 )
						return( status );
					else	break;
				}
			}
		else	return( syntax_error(3024) );
		}
	return( 0 ); 
}


WORD	translate_ask()
{
	BPTR     	device;
	WORD		status=0;
	if (( is_equals() )
	&&  ((status = start_iof()) == 0)
	&&  ((device = EvaluateExpression()) != (BPTR) 0)
	&&  ((status = translate_hotkeys()) == 0 )
	&&  ( is_colon()  )
	&&  ((status = iof_instructions(1))   == 0 ))
		return( flush_ask( device ) );
	else	return( syntax_error(3025) );	
}

WORD	translate_op()
{
	BYTE		label[64];
	BPTR		lptr=(BPTR) 0;
	WORD		status;
	TCVARPTR  	vptr=(TCVARPTR) 0;

	if ( is_mnemonic("NEXT") )
		status = 0;
	else if ( is_mnemonic("BREAK") )
		lptr = (BPTR) "\0";
	else	{
		if (( get_token() ) 	/* Label */
		&&  ( copy_token( label, 32) ))
			lptr = (BPTR) label;
		else	return( syntax_error(3026) );
		}
	if (( is_comma() )
	&&  ( get_token() )
	&&  ((vptr = is_variable(1)) == (TCVARPTR) 0))
		return( syntax_error(3027) );

	if ((status = generate_op( lptr, vptr )) != 0)
		return( status );
	else	return( 0 );
}

WORD	translate_iof()
{
	WORD	type;
	switch ((type = is_iof_keyword())) {
		case	_IOF_PRINT	:
			return( translate_print() );
		case	_IOF_ASK	:
			return( translate_ask() );
		case	_IOF_PAUSE	:
			return( translate_pause() );
		case	_IOF_OP		:
			return( translate_op() );
		case	_IOF_GET	:
		case	_IOF_PUT	:
			return( not_yet_available() );
		default	:
			return( MOINS_UN );
		}
}

WORD		clf_print( target, format, value )
BPTR     	target;
BPTR		format;
BPTR     	value;
{
	WORD	status;
	if  (((status = start_iof()) == 0)
	&&   ((status = store_iof_fmt( format )) == 0 )
	&&   ((status = store_iof_prn( value  )) == 0 ))
		return( flush_print( target, FAUX ) );
	else	return( syntax_error(3028) );
}

WORD	cancel_iof_instruction()
{
	WORD	type;
	if ((type = is_iof_instruction()) != MOINS_UN) {
		cancel_keyword( & print_keywords[type] );
		return( VRAI );
		}
	else	return( MOINS_UN );
}



#endif	/* _TRIOF_C */
	/* -------- */


