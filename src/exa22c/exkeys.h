/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992  Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXKEYS.H  				*/
/*		Version	:	2.1a      				*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXKEYS_H
#define	_EXKEYS_H

#define	LEFT_KEY	8
#define RIGH_KEY	6
#define HAUT_KEY	11
#define	DOWN_KEY	10
#define ESC_KEY		27

#ifdef INTEL
#define	ANUL_KEY	1
#define INSE_KEY	15
#define	HOME_KEY	28
#define	DELE_KEY	127
#else
#define	ANUL_KEY	1
#define INSE_KEY	15
#define	HOME_KEY	2
#define	DELE_KEY	7
#endif

/*
 *	Keys That may be redefined during Execution
 *	-------------------------------------------
 *	The Key values refer to the entry in SYSKEY [9]
 */

#define	IO_FOR		1
#define	IO_BAK		2
#define	IO_UP		3
#define	IO_BAS		4
#define	IO_TOP		5
#define	IO_CLS		6
#define	IO_CAN		7

#define	IO_LF		10
#define	IO_RC		13

#define	IO_DWN		10
#define	IO_TAB		9
#define	IO_ESC		ESC_KEY
#define	IO_BEL		7
#define	IO_ESP		32
#define	IO_INS		15
#define	IO_FIN		2
#define	IO_DEL		127
#define	IO_NUL		0

#endif	/* _EXKEYS_H */
	/* --------- */
