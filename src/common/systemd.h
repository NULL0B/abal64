/*
 *	---------------------------------
 *	Copyright (c) 1995 Amenesik / Sologic s.a.
 *	---------------------------------
 *	Project	:	ABAL VERSION 2.1D
 *	---------------------------------
 *	File	:	SYSTEMD.H
 *	Date	:	21/04/1995
 *	---------------------------------
 */

#ifndef _SYSTEMD_H
#define _SYSTEMD_H

#include "stdtypes.h"

#define	STDIO  1
#define STDERR 2

#ifndef UNIX
#ifdef DOS
#define x_putch( arg1 ) _co( arg1 )
VOID	establish_relay( VOID (far *) () ); 
#endif

WORD	redirect_stdout( VOID );
VOID	recover_stdout( VOID );
WORD	ll_system( BPTR , BPTR );
BPTR	ll_getenv( BPTR );
WORD	Mstrlen( BPTR );
WORD	systeme( BPTR );
WORD	systemd( BPTR , WORD , WORD , WORD );
VOID	UpperCase( BPTR , WORD );
WORD	fn_parser( BPTR , BPTR , WORD );
void	x_putch(WORD);
WORD	conf(WORD);

#else
WORD	systemd();
void	x_putch(WORD);
WORD	conf(WORD);
#endif

#endif	/* _SYSTEMD_H */
	/* ---------- */



