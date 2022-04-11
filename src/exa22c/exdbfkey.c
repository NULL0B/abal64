/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBFKEY.C				*/
/*		Date 	:	14/05/1996				*/
/*		Version :	2.1d					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBFKEY_C
#define _EXDBFKEY_C

#include "exdbfkey.h"
#include "allocate.h"

static	struct program_function_keys 	ProgramKeys;
static 	EXABYTE				FunctionKeys[10];

extern EXABYTE max_ligne;

void	establish_function_key( nb, val, msg  )
EXAWORD	nb;
EXAWORD	val;
BPTR	msg;
{
	EXAWORD	n;
	EXAWORD	l;
	EXAWORD	c;
	EXABYTE	buffer[32];
#ifndef	_JAKO_BUG_POS	
	x_bstart();
	symbolic_atribut(2);
	pos((l=((ScreenLin-1)+((nb - 1)/5))),(c=(1+(((nb-1)%5)*16))));
	x_putch('F');
	if ((n = display_integer( nb )) < 2 )
		x_putch(' ');
	x_putch(':');
	left_string( c+4, l, 11, (BPTR) msg );
	symbolic_atribut(0);
	x_bflush();
#else
	for ( l = 5; l <= 24; l++ ) {
		pos(l,1);
		display_integer( l );
		x_putch( ' ');
		display_integer( max_ligne );
		}
	mimo_getch();
#endif
	FunctionKeys[(nb-1)] = val;
	buffer[0] = val;
	buffer[1] = 0;
	prfo( 127+nb, (BPTR) buffer, 1 );
	return;
}

void	establish_function_keys( mode )
EXAWORD	mode;
{
	establish_function_key( 1, CTRL_H, (BPTR) interface_message(10) );
	establish_function_key( 2, CTRL_G, (BPTR) interface_message(11) );
	establish_function_key( 3, CTRL_V, (BPTR) interface_message(12) );
	establish_function_key( 4, CTRL_P, (BPTR) interface_message(13) );
	establish_function_key( 5, CTRL_S, (BPTR) interface_message(14) );
	if ( mode == 0 ) {
		establish_function_key( 6, CTRL_X, (BPTR) interface_message(15) );
		establish_function_key( 7, CTRL_Q, (BPTR) interface_message(16) );
		establish_function_key( 8, CTRL_O, (BPTR) interface_message(17) );
		establish_function_key(10, CTRL_I, (BPTR) interface_message(18) );
	}
	else	{
		establish_function_key( 6, 0x0027, (BPTR) interface_message(19) );
		establish_function_key( 7, CTRL_M, (BPTR) interface_message(20) );
		establish_function_key( 8, CTRL_B, (BPTR) interface_message(21) );
		establish_function_key(10, CTRL_J, (BPTR) interface_message(22) );
	}
	establish_function_key( 9, CTRL_A, (BPTR) interface_message(23) );

#ifdef WIN1632
	/* Establish SHIFT-F7 : STEP OUT ^N v RC v RC ^B esc esc ^X */
	{ EXABYTE b[10];
		b[0]=14; b[1]=5;  b[2]=13; b[3]=5;  b[4]=13;
		b[5]=2;  b[6]=27; b[7]=27; b[8]=24; b[9]=0;
		prfo( 144, (BPTR)b, 9 );
	}
#endif

	return;
}

EXAWORD	detect_function_key( nbl )
EXAWORD	nbl;
{
	EXAWORD	nbc;
	EXAWORD	nbk;
	if ((nbc = get_mimo_col()) == 0)
		return( 0 );
	if ((nbc % 16) == 0)
		return( 0 );

	nbk = ((((nbc / 16) + 1) + ( nbl > (ScreenLin-1) ? 5 : 0 )));
	if (( nbk >= 1 ) && ( nbk <= 10 ))
		return( (EXAWORD) FunctionKeys[(nbk-1)] );
	else	return( 0 );
}

VOID	store_function_keys()
{
	EXAWORD		lerr;
	EXAWORD		x;
	PGMFKEYPTR	pfkey;
	pfkey = ProgramKeys.keylist;
	for ( x = 0; x < ProgramKeys.keycount; x++ ) {
		if ( pfkey == (PGMFKEYPTR) 0)
			break;
		memset( (BPTR) pfkey->buffer , 0, 33 );
		if ((lerr = lcfo( 128+x, (BPTR) pfkey->buffer, 32 )) != MOINS_UN )
			pfkey->length = exadb_strlen( pfkey->buffer );
		else	pfkey->length = 0;
		pfkey = pfkey->next;
		}
	return;
}

VOID	restore_function_keys()
{
	EXAWORD	x;
	PGMFKEYPTR	pfkey;
	pfkey = ProgramKeys.keylist;
	for ( x = 0; x < ProgramKeys.keycount; x++ ) {
		if ( pfkey == (PGMFKEYPTR) 0)
			break;
		if ( pfkey->length != 0 )
			prfo( 128+x, (BPTR) pfkey->buffer, pfkey->length );
		pfkey = pfkey->next;
		}
	return;
}

#ifndef	UNIX
VPTR	allocate( EXAWORD );
#else
#if !defined(AVIION) && !defined(RT_AIX) && !defined(LINUX)
VPTR	allocate();
#endif
#endif /* UNIX */

VOID	init_fkey_storage()
{
	EXAWORD	x;
	PGMFKEYPTR	pfkey;
	ProgramKeys.keylist = (PGMFKEYPTR) 0;
	memset((BPTR) FunctionKeys, 0, 10);
	ProgramKeys.keycount = 10;
	for ( x = 0; x < ProgramKeys.keycount; x++ ) {
		if ((pfkey = (PGMFKEYPTR) allocate( sizeof( struct program_function_key ) )) != (PGMFKEYPTR)  0) {
			pfkey->next = ProgramKeys.keylist;
			ProgramKeys.keylist = pfkey;
			}
		else	break;
		}
	return;
}

VOID	liber_fkey_storage()
{
	EXAWORD	x;
	PGMFKEYPTR	pfkey;
	return;
	for ( x = 0; x < ProgramKeys.keycount; x++ ) {
		if ((pfkey = ProgramKeys.keylist) != (PGMFKEYPTR)  0) {
			ProgramKeys.keylist = pfkey->next ;
			liberate( pfkey );
			}
		else	break;
		}
	ProgramKeys.keycount = 0;
	return;
}

#endif	/* _EXDBFKEY_C */
	/* ----------- */
